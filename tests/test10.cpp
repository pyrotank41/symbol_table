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


TEST_CASE("(10) dump()") 
{
    symtable<int, int>  table;

    table.enterScope("gloabl");
    table.insert(1, 1);
    table.insert(2, 1);
    table.insert(3, 1);
    table.insert(4, 1);
    table.insert(5, 1);

    table.enterScope("yoyo");
    table.insert(1, 1);
    table.insert(2, 1);
    table.insert(3, 1);
    REQUIRE(table.size() == 8);

    table.exitScope();
    REQUIRE(table.size() == 5);
    

    
}   