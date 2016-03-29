#ifndef INTERVAL_H
#define INTERVAL_H

#include "Notes.h"

class Interval : public Notes {
    //Variables:
private :
    Note m_fondamental;
    IntervalName m_interName;

    //Constructors
public:
    Interval( const Note &fondamental, const  IntervalName &interName );
    Interval( const std::string &strNote, int _octave, const IntervalName &interName );
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
