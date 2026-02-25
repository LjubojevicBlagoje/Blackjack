#include "Controller.h"

void Controller::InitShoe() {
  // Shoe reshuffles every hand (standard to prevent card counting)
  shoe.ClearShoe();
  shoe.InitialiseShoe(8);  // Initialise 8 deck shoe (standard in casinos)
  shoe.Shuffle();
}

void Controller::Deal() {
    dealer.refreshFaceDownLogic();
  std::cout << "------------------------------\n";
  // Initialise shoe
  InitShoe();
  // Deal two
  player.DealTwo(shoe);
  player.PrintCards();
  

  dealer.DealTwo(shoe);
  dealer.PrintCards();

  std::cout << "------------------------------\n";
}

void Controller::PlayerTurn() {
  std::string entry;
  std::cout << "\nWould you like to hit? (y/n) ";
  std::cin >> entry;
  std::cout << "" << std::endl;

  // If user entered y, hit, and if entered n skip the turn (stand)
  if (entry == "y") {
    player.Hit(shoe);
    player.PrintCards();
    if (player.Sum() > 21) {
      // if player busts
      playerBustedFirst = true;
    } else if (player.Sum() < 21) {
      PlayerTurn();
    }
    // If user enters neither y nor n request input untill satisfactory
  } else if (entry != "y" && entry != "n") {
    std::cout << "INVALID INPUT, TRY AGAIN\n";
    PlayerTurn();
  }
  std::cout << "------------------------------\n";
}

void Controller::DealerTurn() {
  std::cout << "Dealer's turn...\n";
  std::cout << "------------------------------\n";
  dealer.Hit(shoe);
  player.PrintCards();
  dealer.PrintCards();
}

void Controller::ResolveRound() {
  int playerSum = player.Sum();
  int dealerSum = dealer.Sum();
  std::cout << "------------------------------\n";
  std::cout << "Player has: " << playerSum << std::endl;
  std::cout << "Dealer has: " << dealerSum << std::endl;

  // If both player and dealer bust, favour dealer
  if (dealerSum > 21 && playerSum > 21) {
    std::cout << "Dealer Wins!" << std::endl;
  }
  // If player sum > dealer sum, and player hasn't busted, or if dealer busted
  // and player hasn't -> Player wins
  else if ((playerSum > dealerSum && playerSum <= 21) ||
           (playerSum <= 21 && dealerSum > 21 && playerBustedFirst == false)) {
    std::cout << "Player Wins!" << std::endl;
  }
  // If dealer sum > player sum, and dealer hasn't busted, or if player busted
  // and dealer hasn't -> Player wins
  else if ((dealerSum > playerSum && dealerSum <= 21) ||
           (dealerSum <= 21 && playerSum > 21)) {
    std::cout << "Dealer Wins!" << std::endl;
  }
  // If dealer sum equals player sum it's a tie
  else if (dealerSum == playerSum) {
    std::cout << "Tie!" << std::endl;
  }
}

void Controller::PlayRound() {
  InitShoe();
  Deal();
  PlayerTurn();
  DealerTurn();
  ResolveRound();
}

bool Controller::AskPlayAgain() {
  std::string input;
  std::cout << "\nWould you like to play again? (y/n) ";
  std::cin >> input;

  if (input == "y") {
    return true;
  } else if (input == "n") {
    return false;
  } else {
    std::cout << "INVALID INPUT, TRY AGAIN\n";
    return AskPlayAgain();
  }
}

void Controller::Run() {
  PlayRound();
  bool KeepPlaying = AskPlayAgain();
  if (KeepPlaying == true) {
    Run();
  } else {
    std::cout << "\nThanks for playing!" << std::endl;
  }
}