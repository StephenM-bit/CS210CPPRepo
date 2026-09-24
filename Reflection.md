1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
   Name exactly what each one frees, and name the two new calls back in the program responsible
   for putting them on the heap in the first place.

delete doomed->data frees the T object created by calls like new int(10) and delete doomed frees the Node<T> created by new Node<T>(value) in addFront(). They are both needed because the data and the node are two separate objects on the heap

2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?

Switching from T data[CAPACITY] to T* data [CAPACITY] means the array now stores pointers to objects created with new, like new Data(1,"Alice"), so the destructor needs to delete those objects. If I forgot to write one, the heap objects would not be deleted and would cause memory leaks.
   
3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?

addFront() has ownership of the pointer because hte list stores it and later deletes it. search() can use the pointer to compare values but cannot delete it.

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?

The two mechanisms that made that possible are inheritance and virtual functions. LinkedList and ArrayList both inherit from List, so main.cpp can use either one through List without having to change the code.

5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.

Override helps make sure that a function in a class like LinkedList correctly matches a function in List. If I accidentally changed a parameter of search from T* to T, override would catch the mistake instead of letting me create a different function.