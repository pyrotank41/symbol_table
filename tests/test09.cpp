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


TEST_CASE("(9) dump") 
{
    symtable<int, int>  table;

    table.enterScope("L1");
    table.insert(1,-1);
    table.insert(2,-2);
    table.insert(3,-3);
    table.insert(4,-4);
    table.insert(5,-5);
    table.insert(6,-6);
    table.insert(7,-7);

    table.enterScope("L2");
    table.insert(1,2);
    table.insert(2,4);
    table.insert(3,6);

    table.enterScope("L3_v2");
    table.insert(1,26);
    table.insert(2,48);

    table.enterScope("L4");

    table.dump(std::cout);
	table.dump(std::cout, symtable<int,int>::ScopeOption::CURRENT);
    table.dump(std::cout, symtable<int,int>::ScopeOption::GLOBAL);

}