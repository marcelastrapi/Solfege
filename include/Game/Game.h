#pragma once

#include "Solfege/Note.h"
#include "Musicien.h"
#include "Instrument.h"


/// \brief enum of way of the melodic interval
enum Ways {
    down2up = true, ///< bass to high
    up2down = false, ///< hight to bass
    both = 2,    ///< a bit a' both (randomly decided)
};

/// \brief adbstract class game, parent of all game, is the base of the musical game
/// own only global things, don't handl question playing
class Game {

    //Constructor
protected:
    Game( unsigned short nbQuestions = 30 , const sf::Time &timeNote = sf::seconds( 1 ), bool melodic = true, Ways ways = down2up ) :
        m_totalNbOfQuestions(nbQuestions),
        m_currentNumQuestion(0),
        m_goodAnsweres(0),
        m_totalTime(sf::seconds(0)),
        m_melodic(melodic),
        m_ways(ways),
        m_currentWay(up2down),
        m_timeNote(timeNote) { }


    //Subs
    void reStart() {
        m_goodAnsweres = 0;
        m_currentNumQuestion = 0;
        m_totalTime = sf::seconds(0);
    }

    void play() {
//        m_currentQuestion.play(m_melodic,static_cast<bool>(m_currentWay),m_timeNote);
    }

    void showScore() {

        using namespace std;
        cout << "Number of questions  : " << m_totalNbOfQuestions << endl;
        cout << "Good answers : " << m_goodAnsweres << endl;
        cout << "Time : " << std::to_string( calculAverageTime().asMilliseconds()) << endl;

    }

    //Fonctions
    sf::Time calculAverageTime() {
        return sf::milliseconds(  m_totalTime.asMilliseconds() / m_currentNumQuestion   );
    }

    ////////////////
    //Variables
    ////////////////
protected :
    sf::Uint16 m_totalNbOfQuestions;
    sf::Uint16 m_currentNumQuestion; ///< the current number of the question
    sf::Uint16 m_goodAnsweres;

    sf::Time m_totalTime; ///< the addition of the reflection time of the gamer

    Musicien m_currentQuestion; ///< notes being played
    sf::Clock m_clock;

    bool m_melodic;
    Ways m_ways;
    Ways m_currentWay;
    sf::Time m_timeNote;
};


/*
Une fenetre où aficher le jeu
Un jeux c'est un nombre de question qui va de 1 à illimitée
Un score que l'on comptabilise au fur et a mesure.
Un temps de réponse
*/
