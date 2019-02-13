#include "ciel.h"
#include "../objets/elements.h"

Ciel::Ciel(int densiteOiseau, int densiteNuage,int posSoleil, Svgfile& svgout,std::mt19937& randGen)
{
    m_x=svgout.getWidth()/2;
    m_y=svgout.getHeight()*2/3;
    m_rx=svgout.getWidth();
    m_ry=svgout.getHeight();
    m_posSoleil=posSoleil;
    try
    {
        if(m_posSoleil<1||m_posSoleil>4)
            throw std::domain_error("Moment du jour invalide. Veuillez entrer un nombre entre 1 et 4 !");


        m_densiteOiseau=densiteOiseau;
        m_densiteNuage=densiteNuage;


        if(m_densiteOiseau<0||m_densiteOiseau>3)
            throw std::domain_error("Densite de Oiseau non valide !");
        if(m_densiteNuage<0||m_densiteNuage>3)
            throw std::domain_error("Densite de Nuage non valide !");




        int nbOiseauMin,nbOiseauMax;

        nbOiseauMin=m_densiteOiseau;
        nbOiseauMax=2*m_densiteOiseau;

        int nbNuageMin,nbNuageMax;

        nbNuageMin=2*m_densiteNuage;
        nbNuageMax=4*m_densiteNuage;


        if(m_posSoleil==1)
        {
            m_colorInt=Couleur{157,255,255};
            m_colorExt=Couleur{227,155,251};
            m_soleil= {svgout.getWidth()/15,svgout.getHeight()/10,Couleur{242,198,94}};
        }
        if(m_posSoleil==2)
        {
            m_colorInt=Couleur{135,172,200};
            m_colorExt=Couleur{3,60,145};
            m_soleil= {svgout.getWidth()/2,svgout.getHeight()/10,Couleur{251,226,55}};
        }
        if(m_posSoleil==3)
        {
            m_colorInt=Couleur{254,145,54};
            m_colorExt=Couleur{161,119,120};
            m_soleil= {svgout.getWidth()*14/15,svgout.getHeight()/10,Couleur{253,202,31}};
        }
        if(m_posSoleil==4)
        {
            m_densiteOiseau=0;
            m_densiteNuage=0;
            m_colorInt=Couleur{33,85,107};
            m_colorExt=Couleur{1,7,23};
            m_soleil= {svgout.getWidth()/15,svgout.getHeight()/10,Couleur{0,0,0}};
            size_t nbEtoile=util::alea(50,200,randGen);
            for(double i=0; i<=3; ++i)
            {
                for(size_t j=0; j<nbEtoile; ++j)
                {
                    m_objects.insert(m_objects.begin(),new Etoile{util::alea((svgout.getWidth()/3)*(i),(svgout.getWidth()/3)*(i+1),randGen),util::alea(0,svgout.getHeight()-svgout.getHeight()*0/9,randGen),util::alea(1,10,randGen),util::alea(15,50,randGen),1});
                }
            }
        }


        size_t nbOiseau=util::alea(nbOiseauMin,nbOiseauMax,randGen);

        for(double i=0; i<=3; ++i)
        {
            for(size_t j=0; j<nbOiseau; ++j)
            {
                m_objects.insert(m_objects.begin(),new Oiseau{util::alea((svgout.getWidth()/3)*(i),(svgout.getWidth()/3)*(i+1),randGen),util::alea(0,svgout.getHeight()-svgout.getHeight()*7/9,randGen),util::alea(15,30,randGen),util::alea(15,40,randGen),util::alea(2,3,randGen)});
            }
        }

        size_t nbNuage=util::alea(nbNuageMin,nbNuageMax,randGen);

        for(double i=0; i<=3; ++i)
        {
            for(size_t j=0; j<nbNuage; ++j)
            {
                m_objects.insert(m_objects.begin(),new Nuage{util::alea((svgout.getWidth()/3)*(i),(svgout.getWidth()/3)*(i+1),randGen),util::alea(0,svgout.getHeight()-svgout.getHeight()*7/9,randGen),util::alea(10,25,randGen),util::alea(15,50,randGen),util::alea(2,3,randGen)});
            }
        }


    }
    catch(const std::exception& e)
    {
        std::cerr << "Attention !!" << std::endl;
        std::cerr << "La raison est : " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }

}

void Ciel::dessiner(Svgfile& svgout,std::mt19937& randGen)
{

    svgout.addRadialDegrade("grad1",m_colorInt,m_colorExt);
    svgout.addEllipse(m_x,m_y,m_rx,m_ry,"url(#grad1)");
                m_soleil.dessiner(svgout,randGen);
    for(size_t i=1; i<=3; ++i)
    {

        for(size_t k=0; k<m_objects.size(); ++k)
        {
            if(m_objects[k]->getPos()==i)
            {
                if(m_objects[k]->getOm()==true)
                    m_objects[k]->ombrer(svgout,m_posSoleil);

                m_objects[k]->dessiner(svgout,randGen);
            }


        }
    }

}

Ciel::~Ciel()
{
    for(size_t j=0; j<m_objects.size(); ++j)
    {
        delete m_objects[j];
    }
}
