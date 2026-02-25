#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Shoe.h"

class Player {
 protected:
  std::vector<Card> cards;
  bool firstDealOver = false;

 public:
  Player();

  void DealTwo(Shoe& shoe);
  virtual void Hit(Shoe& shoe);
  int Sum();
  virtual void PrintCards();
  // The purpose of below function is to reset firstDealover every new round so
  // that on every hand, before the player finishes his move the dealer's second
  // card is "face down"
  void refreshFaceDownLogic();
};

#endif