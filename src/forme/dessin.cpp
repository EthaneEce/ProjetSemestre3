#include "../forme/dessin.h"
#include "../util/util.h"


Sapin::Sapin(std::mt19937& randGen,double x, double y,double tailleH,double tailleV,int pos,bool neige)
{
    m_couleurRand=util::alea(1,2,randGen);
    m_co= {x,y};
    m_tH=tailleH;
    m_tV=tailleV;
    ombrable=true;
    m_pos=pos;
    m_neige=neige;

}

void Sapin::dessiner(Svgfile& svgout,std::mt19937& randGen) const
{



    svgout.addRectangle(m_co.getX()+(2*m_tH)/5,m_co.getY(),m_co.getX()+(3*m_tH)/5,m_co.getY()-(2*m_tV)/5,Couleur{50*m_couleurRand*m_couleurRand,25*m_couleurRand*m_couleurRand,25*m_couleurRand*m_couleurRand});

    svgout.addTriangle(m_co.getX()-m_tH/8,m_co.getY()-(2*m_tV)/5,m_co.getX()+m_tH/2,m_co.getY()-(6*m_tV)/5,m_co.getX()+9*m_tH/8,m_co.getY()-(2*m_tV)/5,Couleur{0,90*m_couleurRand,0},1,"lightgrey");
    svgout.addTriangle(m_co.getX(),m_co.getY()-(3.5*m_tV)/5,m_co.getX()+m_tH/2,m_co.getY()-(6.5*m_tV)/5,m_co.getX()+m_tH,m_co.getY()-(3.5*m_tV)/5,Couleur{0,90*m_couleurRand,0},1,"lightgrey");
    svgout.addTriangle(m_co.getX()+(m_tH/17),m_co.getY()-(5*m_tV)/5,m_co.getX()+m_tH/2,m_co.getY()-(8*m_tV)/5,m_co.getX()+(16*m_tH/17),m_co.getY()-(5*m_tV)/5,Couleur{0,90*m_couleurRand,0},1,"lightgrey");
    if(m_neige==true)
    {


        /*--------------------Neige---------------------------*/
        svgout.addTriangle(m_co.getX()+(m_tH*1.33/5),m_co.getY()-(6.5*m_tV)/5,m_co.getX()+m_tH/2,m_co.getY()-(8*m_tV)/5,m_co.getX()+(3.66*m_tH/5),m_co.getY()-(6.5*m_tV)/5,Couleur{255,255,255});

        for(size_t i=0; i<util::alea(4,7,randGen); ++i)
            svgout.addEllipse(util::alea(m_co.getX()+m_tH*3/10,m_co.getX()+m_tH*7/10,randGen),m_co.getY()-(6.5*m_tV)/5,util::alea(m_tH*0.02,m_tH*0.03,randGen),util::alea(m_tV*0.02,m_tV*0.08,randGen),Couleur(255,255,255));


    }
}


void Sapin::ombrer(Svgfile& svgout , int posSoleil) const
{
    if(posSoleil==1)
    {
        svgout.addEllipseTransp(m_co.getX()+m_tH/2+m_tH/5,m_co.getY(),m_tH/2,m_tV/12,Couleur{50,50,50},0.7);
    }
    if(posSoleil==2)
    {
        svgout.addEllipseTransp(m_co.getX()+m_tH/2,m_co.getY(),m_tH/2,m_tV/12,Couleur{50,50,50},0.7);
    }
    if(posSoleil==3)
    {
        svgout.addEllipseTransp(m_co.getX()+m_tH/5,m_co.getY(),m_tH/2,m_tV/12,Couleur{50,50,50},0.7);
    }
}



Mont::Mont(std::mt19937& randGen,double x, double y,double tailleH,double tailleV,int pos,Couleur oue)
{
    m_couleurRand=util::alea(1,2,randGen);
    m_co= {x,y};
    m_tH=tailleH;
    m_tV=tailleV;
    ombrable=true;
    m_pos=pos;
    m_c=oue;
}


void Mont::dessiner(Svgfile& svgout,std::mt19937& randGen)const
{
    if (m_c.getB()==40&&m_c.getR()==40&&m_c.getV()==40)
    {
        Couleur o=m_c;
        svgout.addMontain(m_co.getX()-m_tH/2,m_co.getX()+m_tH/2,m_co.getY(),m_co.getX()-(m_tH/2)*0.150,m_co.getX()+(m_tH/2)*0.150,m_co.getY()-m_tV,m_tV*0.050,o.ajouter(40*m_couleurRand));
        /*-----------------------Neige------------------------------*/

        svgout.addMontain((m_co.getX()-m_tH*5/36),m_co.getX()+m_tH*5/36,m_co.getY()-m_tV*0.85,m_co.getX()-(m_tH/2)*0.150,m_co.getX()+(m_tH/2)*0.150,(m_co.getY()-m_tV*0.85)-m_tV*0.15,m_tV*0.050,Couleur(255,255,255));
        for(size_t i=0; i<util::alea(2,4,randGen); ++i)
            svgout.addEllipse(util::alea(m_co.getX()-m_tH*3.5/36,m_co.getX()+m_tH*3.4/36,randGen),m_co.getY()-m_tV*0.85,util::alea(m_tH*0.005,m_tH*0.01,randGen),util::alea(m_tV*0.05,m_tV*0.01,randGen),Couleur(255,255,255));

    }
    else
        svgout.addMontain(m_co.getX()-m_tH/2,m_co.getX()+m_tH/2,m_co.getY(),m_co.getX()-(m_tH/2)*0.80,m_co.getX()+(m_tH/2)*0.80,m_co.getY()-m_tV,m_tV*0.9,m_c);

}

