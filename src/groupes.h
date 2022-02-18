/* Fichier groupes.h */


#ifndef _GROUPES_H
#define _GROUPES_H
#include"liste.h"

struct groupes_s
{
	liste_t *pierres;
	liste_t *libertes;
};
typedef struct groupes_s groupes_t;

/* Les fonctions associées */

groupes_t *creer_groupe();
void ajouter_pierre_groupe(groupes_t *g,int x,int y);
void ajouter_liberte_groupe(groupes_t *g,int x,int y);
groupes_t *supprimer_liberte_groupe(groupes_t *g,int x,int y);
void detruire_groupe(groupes_t *g);
void fusionner_groupes(groupes_t *g1,groupes_t *g2);
int est_mort(groupes_t g);
void afficher_groupe(groupes_t *g);

#endif
