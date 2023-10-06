#ifndef __JEU_DE_LA_VIE_PRIVE__
#define __JEU_DE_LA_VIE_PRIVE__
#include "JeuDeLaVie.h"
void initialiser(JDLV_Grille* uneGrille, unsigned short probabilite);
unsigned int nbVoisinsVivants(JDLV_Grille uneGrille, unsigned int x, unsigned int y);
void calculerNouvelleGeneration(JDLV_Grille *uneGrille);

#endif

