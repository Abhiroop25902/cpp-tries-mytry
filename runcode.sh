#!/bin/bash
g++ main.cpp -o main
valgrind --tool=memcheck --leak-check=full ./main
rm ./main