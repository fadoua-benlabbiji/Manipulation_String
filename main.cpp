#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;

bool Appartenir(string source, string chaine){
    int pos=0;
    for(int i=0;i<chaine.length();i++){
        pos=source.find(chaine[i],pos);
        if(pos==string::npos) return false;
        pos++;
    }
    return true;
}

bool Appartenir_fichier_1(string nomfichier,string chaine){
    int comp=0;
    ifstream fichier(nomfichier);

    if(!fichier){
        cout <<"Le fichier n'existe pas !"<<endl;
        return false;
    }

    string courant;

    while(fichier >> courant){
        if(courant==chaine)
            return true;
    }

    return false;
}

bool Appartenir_fichier_2(string nomfichier,string chaine){
    int comp=0;
    string courant;

    ifstream fichier(nomfichier);

    if(!fichier){
        cout << "Le fichier n'existe pas !" << endl;
        return false;
    }

    vector<string> chains;

    while (fichier >> courant) {
        chains.push_back(courant);
    }

    for (int i = 0; i < chains.size(); i++) {
        if (chains[i] == chaine)
            return true;
    }

    return false;
}

int main()
{
    /*
    string s,ch;
    cout << "Veuillez entrer une chaine : ";
    cin >> s;
    cout <<"\nEntrer sous chaine : ";
    cin >> ch;

    if(Appartenir(s,ch)==true)
        cout <<"\nOUI il appartient " <<endl ;
    else
        cout << "\nNON il n'appartient pas " <<endl ;

    return 0;
    */

    string nomFichier="test.txt";
    string chaine;

    cout << "Entrer la chaine a rechercher : ";
    cin >> chaine;


    auto debut1 = std::chrono::high_resolution_clock::now();

    bool resultat1 = Appartenir_fichier_1(nomFichier, chaine);

    auto fin1 = std::chrono::high_resolution_clock::now();

    auto temps1 = std::chrono::duration_cast<std::chrono::nanoseconds>(fin1 - debut1);


    cout << "\n===== Methode 1 =====" << endl;

    if (resultat1)
        cout << "Chaine trouvee." << endl;
    else
        cout << "Chaine non trouvee." << endl;

    cout << "Temps de recherche : "
         << temps1.count() << " ns" << endl;


    auto debut2 = std::chrono::high_resolution_clock::now();

    bool resultat2 = Appartenir_fichier_2(nomFichier, chaine);

    auto fin2 = std::chrono::high_resolution_clock::now();

    auto temps2 = std::chrono::duration_cast<std::chrono::nanoseconds>(fin2 - debut2);


    cout << "\n===== Methode 2 =====" << endl;

    if (resultat2)
        cout << "Chaine trouvee." << endl;
    else
        cout << "Chaine non trouvee." << endl;

    cout << "Temps de recherche : "
         << temps2.count() << " ns" << endl;


    cout << "\n===== Comparaison =====" << endl;

    cout << "Methode 1 : " << temps1.count() << " ns" << endl;
    cout << "Methode 2 : " << temps2.count() << " ns" << endl;

    return 0;
}
