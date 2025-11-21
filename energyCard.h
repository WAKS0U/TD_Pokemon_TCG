#include "card.h"
#ifndef ENERGYCARD_H
#define ENERGYCARD_H   
class EnergyCard : public Card{
    private:
        string cardName;
        string energyType;
    
    public:
        EnergyCard(const string& );

        string getEnergyType() const;

        void displayInfo() override;
};

#endif