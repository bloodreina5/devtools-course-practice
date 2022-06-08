    // Copyright 2022 Melnikov Aleksei

#ifndef MODULES_MELNIKOV_HUFFMAN_INCLUDE_HUFFMAN_CODE_H_
#define MODULES_MELNIKOV_HUFFMAN_INCLUDE_HUFFMAN_CODE_H_

#define HEAP_CAPACITY 10000
#define BEGIN_CHAR (char) 0
#define END_CHAR (char) 127

#include<tgmath.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<cmath>
#include<unordered_map>
#include<map>
#include<set>
#include<sstream>
#include <string>
#include <utility>


using std::cout;
using std::endl;
using std::string;
using std::map;
using std::stringstream;
using std::pair;
using std::set;

class Node {
 public:
    char symbol;
    int freq;
    Node* left, * right;
    ~Node() {
        delete[] left;
        delete[] right;
    }
};



class MinHeap {
 public:
    MinHeap() {
    }

    int heap_size = 0;
    Node** heap_arr = 0;

    explicit MinHeap(map<char, int> symbol_map) {
        this->heap_size = symbol_map.size();
        if (heap_size > HEAP_CAPACITY) {
            cout << "Heap size can't exceed " << HEAP_CAPACITY << " ." << endl;
            return;
        }

        this->heap_arr = new Node * [HEAP_CAPACITY];
        map<char, int>::iterator itr;

        for (itr = symbol_map.begin(); itr != symbol_map.end(); ++itr) {
            int index = distance(symbol_map.begin(), itr);
            this->heap_arr[index] = create_node(itr->first, itr->second);
        }

        this->build_heap();
    }

    Node* create_node(char symbol, int freq,
        Node* left = nullptr, Node* right = nullptr) {
        Node* node = new Node;
        node->symbol = symbol;
        node->freq = freq;
        node->left = left;
        node->right = right;
        return node;
    }

    int add_node(char symbol, int freq,
        Node* left = nullptr, Node* right = nullptr) {
        if (this->heap_size == HEAP_CAPACITY) {
            cout << "Heap capacity limit reached. " << endl;
            return 0;
        }

        this->heap_arr[this->heap_size++] =
            create_node(symbol, freq, left, right);

        for (int i = this->heap_size - 1; i > 0 && this->
            heap_arr[this->get_parent(i)]->freq > this->heap_arr[i]->freq;) {
            int j = this->get_parent(i);
            this->swap_heap_nodes(i, j);
            i = j;
        }

        return 0;
    }


    int get_left_child(int i);
    int get_right_child(int i);
    int get_parent(int i);
    int build_heap();    // Build heap in O(n) time.
    int min_heapify(int index);
    int swap_heap_nodes(int i, int j);
    int print_heap();
    int get_huffman_code(Node*, map<char, string>&, string);
    int get_bit_size(int n);
    string get_binary_string(unsigned int n, unsigned int);
    string get_symbols_for_bit_length(int* , int);
    string get_encoded_text(string, map<char, string>);
    string get_decoded_text(string, map<string, char>);
    map<string, char> get_canonical_codebook(int* bit_codes);
    map<char, int> get_frequency_map(string text);
    map<char, string> get_canonical_code(map<char, string>);
    int* get_bit_length_codes(map<char, string>);

    MinHeap build_huffman_tree(MinHeap min_heap) {
        while (min_heap.heap_size > 1) {
            Node* left_node = min_heap.extract_min();
            Node* right_node = min_heap.extract_min();
            min_heap.add_node('$', left_node->freq +
                right_node->freq, left_node, right_node);
        }

        return min_heap;
    }

    Node* extract_min() {
        Node* min_node = this->heap_arr[0];
        this->swap_heap_nodes(0, this->heap_size - 1);
        this->heap_size--;
        this->min_heapify(0);

        return min_node;
    }
};


#endif  // MODULES_MELNIKOV_HUFFMAN_INCLUDE_HUFFMAN_CODE_H_
