// Copyright 2022 Chornyi Yura

#include "include/vigenere_cipher.h"

#include <sstream>
#include <stdexcept>
#include <string>

const char firstLetter = 'A';
const char lastLetter = 'Z';
const char numberAlpabet = 26;

bool checkString(const std::string& str) {
  for (auto element : str) {
    if (element < firstLetter || element > lastLetter) return false;
  }

  return true;
}

VigenereCipher::VigenereCipher() : m_original(), m_key() {}
VigenereCipher::VigenereCipher(const std::string& original,
                               const std::string& key)
    : m_original(original), m_key(key) {
  if (m_original.size() != m_key.size())
    throw std::invalid_argument("wrong length");
  if (!checkString(original))
    throw std::invalid_argument("invalid original character value");
  if (!checkString(key))
    throw std::invalid_argument("invalid key character value");
}

const std::string& VigenereCipher::getOriginal() const { return m_original; }
const std::string& VigenereCipher::getKey() const { return m_key; }

void VigenereCipher::setOriginal(const std::string& original) {
  if (m_original.size() != original.size())
    throw std::invalid_argument("wrong length");
  if (!checkString(original))
    throw std::invalid_argument("invalid original character value");

  m_original = original;
}
void VigenereCipher::setKey(const std::string& key) {
  if (m_key.size() != key.size()) throw std::invalid_argument("wrong length");
  if (!checkString(key))
    throw std::invalid_argument("invalid key character value");

  m_key = key;
}

void VigenereCipher::setPair(const std::string& original,
                             const std::string& key) {
  if (original.size() != key.size())
    throw std::invalid_argument("wrong length");
  if (!checkString(original))
    throw std::invalid_argument("invalid original character value");
  if (!checkString(key))
    throw std::invalid_argument("invalid key character value");

  m_original = original;
  m_key = key;
}

std::string VigenereCipher::cipher() const {
  std::stringstream cipher;

  for (std::string::size_type it = 0; it < m_original.size(); ++it) {
    cipher << static_cast<char>(firstLetter +
                                (m_original[it] + m_key[it]) % numberAlpabet);
  }

  return cipher.str();
}
