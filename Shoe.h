#ifndef SHOE_H
#define SHOE_H

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "Card.h"

class Shoe {
 public:
  std::vector<Card> cards;

  void InitialiseShoe(int numberOfDecks);
  void Shuffle();
  Card DealCard();

  void PrintShoe();
};

#endif