#include "card.h"
#ifndef TRAINERCARD_H
#define TRAINERCARD_H

class TrainerCard : public Card{
    private:
        string trainerEffect;
        string cardName;
    public:
        TrainerCard(const string& , const string& );

        string getTrainerEffect() const;

        void displayInfo() override;

        void healPokemon();
};
#endif