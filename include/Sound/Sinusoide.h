#pragma once

#include <cmath>
#include <string>

#include "../Solfege/Note.h"
#include "MySound.h"

class Sinusoide : public MySound {
    //Membres
public :
private:
    static const unsigned SAMPLE_RATE = 44100;
    static const unsigned AMPLITUDE = 30000;
    static constexpr double TWO_PI = 6.28318;

    sf::Int16 *m_raw;

    //Constructeurs / Destructeur
public:
    //Ctor
    Sinusoide( const double _frequence, const sf::Time &_duree = sf::seconds( 1 ) );
    Sinusoide( const Note &note, const sf::Time &_duree = sf::seconds( 1 ) );

    //Dtor
    virtual ~Sinusoide();

private :
    inline sf::Int32       getSamples() const {
        return getTime().asSeconds() * SAMPLE_RATE;
    }

    //Subs
public :
    //INFOS
    void showRaw( int nbElem ) const;
    void showInfosSinusoide() const;

    //SETTER
    void reloadBuffer( double _frequence, const sf::Time &_duree = sf::seconds( 1 ) );
    void reloadBuffer( const Note &note, const sf::Time &_duree = sf::seconds( 1 ) );

private :
    virtual void initialiseBuffer();
    void fillArray(); ///Remplis de la tableau m_raw de la sinusoide à la fréquence voulue

};


/* Utilisation
/start code
    Sinusoide son(Note("cis",4),sf::seconds(0.5));
    son.play();
    sf::sleep( sf::seconds(0.5) );

    //Accord de do majeur
    Sinusoide son1(Note("c",4));
    Sinusoide son2(son1.getNote() += IntervalName(tierce,mineur));
    Sinusoide son3(son1.getNote() += IntervalName(quinte,juste));
    son1.play();son2.play();son3.play();
/end code
*/
