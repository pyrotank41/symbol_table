#include <iostream>
#include "symtable.h"
#include "catch.hpp"

using namespace std;


TEST_CASE("(6) Multi table testing") 
{
    symtable<string, string>  table1;

    table1.enterScope("gloabl");
    table1.insert("x", "char");
    table1.insert("y", "int");

    symtable<string, string>  table2;
    table2.enterScope("global");
    table2.insert("i", "char");
    table2.insert("j", "double");
    table2.insert("k", "char");
    table2.insert("l", "int");

    // check for table if they are effecting earch other. 
    REQUIRE(table1.size() == 2);
    REQUIRE(table1.numscopes() == 1);
    REQUIRE(table2.size() == 4);
    REQUIRE(table2.numscopes() == 1);

    // checking if enterscope is effecting another table.
    table2.enterScope("scope2");
    table2.insert("i", "char");
    table2.insert("j", "double");

    REQUIRE(table1.size() == 2);
    REQUIRE(table1.numscopes() == 1);
    REQUIRE(table2.size() == 6);
    REQUIRE(table2.numscopes() == 2);

    // some operations on table1
    table1.enterScope("scope2");
    table1.enterScope("scope3");
    table1.insert("i", "char");
    table1.insert("j", "double");

    REQUIRE(table1.size() == 4);
    REQUIRE(table1.numscopes() == 3);
    
    table1.exitScope();
    REQUIRE(table1.size() == 2);
    REQUIRE(table1.numscopes() == 2);

    // making sure table2 is not being efficted by table one operations
    REQUIRE(table2.size() == 6);
    REQUIRE(table2.numscopes() == 2);
    
}