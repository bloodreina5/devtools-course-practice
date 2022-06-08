// Copyright 2022 Melnikov Aleksei
#include "include/huffman_code.h"
#include <map>
#include <utility>
#include <string>
#include <set>

#define HEAP_CAPACITY 10000
#define BEGIN_CHAR (char) 0
#define END_CHAR (char) 127

int b_ch = static_cast<int>(BEGIN_CHAR);
int e_ch = static_cast<int>(END_CHAR);

int DICT_SIZE = e_ch - b_ch + 1;

int MinHeap::get_left_child(int i) {
    return 2 * i + 1;
}

int MinHeap::get_right_child(int i) {
    return 2 * i + 2;
}

int MinHeap::get_parent(int i) {
    return ceil((static_cast<float>(i) / 2) - 1);
}

int MinHeap::build_heap() {
    int last_parent_index = this->heap_size / 2 - 1;
    for (int i = last_parent_index; i >= 0; --i) {
        this->min_heapify(i);
    }

    return 0;
}

int MinHeap::print_heap() {
    for (int i = 0; i < this->heap_size; ++i) {
        cout << this->heap_arr[i]->symbol << " - "
            << this->heap_arr[i]->freq << endl;
    }

    return 0;
}

int MinHeap::swap_heap_nodes(int i, int j) {
    Node* temp = this->heap_arr[i];
    this->heap_arr[i] = this->heap_arr[j];
    this->heap_arr[j] = temp;
    return 0;
}

int MinHeap::min_heapify(int index) {
    int min_index = index;
    int left_child = this->get_left_child(index);
    int right_child = this->get_right_child(index);

    if (left_child <= this->heap_size - 1 &&
        this->heap_arr[left_child]->freq < this->heap_arr[min_index]->freq) {
        min_index = left_child;
    }

    if (right_child <= this->heap_size - 1 &&
        this->heap_arr[right_child]->freq < this->heap_arr[min_index]->freq) {
        min_index = right_child;
    }

    if (min_index != index) {
        this->swap_heap_nodes(index, min_index);
        this->min_heapify(min_index);
    }

    return 0;
}


int MinHeap::get_huffman_code(Node* huffman_node,
    map<char, string>& encoded_symbols, string code = "") {
    if (!huffman_node->left && !huffman_node->right) {
        encoded_symbols[huffman_node->symbol] = code;
        return 0;
    }

    get_huffman_code(huffman_node->left, encoded_symbols, code + "0");
    get_huffman_code(huffman_node->right, encoded_symbols, code + "1");

    return 0;
}

bool comparator(pair<char, string> left, pair<char, string> right) {
    return left.second.size() == right.second.size() ? left.first
        < right.first : left.second.size() < right.second.size();
}

int MinHeap::get_bit_size(int n) {
    int bits = 1;
    while (pow(2, bits) <= n) {
        ++bits;
    }

    return bits;
}

string MinHeap::get_binary_string(unsigned int n,
    unsigned int bit_size = -1) {
    stringstream stream;
    string reverse_binary, binary_str;
    do {
        stream << n % 2;
        n /= 2;
    } while (n);
    unsigned int sizeB = bit_size;
    if (sizeB != -1u && stream.str().size() < sizeB) {
        unsigned int padding_size = sizeB - stream.str().size();
        while (padding_size--) {
            stream << '0';
        }
    }

    reverse_binary = stream.str();
    binary_str.assign(reverse_binary.rbegin(), reverse_binary.rend());


    return binary_str;
}

map<char, string> MinHeap::get_canonical_code(map<char, string> huffman_code) {
    MinHeap c1;
    set<pair<char, string>, bool(*)(pair<char, string>, pair<char, string>)>
        ordered_huffman(huffman_code.begin(), huffman_code.end(), &comparator);
    int current_val, previous_bit_length;
    current_val = 0;
    previous_bit_length = static_cast<int>
        (ordered_huffman.begin()->second.size());

    map<char, string> canonical_code;

    for (pair<char, string> current : ordered_huffman) {
        int shift_bits = current.second.size() - previous_bit_length;
        current_val = current_val << shift_bits;
        canonical_code[current.first] = c1.get_binary_string
        (current_val, current.second.size());
        ++current_val;
        previous_bit_length = current.second.size();
    }

    return canonical_code;
}

int* MinHeap::get_bit_length_codes(map<char, string> canonical_code) {
    int* bit_codes = new int[DICT_SIZE];

    for (int i = 0; i < DICT_SIZE; ++i) {
        bit_codes[i] = canonical_code[static_cast<char>
            ((static_cast<int>(BEGIN_CHAR) + i))].size();
    }

    return bit_codes;
}

string MinHeap::get_symbols_for_bit_length(int* bit_codes, int bit_length) {
    string symbols = "";

    for (int i = 0; i < DICT_SIZE; ++i) {
        if (bit_codes[i] == bit_length) {
            symbols += static_cast<char>(BEGIN_CHAR) + i;
        }
    }

    return symbols;
}

map<string, char> MinHeap::get_canonical_codebook(int* bit_codes) {
    MinHeap c1;
    map<string, char> codebook;
    int current_val, previous_bit_size;
    current_val = 0;
    previous_bit_size = 0;

    for (int bit_length = 1; bit_length < DICT_SIZE; ++bit_length) {
        string symbols = c1.get_symbols_for_bit_length(bit_codes, bit_length);
        previous_bit_size = bit_length - 1;

        for (unsigned int i = 0; i < symbols.size(); ++i) {
            int shift_bits = bit_length - previous_bit_size;
            current_val = current_val << shift_bits;
            string binary_str = c1.get_binary_string(current_val, bit_length);
            codebook[binary_str] = symbols[i];
            previous_bit_size = bit_length;
            ++current_val;
        }
    }

    return codebook;
}

string MinHeap::get_encoded_text(string text,
    map<char, string> canonical_codes) {
    string encoded_text = "";

    for (unsigned int i = 0; i < text.size(); ++i) {
        encoded_text += canonical_codes[text[i]];
    }

    return encoded_text;
}

string MinHeap::get_decoded_text(string encoded_text,
    map<string, char> canonical_codes) {
    unsigned int start, length;
    string decoded_text = "";
    start = 0;
    length = 1;

    while (start + length <= encoded_text.size()) {
        string current = encoded_text.substr(start, length);
        if (canonical_codes.find(current) != canonical_codes.end()) {
            decoded_text += canonical_codes[current];
            start += length;
            length = 1;
            continue;
        }

        ++length;
    }

    return decoded_text;
}


map<char, int> MinHeap::get_frequency_map(string text) {
    map<char, int> frequency_map;

    for (unsigned int i = 0; i < text.size(); ++i) {
        if (frequency_map.find(text[i]) == frequency_map.end()) {
            frequency_map[text[i]] = 1;
            continue;
        }

        ++frequency_map[text[i]];
    }

    return frequency_map;
}


