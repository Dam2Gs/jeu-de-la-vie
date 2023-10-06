#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "GrilleJeuDeLaVie.h"
#include "JeuDeLaVie.h"

void afficher_ncurses(JDLV_Grille uneGrille) {
  unsigned int i,j;
  
  clear(); /* Effacement de l'ecran (ncurses) */
  move (0,0); /* Position du curseur en haut à gauche (ncurses) */

  for (i=1;i<=JDLV_obtenirLargeur(uneGrille);i++) {   
    for (j=1;j<=JDLV_obtenirHauteur(uneGrille);j++)
      if (JDLV_estCelluleVivante(uneGrille,i,j))
	printw("*");
      else
	printw(" ");
    printw("\n");
  }

  refresh(); /* On reffraichi l'ecran (ncurses) */
  sleep(1);   
}

/* void saisirInfos(unsigned int *largeur, unsigned int *hauteur, unsigned int *probabilite, unsigned int *nbGeneration) {
  printf("Largeur de la grille : ");
  scanf("%u",largeur);
  printf("Hauteur de la grille : ");
  scanf("%u",hauteur);
  printf("Probabilité d'apparition initiale d'une cellule (0-100) : ");
  scanf("%u",probabilite);
  printf("Nombre de générations : ");
  scanf("%u",nbGeneration);
} */

int main(int argc,char** argv) {
  if (argc != 5) {
        printf("Utilisation : %s <largeur> <hauteur> <probabilité> <nombre de générations>\n", argv[0]);
        return EXIT_FAILURE;
  }
  printf("JEU DE LA VIE\n");
  unsigned int largeur = atoi(argv[1]), hauteur = atoi(argv[2]), probabilite = atoi(argv[3]), nbGeneration = atoi(argv[4]);

  /* saisirInfos(&largeur,&hauteur,&probabilite,&nbGeneration); */

  initscr(); /* Initialisation de l'ecran (ncurses) */
  simulerJeuDeLaVie(largeur,hauteur,probabilite,nbGeneration,afficher_ncurses);
  endwin(); /* Fermeture de l'ecran (ncurses) */
  return EXIT_SUCCESS;
}
