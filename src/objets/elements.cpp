#include "elements.h"

Poisson::Poisson(double x,double y,double tailleH,double tailleV,int pos)
{

    m_couleurRand=1;
    m_co={x,y};
    m_tH=tailleH;
    m_tV=tailleV;
    ombrable=false;
    m_pos=pos;
}

void Poisson::dessiner(Svgfile& svgout,std::mt19937& randGen) const
{
        int senspoisson;

        senspoisson=util::alea(-1,1,randGen);

        if(senspoisson==0)
            senspoisson=1;

        Couleur poisson1=Couleur(util::alea(1,255,randGen),util::alea(1,255,randGen),0);
        svgout.addEllipse(m_co.getX(),m_co.getY(),m_tH,m_tV, poisson1);
        svgout.addTriangle(m_co.getX()-(senspoisson*(0.75*m_tH)),m_co.getY(),(m_co.getX()-(senspoisson*(1.25)*m_tH)),m_co.getY()+(1.25*m_tV),m_co.getX()-(senspoisson*(1.25*m_tH)),m_co.getY()-(1.25*m_tV),poisson1);
        svgout.addDisk(m_co.getX()+(senspoisson*(0.80*m_tH)),m_co.getY(),(0.05*m_tH),"black");




}


void Poisson::ombrer(Svgfile& svgout, int posSoleil) const
{

}

Nuage::Nuage(double x,double y,double tailleH,double tailleV,int pos)
{

     m_couleurRand=1;
    m_co={x,y};
    m_tH=tailleH;
    m_tV=tailleV;
    ombrable=false;
    m_pos=pos;
}


void Nuage::dessiner(Svgfile& svgout,std::mt19937& randGen) const
{

    int couleur=util::alea(195,255,randGen);
    Couleur nuage1(couleur,couleur,couleur);

    svgout.addDisk(m_co.getX(),m_co.getY()+(m_tH*0.6),m_tH,nuage1);
    svgout.addDisk(m_co.getX()+(m_tH*1),m_co.getY()+(m_tH*0.8),m_tH,nuage1);
    svgout.addDisk(m_co.getX()+(m_tH*2),m_co.getY()+(m_tH*0.8),m_tH,nuage1);
    svgout.addDisk(m_co.getX()+(m_tH*3),m_co.getY()+(m_tH*0.6),m_tH,nuage1);

    svgout.addDisk(m_co.getX()-(m_tH*0.5),m_co.getY(),m_tH,nuage1);
    svgout.addDisk(m_co.getX(),m_co.getY(), m_tH,nuage1);
    svgout.addDisk(m_co.getX()+(m_tH*1),m_co.getY(), m_tH,nuage1);
    svgout.addDisk(m_co.getX()+(m_tH*2),m_co.getY(), m_tH,nuage1);
    svgout.addDisk(m_co.getX()+(m_tH*3),m_co.getY(), m_tH,nuage1);
    svgout.addDisk(m_co.getX()+(m_tH*3.5),m_co.getY(), m_tH,nuage1);


    svgout.addDisk(m_co.getX(),m_co.getY()-(m_tH*0.6), m_tH,nuage1);
    svgout.addDisk(m_co.getX()+(m_tH*1),m_co.getY()-(m_tH*0.8),m_tH,nuage1);
    svgout.addDisk(m_co.getX()+(m_tH*2),m_co.getY()-(m_tH*0.8),m_tH,nuage1);
    svgout.addDisk(m_co.getX()+(m_tH*3),m_co.getY()-(m_tH*0.6),m_tH,nuage1);




}


void Nuage::ombrer(Svgfile& svgout, int posSoleil) const
{

}






Etoile::Etoile(double x, double y,double tailleH,double tailleV,int pos)
{
    m_couleurRand=1;
    m_co= {x,y};
    m_tH=tailleH;
    m_tV=tailleV;
    ombrable=false;
    m_pos=pos;

}

void Etoile::dessiner(Svgfile& svgout,std::mt19937& randGen) const
{



   svgout.addTriangle(m_co.getX(),m_co.getY(),m_co.getX()+m_tH,m_co.getY(),m_co.getX()+(m_tH*0.5),(0.4*m_tH)+m_co.getY(),"white");
   svgout.addTriangle(m_co.getX()+(m_tH*0.5),m_co.getY()-(0.43*m_tH),(0.80*m_tH)+m_co.getX(),(0.57*m_tH)+m_co.getY(),m_co.getX()+(m_tH*0.5),(0.4*m_tH)+m_co.getY(),"white");
    svgout.addTriangle(m_co.getX()+(m_tH*0.5),m_co.getY()-(0.43*m_tH),(0.20*m_tH)+m_co.getX(),(0.57*m_tH)+m_co.getY(),m_co.getX()+(m_tH*0.5),(0.4*m_tH)+m_co.getY(),"white");


}




void Etoile::ombrer(Svgfile& svgout, int posSoleil) const
{

}

