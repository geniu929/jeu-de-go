#include <stdlib.h>
#include <stdio.h>
#include "plateau.h"
#include <string.h>
#include "liste.h"
#include "groupes.h"
#include "partie.h"
#include "listegroup.h"

int main()
{

	partie_t *p=malloc(sizeof(partie_t));
	int tour=1, x=1,y=1,c=5,s;


	
	printf("BIENVENUE DANS LE JEU DE GO \n");
	printf("Choisissez la taille du plateau ! \n");
	printf("Pour un petit plateau tapez 1 \n");
	printf("Pour un plateau moyen tapez 2 \n");
	printf("Pour un grand plateau tapez 3 \n");
	scanf("%d",&c);

	/* Ici on définit la taille du plateau suivant la valeur c */
	
		if (c==1)
			s=9;
		else if (c==2)
			s=13;	
		else if (c==3)
			s=19;
	
	/* Initialistation du plateau et définition des différentes variables */

	p->plat=creer_plateau(s);
	p->taille=s;
	p->l=liste_intialiser_g();
	p->jnoir=0;
	p->jblanche=0;	
	afficher_plateau(p->plat);

	/* Ici on commence à jouer */

	while(tour==1||tour==2)
		if(tour==1)
		{
			printf("Joueur1 (pierres noires) : à vous de jouer! \n");
			printf("Où voulez vous poser votre pierre  ?\n");
			scanf("%d",&x);
			scanf("%d",&y);
			jouer_coup(p,x,y,'n');
			afficher_plateau(p->plat);
			afficher_liste_g(p->l);
			tour++;
		} 
		else if (tour==2)
		{
			afficher_plateau(p->plat);
			printf("Joueur2 (pierres blanches) : à vous de jouer! \n");
			printf("Où voulez vous poser votre pierre  ?\n");
			scanf("%d",&x);
			scanf("%d",&y);
			jouer_coup(p,x,y,'b');
			afficher_plateau(p->plat);
			afficher_liste_g(p->l);
			tour--;
		}
	
 

	detruire_partie(p);
	return EXIT_SUCCESS;
}
