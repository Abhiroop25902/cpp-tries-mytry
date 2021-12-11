#!/bin/bash
g++ ./trie.cpp -o trie
valgrind --tool=memcheck --leak-check=full ./trie
rm ./trie