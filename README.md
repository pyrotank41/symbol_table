# symbol_table

Symbol Table: a symbol table is a stack of scopes, typically used by a
compiler to keep track of symbols in a program (functions, variables,
types, etc.).  In most programming languages, you "enter scope" when you 
see {, and "exit scope" when you see the corresponding }.  Example:

int main()
{              <-- enterScope()
   int i;      <-- enter "i" into symbol table as type "int"
   .
   .
   while (true)
   {              <-- enterScope()
      char i;     <-- enter "i" into symbol table as type "char"

Notice there are two variables named "i", which is legal because
they are in different scopes.
