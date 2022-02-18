/* Fichier liste.h */


#ifndef _LISTE_H
#define _LISTE_H
#include<stdio.h>
#include<stdlib.h>

/* Definition de la structure maillon_t */

struct maillon_s
{
	int x;
	int y;
	struct maillon_s *suiv;
};
typedef struct maillon_s maillon_t;

/* Definition de la structure liste_t*/

struct liste_s
{
	maillon_t *debut;
	maillon_t *fin;
	int val;
};
typedef struct liste_s liste_t;

/* Les fonctions associées */

liste_t *liste_initialiser();
int liste_vide(liste_t *l);
int liste_cardinal(liste_t *l);
void liste_ajouter_debut(liste_t *l,int x,int y);
void liste_ajouter_fin(liste_t *l,int x,int y);
void liste_detruire_liste(liste_t *l);
void liste_afficher(liste_t *l);
maillon_t *liste_extrair_debut(liste_t *l);
void extrair_debut(liste_t *l);
void maillon_afficher(maillon_t* m);
maillon_t *creer_maillon(int x,int y);
void detruire_maillon(maillon_t *m);

#endif

