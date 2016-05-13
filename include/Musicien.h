/*Produce Sounds*/

#pragma once

#include <Sound.h>
#include <Solfege/Note.h>
#include <Rnd.h>

#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>

#include <vector>

#include <iostream>
using std::cout; using std::endl;


/// \brief Class qui prend des notes et les joue avec le Sound voulue
class  Musicien  {

    //Ctor
public :
    Musicien( const Instrument instrument = Sinusoide );

    //Dtor
    ~Musicien();

    void add(const Note &note, const sf::Time& timeOfNote = sf::seconds( 1 ) );
    void add(const std::vector<Note> & notes, const sf::Time &timeOfNotes = sf::seconds( 1 ) );

    void play( bool melodic = true, bool downToUp = true);

    void clear(); ///< clear the notes in (t)his head

    /// \brief randomize the order of the notes in his head
    Musicien& randomize( unsigned short beginIndex = 0 );

    inline void showInfosNotes() {

        for (auto const & son : m_notesToPlay ) son.getNote().showInfosNote();

    }

    //Setter
    void setInstrument(const Instrument newInstrument);

//Variable
private :
    Instrument m_instrument;
    std::vector<Sound> m_notesToPlay;
    unsigned short int m_nbNotes;


};


