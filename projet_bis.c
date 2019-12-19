#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLANC 'O'
#define NOIR 'X'
#define VIDE ' '


void initialise_rand()
{
  srand(time(NULL));  
}

/*tire un entier au hasard entre inf et sup */
int hasard(int inf, int sup)
{
  int rando = rand();
  return (inf + (rando % (sup - inf +1)));
}


void init(char m[8][8]) {
  for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
	{
	  if ((i == 3 && j == 3) || (i == 4 && j == 4)) {
	    m[i][j] = BLANC;
	  } else if ((i == 3 && j == 4) || (i == 4 && j == 3)) {
	    m[i][j] = NOIR;
	  } else {
	    m[i][j] = VIDE;
	  }
	}
    }
}

void affichage(char m[8][8]) {
  int c = 0;
  int range = 0;
  printf(" ");
  for (int g = 0; g<8; g++){
    printf("  %d ",c);
    c++;
  }
  printf("\n ");
  for (int k = 0; k < 33; ++k)
    {
      printf("-");
    }
  printf("\n");
	
  for (int i = 0; i < 8; ++i)
    {

      printf("%d",range);
      range++;
      printf("|");
      for (int j = 0; j < 8; ++j)
	{
	  if (m[i][j] == VIDE)
	    {
	      printf(" %c |", m[i][j]);
	    } else if (m[i][j] == BLANC)
	    {
	      printf("\033[31m %c \033[0m|", m[i][j]);
	    } else if (m[i][j] == NOIR)
	    {
	      printf("\033[32m %c \033[0m|", m[i][j]);
	    }
			
	}
      printf("\n ");
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

int verif(int l, int c, char m[8][8], int joueur) {
  int ok, i, j;
  char jou, adv;


  if (joueur == 1)
    {
      jou = NOIR;
      adv = BLANC;
    } else {
    jou = BLANC;
    adv = NOIR;
  }

  // on vérifie que la case existe
  if (!case_valide(l,c) || m[l][c] != ' ') {
    return 0;
  }

  // on test la ligne horizontale de gauche à droite

  i = c + 1;
  ok = 0;
  while (case_valide(l, i) && m[l][i] == adv) {
    i++;
    ok = 1;
  }
  if (case_valide(l, i) && m[l][i] == jou && ok == 1) {
    return 1;
  }

  // on test la ligne horizontale de droite à gauche
  i = c - 1;
  ok = 0;
  while (case_valide(l, i) && m[l][i] == adv) {
    i--;
    ok = 1;
  }
  if (case_valide(l, i) && m[l][i] == jou && ok == 1) {
    return 1;
  }
  // on test la ligne verticale de haut à bas
    
  i = l + 1;
  ok = 0;
  while (case_valide(i, c) && m[i][c] == adv) {
    i++;
    ok = 1;
  }
  if (case_valide(i, c) && m[i][c] == jou && ok == 1) {
    return 1;
  }
  // on test la ligne verticale de bas à haut
    
  i = l - 1;
  ok = 0;
  while (case_valide(i, c) && m[i][c] == adv) {
    i--;
    ok = 1;
  }
  if (case_valide(i, c) && m[i][c] == jou && ok == 1) {
    return 1;
  }

  // on test la diago de haut en bas et gauche droite
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
  // on test la diago de bas en haut et gauche droite
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

  // on test la diago de bas en haut et droite gauche
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

  // on test la diago de haut en bas et droite gauche
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

void remplissage(char m[8][8], int l, int c, int joueur) {

  int i, j;
  char jou, adv;


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
  i = l + 1;
  j = c - 1;
  while (case_valide(i, j) && m[i][j] == adv) {
    j--;
    i++;
  }
  if (case_valide(i, j) && m[i][j] == jou) {
    j = c - 1;
    i = l + 1;
    while (m[i][j] == adv) {
      m[i][j] = jou;
      j--;
      i++;
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
      m[j][i] = jou;
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
      m[j][i] = jou;
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
      m[j][i] = jou;
      i++;
      j--;
    }
  }


}


int max(char m[8][8], int l, int c, int joueur) { // renvoie le max de pions "mangeables" pour une position
  int i, j, cpt=0;
  char jou, adv;


  if (joueur == 1)
    {
      jou = NOIR;
      adv = BLANC;
    } else {
    jou = BLANC;
    adv = NOIR;
  }

  // vertical de bas en haut
  i = l - 1;
  while (case_valide(i, c) && m[i][c] == adv) 
    i--;
  if (case_valide(i, c) && m[i][c] == jou) {
    i = l - 1;
    while (m[i][c] == adv) {
      i--;
      cpt++;
    }
  }


  // vertical haut en bas
  i = l + 1;
  while (case_valide(i, c) && m[i][c] == adv) 
    i++;
  if (case_valide(i, c) && m[i][c] == jou) {
    i = l + 1;
    while (m[i][c] == adv) {
      cpt++;
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
      cpt++;
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
      cpt++;
      i--;
    }
  }

  //diagonale droite à gauche Haut bas
  i = l + 1;
  j = c - 1;
  while (case_valide(i, j) && m[i][j] == adv) {
    j--;
    i++;
  }
  if (case_valide(i, j) && m[i][j] == jou) {
    j = c - 1;
    i = l + 1;
    while (m[i][j] == adv) {
      cpt++;
      j--;
      i++;
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
      cpt++;
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
      cpt++;
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
      cpt++;
      i++;
      j--;
    }
  }
  return cpt;
  
}

void meilleurePos(char m[8][8], int *c, int *l, int joueur) {
  int memc, meml, maxi=0;
  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      if (max(m,i,j,joueur) > maxi)
      {
        memc = i;
        meml = j;
        maxi = max(m,i,j,joueur);
      }
    }
  }
  *c = memc;
  *l = meml;
}


int next(int joueur) {
  return (joueur%2 +1);
}

int termine(char m[8][8]) {
  for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
	{
	  if (m[i][j] == ' ' || verif(i,j,m,1) || verif(i,j,m,2))
	    {
	      return 0;
	    }
	}
    }
  return 1;
}
void compte_points(char m[8][8]){
  int b=0,n=0;
   for (int i = 0; i < 8; ++i)
    {
      for (int j = 0; j < 8; ++j)
	{
	  if (m[i][j]== BLANC) {
	    b++;
	  } else if (m[i][j]== NOIR) {
	    n++ ;
	  }
	}
    }
   printf("Il y a %d pions noirs et %d pions blancs\n",n,b);
}

