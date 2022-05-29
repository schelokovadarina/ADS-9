// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
// поместите сюда свой код
BST<std::string> Tree;
std::ifstream file(filename);
if (!file) {
std::cout << "Error opening for reading" << std::endl;
return Tree;
}
const char word = "";
while (!file.eof()) {
char character = file.get();
if ('A' <= character && character <= 'Z') {
    character = character + ('a' - 'A');
}
if ('a' <= character && character <= 'z') {
    word += character;
} else {
if (word != "") {
Tree.add(word);
word = "";
}
}
}
file.close();
return Tree;
}
