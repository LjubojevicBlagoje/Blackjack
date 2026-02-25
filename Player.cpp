#include "Player.h"

Player::Player() {};

void Player::DealTwo(Shoe& shoe) {
  cards.clear();  // Reset cards to an empty vector
  cards.push_back(shoe.DealCard());
  cards.push_back(shoe.DealCard());
  firstDealOver = true;
}

void Player::Hit(Shoe& shoe) {
  Card card = shoe.DealCard();
  cards.push_back(card);
}

int Player::Sum() {
  int sum = 0;
  int aceCount = 0;
  for (auto& x : cards) {
    // Counting aces as 1 first (can later upgrade to 11)
    if (x.ReturnRank() == 1) {
      sum += 1;
      aceCount++;
    }
    // Logic for picture cards
    else if (x.ReturnRank() == 11 || x.ReturnRank() == 12 ||
             x.ReturnRank() == 13) {
      sum += 10;
    } else {
      sum += x.ReturnRank();
    }
  }

  // Ace upgrade to 11 logic
  while (aceCount > 0 && sum + 10 <= 21) {
    sum += 10;  // upgrade one ace from 1 to 11
    aceCount--;
  }

  return sum;
}

void Player::PrintCards() {
  std::cout << "Player's hand: ";
  for (auto& x : cards) {
    // Print each card's rank
    if (x.ReturnRank() > 1 && x.ReturnRank() < 11) {
      std::cout << x.ReturnRank() << " ";
    } else if (x.ReturnRank() == 1) {
      std::cout << "A" << " ";
    } else if (x.ReturnRank() == 11) {
      std::cout << "J" << " ";
    } else if (x.ReturnRank() == 12) {
      std::cout << "Q" << " ";
    } else if (x.ReturnRank() == 13) {
      std::cout << "K" << " ";
    }
  }
  std::cout << "" << std::endl;
}