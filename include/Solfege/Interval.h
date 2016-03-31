#pragma once

#include <ostream>
#include <vector>

#include "NoteName.h"
#include "../Rnd.h"

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
class Interval  {
    //Variables
private:
    SimpleIntervalsNames m_intervalName;
    IntervalsQualifications m_intervalQualification;

    //Constructor
public:
    Interval() : m_intervalName( nopenopenope ), m_intervalQualification( majeur ) {}
    Interval( SimpleIntervalsNames nomI, IntervalsQualifications qI ) :
        m_intervalName( nomI ), m_intervalQualification( qI )  { }

    //Getter
    inline SimpleIntervalsNames getIntervalName() const {
        return m_intervalName;
    }
    inline IntervalsQualifications getIntervalQualification() const {
        return m_intervalQualification;
    }

    //Setter
    Interval& setIntervalQualification( IntervalsQualifications newQualif ) {
        m_intervalQualification = newQualif ;
        return *this ;
    }
    Interval& setIntervalName( SimpleIntervalsNames newInter ) {
        m_intervalName = newInter;
        return *this;
    }
    Interval& setInterval( SimpleIntervalsNames name, IntervalsQualifications qualif ) {
        m_intervalName = name;
        m_intervalQualification = qualif;
        return *this;
    }

    //Fonctions
public:
    /// \return number of semi-tones that constitute the Interval
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
    static Interval RND_INTERVAL( const std::vector<SimpleIntervalsNames> &possibleInters, bool onlyJuste = true, bool onlyMajeurMineur = true ) {

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

        return Interval(rndName,rndQual);

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
        case d:
            return  re;
        case e:
            return  mi;
        case f:
            return  fa;
        case g:
            return  sol;
        case a:
            return  la;
        case b:
            return  si;
        default:
            return unknown;
        }
    }
    SimpleNotesNames NomsTps_TO_NomsSimplesNotes( const NomsTps nomNote ) const {
        switch ( nomNote ) {
        case ut:
            return  c;
        case re:
            return  d;
        case mi:
            return  e;
        case fa:
            return  f;
        case sol:
            return  g;
        case la:
            return  a;
        case si:
            return  b;
        default:
            return UNKNOWN;
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

