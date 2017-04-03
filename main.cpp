#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Giocatore.h"

using namespace std;

int main() {
    int ng;
    int mazzo[4 * 13]; //senza jolly
    for(int j=0; j<4; j++)
        for(int i=0; i<13; i++)
            mazzo[i + 13*j] = i;

    for(int i=0; i<13*4; i++) cout << (i%13==0 && i!=0 ? "\n" : "") << mazzo [i] << " ";

    cout <<endl<<endl<<"---------------------------" << endl;
    cout << "    Benvenuto a Dubito++" << endl;
    cout << "----------by jf----------" << endl << endl;
    do {
        cout << "Numero di giocatori: ";
        cin >> ng;
    } while(ng <= 0);

    Giocatore * gs[ng];
    //inizializzo i giocatori
    for(int i=0; i<ng; i++) {
        gs[i] = new Giocatore(i);
    }

    //distribuisco ai giocatori le carte del mazzo
    //mischio il vettore, prendo l'ultimo elemento e lo assegno
    {
        cout << mazzo [4 * 13 -1];
        vector<int> mazzoshuffle(mazzo, mazzo + sizeof mazzo / sizeof mazzo[0]);
        int indexg = 0;
        while(mazzoshuffle.size() != 0) {
            std::random_shuffle(mazzoshuffle.begin(), mazzoshuffle.end());
            cout << *mazzoshuffle.end() << ": ";
            gs[indexg % ng]->prendi(*mazzoshuffle.end());
            mazzoshuffle.erase(mazzoshuffle.end() - 1);
            indexg++;
        }
    }

    for(int i=0; i<ng; i++) {
        cout << gs[i]->getNome() << ": " << gs[i]->mostra() << endl;
    }

    return 0;
}
