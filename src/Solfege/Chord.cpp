#include <Solfege/Chord.h>

//Ctor
Chord::Chord( const Note& fondamental, const ChordsNames &chordName,const sf::Time &time, const InstrumentName instrument) :
    Musicien(instrument),
    m_fondamental( fondamental ),
    m_chordName( chordName ),
    m_time(time) {

    initialise();
}
//private
void Chord::initialise() {

    switch( m_chordName ) {
    case maj:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        break;
    case maj5Dim7Min:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, diminue )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, mineur )  , m_time );
        break;
    case maj5Aug:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        break;
    case maj5Aug7Min:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, augmente )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( neuvieme, mineur )  , m_time );
        break;
    case maj5Dim:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, diminue )  , m_time );
        break;
    case maj7Min:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, mineur )  , m_time );
        break;
    case maj7Min9Maj:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( neuvieme, majeur )  , m_time );
        break;
    case maj7Maj:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add(  m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add(  m_fondamental + IntervalName( septieme, majeur ) ) ;
        break;
    case maj7Maj9Maj:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( neuvieme, majeur )  , m_time );
        break;
    case maj7Maj9Aug:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( neuvieme, augmente )  , m_time );
        break;
    case maj7Maj9Dim:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( neuvieme, diminue )  , m_time );
        break;
    case majAdd2:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( seconde, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        break;
    case majAdd4:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quarte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        break;
    case maj6Maj:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( sixte, majeur )  , m_time );
        break;
    case maj6Maj9Maj:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( sixte, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( neuvieme, majeur )  , m_time );
        break;
//                          ////////////////////////////
//                          //    ACCORDS MINEURS     //
//                          ////////////////////////////
    case minor:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        break;
    case min5Dim:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, diminue )  , m_time );
        break;
    case min5Dim7Min:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, diminue )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, mineur )  , m_time );
        break;
    case min5Dim7Dim:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, diminue )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, diminue )  , m_time );
        break;
    case min7Min:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, mineur )  , m_time );
        break;
    case min7Min9Maj:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( neuvieme, majeur )  , m_time );
        break;
    case min7Maj:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( septieme, majeur )  , m_time );
        break;
    case minAdd2:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( seconde, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        break;
    case minAdd4:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quarte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        break;
    case min6Maj:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( sixte, majeur )  , m_time );
        break;
    case min6Maj9Maj:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( tierce, mineur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( sixte, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( neuvieme, majeur )  , m_time );
        break;

    case sus2:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( seconde, majeur )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        break;
    case sus4:
        this->add( m_fondamental , m_time );
        this->add( m_fondamental + IntervalName( quarte, juste )  , m_time );
        this->add( m_fondamental + IntervalName( quinte, juste )  , m_time );
        break;

    }


}

//Setter
void Chord::setFondamental(const Note &newFondamental) {
    m_fondamental = newFondamental;
    initialise();
}
void Chord::setChordName(const ChordsNames &newChordName) {
    m_chordName = newChordName;
    initialise();
}

