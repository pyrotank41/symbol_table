//
// A symtable unit test based on Catch framework
//
// Karan Singh Kochar
// U. of Illinois, Chicago
// CS 251, Spring 2020
// Project #03: symtable
//
#include <iostream>
#include "symtable.h"
#include "catch.hpp"

using namespace std;


TEST_CASE("(3) insert function: dublicate key insert") 
{
    symtable<string, string>  table;

    table.enterScope("gloabl");
    table.insert("i", "char");
    table.insert("i", "int");
    
    REQUIRE(table.size() == 1);
    REQUIRE(table.numscopes() == 1);

    table.enterScope("yoyo");
    table.insert("i", "char");
    table.insert("i", "int");
    
    REQUIRE(table.size() == 2);
    REQUIRE(table.numscopes() == 2);

}