void Mont::ombrer(Svgfile& svgout, int posSoleil)const
{
    if(posSoleil==1)
    {
        svgout.addPolygoneTransp(m_co.getX()+m_tH/6,m_co.getY(),m_co.getX(),m_co.getY()-m_tV*0.85,m_co.getX()+m_tH*5/36,m_co.getY()-m_tV*0.85,m_co.getX()+(m_tH/2),m_co.getY(),Couleur(50,50,50),0.7);
    }
    if(posSoleil==3)
    {
        svgout.addPolygoneTransp(m_co.getX()-m_tH/6,m_co.getY(),m_co.getX(),m_co.getY()-m_tV*0.85,m_co.getX()-m_tH*5/36,m_co.getY()-m_tV*0.85,m_co.getX()-(m_tH/2),m_co.getY(),Couleur(50,50,50),0.7);
    }

}

Soleil::Soleil(double x,double y,Couleur color,double tailleH,double tailleV)
{

    m_couleurRand=1;
    m_co={x,y};
    m_tH=tailleH;
    m_tV=tailleV;
    ombrable=false;
    m_pos=3;
    m_color=color;

}
void Soleil::dessiner(Svgfile& svgout,std::mt19937& randGen) const
{
    if (m_color.getB()==0&&m_color.getR()==0&&m_color.getV()==0)
    {
        svgout.addDisk(m_co.getX(),m_co.getY(),m_tH,"white");
        svgout.addEllipseTransp(m_co.getX()+m_co.getX()*3/30,m_co.getY()+m_co.getY()*4/20,m_tH/4,m_tH/5,Couleur{191,191,191},0.7);
        svgout.addEllipseTransp(m_co.getX()-m_co.getX()*0/30,m_co.getY()-m_co.getY()*4/20,m_tH/4,m_tH/5,Couleur{191,191,191},0.7);
    }
    else
    {
        svgout.addTriangle(m_co.getX()-(m_tH*1.2),m_co.getY()+(m_tH*0.2),m_co.getX()-(m_tH*1.2),m_co.getY()-(m_tH*0.2),m_co.getX()-(m_tH*1.9),m_co.getY(),m_color);//triangles au nord sud est ouest (par rapport au soleil)
        svgout.addTriangle(m_co.getX()+(m_tH*1.2),m_co.getY()+(m_tH*0.2),m_co.getX()+(m_tH*1.2),m_co.getY()-(m_tH*0.2),m_co.getX()+(m_tH*1.9),m_co.getY(),m_color);
        svgout.addTriangle(m_co.getX()+(m_tH*0.2),m_co.getY()-(m_tH*1.2),m_co.getX()-(m_tH*0.2),m_co.getY()-(m_tH*1.2),m_co.getX(),m_co.getY()-(m_tH*1.9),m_color);
        svgout.addTriangle(m_co.getX()+(m_tH*0.2),m_co.getY()+(m_tH*1.2),m_co.getX()-(m_tH*0.2),m_co.getY()+(m_tH*1.2),m_co.getX(),m_co.getY()+(m_tH*1.9),m_color);

        svgout.addTriangle(m_co.getX()-m_tH,m_co.getY()-(m_tH*0.7),m_co.getX()-(m_tH*0.7),m_co.getY()-m_tH,m_co.getX()-(m_tH*1.3),m_co.getY()-(m_tH*1.3),m_color);// triangle au nord-ouest, sud-ouest, sud-est et nord-est (par rapport au soleil)
        svgout.addTriangle(m_co.getX()+m_tH,m_co.getY()+(m_tH*0.7),m_co.getX()+(m_tH*0.7),m_co.getY()+m_tH,m_co.getX()+(m_tH*1.3),m_co.getY()+(m_tH*1.3),m_color);
        svgout.addTriangle(m_co.getX()-m_tH,m_co.getY()+(m_tH*0.7),m_co.getX()-(m_tH*0.7),m_co.getY()+m_tH,m_co.getX()-(m_tH*1.3),m_co.getY()+(m_tH*1.3),m_color);
        svgout.addTriangle(m_co.getX()+(m_tH*0.7),m_co.getY()-m_tH,m_co.getX()+m_tH,m_co.getY()-(m_tH*0.7),m_co.getX()+(m_tH*1.3),m_co.getY()-(m_tH*1.3),m_color);
        svgout.addDisk(m_co.getX(),m_co.getY(),m_tH,m_color);
    }



}


void Soleil::ombrer(Svgfile& svgout, int posSoleil) const
{

}













