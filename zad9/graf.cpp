#include <iostream>
#include<vector>
#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int W, K;     // W - liczba wierzcholkow, K - liczba krawedzi
    cout << "Liczba wierzcholkow: ";
    cin >> W;
    cout << "Liczba krawedzi: ";
    cin >> K;

    vector<int> *ZA = new vector<int>[W+1];// wektor przechowujacy dane o krawedziach i wierzcholkach
    ofstream outfile ("test.dot"); // tworzenie pliku test.dot
    outfile << "graph {" <<endl; // pocztek funkcji rysujacej graf zapisanej w pliku test.dot

    for(int i=1; i<=K; i++){      // wprowadz wierzcholki i krawedzie
        int a, b;
        cout << "Krawedz " << i << ": ";
        cin >> a >> b;
        ZA[a].push_back(b);
        ZA[b].push_back(a);
        outfile <<" " << a <<" -- "<< b <<endl; // zapisanie danych o krawedziach do pliku test.dot

    }
    outfile << "}" <<endl; // zamkniecie graph w pliku
    outfile.close(); //zapisanie pliku test.dot w folderze cmake-build-debug
    cout << "1.dot \n 2.circo"<< endl;
    int wybor;
    cin >> wybor;
    if(wybor == 1 ) {
        system(" dot -Tsvg test.dot -o test.svg");
    }
    if (wybor == 2){
        system(" circo -Tsvg test.dot -o test.svg");
    }
    int Tabwa[K+1];
    Tabwa[0] = 0;

    //wagi scizek krawedzi
   /* for(int i=1; i<=K; i++){
        int w;
        cout<<"waga sciezki: " << i << ": ";
        cin >> w;
        Tabwa[i] = w;
    }*/


    for(int i=1; i<=W; i++){     // wypisujemy graf

        cout << endl << "Sasiedzi wierzcholka " << i << ": ";
        for(vector<int>::iterator it = ZA[i].begin(); it != ZA[i].end(); ++it) cout << *it << ", ";
    }


   /* for (int i = 1; i <= K ; ++i) { // wypisujemy wagi krawedzi
        cout << endl << "waga krawedzi " << i << ": "<< Tabwa[i];
    }*/
    system("open -a \"Google Chrome\" test.svg"); //uruchominie pliku svg w przegldarce
    delete []ZA; // usuwanie wektora
}
