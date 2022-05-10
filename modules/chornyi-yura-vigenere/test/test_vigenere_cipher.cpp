// Copyright 2022 Chornyi Yura

#include <gtest/gtest.h>

#include <string>
#include <tuple>

#include "include/vigenere_cipher.h"
#include "include/vigenere_cipher_app.h"

TEST(VigenereCipherConstructor, ConstructorWithoutParameters) {
  ASSERT_NO_THROW(VigenereCipher());
}

TEST(VigenereCipherConstructor, ConstructorWithTwoParameters) {
  ASSERT_NO_THROW(VigenereCipher("TEST", "QWER"));
}

TEST(VigenereCipherConstructor, ConstructorWithTwoParametersNotEqualSize) {
  ASSERT_ANY_THROW(VigenereCipher("TEST", ""));
}

TEST(VigenereCipherConstructor, ConstructorWithTwoParametersWithNotAllowChar) {
  ASSERT_ANY_THROW(VigenereCipher("TE12", "QW12"));
}

TEST(VigenereCipherMethods, CheckDefaultValue) {
  VigenereCipher v;

  ASSERT_EQ(v.getOriginal(), "");
  ASSERT_EQ(v.getKey(), "");
}

TEST(VigenereCipherMethods, CheckCustomValue) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_EQ(v.getOriginal(), "TEST");
  ASSERT_EQ(v.getKey(), "QWER");
}

TEST(VigenereCipherMethods, CheckCipheringWithoutParameters) {
  VigenereCipher v;

  std::string cipher = v.cipher();

  ASSERT_EQ(cipher, "");
}

TEST(VigenereCipherMethods, CheckCipheringWithParameters) {
  VigenereCipher v("ATTACKATDAWN", "LEMONLEMONLE");

  std::string cipher = v.cipher();

  ASSERT_EQ(cipher, "LXFOPVEFRNHR");
}

TEST(VigenereCipherMethods, CheckSetOriginalEqualKey) {
  VigenereCipher v("TEST", "QWER");

  v.setOriginal("QQQQ");

  ASSERT_EQ(v.getOriginal(), "QQQQ");
}

TEST(VigenereCipherMethods, CheckSetOriginalNotEqualKey) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setOriginal("T"));
}

TEST(VigenereCipherMethods, CheckSetOriginalWithNotAllowedCharacter) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setOriginal("TE12"));
}

TEST(VigenereCipherMethods, CheckSetKeyEqualOriginal) {
  VigenereCipher v("TEST", "QWER");

  v.setKey("QQQQ");

  ASSERT_EQ(v.getKey(), "QQQQ");
}

TEST(VigenereCipherMethods, CheckSetKeyNotEqualOriginal) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setKey("Q"));
}

TEST(VigenereCipherMethods, CheckSetKeyWithNotAllowedCharacter) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setOriginal("QW12"));
}

TEST(VigenereCipherMethods, CheckSetPairWithEqualSize) {
  VigenereCipher v("TEST", "QWER");

  v.setPair("QWER", "TEST");

  ASSERT_EQ(v.getOriginal(), "QWER");
  ASSERT_EQ(v.getKey(), "TEST");
}

TEST(VigenereCipherMethods, CheckSetPairWithoutEqualSize) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setPair("TEST", "Q"));
}

TEST(VigenereCipherMethods, CheckSetPairWithNotAllowedCharacter) {
  VigenereCipher v("TEST", "QWER");

  ASSERT_ANY_THROW(v.setPair("TE12", "QW12"));
}
