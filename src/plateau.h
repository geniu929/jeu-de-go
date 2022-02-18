#ifndef _PLATEAU_H
#define _PLATEAU_H
#include"liste.h"
typedef struct tableau_s
{
  char ** tableau;
  int l;
}plateau_t;



plateau_t * creer_plateau(int l);
void afficher_plateau(plateau_t *p);
void detruir_plateau(plateau_t *p);
char contenu_case (plateau_t *p,int x,int y);
void modifier_contenue_case(plateau_t *p,int x,int y,char c);
void liberer_case(plateau_t *p,liste_t *l);
plateau_t *charger_plateau(char *c);
#endif
