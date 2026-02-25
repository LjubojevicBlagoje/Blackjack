#ifndef DEALER_H
#define DEALER_H

#include "Player.h"

class Dealer : public Player {
 public:
  void Hit(Shoe& shoe) override;
  void PrintCards() override;
  // The purpose of below function is to reset firstDealover every new round so
  // that on every hand, before the player finishes his move the dealer's second
  // card is "face down"
  void refreshFaceDownLogic();
};

#endif