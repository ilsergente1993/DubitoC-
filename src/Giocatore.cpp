#include "Giocatore.h"


Giocatore::Giocatore(int id) {
    this->id = id;
    this->scartato[0] = -1;
    this->scartato[1] = -1;
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

void Giocatore::scarta(void){
    int val, qu;
    this->decisione(val, qu);
    while(qu-- > 0) {
        vector<int>::iterator it = find(this->carte.begin(), this->carte.end(), val);
        if (it != this->carte.end()) {
          iter_swap(it, this->carte.end() - 1);
          this->carte.erase(this->carte.end() - 1);
        }
        else {
            cout << "ERRORE: sto cercando di scartare una carta che non ho!!" << endl;
        }
    }
    this->scartato[0] = val;
    this->scartato[1] = qu;
}

string Giocatore::mostra(void) {
    string s ("[");
    char buffer [33];
    for (vector<int>::iterator it = this->carte.begin() ; it != this->carte.end(); ++it) {
        s += itoa (*it, buffer, 10);
        if(this->carte.end() != it + 1)
            s += ", ";
        else
            s += "]";
    }
    return s;
}


vector<int> Giocatore::getCarte(void) {
    return this->carte;
}
int Giocatore::getVal(void){
    return this->scartato[0];
}
int Giocatore::getQu(void){
    return this->scartato[1];
}
string Giocatore::getNome(void){
    return string(1, (char)(this->id + 65));
}

void Giocatore::decisione(int &valore, int &quantita){
    valore = 1;
    quantita = 1;
}
