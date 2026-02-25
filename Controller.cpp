#include"Controller.h"

void Controller::Deal(){
    // Deal two 
    player.DealTwo(shoe);
    player.PrintCards();

    dealer.DealTwo(shoe);
    dealer.PrintCards();
}

void Controller::PlayRound(){

}
    void PlayerTurn();
    void DealerTurn();
    void ResolveRound();
    bool AskPlayAgain();

    void Controller::Run(){
        Deal();
    }