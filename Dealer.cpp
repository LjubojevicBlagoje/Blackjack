#include "Dealer.h"

void Dealer::Hit(Shoe& shoe) {
  if (sum < 17) {
    Card card = shoe.DealCard();
    cards.push_back(card);
  }
}