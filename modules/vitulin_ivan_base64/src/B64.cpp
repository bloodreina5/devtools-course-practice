// Copyright 2022 Vitulin Ivan

#include "include/B64.h"
#include <string>
#include <vector>

char cd[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

unsigned char get_byte_from_digit(int sequence, int byte_pos) {
    return (sequence >> ((byte_pos - 1) * 8)) & 0xFF;
}

int get_six_bits_from_digit(int sequence, int position_first_bit) {
    return sequence >> (position_first_bit - 6);
}

int remove_six_bits_from_digit(int sequence, int position_first_bit) {
    int power = 1;
    for (int i = 0; i < position_first_bit - 6; ++i) {
        power *= 2;
    }
    return sequence % power;
}

std::string encode_three_bytes(int sequence) {
    std::string result;

    for (int bit_length = 24; bit_length != 0; bit_length -= 6) {
        char code = cd[get_six_bits_from_digit(sequence, bit_length)];
        result += code;
        sequence = remove_six_bits_from_digit(sequence, bit_length);
    }

    return result;
}

int get_bit_sequence(char* data, int size) {
    int sequence = 0;

    for (int i = 0; i < size; ++i) {
        sequence <<= 8;
        sequence += data[i];
    }

    return sequence;
}

std::string encode(char* data, int data_size) {
    std::string result = "";

    int round_data_size = data_size / 3;

    for (int i = 0; i < round_data_size; ++i) {
        int sequence = get_bit_sequence(data, 3);
        result += encode_three_bytes(sequence);
        data += 3;
    }

    if (data_size % 3 == 1) {
        int sequence = get_bit_sequence(data, 1);
        sequence <<= 16;
        result += encode_three_bytes(sequence);
        result[result.size() - 1] = '=';
        result[result.size() - 2] = '=';
    }

    if (data_size % 3 == 2) {
        int sequence = get_bit_sequence(data, 2);
        sequence <<= 8;
        result += encode_three_bytes(sequence);
        result[result.size() - 1] = '=';
    }

    return result;
}

void process_four_b64(const std::string& letters,
                            std::vector<unsigned char>* result) {
    int sequence = 0;
    int byte_count = 3;

    for (int i = 0; i < 4; ++i) {
        if (letters[i] == '=') {
            if (i == 3) {
                sequence >>= 2;
                byte_count = 2;
                break;
            }

            if (i == 2) {
                sequence >>= 4;
                byte_count = 1;
                break;
            }
        }

        size_t code = 0;
        for (int j = 0; j < 64; ++j) {
            if (letters[i] == cd[j]) {
                code = j;
                break;
            }
        }

        sequence <<= 6;
        sequence += code;
    }

    for (int i = byte_count; i > 0; --i) {
        unsigned char byt = get_byte_from_digit(sequence, i);
        result->push_back(byt);
    }
}

std::vector<unsigned char> decode(const std::string& encoded_string) {
    if (encoded_string.size() % 4 != 0)
        return std::vector<unsigned char>();

    std::vector<unsigned char> result;

    for (unsigned int i = 0; i < encoded_string.size(); i += 4)
        process_four_b64(encoded_string.substr(i, 4), &result);

    return result;
}
