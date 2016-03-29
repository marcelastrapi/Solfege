#include <Solfege/Scale.h>

//Ctor
Scale::Scale( const std::string& strNote, int _octave, const Modes &mode ) :
    Notes(),
    m_fondamental( Note( strNote, _octave ) ),
    m_mode( mode ) {

    initialise();
}
Scale::Scale( const Note& fondamental, const Modes &mode ) :
    Notes(),
    m_fondamental( fondamental ),
    m_mode( mode ) {

    initialise();
}
//private
void Scale::initialise() {

    Note fondamental(m_fondamental);
    IntervalName inter( seconde, majeur );
    switch ( m_mode ) {
    case ionien: // t  t  dt  t t t
        this->add( fondamental ) ;
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        break;
    case dorien: // t /dt / t / t / t /dt
        this->add( fondamental ) ;
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        break;
    case phrygien: // dt / t / t / t / dt / t
        this->add( fondamental ) ;
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        break;
    case lydien: // t / t / t / dt / t / t
        this->add( fondamental ) ;
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        break;
    case mixolydien: // t / t /dt / t / t / dt
        this->add( fondamental ) ;
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        break;
    case eolien: // t /dt / t / t / dt / t
        this->add( fondamental ) ;
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        break;
    case locrien: // dt / t / t /dt/ t / t
        this->add( fondamental ) ;
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        break;
    case parTon: // t t t t t (que 6 notes)
        this->add( fondamental ) ;
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        this->add( fondamental );
        break;

    //POur les 2 prochaines, on met true pour montante et true trouve tout seul la fondamental la plus adapté = celle with le moins d'altération
    case tondemiton: //  t / dt / t /dt /t  / dt
        this->add( fondamental ) ; //do
        fondamental.addInterval(  inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental ); //re
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental ); //mib
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental ); //fa
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental ); //solb
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental ); //lab
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental ); //labecarre
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental ); //si
        break;
    case demitonton:
        this->add( fondamental ) ; //do
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental ); //reb
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental ); //mib
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental ); //mi
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental ); //fa#
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental ); //sol
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        this->add( fondamental ); //la
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        this->add( fondamental ); //sib
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
