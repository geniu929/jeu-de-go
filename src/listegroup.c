#include "listegroup.h"


/* maillon position */
maillonGroup_t* maillon_initialiser_g(groupes_t p)
{
  maillonGroup_t* m=(maillonGroup_t *)malloc(sizeof(maillonGroup_t));	
  m->p.pierres= p.pierres;
  m->p.libertes= p.libertes;
  m->suivant=NULL;
  m->precedent = NULL;
	
  return m;
}

void maillon_detruire_g(maillonGroup_t * m)
{
  if (m!=NULL)
    free(m);

}


/*les fonction liste group*/


listeGroup_t* liste_intialiser_g()
{	
  listeGroup_t* res=NULL;
  res=(listeGroup_t*)malloc(sizeof(listeGroup_t));
  res->premier=NULL;
  res->dernier=NULL;
  res->taille =0;
  return res;
}

void liste_ajouter_debut_g(listeGroup_t* l,groupes_t val )
{


   maillonGroup_t *nouv = malloc(sizeof(maillonGroup_t));
   if(!nouv) exit(EXIT_FAILURE);
   nouv->p = val;
   nouv->suivant = l->premier;
   nouv->precedent = NULL;      
   if(l->premier) l->premier->precedent = nouv;
   else l->dernier = nouv;
   l->premier = nouv;



}

void liste_ajouter_fin_g(listeGroup_t* l,groupes_t p)
{
  maillonGroup_t * m=maillon_initialiser_g(p);

  if(l->taille==0)
    {
      l->premier=m;
      l->dernier=m;			
      l->taille++;		
    }
  else
    {
      l->dernier->suivant=m;	
      m->precedent= l->dernier;
      l->dernier=m;
      l->taille++;
    }


}

void liste_detruire_g(listeGroup_t* l)
{
	
  maillonGroup_t * m=NULL;
  if (l!=NULL)
    {
      while(l->taille!=0)
	{
	  m=liste_extraire_deb_g(l);
	  maillon_detruire_g(m);		
	}
      free(l);	
    }	
  l=NULL;


	
}

void afficher_liste_g(listeGroup_t *l)
{
  maillonGroup_t *m= l->premier;
  
      while(m!=NULL)
	{

	  liste_afficher(m->p.libertes);
	  m= m->suivant;	
	}

      
    
 
	
}


void supprimer_maillon(listeGroup_t *l, maillonGroup_t *p)
{
	maillonGroup_t * m = l->premier;
	
	if(l->taille==0)
		printf("la liste est vide! ");

	while(m!=NULL)
	{
		if(p->p.pierres==m->p.pierres && p->p.libertes==m->p.libertes )
		{
		
			if (m->suivant == NULL)
			{
				m->precedent=l->dernier;
				m->suivant=NULL;
			}
			else if (m->precedent == l->premier)
			{
				l->premier=m->suivant;
				m->precedent=NULL;			
			}
			else
			{
				m->precedent->suivant=m->suivant->suivant;				
				m->precedent=m->precedent->precedent;
			}
		}
	m=m->suivant;
	}
}


maillonGroup_t * liste_extraire_deb_g(listeGroup_t * l )
{
  maillonGroup_t * m = NULL;
  m = l->premier;


  if(l->taille==0)
    {

      return NULL;
    }
  else if(l->taille==1)
    {
      l->premier= m;
      l->dernier= m;
      l->taille=0;
    }

  else if(l->taille>1)
    {
      l->premier = m->suivant;
      l->taille--;
    }	
	

  return m;

}
int chercher_liberte_liste(listeGroup_t *l)
{
  maillonGroup_t *m = l->premier;

  /* valeur trouvé renvoi 1*/
  while(m!=NULL)
    {
      
	
	  if(m->p.libertes->val==0)
	    return 1;
				
	 			
	
			
      m=m->suivant;
    }
  /* valaur non trouvé renvoi 0*/
  return 0;
}

void suprime_liberte(listeGroup_t *t,int x, int y)
{
  maillonGroup_t *m = NULL;
  m = t->premier;
	
 
  /* valeur trouvé renvoi 1*/
  while(m!=NULL)
    {
     
	  supprimer_liberte_groupe(&m->p,x,y);
	 			
	
			
      m=m->suivant;
    } 


}

void detruire_groupe_liste(listeGroup_t *l,plateau_t *p)
{
  maillonGroup_t *m = NULL;
  m = l->premier;

  while(m!=NULL)
    {
      if(chercher_liberte_liste(l))
			
	{	
	  liberer_case(p,m->p.pierres);	
	  supprimer_maillon(l,m);
			
		
	}
      m=m->suivant;
    }
}
	
void fusione_groupe_liste(listeGroup_t *l,int x,int y,int x1,int y1)
{
  maillonGroup_t *m = NULL;
  maillon_t *m1=NULL;
  groupes_t *g1=creer_groupe();
  groupes_t *g2=creer_groupe();
  m = l->premier;
  m1=m->p.pierres->debut;
		
  /* valeur trouvé renvoi 1*/
  while(m!=NULL)
    {
      while(m1!=NULL)
	{
	  if(m1->x==x&&m1->y==y)
	    {	
	      g1=&m->p;
	    }
	  else
	    m1=m->p.pierres->debut->suiv;			
	}
							
      m=m->suivant;
    }

  while(m!=NULL)
    {
      while(m1!=NULL)
	{
	  if(m1->x==x1&&m1->y==y1)
	    {	
	      g2=&m->p;
	     
	    }
				
	  m1=m->p.pierres->debut->suiv;			
	}
							
      m=m->suivant;
    }
	
  fusionner_groupes(g1,g2);


}	

/*
  FIN DE LITES
*/
