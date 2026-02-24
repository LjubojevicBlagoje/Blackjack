#include "Shoe.h"

void Shoe::InitialiseShoe(int numberOfDecks) {
  // NumberOfDecks times 4 as there are 4 suits of each card
  for (int i = 0; i < numberOfDecks * 4; i++) {
    for (int rank = 1; rank <= 13; rank++) {
      shoe.push_back(Card(rank));
    }
  }
}

void Shoe::PrintShoe(){
    for(auto& x : shoe){
        std::cout<<x.ReturnRank()<<"\n";
    }
}