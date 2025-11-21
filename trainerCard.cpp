#include "trainerCard.h"
#include <iostream>    
TrainerCard::TrainerCard(const string& name, const string& effect)
    : Card(name), trainerEffect(effect) {}

string TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}

void TrainerCard::displayInfo() {
    std::cout << "Trainer Card - Name: " << getCardName() << ", Effect: " << trainerEffect << std::endl;
}

void TrainerCard::healPokemon() {
    
}