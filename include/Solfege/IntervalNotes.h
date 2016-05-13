#pragma once

#include <Solfege/Interval.h>
#include <Solfege/Note.h>
#include <vector>

class IntervalNotes {
    //Variables:
private :
    Note m_fondamental;
    Interval m_interName;
    std::vector<Note> m_intervalNotes;

    //Constructors
public:
    IntervalNotes( const Note &fondamental, const  Interval &interName);
private:
    void initialise();

    //Getter
public:
    inline Note getFondamental() const { return m_fondamental; }
    inline Interval getIntervalName() const { return m_interName; }
    inline std::vector<Note> getNotes() const { return m_intervalNotes; }

    //Setter
    void setFondamental(const Note &newFondamental);
    void setIntervalName(const Interval &newInterName);

};

