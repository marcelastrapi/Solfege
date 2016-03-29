#pragma once

#include <SFML/Audio.hpp>

#include "../Solfege/Note.h"

class MySound {
    //Member Data
protected :
    Note m_note;
    sf::Time m_time;
    sf::SoundBuffer *m_sb;
    sf::Sound *m_son;

public:
    MySound() : m_note(Note(UNKNOWN)), m_time(sf::seconds(1)) ,  m_sb( nullptr ), m_son( nullptr ) { }
    MySound( const Note& note, const sf::Time& time ) : m_note( note ), m_time( time ), m_sb( nullptr ), m_son( nullptr ) {
        m_son = new sf::Sound ;
        m_sb = new sf::SoundBuffer;
    }

    //Dtor
    virtual ~MySound() {
        delete m_sb;
        delete m_son;
    }

public :
    //Fonctions de jeu du m_son
    inline void play() {
        if ( m_son->getBuffer() != nullptr ) m_son->play();
    }
    inline void stop() {
        m_son->stop();
    }
    inline void pause() {
        if ( m_son->getStatus() == sf::Sound::Playing ) m_son->pause();
    }

    //Getter
    inline sf::SoundBuffer& getBuffer()    const {
        return *m_sb;
    }
    inline sf::Sound&       getSound()     const {
        return *m_son;
    }
    inline sf::Time         getTime()     const {
        return m_time;
    }
    inline double          getFrequence() const {
        return m_note.getFrequence() ;
    }
    inline Note             getNote() const {
        return m_note;
    }
    inline float           getVolume() const {
        return m_son->getVolume();
    }

    //Setter
    /// \brief Set the volume of the sound between 0 (mute) and 100 qui déchir un peu....
    /// Initialisé à 10....
    /// \param volume entre 0 et 100
    inline void setVolume( float volume ) {
        m_son->setVolume( volume );
    }
    inline void setNote(const Note &newNote) { m_note = newNote;}
    inline void setTime(const sf::Time &newTime ) { m_time = newTime; }

    //VIRTUAL PURE !!!
//    virtual void initialiseBuffer() = 0;
};
