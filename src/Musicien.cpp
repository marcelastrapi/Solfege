#include <Musicien.h>

//Ctor
Musicien::Musicien(Instrument instrument) :
	m_instrument(instrument),
	m_nbNotes(0)  { }

//Dtor
Musicien::~Musicien() {

//	for ( Sound* son : m_notesToPlay) {
//		delete son;
//	}
}


void Musicien::add(const Note& note, const sf::Time& timeOfNote) {

	m_nbNotes++;
	cout << "size : " << m_notesToPlay.size() << endl;
	cout << "nbNotes : " << m_nbNotes << endl;
    m_notesToPlay.push_back( Sound( note , timeOfNote , m_instrument ) );

}
void Musicien::add(const std::vector<Note>& notes, const sf::Time &timeOfNotes) {

	cout << "size : " << m_notesToPlay.size() << endl;

    for ( const Note & note : notes) {
        this->add(note,timeOfNotes);
    }

}
void Musicien::play(bool melodic, bool downToUp) {

    if ( !downToUp ) std::reverse( m_notesToPlay.begin(), m_notesToPlay.end() );

    //Here we play the m_notesToPlayToPlay
    for ( auto  & son : m_notesToPlay ) {
        son.play();
        //Si mélodique alors on fait une pose après chaque note
        if ( melodic ) sf::sleep( son.getTime() );
    }
    //Sinon après avoir lancé toutes les notes (les notes sont donc considéré comme étant toute de time égale
    if ( !melodic ) sf::sleep( m_notesToPlay.back().getTime() );

}
void Musicien::clear() {

//	if ( m_nbNotes > 0 )
//		for (auto son : m_notesToPlay)
//			delete son;

//	if ( ! m_notesToPlay.empty())
//		m_notesToPlay.clear();
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
void Musicien::setInstrument(const Instrument newInstrument) {

    if (m_instrument != newInstrument) {
        for (auto & son : m_notesToPlay) {

            son.setInstrument(newInstrument);

        }
    }

}
