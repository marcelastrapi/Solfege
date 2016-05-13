#include "Solfege/ScaleNotes.h"

//Ctor
ScaleNotes::ScaleNotes( const Note& fondamental, const Modes &mode) :
    m_fondamental( fondamental ),
    m_mode( mode ) {

    initialise();
}
//private
void ScaleNotes::initialise() {

    Note fondamental(m_fondamental);
    Interval inter( seconde, majeur );
    switch ( m_mode ) {
    case ionien: // t  t  dt  t t t
        m_scaleNotes.push_back( fondamental  ) ;
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        break;
    case dorien: // t /dt / t / t / t /dt
        m_scaleNotes.push_back( fondamental  );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        break;
    case phrygien: // dt / t / t / t / dt / t
        m_scaleNotes.push_back( fondamental  );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        break;
    case lydien: // t / t / t / dt / t / t
        m_scaleNotes.push_back( fondamental  );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        break;
    case mixolydien: // t / t /dt / t / t / dt
        m_scaleNotes.push_back( fondamental  );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        break;
    case eolien: // t /dt / t / t / dt / t
        m_scaleNotes.push_back( fondamental  );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        break;
    case locrien: // dt / t / t /dt/ t / t
        m_scaleNotes.push_back( fondamental  );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( mineur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        break;
    case parTon: // t t t t t (que 6 notes)
        m_scaleNotes.push_back( fondamental  );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        fondamental += inter.setIntervalQualification( majeur );
        m_scaleNotes.push_back( fondamental );
        break;

    //POur les 2 prochaines, on met true pour montante et true trouve tout seul la fondamental la plus adapté = celle with le moins d'altération
    case tondemiton: //  t / dt / t /dt /t  / dt
        m_scaleNotes.push_back( fondamental  ); //do
        fondamental.addInterval(  inter.setIntervalQualification( majeur ), true, true );
        m_scaleNotes.push_back( fondamental ); //re
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        m_scaleNotes.push_back( fondamental ); //mib
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        m_scaleNotes.push_back( fondamental ); //fa
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        m_scaleNotes.push_back( fondamental ); //solb
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        m_scaleNotes.push_back( fondamental ); //lab
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        m_scaleNotes.push_back( fondamental ); //labecarre
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        m_scaleNotes.push_back( fondamental ); //si
        break;
    case demitonton:
        m_scaleNotes.push_back( fondamental  ); //do
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        m_scaleNotes.push_back( fondamental ); //reb
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        m_scaleNotes.push_back( fondamental ); //mib
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        m_scaleNotes.push_back( fondamental ); //mi
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        m_scaleNotes.push_back( fondamental ); //fa#
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        m_scaleNotes.push_back( fondamental ); //sol
        fondamental.addInterval( inter.setIntervalQualification( majeur ), true, true );
        m_scaleNotes.push_back( fondamental ); //la
        fondamental.addInterval( inter.setIntervalQualification( mineur ), true, true );
        m_scaleNotes.push_back( fondamental ); //sib
        break;
    }
    m_scaleNotes.push_back( m_fondamental + Interval(octave,juste));

}


//Setter
void ScaleNotes::setFondamental(const Note& newFondamental) {
    m_fondamental = newFondamental;
    initialise();
}
void ScaleNotes::setMode(const Modes &newMode) {
    m_mode = newMode;
    initialise();
}
