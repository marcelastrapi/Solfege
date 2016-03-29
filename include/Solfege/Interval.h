#ifndef INTERVAL_H
#define INTERVAL_H

#include "Musicien.h"

class Interval : public Musicien {
    //Variables:
private :
    Note m_fondamental;
    IntervalName m_interName;
    sf::Time m_time;

    //Constructors
public:
    Interval( const Note &fondamental, const  IntervalName &interName, const sf::Time &time, InstrumentName instrument = Sinusoide );
private:
    void initialise();

    //Getter
public:
    inline Note getFondamental() const { return m_fondamental; }
    inline IntervalName getIntervalName() const { return m_interName; }

    //Setter
    void setFondamental(const Note &newFondamental);
    void setIntervalName(const IntervalName &newInterName);

};

#endif
