#include "Dealer.h"

void Dealer::Hit(Shoe& shoe) {
  while (Sum() < 17) { // Hit untill 17 (dealer stands on soft 17)
    Card card = shoe.DealCard();
    cards.push_back(card);
  }
}