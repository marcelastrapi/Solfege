#pragma once

#include "Note.h"

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

/// \brief specialized musician who only play ScaleNotes...
class  ScaleNotes {
    //Variables
private :
    Note m_fondamental;
    Modes m_mode;
    std::vector<Note> m_scaleNotes;

    //Constructors
public:
    ScaleNotes( const Note &fondamental, const Modes &mode );
private :
    void initialise();

    //Getter
public:
    inline Note getFondamental() const { return m_fondamental; }
    inline Modes getMode() const { return m_mode;}
    inline std::vector<Note> getNotes() const { return m_scaleNotes; }

    //Setter
    void setFondamental(const Note &newFondamental);
    void setMode(const Modes &newMode);

};

