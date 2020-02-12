
#include <iostream>

#include "symtable.h"

int main()
{
    symtable<string, string>  table;
    
  
    cout << (table.size() == 0) << endl;
    cout << (table.numscopes() == 0) << endl;

    table.enterScope("global");
    
    table.insert("i", "int");
    table.insert("j", "double");
    
    cout << (table.size() == 2) << endl;
    cout << (table.numscopes() == 1) << endl;
    
    table.enterScope("x");
    table.insert("k", "char");
    
    cout << (table.size() == 3) << endl;
    cout << (table.numscopes() == 2) << endl;

    //
    // these lookups should both succeed:
    //
    string symbol;
    
    cout << (table.lookup("k", symbol)) << endl;
    cout << (symbol == "char") << endl;
    
    cout << (table.lookup("i", symbol)) << endl;
    cout << (symbol == "int") << endl;
    
    cout << (table.lookup("j", symbol)) << endl;
    cout << (symbol == "double") << endl;
    
    //
    // this lookup should return false:
    //
    cout << ((!table.lookup("x", symbol))) << endl;



    return 0;
}