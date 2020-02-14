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


TEST_CASE("(4) curscope: testing current scope") 
{
    symtable<string, string>  table;

    table.enterScope("gloabl");
    table.insert("x", "char");
    table.insert("y", "int");
    
    REQUIRE(table.size() == 2);
    REQUIRE(table.numscopes() == 1);

    table.enterScope("yoyo");
    table.insert("i", "char");
    table.insert("j", "double");

    REQUIRE(table.size() == 4);
    REQUIRE(table.numscopes() == 2);

    //cure scope is yoyo.
    symtable<string, string>::Scope s = table.curScope();
    
    //editing the temp scope
    s.Name = "copy";
    s.Symbols.end()->second = "string";

    //checking it with orignal scope.
    REQUIRE(s.Name != table.curScope().Name);
    REQUIRE(s.Symbols.end()->second != table.curScope().Symbols.end()->second);

    // clearing the Scope and checking its size.
    s.Symbols.clear();
    REQUIRE(s.Symbols.size() == 0);

    // checking if changes were made to orignal curScope.
    REQUIRE(table.curScope().Symbols.size() == 2);

    
}