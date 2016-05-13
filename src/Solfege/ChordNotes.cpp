#include "Solfege/ChordNotes.h"

//Ctor
ChordNotes::ChordNotes( const Note& fondamental, const ChordsNames &chordName) :
    m_fondamental( fondamental ),
    m_chordName( chordName ) {

    initialise();
}
//private
void ChordNotes::initialise() {

    switch( m_chordName ) {
    case maj:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        break;
    case maj5Dim7Min:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, diminue ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, mineur ) );
        break;
    case maj5Aug:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        break;
    case maj5Aug7Min:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, augmente ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( neuvieme, mineur ) );
        break;
    case maj5Dim:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, diminue ) );
        break;
    case maj7Min:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, mineur ) );
        break;
    case maj7Min9Maj:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( neuvieme, majeur ) );
        break;
    case maj7Maj:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back(  m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back(  m_fondamental + Interval( septieme, majeur ) ) ;
        break;
    case maj7Maj9Maj:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( neuvieme, majeur ) );
        break;
    case maj7Maj9Aug:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( neuvieme, augmente ) );
        break;
    case maj7Maj9Dim:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( neuvieme, diminue ) );
        break;
    case majAdd2:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( seconde, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        break;
    case majAdd4:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quarte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        break;
    case maj6Maj:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( sixte, majeur ) );
        break;
    case maj6Maj9Maj:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( sixte, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( neuvieme, majeur ) );
        break;
//                          ////////////////////////////
//                          //    ACCORDS MINEURS     //
//                          ////////////////////////////
    case minor:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        break;
    case min5Dim:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, diminue ) );
        break;
    case min5Dim7Min:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, diminue ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, mineur ) );
        break;
    case min5Dim7Dim:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, diminue ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, diminue ) );
        break;
    case min7Min:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, mineur ) );
        break;
    case min7Min9Maj:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( neuvieme, majeur ) );
        break;
    case min7Maj:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( septieme, majeur ) );
        break;
    case minAdd2:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( seconde, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        break;
    case minAdd4:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quarte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        break;
    case min6Maj:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( sixte, majeur ) );
        break;
    case min6Maj9Maj:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( tierce, mineur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( sixte, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( neuvieme, majeur ) );
        break;

    case sus2:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( seconde, majeur ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        break;
    case sus4:
        m_chordNotes.push_back( m_fondamental );
        m_chordNotes.push_back( m_fondamental + Interval( quarte, juste ) );
        m_chordNotes.push_back( m_fondamental + Interval( quinte, juste ) );
        break;

    }


}

//Setter
void ChordNotes::setFondamental( const Note &newFondamental ) {
    m_fondamental = newFondamental;
    initialise();
}
void ChordNotes::setChordName( const ChordsNames &newChordName ) {
    m_chordName = newChordName;
    initialise();
}

//STATIC
ChordNotes ChordNotes::RND_CHORD(unsigned short int numberOfNotes, bool exactNumberOfNotes) {

	//Je détermine quelles sont les chordNames qui conviennent au numberOfNotes voulue SI voulue
	int a(0),b(6);
	switch (numberOfNotes) {
		case 4:
			a = (exactNumberOfNotes) ? 7 : 0;
			b = 20;
			break;
		case 5:
			a = (exactNumberOfNotes) ? 21 : 0;
			b = 27;
			break;
	}
	int rndChordName( Rnd::_int(a,b) );

	return ChordNotes( Note::RND_NOTE() , static_cast<ChordsNames>(rndChordName) );


}
ChordNotes ChordNotes::RND_CHORD_IN_SCALE(const Note & fondamental) {


}
