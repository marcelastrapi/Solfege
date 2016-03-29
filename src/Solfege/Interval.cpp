#include "Solfege/Interval.h"

//Ctor
Interval::Interval(const Note& fondamental, const IntervalName& interName, const sf::Time &time,const  InstrumentName instrument) :
    Musicien(instrument),
    m_fondamental(fondamental),
    m_interName(interName) ,
    m_time(time) {

    initialise();
}
//private
void Interval::initialise() {

    this->add( m_fondamental , m_time );
    this->add( m_fondamental + m_interName , m_time);

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
