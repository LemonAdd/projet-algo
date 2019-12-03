#include <stdio.h>
#define BLANC 1
#define NOIR 2
#define VIDE 0

void init(int m[8][8]) {
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if ((i == 3 && j == 3) || (i == 4 && j == 4)) {
				m[i][j] = BLANC;
			} else if ((i == 3 && j == 4) || (i == 4 && j == 3)) {
				m[i][j] = NOIR;
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

int case_valide (int l, int c) {
    return ((c >= 0) && (c < 8) && (l >= 0) && (l < 8));
}

int verif(int l, int c, int m[8][8], int joueur) {
	int ok, i, j, jou, adv;


	if (joueur == 1)
	{
		jou = NOIR;
		adv = BLANC;
	} else {
		jou = BLANC;
		adv = NOIR;
	}

	// on vérifie que la case existe
	if (!case_valide(l,c) || m[l][c] != 0) {
		return 0;
	}


	// on test la ligne verticale de haut à bas
	i = c + 1;
    ok = 0;
    while (case_valide(l, i) && m[l][i] == adv) {
        i++;
        ok = 1;
    }
    if (case_valide(l, i) && m[l][i] == jou && ok == 1) {
    	return 1;
    }

	// on test la ligne verticale de bas à haut
	i = c - 1;
    ok = 0;
    while (case_valide(l, i) && m[l][i] == adv) {
        i--;
        ok = 1;
    }
    if (case_valide(l, i) && m[l][i] == jou && ok == 1) {
    	return 1;
    }

    // on test la ligne horizontale de gauche à droite
	i = l + 1;
    ok = 0;
    while (case_valide(i, c) && m[i][c] == adv) {
        i++;
        ok = 1;
    }
    if (case_valide(i, c) && m[i][c] == jou && ok == 1) {
    	return 1;
    }

    // on test la ligne horizontale de droite à gauche
	i = l - 1;
    ok = 0;
    while (case_valide(i, c) && m[i][c] == adv) {
        i--;
        ok = 1;
    }
    if (case_valide(i, c) && m[i][c] == jou && ok == 1) {
    	return 1;
    }

    // on test la verticale de haut en bas et gauche droite
	i = l + 1;
	j = c + 1;
    ok = 0;
    while (case_valide(i, j) && m[i][j] == adv) {
        i++;
        j++;
        ok = 1;
    }
    if (case_valide(i, j) && m[i][j] == jou && ok == 1) {
    	return 1;
    }
    // on test la verticale de bas en haut et gauche droite
	i = l + 1;
	j = c - 1;
    ok = 0;
    while (case_valide(i, j) && m[i][j] == adv) {
        i++;
        j--;
        ok = 1;
    }
    if (case_valide(i, j) && m[i][j] == jou && ok == 1) {
    	return 1;
    }

    // on test la verticale de bas en haut et droite gauche
	i = l - 1;
	j = c - 1;
    ok = 0;
    while (case_valide(i, j) && m[i][j] == adv) {
        i--;
        j--;
        ok = 1;
    }
    if (case_valide(i, j) && m[i][j] == jou && ok == 1) {
    	return 1;
    }

    // on test la verticale de haut en bas et droite gauche
	i = l - 1;
	j = c + 1;
    ok = 0;
    while (case_valide(i, j) && m[i][j] == adv) {
        i--;
        j++;
        ok = 1;
    }
    if (case_valide(i, j) && m[i][j] == jou && ok == 1) {
    	return 1;
    }


	return 0;
}

void remplissage(int m[8][8], int l, int c, int joueur) {

	int i, j, jou, adv;


	if (joueur == 1)
	{
		jou = NOIR;
		adv = BLANC;
	} else {
		jou = BLANC;
		adv = NOIR;
	}
	    m[l][c] = jou;

    // vertical de bas en haut
    i = l - 1;
    while (case_valide(i, c) && m[i][c] == adv) 
    	i--;
    if (case_valide(i, c) && m[i][c] == jou) {
        i = l - 1;
        while (m[i][c] == adv) {
            m[i][c] = jou;
            i--;
        }
    }
    // vertical haut en bas
    i = l + 1;
    while (case_valide(i, c) && m[i][c] == adv) 
    	i++;
    if (case_valide(i, c) && m[i][c] == jou) {
        i = l + 1;
        while (m[i][c] == adv) {
            m[i][c] = jou;
            i++;
        }
    }
    // horizontal gauche à droite
    i = c + 1;
    while (case_valide(l, i) && m[l][i] == adv) 
    	i++;
    if (case_valide(l, i) && m[l][i] == jou) {
        i = c + 1;
        while (m[l][i] == adv) {
            m[l][i] = jou;
            i++;
        }
    }
    //horizontal droite à gauche 
    i = c - 1;
    while (case_valide(l, i) && m[l][i] == adv) 
    	i--;
    if (case_valide(l, i) && m[l][i] == jou) {
        i = c - 1;
        while (m[l][i] == adv) {
            m[l][i] = jou;
            i--;
        }
    }

   //diagonale droite à gauche Haut bas
    j = l + 1;
    i = c - 1;
    while (case_valide(j, i) && m[j][i] == adv) {
    	i--;
    	j++;
    }
    if (case_valide(j, i) && m[j][i] == jou) {
        i = c - 1;
        j = l + 1;
        while (m[j][i] == adv) {
            m[l][i] = jou;
            i--;
            j++;
        }
    }
    //diagonale droite à gauche Bas Haut
    j = l - 1;
    i = c - 1;
    while (case_valide(j, i) && m[j][i] == adv) {
    	i--;
    	j--;
    }
    if (case_valide(j, i) && m[j][i] == jou) {
        i = c - 1;
        j = l - 1;
        while (m[j][i] == adv) {
            m[l][i] = jou;
            i--;
            j--;
        }
    }
    //diagonale gauche droite Haut bas
    j = l + 1;
    i = c + 1;
    while (case_valide(j, i) && m[j][i] == adv) {
    	i++;
    	j++;
    }
    if (case_valide(j, i) && m[j][i] == jou) {
        i = c + 1;
        j = l + 1;
        while (m[j][i] == adv) {
            m[l][i] = jou;
            i++;
            j++;
        }
    }
    //diagonale gauche droite bas haut
    j = l - 1;
    i = c + 1;
    while (case_valide(j, i) && m[j][i] == adv) {
    	i++;
    	j--;
    }
    if (case_valide(j, i) && m[j][i] == jou) {
        i = c + 1;
        j = l - 1;
        while (m[j][i] == adv) {
            m[l][i] = jou;
            i++;
            j--;
        }
    }


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
		remplissage(pions,colonne,ligne,1);
		affichage(pions);
	}

	

	return 0;
}