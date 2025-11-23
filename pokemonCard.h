#include "card.h"
#include <tuple>
#include <vector>
using namespace std;
#ifndef POKEMONCARD_H
#define POKEMONCARD_H   

class PokemonCard : public Card{
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        vector<tuple<int,int,string, int>> attacks; 
    public:
        PokemonCard(const string& , const string& , const string& , int , int, int , string,int,int,string,int );

        string getFamilyName() const;

        void displayInfo() override;
        void addEnergy();
        tuple<int , int , string, int > getAttack(int index) const {
            return attacks[index];
        }
        int getnumberOfAttacks() const;
        void reduceHP(int);
        bool isKO() const;
        void reduceEnergy(int);
};

#endif