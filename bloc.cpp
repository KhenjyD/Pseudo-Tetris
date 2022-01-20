#include "tetris.hpp"

//Constructeur de la classe permet de créer différent type de bloc
Bloc::Bloc(int type, int orientation)
{
	if(type == 1)
	{
		switch(orientation)
		{
			case 1:
				b_forme = {{0,1},
						   {1,1}};
				break;
			case 2:
				b_forme = {{1,0},
						   {1,1}};
				break;
			case 3:
				b_forme = {{1,1},
						   {1,0}};
				break;
			case 4:
				b_forme = {{1,1},
						   {0,1}};
				break;
		}
	}
	else if (type == 2)
	{
		switch(orientation)
		{
			case 1:
				b_forme = {{1,0,0},
						   {1,1,1}};
				break;
			case 2:
				b_forme = {{0,0,1},
						   {1,1,1}};
				break;
			case 3:
				b_forme = {{1,1},
						   {0,1},
						   {0,1}};
				break;
			case 4:
				b_forme = {{1,0},
						   {1,0},
						   {1,1}};
				break;
		}
	}
	else if (type == 3)
	{
		switch(orientation)
		{
			case 1:
				b_forme = {{0,1,0},
						   {1,1,1}};
				break;
			case 2:
				b_forme = {{1,1,1},
						   {0,1,0}};
				break;
			case 3:
				b_forme = {{0,1},
						   {1,1},
						   {0,1}};
				break;
			case 4:
				b_forme = {{1,0},
						   {1,1},
						   {1,0}};
				break;
		}
	}
	else if (type == 4)
	{
		switch(orientation)
		{
			case 1:
				b_forme = {{1,1,0},
						   {0,1,1}};
				break;
			case 2:
				b_forme = {{0,1,1},
						   {1,1,0}};
				break;
			case 3:
				b_forme = {{1,0},
						   {1,1},
						   {0,1}};
				break;
			case 4:
				b_forme = {{0,1},
						   {1,1},
						   {1,0}};
				break;
		}
	}
	else if (type == 5)
	{
		switch(orientation)
		{
			case 1:
				b_forme = {{1},
						   {1},
						   {1},
						   {1}};
				break;
			case 2:
				b_forme = {{1,1,1,1}};
				break;
		}
	}
	else if (type == 6)
	{
		b_forme = {{1,1},
				   {1,1}};
	}
	else if (type == 7)
	{
		b_forme = {{1}};
	}
//Cercle
	else if(type == 8)
	{
		b_forme = {{1,1,1,1},
				   {1,1,1,1},
				   {1,1,1,1},
				   {1,1,1,1}};
	}
	else if(type == 9)
	{
		b_forme = {{0,1,1,0},
				   {1,1,1,1},
				   {1,1,1,1},
				   {0,1,1,0}};
	}
	else if(type == 10)
	{
		b_forme = {{1,0,0,1},
				   {1,0,0,1},
				   {1,0,0,1},
				   {1,1,1,1}};
	}
	else if(type == 11)
	{
		b_forme = {{1,1,1,1},
				   {0,0,0,1},
				   {0,0,0,1},
				   {0,0,0,1}};
	}
	else if(type == 12)
	{
		b_forme = {{1,1,1,1},
				   {1,1,1,0}};
	}
	else if(type == 13)
	{
		b_forme = {{1,1,1},
				   {0,0,1},
				   {0,0,1},
				   {1,1,1}};
	}
	else if(type == 14)
	{
		b_forme = {{1,1},
			   	   {1,1},
			   	   {1,1},
			   	   {1,1}};
	}
	else if (type == 15)
	{
		b_forme = {{1,1,1,1},
				   {1,1,1,1}};
	}
	else if (type == 16)
	{
		b_forme = {{1},
				   {1},
			   	   {1},
			   	   {1},
			   	   {1}};
	}
	else if(type == 17)
	{
		b_forme = {{1,1,1,1,1}};
	}
	else if (type == 18)
	{
		b_forme = {{1,1,1,1,1},
				   {1,0,0,0,1}};
	}
	else if (type == 19)
	{
		b_forme = {{1,0,0,0},
				   {1,0,0,0},
				   {1,0,0,1},
				   {1,1,1,1}};
	}
//Losange
	else if(type == 20){
        b_forme={{0,0,1,1},
                 {0,1,1,0},
                 {1,1,0,0},
                 {1,0,0,0}};
    }
    else if(type == 21){
        b_forme={{1,0,0,0},
                 {1,1,0,0},
                 {0,1,1,0},
                 {0,0,1,1}};
    }
    else if(type == 22){
        b_forme={{1,1,0,0},
                 {0,1,1,0},
                 {0,0,1,1},
                 {0,0,0,1}};
    }
    else if(type == 23){
        b_forme={{0,0,0,1},
                 {0,0,1,1},
                 {0,1,1,0},
                 {1,1,0,0}};
    }
    else if(type == 24){
        b_forme={{1,1,1,1},
                 {0,1,1,0},
                 {0,1,1,0},
                 {0,1,1,0}};
    }
    else if(type == 25){
        b_forme={{1},
                {1},
                {1},
                {1},
                {1}};
    }
    else if(type == 26){
        b_forme={{1,0,0,1},
                {0,1,1,0},
                {0,1,1,0},
                {1,0,0,1}};
    }
    else if(type == 27){
        b_forme={{0,0,0,1},
                 {1,1,1,1},
                 {0,0,0,1}};
    }
    else if(type == 28){
        b_forme={{1,1,1,1,1}};
    }
    else if(type == 29){
        b_forme={{1,1,1,1,1},
                 {0,1,1,1,0},
                 {0,0,1,0,0}};
    }
    else if(type == 30){
        b_forme={{1,1,1,1},
                {1,1,1,1},
                {1,1,1,1},
                {1,1,1,1}};
    }
    else if(type == 31){
        b_forme={{1,1,1,1},
                 {0,0,0,1}};
    }
    else if(type == 32){
        b_forme={{1,1},
                 {0,1},
                 {0,1},
                 {0,1}};
    }
    else if(type == 33){
        b_forme={{1,0},
                 {1,0},
                 {1,0},
                 {1,1}};
    }
//Triangle
	else if (type == 34)
	{
		b_forme = {{1,0,0},
				   {1,1,1},
				   {0,0,1}}; 
	}
	else if (type == 35)
	{
		b_forme = {{1,1,0},
				   {0,1,0},
				   {0,1,1}}; 
	}
	else if (type == 36)
	{
		b_forme = {{0,0,1},
				   {1,1,1},
				   {1,0,0}}; 
	}
	else if (type == 37)
	{
		b_forme = {{0,1,1},
				   {0,1,0},
				   {1,1,0}}; 
	}
	else if (type == 38)
	{
		b_forme = {{0,0,1},
				   {0,1,0},
				   {1,0,0}}; 
	}
	else if (type == 39)
	{
		b_forme = {{1,0,0},
				   {0,1,0},
				   {0,0,1}}; 
	}
	else if (type == 40)
	{
		b_forme = {{1},
				   {1},
				   {1}}; 
	}
	else if (type == 41)
	{
		b_forme = {{1,1,1}}; 
	}
	else if (type == 42)
	{
		b_forme = {{1,1}}; 
	}
	else if (type == 43)
	{
		b_forme = {{1},
				   {1}}; 
	}
	else if (type == 44)
	{
		b_forme = {{0,1,0},
				   {1,1,1},
				   {0,1,0}}; 
	}
}

//Permet de récupérer la matrice d'un bloc
vector<vector<int>> Bloc::getForme()
{
	return b_forme;
}

//Permet d'afficher un bloc
void Bloc::afficheBloc()
{
	for (int i = 0; i < b_forme.size(); ++i)
	{
		for (int j = 0; j < b_forme[i].size(); ++j)
		{
			if (b_forme[i][j] == 0)
			{
				cout << " " << " ";
			}
			else
			{
				cout << "□" << " ";
			}
		}
		cout << endl;
	}
}