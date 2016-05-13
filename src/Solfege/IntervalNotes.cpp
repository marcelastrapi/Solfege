#include "Solfege/IntervalNotes.h"

//Ctor
IntervalNotes::IntervalNotes(const Note& fondamental, const Interval& interName) :
    m_fondamental(fondamental),
    m_interName(interName)  {

    initialise();
}

//private
void IntervalNotes::initialise() {

    m_intervalNotes.push_back( m_fondamental );
    m_intervalNotes.push_back( m_fondamental + m_interName );

}

//Setter
void IntervalNotes::setFondamental(const Note &newFondamental) {
    m_fondamental = newFondamental;
    initialise();
}
void IntervalNotes::setIntervalName(const Interval &newInterName) {
    m_interName = newInterName;
    initialise();
}
