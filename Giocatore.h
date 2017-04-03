#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Giocatore {
    int id;
    vector<int> carte; //le carte francesi sono massimo 52
    int scartato [2];
    public:
        Giocatore(int);
        virtual ~Giocatore();

        void prendi(int);
        void prendi(vector<int>);
        void scarta(void);

        string mostra(void);
        int conta(void);

        vector<int> getCarte(void);
        int getVal(void);
        int getQu(void);
        string getNome(void);

    protected:

    private:
        void decisione(int &valore, int &quantita);
};

#endif // GIOCATORE_H
