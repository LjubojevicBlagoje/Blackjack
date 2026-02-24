#include "Player.h"

Player::Player() : sum(0) {};

void Player::Hit(Shoe& shoe) {
  if (sum != 21) {
    Card card = shoe.DealCard();
    cards.push_back(card);
  }
}

int Player::PlayerSum() {
  for (auto& x : cards) {
    // Logic for Ace
    if (x.ReturnRank() == 1) {
      int delta1 = 100;
      int delta11 = 100;

      if (sum + 1 <= 21) {
        delta1 = 21 - (sum + 1);
      }

      if (sum + 11 <= 21) {
        delta11 = 21 - (sum + 1);
      }

      if (delta1 < delta11) {
        sum += 1;
      } else {
        sum += 11;
      }
    }
    // Logic for picture cards
    else if (x.ReturnRank() == 11 || x.ReturnRank() == 12 ||
             x.ReturnRank() == 13) {
      sum += 10;
    } else {
      sum += x.ReturnRank();
    }
  }
}