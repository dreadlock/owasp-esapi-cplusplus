/**
* OWASP Enterprise Security API (ESAPI)
*
* This file is part of the Open Web Application Security Project (OWASP)
* Enterprise Security API (ESAPI) project. For details, please see
* <a href="http://www.owasp.org/index.php/ESAPI">http://www.owasp.org/index.php/ESAPI</a>.
*
* Copyright (c) 2011 - The OWASP Foundation
*
* The ESAPI is published by OWASP under the BSD license. You should read and accept the
* LICENSE before you use, modify, and/or redistribute this software.
*
* @author Jeff Williams <a href="http://www.aspectsecurity.com">Aspect Security</a>
* @created 2011
*/

#include "EsapiCommon.h"
#include "codecs/Codec.h"

#include <boost/shared_ptr.hpp>

#include <sstream>
#include <iomanip>

#define HEX(x) std::hex << std::setw(x) << std::setfill('0')
#define OCT(x) std::octal << std::setw(x) << std::setfill('0')

/**
* Precomputed size of the internal hex array.
* Private to this compilation unit.
*/
static const size_t ARR_SIZE = 256;

//
// Thread safe, multiprocessor initialization
// http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
//

const esapi::HexArray& esapi::Codec::getHexArray ()
{
  MutexLock lock(getClassMutex());

  static volatile bool init = false;
  static boost::shared_ptr<HexArray> hexArr;

  MEMORY_BARRIER();
  if(!init)
  {
    boost::shared_ptr<HexArray> temp(new HexArray);
    ASSERT(temp);
    if(nullptr == temp.get())
      throw std::bad_alloc();

    // Convenience
    HexArray& ta = *temp.get();

    // Save on reallocations
    ta.resize(ARR_SIZE);

    for ( unsigned int c = 0; c < ARR_SIZE; c++ ) {
      if ( (c >= 0x30 && c <= 0x39) || (c >= 0x41 && c <= 0x5A) || (c >= 0x61 && c <= 0x7A) ) {
        ta[c] = std::string();
      } else {
        std::ostringstream str;
        // str << HEX(2) << int(0xFF & c);
        str << std::hex << c;
        ta[c] = str.str();
      }
    }

    hexArr.swap(temp);
    init = true;

    MEMORY_BARRIER();

    } // !init

  return *hexArr.get();
}

/**
* Retrieve the class wide intialization lock.
*
* @return the mutex used to lock the class.
*/
esapi::Mutex& esapi::Codec::getClassMutex ()
{
  static esapi::Mutex s_mutex;
  return s_mutex;
}

std::string esapi::Codec::encode(const char immune[], size_t length, const std::string& input) const
{
  ASSERT(immune);
  ASSERT(length);
  ASSERT(!input.empty());

  if(!immune)
    return std::string();

  std::string sb;
  sb.reserve(input.size());

  for (size_t i = 0; i < input.length(); i++) {
    char c = input[i];
    sb.append(encodeCharacter(immune, length, c));
  }

  return sb;
}

std::string esapi::Codec::encodeCharacter(const char immune[], size_t length, char c) const{
  ASSERT(immune);
  ASSERT(length);
  ASSERT(c != 0);

  return std::string(1, c);
}

std::string esapi::Codec::decode(const std::string& input) const{
  ASSERT(!input.empty());

  std::string sb;
  sb.reserve(input.size());

  esapi::PushbackString pbs(input);
  while (pbs.hasNext()) {
    char c = decodeCharacter(pbs);
    if (c != 0) {
      sb+=c;
    } else {
      sb+=pbs.next();
    }
  }
  return sb;
}

char esapi::Codec::decodeCharacter(PushbackString& input) const{
  // This method needs to reset input under certain conditions,
  // which it is not doing. See the comments in the header file.
  ASSERT(0);
  ASSERT(input.hasNext());

  return input.next();
}

std::string esapi::Codec::getHexForNonAlphanumeric(char c) {
  ASSERT(c != 0);

  const HexArray& hex = getHexArray();

  int i = (int)c;
  if(i < (int)ARR_SIZE)
    return hex.at(i);

  return toHex((char)i);
}

std::string esapi::Codec::toOctal(char c) {
  ASSERT(c != 0);

  std::ostringstream str;
  // str << OCT(3) << int(0xFF & c);
  str << std::oct << c;
  return str.str();
}

std::string esapi::Codec::toHex(char c) {
  ASSERT(c != 0);

  std::ostringstream str;
  // str << HEX(2) << int(0xFF & c);
  str << std::hex << c;
  return str.str();
}

bool esapi::Codec::containsCharacter(char c, const std::string& s) const{
  ASSERT(c != 0);
  ASSERT(!s.empty());

  return s.find(c, 0) != std::string::npos;
}

bool esapi::Codec::containsCharacter(char c, const char array[], size_t length) const{
  ASSERT(c != 0);
  ASSERT(array);
  ASSERT(length);

  if(!array)
    return false;

  for (size_t ch=0; ch < length; ch++) {
    if (c == array[ch]) return true;
  }

  return false;
}

