/*Produce Sounds*/

#pragma once

#include <SFML/Audio.hpp>

#include "Solfege/Note.h"
#include <cmath>

enum Instrument {
    Sinusoide
    //Piano , violon ...
};

///Brief class who play sound of the chosen instrument
class Sound {

    //Ctor
public:
    Sound();
    Sound( const Note &note, const sf::Time &time , Instrument instrument = Sinusoide);

    //Dtor
    virtual ~Sound();


public :
    //Fonctions de jeu du m_son
    inline void play() {
        if ( m_son.getBuffer() != nullptr ) m_son.play();
    }
    inline void stop() {
        m_son.stop();
    }
    inline void pause() {
        if ( m_son.getStatus() == sf::Sound::Playing ) m_son.pause();
    }

    //Getter
    inline sf::SoundBuffer getBuffer()    const {
        return m_sb;
    }
    inline sf::Sound       getSound()     const {
        return m_son;
    }
    inline sf::Time        getTime()     const {
        return m_time;
    }
    inline double          getFrequence() const {
        return m_note.getFrequence() ;
    }
    inline Note            getNote() const {
        return m_note;
    }
    inline float           getVolume() const {
        return m_son.getVolume();
    }

    //Setter
    /// \brief Set the volume of the sound between 0 (mute) and 100 qui déchir un peu....
    /// Initialisé à 10....
    /// \param volume entre 0 et 100
    inline void setVolume( float volume ) {
        m_son.setVolume( volume );
    }
    void setNote(const Note &newNote);
    void setTime(const sf::Time &newTime );
    void setInstrument(const Instrument newInstrument);

private :
    /// \brief Initialise the sound_buffer, depending of the instrument choosen
    void initialiseBuffer();

    //Only for Sinusoide
    void fillArray();
    inline sf::Int32 getSamples() { return m_time.asSeconds()* SAMPLE_RATE; }


    //////////////////
    //Member Data
    /////////////////
private :
    Note m_note;
    sf::Time m_time;
    Instrument m_instrument;
    sf::SoundBuffer m_sb;
    sf::Sound m_son;
    sf::Int16 *m_raw;

    static const unsigned SAMPLE_RATE = 44100;
    static const unsigned AMPLITUDE = 30000;
    static constexpr double TWO_PI = 6.28318;
};
