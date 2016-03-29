#pragma once

#include "Game.h"

/// \brief Game who's got the purspose to learn recognize melodic and harmonic interval (only 2 notes)
//template<class T>
class GameInterval : public Game {
//Variable
private:
    std::vector<SimpleIntervalsNames> m_listOfInter;


public:
    //Constructor
    GameInterval( unsigned short nbQuestions, const std::vector<SimpleIntervalsNames> &listOfPossibleIntervals, const sf::Time &timeNote = sf::seconds( 1 ), bool melodic = true, Ways ways = down2up );


    //Jeux
    bool newQuestion();

    void repeatQuestion();

    bool checkAnswere( const IntervalName &answere );

    void getAnswere();

private :
    IntervalName rndInter();
    void finish();

};

#include "../../src/Games/GameInterval.cpp"

