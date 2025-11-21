#include "player.h"
#include "card.h"
#include "pokemonCard.h"
#include "trainerCard.h"
#include "energyCard.h"
#include <iostream>
using namespace std;
#include <string>

int main(){
    Player player1("Hadi");

    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash","heal all your action pokemon"));
    player1.addCardToBench(new PokemonCard("Pikachu","Electric","Pikachu",2,100,2,"thunder bolt", 20,3,"thunder storm", 30));

    player1.activatePokemonCard(3);
    player1.attachEnergyCard(0,0);
    player1.attachEnergyCard(0,0);

    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayAction();
    return 0;
}