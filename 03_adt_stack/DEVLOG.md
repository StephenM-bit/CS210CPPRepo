## September 13 2026
I chose -1 to represent an empty stack
because the first valid array index is 0.

## September 13 2026
I decided that when the stack is empty,
`pop()` and `peek()` will print
"Stack is empty" and return -1. For a full
stack, `push()` will print "Stack is full"
and will not add the value to the stack.
I chose these as alternatives to exceptions.

## September 14 2026
I tested the stack using `main.cpp`. I 
pushed many values, checked the top 
and size, and popped values to make sure 
the last-in, first-out behavior worked
correctly. I also tested the empty and 
full conditions to make sure the
error handling worked as I intended.