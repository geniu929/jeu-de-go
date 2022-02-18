/* Fichier liste.c */


#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

/*
Cette fonction crée un maillon qui servira aprés à parcourir la liste.
les champs x et y représentent les coordonnées d'une case.
le pointeur suiv indique le maillon suivant.
*/

maillon_t *creer_maillon(int x,int y)
{
	maillon_t *m = (maillon_t*)malloc(sizeof
(maillon_t));
	m -> x = x;
	m -> y = y;
	m -> suiv = NULL;
return m;
}

/*
Cette fonction détruit un maillon en libérant son espace mémoire.
*/

void detruire_maillon(maillon_t *m)
{
	free(m);
}

/*
Cette fonction initialise une liste.
les champs début et fin représentent le premier et dernier élements de la liste.
Le champ val représente le nombre de maillon que contient la liste
*/

liste_t *liste_initialiser()
{
	liste_t *l=(liste_t*)malloc(sizeof(liste_t));
	l -> debut = NULL;
	l -> fin = NULL;
	l -> val = 0;
	return l;

}

/*
Cette fonction nous indique si une liste est vide ou pas en vérifiant la valeur de 'val'.
*/

int liste_vide(liste_t *l)
{
	if(l -> val == 0)
		{
		return 1;
		}
	else
		return 0;

}

/*
Cette fonction retourne le cardinal d'une liste.
*/

int liste_cardinal(liste_t *l)
{
	return l->val;
}

/*
Cette fonction ajoute un maillon m au début d'une liste l.
Si l est vide, m sera le début ET la fin de la liste.
Sinon, le suivant de m sera l'ancien premier élement de l.
*/

void liste_ajouter_debut(liste_t *l,int x,int y)
{
	maillon_t *m = creer_maillon(x,y);
	if(l -> val == 0)
		{
		l -> debut = m;
		l -> fin = m;
		}
	else
		{
		m -> suiv = l -> debut;
		l -> debut = m;
		}
	l -> val++;
}

/*
Cette fonction ajoute un maillon m à la fin de la liste l.
Si l est vide, m sera le début ET la fin de l.
Sinon, le précédent de m sera l'ancien dernier élement de l.
*/

void liste_ajouter_fin(liste_t *l,int x,int y)
{
	maillon_t *m = creer_maillon(x,y);
	if(l -> val == 0)
		{
		l -> debut = m;
		l -> fin = m;
		}
	else
		{
		l -> fin -> suiv = m;
		l -> fin = m;
		}
	l -> val++;
}

/*
Cette fonction vérifie si la liste est vide ou pas en faisant appel à liste_vide.
si elle ne l'est pas, la fonction  détruira son premier maillon avec les deux fonction liste_extrair_début et detruire_maillon.
Enfin elle libére l'espace mémoire que occupait la liste.
*/

void liste_detruire_liste(liste_t *l)
{
	while(liste_vide(l)==0)
		{
		detruire_maillon(liste_extrair_debut(l));
		}

	free(l);
}

/*
Cette fonction retourne le premier maillon d'une liste l.
Si l est vide, on aura rien en sortie.
Sinon, le nouveau premier élement de l sera l'ancien deuxiéme et il faudra dérementer le cardinal de l.
*/

maillon_t *liste_extrair_debut(liste_t *l)
{
	maillon_t *res = l -> debut;
	if(liste_vide(l)==0)
		{
            l -> debut = l -> debut -> suiv;
            l -> val--;
		}
	else
		{
            l -> debut = NULL;
            l -> fin = NULL;
            l -> val = 0;
		}
	return res;

}

/*
Cette fonction supprime le premier maillon de la liste sans le retourner.
Le principe est le méme que celui de liste_extrair_debut.
*/

void extrair_debut(liste_t *l)
{

	if(liste_vide(l)==0)
		{
            l -> debut = l -> debut -> suiv;
            l -> val--;
		}
	else
		{
            l -> debut = NULL;
            l -> fin = NULL;
            l -> val = 0;
		}
}

/*
Cette fonction parcourt une liste maillon par maillon et les affiche tous en faisant appel à maillon_afficher.
Si la liste est vide, on aura un message d'erreur.
*/

void liste_afficher(liste_t *l)
{

maillon_t *m= l->debut;

if(m!=NULL)
	{
	while(m!=NULL)
		{
		maillon_afficher(m);
		m= m->suiv;
		}

	printf("   la taiille =%d ",l->val);
	}
else

	printf("ERREUR\n");
printf("\n");
}

/*
Cette fonction affiche les coordonnées que comporte un maillon m passé en paramétre.
Si ce maillon est vide, un mesage d'erreur sera affiché.
*/

void maillon_afficher(maillon_t* m)
{

	if (m!=NULL)
		{
            printf("x=%d, y=%d ",m->x,m->y);
            
		}
	else
            printf("ERREUR \n");
printf("\n");
}
