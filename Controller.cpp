#include"Controller.h"

void Controller::InitShoe(){
    // Shoe reshuffles every hand (standard to prevent card counting)
    shoe.ClearShoe();
    shoe.InitialiseShoe(8); // Initialise 8 deck shoe (standard in casinos)
}

void Controller::Deal(){
    // Initialise shoe
    InitShoe();
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