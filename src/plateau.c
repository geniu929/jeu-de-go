#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"plateau.h"
#include "liste.h"

/*
Cette fonction alloue l'espace mémoire necessaire pour créer un plateau de taille l*l.
*/


plateau_t * creer_plateau(int l)
{
	int i;
	int j;

	plateau_t * res = (plateau_t *)malloc(sizeof(plateau_t));


	res -> tableau = (char * *)malloc(sizeof(char *)*l);
	for(i = 0; i < (l); i += 1)
		{
			res -> tableau[i] = (char *)malloc(sizeof(char)*l);
		}
	
	res -> l = l;
	
	for(i = 0; i < res ->l; i += 1)
	{
		for(j = 0; j < res ->l; j += 1)
		{
			res -> tableau[i][j] = '.';
		}
	} 
	
	
	
	return res;
}

/*
Cette fonction affiche un plateau p.
Les deux boucles for fixent à chaque fois la ligne et affichent colonne par colonne.
*/

void afficher_plateau(plateau_t * p)
{
	int i;
	int j;
	printf("  ");
	for(j = 0 ; j < p -> l ; j += 1)
	{
	printf(" %2d",j+1);
	}
	printf("\n");
	
	
	for ( i = 0 ; i < p -> l ; i += 1 ) 
	{
	
	printf("%2d  ",i+1);
	
		for ( j = 0 ; j < p -> l ; j += 1 )
		{
			
			printf("%c  ", p -> tableau[i][j]);
			
			
			
		}
		if (j==p->l)
		printf("%2d",i+1);
	printf("\n");
	}
	printf("  ");
	for(j = 0 ; j < p -> l ; j += 1)
	{
	printf(" %2d",j+1);
	}
	printf("\n");
	printf("\n----------------------------------------------------------------\n");
}

/*
Cette fonction renvoie le contenu de la case qui a pour coordonnées (x,y).
*/


char contenu_case(plateau_t * p, int x, int y)
{
	return p -> tableau[x-1][y-1];
}


/*
Cette fonction modifie le contenu de la case de coordonnées (x,y) par un char passé en paramétre.
*/


void modifier_contenue_case(plateau_t *p,int x,int y,char c)
{
	if ((c == 'n')|| (c == 'b') ||( c == '.') )
	p -> tableau[x-1][y-1] = c;
}

/*
Cette fonction prend en entrée une liste l de positions et libére les cases faisant partie de l.
Pour cela elle déclare un maillon m, parcourt toute la liste avec et remplace les cases par des '.' en faisant appel à modifier_contenu_case.
*/

void liberer_case(plateau_t *p, liste_t *l)
{
maillon_t *m = l->debut;

	while(m!=NULL)	
	{
	modifier_contenue_case(p,m->x,m->y,'.');
	m=m->suiv;	
	}

}


/*
Cette fonction prend en entrée un chemin vers un fichier qui contient un plateau déjà crée.
Elle lui charge avec 'fopen' avec des droits r+ (lecture+ecriture) puis affiche la Taille et le nombre des piérres noires et blanches capturées.
Si le chemin donné est invalide, un message d'erreur sera affiché.
*/

plateau_t *charger_plateau(char *c)
{
FILE * f=NULL;

char data[19][19];
int taill;
int i,j;
char e;
plateau_t *p;
int y;
int z;
f=fopen( c,"r");	
	if(f!=NULL)
	{
	fscanf(f,"%d",&taill);
	fscanf(f,"%d",&y);
	fscanf(f,"%d",&z);
	printf("la taille recuperee est %d\n",taill);
	/*fscanf(f,"%d",&parq[1],&parq[2]);*/
	
	p=creer_plateau(taill);
	
	for(i=0;i<taill;i++)
		{
		for (j=0;j<taill;j++)
			{
			
				fscanf(f," %c",&data[i][j]);
				e=data[i][j];
				modifier_contenue_case(p,i,j,e);
			
			}
		}

	return p;

fclose(f);
 	}
  else
	{
	return NULL;	
	}
}

/*
Cette fonction libére l'espace mémoire alloué precedamment et donc détruit le plateau.
*/


void detruir_plateau(plateau_t *p)
{

free(p);
}


