/*Produce Sounds*/

#pragma once

#include <Instrument.h>
#include <SFML/System/Time.hpp>
#include <Solfege/Note.h>
#include <memory>
#include <vector>


/// \brief Class qui prend des notes et les joue avec l'instrument voulue
class  Musicien  {

    //Ctor
public :
    Musicien( const InstrumentName instrumentName = Sinusoide );

    //Dtor
    ~Musicien();

    void add(const Note &note, const sf::Time& timeOfNote = sf::seconds( 1 ) );
    void add(const std::vector<Note>& notes, const sf::Time &timeOfNotes = sf::seconds( 1 ) );

    void play( bool melodic = true, bool downToUp = true);

    /// \brief randomize the order of the notes in his head
    Musicien& randomize( unsigned short beginIndex = 0 );

    inline void showInfosNotes() {

        for (auto const & son : m_notesToPlay ) son->getNote().showInfosNote();

    }


    //Setter
    void setInstrumentName(const InstrumentName newInstrument);

//Variable
private :
    InstrumentName m_instrumentName;
    std::vector< std::unique_ptr<Instrument> > m_notesToPlay;


};


