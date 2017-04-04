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

vector< pair<int, int> > Giocatore::scarta(vector< pair<int, int> > tavoloIpotetico){
    vector< pair<int, int> > sca;
    sca = this->decisione(tavoloIpotetico);

    for (vector< pair<int, int> >::iterator it = sca.begin() ; it != sca.end(); ++it) {
        vector<int>::iterator da_eliminare = find(this->carte.begin(), this->carte.end(), (*it).first);
        if (da_eliminare != this->carte.end()) {
          iter_swap(da_eliminare, this->carte.end() - 1);
          this->carte.erase(this->carte.end() - 1);
        }
    }
    return sca;
}

string Giocatore::mostra(void) {
    string s ("[");
    char buffer [33];
    if(this->carte.size() != 0)
        for (vector<int>::iterator it = this->carte.begin() ; it != this->carte.end(); ++it) {
            s += itoa (*it, buffer, 10);
            if(this->carte.end() != it + 1)
                s += ", ";
            else
                s += "]";
        }
    else
        s += " vuoto ]";
    return s;
}

int Giocatore::conta(void){
    return this->carte.size();
}

vector<int> Giocatore::getCarte(void) {
    return this->carte;
}
string Giocatore::getNome(void){
    return string(1, (char)(this->id + 65));
}

bool Giocatore::haAssoDiCuori(void){
    return (find(this->carte.begin(), this->carte.end(), this->AssoDiCuori) != this->carte.end());
}

bool Giocatore::haFinito(void){
    return this->carte.empty();
}
vector< pair<int, int> > Giocatore::decisione(vector< pair<int, int> > tavoloIpotetico){
    vector< pair<int, int> > a;
    pair<int, int> p(1, 1);
    a.push_back(p);
    return a;
}
