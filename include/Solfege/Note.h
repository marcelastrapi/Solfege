//#pragma once
#ifndef NOTE_H
#define NOTE_H


#include <iostream>
#include <cmath>
#include <string>

#include "NoteName.h"
#include "Interval.h"

#include "../Rnd.h"

///////////////////////
//   LA CLASS NOTE   //
///////////////////////
/** @brief Class Note qui possède un nom une octave (entre 0 et 11) et une fréquence */
class Note {
    //Variables
private:
    NoteName m_nomNote;
    int m_octave;
    double m_frequence;

    //Static constante
    static constexpr unsigned short int NB_NOTES = 7;
    static constexpr double DT = 1.05946; //Demi-ton
    static const bool NOTATION_FRANCAISE = false;
public:
    static  double A4;

    //Constructeurs
public:
    Note();
    Note( const NoteName& nom, int oct = 0 );
    Note( const std::string &strNomNote, int oct = 0 );
    Note( double frequence );

    //copy
    Note( const Note& noteACopier );

    virtual ~Note();

    //Getter
public:
    inline NoteName getNoteName() const {
        return m_nomNote;
    }
    inline int getOctave() const {
        return m_octave;
    }
    inline double getFrequence() const {
        return m_frequence;
    }


    //Setter
public :
    void setNewNote( const NoteName& _nomNote, const int _octave );
    void setNewNote( const Note& nouvelleNote );

    //Fonctions :
public :
    /// \brief Renvoi la Note de l'intervalle superieur ou inferieur
    /// \see operator += operator -=
    inline Note& getNoteFromInterval( const Interval& intervalle, bool superieur = true ) {
        return ( superieur )  ? ( *this += intervalle ) : ( *this -= intervalle ) ;
    }

    //Operator :
public:
    Note& operator=( const Note& noteACopier );
    Note& operator+=( const Interval& interval2Add );
    Note& operator-=( const Interval& interval2Add );
    Note  operator+( const Interval& interval2Add )const ;
    Note  operator-( const Interval& interval2Add )const ;
    Note& addInterval( const Interval& interval2Add, bool montante = true, bool findTheBestNoteMyself = false );
    /// \brief operator== qui ne vérifie que si la note est la bonne hauteur pas le nom
    bool operator==( const Note& noteAVerifier ) {
        return NOTE_TO_INT( *this ) == NOTE_TO_INT( noteAVerifier );
    }

    //Static function
public :
    static short int NB_DT_ENTRE_2_NOTES( const Note& noteA, const Note& noteB ); //Unuse
    //Convertions
    static short int NOTE_TO_INT( const Note& note );
    static Note INT_TO_NOTE( const int numeroNote, const SimpleNotesNames notePrefere = UNKNOWN, const Alterations altPrefere = wtf );
    static std::string NOTE_TO_STRING( const Note& noteQuiVaDevenirUnString );
    static NoteName STRING_TO_NOMNOTE( std::string nomNote );
    static Note FREQ_TO_NOTE( double frequence );
    /// \return random Note between Uint a and Uint b
    static Note RND_NOTE( unsigned short a, unsigned short b );
    /// \return random Note between minNote and maxNote
    static Note RND_NOTE( const Note &minNote = Note( "c", 3 ), const Note &maxNote = Note( "c", 8 ) );


private :
    short int nbDemiTonDepuisA4() const;

    //Sub
public:
    void showInfosNote() const;

private :
    void calculeFrequence();


};


#endif // NOTE_H
