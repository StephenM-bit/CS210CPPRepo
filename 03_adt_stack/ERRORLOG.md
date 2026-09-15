## September 14

error: no declaration matches 'void Stack::pop()'
22 | void Stack::pop() {

I defined pop() as returning void, but 
Stack.h declared it as returning int, so 
the declaration and definition did not 
match.

I redefine pop() to return int.

## September 14

error: 's' was not declared in this scope
24 |     if (s.isEmpty()==false) {

I tried to call isEmpty() using s.isEmpty()
inside Stack.cpp, but the object s was
created in main.cpp and is not available
inside the Stack member function.

I changed the condition to call the member
function directly:isEmpty().