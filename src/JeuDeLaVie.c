#include <math.h>
#include <stdlib.h>
#include "GrilleJeuDeLaVie.h"
#include "JeuDeLaVie.h"
#include "JeuDeLaViePrive.h"
#include <time.h>

/* Partie Privee */
void initialiser(JDLV_Grille* uneGrille, unsigned short probabilite){
  unsigned int i, j;
  int doitNaitre;
  srand(time(NULL));
  for(i=1;i<=JDLV_obtenirLargeur(*uneGrille);i++) {
    for(j=1;j<=JDLV_obtenirHauteur(*uneGrille);j++) {
      doitNaitre = (rand() % 101)<=probabilite;
      if (JDLV_estCelluleVivante(*uneGrille,i,j) && !doitNaitre) {
	      JDLV_tuerCellule(uneGrille,i,j);
      } else {
        if (!JDLV_estCelluleVivante(*uneGrille,i,j) && doitNaitre) {
          JDLV_faireNaitreCellule(uneGrille,i,j);
      	}
      }
    }
  }
}


unsigned int max(unsigned int a, unsigned int b) {
  if (a<b)
    return b;
  else
    return a;
}

unsigned int min(unsigned int a, unsigned int b) {
  if (a>b)
    return b;
  else
    return a;
}

unsigned int nbVoisinsVivants(JDLV_Grille uneGrille, unsigned int x, unsigned int y) {
  if ((x<=JDLV_obtenirLargeur(uneGrille)) && (y<=JDLV_obtenirHauteur(uneGrille))) { //préconditions
    unsigned int resultat, i, j, minx, miny, maxx, maxy;
    resultat=0;
    minx=max(1,x-1);
    miny=max(1,y-1);
    maxx=min(JDLV_obtenirLargeur(uneGrille),x+1);
    maxy=min(JDLV_obtenirHauteur(uneGrille),y+1);
    for(i=minx;i<=maxx;i++) {
      for(j=miny;j<=maxy;j++) {
	if (JDLV_estCelluleVivante(uneGrille,i,j) && ((i!=x) || (j!=y))) {
	  resultat=resultat+1;
	}
      }
    }
  return resultat;
  } else {
    return 0;
  }
}

int vaNaitreOuContinuerAVivre(JDLV_Grille uneGrille, unsigned int x, unsigned int y) {
  if ((x<=JDLV_obtenirLargeur(uneGrille)) && (y<=JDLV_obtenirHauteur(uneGrille))) { //préconditions
    unsigned int nombreVoisinsVivants;
    nombreVoisinsVivants=nbVoisinsVivants(uneGrille,x,y);
    return (!JDLV_estCelluleVivante(uneGrille,x,y) && nombreVoisinsVivants==3) || (JDLV_estCelluleVivante(uneGrille,x,y) && (nombreVoisinsVivants==3 || nombreVoisinsVivants==2));
  } else {
    return 0;
  }
}

void calculerNouvelleGeneration(JDLV_Grille *uneGrille) {
  JDLV_Grille temp;
  unsigned int i, j;
  temp=JDLV_creerGrille(JDLV_obtenirLargeur(*uneGrille),JDLV_obtenirHauteur(*uneGrille));
  for(i=1;i<=JDLV_obtenirLargeur(*uneGrille);i++) {
    for(j=1;j<=JDLV_obtenirHauteur(*uneGrille);j++) {
      if (vaNaitreOuContinuerAVivre(*uneGrille,i,j)) {
        JDLV_faireNaitreCellule(&temp,i,j);
      } else {
          JDLV_tuerCellule(&temp,i,j);
        }
    }
  }
  *uneGrille=temp;
}



/* Partie publique */
void simulerJeuDeLaVie(unsigned int largeur, unsigned int hauteur, unsigned int probabilite, unsigned int nbGeneration, void(*afficher)(JDLV_Grille)) {
  JDLV_Grille laGrille;
  unsigned int i;  

  laGrille=JDLV_creerGrille(largeur,hauteur);
  initialiser(&laGrille,probabilite);
  for (i=1;i<=nbGeneration;i++) {
    afficher(laGrille);
    calculerNouvelleGeneration(&laGrille);
  }
  afficher(laGrille);
  JDLV_effacer(&laGrille);
}
