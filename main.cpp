#include <iostream>
#include "Giocatore.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Giocatore g(1);
    for(int i=1; i<11; i++){
        g.prendi(i);
    }
    g.prendi(g.getCarte());

    cout << g.mostra();


    return 0;
}
