#ifndef DEALER_H
#define DEALER_H

#include "Player.h"

class Dealer : public Player {
 public:
 bool hideHoleCard = true;
  void Hit(Shoe& shoe) override;
  void PrintCards() override;
  
};

#endif