// Copyright 2022 Vitulin Ivan

#include <gtest/gtest.h>
#include <string>

#include "include/B64.h"

TEST(Vitulin_Ivan_Base64, Base64_encode_test1) {
    std::string test_string = "QWERTY";
    std::string exp_result = "UVdFUlRZ";

    std::string encoded_string = encode(&test_string[0], test_string.size());

    ASSERT_EQ(encoded_string, exp_result);
}

TEST(Vitulin_Ivan_Base64, Base64_encode_test2) {
    std::string test_string = "QwErTy1";
    std::string exp_result = "UXdFclR5MQ==";

    std::string encoded_string = encode(&test_string[0], test_string.size());

    ASSERT_EQ(encoded_string, exp_result);
}

TEST(Vitulin_Ivan_Base64, Base64_encode_test3) {
    std::string test_string = "QwErTy12";
    std::string exp_result = "UXdFclR5MTI=";

    std::string encoded_string = encode(&test_string[0], test_string.size());

    ASSERT_EQ(encoded_string, exp_result);
}

TEST(Vitulin_Ivan_Base64, Base64_decode_test1) {
    bool nonCorr = false;
    int indForResStr = 0;
    std::string test_string = "UVdFUlRZ";
    std::string exp_s = "QWERTY";

    auto dec_str = decode(test_string);

    for (unsigned int i = 0; i < dec_str.size(); ++i) {
        for (unsigned int j = indForResStr; j < exp_s.size(); ++j) {
            if (static_cast<char>(dec_str[i]) != static_cast<char>(exp_s[j])) {
                nonCorr = true;
                break;
            } else {
                indForResStr += 1;
                break;
            }
        }
        if (nonCorr != true)
            break;
        else
            continue;
    }

    ASSERT_FALSE(nonCorr);
}

TEST(Vitulin_Ivan_Base64, Base64_decode_test2) {
    bool nonCorr = false;
    int indForResStr = 0;
    std::string test_string = "UXdFclR5MQ==";
    std::string exp_s = "QwErTy1";

    auto dec_str = decode(test_string);

    for (unsigned int i = 0; i < dec_str.size(); ++i) {
        for (unsigned int j = indForResStr; j < exp_s.size(); ++j) {
            if (static_cast<char>(dec_str[i]) != static_cast<char>(exp_s[j])) {
                nonCorr = true;
                break;
            } else {
                indForResStr += 1;
                break;
            }
        }
        if (nonCorr != true)
            break;
        else
            continue;
    }

    ASSERT_FALSE(nonCorr);
}

TEST(Vitulin_Ivan_Base64, Base64_decode_test3) {
    bool nonCorr = false;
    int indForResStr = 0;
    std::string test_string = "UXdFclR5MTI=";
    std::string exp_s = "QwErTy12";

    auto dec_str = decode(test_string);

    for (unsigned int i = 0; i < dec_str.size(); ++i) {
        for (unsigned int j = indForResStr; j < exp_s.size(); ++j) {
            if (static_cast<char>(dec_str[i]) != static_cast<char>(exp_s[j])) {
                nonCorr = true;
                break;
            } else {
                indForResStr += 1;
                break;
            }
        }
        if (nonCorr != true)
            break;
        else
            continue;
    }

    ASSERT_FALSE(nonCorr);
}
