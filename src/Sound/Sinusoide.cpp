#include "Sound/Sinusoide.h"

// -- CONSTRUCTOR --
Sinusoide::Sinusoide( const double frequence, const sf::Time &duree ) :
    MySound( Note( frequence ), duree ), //Call of the parent ctor
    m_raw( nullptr ) {

    m_son = new sf::Sound;
    m_sb = new sf::SoundBuffer;
    initialiseBuffer();
}
Sinusoide::Sinusoide( const Note  &note, const sf::Time &duree ) :
    MySound( note, duree ), //Call of the parent ctor
    m_raw( nullptr ) {

    m_son = new sf::Sound;
    m_sb = new sf::SoundBuffer;
    initialiseBuffer();
}


// -- DESTRUCTOR --
Sinusoide::~Sinusoide() {
    delete[] m_raw;
}


// --------------------- Fonctions publics --------------

// -- reloadBuffer
void Sinusoide::reloadBuffer( const Note& note, const  sf::Time& _duree ) {
    delete m_son;
    m_son = new sf::Sound;
    delete m_sb;
    m_sb = new sf::SoundBuffer;
    delete[] m_raw;

    setNote( note );
    setTime( _duree );

    initialiseBuffer();
}
void Sinusoide::reloadBuffer( const  double _frequence, const sf::Time& _duree ) {

    setNote( Note( _frequence ) );
    setTime( _duree );

    delete m_son;
    m_son = new sf::Sound;
    delete m_sb;
    m_sb = new sf::SoundBuffer;
    delete[] m_raw;

    initialiseBuffer();
}

//Getter
void Sinusoide::showRaw( int nbElem ) const {
    for ( int i( 0 ); i < nbElem; i++ ) {
        std::cout << m_raw[i] << std::endl;
    }
}
void Sinusoide::showInfosSinusoide() const {
    m_note.showInfosNote();
    showRaw( 10 );
}


// --------------------- Sub et Fonctions privée ----------------
void Sinusoide::initialiseBuffer() {

    fillArray();

    //Je remplis le buffer
    if ( !m_sb->loadFromSamples( m_raw, getSamples(), 1, SAMPLE_RATE ) ) {
        std::cout << "Loading failed !" << std::endl;
    }

    m_son->setBuffer( *m_sb );
    m_son->setVolume( 10 );
}

void Sinusoide::fillArray() {

    //Pour définir SAMPLES, je dois déterminé la temps d'une periode
    unsigned int samples = getSamples();

    m_raw = new sf::Int16[samples];

    const double increment = getFrequence() / SAMPLE_RATE;
    double x( 0 );

    float widthOfRampInPercent = ( samples < 8820 ) ? .4f : .1f;
    float ramp( samples * widthOfRampInPercent );
    float attenuation( 0 );

    //Pente montante
    for ( unsigned i ( 0 ); i < ramp; i++ ) {
        m_raw[i] = AMPLITUDE * attenuation * sin( x * TWO_PI ) ;
        x += increment;
        attenuation = ( ( float )i / ramp );
    }
    for ( unsigned i ( ramp ); i < samples - ramp; i++ ) {
        m_raw[i] = AMPLITUDE * sin( x * TWO_PI ) ;
        x += increment;
    }
    //Pente descendante
    for ( unsigned i ( samples - ramp ); i < samples ; i++ ) {
        m_raw[i] = AMPLITUDE * attenuation * sin( x * TWO_PI ) ;
        x += increment;
        attenuation = ( samples - i ) / ramp ;
    }
}

