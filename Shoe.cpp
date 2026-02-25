#include "Shoe.h"

void Shoe::InitialiseShoe(int numberOfDecks) {
  // NumberOfDecks times 4 as there are 4 suits of each card
  for (int i = 0; i < numberOfDecks * 4; i++) {
    for (int rank = 1; rank <= 13; rank++) {
      cards.push_back(Card(rank));
    }
  }
}

void Shoe::Shuffle() {
  // RNG seeded once using OS entropy
  static thread_local std::mt19937 rng(std::random_device{}());
  // std::shuffle implements Fisher–Yates (uniform unbiased shuffle)
  std::shuffle(cards.begin(), cards.end(), rng);
}

Card Shoe::DealCard() {
  if (!cards.empty()) {
    Card card = std::move(cards.back());
    cards.pop_back();
    return card;
  }
}

void Shoe::PrintShoe() {
  for (auto& x : cards) {
    std::cout << x.ReturnRank() << "\n";
  }
}