1. For every function you wrote (TODO 1 to 19), explain in your own words what it does and
give its time complexity in terms of n, the number of scenes. One short paragraph each.

TODO 1: The `Scene` constructor stores the scene data and creates exactly as many choice slots as the scene needs. It also initializes every slot to `nullptr`. If a scene has `k` choices, this takes O(k) time, which is O(n) in the worst case.

TODO 2: The `Scene` destructor deletes every child scene, deletes the choices array, and then deletes the scene's data. It takes O(n) time for the entire subtree owned by that scene.

TODO 3: The `isEnding` function checks whether the scene has zero choices. It only checks one variable, so it takes O(1) time.

TODO 4: The `getChoice` function checks whether the requested index is valid and returns the child at that index. It takes O(1) time.

TODO 5: The `setChoice` function checks the index and stores a child scene in the correct slot. It takes O(1) time.

TODO 6: The `countScenes` function recursively counts the current scene and all of its children. Since each scene is visited once, it takes O(n) time.

TODO 7: The `countEndings` function recursively checks every scene and counts the scenes with zero choices. Each scene is visited once, so it takes O(n) time.

TODO 8: The `height` function recursively finds the longest path from a scene to an ending. It checks each scene once, so it takes O(n) time.

TODO 9: The `clear` function deletes the root scene and sets the root pointer to `nullptr`. The destructor then deletes the entire tree, so this takes O(n) time.

TODO 10: The `load` function opens the story file, reads the starting HP, and calls `readScene` to build the entire tree. Since it processes the story once, it takes O(n) time.

TODO 11: The `readScene` function reads one scene and recursively reads all of its children. Every scene in the story is built once, so loading the entire story takes O(n) time.

TODO 12: The `askChoice` function reads input and continues asking until the player enters a valid choice. Each individual attempt takes O(1) time because the number of choices is limited to three, although the total time depends on how many invalid attempts the player makes.

TODO 13: The `play` function follows one path through the story and updates HP, loot, and the inventory. The path itself takes O(n) time, but searching the linked-list inventory can take O(n) for each item, making the worst-case time O(n²).

TODO 14: The `printStats` function calculates the number of scenes, number of endings, and height. These three tree traversals each take O(n), so the total time is still O(n).

TODO 15: The `printSpoilers` function starts the recursive process that prints all endings. Since every scene is visited, it takes O(n) time.

TODO 16: The `printEndings` function recursively visits the tree and prints each ending with its path. It visits every scene once, so it takes O(n) time.

TODO 17: The `greedyRun` function follows one path and chooses the child with the most immediate loot at each scene. Since it visits at most n scenes and each scene has at most three choices, it takes O(n) time.

TODO 18: The `bestLoot` function recursively checks every child and calculates the best surviving result. Each tree node is processed once, so the function takes O(n) time.

TODO 19: The `optimalRun` function calls `bestLoot` starting at the root and prints the result. Since `bestLoot` takes O(n) time, `optimalRun` also takes O(n) time.


2. Why does each scene allocate exactly numChoices slots instead of declaring Scene<T>*
choices[3]? What does an ending hold in choices_, and why?

Each scene allocates exactly `numChoices` slots because it only needs enough space for its actual children. Using `choices[3]` would waste memory for scenes with fewer choices and would not follow the assignment's exact-size allocation requirement. An ending has zero choices, so its `choices_` pointer stays `nullptr`. This is appropriate because an ending has no child scenes to store.

3. Walk through your Scene destructor. What gets deleted, and in what order? What would
go wrong if choices_ were deleted first?

The destructor first deletes every child scene stored in the choices array. Each child destructor then deletes its own children, so this cleans up the entire subtree. After deleting the child scenes, the destructor deletes the choices array and finally deletes the scene's data. If the choices array were deleted first, the program would lose access to the child scene pointers and would not be able to delete the child scenes, causing memory leaks.

4. Show the path greedy took and the path optimal took on your story, with the loot for each.
Explain why greedy lost. If greedy did not lose, change your story until it does, and explain
what you changed.

In my story, the greedy advisor takes path `2-1` and collects 13 loot, but it dies. It chooses the second root option because that next scene gives 6 loot immediately, and then it chooses the first child because it gives 7 more loot. However, that scene causes enough HP damage to reduce Jerry's HP below zero. The optimal advisor takes path `1-1-1-1-1` and collects 12 loot while surviving with 9 HP. Greedy loses because it only looks at the next scene's loot, while optimal considers the HP damage and the rest of the path.

5. bestLoot tries every path, yet it runs in O(n) time. Explain why it is not exponential, using what you know about paths and leaves in a tree.

Although `bestLoot` considers every possible path, the paths share scenes near the top of the tree. The function does not copy the tree or revisit the same scene through different paths because every scene has only one parent. Therefore, each scene is processed once, and the total running time is O(n), not exponential. The number of paths can be large, but the number of scenes being visited is still n.

6. Which List methods does your game use, and why? What does one search cost as the bag
grows?

My game uses `addFront` to add a new item to Jerry's inventory, `search` to check whether Jerry already has an item, `size` to print the number of items, and `print` to display the inventory. The list destructor and `deleteFront` clean up the allocated items automatically. One `search` takes O(n) time in the worst case because it may need to check every item in the linked list.
