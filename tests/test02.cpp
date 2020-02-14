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

    // goinf to multiple scopes 
    int num= 100000;
    for(int i = 0; i < num; i++){
        table.enterScope(""+i);
    }
    REQUIRE(table.numscopes() == num);
    
    //getting ouf of multiple scopes
    for(int i = 0; i < num; i++){
        table.exitScope();
    }
    REQUIRE(table.numscopes() == 0); 

    //some extra tests for checking exceptions thrown.
    table.enterScope("test");
    table.exitScope();
    REQUIRE_THROWS(table.exitScope());
    table.enterScope("test");
    table.exitScope();
    REQUIRE(table.numscopes() == 0); 



}