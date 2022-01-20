#include "tetris.hpp"

//Constructeur de la classe Jeu, permet d'initialiser le jeu avec un score à 0
Jeu::Jeu()
{
	mscore = 0;
}

//Permet d'afficher le score du joueur
void Jeu::afficheScore(){
    for(int i = 0; i < 10; i++){
        cout << "-";
    }
    cout<<endl;
    cout <<" Score: " << mscore <<endl;
    for(int j = 0; j < 10; j++){
        cout <<"-";
    }
    cout<<endl;
}

//Permet de remplir la liste de choix de bloc
void Jeu::remplirChoix(int shape)
{
	int i;

	for (i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			Bloc b(i,j);
			mes_bloc.push_back(b);
		}
	}
	Bloc b2(5,1);
	mes_bloc.push_back(b2);
	Bloc b3(5,2);
	mes_bloc.push_back(b3);
	Bloc b4(6,0);
	mes_bloc.push_back(b4);
	Bloc b5(7,0);
	mes_bloc.push_back(b5);

	if (shape == 1)
	{
		for (i = 20; i <= 33; ++i)
		{
			Bloc b6(i,0);
			mes_bloc.push_back(b6);
		}
	}
	else if(shape == 2)
	{
		for (i = 34; i <= 44; ++i)
		{
			Bloc b6(i,0);
			mes_bloc.push_back(b6);
		}
	}
	else if(shape == 3)
	{
		for (i = 8; i <= 19; ++i)
		{
			Bloc b6(i,0);
			mes_bloc.push_back(b6);
		}
	}
}

//Permet de remplir aléatoire la liste de choix de bloc
void Jeu::remplirRand()
{
    int r_and;

    while(mes_bloc_rand.size() != 0)
    {
    	mes_bloc_rand.pop_back();
    }
   	
   	while(mes_bloc_rand.size() != 3)
   	{
   		r_and = rand()%mes_bloc.size();
   		mes_bloc_rand.push_back(mes_bloc[r_and]);
   	}
}

//Permet d'afficher la liste de choix de bloc
void Jeu::afficheChoix(int politique)
{
	int i;

	if (politique == 1)
	{
		for (i = 0; i < mes_bloc.size(); ++i)
		{
			cout << "Bloc " << i << endl;
			mes_bloc[i].afficheBloc();
			cout << endl;
		}
	}
	else if (politique == 2)
	{
		for (i = 0; i < mes_bloc_rand.size(); ++i)
		{
			cout << "Bloc " << i << endl;
			mes_bloc_rand[i].afficheBloc();
			cout << endl;
		}
	}
}

//Permet de choisir un bloc parmis les bloc disponibles
Bloc Jeu::choisirBloc(int politique)
{
    int pos;

    if (politique == 1)
    {
    	cout << "Choisissez le bloc a jouer: ";
	    cin >> pos;
	    if(pos > mes_bloc.size()-1){
	        cout << "Choisissez un bloc entre 0 et "<<mes_bloc.size()-1<<": ";
	        do{
	        cin >> pos;
	        cout << "Choisissez un bloc entre 0 et "<<mes_bloc.size()-1<<": ";
	        }while(pos > mes_bloc.size()-1);
	    }
	    cout << "Vous avez choisi: "<<endl;
	    return mes_bloc[pos];
    }
    else if(politique == 2)
    {
    	cout << "Choisissez le bloc a jouer: ";
	    cin >> pos;
	    if(pos > mes_bloc_rand.size()-1){
	        cout << "Choisissez un bloc entre 0 et "<<mes_bloc_rand.size()-1<<": ";
	        do{
	        cin >> pos;
	        cout << "Choisissez un bloc entre 0 et "<<mes_bloc_rand.size()-1<<": ";
	        }while(pos > mes_bloc_rand.size()-1);
	    }
	    cout << "Vous avez choisi: "<<endl;
	    return mes_bloc_rand[pos];
    }  
}

