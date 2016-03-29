#include "Solfege/Interval.h"

//Ctor
Interval::Interval(const std::string& strNote, int _octave, const IntervalName& interName) :
    Notes(),
    m_fondamental(Note(strNote,_octave)),
    m_interName(interName) {

    initialise();
}
Interval::Interval(const Note& fondamental, const IntervalName& interName) :
    Notes(),
    m_fondamental(fondamental),
    m_interName(interName) {

    initialise();
}
//private
void Interval::initialise() {

    this->add( m_fondamental );
    this->add( m_fondamental + m_interName );

}

//Setter
void Interval::setFondamental(const Note &newFondamental) {
    m_fondamental = newFondamental;
    initialise();
}
void Interval::setIntervalName(const IntervalName &newInterName) {
    m_interName = newInterName;
    initialise();
}
