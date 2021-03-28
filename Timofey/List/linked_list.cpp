//
// Created by nightingale on 3/27/21.
//

#include <iostream>
#include <string>

#include "node.hpp"

using std::cout;
using std::string;

int main()
{
    List<std::string> strList;

    list_init(strList);

    list_insert(strList, string("Hello"));
    list_insert(strList, string("Vasyl"));

    list_print(strList, cout);

    list_destroy(strList);

    return 0;
}