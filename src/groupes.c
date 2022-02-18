/* Fichier groupes.c */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "groupes.h"

/*
Cette fonction crée un groupe.
elle alloue l'espace mémoire nécessaire puis initialise ses deux listes en faisant appel à liste_initialiser.
*/

groupes_t *creer_groupe()
{
groupes_t *g=(groupes_t*)malloc(sizeof(groupes_t));

g->pierres=liste_initialiser();
g->libertes=liste_initialiser();

return g;

}

/*
Cette fonction ajoute une pierre à la position (x,y) à la liste des pierres d'un groupe en appelant liste_ajouter_fin.
*/

void ajouter_pierre_groupe(groupes_t *g,int x,int y)
{
    liste_ajouter_fin(g->pierres,x,y);
}

/*
Cette fonction ajoute une liberté à la position (x,y) à la liste des libértés d'un groupe en appelant liste_ajouter_fin.
*/

void ajouter_liberte_groupe(groupes_t *g,int x,int y)
{
    liste_ajouter_fin(g->libertes,x,y);
}

/*

Cette fonction supprime une liberté de la liste des libértés d'un groupe.
*/

groupes_t *supprimer_liberte_groupe(groupes_t *g,int x,int y)
{
maillon_t *iterateur=malloc(sizeof(maillon_t));
iterateur=g->libertes->debut ; 

if(g->libertes == NULL)
	return NULL; 
else if (g->libertes->debut->x == x && g->libertes->debut->y == y)
	{ 
	extrair_debut(g->libertes);	
	
	} 	
while(iterateur->suiv!= NULL)	
	{ 
	printf("\n");
	if(x ==iterateur->suiv->x && y==iterateur->suiv->y)	
	{	

		iterateur->suiv = iterateur->suiv->suiv;	
 		g->libertes->val --;
		
	} 
	else 
	{    
      		iterateur= iterateur->suiv;
	}   	
      	}    
return g;
free (iterateur);	
}


/*
Cette fonction détruit les deux listes qui forment un groupe en faisant appel à liste_detruire_liste.
*/

void detruire_groupe(groupes_t *g)
{

	liste_detruire_liste(g->libertes);
	liste_detruire_liste(g->pierres);

}

/*
Cette fonction ajoute les élements d'un groupe g1 à un deuxiéme groupe g2.
*/

void fusionner_groupes(groupes_t *g1,groupes_t *g2)
{

if((g1->pierres->val==0||g1->libertes->val==0)||(g2->pierres->val==0||g2->libertes->val==0))
	{

	if(g1->pierres->val!=0&&g1->libertes->val!=0&&(g2->pierres->val==0||g2->libertes->val==0||g2->pierres->val==0||g2->libertes->val==0))
		{
		g1->pierres->fin->suiv=g2->pierres->debut;
		g1->libertes->fin->suiv=g2->libertes->debut;
		}
	else if(g1->pierres->val!=0&&g1->libertes->val==0&&(g2->pierres->val!=0||g2->libertes->val!=0||g2->pierres->val==0||g2->libertes->val==0))
		{
		g1->pierres->fin->suiv=g2->pierres->debut;
		g1->libertes->debut=g2->libertes->debut;
		}

	else if(g1->pierres->val==0&&g1->libertes->val!=0&&(g2->pierres->val!=0||g2->libertes->val!=0||g2->pierres->val==0||g2->libertes->val==0))
		{
		g1->pierres->debut=g2->pierres->debut;
		g1->libertes->fin->suiv=g2->libertes->debut;
		}
	else if(g1->pierres->val==0&&g1->libertes->val==0&&(g2->pierres->val!=0||g2->libertes->val!=0||g2->pierres->val==0||g2->libertes->val==0))
		{
		g1->pierres->debut=g2->pierres->debut;
		g1->libertes->debut=g2->libertes->debut;
		}


	g1->pierres->fin=g2->pierres->fin;
	g1->pierres->val+=g2->pierres->val;
	g1->libertes->fin=g2->libertes->fin;
	g1->libertes->val+=g2->libertes->val;
	}
else
	{

	g1->pierres->fin->suiv=g2->pierres->debut;
	g1->libertes->fin->suiv=g2->libertes->debut;
	g1->pierres->fin=g2->pierres->fin;
	g1->pierres->val+=g2->pierres->val;
	g1->libertes->fin=g2->libertes->fin;
	g1->libertes->val+=g2->libertes->val;
	}


}

/*
Cette fonction affiche les deux listes d'un groupe en faisant appel à liste_afficher.
*/

void afficher_groupe(groupes_t *g)
{
	liste_afficher(g->libertes);
	liste_afficher(g->pierres);
}

/*
Cette fonction vérifie si un groupe g a encore des libértés ou pas.
Pour cela on applique liste_vide sur la liste des libértés de g.
*/

int est_mort(groupes_t g)
{
    return liste_vide(g.libertes);
}
