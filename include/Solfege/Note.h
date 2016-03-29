//#pragma once
#ifndef NOTE_H
#define NOTE_H


#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "Rnd.h"


//NOTE NAME
enum SimpleNotesNames  {
    c = 0,
    d = 2,
    e = 4,
    f = 5,
    g = 7,
    a = 9,
    b = 11,
    UNKNOWN = -1///< Note unknown
};
enum Alterations {
    ees = -2,
    es = -1,
    NONE = 0,
    is = 1,
    iis = 2,
    wtf = -1000 ///< this alteration does not exist
};
class  NoteName {
    //Variables
public:
    SimpleNotesNames nomNote;
    Alterations alteration;

    //Construteur
public :
    NoteName():  nomNote( UNKNOWN ), alteration( NONE ) {}
    NoteName( SimpleNotesNames nom, Alterations alt = NONE ) : nomNote( nom ), alteration( alt ) {}
    //Copie
    NoteName( const NoteName& noteACopier ) :  nomNote( noteACopier.nomNote ), alteration( noteACopier.alteration ) {}
    NoteName& operator=( const NoteName& noteACopier ) {
        nomNote = noteACopier.nomNote;
        alteration = noteACopier.alteration;
        return *this;
    }
};

//INTERVAL
enum SimpleIntervalsNames  {
    unisson = 0,
    seconde = 2,
    tierce = 4,
    quarte = 5,
    quinte = 7,
    sixte = 9,
    septieme = 11,
    octave = 12,
    neuvieme = 14,
    dixieme = 16,
    onzieme = 17,
    douzieme = 18,
    treizieme = 20,
    nopenopenope = -1

};
enum IntervalsQualifications  {
    mineurDiminue = -2, ///< diminue for seconde tierce sixte septieme
    mineur = -1, diminue = -1,
    majeur = 0, juste = 0,
    augmente = +1
};
class IntervalName  {
    //Variables
private:
    SimpleIntervalsNames m_intervalName;
    IntervalsQualifications m_intervalQualification;

    //Constructor
public:
    IntervalName() : m_intervalName( nopenopenope ), m_intervalQualification( majeur ) {}
    IntervalName( SimpleIntervalsNames nomI, IntervalsQualifications qI ) :
        m_intervalName( nomI ), m_intervalQualification( qI )  { }

    //Getter
    inline SimpleIntervalsNames getIntervalName() const {
        return m_intervalName;
    }
    inline IntervalsQualifications getIntervalQualification() const {
        return m_intervalQualification;
    }

    //Setter
    IntervalName& setIntervalQualification( IntervalsQualifications newQualif ) {
        m_intervalQualification = newQualif ;
        return *this ;
    }
    IntervalName& setIntervalName( SimpleIntervalsNames newInter ) {
        m_intervalName = newInter;
        return *this;
    }
    IntervalName& setInterval( SimpleIntervalsNames name, IntervalsQualifications qualif ) {
        m_intervalName = name;
        m_intervalQualification = qualif;
        return *this;
    }

    //Foncitons
public:
    inline short int getNbDemiTons() const {
        return static_cast<short int>( m_intervalName ) +
               static_cast<short int>( m_intervalQualification );
    }
    /// \brief Donne le nom de la note d'après l'intervalle
    ///
    /// \param note const NoteName& le nom de la note
    /// \param true bool montante
    /// \return SimpleNotesNames le nom necessaire à la bonne intervalle à utiliser with INT_TO_NOTE
    ///
    SimpleNotesNames getNoteNameFromInterval( const NoteName& note, bool montante = true )const {

        NomsTps nomTps( NomsSimplesNotes_TO_NomsTps( note.nomNote ) );
        IntervallesTps intervalleTps( NomsIntervalles_TO_IntervallesTps( m_intervalName ) );

        SimpleNotesNames rep;
        short int numNom = static_cast<short int>( nomTps ) ;
        short int numInter = static_cast<short int>( intervalleTps );


        short int res;
        if ( montante ) {
            res = ( numNom + numInter ) % 7;
            rep = NomsTps_TO_NomsSimplesNotes( static_cast<NomsTps>( res ) );
        } else {
            res = ( numNom - numInter );
            //Modulo perso parce que bon hein...y en a marre !
            res = ( res > 6 ) ? res - 6 : res;
            res = ( res < 0 ) ? res + 7 : res;
            rep = NomsTps_TO_NomsSimplesNotes( static_cast<NomsTps>( res ) );
        }
        return rep;
    }

    void showInfos() {

        std::cout << "Numeros interval : " << std::to_string( NomsIntervalles_TO_IntervallesTps( m_intervalName ) ) << std::endl;
        std::cout << "Qualification : " << std::to_string( m_intervalQualification ) << std::endl;

    }

