#include "maison.h"


Maison::Maison(std::mt19937& randGen,double x, double y,double tailleH,double tailleV,int pos)
{
    m_couleurRand=util::alea(1,2,randGen);
    m_co= {x,y};
    m_tH=tailleH;
    m_tV=tailleH;
    ombrable=true;
    m_pos=pos;
}

void Maison::dessiner(Svgfile& svgout,std::mt19937& randGen) const
{
    ///Maison
    svgout.addRectangle(m_co.getX(),m_co.getY(),m_co.getX()+m_tH,m_co.getY()-m_tV,Couleur{205,50*m_couleurRand*m_couleurRand,50*m_couleurRand*m_couleurRand});
    ///Cheminée
    svgout.addRectangle(m_co.getX()+m_tH/10,m_co.getY()-m_tV*1.1,(m_co.getX()+m_co.getX()+m_tH)/2-m_tH/7,m_co.getY()-3*(m_tH/2),Couleur{0,60*m_couleurRand,30*m_couleurRand});
    ///Toit
    svgout.addTriangle(m_co.getX()-m_tH/7,m_co.getY()-m_tV,m_co.getX()+8*(m_tH/7),m_co.getY()-m_tV,m_co.getX()+m_tH/2,m_co.getY()-3*(m_tH/2),Couleur{110*m_couleurRand*m_couleurRand,35*m_couleurRand*m_couleurRand,0});
    ///Porte
    svgout.addRectangle((m_co.getX()+m_co.getX()+m_tH)/2-m_tH/7,m_co.getY(),(m_co.getX()+m_co.getX()+m_tH)/2+m_tH/7,m_co.getY()-2*(m_tH/5),Couleur{50*m_couleurRand*m_couleurRand,25*m_couleurRand*m_couleurRand,25*m_couleurRand*m_couleurRand});
    ///Fenetres
    svgout.addRectangle(m_co.getX()+3*(m_tH/20),m_co.getY()-13*(m_tV/20),m_co.getX()+8*(m_tH/20),m_co.getY()-9*(m_tV/10),Couleur{80*m_couleurRand*m_couleurRand,80*m_couleurRand*m_couleurRand,80*m_couleurRand*m_couleurRand});
    svgout.addRectangle(m_co.getX()+12*(m_tH/20),m_co.getY()-13*(m_tV/20),m_co.getX()+17*(m_tH/20),m_co.getY()-9*(m_tV/10),Couleur{80*m_couleurRand*m_couleurRand,80*m_couleurRand*m_couleurRand,80*m_couleurRand*m_couleurRand});
}


void Maison::ombrer(Svgfile& svgout, int posSoleil) const
{
    if(posSoleil==1)
        svgout.addPolygoneTransp(m_co.getX(),m_co.getY(),m_co.getX()+m_tH,m_co.getY(),m_co.getX()+m_tH*1.5,m_co.getY()+m_tV*0.1,m_co.getX()+m_tH*0.5,m_co.getY()+m_tV*0.1,Couleur{50,50,50},0.7);
    if(posSoleil==3)
        svgout.addPolygoneTransp(m_co.getX(),m_co.getY(),m_co.getX()+m_tH,m_co.getY(),m_co.getX()+m_tH*0.5,m_co.getY()+m_tV*0.1,m_co.getX()-m_tH*0.5,m_co.getY()+m_tV*0.1,Couleur{50,50,50},0.7);

}



Immeuble::Immeuble(std::mt19937& randGen,double x, double y,double tailleH,double tailleV,int pos)
{
    m_couleurRand=util::alea(1,2,randGen);
    m_co= {x,y};
    m_tH=tailleH;
    m_tV=2*tailleH;
    ombrable=true;
    m_pos=pos;
}

void Immeuble::dessiner(Svgfile& svgout,std::mt19937& randGen) const
{
    ///Immeuble
    svgout.addRectangle(m_co.getX(),m_co.getY(),m_co.getX()+m_tH,m_co.getY()-m_tV,Couleur{0,30*m_couleurRand*m_couleurRand,60*m_couleurRand*m_couleurRand});
    ///Porte
    svgout.addRectangle((m_co.getX()+m_co.getX()+m_tH)/2-m_tH/7,m_co.getY(),(m_co.getX()+m_co.getX()+m_tH)/2+m_tH/7,m_co.getY()-2*(m_tH/5),Couleur{30*m_couleurRand*m_couleurRand,30*m_couleurRand*m_couleurRand,30*m_couleurRand*m_couleurRand});
    /// Boucle fenetres
    double posFenetrex=m_tH;
    double posFenetrey=4*(m_tV/5);
    double posX=m_co.getX();
    for(size_t i=0;i<4;++i)
    {
        for(size_t j=0;j<2;++j)
        {
            svgout.addRectangle(posX+(posFenetrex/5),m_co.getY()-posFenetrey,posX+(2*posFenetrex/5),m_co.getY()-11*posFenetrey/10,Couleur{80*m_couleurRand*m_couleurRand,80*m_couleurRand*m_couleurRand,80*m_couleurRand*m_couleurRand});
            posX=posX+5*(m_tH/12);
        }
      posFenetrey=posFenetrey-m_tV/8;
      posX=m_co.getX();
    }

}


void Immeuble::ombrer(Svgfile& svgout, int posSoleil) const
{
    if(posSoleil==1)
        svgout.addPolygoneTransp(m_co.getX(),m_co.getY(),m_co.getX()+m_tH,m_co.getY(),m_co.getX()+m_tH*1.6,m_co.getY()+m_tV*0.15,m_co.getX()+m_tH*0.6,m_co.getY()+m_tV*0.15,Couleur{50,50,50},0.7);
    if(posSoleil==3)
        svgout.addPolygoneTransp(m_co.getX(),m_co.getY(),m_co.getX()+m_tH,m_co.getY(),m_co.getX()+m_tH*0.6,m_co.getY()+m_tV*0.15,m_co.getX()-m_tH*0.4,m_co.getY()+m_tV*0.15,Couleur{50,50,50},0.7);

}


Herbe::Herbe(std::mt19937& randGen,double x, double y,double tailleH,double tailleV,int pos)
{
    m_couleurRand=util::alea(1,2,randGen);
    m_co= {x,y};
    m_tH=tailleH;
    m_tV=3*tailleH/3;
    ombrable=false;
    m_pos=pos;
}

void Herbe::dessiner(Svgfile& svgout,std::mt19937& randGen) const
{
    svgout.addTriangle(m_co.getX(),m_co.getY(),m_co.getX()-m_tH/5,m_co.getY()-m_tV,m_co.getX()+m_tH/2,m_co.getY(),Couleur{0,90*m_couleurRand,0});
    svgout.addTriangle(m_co.getX(),m_co.getY(),m_co.getX()+m_tH/2,m_co.getY()-3*m_tV/4,m_co.getX()+m_tH,m_co.getY(),Couleur{0,90*m_couleurRand,0});
    svgout.addTriangle(m_co.getX()+m_tH/2,m_co.getY(),m_co.getX()+m_tH,m_co.getY(),m_co.getX()+6*m_tH/5,m_co.getY()-m_tV,Couleur{0,90*m_couleurRand,0});
}


void Herbe::ombrer(Svgfile& svgout, int posSoleil) const
{

}
