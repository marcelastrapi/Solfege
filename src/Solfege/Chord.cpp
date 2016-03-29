#include <Solfege/Chord.h>

//Ctor
Chord::Chord( const std::string& strNote, int _octave, const ChordsNames &chordName ) :
    Notes(),
    m_fondamental( Note( strNote, _octave ) ),
    m_chordName( chordName) {

    initialise();
}
Chord::Chord( const Note& fondamental, const ChordsNames &chordName) :
    Notes(),
    m_fondamental( fondamental ),
    m_chordName( chordName ) {

    initialise();
}
//private
void Chord::initialise() {

    switch( m_chordName ) {
    case maj:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        break;
    case maj5Dim7Min:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, diminue )  );
        this->add( m_fondamental + IntervalName( septieme, mineur )  );
        break;
    case maj5Aug:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        break;
    case maj5Aug7Min:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, augmente )  );
        this->add( m_fondamental + IntervalName( septieme, mineur )  );
        this->add( m_fondamental + IntervalName( neuvieme, mineur )  );
        break;
    case maj5Dim:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, diminue )  );
        break;
    case maj7Min:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( septieme, mineur )  );
        break;
    case maj7Min9Maj:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( septieme, mineur )  );
        this->add( m_fondamental + IntervalName( neuvieme, majeur )  );
        break;
    case maj7Maj:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add(  m_fondamental + IntervalName( quinte, juste )  );
        this->add(  m_fondamental + IntervalName( septieme, majeur ) ) ;
        break;
    case maj7Maj9Maj:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( septieme, majeur )  );
        this->add( m_fondamental + IntervalName( neuvieme, majeur )  );
        break;
    case maj7Maj9Aug:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( septieme, majeur )  );
        this->add( m_fondamental + IntervalName( neuvieme, augmente )  );
        break;
    case maj7Maj9Dim:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( septieme, majeur )  );
        this->add( m_fondamental + IntervalName( neuvieme, diminue )  );
        break;
    case majAdd2:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( seconde, majeur )  );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        break;
    case majAdd4:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quarte, juste )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        break;
    case maj6Maj:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( sixte, majeur )  );
        break;
    case maj6Maj9Maj:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( sixte, majeur )  );
        this->add( m_fondamental + IntervalName( neuvieme, majeur )  );
        break;
//                          ////////////////////////////
//                          //    ACCORDS MINEURS     //
//                          ////////////////////////////
    case minor:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        break;
    case min5Dim:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quinte, diminue )  );
        break;
    case min5Dim7Min:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quinte, diminue )  );
        this->add( m_fondamental + IntervalName( septieme, mineur )  );
        break;
    case min5Dim7Dim:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quinte, diminue )  );
        this->add( m_fondamental + IntervalName( septieme, diminue )  );
        break;
    case min7Min:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( septieme, mineur )  );
        break;
    case min7Min9Maj:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( septieme, mineur )  );
        this->add( m_fondamental + IntervalName( neuvieme, majeur )  );
        break;
    case min7Maj:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( septieme, majeur )  );
        break;
    case minAdd2:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( seconde, majeur )  );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        break;
    case minAdd4:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quarte, juste )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        break;
    case min6Maj:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( sixte, majeur )  );
        break;
    case min6Maj9Maj:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( tierce, mineur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        this->add( m_fondamental + IntervalName( sixte, majeur )  );
        this->add( m_fondamental + IntervalName( neuvieme, majeur )  );
        break;

    case sus2:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( seconde, majeur )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
        break;
    case sus4:
        this->add( m_fondamental );
        this->add( m_fondamental + IntervalName( quarte, juste )  );
        this->add( m_fondamental + IntervalName( quinte, juste )  );
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

