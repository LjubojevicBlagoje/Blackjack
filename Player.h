#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Shoe.h"

class Player {
 protected:
  std::vector<Card> cards;

 public:
  Player();

  void DealTwo(Shoe& shoe);
  virtual void Hit(Shoe& shoe);
  int Sum();
  virtual void PrintCards();
};

#endif