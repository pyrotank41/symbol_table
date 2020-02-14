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

TEST_CASE("(2) enterscope and exitscope function") 
{
    symtable<string, string>  table;

    table.enterScope("gloabl");
    table.insert("i", "char");
    table.insert("j", "int");
    
    REQUIRE(table.size() == 2);
    REQUIRE(table.numscopes() == 1);

    table.enterScope("yoyo");
    table.insert("x", "double");
    table.insert("y", "string");

    REQUIRE(table.size() == 4);
    REQUIRE(table.numscopes() == 2);

    table.exitScope();
    REQUIRE(table.size() == 2);
    REQUIRE(table.numscopes() == 1);

    table.exitScope();
    REQUIRE(table.size() == 0);
    REQUIRE(table.numscopes() == 0); 
}