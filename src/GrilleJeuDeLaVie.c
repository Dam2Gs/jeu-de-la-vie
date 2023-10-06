#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "GrilleJeuDeLaVie.h"

/* #define NDEBUG 
   decommenter pour annuler les tests
   de precondition
*/

/* Partie privee */
#define VIVANT 1
#define MORT 0

unsigned short obtenirEtat(JDLV_Grille laGrille, unsigned int x,unsigned int y) {
  return laGrille.cellules[x-1+(y-1)*JDLV_obtenirLargeur(laGrille)];
}

void fixerEtat(JDLV_Grille* laGrille, unsigned int x,unsigned int y, unsigned short lEtat) {
  (*laGrille).cellules[x-1+(y-1)*JDLV_obtenirLargeur(*laGrille)]=lEtat;
}

int zoneMemoireBienAllouee(JDLV_Grille laGrille) {
  return laGrille.cellules!=NULL;
}

/* Partie publique */


JDLV_Grille JDLV_creerGrille(unsigned int largeur,unsigned int hauteur) {
  int i,j;
  JDLV_Grille resultat;
  resultat.largeur=largeur;
  resultat.hauteur=hauteur;
  resultat.cellules=(unsigned short *)malloc(sizeof(unsigned short)*largeur*hauteur);
  for (i=1;i<=largeur;i++)
    for (j=1;j<=hauteur;j++) 
      fixerEtat(&resultat,i,j,MORT);
  return resultat;
}

unsigned int JDLV_obtenirLargeur(JDLV_Grille laGrille) {
  return laGrille.largeur;
}


unsigned int JDLV_obtenirHauteur(JDLV_Grille laGrille) {
  return laGrille.hauteur;
}


void JDLV_tuerCellule(JDLV_Grille* laGrille, unsigned int x,unsigned int y) {
  if (x<=JDLV_obtenirLargeur(*laGrille) && y<=JDLV_obtenirHauteur(*laGrille) && JDLV_estCelluleVivante(*laGrille,x,y)) { //préconditions
    assert(x>0 && x<=JDLV_obtenirLargeur(*laGrille) &&
	 y>0 && y<=JDLV_obtenirHauteur(*laGrille) &&
	 JDLV_estCelluleVivante(*laGrille,x,y) && 
	 zoneMemoireBienAllouee(*laGrille));

    fixerEtat(laGrille,x,y,MORT);
  }
}

void JDLV_faireNaitreCellule(JDLV_Grille* laGrille, unsigned int x,unsigned int y) {
  if (x<=JDLV_obtenirLargeur(*laGrille) && y<=JDLV_obtenirHauteur(*laGrille) && !JDLV_estCelluleVivante(*laGrille,x,y)) { //préconditions
   assert(x>0 && x<=JDLV_obtenirLargeur(*laGrille) &&
	 y>0 && y<=JDLV_obtenirHauteur(*laGrille) &&
	 !JDLV_estCelluleVivante(*laGrille,x,y) && 
	 zoneMemoireBienAllouee(*laGrille));

   fixerEtat(laGrille,x,y,VIVANT);
 }
}

int JDLV_estCelluleVivante(JDLV_Grille laGrille, unsigned int x,unsigned int y) {
  if (x<=JDLV_obtenirLargeur(laGrille) && y<=JDLV_obtenirHauteur(laGrille)) { //préconditions
    assert(x>0 && x<=JDLV_obtenirLargeur(laGrille) &&
	 y>0 && y<=JDLV_obtenirHauteur(laGrille) &&
	 zoneMemoireBienAllouee(laGrille));

  return obtenirEtat(laGrille,x,y)==VIVANT;
  } else {
    return 0;
  }
}

/* fonctions liees a l'utilisation deu C et de l'allocation dynamique */
JDLV_Grille JDLV_copier(JDLV_Grille uneGrille) {
  JDLV_Grille resultat;
  resultat=JDLV_creerGrille(JDLV_obtenirLargeur(uneGrille),JDLV_obtenirHauteur(uneGrille));
  memcpy(resultat.cellules,uneGrille.cellules,sizeof(unsigned short)*JDLV_obtenirLargeur(uneGrille)*JDLV_obtenirHauteur(uneGrille));
  return resultat;
}

int JDLV_memeGrilles(JDLV_Grille uneGrille, JDLV_Grille uneAutreGrille) {
  int res=1;
  int i,j;
  if ((JDLV_obtenirLargeur(uneGrille) != JDLV_obtenirLargeur(uneAutreGrille))
      || (JDLV_obtenirHauteur(uneGrille) != JDLV_obtenirHauteur(uneAutreGrille)))
    res=0;
  else {
    i=1;
    j=1;
    while ((res==1) && (j<=JDLV_obtenirHauteur(uneGrille))) {
      if (obtenirEtat(uneGrille,i,j)!=obtenirEtat(uneAutreGrille,i,j))
	res=0;
      else {
	i++;
	if (i>JDLV_obtenirLargeur(uneGrille)) {
	  j++;
	  i=1;
	}
      }
    }
  }
  return res;
}

void JDLV_effacer(JDLV_Grille* uneGrille) {
  free(uneGrille->cellules);
  uneGrille->cellules=NULL;
}

