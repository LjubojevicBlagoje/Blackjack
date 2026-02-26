#include "Controller.h"

void Controller::InitBankroll() {
  int temp;
  std::cout << "------------------------------\n";
  std::cout << "Enter bankroll size: ";
  std::cin >> temp;
  player.SetBankroll(temp);
  std::cout << "------------------------------\n";
}

void Controller::InitShoe() {
  // Shoe reshuffles every hand (standard for card counting prevention)
  shoe.ClearShoe();
  shoe.InitialiseShoe(8);  // Initialise 8 deck shoe (standard in casinos)
  shoe.Shuffle();
}

void Controller::PrintBankroll() {
  std::cout << "Bankroll: " << player.ReturnBankroll() << std::endl;
  std::cout << "------------------------------\n";
}

int Controller::PlaceBet() {
  int betSize;

  std::cout << "Enter bet size (multiples of $5): ";
  std::cin >> betSize;

  if (betSize < 5 || betSize % 5 != 0) {
    std::cout << "Invalid bet size, please enter a valid amount!\n"
              << std::endl;
    return PlaceBet();
  } else {
    // Check if player posesses enough bankroll to place bet
    if (player.ReturnBankroll() - betSize < 0) {
      std::cout << "Invalid bet size, please enter a valid amount!\n"
                << std::endl;
      return PlaceBet();
    }
    return betSize;
  }
  return 0;
}

void Controller::EvaluateBet(int bet, int multiplier) {
  // Double down logic
  if (doubleDown == true) {
    bet = 2 * bet;
  }

  player.UpdateBankroll(bet * multiplier);
}

void Controller::Deal() {
  std::cout << "------------------------------\n";
  // Initialise shoe
  InitShoe();
  // Deal two
  player.DealTwo(shoe);
  player.PrintCards();

  dealer.DealTwo(shoe);
  dealer.PrintCards();
  dealer.hideHoleCard = false;

  std::cout << "------------------------------\n";
}

void Controller::PlayerTurn() {
  std::string entry;
  std::cout << "\nHit(h) | Stand(s) | Double down(d) ";
  std::cin >> entry;
  std::cout << "" << std::endl;

  // If user entered h, hit, and if entered s skip the turn (stand)
  if (entry == "h") {
    player.Hit(shoe);
    player.PrintCards();
    if (player.Sum() > 21) {
      // if player busts
      playerBustedFirst = true;
    } else if (player.Sum() < 21) {
      PlayerTurn();
    }
    // Double down
  } else if (entry == "d") {
    doubleDown = true;
    // After doubling down player recieves exactly 1 more card and turn ends
    player.Hit(shoe);
    player.PrintCards();
    if (player.Sum() > 21) {
      // if player busts
      playerBustedFirst = true;
    }
  }
  // If user enters neither h, s nor d request input untill satisfactory
  else if (entry != "h" && entry != "s" && entry != "d") {
    std::cout << "INVALID INPUT, TRY AGAIN\n";
    PlayerTurn();
  }
}

void Controller::DealerTurn() {
  std::cout << "Dealer's turn...\n";
  std::cout << "------------------------------\n";
  dealer.Hit(shoe);
  player.PrintCards();
  dealer.PrintCards();
}

void Controller::ResolveRound(int& multiplier) {
  int playerSum = player.Sum();
  int dealerSum = dealer.Sum();
  std::cout << "------------------------------\n";
  std::cout << "Player has: " << playerSum << std::endl;
  std::cout << "Dealer has: " << dealerSum << std::endl;

  // If both player and dealer bust, favour dealer
  if (dealerSum > 21 && playerSum > 21) {
    std::cout << "\nDealer Wins!" << std::endl;
    multiplier = -1;
  }
  // If player sum > dealer sum, and player hasn't busted, or if dealer busted
  // and player hasn't -> Player wins
  else if ((playerSum > dealerSum && playerSum <= 21) ||
           (playerSum <= 21 && dealerSum > 21 && playerBustedFirst == false)) {
    std::cout << "\nPlayer Wins!" << std::endl;
    multiplier = 1;
  }
  // If dealer sum > player sum, and dealer hasn't busted, or if player busted
  // and dealer hasn't -> Player wins
  else if ((dealerSum > playerSum && dealerSum <= 21) ||
           (dealerSum <= 21 && playerSum > 21)) {
    std::cout << "\nDealer Wins!" << std::endl;
    multiplier = -1;
  }
  // If dealer sum equals player sum it's a tie
  else if (dealerSum == playerSum) {
    std::cout << "\nTie!" << std::endl;
    multiplier = 0;
  }
}

void Controller::PlayRound() {
  int bet;
  int multiplier;
  InitShoe();
  PrintBankroll();
  bet = PlaceBet();
  Deal();
  PlayerTurn();
  DealerTurn();
  ResolveRound(multiplier);
  EvaluateBet(bet, multiplier);
  PrintBankroll();
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
  // Reset flag so that in the next round dealer hole card is hidden
  dealer.hideHoleCard = true;
  // Reset double down flag for next round
  doubleDown = false;
  // Reset player bust flag for next round
  playerBustedFirst = false;
  
  bool KeepPlaying = AskPlayAgain();
  if (KeepPlaying == true) {
    std::cout << "" << std::endl;
    std::cout << "==============================\n";
    std::cout << "        NEW HAND        \n";
    std::cout << "==============================\n" << std::endl;
    Run();
  } else {
    std::cout << "\nThanks for playing!\n" << std::endl;
  }
}