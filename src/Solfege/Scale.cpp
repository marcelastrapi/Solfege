#include <Solfege/Scale.h>

//Ctor
Scale::Scale( const Note& fondamental, const Modes &mode, const sf::Time &time, const InstrumentName instrument ) :
    Musicien(instrument),
    m_fondamental( fondamental ),
    m_mode( mode ),
    m_time(time) {

    initialise();
}
//private
void Scale::initialise() {

    Note fondamental(m_fondamental);
    IntervalName inter( seconde, majeur );
    switch ( m_mode ) {
    case ionien: // t  t  dt  t t t
        this->add( fondamental , m_time ) ;
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        break;
    case dorien: // t /dt / t / t / t /dt
        this->add( fondamental ,  m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        break;
    case phrygien: // dt / t / t / t / dt / t
        this->add( fondamental ,  m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        break;
    case lydien: // t / t / t / dt / t / t
        this->add( fondamental ,  m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        break;
    case mixolydien: // t / t /dt / t / t / dt
        this->add( fondamental ,  m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        break;
    case eolien: // t /dt / t / t / dt / t
        this->add( fondamental ,  m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        break;
    case locrien: // dt / t / t /dt/ t / t
        this->add( fondamental ,  m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        break;
    case parTon: // t t t t t (que 6 notes)
        this->add( fondamental ,  m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental, m_time );
        break;

    //POur les 2 prochaines, on met true pour montante et true trouve tout seul la fondamental la plus adapté = celle with le moins d'altération
    case tondemiton: //  t / dt / t /dt /t  / dt
        this->add( fondamental ,  m_time ); //do
        fondamental.addInterval(  inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental, m_time ); //re
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental, m_time ); //mib
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental, m_time ); //fa
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental, m_time ); //solb
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental, m_time ); //lab
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental, m_time ); //labecarre
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental, m_time ); //si
        break;
    case demitonton:
        this->add( fondamental ,  m_time ); //do
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental, m_time ); //reb
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental, m_time ); //mib
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental, m_time ); //mi
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental, m_time ); //fa#
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental, m_time ); //sol
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental, m_time ); //la
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental, m_time ); //sib
        break;
    }

}


//Setter
void Scale::setFondamental(const Note& newFondamental) {
    m_fondamental = newFondamental;
    initialise();
}
void Scale::setMode(const Modes &newMode) {
    m_mode = newMode;
    initialise();
}
