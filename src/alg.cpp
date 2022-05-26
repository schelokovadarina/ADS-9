// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
BST<std::string>tree;
char lowercase = 'a' - 'A';
std::ifstream file(filename);
if (!file) {
    throw std::string("Error opening for reading ");
    return tree;
}
std::string word = "";
while (!file.eof()) {
    char character = file.get();
    if (('A' <= character && character <= 'Z') || ('a' <= character && character <= 'z')) {
        if ('A' <= character && character <= 'Z') {
            character += ('a' - 'A');
        word += character;
    }
    else if (word != "") {
        tree.add(word);
        word = "";
    }
}
file.close();
return tree
}
