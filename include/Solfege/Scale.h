//#pragma once

#ifndef SCALE_H
#define SCALE_H

#include "Notes.h"

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
class  Scale : public Notes {
    //Variables
private :
    Note m_fondamental;
    Modes m_mode;

    //Constructors
public:
    Scale( const Note &fondamental, const Modes &mode );
    Scale (const std::string &noteName, int _octave, const Modes &mode );
private :
    void initialise();
//Copy implicite inside Notes from std::vector

    //Getter
public:
    inline Note getFondamental() const { return m_fondamental; }
    inline Modes getMode() const { return m_mode;}

    //Setter
    void setFondamental(const Note &newFondamental);
    void setMode(const Modes &newMode);

};

#endif // SCALE_H
