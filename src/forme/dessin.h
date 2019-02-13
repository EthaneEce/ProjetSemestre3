#ifndef DESSIN_H_INCLUDED
#define DESSIN_H_INCLUDED
#include <iostream>
#include <random>
#include "../graphisme/couleur.h"
#include "../svg/svgfile.h"
#include "../util/util.h"
#include "../geometrie/coords.h"


class Objet
{
protected :
    Coords m_co;
    double m_couleurRand;
    double m_tH, m_tV;
    bool ombrable;
    int m_pos;
public :
    virtual ~Objet()= default;

    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const =0;

    virtual void ombrer(Svgfile& svgout, int posSoleil) const=0;
    /*------Get----------*/
    virtual Coords getCo() const  {return m_co;};
    virtual bool getOm()const {return ombrable;};
    virtual double getTH()const {return m_tH;};
    virtual double getTV()const {return m_tV;};
    virtual double getPos()const {return m_pos;};


    /*-------------------*/

};

class Sapin : public Objet
{
protected:
    bool m_neige;
public :
    Sapin (std::mt19937& randGen,double x,double y,double tailleH=60,double tailleV=60,int pos=util::alea(1,3),bool neige=true);
    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;


    virtual void ombrer(Svgfile& svgout, int posSoleil)const;
};

class Mont : public Objet
{
protected :
    Couleur m_c;

public :
    Mont (std::mt19937& randGen,double x,double y,double tailleH=600,double tailleV=600,int pos=util::alea(1,3),Couleur oue=Couleur{40,40,40});


    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;
    void setColor(Couleur c);

    virtual void ombrer(Svgfile& svgout, int posSoleil)const;
};

class Soleil : public Objet
{
protected :
    Couleur m_color;

public :
    Soleil(double x,double y,Couleur color,double tailleH=30,double tailleV=60);
    virtual void dessiner(Svgfile& svgout,std::mt19937& randGen) const;
    virtual void ombrer(Svgfile& svgout, int posSoleil)const;



};



#endif // DESSIN_H_INCLUDED
