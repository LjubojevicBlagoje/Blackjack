#ifndef DEALER_H
#define DEALER_H

#include "Player.h"

class Dealer : private Player {
 public:
  int sum;
  std::vector<Card> cards;

 public:
  void Hit(Shoe& shoe) override;
};

#endif