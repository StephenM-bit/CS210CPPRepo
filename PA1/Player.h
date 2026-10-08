#pragma once
#include <ostream>
#include <string>
#include "Stack.h"
#include "Card.h"


class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name) {}

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

    //Extra Credit
    /*
    void addCard(Card* card) {
        hand_.push(card);
    }

    Card* playCard() {
        return hand_.pop();
    }
    */

private:
    int id_;
    std::string name_;

    //Extra Credit
    /*
    Stack<Card> hand_;
    */
};
