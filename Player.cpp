#include "Player.h"

Player::Player(){};

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
      sum+=1;
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
