#include "tetris.hpp"

int main()
{
	int choix, h, w, s, politique, fin = 0;
	srand(time(NULL));
	
	while(fin == 0)
    {
    	system("clear");
        afficheMenu();
        cout << "Faites votre choix: ";
        cin >> choix;

        switch(choix)
        {
            case 1:
                choisirForm(s);
                choisirHauteur(h);
                choisirLargeur(w);
                choisirPolitique(politique);
                fin = 1;
                break;
            case 2:
                afficheRegle();
                break;
            case 3:
            	cout << "Au revoir !" << endl;
            	return 0;
            default:
                cout << "Entrez un chiffre valide !" << endl;
                break;
        }
    }

	Grille g(h,w,s);
	Jeu j;
	j.remplirChoix(s);
	fin = 0;

	while(fin == 0)
	{
		system("clear");
		cout <<"             -------------------------------"<<endl;
	    cout <<"            |   BIENVENUE DANS LA MATRICE   |"<<endl;
	    cout <<"             -------------------------------"<<endl;

	    if (politique == 2)
	    {
	    	j.remplirRand();
	    }
		j.afficheScore();
		j.afficheChoix(politique);
		g.afficheGrille();
		Bloc x = j.choisirBloc(politique);
		x.afficheBloc();
		fin = j.placerBloc(g,x);
	}

	return 0;
}