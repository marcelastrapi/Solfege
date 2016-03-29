#pragma once

#include "Notes.h"
//#include "iostream"

//ACCORDS
/// \brief enum du noms de tout les accords, commencant toute par c comme chords
enum ChordsNames {
    maj,                   ///< Chord majeur = M
    maj5Dim,               ///< Chord majeur with 5 dim = b5
    maj5Dim7Min,           ///< Chord majeur with 5 dim 7 mineur = 7b5
    maj5Aug,               ///< Chord majeur with 5 aug = +
    maj5Aug7Min,           ///< Chord majeur with 5 aug 7 mineur = +7
    maj7Min,               ///< Chord majeur with 7 mineur = 7
    maj7Min9Maj,           ///< Chord majeur with 7 mineur 9 majeur = 9
    maj7Maj,               ///< Chord majeur with 7 majeur = M7
    maj7Maj9Maj,           ///< Chord majeur with 7 majeur 9 majeur = M9
    maj7Maj9Aug,           ///< Chord majeur with 7 majeur 9 augmentée = 7#9
    maj7Maj9Dim,           ///< Chord majeur with 7 majeur 9 mineur = 7b9
    majAdd2,               ///< Chord majeur with 2 ajoutée = add2
    majAdd4,               ///< Chord majeur with 4 ajoutée = add4
    maj6Maj,               ///< Chord majeur with 6 majeur = 6
    maj6Maj9Maj,           ///< Chord majeur with 6 majeur 9 majeur = 6/9

    minor,                 ///< Chord mineur = m
    min5Dim,               ///< Chord mineur with 5 dim  = mb5
    min5Dim7Min,           ///< Chord mineur with 5 dim 7 mineur = demi-diminué = rond-barré
    min5Dim7Dim,           ///< Chord mineur with 5 dim 7 dim      = septième-diminuée = °7
    min7Min,               ///< Chord mineur with 7 mineur   = m7
    min7Min9Maj,           ///< Chord mineur with 7 mineur 9 majeur = m9
    min7Maj,               ///< Chord mineur with 7 majeur = m7M
    minAdd2,               ///< Chord mineur with 2 ajoutée = madd2
    minAdd4,               ///< Chord mineur with 4 ajoutée = madd4
    min6Maj,               ///< Chord mineur with 6 majeur = m6
    min6Maj9Maj,           ///< Chord mineur with 6 majeur 9 majeur = m6/9

    sus2,                  ///< Chord with 2 ajoutée = sus2
    sus4,                  ///< Chord with 4 ajoutée = sus4
};
class  Chord : public Notes {
    //Variables
private :
    Note m_fondamental;
    ChordsNames m_chordName;

    //Constructors
public :
    Chord( const Note  &fondamental, const ChordsNames &chordName );
    Chord( const std::string &strFondamental,int _octave , const ChordsNames &chordName );
private :
    void initialise();

    //Getter
public:
    inline Note getFondamental() const { return m_fondamental; }
    inline ChordsNames getIntervalName() const { return m_chordName; }

    //Setter
    void setFondamental(const Note &newFondamental);
    void setChordName(const ChordsNames &newChordName);

};

