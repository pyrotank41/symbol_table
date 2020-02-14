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


TEST_CASE("(7) lookup: trying to break the table") 
{
    int numScopes = 10;
    int numSymbols = 100000;

    symtable<int, string> table;

    table.enterScope("global");
    //inserting multiple Symbols in one scope.
    for(int symbol = 0; symbol < numSymbols; ++symbol)
    {
        table.insert(symbol,""+(symbol+5));
    }

    REQUIRE(table.size() == numSymbols);
    REQUIRE(table.numscopes() == 1);
    table.exitScope();

    // inserting multiple symbols in multiple scopes.
    for (int i = 0; i < numScopes; i++)
    {
        table.enterScope("test"+i);
        for (int j = 0; j < numSymbols; j++)
        {
            table.insert(j,""+i);
        }
    }

    REQUIRE(table.size() == numSymbols*numScopes);
    REQUIRE(table.numscopes() == numScopes);
    
    // exitting all the scopes.
    for (int i = 0; i < numScopes; i++)
    {
        table.exitScope();
    }

    REQUIRE(table.size() == 0);
    REQUIRE(table.numscopes() == 0);
}