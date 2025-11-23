#include "player.h"
#include "energyCard.h"
#include "pokemonCard.h"
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
    targetPokemon->addEnergy();
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

void Player::attack(int attackIndex,int CartePokemonIndex, Player& opponent , int opponentPokemonIndex){
    int numberOfAttacks= actionCards[CartePokemonIndex]->getnumberOfAttacks();
    std::cout<<"Only "<<numberOfAttacks<<" atttacks exist"<<std::endl;
    PokemonCard* attackingPokemon = actionCards[CartePokemonIndex];
    PokemonCard* defendingPokemon = opponent.actionCards[opponentPokemonIndex];

    auto attack = attackingPokemon->getAttack(attackIndex);
    int attackDamage = get<3>(attack);
    defendingPokemon->reduceHP(attackDamage);
    attackingPokemon->reduceEnergy(get<0>(attack));
    std::cout << playerName << " attacking " <<opponent.playerName << "'s Pokemon " << defendingPokemon->getFamilyName() << " with the Pokemon " << attackingPokemon->getFamilyName() << " with its attack: " << get<2>(attack)<< std::endl<<"Reducing "<<
    get<3>(attack)<<" from "<<opponent.playerName<<"'s Pokemon's HP"<<std::endl;
    if(defendingPokemon->isKO()){
        std::cout << opponent.playerName << "'s Pokemon " << defendingPokemon->getFamilyName() << " is KO" << std::endl;
        opponent.actionCards.erase(opponent.actionCards.begin() + opponentPokemonIndex);
    }
    else{
        std::cout <<"Pokemon "<< defendingPokemon->getFamilyName() << " is still alive" << std::endl;
    }    

}
void Player::useTrainerCard(int trainerCardIndex){
    Card* selectedCard = benchCards[trainerCardIndex];
    TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(selectedCard);
    std::cout << playerName << " is using Trainer Card to " << trainerCard->getTrainerEffect() << std::endl;
    applyTrainerEffect:
    if(trainerCard->getTrainerEffect() == "heal all your action pokemon"){
        for(auto& pokemon : actionCards){
            pokemon->reduceHP(-20); 
        }
    }
    benchCards.erase(benchCards.begin() + trainerCardIndex);
}