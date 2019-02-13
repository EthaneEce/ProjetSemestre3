#ifndef PLAN_H_INCLUDED
#define PLAN_H_INCLUDED
#include "../forme/dessin.h"
#include "../util/util.h"
#include "../objets/elements.h"
#include "../objets/maison.h"

#include <vector>




class Plan
{
public :
    virtual ~Plan()=default;

    virtual void dessiner(Svgfile& svgout,std::mt19937& rg,int posSoleil)const =0;
};

class PlanMontagne : public Plan
{
protected :
    std::vector<Objet*> m_objects ;
    std::vector<Objet*> m_monts; //On stock chaque mont
    int m_densiteArbre,m_densiteMontagne, m_densiteMaison;
public :
    PlanMontagne(int densiteMontagne,int densiteArbre,int densiteMaison,Svgfile& svgout,std::mt19937& randGen);

    virtual void dessiner(Svgfile& svgout,std::mt19937& rg,int posSoleil)const ;

/*------Get----------*/
    const std::vector<Objet*>& getObj()const {return m_objects;}
    int getDArbre(){return m_densiteArbre;}
    int getDMontagne(){return m_densiteMontagne;}
    int getDMaison(){return m_densiteMaison;}



    ~PlanMontagne();
};



class PlanOcean : public Plan
{
protected :
    std::vector<Objet*> m_objects ;

    int m_densitePoisson,  m_densiteBateau;
public :
    PlanOcean(int densitePoisson,int densiteBateau,Svgfile& svgout,std::mt19937& randGen);

    virtual void dessiner(Svgfile& svgout,std::mt19937& rg,int posSoleil)const ;

/*------Get----------*/
    const std::vector<Objet*>& getObj()const {return m_objects;}
    int getDPoisson(){return m_densitePoisson;}
    int getDBateau(){return m_densiteBateau;}



    ~PlanOcean();
};

class PlanVille : public Plan
{
protected :
    std::vector<Objet*> m_objects ;

    int m_densiteImmeuble,  m_densiteMaison,m_densiteArbre;
public :
    PlanVille(int densiteImmeuble,int densiteMaison,int densiteArbre,Svgfile& svgout,std::mt19937& randGen);

    virtual void dessiner(Svgfile& svgout,std::mt19937& rg,int posSoleil)const ;

/*------Get----------*/
    const std::vector<Objet*>& getObj()const {return m_objects;}
    int getDImmeuble(){return m_densiteImmeuble;}
    int getDMaison(){return m_densiteMaison;}
    int getDArbre(){return m_densiteArbre;}


    ~PlanVille();
};


#endif // PLAN_H_INCLUDED
