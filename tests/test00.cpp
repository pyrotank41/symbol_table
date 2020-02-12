#include <iostream>

#include "symtable.h"

#include "catch.hpp"

using namespace std;


TEST_CASE("(0) initializing symtable") 
{
    symtable<string, string>  table;

    REQUIRE(table.size() == 0);
    REQUIRE(table.numscopes() == 0);
}