#ifndef PAYSAGE_H_INCLUDED
#define PAYSAGE_H_INCLUDED
#include "../forme/dessin.h"
#include "../page/plan.h"
#include "../forme/ciel.h"
#include "../graphisme/couleur.h"
#include "../svg/svgfile.h"
#include "../util/util.h"



struct VariablePaysage
{
    int m_densiteOiseau,m_densiteNuage, m_densite1,m_densite2,m_densite3,m_momentJour,m_typePaysage,m_seed;

};

VariablePaysage initVar(int seed,int typePaysage,int densiteOiseau,int densiteNuage,int momentJour,int densite1, int densite2, int densite3,std::mt19937& randGen);



int menu();
int menu2(int& choix,int& choix2);


std::mt19937 modifSeed(int seed);





#endif // PAYSAGE_H_INCLUDED
