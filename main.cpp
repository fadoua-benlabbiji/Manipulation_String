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
    int compt=0;
    for(int i=0;i<chaine.length();i++){
        pos=source.find(chaine[i],pos);
        if(pos==string::npos) return false;
        pos++;
    }
    return true;
}

int Appartenir_fichier_1(string nomfichier,string chaine){
    int comp=0;
    int pos=0;
    ifstream fichier(nomfichier);

    if(!fichier){
        cout <<"Le fichier n'existe pas !"<<endl;
        return false;
    }

    string courant;

    while(fichier >> courant){
            pos=0;
       while((pos=courant.find(chaine,pos))!=string::npos){
            comp++;
            pos = pos + chaine.length();
    }
    }
    return comp;
}

int Appartenir_fichier_2(string nomfichier,string chaine,string Replace){
    int comp=0;
    string courant;
    int pos=0;

    ifstream fichier(nomfichier);

    if(!fichier){
        cout << "Le fichier n'existe pas !" << endl;
        return false;
    }

    vector<string> chains;

    while (fichier >> courant) {
        chains.push_back(courant);
    }
    fichier.close();
    for (int i = 0; i < chains.size(); i++) {
            pos=0;
        while ((pos=chains[i].find(chaine,pos)) != string::npos){
            comp++;
            chains[i].replace(pos,chaine.length(),Replace);
            pos=pos+Replace.length();
        }

    }
    ofstream fichier2(nomfichier);
    for(int i=0;i<chains.size();i++){
        fichier2 << chains[i] << " " ;
    }
    fichier2.close();
    return comp;
}

int main(){
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

    string nomFichier="text.txt";
    string chaine,chaine2;

    cout << "Entrer la chaine a rechercher : ";
    cin >> chaine;
    cout << "Entrer la chaine avec lequel on va remplacer : ";
    cin >> chaine2;
    auto debut1 = std::chrono::high_resolution_clock::now();

    int resultat1 = Appartenir_fichier_1(nomFichier, chaine);

    auto fin1 = std::chrono::high_resolution_clock::now();

    auto temps1 = std::chrono::duration_cast<std::chrono::nanoseconds>(fin1 - debut1);


    cout << "\n===== Methode 1 =====" << endl;

    cout << "Nombre d'occurrence de la sous-chaine : "
         << resultat1 << endl;

    cout << "Temps de recherche : "
         << temps1.count() << " ns" << endl;
cout << "Temps de recherche : "
     << temps1.count() / 1000000000.0 << " secondes" << endl;


    auto debut2 = std::chrono::high_resolution_clock::now();

    int resultat2 = Appartenir_fichier_2(nomFichier, chaine,chaine2);

    auto fin2 = std::chrono::high_resolution_clock::now();

    auto temps2 = std::chrono::duration_cast<std::chrono::nanoseconds>(fin2 - debut2);


    cout << "\n===== Methode 2 =====" << endl;

    cout << "Nombre d'occurrence de la sous-chaine : "
         << resultat2 << endl;

    cout << "Temps de recherche : "
         << temps2.count() << " ns" << endl;
    cout << "Temps de recherche : "
     << temps2.count() / 1000000000.0 << " secondes" << endl;

    cout << "\n===== Comparaison =====" << endl;

    cout << "Methode 1 : " << temps1.count() << " ns" << endl;
    cout << "Methode 2 : " << temps2.count() << " ns" << endl;

    return 0;
}
