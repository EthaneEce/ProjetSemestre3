#ifndef CIEL_H_INCLUDED
#define CIEL_H_INCLUDED
#include "../svg/svgfile.h"
#include "../geometrie/coords.h"
#include "../graphisme/couleur.h"
#include "../util/util.h"
#include "../forme/dessin.h"

class Ciel
{
private :
    double m_x,m_y,m_rx,m_ry;
    Couleur m_colorInt,m_colorExt;
    int m_posSoleil;
    Soleil m_soleil{0,0,Couleur{0,0,0}};
    std::vector<Objet*> m_objects;
    int m_densiteNuage,m_densiteOiseau;

public :
    Ciel(int densiteOiseau, int densiteNuage ,int posSoleil,Svgfile& svgout,std::mt19937& randGen);
    ~Ciel();

    void dessiner(Svgfile& svgout,std::mt19937& randGen);
    int getPosSoleil(){return m_posSoleil;}
};



#endif // CIEL_H_INCLUDED
