#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----

    std::cout << std::endl << "== Uno Turn Order ==" << std::endl;

    // A table forms with four players.
    std::unique_ptr<List<Player>> table = makeList<Player>();
    Player* diana = new Player(4, "Diana");
    Player* charlie = new Player(3, "Charlie");
    Player* bob = new Player(2, "Bob");
    Player* alice = new Player(1, "Alice");

    table->addFront(diana);
    table->addFront(charlie);
    table->addFront(bob);
    table->addFront(alice);

    std::cout << "The table forms: ";
    table->print();

    //Extra Credit
    /*
    std::cout << "Dealing starting hands." << std::endl;

    alice->addCard(new Card("Red", "7"));
    alice->addCard(new Card("Blue", "2"));

    bob->addCard(new Card("Green", "5"));
    bob->addCard(new Card("Yellow", "Reverse"));

    charlie->addCard(new Card("Red", "Skip"));
    charlie->addCard(new Card("Blue", "9"));

    diana->addCard(new Card("Yellow", "3"));
    diana->addCard(new Card("Green", "8"));
    */

    // A new player joins in the middle of the turn order.
    std::cout << "Evan pulls up a chair and joins the middle of the order: ";
    table->addAnywhere(2, new Player(5, "Evan"));
    table->print();

    // A Reverse card is played.
    std::cout << "A Reverse card is played." << std::endl;
    std::cout << "Before reverse: ";
    table->print();

    table->reverse();

    std::cout << "After reverse: ";
    table->print();

    //Extra Credit
    /*
    std::cout << "Alice plays a card: ";
    Card* playedCard = alice->playCard();

    if (playedCard != nullptr) {
        std::cout << *playedCard << std::endl;
        delete playedCard;
    }
    */

    // A player runs out of cards and leaves from the middle.
    std::cout << "Evan runs out of cards and leaves the table: ";
    table->deleteAnywhere(2);
    table->print();

    // A second table forms separately.
    std::unique_ptr<List<Player>> secondTable = makeList<Player>();
    secondTable->addFront(new Player(7, "Grace"));
    secondTable->addFront(new Player(6, "Frank"));

    std::cout << "A second table finishes its game." << std::endl;
    std::cout << "First table before concat: ";
    table->print();

    std::cout << "Second table before concat: ";
    secondTable->print();

    // The second table merges into the first.
    table->concat(secondTable.get());

    std::cout << "First table after concat: ";
    table->print();

    std::cout << "Second table after concat: ";
    secondTable->print();

    return 0;
}
