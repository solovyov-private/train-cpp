#include <iostream>
#include <string>
#include "node.hpp"

using std::cout;
using std::endl;
using std::string;

int main() {
    Node<string>* ptrStr = nullptr;
    ptrStr = insertNode(ptrStr, string("Hello"));
    ptrStr = insertNode(ptrStr, string("World"));
    ptrStr = insertNode(ptrStr, string("First"));

    return 0;
}
