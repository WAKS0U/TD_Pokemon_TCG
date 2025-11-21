#include "card.h"
Card::Card(const string& name) : cardName(name) {}
string Card::getCardName() const { return cardName; }