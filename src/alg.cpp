// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
// поместите сюда свой код
BST<std::string> tree;
std::ifstream file(filename);
if (!file) {
    throw std::string("Error opening for reading ");
    return tree;
}
std::string w = "";
while (!file.eof()) {
    char character = file.get();
    if (('A' <= character && character <= 'Z') || ('a' <= character && character <= 'z')) {
        if ('A' <= character && character <= 'Z') {
            character += ('a' - 'A');
        }
        if ('a' <= character && character <= 'z') {
            w += character;
        } else {
            tree.add(w);
            w = "";
        }
    }
}
file.close();
return tree;
}


