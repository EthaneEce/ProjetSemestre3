#include "geometrie/transformation.h"
#include "graphisme/couleur.h"
#include "svg/svgfile.h"
#include "util/util.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "forme/dessin.h"
#include "page/plan.h"
#include "forme/ciel.h"
#include "paysage/paysage.h"





int main()
{
    int choix;
    int seed;
    int choix2, nbmodif;






    VariablePaysage varNouv;


    std::mt19937 rg1{10};

///menu fonctionnel si pas de bug lors du bouclage
    do
    {

        choix=menu();

        if(choix==1)
        {
            Svgfile svgout;
            seed=util::alea(1,300);
            rg1=modifSeed(seed);

            varNouv = initVar(seed,9,9,9,9,9,9,9,rg1);

            Ciel c{varNouv.m_densiteOiseau,varNouv.m_densiteNuage,varNouv.m_momentJour,svgout,rg1};

            if(varNouv.m_typePaysage==1)
            {
                c.dessiner(svgout,rg1);
                PlanMontagne p{varNouv.m_densite1,varNouv.m_densite2,varNouv.m_densite3,svgout,rg1};
                p.dessiner(svgout,rg1,c.getPosSoleil());
            }

            if(varNouv.m_typePaysage==2)
            {
                c.dessiner(svgout,rg1);
                PlanVille p{varNouv.m_densite1,varNouv.m_densite2,varNouv.m_densite3,svgout,rg1};
                p.dessiner(svgout,rg1,c.getPosSoleil());
            }
            if(varNouv.m_typePaysage==3)
            {
                c.dessiner(svgout,rg1);
                PlanOcean p{varNouv.m_densite1,varNouv.m_densite2,svgout,rg1};
                p.dessiner(svgout,rg1,c.getPosSoleil());
            }


            std::cout<<"Plan : "<<varNouv.m_typePaysage<<std::endl;
            std::cout<<"Seed : "<<seed<<std::endl;
            system("pause");
        }

///-------------------------------------------------------------------------------------///

        if(choix==2)
        {
            Svgfile svgout;
            std::cout<<"Seed : "<<std::endl;
            std::cin>>seed;
            std::cout<<std::endl;

            rg1=modifSeed(seed);
            varNouv = initVar(seed,9,9,9,9,9,9,9,rg1);
            std::cout<<"oue"<<std::endl;
            Ciel c{varNouv.m_densiteOiseau,varNouv.m_densiteNuage,varNouv.m_momentJour,svgout,rg1};

            if(varNouv.m_typePaysage==1)
            {
                c.dessiner(svgout,rg1);
                PlanMontagne p{varNouv.m_densite1,varNouv.m_densite2,varNouv.m_densite3,svgout,rg1};
                p.dessiner(svgout,rg1,c.getPosSoleil());
            }

            if(varNouv.m_typePaysage==2)
            {
                c.dessiner(svgout,rg1);
                PlanVille p{varNouv.m_densite1,varNouv.m_densite2,varNouv.m_densite3,svgout,rg1};
                p.dessiner(svgout,rg1,c.getPosSoleil());
            }
            if(varNouv.m_typePaysage==3)
            {
                c.dessiner(svgout,rg1);
                PlanOcean p{varNouv.m_densite1,varNouv.m_densite2,svgout,rg1};
                p.dessiner(svgout,rg1,c.getPosSoleil());
            }

        }

        if(choix==3)
        {
            Svgfile svgout;
            menu2(choix2,nbmodif);
            if(choix2==1)
                varNouv.m_densite1=nbmodif;
            if(choix2==2)
                varNouv.m_densite2=nbmodif;
            if(choix2==3)
                varNouv.m_densite3=nbmodif;
            if(choix2==4)
                varNouv.m_densiteOiseau=nbmodif;
            if(choix2==5)
                varNouv.m_densiteNuage=nbmodif;
            if(choix2==6)
                varNouv.m_momentJour=nbmodif;

            Ciel c{varNouv.m_densiteOiseau,varNouv.m_densiteNuage,varNouv.m_momentJour,svgout,rg1};

            if(varNouv.m_typePaysage==1)
            {
                c.dessiner(svgout,rg1);
                PlanMontagne p{varNouv.m_densite1,varNouv.m_densite2,varNouv.m_densite3,svgout,rg1};
                p.dessiner(svgout,rg1,c.getPosSoleil());
            }

            if(varNouv.m_typePaysage==2)
            {
                c.dessiner(svgout,rg1);
                PlanVille p{varNouv.m_densite1,varNouv.m_densite2,varNouv.m_densite3,svgout,rg1};
                p.dessiner(svgout,rg1,c.getPosSoleil());
            }
            if(varNouv.m_typePaysage==3)
            {
                c.dessiner(svgout,rg1);
                PlanOcean p{varNouv.m_densite1,varNouv.m_densite2,svgout,rg1};
                p.dessiner(svgout,rg1,c.getPosSoleil());
            }

        }
        if(choix==4)
        {
            std::ofstream ofs{"save.txt"};
            if (!ofs)
                std::cerr << "Can't write/open save.txt\n";
            else
            {
                ofs << varNouv.m_seed << std::endl
                    << varNouv.m_momentJour << std::endl
                    << varNouv.m_typePaysage << std::endl
                    << varNouv.m_densite1 << std::endl
                    << varNouv.m_densite2 << std::endl
                    << varNouv.m_densite3 << std::endl
                    << varNouv.m_densiteNuage << std::endl
                    << varNouv.m_densiteOiseau << std::endl;
                ofs.close();
            }
            return 0;
        }
        if(choix==5)
        {
            Svgfile svgout;
            bool myVecLoaded = false;
            std::ifstream ifs{"save.txt"};
            if (!ifs)
                std::cerr << "Can't read/open save.txt\n";
            else
            {
                ifs >> varNouv.m_seed
                    >> varNouv.m_momentJour
                    >> varNouv.m_typePaysage
                    >> varNouv.m_densite1
                    >> varNouv.m_densite2
                    >> varNouv.m_densite3
                    >> varNouv.m_densiteNuage
                    >> varNouv.m_densiteOiseau;
                ifs.close();

                Ciel c{varNouv.m_densiteOiseau,varNouv.m_densiteNuage,varNouv.m_momentJour,svgout,rg1};

                if(varNouv.m_typePaysage==1)
                {
                    c.dessiner(svgout,rg1);
                    PlanMontagne p{varNouv.m_densite1,varNouv.m_densite2,varNouv.m_densite3,svgout,rg1};
                    p.dessiner(svgout,rg1,c.getPosSoleil());
                }

                if(varNouv.m_typePaysage==2)
                {
                    c.dessiner(svgout,rg1);
                    PlanVille p{varNouv.m_densite1,varNouv.m_densite2,varNouv.m_densite3,svgout,rg1};
                    p.dessiner(svgout,rg1,c.getPosSoleil());
                }
                if(varNouv.m_typePaysage==3)
                {
                    c.dessiner(svgout,rg1);
                    PlanOcean p{varNouv.m_densite1,varNouv.m_densite2,svgout,rg1};
                    p.dessiner(svgout,rg1,c.getPosSoleil());
                }
            }

        }
    }
    while(choix!=0);



    return 0;
}


