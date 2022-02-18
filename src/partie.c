#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partie.h"
#include "plateau.h"
#include "groupes.h"
#include"listegroup.h"

/*
Cette fonction crée une nouvelle partie en chargeant un plateau.
Si le chemin c passé en paramétre est vide, un nouveau plateau sera crée en utilisant la fonction creer_plateau (la taille est choisie par l'utilisateur).
Sinon, le plateau sera chargé avec la fonction fopen avec le droit 'r+'.
*/

partie_t *nouvelle_partie(char *c)
{
	
FILE * f=NULL;
int taill;
int pblanche;
int pnoir;


partie_t *p= (partie_t*)malloc(sizeof(partie_t));


	if((f=fopen( c,"r"))!=NULL)
	{
	
	fscanf(f,"%d",&taill);
	fscanf(f,"%d",&pblanche);
	p->jnoir=pblanche; 
	fscanf(f,"%d",&pnoir);
	p->jblanche=pnoir;	
	return p;

fclose(f);
 	}
  else
	{
	p->jnoir=0;
	p->jblanche=0;
	return p;	
	}
  free(p);  
}
/*
Cette fonction detruit une partie en libérant l'espace mémoire de son plateau.
Le nombre des piérres blanches noires sera, donc, remis à zéro.
*/

void detruire_partie(partie_t *p)
{
	detruir_plateau(p->plat);
	p->jnoir=0;
	p->jblanche=0;
}

/*
Cette fonction teste si le coup désiré par un joueur est autorisé ou pas.
Elle teste si à la position (x,y) se trouve '.' ET à l'une des positions qui entourent (x,y) se trouve aussi '.'.
Si ces deux conditions sont vérifées, le coup sera autorisé.
*/

int coup_autorise(partie_t *p, int x, int y)
{
	if ((x>=1 && y>=1)&&(x<=p->taille&&y<=p->taille))
	{
		
		
		if(x==1&&y==1&&p->plat->tableau[0][0]=='.' && (p->plat->tableau[x][y-1]=='.' || p->plat->tableau[x-1][y]=='.'))
			return 1;
			
		else if(x==p->taille&&y==p->taille&&p->plat->tableau[p->taille-1][p->taille-1]=='.' && (p->plat->tableau[x-2][y-1]=='.'|| p->plat->tableau[x-1][y-2]=='.'))
			return 1;
			
		else if(x==1&&y==p->taille&&p->plat->tableau[0][p->taille-1]=='.' && (p->plat->tableau[x-1][y-2]=='.'||p->plat->tableau[x][y-1]=='.'))
			return 1;
			
		else if(x==p->taille&&y==1&&p->plat->tableau[p->taille-1][y-1]=='.' &&( p->plat->tableau[x-2][y-1]=='.'|| p->plat->tableau[x-1][y]=='.'))
			return 1;
			
		else if (1 < x && x < p -> taille && 1 < y&&y < p -> taille && p->plat->tableau[x-1][y-1]=='.' && (p->plat->tableau[x-2][y-1]=='.' || p->plat->tableau[x-1][y-2]=='.' || p->plat->tableau[x][y-1]=='.'|| p->plat->tableau[x-1][y]=='.'))
			return 1;
			
		else if (x>1 && x < p -> taille && y==1 && p->plat->tableau[x-1][y-1]=='.' && (contenu_case(p->plat,x-1,y)=='.' || contenu_case(p->plat,x+1,y)=='.' || contenu_case(p->plat,x,y+1)=='.'))
			return 1;
			
		else if(1 < y&&y < p -> taille && x==1 && p->plat->tableau[x-1][y-1]=='.' && (p->plat->tableau[x-1][y-2]=='.' || p->plat->tableau[x-1][y]=='.' || p->plat->tableau[x][y-1]=='.'))
			return 1;
			
		else if(x == p -> taille && 1 < y&&y < p -> taille && p->plat->tableau[p -> taille-1][y-1]=='.' && (p->plat->tableau[x-2][y-1]=='.' || p->plat->tableau[x-1][y-2]=='.' || p->plat->tableau[x-1][y]=='.'))
			return 1;
			
		else if(1 < x&&x < p -> taille && y==p -> taille && p->plat->tableau[x-1][y-1]=='.' && (p->plat->tableau[x][y-1]=='.' || p->plat->tableau[x-2][y-1]=='.' || p->plat->tableau[x-1][y-2]=='.'))
			return 1;
	}
	else

return 0;	
} 

/*
Cette fonction modifie le plateau comme désire l'utilisateur si son coup est autorisé.
Si coup_autorise retourne 1, modifier_contenue_case sera appliquée sur la case (x,y) pouur poser la pierre 'c'.

*/


