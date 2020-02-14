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

    cout << "all----------------" << endl;
    table.dump(std::cout);
    cout << "\nglobal----------------" << endl;
    table.dump(std::cout, symtable<string,string>::ScopeOption::GLOBAL);
    cout << "\ncurrent----------------" << endl;
    table.dump(std::cout, symtable<string,string>::ScopeOption::CURRENT);
}   