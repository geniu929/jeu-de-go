/* Fichier partie.h */


#ifndef _PARTIE_H
#define _PARTIE_H
typedef struct listeGroup_s listeGroup_t;
typedef struct tableau_s plateau_t;
struct partie_s
{
plateau_t *plat;
listeGroup_t *l;
int jnoir;
int jblanche;
int taille;
};
typedef struct partie_s partie_t;

/* Fonctions associées */

partie_t *nouvelle_partie(char *c);
void detruire_partie(partie_t *p);
int coup_autorise(partie_t *p, int x, int y);
int jouer_coup(partie_t *p, int x,int y,char c);
#endif
