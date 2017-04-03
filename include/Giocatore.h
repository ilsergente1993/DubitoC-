#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Giocatore {
    int id;
    vector<int> carte; //le carte francesi sono massimo 52
    public:
        Giocatore(int);
        virtual ~Giocatore();

        void prendi(int);
        void prendi(vector<int>);
        void scarta(int);

        string mostra(void);

        vector<int> getCarte(void);

    protected:

    private:
        int decisione();
};

#endif // GIOCATORE_H
