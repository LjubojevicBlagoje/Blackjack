#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Shoe.h"

class Player {
 private:
  int bankroll;

 protected:
  std::vector<Card> cards;

 public:
  Player();

  void SetBankroll(int value);
  void UpdateBankroll(int amount);
  int ReturnBankroll();

  void DealTwo(Shoe& shoe);
  virtual void Hit(Shoe& shoe);
  int Sum();
  virtual void PrintCards();
};

#endif