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

    table.enterScope("curscope");
    table.insert("i", "char");
    table.insert("j", "double");

    REQUIRE(table.size() == 4);
    REQUIRE(table.numscopes() == 2);

    //cure scope is yoyo.
    symtable<string, string>::Scope s = table.curScope();

    //editing the temp scope
    s.Name = "copy";
    s.Symbols.begin()->second = "string";

    //checking it with orignal scope.
    REQUIRE(table.curScope().Name != "copy");
    REQUIRE(table.curScope().Symbols.begin()->second != "string");
	
	// inserting and checking if our scope changes.
	table.insert("new","newS");
    REQUIRE(table.curScope().Symbols.size() == 3);
	REQUIRE(s.Symbols.size() == 2);
	
    // clearing the Scope and checking its size.
    s.Symbols.clear();
    REQUIRE(s.Symbols.size() == 0);
	REQUIRE(table.curScope().Symbols.size() == 3);

}