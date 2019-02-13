#include "paysage.h"


VariablePaysage initVar(int seed,int typePaysage,int densiteOiseau,int densiteNuage,int momentJour,int densite1, int densite2, int densite3,std::mt19937& randGen)
{
    VariablePaysage varNouv;
     varNouv.m_seed=seed;

    if(densiteOiseau!=9)
        varNouv.m_densiteOiseau=densiteOiseau;
    else
        varNouv.m_densiteOiseau=util::alea(0,3,randGen);

    if(densiteNuage!=9)
        varNouv.m_densiteNuage=densiteNuage;
    else
        varNouv.m_densiteNuage=util::alea(0,3,randGen);

    if(densite1!=9)
        varNouv.m_densite1=densite1;
    else
        varNouv.m_densite1=util::alea(1,3,randGen);

    if(densite2!=9)
        varNouv.m_densite2=densite2;
    else
        varNouv.m_densite2=util::alea(0,3,randGen);

    if(densite3!=9)
        varNouv.m_densite3=densite3;
    else
        varNouv.m_densite3=util::alea(0,3,randGen);

    if(momentJour==9)
        varNouv.m_momentJour=util::alea(1,4,randGen);
    else
        varNouv.m_momentJour=momentJour;

    if(typePaysage==9)
        varNouv.m_typePaysage=util::alea(1,3,randGen);
    else
        varNouv.m_typePaysage=typePaysage;

    return varNouv;
}

int menu()
{
    int choix;
    system("cls");
            std::cout<< "Que voulez-vous faire ? :"<<std::endl
                    << "0 : Quitter" <<std::endl
                    << "1 : Creer un paysage random" <<std::endl
                    << "2 : Afficher un paysage a partir d'une graine" <<std::endl
                    << "3 : Modifier le paysage actuel" <<std::endl
                    << "4 : Sauvegarder le paysage actuel et quitter" <<std::endl
                    << "5 : Restaurer une sauvegarde" <<std::endl<<std::endl
                    << "Choix : " <<std::endl;
            std::cin>>choix;
            std::cout<<std::endl;
            return choix;
}

int menu2(int& choix,int& choix2)
{
    std::cout<<"Que voulez vous modifier ?"<<std::endl
            <<"1 : densite1"<<std::endl
            <<"2 : densite2"<<std::endl
            <<"3 : densite3"<<std::endl
            <<"4 : densiteOiseau"<<std::endl
            <<"5 : densiteNuage"<<std::endl
            <<"6 : Le moment de la journée"<<std::endl;
    std::cin>>choix;

    std::cout<<"Par quelle valeur voulez vous la modifier"<<std::endl;
    std::cin>>choix2;

}


std::mt19937 modifSeed(int seed)
{
    std::mt19937 rgnouv {seed};
    return rgnouv;
}



