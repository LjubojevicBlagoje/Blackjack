#ifndef PLAYER_H
#define PLAYER_H

#include"Shoe.h"
#include"Card.h"

class Player{
    private:
    std::vector<Card> cards;
    int sum;

    public:
    Player();

    virtual void Hit(Shoe& shoe);
    int Sum();
};

#endif