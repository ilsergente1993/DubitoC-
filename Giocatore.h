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
    const int AssoDiCuori = 1; //in realtà controllo se ha un asso qualsiasi
    int id;
    vector<int> carte; //le carte francesi sono massimo 52
    //vector< pair<int, int> > scartate; //valore vero | quantità : delle vere carte scartate. le ipotetiche le ottengo dal main
    public:
        Giocatore(int);
        virtual ~Giocatore();

        void prendi(int);
        void prendi(vector<int>);
        vector< pair<int, int> > scarta(vector< pair<int, int> >);

        string mostra(void);
        int conta(void);

        vector<int> getCarte(void);

        string getNome(void);

        bool haAssoDiCuori(void);
        bool haFinito(void);

    protected:

    private:
        vector< pair<int, int> > decisione(vector< pair<int, int> >);
};

#endif // GIOCATORE_H
