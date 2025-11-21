#include "player.h"
#include "energyCard.h"
#include <iostream>
Player::Player(const string& name) : playerName(name) {}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int index) {


    Card* selectedCard = benchCards[index];
    PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(selectedCard);
    actionCards.push_back(pokemonCard);
    benchCards.erase(benchCards.begin() + index);
    std::cout << playerName << " is activating a Pokemon card: " << pokemonCard->getFamilyName() << std::endl;
}

void Player::attachEnergyCard(int energyCardIndex,int pokemonCardIndex){
    Card* selectedCard = benchCards[energyCardIndex];
    EnergyCard* energyCard = dynamic_cast<EnergyCard*>(selectedCard);
    PokemonCard* targetPokemon = actionCards[pokemonCardIndex];
    std::cout << playerName << " is attaching Energy Card of type " << energyCard->getEnergyType() << " to the Pokemon " << targetPokemon->getFamilyName() << std::endl;
    benchCards.erase(benchCards.begin() + energyCardIndex);

}

void Player::displayBench(){
    std::cout<<"Bench cards for Player "<<playerName<<":"<<std::endl;
    for(size_t i=0;i<benchCards.size();i++){
        benchCards[i]->displayInfo();
        
    }
}

void Player::displayAction(){
    std::cout<<"Action cards for Player "<<playerName<<":"<<std::endl;
    actionCards[0]->displayInfo();
}