//Permet de placer un bloc sur la grille
int Jeu::placerBloc(Grille &grille, Bloc bloc)
{
	char pos1, pos2;
    int posX, posY,i ,j ,tmp,count = 1;

    cout << "Entrée coordonnée pour placer le bloc." << endl;
	cout << "Ligne: ";
	cin >> pos1;
	cout << "Colonne: ";
	cin >> pos2;
    posX = pos1 - 97;
    posY = pos2 - 97;

    while(!verifPos(grille,bloc,posX,posY))
    {
        if(count == 3){
            cout << "Fin du programme, trop de tentatives !"<<endl;
            afficheScore();
            return 1;
        }
        count++;

        cout << "Entrée coordonnée pour placer le bloc." << endl;
		cout << "Ligne: ";
		cin >> pos1;
		cout << "Colonne: ";
		cin >> pos2;
	    posX = pos1 - 97;
    	posY = pos2 - 97;
    }
    tmp = posY;

    vector<vector<int>> gtmp = grille.getPlateau();
    vector<vector<int>> btmp = bloc.getForme();
    for (i = btmp.size()-1; i >= 0; --i)
    {
        for (j = 0; j < btmp[0].size(); ++j)
        {
            if (btmp[i][j] == 1 )
            {
                gtmp[posX][posY] = btmp[i][j];
            }
            posY++;
        }
        posX--;
        posY = tmp;
    }
    vector<int> vec1 = casseL(gtmp);
    vector<int> vec2 = casseC(gtmp);
    int score = casseBloc(gtmp,vec1,vec2);
    setScore(score);
    grille.setPlateau(gtmp);

    return 0;
}

//Permet de vérifier si les coordonnées entrées sont valides pour placer un bloc
int Jeu::verifPos(Grille grille, Bloc bloc, int posX, int posY)
{
	int i, j, tmp = posY;
	vector<vector<int>> gtmp = grille.getPlateau();
	vector<vector<int>> btmp = bloc.getForme();

	for (i = btmp.size()-1; i >= 0; --i)
	{
		for (j = 0; j < btmp[0].size(); ++j)
		{
			if ((posX < 0 || posX > gtmp.size()) || (posY < 0 || posY > gtmp[0].size()))
			{
				cout << "Coordonnée invalide !" << endl;
				return 0;
			}
			if ((gtmp[posX][posY] == -1 || gtmp[posX][posY] == 1) && btmp[i][j] == 1)
			{
				cout << "Coordonnée invalide !" << endl;
				return 0;
			}
			posY++;
		}
		posX--;
		posY = tmp;
	}
	return 1;
}

//Permet de vérifier si certaines lignes de la grille sont pleines 
vector<int> Jeu::casseL(vector<vector<int>> grille)
{
    int i, j, posX, found,seul = 0;
    vector<int> casse;
    for (i = 0; i < grille.size(); ++i)
    {
    	found = 0;
    	seul = 0;
    	for (j = 0; j < grille[0].size(); ++j)
	    {
	    	if(grille[i][j] == 0)
	    	{
	            found = 1;
	        }
	        if (grille[i][j] != -1)
	        {
	        	seul++;
	        }
	    }

	    if (found == 0 && seul != 1)
	    {
	    	casse.push_back(i);
	    }
    }

    return casse;
}

//Permet de vérifier si certaines colonnes de la grille sont pleines
vector<int> Jeu::casseC(vector<vector<int>> grille)
{
    int i, j, posY, found, seul = 0;
    vector<int> casse;
    for (j = 0; j < grille[0].size(); ++j)
    {
    	found = 0;
    	seul = 0;
    	for (i = 0; i < grille.size(); ++i)
	    {
	    	if(grille[i][j] == 0)
	    	{
	            found = 1;
	        }
	        if (grille[i][j] != -1)
	        {
	        	seul++;
	        }
	    }

	    if (found == 0 && seul != 1)
	    {
	    	casse.push_back(j);
	    }
    }

    return casse;
}

//Permet de réinitialiser les lignes/colonnes qui sont pleines et incrémente le score
int Jeu::casseBloc(vector<vector<int>> &grille, vector<int> vec1 ,vector<int> vec2)
{
	int i, j, posX, posY, score = 0;

	for (i = 0; i < vec1.size(); ++i)
    {
    	posX = vec1[i];
    	for (j = 0; j < grille[0].size(); ++j)
    	{
    		if (grille[posX][j] != -1)
    		{
    			grille[posX][j] = 0;
    			score++;
    		}
    	}
    }

    for (j = 0; j < vec2.size(); ++j)
    {
    	posY = vec2[j];
    	for (i = 0; i < grille.size(); ++i)
    	{
    		if (grille[i][posY] != -1)
    		{
    			grille[i][posY] = 0;
    			score++;
    		}
    	}
    }

    return score;
}

//Permet d'incrémenter le score du joueur
void Jeu::setScore(int s)
{
	mscore += (s*10);
}

//Permet de récupérer le score
int Jeu::getScore()
{
	return mscore;
}