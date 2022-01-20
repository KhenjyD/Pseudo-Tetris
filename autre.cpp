#include "tetris.hpp"

//Permet d'afficher l'écran d'accueil du jeu
void afficheMenu()
{
	cout <<"             -------------------------------"<<endl;
	cout <<"            |   BIENVENUE DANS LA MATRICE   |"<<endl;
	cout <<"             -------------------------------"<<endl;
	cout << endl;
	cout << " 1 - Commencer à jouer" << endl;
	cout << " 2 - Règles du jeu" << endl;
	cout << " 3 - Quitter le jeu" << endl;
	cout << endl;
	cout << "Entrez votre choix: ";
}

//Permet d'afficher les règles du jeu
void afficheRegle()
{
    system("clear");
    char sortir;
    cout <<"             -------------------------------"<<endl;
    cout <<"            |          REGLES DU JEU        |"<<endl;
    cout <<"             -------------------------------"<<endl;
    cout << endl<<endl;
    cout << "Les règles sont les suivantes:"<<endl<<endl
    	 <<"1. Vous devez placer les blocs dans le plateau en essayant de casser le plus de bloc possible en formant des lignes ou des colonnes."<<endl
    	 <<"2. Plus vous détruisez de bloc et plus votre score augmente ! "<<endl
    	 <<"3. La partie s'arrête quand vous tenter de jouer 3 fois un bloc à une position déja occupée ou ne pouvant supporter la dimension du bloc." << endl
    	 <<"4. Le placement d'un bloc se fait en entrant les coordonnées de la case de la matrice la plus en bas à gauche de la forme." << endl;
    cout << endl;
    cout << "Entrez n'importe quel caractère pour sortie: ";
    cin >> sortir;
}
 //Permet de choisir la forme de la grille
void choisirForm(int &s)
{
	cout << "Sur quel forme de plateau souhaitez-vous jouer ? 1:Losange | 2:Triangle | 3:Cercle. Entrez votre choix: ";
    cin >> s;
    if(s > 3 || s <= 0){
        cout << "Entrez un nombre correspondant à une forme: ";
        cin >> s;
        while(s > 3 || s <= 0){
            cout << "Entrez un nombre entre 1 et 3: ";
            cin >> s;
        }
    }
}

//Permet de choisir la hauteur de la grille
void choisirHauteur(int &h)
{
	cout << "Choisissez la hauteur du plateau: ";
	cin >> h;
    if(h < 21){
        cout << "Choisissez la hauteur du plateau (minimum 21): ";
        cin >> h;
        while(h < 21){
            cout << "Entrez une hauteur supérieur à 21: ";
            cin >> h;
        }
    }
}

//Permet de choisir la largeur de la grille
void choisirLargeur(int &w)
{
	cout << "Choisissez la largeur du plateau: ";
    cin >> w;
    if(w < 21){
        cout << "Choisissez la largeur du plateau (minimum 21): ";
   	    cin >> w;
        while(w < 21){
            cout << "Entrez une largeur supérieur à 21: ";
            cin >> w;
        }
    }
}

//Permet de choisir la politique de jeu
void choisirPolitique(int &politique)
{
	cout << "Sous quelle configuration voulez-vous jouer [Affichage complet des Blocs]->tapez 1 ou [Bloc aléatoire]->tapez 2 ? ";
    cin >> politique;
    if(politique > 2 || politique <= 0){
        cout << "Entrez un nombre correspondant à une politique: ";
        cin >> politique;
        while(politique > 2 || politique <= 0){
            cout << "Entrez un nombre entre 1 et 2: ";
            cin >> politique;
        }
    }
}
