#include "Musicien.h"

//Ctor
Musicien::Musicien(InstrumentName instrumentName) :
    m_instrumentName(instrumentName)  { }
//Dtor
Musicien::~Musicien() {

}

void Musicien::add(const Note& note, const sf::Time& timeOfNote) {

    m_notesToPlay.emplace_back( new Instrument( note , timeOfNote , m_instrumentName ) );

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
void Musicien::setInstrumentName(InstrumentName newInstrument) {

    for (auto & son : m_notesToPlay) {

        son->setInstrumentName(newInstrument);
    }

}