    //Rnd
    static IntervalName RND_INTERVAL_NAME( const std::vector<SimpleIntervalsNames> &possibleInters, bool onlyJuste = true, bool onlyMajeurMineur = true ) {

        SimpleIntervalsNames rndName( possibleInters.at(  Rnd::_int(possibleInters.size()-1)  ) );

        int minQual(-1);
        int maxQual(1);

        //Now I find the qualification
        switch (rndName) {
        case seconde:
        case tierce:
        case sixte:
        case septieme:
        case neuvieme:
        case dixieme:
        case treizieme:
            minQual = ( onlyMajeurMineur ) ? -1 : -2; //mineur ou diminue ET mineur
            maxQual = ( onlyMajeurMineur ) ?  0 : +1;   // majeur ou majeur ET augmente
            break;
        default :
            minQual = ( onlyJuste ) ? 0 : -1; //Juste ou diminué ET juste
            maxQual = ( onlyJuste ) ? 0 : +1; //Juste ou juste ET augmente
        }

        IntervalsQualifications rndQual( static_cast<IntervalsQualifications>( Rnd::_int(minQual , maxQual ) ) );

        return IntervalName(rndName,rndQual);

    }

private :
    //Grosse loosedé pour pouvoir ajouter les notes a des noms d'intervalle pour avoir le bon nom de note en fonction de l'intervalle voulue
    enum NomsTps :  short {
        ut, re, mi, fa, sol, la, si, unknown = -1
    };
    enum IntervallesTps : short  {
        uni, sec, tie, qua, quin, six, sept, oct, neuv, dix, onze, douze, treize, nopenope = -1
    };
    NomsTps NomsSimplesNotes_TO_NomsTps( const SimpleNotesNames nomNote ) const {
        switch ( nomNote ) {
        case c:
            return  ut;
            break;
        case d:
            return  re;
            break;
        case e:
            return  mi;
            break;
        case f:
            return  fa;
            break;
        case g:
            return  sol;
            break;
        case a:
            return  la;
            break;
        case b:
            return  si;
            break;
        default:
            return unknown;
            break;
        }
    }
    SimpleNotesNames NomsTps_TO_NomsSimplesNotes( const NomsTps nomNote ) const {
        switch ( nomNote ) {
        case ut:
            return  c;
            break;
        case re:
            return  d;
            break;
        case mi:
            return  e;
            break;
        case fa:
            return  f;
            break;
        case sol:
            return  g;
            break;
        case la:
            return  a;
            break;
        case si:
            return  b;
            break;
        default:
            return UNKNOWN;
            break;
        }
    }
    static IntervallesTps NomsIntervalles_TO_IntervallesTps( const SimpleIntervalsNames nomInter ) {
        switch ( nomInter ) {
        case unisson :
            return uni;
        case seconde:
            return sec ;
        case tierce:
            return tie ;
        case quarte:
            return qua ;
        case quinte:
            return quin ;
        case sixte:
            return six ;
        case septieme:
            return sept ;
        case octave:
            return oct ;
        case neuvieme:
            return neuv ;
        case dixieme :
            return dix ;
        case onzieme :
            return onze ;
        case douzieme :
            return douze ;
        case treizieme :
            return treize ;
        default:
            return nopenope;
        }
    }
    static SimpleIntervalsNames IntervallesTps_TO_NomsIntervalles( const IntervallesTps inter ) {
        switch ( inter ) {
        case uni:
            return unisson;
        case sec:
            return seconde ;
        case tie:
            return tierce ;
        case qua:
            return quarte ;
        case quin:
            return quinte ;
        case six:
            return sixte ;
        case sept:
            return septieme ;
        case oct:
            return octave ;
        case neuv:
            return neuvieme;
        case dix:
            return dixieme;
        case onze:
            return onzieme;
        case douze:
            return douzieme;
        case treize:
            return treizieme;
        default:
            return nopenopenope;
        }
    }

};



///////////////////////
//   LA CLASS NOTE   //
///////////////////////
/// \brief Class Note qui possède un nom une octave (entre 0 et 11) et une fréquence
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
    Note ( std::string strNomNote, int oct = 0 );
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
    inline Note& getNoteFromInterval( const IntervalName& intervalle, bool superieur = true ) {
        return ( superieur )  ? ( *this += intervalle ) : ( *this -= intervalle ) ;
    }

    //Operator :
public:
    Note& operator=( const Note& noteACopier );
    Note& operator+=( const IntervalName& interval2Add );
    Note& operator-=( const IntervalName& interval2Add );
    Note  operator+( const IntervalName& interval2Add )const ;
    Note  operator-( const IntervalName& interval2Add )const ;
    Note& addInterval( const IntervalName& interval2Add, bool montante = true, bool findTheBestNoteMyself = false );
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
    static NoteName STRING_TO_NOMNOTE( std::string& nomNote );
    static Note FREQ_TO_NOTE( double frequence );
    /// \return random Note between a and b
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
