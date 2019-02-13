#ifndef ELEMENTS_H_INCLUDED
#define ELEMENTS_H_INCLUDED

#include "../forme/dessin.h"

class Poisson : public Objet
{
    public :
    Poisson (double x,double y,double tailleH=30,double tailleV=60,int pos=3);
    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;

    virtual void ombrer(Svgfile& svgout, int posSoleil)const;
};





class Nuage : public Objet
{
    public :
    Nuage (double x,double y,double tailleH=30,double tailleV=60,int pos=3);
    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;
    virtual void ombrer(Svgfile& svgout, int posSoleil)const;
};





class Etoile : public Objet
{

public :
    Etoile (double x,double y,double tailleH=60,double tailleV=60,int pos=3);
    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;

    virtual void ombrer(Svgfile& svgout, int posSoleil)const;
};






class Bateau : public Objet
{

public :
    Bateau (double x,double y,double tailleH=100,double tailleV=50,int pos=3);
    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;

    virtual void ombrer(Svgfile& svgout, int posSoleil)const;
};





class Oiseau : public Objet
{

public :
    Oiseau (double x,double y,double tailleH=60,double tailleV=30,int pos=3);
    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;

    virtual void ombrer(Svgfile& svgout, int posSoleil)const;
};

#endif // ELEMENTS_H_INCLUDED
