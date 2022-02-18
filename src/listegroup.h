/* Fichier listegroup.h */


#ifndef _LISTEGROUP_H
#define _LISTEGROUP_H
#include<stdio.h>
#include<stdlib.h>
#include "liste.h"
#include "plateau.h"
#include "groupes.h"

typedef struct maillonGroup_s{

	groupes_t p;
	struct maillonGroup_s *suivant;
	struct maillonGroup_s *precedent;
}maillonGroup_t;



struct listeGroup_s{
	struct maillonGroup_s *premier;
	struct maillonGroup_s *dernier;
	int taille;
};
typedef struct listeGroup_s listeGroup_t;

/*fonctions maillon*/
maillonGroup_t* maillon_initialiser_g(groupes_t p);
void maillon_detruire_g(maillonGroup_t *m);
void maillon_afficher_g(maillonGroup_t *m); 


/*fonctions liste*/
void supprimer_maillon(listeGroup_t *l, maillonGroup_t *p);
listeGroup_t* liste_intialiser_g();
void liste_ajouter_debut_g(listeGroup_t *l,groupes_t val);
void liste_ajouter_fin_g(listeGroup_t* l,groupes_t p);
void liste_detruire_g(listeGroup_t* l);
void afficher_liste_g(listeGroup_t *l);
int chercher_valeur_liste_g(listeGroup_t *l, int x , int y);
void  supprimer_maillon_g(listeGroup_t *l,maillonGroup_t *p);
maillonGroup_t * liste_extraire_deb_g(listeGroup_t *);
void suprime_liberte(listeGroup_t *t,int x, int y);
int chercher_liberte_liste(listeGroup_t *l);
void detruire_groupe_liste(listeGroup_t *l,plateau_t *p);
void fusione_groupe_liste(listeGroup_t *l,int x,int y,int x1,int y1);

#endif