Bateau::Bateau(double x,double y,double tailleH,double tailleV,int pos)
{

    m_couleurRand=1;
    m_co={x,y};
    m_tH=tailleH;
    m_tV=tailleV;
    ombrable=false;
    m_pos=pos;
}
void Bateau::dessiner(Svgfile& svgout,std::mt19937& randGen) const
{
    int couleur=util::alea(30,75,randGen);
    Couleur bateaucoqueetmat(2*couleur,couleur,0);
    int couleur1=util::alea(0,255,randGen);
    int couleur2=util::alea(0,255,randGen);
    int couleur3=util::alea(0,255,randGen);

    svgout.addRectangle(m_co.getX(),m_co.getY(),m_co.getX()+m_tH,m_co.getY()-m_tV,bateaucoqueetmat);

    svgout.addTriangle(m_co.getX()+m_tH-1,m_co.getY(),m_co.getX()+m_tH-1,m_co.getY()-m_tV,m_co.getX()+(m_tH*1.5),m_co.getY()-m_tV,bateaucoqueetmat);
    svgout.addTriangle(m_co.getX(),m_co.getY(),m_co.getX(),m_co.getY()-m_tV,m_co.getX()-(m_tH*0.5),m_co.getY()-m_tV,bateaucoqueetmat);
    svgout.addLine(m_co.getX()+(m_tH*0.65),m_co.getY()-m_tV,m_co.getX()+(m_tH*0.65),m_co.getY()-(m_tV*5),bateaucoqueetmat);
    svgout.addLine(m_co.getX()+(m_tH*0.75),m_co.getY()-m_tV,m_co.getX()+(m_tH*0.75),m_co.getY()-(m_tV*5),bateaucoqueetmat);
    svgout.addTriangle(m_co.getX()+(m_tH*0.65),m_co.getY()-(m_tV*1.25),m_co.getX()+(m_tH*0.65),m_co.getY()-(m_tV*5),m_co.getX()-(m_tH*0.6),m_co.getY()-(m_tV*1.25),Couleur(couleur1,couleur2,couleur3));
    svgout.addTriangle(m_co.getX()+(m_tH*0.75),m_co.getY()-(m_tV*1.25),m_co.getX()+(m_tH*0.75),m_co.getY()-(m_tV*4.2),m_co.getX()+(m_tH*1.75),m_co.getY()-(m_tV*1.25),Couleur(couleur3,couleur1,couleur2));
    svgout.addTriangle(m_co.getX()+(m_tH*0.75),m_co.getY()-(m_tV*4.4),m_co.getX()+(m_tH*0.75),m_co.getY()-(m_tV*5),m_co.getX()+(m_tH*1.25),m_co.getY()-(m_tV*4.7),Couleur(couleur2,couleur3,couleur1));


}


void Bateau::ombrer(Svgfile& svgout, int posSoleil) const
{
    //svgout.addEllipse(m_co.getX()+m_tH/2,m_co.getY(),m_tH/2,m_tV/20,fond.assombrir(2));
}


Oiseau::Oiseau(double x,double y,double tailleH,double tailleV,int pos)
{

    m_couleurRand=1;
    m_co={x,y};
    m_tH=tailleH;
    m_tV=tailleV;
    ombrable=false;
    m_pos=pos;
}

void Oiseau::dessiner(Svgfile& svgout,std::mt19937& randGen) const
{
     int sensoiseau;
     int sensaile;


    sensoiseau=util::alea(-1,1,randGen);
    sensaile=util::alea(-1,1,randGen);

    if (sensaile==0)
        sensaile=1;
    if(sensoiseau==0)
        sensoiseau=1;


    int couleur=util::alea(80,255,randGen);
    Couleur oiseau(couleur,couleur,couleur);
    svgout.addEllipse(m_co.getX(),m_co.getY(),m_tH,m_tH*0.5,oiseau);
    svgout.addTriangle(m_co.getX()+(m_tH*sensoiseau),m_co.getY(),m_co.getX()+(m_tH*sensoiseau*0.83),m_co.getY()+m_tH*0.25,m_co.getX()+(m_tH*sensoiseau*1.17),m_co.getY()+m_tH*0.25,"orange");
    svgout.addEllipse(m_co.getX()-(m_tH*sensoiseau),m_co.getY(),m_tH/6,m_tH/4,oiseau);
    svgout.addEllipse(m_co.getX()+(m_tH*sensoiseau*0.42),m_co.getY()+(m_tH*0.25*sensaile),m_tH/4,m_tH*0.66,oiseau);
    svgout.addEllipse(m_co.getX()-(m_tH*sensoiseau*0.16),m_co.getY()+(m_tH*0.42*sensaile),m_tH/4,m_tH*0.66,oiseau);
    svgout.addDisk(m_co.getX()+(m_tH*sensoiseau*0.66),m_co.getY()-(m_tH*0.08),m_tH*0.08,"dark");



}


void Oiseau::ombrer(Svgfile& svgout, int posSoleil) const
{

}

