#include "energyCard.h"
EnergyCard::EnergyCard(const string& type)
    : Card("Energy"), energyType(type) {}

string EnergyCard::getEnergyType() const {
    return energyType;    
}

void EnergyCard::displayInfo() {
    
}   