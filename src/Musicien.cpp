#include <Musicien.h>
#include <Rnd.h>
#include <SFML/System/Sleep.hpp>
#include <algorithm>
#include <iterator>

//Ctor
Musicien::Musicien(InstrumentName instrumentName) :
    m_instrumentName(instrumentName)  { }
//Dtor
Musicien::~Musicien() {

}

/**
 * @brief Add note to my internal staff
 * @param const Note& my note to add in my head
 * @param Time the time of the note
 */
void Musicien::add(const Note& note, const sf::Time& timeOfNote) {

    m_notesToPlay.emplace_back( new Instrument( note , timeOfNote , m_instrumentName ) );

}
void Musicien::add(const std::vector<Note>& notes, const sf::Time &timeOfNotes) {

    for ( const Note & note : notes) {
        this->add(note,timeOfNotes);
    }

}
void Musicien::play(bool melodic, bool downToUp) {

    if ( !downToUp ) std::reverse( m_notesToPlay.begin(), m_notesToPlay.end() );

    //Here we play the m_notesToPlayToPlay
    for ( auto  & son : m_notesToPlay ) {
        son->play();
        //Si mélodique alors on fait une pose après chaque note
        if ( melodic ) sf::sleep( son->getTime() );
    }
    //Sinon après avoir lancé toutes les notes
    if ( !melodic ) sf::sleep( m_notesToPlay.back()->getTime() );

}

Musicien& Musicien::randomize(unsigned short beginIndex) {

    unsigned short _size( m_notesToPlay.size() );
    for ( unsigned short i(beginIndex) ; i < _size ; i++ ) {
        unsigned short indexToSwap( Rnd::_int( beginIndex , _size -1 ) );
        std::iter_swap( m_notesToPlay.begin() + i , m_notesToPlay.begin() + indexToSwap );
    }
    return *this;

}

//Setter
void Musicien::setInstrumentName(const InstrumentName newInstrument) {

    if (m_instrumentName != newInstrument) {
        for (auto & son : m_notesToPlay) {

            son->setInstrumentName(newInstrument);
        }
    }

}
