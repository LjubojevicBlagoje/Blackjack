#ifndef SHOE_H
#define SHOE_H

#include<vector>
#include<iostream>

#include "Card.h"

class Shoe{
    private:
    std::vector<Card> shoe;

    public:
    void InitialiseShoe(int numberOfDecks);

    void PrintShoe();
};

#endif