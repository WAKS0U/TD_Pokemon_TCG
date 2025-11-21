#include <string>
using namespace std;
#ifndef CARD_H
#define CARD_H  

class Card{
    private:
        string cardName;
    public:
        Card(const string&);
        string getCardName() const;
        virtual void displayInfo() = 0;
};

#endif 