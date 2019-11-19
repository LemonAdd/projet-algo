#include <stdio.h>
#define couleur(param) printf("\033[%sm",param)

void init(int m[8][8]) {
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if ((i == 3 && j == 3) || (i == 4 && j == 4)) {
				m[i][j] = 1;
			} else if ((i == 3 && j == 4) || (i == 4 && j == 3)) {
				m[i][j] = 2;
			} else {
				m[i][j] = 0;
			}
		}
	}
}

void affichage(int m[8][8]) {
	for (int k = 0; k < 33; ++k)
	{
		printf("-");
	}
	printf("\n");
	for (int i = 0; i < 8; ++i)
	{
		printf("|");
		for (int j = 0; j < 8; ++j)
		{
			printf("\033[34m %d \033[0m|", m[i][j]);
		}
		printf("\n");
		for (int k = 0; k < 33; ++k)
		{
			printf("-");
		}
		printf("\n");
	}
}

int case_existe(int l, int c) {
	if (l >= 0 && l < 8 && c >= 0 && c < 8)
	{
		return 1;
	} else {
		return 0;
	}
}

int verif(int l, int c, int m[8][8], int joueur) {
	int i, stop=0, in=0, r;
	i = l+1;
	while (i<8 && !stop) {
		if (m[i][c] != joueur && m[i][c] != 0)
		{
			in = 1;
		}
		if (m[i][c] == joueur) 
		{
			stop = 1;
		}
		i++;
	}
	if (stop == 1 && in==1)
	{
		r=1;
	} else {
		r=0;
	}

	return r;
}

int main(int argc, char const *argv[])
{
	int pions[8][8], fin=0, ligne;
	int colonne;

	init(pions);

	affichage(pions);

	while (!fin) {
		printf("J1 : Choisissez une position (exemple : A1)\n");
		scanf("%d %d", &colonne, &ligne);
		printf("%d\n", verif(ligne, colonne, pions, 1));
	}

	

	return 0;
}