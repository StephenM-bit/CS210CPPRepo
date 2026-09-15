## Reflection Questions

1.  after my Stack is constructed,
topIndex is set to -1 in my Stack::Stack()
constructor. I chose -1 because the first
valid position in my data array is index 0
. A topIndex of -1 means that there are no
elements in the stack. My isEmpty() 
function checks whether topIndex == -1 and
returns that result directly, so it does
not need any special cases.

2. When Stack::push() is called, it first
checks whether the stack is full by
calling isFull(). If it is not full,
topIndex is increased by one. Then the
new value is stored in data[topIndex].
The order matters because I need to move
topIndex to the next available position
before storing the new value. If I stored
the value first and then increased 
topIndex, the value would be placed at the
old top position instead of the new top
position, and the stack would not track
its top correctly.

3. push is O(1). My push() checks isFull(),
increases topIndex by one, and assigns the
value to one position in data. None of 
these operations depends on how many 
elements are in the stack.

pop is O(1). My pop() checks isEmpty(),
saves data[topIndex] into a variable, 
decreases topIndex by one, and returns 
the saved value. It does not move or 
search through the other elements.

peek is O(1). My peek() checks isEmpty()
and, when the stack is not empty, 
directly accesses data[topIndex]. It 
only looks at one array position.

isEmpty is O(1). My isEmpty() only 
compares topIndex to -1.

isFull is O(1). My isFull() only compares
topIndex to 99, which is the last valid
index in my 100-element array.

size is O(1). My size() only calculates
topIndex + 1. It does not have to count
the elements in the array.

4. When push() is called while my stack
is full, isFull() returns true, so
the code goes into the else statement.
It prints Stack is full. Since push()
has a return type of void, it does not
return a value. topIndex also does not
change, so it stays at 99. I chose this 
because the array only has 100 slots. 
Printing a message makes it clear that
the value could not be added without 
trying to expand the array.

5. When pop() is called on my empty stack,
isEmpty() returns true. My code prints
'Stack is empty' and returns -1. Since it
does not enter the part of the function 
that decreases topIndex, topIndex stays at
-1.
When peek() is called on my empty stack,
it also checks isEmpty(). It prints
Stack is empty and returns -1. 
topIndex does not change because peek()
never changes the stack.
I return -1 on both functions because they
both need to return an int.

6. I would need to create a resizable
array. With a resizable array, most 
push() operations could still be O(1),
but when the array fills up, the class 
would have to create a larger storage
area and copy the existing elements into
it. That resizing operation would take
O(n) time for that particular push.

7. One advantage of using a linked list
would be that the stack would not have a
fixed limit of 100 elements and could keep
adding nodes.
One disadvantage is that a linked list
needs pointers and separate nodes instead
of storing the values next to each other
in one array, which would make it more
complicated.