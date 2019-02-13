#include "../page/plan.h"
#include "../geometrie/transformation.h"
#include "../util/util.h"
#include <algorithm>

PlanMontagne::PlanMontagne(int densiteMontagne,int densiteArbre,int densiteMaison,Svgfile& svgout,std::mt19937& randGen)
{
    try
    {
        m_densiteMontagne=densiteMontagne;
        m_densiteArbre=densiteArbre;
        m_densiteMaison=densiteMaison;
        int z;
        double x;
        if(m_densiteMontagne<1||m_densiteMontagne>3)
            throw std::domain_error("Densite de montagne non valide !");
        if(m_densiteMaison<0||m_densiteMaison>3)
            throw std::domain_error("Densite de maison non valide !");
        if(m_densiteArbre<0||m_densiteArbre>3)
            throw std::domain_error("Densite d'arbre non valide !");

        //for (size_t)

        int comptMont=0;
        int nbMontMin,nbMontMax,nbArbreMin,nbArbreMax,nbMaisonMin,nbMaisonMax;


        if(m_densiteMontagne==1)
        {
            nbMontMin=4;
            nbMontMax=6;
        }
        if(m_densiteMontagne==2)
        {
            nbMontMin=7;
            nbMontMax=9;
        }
        if(m_densiteMontagne==3)
        {
            nbMontMin=10;
            nbMontMax=12;
        }

        nbArbreMin=m_densiteArbre;
        nbArbreMax=3*m_densiteArbre;

        nbMaisonMin=m_densiteMaison;
        nbMaisonMax=2*m_densiteMaison;

        /*------Générations des montagnes, on cherche a avoir au moinss une montagne par chunk,--------------------
         --------                    ce qui correspond a 1/3 de l'ecran                        --------------------*/

        int nbMont;

        nbMont=util::alea(nbMontMin,nbMontMax,randGen);


        m_monts.push_back(new Mont{randGen,svgout.getWidth()/2,svgout.getHeight(),svgout.getWidth()*1.3,150,2,Couleur(0,util::alea(190,255,randGen),0)});


        for(size_t i=1; i<util::alea(2,(nbMont-2),randGen); ++i)
        {
            do
            {
                x=util::alea(0,svgout.getWidth()/3,randGen);
                if (x>(m_monts[0]->getCo().getX()-m_monts[0]->getCo().getX()*0.7) && x<m_monts[0]->getCo().getX()+m_monts[0]->getCo().getX()*0.7)
                    z=1;
                else
                    z=util::alea(1,3,randGen);
            }
            while(z==2);
            m_monts.push_back(new Mont{randGen,x,svgout.getHeight(),util::alea(500,700,randGen),util::alea(350,600,randGen),z,Couleur{40,40,40}});
            comptMont=i;
        }
        for(size_t i=comptMont; i<util::alea(comptMont,(nbMont-1),randGen); ++i)
        {
            do
            {
                x=util::alea(svgout.getWidth()/3,svgout.getWidth()*2/3,randGen);
                if (x>m_monts[0]->getCo().getX()-250&&x<m_monts[0]->getCo().getX()+250)
                    z=1;
                else
                    z=util::alea(1,3,randGen);
            }
            while(z==2);
            m_monts.push_back(new Mont{randGen,x,svgout.getHeight(),util::alea(500,700,randGen),util::alea(350,600,randGen),z,Couleur{40,40,40}});
            comptMont=i;
        }
        for(size_t i=comptMont; i<(nbMont); ++i)
        {
            do
            {
                x=util::alea(svgout.getWidth()*2/3,svgout.getWidth()*3/3,randGen);
                if (x>m_monts[0]->getCo().getX()-250&&x<m_monts[0]->getCo().getX()+250)
                    z=1;
                else
                    z=util::alea(1,3,randGen);
            }
            while(z==2);
            m_monts.push_back(new Mont{randGen,x,svgout.getHeight(),util::alea(500,700,randGen),util::alea(350,600,randGen),z,Couleur{40,40,40}});
        }

        /*------------------Generation d'arbre que l'on gere aussi par chunk--------------------------------- */

        int arbregen=0; int rang=0;
        size_t nbArbre=util::alea(nbArbreMin,nbArbreMax,randGen);
        double yTest;

        for(double i=1; i<=5; ++i)
        {

            for(size_t j=0; j<nbArbre; ++j)
            {

               yTest=util::alea(svgout.getHeight()*2/2.8,svgout.getHeight()*0.9,randGen);
                for(size_t k=0; k<m_objects.size(); ++k)
                {
                    if(yTest>m_objects[k]->getCo().getY())
                        rang++;
                }

                m_objects.insert(m_objects.begin()+rang,new Sapin{randGen,util::alea((svgout.getWidth()*1/9)*(i),(svgout.getWidth()/6)*(i+1),randGen),yTest,util::alea(25,50,randGen),util::alea(50,75,randGen),util::alea(1,3,randGen),true});
                rang=0;
                arbregen++;

            }
        }


///-------------------------------------------------GENE MAISON ----------------------------------------------------------------------------///
        size_t nbMaison=util::alea(nbMaisonMin,nbMaisonMax,randGen);
        rang=0;

        for(size_t j=0; j<nbMaison; ++j)
        {
            yTest=util::alea(svgout.getHeight()*2/2.8,svgout.getHeight()*0.9,randGen);
            for(size_t k=0; k<m_objects.size(); ++k)
            {
                if(yTest>m_objects[k]->getCo().getY())
                    rang++;
            }

            m_objects.insert(m_objects.begin()+rang,new Maison{randGen,util::alea(0,svgout.getWidth(),randGen),yTest,util::alea(75,100,randGen),util::alea(50,75,randGen),util::alea(1,3,randGen)});

            rang=0;
        }

///-------------------------------------------------GENE HERBE ----------------------------------------------------------------------------///
        size_t nbHerbe=util::alea(30,70,randGen);
        rang=0;

        for(size_t j=0; j<nbHerbe; ++j)
        {
            yTest=util::alea(svgout.getHeight()*2/2.8,svgout.getHeight()*0.9,randGen);
            for(size_t k=0; k<m_objects.size(); ++k)
            {
                if(yTest>m_objects[k]->getCo().getY())
                    rang++;
            }

            m_objects.insert(m_objects.begin()+rang,new Herbe{randGen,util::alea(svgout.getWidth()*0.10,svgout.getWidth()*0.90,randGen),yTest,util::alea(10,15,randGen),util::alea(10,15,randGen),util::alea(1,3,randGen)});

            rang=0;
        }


    }
    catch(const std::exception& e)
    {
        std::cerr << "Attention !!" << std::endl;
        std::cerr << "La raison est : " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}
PlanMontagne::~PlanMontagne()
{


    for(size_t j=0; j<m_objects.size(); ++j)
    {
        delete m_objects[j];
    }

    for(size_t j=0; j<m_monts.size(); ++j)
    {
        delete m_monts[j];
    }
}



void PlanMontagne::dessiner(Svgfile& svgout,std::mt19937& rg,int posSoleil)const
{

    for(size_t j=1; j<=3; ++j)
    {
        for(size_t i=1; i<m_monts.size(); ++i)
        {
            if (m_monts[i]->getPos()==j)
            {
                m_monts[i]->dessiner(svgout,rg);
                m_monts[i]->ombrer(svgout,posSoleil);
            }

        }
        if (j==2)
        {
            m_monts[0]->dessiner(svgout,rg);
            for(size_t k=0;k<m_objects.size();++k)
            {

                if(m_objects[k]->getOm()==true)
                    m_objects[k]->ombrer(svgout,posSoleil);

                m_objects[k]->dessiner(svgout,rg);
            }
        }

    }
    svgout.finir();


}

PlanOcean::PlanOcean(int densitePoisson,int densiteBateau,Svgfile& svgout,std::mt19937& randGen)
{
    try
    {
        m_densitePoisson=densitePoisson;
        m_densiteBateau=densiteBateau;


        if(m_densitePoisson<1||m_densitePoisson>3)
            throw std::domain_error("Densite de poisson non valide !");
        if(m_densiteBateau<0||m_densiteBateau>3)
            throw std::domain_error("Densite de poisson non valide !");



        int nbPoissonMin,nbPoissonMax;

        nbPoissonMin=2*m_densitePoisson;
        nbPoissonMax=4*m_densitePoisson;

        int nbBateauMin,nbBateauMax;

        nbBateauMin=m_densiteBateau;
        nbBateauMax=3*m_densiteBateau;




        /*------------------Generation de poisson que l'on gere aussi par chunk--------------------------------- */

        int poissongen=0; int rang=0;
        size_t nbPoisson=util::alea(nbPoissonMin,nbPoissonMax,randGen);
        double yTest;

        for(double i=0; i<=3; ++i)
        {

            for(size_t j=0; j<nbPoisson; ++j)
            {

                yTest=util::alea(svgout.getHeight()-svgout.getHeight()*5/9,(svgout.getHeight()),randGen);
                for(size_t k=0; k<m_objects.size(); ++k)
                {
                    if(yTest>m_objects[k]->getCo().getY())
                        rang++;
                }

                m_objects.insert(m_objects.begin()+rang,new Poisson{util::alea((svgout.getWidth()/3)*(i),(svgout.getWidth()/3)*(i+1),randGen),yTest,util::alea(10,60,randGen),util::alea(10,50,randGen),util::alea(1,3,randGen)});
                rang=0;
                poissongen++;

            }
        }



        size_t nbBateau=util::alea(nbBateauMin,nbBateauMax,randGen);

        for(size_t j=0; j<nbBateau; ++j)
            {


                m_objects.insert(m_objects.begin()+1,new Bateau{util::alea(0,svgout.getWidth(),randGen),svgout.getHeight()/3,util::alea(40,80,randGen),util::alea(20,50,randGen),util::alea(1,3,randGen)});


            }


    }
    catch(const std::exception& e)
    {
        std::cerr << "Attention !!" << std::endl;
        std::cerr << "La raison est : " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

PlanOcean::~PlanOcean()
{
    for(size_t j=0; j<m_objects.size(); ++j)
    {
        delete m_objects[j];
    }
}


void PlanOcean::dessiner(Svgfile& svgout,std::mt19937& rg,int posSoleil)const
{
    svgout.degrade("gradMer",Couleur{0,0,62},Couleur{0,0,236});
    svgout.addRectangle(0,svgout.getHeight(),svgout.getWidth(),svgout.getHeight()/3,"url(#gradMer)");

    svgout.addRadialDegrade("gradSable",Couleur{205,191,18},Couleur{138,129,12});
    svgout.addEllipse(svgout.getWidth()/2,svgout.getHeight(),svgout.getWidth()*2/3,svgout.getHeight()/6,"url(#gradSable)");


    for(size_t k=0;k<m_objects.size();++k)
    {
        if(m_objects[k]->getOm()==true)
            m_objects[k]->ombrer(svgout,posSoleil);

        m_objects[k]->dessiner(svgout,rg);
    }

    svgout.finir();
}


///------------------------------------------------------------------------------------------------------------------------------------------------------------///

PlanVille::PlanVille(int densiteImmeuble,int densiteMaison,int densiteArbre,Svgfile& svgout,std::mt19937& randGen)
{
    try
    {
        m_densiteImmeuble=densiteImmeuble;
        m_densiteMaison=densiteMaison;
        m_densiteArbre=densiteArbre;

        int z;
        double x;
        if(m_densiteImmeuble<1||m_densiteImmeuble>3)
            throw std::domain_error("Densite de Immeuble non valide !");
        if(m_densiteMaison<0||m_densiteMaison>3)
            throw std::domain_error("Densite de maison non valide !");
        if(m_densiteArbre<0||m_densiteArbre>3)
            throw std::domain_error("Densite d'arbre non valide !");

        //for (size_t)


        int nbArbreMin,nbArbreMax,nbImmeubleMin,nbImmeubleMax,nbMaisonMin,nbMaisonMax;


        nbArbreMin=m_densiteArbre;
        nbArbreMax=2*m_densiteArbre;

        nbImmeubleMin=4*m_densiteImmeuble;
        nbImmeubleMax=6*m_densiteImmeuble;

        nbMaisonMin=m_densiteMaison;
        nbMaisonMax=2*m_densiteMaison;

        /*------Générations des Immeubles, on cherche a avoir au moinss une Immeuble par chunk,--------------------
         --------                    ce qui correspond a 1/3 de l'ecran                        --------------------*/



        m_objects.push_back(new Mont{randGen,svgout.getWidth()/2,800,svgout.getWidth()*1.3,150,1,Couleur(0,util::alea(190,255,randGen),0)});

        /*------------------Generation d'arbre que l'on gere aussi par chunk--------------------------------- */

        int arbregen=0; int rang=0;
        size_t nbArbre=util::alea(nbArbreMin,nbArbreMax,randGen);
        double yTest;

        for(double i=1; i<=5; ++i)
        {
            //m_objects.push_back(std::vector<Objet*>);
            for(size_t j=0; j<nbArbre; ++j)
            {

                yTest=util::alea(svgout.getHeight()*2/2.8,svgout.getHeight()*0.9,randGen);
                for(size_t k=0; k<m_objects.size(); ++k)
                {
                    if(yTest>m_objects[k]->getCo().getY())
                        rang++;
                }

                m_objects.insert(m_objects.begin()+rang+1,new Sapin{randGen,util::alea((svgout.getWidth()*1/9)*(i),(svgout.getWidth()/6)*(i+1),randGen),yTest,util::alea(25,50,randGen),util::alea(50,75,randGen),util::alea(1,3,randGen),false});
                rang=0;
                arbregen++;

            }
        }


///-------------------------------------------------GENE MAISON ----------------------------------------------------------------------------///
        size_t nbMaison=util::alea(nbMaisonMin,nbMaisonMax,randGen);
        rang=0;

        for(size_t j=0; j<nbMaison; ++j)
        {
            yTest=util::alea(svgout.getHeight()*2/2.8,svgout.getHeight()*0.9,randGen);
            for(size_t k=0; k<m_objects.size(); ++k)
            {
                if(yTest>m_objects[k]->getCo().getY())
                    rang++;
            }

            m_objects.insert(m_objects.begin()+rang+1,new Maison{randGen,util::alea(0,svgout.getWidth(),randGen),yTest,util::alea(75,100,randGen),util::alea(50,75,randGen),util::alea(1,3,randGen)});

            rang=0;
        }


///-------------------------------------------------GENE Immeuble ----------------------------------------------------------------------------///
        size_t nbImmeuble=util::alea(nbImmeubleMin,nbImmeubleMax,randGen);
        rang=0;

        for(size_t j=0; j<nbImmeuble; ++j)
        {
            yTest=util::alea(svgout.getHeight()*2/2.8,svgout.getHeight()*0.9,randGen);
            for(size_t k=0; k<m_objects.size(); ++k)
            {
                if(yTest>m_objects[k]->getCo().getY())
                    rang++;
            }

            m_objects.insert(m_objects.begin()+rang+1,new Immeuble{randGen,util::alea(0,svgout.getWidth(),randGen),yTest,util::alea(75,100,randGen),util::alea(50,75,randGen),util::alea(1,3,randGen)});

            rang=0;
        }

///-------------------------------------------------GENE HERBE ----------------------------------------------------------------------------///
        size_t nbHerbe=util::alea(30,70,randGen);
        rang=0;

        for(size_t j=0; j<nbHerbe; ++j)
        {
            yTest=util::alea(svgout.getHeight()*2/2.8,svgout.getHeight()*0.9,randGen);
            for(size_t k=0; k<m_objects.size(); ++k)
            {
                if(yTest>m_objects[k]->getCo().getY())
                    rang++;
            }

            m_objects.insert(m_objects.begin()+rang+1,new Herbe{randGen,util::alea(svgout.getWidth()*0.10,svgout.getWidth()*0.90,randGen),yTest,util::alea(10,15,randGen),util::alea(10,15,randGen),util::alea(1,3,randGen)});

            rang=0;
        }


    }
    catch(const std::exception& e)
    {
        std::cerr << "Attention !!" << std::endl;
        std::cerr << "La raison est : " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}
PlanVille::~PlanVille()
{


    for(size_t j=0; j<m_objects.size(); ++j)
    {
        delete m_objects[j];
    }

}



void PlanVille::dessiner(Svgfile& svgout,std::mt19937& rg,int posSoleil)const
{

    for(size_t k=0;k<m_objects.size();++k)
    {

        if(m_objects[k]->getOm()==true)
            m_objects[k]->ombrer(svgout,posSoleil);

            m_objects[k]->dessiner(svgout,rg);
    }
    svgout.finir();

}

