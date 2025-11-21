#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "pokemonCard.h"
#include "trainerCard.h"
#include "card.h"
using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;
public:
    Player(const string&);
    void addCardToBench(Card*);
    void activatePokemonCard(int);
    void attachEnergyCard(int,int);
    void displayBench();
    void displayAction();
};
#endif