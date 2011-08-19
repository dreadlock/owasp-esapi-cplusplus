/**
 * OWASP Enterprise Security API (ESAPI)
 *
 * This file is part of the Open Web Application Security Project (OWASP)
 * Enterprise Security API (ESAPI) project. For details, please see
 * <a href="http://www.owasp.org/index.php/ESAPI">http://www.owasp.org/index.php/ESAPI</a>.
 *
 * Copyright (c) 2007 - The OWASP Foundation
 *
 * The ESAPI is published by OWASP under the BSD license. You should read and accept the
 * LICENSE before you use, modify, and/or redistribute this software.
 *
 * @author Jeff Williams <a href="http://www.aspectsecurity.com">Aspect Security</a>
 * @created 2007
 */

#pragma once

#include <map>
#include <string>
#include <set>
#include "errors/UnsupportedOperationException.h"

namespace esapi {
/*
 * Trie implementation
 *
 * @author Jeff Williams <a href="http://www.aspectsecurity.com">Aspect Security</a>
 * @author Dan Amodio (dan.amodio@aspectsecurity.com)
 */
template <typename T>
class Trie : std::map<std::string, T>{
protected:
	std::map<std::string,T> map;
public:
	std::pair<std::string,T> getLongestMatch(std::string);
	//pair<std::string,T> getLongestMatch(PushbackReader) =0;
	int getMaxKeyLength();
	int size();

	template <typename Y>
	class TrieProxy : public Trie<Y> {
		private:
			Trie<Y> wrapped;

			TrieProxy(const Trie<Y> &);
			TrieProxy() {};

		protected:
			const Trie<Y>& getWrapped();

		public:
			std::pair<std::string,Y> getLongestMatch (std::string);

			int getMaxKeyLength();

			int size();

			bool isEmpty();

			bool containsKey(std::string);

			bool containsValue(Y);

			Y get(std::string);

			Y put (std::string, Y);

			Y remove(std::string);

			void putAll(std::map<std::string, Y>);

			void clear();

			/*std::set<std::string> keySet();

			std::set<Y> values();

			std::set< std::pair<std::string,Y> > entrySet();

			int hashCode();*/
	};

	template <typename U>
	class Unmodifiable : public TrieProxy<U> {
	public:
		Unmodifiable(const Trie<U> &);

		U put(std::string, U) throw (UnsupportedOperationException);
		U remove(std::string) throw (UnsupportedOperationException);
		void putAll(std::map<std::string,U>) throw (UnsupportedOperationException);
		void clear() throw (UnsupportedOperationException);
		std::set<std::string> keySet();
		std::set<U> values();
		std::set< std::pair<std::string,U> > entrySet();
	};

	template <typename V>
	class Util {
	private:
		Util() {};
	public:
		static Trie<V>* unmodifiable(const Trie<V> &);
	};

};
}; // esapi namespace


// Silly compilers don't like separate files for templates.

template <typename T>
template <typename Y>
esapi::Trie<T>::TrieProxy<Y>::TrieProxy(const esapi::Trie<Y> & toWrap) {
	this->wrapped = toWrap;
}

template <typename T>
template <typename Y>
const esapi::Trie<Y>& esapi::Trie<T>::TrieProxy<Y>::getWrapped() {
	return this->wrapped;
}

template <typename T>
template <typename Y>
std::pair<std::string,Y> esapi::Trie<T>::TrieProxy<Y>::getLongestMatch (std::string) {
	return this->wrapped.getLongestMatch();
}

template <typename T>
template <typename Y>
int esapi::Trie<T>::TrieProxy<Y>::getMaxKeyLength() {
	return this->wrapped.getMaxKeyLength();
}

template <typename T>
template <typename Y>
int esapi::Trie<T>::TrieProxy<Y>::size() {
	return this->wrapped.map.size();
}

template <typename T>
template <typename Y>
bool esapi::Trie<T>::TrieProxy<Y>::isEmpty() {
	return this->wrapped.map.empty();
}

template <typename T>
template <typename Y>
bool esapi::Trie<T>::TrieProxy<Y>::containsKey(std::string key) {
	if (this->wrapped.map.count(key)>0)
		return true;
	else
		return false;
}

