#include "Giocatore.h"


Giocatore::Giocatore(int id) {
    this->id = id;
}


Giocatore::~Giocatore() {
    //dtor
}

void Giocatore::prendi(int n) {
    this->carte.push_back(n);
}
void Giocatore::prendi(vector<int> nn) {
    this->carte.insert(this->carte.end(), nn.begin(), nn.end());
}

string Giocatore::mostra(void){
    string s ("[");
    char buffer [33];
    for (vector<int>::iterator it = this->carte.begin() ; it != this->carte.end(); ++it){
        s += itoa (*it, buffer, 10);
        if(this->carte.end() != it + 1)
           s += ", ";
        else
            s += "]";
    }
    return s;
}

vector<int> Giocatore::getCarte(void){
    return this->carte;
}
