#ifndef DEALER_H
#define DEALER_H

#include "Player.h"

class Dealer : public Player {
 public:
    bool firstDealOver = false;
  void Hit(Shoe& shoe) override;
  void PrintCards() override;
};

#endif