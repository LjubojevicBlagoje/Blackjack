#include"Card.h"
#include"Shoe.h"

int main(){
    Shoe shoe;
    shoe.InitialiseShoe(2);
    shoe.Shuffle();
    shoe.PrintShoe();

    return 0;
}