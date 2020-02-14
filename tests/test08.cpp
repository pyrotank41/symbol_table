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


TEST_CASE("(8) Throw: catching error") 
{
    symtable<string, string>  table;
    REQUIRE_THROWS(table.exitScope());
    REQUIRE_THROWS(table.curScope());
}