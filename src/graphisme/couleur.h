#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

#include <string>
#include <cstdint>

class Couleur
{
    public :
        Couleur(uint8_t rouge, uint8_t vert, uint8_t bleu);
        Couleur();
        void afficher() const;
        void saisir();
        void muter(double amplitude);
        Couleur assombrir(double amplitude)
            {return Couleur{m_rouge/amplitude,m_vert/amplitude,m_bleu/amplitude};}


        Couleur ajouter(uint8_t ajout)
            {return Couleur{m_rouge+ajout,m_vert+ajout,m_bleu+ajout};}


        Couleur ajouter(uint8_t ajoutR,uint8_t ajoutV,uint8_t ajoutB)
            {return Couleur{m_rouge+ajoutR,m_vert+ajoutV,m_bleu+ajoutB};}

        uint8_t getR()const {return m_rouge;}
        uint8_t getV()const {return m_vert;}
        uint8_t getB()const {return m_bleu;}

        int diffR(Couleur a)const{return(m_rouge - a.getR());}
        int diffV(Couleur a)const{return(m_vert - a.getV());}
        int diffB(Couleur a)const{return(m_bleu - a.getB());}

        operator std::string() const;

    private :
        // uint8_t équivalent à unsigned char :
        // unsigned 8 bits (8 bits non signé)
        uint8_t m_rouge, m_vert, m_bleu;
};

#endif // COULEUR_H_INCLUDED
