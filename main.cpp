#include "Card.h"
#include "Controller.h"
#include "Dealer.h"
#include "Player.h"
#include "Shoe.h"

int main() {
  Controller game;
  game.InitBankroll();
  game.Run();

  return 0;
}