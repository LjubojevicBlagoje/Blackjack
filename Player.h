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

    void Hit(Shoe& shoe);
    int PlayerSum();
};

#endif