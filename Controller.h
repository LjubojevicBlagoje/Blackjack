#ifndef CONTROLLER_H
#define CONTROLLER_H

#include"Shoe.h"
#include"Player.h"
#include"Dealer.h"


class Controller{
    private:
    Shoe shoe;
    Player player;
    Dealer dealer;

    void Deal();
    void PlayRound();
    void PlayerTurn();
    void DealerTurn();
    void ResolveRound();
    void AskPlayAgain();

    public:
    void Run();


};

#endif