template <typename T>
template <typename Y>
bool esapi::Trie<T>::TrieProxy<Y>::containsValue(Y val) {
	typename std::map<std::string,Y>::iterator it;
	for ( it=this->wrapped.map.begin() ; it != this->wrapped.map.end(); it++ ) {
		if ( (*it).second == val)
			return true;
	}
	return false;
}

template <typename T>
template <typename Y>
Y esapi::Trie<T>::TrieProxy<Y>::get(std::string key) {
	typename std::map<std::string,Y>::iterator it = this->wrapped.map.find(key);

	if (it == this->wrapped.map.end())
		return NULL;
	else
		return it->second;
}

template <typename T>
template <typename Y>
Y esapi::Trie<T>::TrieProxy<Y>::put (std::string key, Y value) {
	typename std::pair<std::string,Y> newElement(key,value);
	std::pair< typename std::map<std::string,Y>::iterator,bool > ret;

	ret=this->wrapped.map.insert(newElement);

	if (ret.second==false) {
		// return previous existing value
		return ret.first->second;
	} else {
		return NULL;
	}
}

template <typename T>
template <typename Y>
Y esapi::Trie<T>::TrieProxy<Y>::remove(std::string key) {
	typename std::map<std::string,Y>::iterator it = this->wrapped.map.find(key);

	if (it == this->wrapped.map.end()) {
		return NULL;
	} else {
		Y val = it->second;
		this->wrapped.map.erase(it);
		return val;
	}
}

template <typename T>
template <typename Y>
void esapi::Trie<T>::TrieProxy<Y>::putAll(std::map<std::string, Y> t) {
	this->wrapped.map.insert(t.begin(),t.end());
}

template <typename T>
template <typename Y>
void esapi::Trie<T>::TrieProxy<Y>::clear() {
	this->wrapped.map.clear();
}

/*template <typename T>
template <typename Y>
std::set<std::string> esapi::Trie<T>::TrieProxy<Y>::keySet() {

}

template <typename T>
template <typename Y>
std::set<Y> esapi::Trie<T>::TrieProxy<Y>::values() {

}

template <typename T>
template <typename Y>
std::set< std::pair<std::string,Y> > esapi::Trie<T>::TrieProxy<Y>::entrySet() {

}

template <typename T>
template <typename Y>
int esapi::Trie<T>::TrieProxy<Y>::hashCode() {

}*/

template <typename T>
template <typename U>
esapi::Trie<T>::Unmodifiable<U>::Unmodifiable(const Trie<U> & toWrap) : TrieProxy<U>(toWrap){}

template <typename T>
template <typename U>
U esapi::Trie<T>::Unmodifiable<U>::put(std::string, U) throw (esapi::UnsupportedOperationException) {
	throw UnsupportedOperationException("put(..) is unsupported for Unmodifiable Trie.");
}

template <typename T>
template <typename U>
U esapi::Trie<T>::Unmodifiable<U>::remove(std::string) throw (esapi::UnsupportedOperationException) {
	throw UnsupportedOperationException("remove(..) is unsupported for Unmodifiable Trie.");
}

template <typename T>
template <typename U>
void esapi::Trie<T>::Unmodifiable<U>::putAll(std::map<std::string,U>) throw (esapi::UnsupportedOperationException) {
	throw UnsupportedOperationException("putAll(..) is unsupported for Unmodifiable Trie.");
}

template <typename T>
template <typename U>
void esapi::Trie<T>::Unmodifiable<U>::clear() throw (esapi::UnsupportedOperationException) {
	throw UnsupportedOperationException("clear() is unsupported for Unmodifiable Trie.");
}

/*
template <typename T>
template <typename U>
std::set<std::string> esapi::Trie<T>::Unmodifiable<U>::keySet() {

}

template <typename T>
template <typename U>
std::set<U> esapi::Trie<T>::Unmodifiable<U>::values() {

}

template <typename T>
template <typename U>
std::set< std::pair<std::string,U> > esapi::Trie<T>::Unmodifiable<U>::entrySet() {

}*/

template <typename T>
template <typename V>
esapi::Trie<V>* esapi::Trie<T>::Util<V>::unmodifiable(const Trie<V> & toWrap){
	return new Unmodifiable<V>(toWrap);
}