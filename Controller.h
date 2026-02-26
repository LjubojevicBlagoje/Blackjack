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
  void EvaluateBet(int bet, double multiplier);
  void Deal();
  void PlayRound();
  void PlayerTurn();
  void PlayerTurnNoDoubleDown();
  void DealerTurn();
  void ResolveRound(double&);
  bool AskPlayAgain();

 public:
  void InitBankroll();
  void Run();
  bool playerBustedFirst = false;
  bool doubleDown = false;
  bool blackjack = false;
  bool dealerBlackjack = false;
  int playerBet;
};

#endif