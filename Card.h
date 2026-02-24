#ifndef CARD_H
#define CARD_H

class Card {
 private:
  int rank;

 public:
  Card(int rank);

  int ReturnRank();
};

#endif