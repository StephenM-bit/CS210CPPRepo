1. Why does concat only need to work between two lists of the same representation? What would
   you have to do differently, or what would go wrong, if you tried to make it work between a
   LinkedList and an ArrayList?

concat only works between the same type of list because they store their data differently. A LinkedList uses nodes and pointers, while an ArrayList uses an array. If I tried to combine the two different types, I wouldn't be able to directly connect their data, so my code checks the type and rejects it if they don't match.

2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.

In my LinkedList::reverse(), the three pointers are previous, current, and next. current is the node I'm currently reversing, previous keeps track of the part I've already reversed, and next saves the rest of the list before I change current->next. If I lost next, I could lose access to the rest of the list, and if I lost previous or current, I would not be able to correctly reconnect the nodes.

3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?

For addAnywhere, the valid range is from 0 through size, because adding at size means adding to the end. For deleteAnywhere, the valid range is from 0 through size - 1, since there has to already be an element at that position to delete. In my implementations, an invalid position prints an error message and returns without changing the list.

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?

I had to walk to the end of the linked list in concat because I needed to connect the other list after the current last node. addFront and deleteFront only work with the head, so they don't need to search through the list. If I had a tail pointer, concat could connect the lists directly and would be faster, but I would also have to update the tail pointer whenever nodes were added or removed, especially when the list became empty or a new last node was created.

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.

For my ArrayList::deleteAnywhere, the elements after the position being deleted have to shift one position to the left. This fills the empty spot and keeps the elements in the correct order. If I shifted in the wrong direction, I could overwrite an element before I had moved it, causing data to be lost.

6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing.

The line in my main.cpp that actually changes the direction of play is table->reverse();. The list is printed before and after this call so the change in turn order is visible. If I removed the call, the players would stay in the same order after the Reverse card, so the game would not actually change direction.