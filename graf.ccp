#include <iostream>
#include<vector>
using namespace std;
int main() {
    int W, K;     // W - liczba wierzcholkow, K - liczba krawedzi
    cout << "Liczba wierzcholkow: ";
    cin >> W;
    cout << "Liczba krawedzi: ";
    cin >> K;

    vector<int> *ZA = new vector<int>[W+1];// wektor przechowujacy dane o krawedziach i wierzcholkach


    for(int i=1; i<=K; i++){      // wprowadz wierzcholki i krawedzie
        int a, b;
        cout << "Krawedz " << i << ": ";
        cin >> a >> b;
        ZA[a].push_back(b);
        ZA[b].push_back(a);
    }
    int Tabwa[K+1];
    Tabwa[0] = 0;

    //wagi scizek krawedzi
    for(int i=1; i<=K; i++){
        int w;
        cout<<"waga sciezki: " << i << ": ";
        cin >> w;
        Tabwa[i] = w;
    }

    for(int i=1; i<=W; i++){     // wypisujemy graf

        cout << endl << "Sasiedzi wierzcholka " << i << ": ";
        for(vector<int>::iterator it = ZA[i].begin(); it != ZA[i].end(); ++it) cout << *it << ", ";
    }

    for (int i = 1; i <= K ; ++i) { // wypisujemy wagi krawedzi
        cout << endl << "waga krawedzi " << i << ": "<< Tabwa[i];
    }

    delete []ZA;
}
