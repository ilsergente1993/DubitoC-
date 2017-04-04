#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Giocatore.h"

using namespace std;

void pres(){
    cout <<endl<<"---------------------------" << endl;
    cout << "    Benvenuto a Dubito++" << endl;
    cout << "----------by jf----------" << endl << endl;
}

int main() {
    pres();
    int ng, gpartenza;
    vector< pair<int, int> > tavoloReale;
    vector< pair<int, int> > tavoloIpotetico;
    int mazzo[4 * 13]; //senza jolly
    for(int j=0; j<4; j++)
        for(int i=0; i<13; i++)
            mazzo[i + 13*j] = i+1;
    //for(int i=0; i<13*4; i++) cout << (i%13==0 && i!=0 ? "\n" : "") << mazzo [i] << " ";
    //ottengo il numero di giocatori
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
    //mischio il vettore, prendo l'ultimo elemento e lo assegno ciclicamente ad ogni giocatore
    {
        vector<int> mazzoshuffle(mazzo, mazzo + sizeof mazzo / sizeof mazzo[0]);
        int indexg = 0;
        /*for (vector<int>::iterator it = mazzoshuffle.begin() ; it != mazzoshuffle.end(); ++it)
            cout << *it << " ";*/
        while(mazzoshuffle.size() != 0) {
            random_shuffle(mazzoshuffle.begin(), mazzoshuffle.end());
            gs[indexg % ng]->prendi(*(mazzoshuffle.end()-1));
            mazzoshuffle.erase(mazzoshuffle.end() - 1);
            indexg++;
        }
    }

    for(int i=0; i<ng; i++) {
        cout << gs[i]->getNome() << ": " << gs[i]->mostra() << "  #" <<gs[i]->conta() << endl;
    }

    //incomincio dal primo che ha l'asso
    for(gpartenza=0; gpartenza<ng; gpartenza++)
        if(gs[gpartenza]->haAssoDiCuori())
            break;

    //ciclo di gioco
    for(int h = --gpartenza; true; h++){
        vector< pair<int, int> > scartate = gs[h%ng]->scarta(tavoloIpotetico);
        tavoloReale.insert(tavoloReale.end(), scartate.begin(), scartate.end());
        //tavoloReale
    }


    return 0;
}
