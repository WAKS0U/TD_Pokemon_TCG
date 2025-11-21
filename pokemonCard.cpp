#include "pokemonCard.h"
#include <iostream>
PokemonCard::PokemonCard(const string& name, const string& type, const string& family, int evolution, int maxHp, int energyCost1, string nomAttack1, int damage1, int energyCost2, string nomAttack2, int damage2)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(evolution), maxHP(maxHp), hp(maxHp) {
    attacks.push_back(make_tuple(energyCost1, 0, nomAttack1, damage1));
    attacks.push_back(make_tuple(energyCost2, 0, nomAttack2, damage2));
}
string PokemonCard::getFamilyName() const {
    return familyName;
} 


void PokemonCard::displayInfo() {
    std::cout<<"Pokemon card - Name:"<< getCardName() <<", Type:"<< pokemonType <<", Evolution Level:"<< evolutionLevel <<" of the family "<< familyName <<", HP:"<< hp <<endl<<"Attacks: "<<endl;
    int attackNumber = 0;
    for(const auto& attack : attacks){
        std::cout<<"Attack #"<<attackNumber++<<":"<<endl<<"Attack cost:"<<get<0>(attack) <<endl<<", Name:"<< get<2>(attack) <<", Damage:"<< get<3>(attack) <<std::endl;
    }
    std::cout << std::endl;
}