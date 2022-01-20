#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <unistd.h>
using namespace std;

class Bloc
{
	private:
		vector<vector<int>> b_forme;

	public:
		Bloc(int type, int orientation);
		void afficheBloc();
		vector<vector<int>> getForme();
};

class Grille
{
	private:
		vector<vector<int>> g_plateau;

	public:
		Grille(int height, int width, int shape);
		void losangeW(vector<vector<int>> &grille, int height, int width);
		void losangeH(vector<vector<int>> &grille, int height, int width);
		void cercle(vector<vector<int>> &grille,  int height, int width);
		void triangle(vector<vector<int>> &grille,  int height, int width);
		void afficheGrille();
		vector<vector<int>> getPlateau();
		void setPlateau(vector<vector<int>> grille);
};

class Jeu
{
	private:
		vector<Bloc> mes_bloc;
		vector<Bloc> mes_bloc_rand;
		int mscore;

	public:
		Jeu();
		void afficheScore();
		void remplirChoix(int shape);
		void remplirRand();
		void afficheChoix(int politique);
		Bloc choisirBloc(int politique);
		int placerBloc(Grille &grille, Bloc bloc);
		int verifPos(Grille grille, Bloc bloc, int posX, int posY);
		vector<int> casseL(vector<vector<int>> grille);
		vector<int> casseC(vector<vector<int>> grille);
		int casseBloc(vector<vector<int>> &grille, vector<int> vec1, vector<int> vec2);
		void setScore(int s);
		int getScore();
};

void afficheMenu();
void afficheRegle();
void choisirForm(int &s);
void choisirHauteur(int &h);
void choisirLargeur(int &w);
void choisirPolitique(int &politique);