int main(int argc, char const *argv[])
{
  int fin=0, ligne, colonne, joueur=1, ok = 0, mode_jeu=0;
  char pions[8][8];

  initialise_rand();
  init(pions);

  printf("Bonjour, bienvenue au jeu d'othello.\nVeuillez choisir un mode de jeux : (\033[31m 1 \033[0m pour jouer contre un autre joueur, \033[31m 2 \033[0m pour jouer contre l'IA random et \033[31m 3 \033[0m pour l'IA max)\n");
  printf("\033[31m Le J1 est représenté par des \033[0m X \033[31m et le J2 par des \033[0m 0\n");

  while((mode_jeu !=1) && (mode_jeu !=2) && (mode_jeu !=3)){
    scanf("%d",&mode_jeu);
    if((mode_jeu != 1) && (mode_jeu != 2) && (mode_jeu != 3)){
      printf("Mauvaise saisie, veuillez reessayer:\n");
    }
  }
  
  // jeu contre un autre joueur
    
  if(mode_jeu == 1){
    while (!fin) {
      
      
      affichage(pions);
      
      while (!ok) {
	
      	printf("J%d : Choisissez une case (ligne puis colonne)\n", joueur);
      	scanf("%d %d", &ligne, &colonne);
        printf("%d\n", max(pions,ligne,colonne,joueur));
	  
      	if (verif(ligne,colonne,pions,joueur))
      	{
          remplissage(pions,ligne,colonne,joueur);
          ok = 1;
          joueur = next(joueur);
      	} else {
          printf("Erreur, choisissez une autre case\n");
        }
      }
      
      ok = 0;
      
      if (termine(pions)) {
        fin = 1;
      }
    } // fin while
  } // fin if
  
  // jeu contre IA random
  else if (mode_jeu == 2) {
    while (!fin) {
      
      affichage(pions);
      
  	  while (!ok) {
  	    
  	    if(joueur%2 != 0){
  	      printf("Choisissez une case (ligne puis colonne)\n");
  	      scanf("%d %d", &ligne, &colonne);
  	    } else {
  	      ligne = hasard(0,7);
  	      colonne = hasard(0,7); 
  	    }


  	    if(joueur%2 != 0){
  	      if (verif(ligne,colonne,pions,joueur)) {
  		      remplissage(pions,ligne,colonne,joueur);
  		      ok = 1;
  		      joueur = next(joueur);
  		    } else {
  		      printf("Erreur, choisissez une autre case\n");
  	      }
  	    } else if (verif(ligne,colonne,pions,joueur)) {
  		      printf("L'IA a choisi :\n%d %d\n",ligne, colonne);
  		      remplissage(pions,ligne,colonne,joueur);
  		      ok = 1;
  		      joueur = next(joueur); 
  	    }
  	  }
  	  
  	  ok = 0;
  	  
  	  if (termine(pions))
  	    {
  	      fin = 1;
  	    }
  	  
      } //fin while
  } //fin else if

  //jeu contre IA max
  else {
    while (!fin) {
      
      affichage(pions);
      
      while (!ok) {
        
        if(joueur%2 != 0){
          printf("Choisissez une case (ligne puis colonne)\n");
          scanf("%d %d", &ligne, &colonne);
        } else {
          meilleurePos(pions,&ligne,&colonne,joueur);
        }


        if(joueur%2 != 0){
          if (verif(ligne,colonne,pions,joueur)) {
            remplissage(pions,ligne,colonne,joueur);
            ok = 1;
            joueur = next(joueur);
          } else {
            printf("Erreur, choisissez une autre case\n");
          }
        } else if (verif(ligne,colonne,pions,joueur)) {
            printf("L'IA a choisi :\n%d %d\n",ligne, colonne);
            remplissage(pions,ligne,colonne,joueur);
            ok = 1;
            joueur = next(joueur); 
        }
      }
      
      ok = 0;
      
      if (termine(pions))
        {
          fin = 1;
        }
      
    } //fin while
  } //fin else

  //Partie finie, comptage des points
  affichage(pions);
  compte_points(pions);
  printf("Fin de la partie\n");
  return 0;
}
