#ifndef PLAYER_H
#define PLAYER_H

#include"Shoe.h"
#include"Card.h"

class Player{
    protected:
    std::vector<Card> cards;

    public:
    Player();

    virtual void Hit(Shoe& shoe);
    int Sum();
};

#endif