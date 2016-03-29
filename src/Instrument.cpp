#include "Instrument.h"

// -- CONSTRUCTOR --
Instrument::Instrument() :
    m_note( Note("c",0) ),
    m_time( sf::seconds( 1 ) ),
    m_instrumentName( Sinusoide ),
//    m_sb( nullptr ),
//    m_son( nullptr ),
    m_raw( nullptr ) {

//        m_sb = new sf::SoundBuffer;
//        m_son = new sf::Sound;
}

Instrument::Instrument( const Note  &note, const sf::Time &duree , InstrumentName instrumentName ) :
    m_note( note ),
    m_time( duree ),
    m_instrumentName( instrumentName ),
//    m_sb( nullptr ),
//    m_son( nullptr ),
    m_raw( nullptr ) {

//    m_sb = new sf::SoundBuffer;
//    m_son = new sf::Sound ;

    initialiseBuffer();
}


// -- DESTRUCTOR --
Instrument::~Instrument() {
//    delete m_sb;
//    delete m_son;
    delete[] m_raw;
}



// --------------------- Fonctions publics --------------
//Setter
void Instrument::setNote(const Note& newNote) {

    m_note = newNote;
    initialiseBuffer();

}
void Instrument::setTime(const sf::Time& newTime) {

    m_time = newTime;
    initialiseBuffer();

}
void Instrument::setInstrumentName(const InstrumentName newInstrumentName) {

    m_instrumentName = newInstrumentName;
    initialiseBuffer();

}

// --------------------- Sub et Fonctions privée ----------------
void Instrument::initialiseBuffer() {

    switch (m_instrumentName) {
    case Sinusoide:
        fillArray();

        //Je remplis le buffer
        if ( !m_sb.loadFromSamples( m_raw, getSamples(), 1, SAMPLE_RATE ) ) {
            std::cout << "Loading failed !" << std::endl;
        }
        break;
    }

    m_son.setBuffer( m_sb );
    m_son.setVolume( 10 );

}



//For Sinusoide only
void Instrument::fillArray() {

    //Ici je détermine le temps de la note
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

