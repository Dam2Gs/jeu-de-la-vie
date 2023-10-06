#include<stdlib.h>
#include<CUnit/Basic.h>
#include"GrilleJeuDeLaVie.h"
#include"JeuDeLaVie.h"
#include"JeuDeLaViePrive.h"
#define TRUE 1
#define FALSE 0

int init_suite_success(void) { 
  return 0; 
}

int clean_suite_success(void) { 
  return 0; 
}

JDLV_Grille creer_grille() {
  JDLV_Grille g;
  int i,j;

  g = JDLV_creerGrille(5,5);
  for(i=1;i<=JDLV_obtenirLargeur(g);i++) 
    for (j=1;j<=JDLV_obtenirHauteur(g);j++) 
      if (JDLV_estCelluleVivante(g,i,j))
	  JDLV_tuerCellule(&g,i,j);

  JDLV_faireNaitreCellule(&g,1,1);
  JDLV_faireNaitreCellule(&g,2,1);
  JDLV_faireNaitreCellule(&g,1,2);
  JDLV_faireNaitreCellule(&g,5,1);
  JDLV_faireNaitreCellule(&g,4,3);
  JDLV_faireNaitreCellule(&g,2,5);
  JDLV_faireNaitreCellule(&g,3,5);
  JDLV_faireNaitreCellule(&g,4,5);
  
  return g;
}


void test_nb_voisins_coin(void){
  JDLV_Grille g = creer_grille();
  CU_ASSERT_TRUE(nbVoisinsVivants(g,1,1)==2);
  JDLV_effacer(&g);
}

void test_nb_voisins_general_morte(void){
  JDLV_Grille g = creer_grille();
  CU_ASSERT_TRUE(nbVoisinsVivants(g,4,4)==3);
  JDLV_effacer(&g);
}

void test_nb_voisins_general_vivante(void){
  JDLV_Grille g = creer_grille();
  CU_ASSERT_TRUE(nbVoisinsVivants(g,3,5)==2);
  JDLV_effacer(&g);
}


int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : nb voisins", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "nb voisins d'une cellule morte", test_nb_voisins_general_morte))
      || (NULL == CU_add_test(pSuite, "nb voisins d'une cellule vivante", test_nb_voisins_general_vivante))
      || (NULL == CU_add_test(pSuite, "nb voisins dans un coin", test_nb_voisins_coin)) 
      ) 
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}


