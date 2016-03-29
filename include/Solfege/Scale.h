//#pragma once

#ifndef SCALE_H
#define SCALE_H

#include "Musicien.h"

//GAMMES
enum Modes  {
    ionien,         ///< mode de do
    dorien,         ///< mode de ré
    phrygien,       ///< mode de mi
    lydien,         ///< mode de fa
    mixolydien,     ///< mode de sol
    eolien,         ///< mode de la
    locrien,        ///< mode de si
    parTon,         ///< gamme par ton
    tondemiton,     ///< gamme diminué ton/demi-ton
    demitonton      ///< inverse tondemiton-ton/ton
};

/// \brief specialized musician who only play Scale...
class  Scale : public Musicien {
    //Variables
private :
    Note m_fondamental;
    Modes m_mode;
    sf::Time m_time;

    //Constructors
public:
    Scale( const Note &fondamental, const Modes &mode , const sf::Time &time, const InstrumentName instrument = Sinusoide );
private :
    void initialise();

    //Getter
public:
    inline Note getFondamental() const { return m_fondamental; }
    inline Modes getMode() const { return m_mode;}

    //Setter
    void setFondamental(const Note &newFondamental);
    void setMode(const Modes &newMode);

};

#endif // SCALE_H
