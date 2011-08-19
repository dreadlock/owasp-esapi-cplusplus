/**
* OWASP Enterprise Security API (ESAPI)
*
* This file is part of the Open Web Application Security Project (OWASP)
* Enterprise Security API (ESAPI) project. For details, please see
* http://www.owasp.org/index.php/ESAPI.
*
* Copyright (c) 2011 - The OWASP Foundation
*
* @author Kevin Wall, kevin.w.wall@gmail.com
* @author Jeffrey Walton, noloader@gmail.com
*
*/

#include "EsapiCommon.h"
#include "util/Mutex.h"
#include "crypto/SecureRandom.h"
#include "errors/EncryptionException.h"
#include "errors/InvalidArgumentException.h"

#include "safeint/SafeInt3.hpp"

#include <string>
#include <sstream>
#include <stdexcept>

/**
* This class implements functionality similar to Java's SecureRandom for consistency
* http://download.oracle.com/javase/6/docs/api/java/security/SecureRandom.html
*/
namespace esapi
{
  // Retrieve a reference to the global PRNG.
  SecureRandom& SecureRandom::GlobalSecureRandom() throw()
  {
    static SecureRandom s_prng;
    return s_prng;
  }

  // Create an instance PRNG.
  SecureRandom::SecureRandom() throw(EncryptionException)
  {
  }

  // Create an instance PRNG with a seed.
  SecureRandom::SecureRandom(const byte* seed, size_t size)
    throw(InvalidArgumentException, EncryptionException)
  {
    ASSERT(seed);
    ASSERT(size);

    setSeed(seed, size);
  }

  SecureRandom::~SecureRandom() throw()
  {
  }

  // Create an instance PRNG with a seed.
  SecureRandom::SecureRandom(const std::vector<byte>& seed) throw(EncryptionException)
  {
    ASSERT(seed.size());

    setSeed(&seed[0], seed.size());
  }

  // Returns the name of the algorithm implemented by this SecureRandom object.
  std::string SecureRandom::getAlgorithm() const throw()
  {
    return "X9.31/AES";
  }

  // Generates a user-specified number of random bytes.
  void SecureRandom::nextBytes(byte* bytes, size_t size)
    throw(InvalidArgumentException, EncryptionException)
  {
    ASSERT(bytes);
    ASSERT(size);

    if(!bytes && !size)
      return;

    if(!bytes)
      throw InvalidArgumentException("The byte array or size is not valid.");

    try
    {
      SafeInt<size_t> safe((size_t)bytes);
      safe += size;

      MutexAutoLock lock(m_mutex);
      prng.GenerateBlock(bytes, size);
    }
    catch(SafeIntException&)
    {
      throw EncryptionException("Integer overflow detected.");
    }
    catch(CryptoPP::Exception& ex)
    {
      throw EncryptionException(std::string("Internal error: ") + ex.what());
    }
  }

  // Generates a user-specified number of random bytes.
  void SecureRandom::nextBytes(std::vector<byte>& bytes) throw(EncryptionException)
  {
    ASSERT(bytes.size());

    nextBytes(&bytes[0], bytes.size());
  }

  // Reseeds this random object.
  void SecureRandom::setSeed(const byte* seed, size_t size)
    throw(InvalidArgumentException, EncryptionException)
  {
    ASSERT(seed);
    ASSERT(size);

    if(!seed && !size)
      return;

    if(!seed)
      throw InvalidArgumentException("The seed array or size is not valid.");

    try
    {
      SafeInt<size_t> safe((size_t)seed);
      safe += size;

      MutexAutoLock lock(m_mutex);
      prng.IncorporateEntropy(seed, size);
    }
    catch(SafeIntException&)
    {
      throw EncryptionException("Integer overflow detected.");
    }
    catch(CryptoPP::Exception& ex)
    {
      throw EncryptionException(std::string("Internal error: ") + ex.what());
    }
  }

  // Reseeds this random object.
  void SecureRandom::setSeed(const std::vector<byte>& seed) throw(EncryptionException)
  {
    ASSERT(seed.size());

    setSeed(&seed[0], seed.size());
  }

  // Reseeds this random object, using the bytes contained in the given long seed.
  void SecureRandom::setSeed(long seed) throw(EncryptionException)
  {
    setSeed((const byte*)&seed, sizeof(seed));
  }

} // NAMESPACE esapi