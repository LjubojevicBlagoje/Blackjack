#include "Dealer.h"

void Dealer::Hit(Shoe& shoe) {
  while (Sum() < 17) {  // Hit untill 17 (dealer stands on soft 17)
    Card card = shoe.DealCard();
    cards.push_back(card);
  }
}

void Dealer::PrintCards() {
  std::cout << "Dealer's cards: ";
  // Before player decdes to hit or stand, the 2nd card shall remain hidden
  if (cards.size() == 2) {
    // Print first card
    int x = cards[0].ReturnRank();
    if (x > 1 && x < 11) {
      std::cout << x << " ";
    } else if (x == 1) {
      std::cout << "A" << " ";
    } else if (x == 11) {
      std::cout << "J" << " ";
    } else if (x == 12) {
      std::cout << "Q" << " ";
    } else if (x == 13) {
      std::cout << "K" << " ";
    }
    // Keep second card hidden
    std::cout << "[]" << " ";
    std::cout << "" << std::endl;
  } else {
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
}