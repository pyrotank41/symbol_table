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


TEST_CASE("(5) lookup: looping for keys in different scopes") 
{
    symtable<string, string>  table;

    table.enterScope("gloabl");
    table.insert("x", "char");
    table.insert("y", "int");
    table.insert("existInAll", "type1");
    
    REQUIRE(table.size() == 3);
    REQUIRE(table.numscopes() == 1);

    table.enterScope("notCur");
    table.insert("i", "char");
    table.insert("j", "double");
    table.insert("existInAll", "type2");

    table.enterScope("curr");
    table.insert("a", "string");
    table.insert("b", "char");
    table.insert("existInAll", "type3");


    REQUIRE(table.size() == 9);
    REQUIRE(table.numscopes() == 3);

    string symbol;

    // checking in the all scopes.
    REQUIRE(table.lookup("i", symbol));
    REQUIRE(symbol == "char");

    // checking in current scope
    REQUIRE(table.lookup("b", symbol, symtable<string,string>::ScopeOption::CURRENT));
    REQUIRE(symbol == "char");

    //looking in global scope
    REQUIRE(table.lookup("x", symbol, symtable<string,string>::ScopeOption::GLOBAL));
    REQUIRE(symbol == "char");

    // checking in the all scopes and making sure the order of check is correct.
    REQUIRE(table.lookup("existInAll", symbol));
    REQUIRE(symbol == "type3");

    table.exitScope();
    REQUIRE(table.lookup("existInAll", symbol));
    REQUIRE(symbol == "type2");


    // looking for keys that doesnt exist
    REQUIRE(!table.lookup("fake", symbol, symtable<string,string>::ScopeOption::CURRENT));
    REQUIRE(!table.lookup("fake", symbol, symtable<string,string>::ScopeOption::GLOBAL));
    REQUIRE(!table.lookup("fake", symbol));

    // looking for keys that doesnt exist in that scope
    REQUIRE(!table.lookup("x", symbol, symtable<string,string>::ScopeOption::CURRENT));
    REQUIRE(!table.lookup("i", symbol, symtable<string,string>::ScopeOption::GLOBAL));

    //looking for keys that doesnt belong to that scope.
    
    // making sure symbol wasnt changed
    REQUIRE(symbol == "type2");
    
}