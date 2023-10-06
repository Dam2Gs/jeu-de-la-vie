/**
 * \file Grille.h
 * \brief Implantation du TAD Grille pour le jeu de la vie
 * \author N. Delestre
 * \version 2.0
 * \date 20/4/2015
 *
 */

#ifndef __GRILLE_JEU_DE_LA_VIE__
#define __GRILLE_JEU_DE_LA_VIE__

/**
 * \brief Le type JDLV_Grille permet de représenter une grille
 *
 */

typedef struct {
  unsigned int largeur; /**< la largeur de la grille */
  unsigned int hauteur; /**< la hauteur de la grille */
  unsigned short *cellules; /**< le tableau dynamique (taille =  largeur*hauteur) de cellules */
} JDLV_Grille;

/**
 * \fn JDLV_Grille JDLV_creerGrille(unsigned int largeur,unsigned int hauteur)
 * \brief Fonction de création d'une grille de cellules mortes
 *
 * \param unsigned int largeur, la largeur de la grille
 * \param unsigned int hauteur, la hauteur de la grille
 * \return JDLV_Grille
 */
JDLV_Grille JDLV_creerGrille(unsigned int largeur,unsigned int hauteur);

/**
 * \fn unsigned int JDLV_obtenirLargeur(JDLV_Grille laGrille)
 * \brief Fonction qui permet d'obtenir la largeur d'une grille
 *
 * \param JDLV_Grille laGrille, la grille
 * \return unsigned int
 */
unsigned int JDLV_obtenirLargeur(JDLV_Grille laGrille);

/**
 * \fn unsigned int JDLV_obtenirHauteur(JDLV_Grille laGrille)
 * \brief Fonction qui permet d'obtenir la hauteur d'une grille
 *
 * \param JDLV_Grille laGrille, la grille
 * \return unsigned int
 */
unsigned int JDLV_obtenirHauteur(JDLV_Grille laGrille);

/**
 * \fn void JDLV_tuerCellule(JDLV_Grille* laGrille, unsigned int x, unsigned int y)
 * \brief Fonction qui permet de tuer une cellule d'une grille
 * \attention assertion : sur x et y 
 *
 * \param JDLV_Grille *laGrille, un pointeur sur la grille
 * \param unsigned int x, la colonne (largeur) ou se trouve la cellule
 * \param unsigned int y, la ligne (hauteur) ou se trouve la cellule
 */
void JDLV_tuerCellule(JDLV_Grille* laGrille, unsigned int x, unsigned int y);


/**
 * \fn void JDLV_faireNaitreCellule(JDLV_Grille* laGrille, unsigned int x,unsigned int y)
 * \brief Fonction qui permet de tuer une cellule d'une grille
 * \attention assertion : sur x et y 
 *
 * \param JDLV_Grille *laGrille, un pointeur sur la grille
 * \param unsigned int x, la colonne (largeur) ou se trouve la cellule
 * \param unsigned int y, la ligne (hauteur) ou se trouve la cellule
 */
void JDLV_faireNaitreCellule(JDLV_Grille* laGrille, unsigned int x, unsigned int y);

/**
 * \fn int JDLV_estCelluleVivante(JDLV_Grille laGrille, unsigned int x, unsigned int y)
 * \brief Fonction qui permet de tuer une cellule d'une grille
 * \attention assertion : sur x et y 
 *
 * \param JDLV_Grille laGrille, la grille
 * \param unsigned int x, la colonne (largeur) ou se trouve la cellule
 * \param unsigned int y, la ligne (hauteur) ou se trouve la cellule
 * \return int (0 non 1 oui)
 */
int JDLV_estCelluleVivante(JDLV_Grille laGrille, unsigned int x,unsigned int y);


/* fonctions liees a l'utilisation du C et de l'allocation dynamique */
/**
 * \fn JDLV_Grille JDLV_copier(JDLV_Grille uneGrille) 
 * \brief Fonction qui permet de copier une grille 
 *
 * \param JDLV_Grille uneGrille, la grille à copier
 */
JDLV_Grille JDLV_copier(JDLV_Grille uneGrille);

/**
 * \fn int JDLV_memeGrilles(JDLV_Grille uneGrille, JDLV_Grille uneAutreGrille)
 * \brief Fonction qui permet de savoir si deux grilles sont égales
 *
 * \param JDLV_Grille uneGrille, une première grille
 * \param JDLV_Grille uneAutreGrille, une deuxième grille
 * \return int (0 non 1 oui)
 */
int JDLV_memeGrilles(JDLV_Grille uneGrille, JDLV_Grille uneAutreGrille);

/**
 * \fn void JDLV_effacer(JDLV_Grille* uneGrille)
 * \brief Fonction qui permet de libérer l'espace mémoire qui a été réservé pour stocker les éléments de la grille
 *
 * \param JDLV_Grille uneGrille, la grille
 */
void JDLV_effacer(JDLV_Grille* uneGrille);
#endif
