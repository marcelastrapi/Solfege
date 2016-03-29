#ifndef NOTES_H
#define NOTES_H

#include <SFML/Audio.hpp>
#include <vector>
#include <algorithm>
#include <memory>

#include "Note.h"
#include "../Sound/Sinusoide.h"


/// \brief Notes est une struc qui est le parent de Scale et Chord
/// Ajoute de la fléxibilité pour pouvoir gérer une liste de note comme randomize,play
//template <class TSound>
class  Notes  {
public :

    void add(const Note &note, const sf::Time& timeOfNote = sf::seconds( 1 ) ) {

        m_notes.push_back(note);
        m_notesSounds.emplace_back( new Sinusoide(note, timeOfNote ) );

        //Pas de partition à afficher pour l'instant... Rien du tout :/  C'est pour bientot :)


    }

    void play( bool melodic = true, bool downToUp = true) {


        if ( !downToUp ) std::reverse( m_notesSounds.begin(), m_notesSounds.end() );

        //Here we play the m_notesSounds
        for ( auto const & son : m_notesSounds ) {
            son->play();
            //Si mélodique alors on fait une pose après chaque note
            if ( melodic ) sf::sleep( son->getTime() );
        }
        //Sinon après avoir lancé toutes les notes
        if ( !melodic ) sf::sleep( m_notesSounds.back()->getTime() );

    }

    /// \brief randomize the order of Notes inside it
    Notes& randomize( unsigned short beginIndex = 0 ) {

        unsigned short _size( m_notes.size() );
        for ( unsigned short i(beginIndex) ; i < _size ; i++ ) {
            unsigned short indexToSwap( Rnd::_int( beginIndex , _size -1 ) );
//            if (indexToSwap != i) //Not useful ? maybe for a little time winning
                std::iter_swap( m_notes.begin() + i , m_notes.begin() + indexToSwap );
                std::iter_swap( m_notesSounds.begin() + i , m_notesSounds.begin() + indexToSwap );
        }
        return *this;
    }

    inline void showInfosNotes() {

        for (auto const & note : m_notes ) note.showInfosNote();

    }

    inline Note rndNoteFromMe() {

        return m_notes.at(Rnd::_int(m_notes.size()-1));

    }

//Variable
private :
std::vector<Note> m_notes;
std::vector< std::unique_ptr<Sinusoide> > m_notesSounds;


};


#endif // NOTES_H

