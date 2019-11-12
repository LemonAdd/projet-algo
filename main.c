#include <stdio.h>

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
			printf(" %d |", m[i][j]);
		}
		printf("\n");
		for (int k = 0; k < 33; ++k)
		{
			printf("-");
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	
	int pions[8][8];

	init(pions);

	affichage(pions);

	

	return 0;
}