int jouer_coup(partie_t * p, int x,int y,char c)
{

  groupes_t *g=malloc(sizeof(groupes_t));
	if (coup_autorise(p,x,y)==1)
		{
		
		g=creer_groupe();
		ajouter_pierre_groupe(g,x,y);
		modifier_contenue_case(p->plat,x,y,c);	
			
			if (x==1&&y==1)
				
				{
				
				if('.'==contenu_case(p->plat,x+1,y))
					ajouter_liberte_groupe(g,x+1,y);
					
				if('.'==contenu_case(p->plat,x,y+1))
					ajouter_liberte_groupe(g,x,y+1);
						    
				}
			else if(x==1&&y==p->taille)
				{
				if('.'==contenu_case(p->plat,x+1,y))
					ajouter_liberte_groupe(g,x+1,y);
				if('.'==contenu_case(p->plat,x,y-1))
					ajouter_liberte_groupe(g,x,y-1);
							
				}
			else if(x==p->taille&&y==1)
				{
				if('.'==contenu_case(p->plat,x,y+1))
					ajouter_liberte_groupe(g,x,y+1);
				if('.'==contenu_case(p->plat,x-1,y))
					ajouter_liberte_groupe(g,x-1,y);
						
				}
			else if(x==p->taille&&y==p->taille)

				{
				if('.'==contenu_case(p->plat,x,y-1))
					ajouter_liberte_groupe(g,x,y-1);
				if('.'==contenu_case(p->plat,x-1,y))
					ajouter_liberte_groupe(g,x-1,y);		
				}
			else if(x==p->taille&&y>1&&y<p->taille)
				{
				if('.'==contenu_case(p->plat,x-1,y))
					ajouter_liberte_groupe(g,x-1,y);
				if('.'==contenu_case(p->plat,x,y+1))
					ajouter_liberte_groupe(g,x,y+1);
				if('.'==contenu_case(p->plat,x,y-1))
					ajouter_liberte_groupe(g,x,y-1);
				}
			else if(x==1&&y>1&&y<p->taille)
				{
				if('.'==contenu_case(p->plat,x+1,y))
					ajouter_liberte_groupe(g,x+1,y);
				if('.'==contenu_case(p->plat,x,y+1))
					ajouter_liberte_groupe(g,x,y+1);
				if('.'==contenu_case(p->plat,x,y-1))
					ajouter_liberte_groupe(g,x,y-1);

				}
			else
			{
			if('.'==contenu_case(p->plat,x+1,y))
					ajouter_liberte_groupe(g,x+1,y);
			if('.'==contenu_case(p->plat,x,y+1))
					ajouter_liberte_groupe(g,x,y+1);
			if('.'==contenu_case(p->plat,x-1,y))
					ajouter_liberte_groupe(g,x-1,y);
			if('.'==contenu_case(p->plat,x,y-1))
					ajouter_liberte_groupe(g,x,y-1);
			}

		
				
			liste_ajouter_debut_g(p->l,*g );
			
			suprime_liberte(p->l,x,y);
			afficher_groupe(g);
	
			

			
			if (x==1&&y==1)
				
				{
				
				if(c==contenu_case(p->plat,x+1,y))
					fusione_groupe_liste(p->l,x,y,x+1,y);
					
				if(c==contenu_case(p->plat,x,y+1))
					fusione_groupe_liste(p->l,x,y,x,y+1);
						    
				}
			else if(x==1&&y==p->taille)
				{
				if(c==contenu_case(p->plat,x+1,y))
					fusione_groupe_liste(p->l,x,y,x+1,y);
				if(c==contenu_case(p->plat,x,y-1))
					fusione_groupe_liste(p->l,x,y,x,y-1);
							
				}
			else if(x==p->taille&&y==1)
				{
				if(c==contenu_case(p->plat,x,y+1))
					fusione_groupe_liste(p->l,x,y,x,y+1);
				if(c==contenu_case(p->plat,x-1,y))
					fusione_groupe_liste(p->l,x,y,x-1,y);
						
				}
			else if(x==p->taille&&y==p->taille)

				{
				if(c==contenu_case(p->plat,x,y-1))
					fusione_groupe_liste(p->l,x,y,x,y-1);
				if(c==contenu_case(p->plat,x-1,y))
					fusione_groupe_liste(p->l,x,y,x-1,y);		
				}
			else if(x==p->taille&&y>1&&y<p->taille)
				{
				if(c==contenu_case(p->plat,x-1,y))
					fusione_groupe_liste(p->l,x,y,x-1,y);
				if(c==contenu_case(p->plat,x,y+1))
					fusione_groupe_liste(p->l,x,y,x,y+1);
				if(c==contenu_case(p->plat,x,y-1))
					fusione_groupe_liste(p->l,x,y,x,y-1);
				}
			else if(x==1&&y>1&&y<p->taille)
				{
				if(c==contenu_case(p->plat,x+1,y))
					fusione_groupe_liste(p->l,x,y,x+1,y);
				if(c==contenu_case(p->plat,x,y+1))
					fusione_groupe_liste(p->l,x,y,x,y+1);
				if(c==contenu_case(p->plat,x,y-1))
					fusione_groupe_liste(p->l,x,y,x,y-1);

				}
			else
			{
			if(c==contenu_case(p->plat,x+1,y))
					fusione_groupe_liste(p->l,x,y,x+1,y);
			if(c==contenu_case(p->plat,x,y+1))
					fusione_groupe_liste(p->l,x,y,x,y+1);
			if(c==contenu_case(p->plat,x-1,y))
					fusione_groupe_liste(p->l,x,y,x-1,y);
			if(c==contenu_case(p->plat,x,y-1))
					fusione_groupe_liste(p->l,x,y,x,y-1);
			}

			
			detruire_groupe_liste(p->l,p->plat);
			
		return 1;
		
		
			}
			
	
	return 0;	


}



















