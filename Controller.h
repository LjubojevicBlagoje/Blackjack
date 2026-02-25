#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Dealer.h"
#include "Player.h"
#include "Shoe.h"

class Controller {
 private:
  Shoe shoe;
  Player player;
  Dealer dealer;

  void InitShoe();
  void PrintBankroll();
  int PlaceBet();
  void EvaluateBet(int bet, int multiplier);
  void Deal();
  void PlayRound();
  void PlayerTurn();
  void DealerTurn();
  void ResolveRound(int&);
  bool AskPlayAgain();

 public:
  void InitBankroll();
  void Run();
  bool playerBustedFirst;
};

#endif