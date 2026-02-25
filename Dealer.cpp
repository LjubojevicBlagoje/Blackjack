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
    std::cout << cards[0].ReturnRank() << " ";
    std::cout << "[]" << " ";
    std::cout << "" << std::endl;
  } else {
    for (auto& x : cards) {
      // Print each card's rank
      std::cout << x.ReturnRank() << " ";
    }
    std::cout << "" << std::endl;
  }
}