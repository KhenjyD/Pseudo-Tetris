#include "tetris.hpp"

//Constructeur de la classe grille, permet de créer différent type de grille
Grille::Grille(int height, int width, int shape)
{
	int creer = 0;
	vector<vector<int>> grille(height, vector<int>(width,-1));
	g_plateau = grille;

	while(creer != 1)
	{
		switch(shape)
		{
			case 1:
				if (height < width)
				{
					losangeH(g_plateau, height, width);
				}
				else
				{
					losangeW(g_plateau, height, width);
				}
				creer = 1;
				break;
			case 2:
				triangle(g_plateau, height, width);
				creer = 1;
				break;
			case 3:
				cercle(g_plateau, height, width);
				creer = 1;
				break;
			default:
				break;
		}
	}
}

//Permet à la grille de prendre la forme d'un losange en fonction de sa largeur
void Grille::losangeW(vector<vector<int>> &grille, int height, int width)
{
	int i, j, tmp, tmp2;
    int midH = height/2;
    int midW = width/2;
    tmp = 0;
    
    if (width%2 == 0)
    {
    	width--;
    	tmp2 = width;
    }
    else
    {
    	tmp2 = width;
    }

    for (i = midH; i >= 0; --i)
    {
        for (j = tmp; j < width; ++j)
        {
            grille[i][j] = 0;
        }
        width--;
        tmp++;
    }

    tmp = 0;
    for (i = midH; i < height; ++i)
    {
    	for (j = tmp; j < tmp2; ++j)
    	{
    		grille[i][j] = 0;
    	}
    	tmp2--;
        tmp++;
    }
}

//Permet à la grille de prendre la forme d'un losange en fonction de sa hauteur
void Grille::losangeH(vector<vector<int>> &grille, int height, int width)
{
	int i, j, tmp, tmp2;
    int midH = height/2;
    int midW = width/2;
    tmp = 0;

    if (height%2 == 0)
    {
    	height--;
    	tmp2 = height;
    }
    else
    {
    	tmp2 = height;
    }

    for (j = midW; j >= 0; --j)
    {
        for (i = tmp; i < height; ++i)
        {
            grille[i][j] = 0;
        }
        height--;
        tmp++;
    }

    tmp = 0;
    for (j = midW; j < width; ++j)
    {
        for (i = tmp; i < tmp2; ++i)
        {
            grille[i][j] = 0;
        }
        tmp2--;
        tmp++;
    }
}

//Permet à la grille de prendre la forme d'un triangle
void Grille::triangle(vector<vector<int>> &grille, int height, int width)
{
    int i, j, tmp;
    int midH = height/2;
    int midW = width/2;
    tmp = midW;
    for (i = 0; i < height; i++)
    {
        for (j = tmp; j <= midW; j++)
        {
            grille[i][j] = 0;
        }
        midW++;
        if(midW == width){
            break;
        }
        tmp--;
    }
}

//Permet à la grille de prendre la forme d'un cercle
void Grille::cercle(vector<vector<int>> &grille, int height, int width)
{
    int i, j, tmp, tmp2, tmp3,r,d;
    int midH = height/2;
    int midW = width/2;

    if (height > width)
    {
    	r = midH;
    } 
    else
    {
    	r = midW;
    }

    tmp = midW;
    tmp2 = midH;
    
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width ; j++)
        {
            tmp3 = (((i-midH) * (i-midH)) + (j-midW) * (j-midW));
            d = sqrt(tmp3);
            if(r == d || r > d){
                grille[i][j] = 0;
            }
        }
    }
}

//Permet d'afficher une grille
void Grille::afficheGrille ()
{
	int i,j;
	char c;
   	
   	cout << "   ";
	for (i = 0,c = 'a'; i < g_plateau[0].size(); ++i,++c)
	{
		cout << " "<<c;
	}
	cout << endl;

	cout << "  =";
	for (i = 0; i < g_plateau[0].size(); ++i)
	{
		cout << " =";
	}
	cout << " =";
	cout << endl;

	
	for (i = 0,c = 'A'; i < g_plateau.size(); ++i,++c)
	{
		cout << c << " = ";
		for (j = 0; j < g_plateau[i].size(); ++j)
		{
			if(g_plateau[i][j]== -1)
			{
				cout << " " << " " ;
			}
			else if(g_plateau[i][j]==1)
			{
				cout << "□" << " " ;
			}
			else
			{
				cout << "." << " ";
			}
		}
		cout << "=";
		cout << endl;
	}

    cout << "  =";
	for (i = 0; i < g_plateau[0].size(); ++i)
	{
		cout << " =";
	}
	cout << " =";
	cout << endl;
}

//Permet de récupérer la matrice d'une grille
vector<vector<int>> Grille::getPlateau()
{
	return g_plateau;
}

//Permet de modifier la matrice d'une grille
void Grille::setPlateau(vector<vector<int>> grille)
{
	g_plateau = grille;
}