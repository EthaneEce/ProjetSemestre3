#ifndef MAISON_H_INCLUDED
#define MAISON_H_INCLUDED
#include "../forme/dessin.h"
class Maison : public Objet
{

public :
    Maison (std::mt19937& randGen,double x,double y,double tailleH=60,double tailleV=0,int pos=3);
    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;

   virtual void ombrer(Svgfile& svgout, int posSoleil)const;
};


class Immeuble : public Objet
{

public :
    Immeuble (std::mt19937& randGen,double x,double y,double tailleH=50,double tailleV=100,int pos=3);
    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;

    virtual void ombrer(Svgfile& svgout, int posSoleil)const;
};

class Herbe : public Objet
{

public :
    Herbe (std::mt19937& randGen,double x,double y,double tailleH=50,double tailleV=100,int pos=3);
    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;

   virtual void ombrer(Svgfile& svgout, int posSoleil)const;
};

#endif // MAISON_H_INCLUDED
