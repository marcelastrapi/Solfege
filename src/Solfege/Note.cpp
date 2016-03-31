#include <Solfege/Note.h>
#include <vector>

// -- fonction interne --
//min
inline double min( const double &a, const double &b ) {
    return a < b ? a : b;
}
//max
inline double max( const double &a, const double &b ) {
    return a > b ? a : b;
}
//distance
inline double dist( double a, double b ) {
    return max( a, b ) - min( a, b );
}


double Note::A4 = 440;

// ------ CONSTRUCTOR ------

Note::Note() :
    m_nomNote( UNKNOWN ),   m_octave( 4 ),   m_frequence( 0 ) {
    //ctor
}
Note::Note( const NoteName& nom, int oct ) :
    m_nomNote( nom.nomNote, nom.alteration ),   m_octave( oct ),   m_frequence( 0 ) {
    calculeFrequence();
}
Note::Note( const std::string &strNomNote, int oct ) :
    m_nomNote( STRING_TO_NOMNOTE( strNomNote ) ),
    m_octave( oct ),
    m_frequence( 0 ) {
    calculeFrequence();
}
Note::Note( double frequence ):
    m_nomNote( UNKNOWN ),   m_octave( 4 ),   m_frequence( 0 ) {
    *this = FREQ_TO_NOTE( frequence );
}

//copie
Note::Note( const Note& noteACopier ) :
    m_nomNote( noteACopier.getNoteName() ),
    m_octave( noteACopier.getOctave() ),
    m_frequence( noteACopier.getFrequence() ) {
}
// ------ DESTRUCTOR ------
Note::~Note() {
    //dtor
}


// ------ Setter ------
// PUBLIC
void Note::setNewNote( const NoteName& nomNote, const int _octave ) {
    m_nomNote = nomNote;
    m_octave  = _octave;
    calculeFrequence();
}
void Note::setNewNote( const Note& nouvelleNote ) {
    m_nomNote = nouvelleNote.getNoteName();
    m_octave = nouvelleNote.getOctave();
    m_frequence = nouvelleNote.getFrequence();
}


// ----- Operator -----
Note& Note::operator=( const Note& noteACopier ) {
    this->setNewNote( noteACopier );
    return *this;
}
Note& Note::operator+=( const Interval& interval2Add ) {
    short int nbDT = interval2Add.getNbDemiTons();
    short int numNote = NOTE_TO_INT( *this );
    numNote += nbDT;

    //Au cas où la note aille  trop haut
    if ( numNote > 144 ) throw std::string( "ERREUR :  Note sous 0 ! numNote : " + std::to_string( numNote ) );
    this->setNewNote( INT_TO_NOTE( numNote, interval2Add.getNoteNameFromInterval( m_nomNote ) ) );
    return *this;
}
Note  Note::operator+(const Interval& interval2Add)const  {
    short int nbDT = interval2Add.getNbDemiTons();
    short int numNote = NOTE_TO_INT( *this );
    numNote += nbDT;

    //Au cas où la note aille  trop haut
    if ( numNote > 144 ) throw std::string( "ERREUR :  Note sous 0 ! numNote : " + std::to_string( numNote ) );
    Note rep( INT_TO_NOTE( numNote, interval2Add.getNoteNameFromInterval( m_nomNote ) ) );
    return rep;
}
Note& Note::operator-=( const Interval& interval2Add ) {
    short int nbDT = interval2Add.getNbDemiTons();
    short int numNote = NOTE_TO_INT( *this );
    numNote -= nbDT;

    //Au cas où la note aille trop bas
    if ( numNote < 0 ) throw std::string( "ERREUR :  Note trop haute ! numNote : " + std::to_string( numNote ) );

    this->setNewNote( INT_TO_NOTE( numNote, interval2Add.getNoteNameFromInterval( m_nomNote,false ) ) );
    return *this;
}
Note  Note::operator-(const Interval& interval2Add) const {
    short int nbDT = interval2Add.getNbDemiTons();
    short int numNote = NOTE_TO_INT( *this );
    numNote -= nbDT;

    //Au cas où la note aille  trop haut
    if ( numNote > 144 ) throw std::string( "ERREUR :  Note sous 0 ! numNote : " + std::to_string( numNote ) );
    Note rep( INT_TO_NOTE( numNote, interval2Add.getNoteNameFromInterval( m_nomNote ) ) );
    return rep;
}

Note& Note::addInterval(const Interval& interval2Add,bool montante, bool findTheBestNoteMyself) {
    short int nbDT = interval2Add.getNbDemiTons();
    short int numNote = NOTE_TO_INT( *this );

    //Si on veut une intervalle montante alors on ajoute le nombre de demi-ton, sinon ou enlève
    numNote += (montante) ? nbDT : nbDT * -1;
    //Au cas où la note aille  trop haut
    if ( numNote < 0 ||  numNote > 144 ) throw std::string( "ERREUR :  Note out of bounds ! numNote : " + std::to_string( numNote ) );
    if (findTheBestNoteMyself)
        this->setNewNote( INT_TO_NOTE( numNote , SimpleNotesNames::UNKNOWN , Alterations::NONE  ) );
    else
        this->setNewNote( INT_TO_NOTE( numNote, interval2Add.getNoteNameFromInterval( m_nomNote ,  ( montante ) ? true : false )   )    );

    return *this;
}

// ----- Static Fonctions ------
//PUBLIC
short int   Note::NB_DT_ENTRE_2_NOTES( const Note& noteA, const Note& noteB ) {
    return NOTE_TO_INT( noteA ) - noteA.NOTE_TO_INT( noteB );
}
short int   Note::NOTE_TO_INT( const Note& note ) {

    return static_cast<short int>( note.getNoteName().nomNote ) +
            static_cast<short int>( note.getNoteName().alteration ) +
            note.getOctave() * 12;

}
Note         Note::INT_TO_NOTE( const int numNote, const SimpleNotesNames notePrefere , const Alterations altPrefere ) {
    //Si le numéro est trop haut ou trop bas
    if ( numNote < 0 || numNote > 144 )   throw std::string( "ERREUR :  Note au-delà des limites ! numNote : " + std::to_string( numNote ) );

    std::vector<Note> vNotes;
    Note note;
    NoteName nom;

    //Je vais cherche le numéro de chaque note, quand sa correspondra au nbNote c'est que
    //ce sera la bonne note
    short int tblNote[7] = { 0, 2, 4, 5, 7, 9, 11};
    for ( short int nomSimple : tblNote ) { //Je test chaque nomDeNote
        for ( short int alt( -2 ) ; alt <= 2; alt++ ) { //with chaque alterations
            nom.nomNote = static_cast<SimpleNotesNames>( nomSimple );
            nom.alteration = static_cast<Alterations>( alt );
            for ( unsigned short int oct( 0 ); oct <= 11; oct++ ) { //Chaque m_octave
                note.setNewNote( nom, oct );
                if ( NOTE_TO_INT( note ) == numNote )
                    vNotes.push_back( note );

            }
        }
    }

    //Je choisi quelles note je vais retourner en fonction de la note prefere
    if ( vNotes.size() == 0 ) {
        throw std::string ( "Aucune note with ce numéro : " + std::to_string( numNote ) ) ;
    } else if ( vNotes.size() == 1 ) { //Si il n'y a qu'une trouvaille c'est simple
        return vNotes.at( 0 );
    } else { //là je choisi laquelle on préfère (si plusieurs)
        Note rep = vNotes.at( 0 );
        for ( Note noteV : vNotes ) {
            if ( notePrefere != UNKNOWN && noteV.getNoteName().nomNote == notePrefere )
                return noteV;
        }
        for ( Note noteV : vNotes ) {
            if ( noteV.getNoteName().alteration == altPrefere )
                return  noteV;
        }
        for ( Note noteV : vNotes ) {
             if ( noteV.getNoteName().alteration == es || noteV.getNoteName().alteration == is )
                return noteV;
        }
        //Si on arrive là alors il nous forcément un ## ou un bb
        return vNotes.at(1);
    }
}
std::string Note::NOTE_TO_STRING( const Note& note ) {
    std::string noteStr = "";
    if ( !NOTATION_FRANCAISE ) {
        switch ( note.getNoteName().nomNote ) {
            case SimpleNotesNames::a:
                noteStr +=  "a";
                break;
            case SimpleNotesNames::b:
                noteStr +=  "b";
                break;
            case SimpleNotesNames::c:
                noteStr +=  "c";
                break;
            case SimpleNotesNames::d:
                noteStr +=  "d";
                break;
            case SimpleNotesNames::e:
                noteStr +=  "e";
                break;
            case SimpleNotesNames::f:
                noteStr +=  "f";
                break;
            case SimpleNotesNames::g:
                noteStr +=  "g";
                break;
            case SimpleNotesNames::UNKNOWN:
                noteStr +=  "UNKNOWN";
                break;
            default:
                noteStr +=  "note unknown !";
                break;
        }
        switch ( note.getNoteName().alteration ) {
            case Alterations::es:
                noteStr += "es";
                break;
            case Alterations::ees:
                noteStr += "ees";
                break;
            case Alterations::is:
                noteStr += "is";
                break;
            case Alterations::iis:
                noteStr += "iis";
                break;
            case Alterations::NONE:
                break;
            default:
                noteStr += "alteration unknown !";
                break;
        }

    } else {
        switch ( note.getNoteName().nomNote ) {
            case SimpleNotesNames::a:
                noteStr +=  "la";
                break;
            case SimpleNotesNames::b:
                noteStr +=  "si";
                break;
            case SimpleNotesNames::c:
                noteStr +=  "do";
                break;
            case SimpleNotesNames::d:
                noteStr +=  "ré";
                break;
            case SimpleNotesNames::e:
                noteStr +=  "mi";
                break;
            case SimpleNotesNames::f:
                noteStr +=  "fa";
                break;
            case SimpleNotesNames::g:
                noteStr +=  "sol";
                break;
            case SimpleNotesNames::UNKNOWN:
            default:
                noteStr +=  "note inconnue !";
                break;
        }
        switch ( note.getNoteName().alteration ) {
            case Alterations::es:
                noteStr += "b";
                break;
            case Alterations::ees:
                noteStr += "bb";
                break;
            case Alterations::is:
                noteStr += "#";
                break;
            case Alterations::iis:
                noteStr += "##";
                break;
            case Alterations::NONE:
                break;
            default:
                noteStr += "alteration inconnue !";
                break;
        }
    }
    return noteStr;
}
NoteName     Note::STRING_TO_NOMNOTE( std::string _nomNote ) {
    NoteName rep;
    if ( !NOTATION_FRANCAISE ) {
        char nom = _nomNote[0];
        _nomNote.at( 0 ) = 'X';

        switch ( nom ) {
            case 'c':
                rep.nomNote = c;
                break;
            case 'd':
                rep.nomNote = d;
                break;
            case 'e':
                rep.nomNote = e;
                break;
            case 'f':
                rep.nomNote = f;
                break;
            case 'g':
                rep.nomNote = g;
                break;
            case 'a':
                rep.nomNote = a;
                break;
            case 'b':
                rep.nomNote = b;
                break;
            default:
                rep.nomNote = UNKNOWN;
                break;
        }
        if ( _nomNote ==  "Xes" ) {
            rep.alteration = es;
        } else if ( _nomNote == "Xees" ) {
            rep.alteration = ees;
        } else if ( _nomNote == "Xis" ) {
            rep.alteration = is;
        } else if ( _nomNote == "Xiis" ) {
            rep.alteration = iis;
        } else {
            rep.alteration = NONE;
        }
    } else { //NOTATION FRANCAISE
        //Nom de la note
        if ( _nomNote.find( "do" ) != std::string::npos ) {
            rep.nomNote = c;
        } else if  ( _nomNote.find( "ré" ) != std::string::npos ) {
            rep.nomNote = d;
        } else if  ( _nomNote.find( "mi" ) != std::string::npos ) {
            rep.nomNote = e;
        } else if  ( _nomNote.find( "rfa" ) != std::string::npos ) {
            rep.nomNote = f;
        } else if  ( _nomNote.find( "sol" ) != std::string::npos ) {
            rep.nomNote = g;
        } else if  ( _nomNote.find( "la" ) != std::string::npos ) {
            rep.nomNote = a;
        } else if  ( _nomNote.find( "si" ) != std::string::npos ) {
            rep.nomNote = g;
        } else {
            rep.nomNote = UNKNOWN;
        }

        //Alterations
        if ( _nomNote.find( "#" ) != std::string::npos ) {
            rep.alteration = is;
        } else if ( _nomNote.find( "##" ) != std::string::npos ) {
            rep.alteration = iis;
        } else if ( _nomNote.find( "b" ) != std::string::npos ) {
            rep.alteration = es;
        } else if ( _nomNote.find( "bb" ) != std::string::npos ) {
            rep.alteration = ees;
        } else {
            rep.alteration = NONE;
        }

    }
    return rep;
}
Note         Note::FREQ_TO_NOTE( double frequence ) {
    //if (frequence < 20 || frequence > 30000) throw std::string("ERREUR :  Impossible d'entendre cette fréquence : " + std::to_string(frequence) );
    //On cherche la note qui à la frequence la plus proche des notes que j'utilise
    Note rep, note;
    NoteName nom;
    double minDist( 44100 );
    short int tblNote[7] = { 0, 2, 4, 5, 7, 9, 11};
    for ( short int nomSimple : tblNote ) { //Je test chaque nomDeNote
        for ( short int alt( -2 ) ; alt <= 2; alt++ ) { //with chaque alterations
            nom.nomNote = static_cast<SimpleNotesNames>( nomSimple );
            nom.alteration = static_cast<Alterations>( alt );
            for ( unsigned short int oct( 0 ); oct <= 10; oct++ ) { //Chaque m_octave
                note.setNewNote( nom, oct );
                if ( dist( note.getFrequence(), frequence ) < minDist  && nom.alteration != ees && nom.alteration != iis ) {
                    minDist = dist( note.getFrequence(), frequence );
                    rep = note; //copie
                }
            }
        }
    }
    return  rep;
}

Note Note::RND_NOTE(unsigned short a, unsigned short b) {

    return INT_TO_NOTE( Rnd::_int(a,b) , UNKNOWN,NONE );
}
Note Note::RND_NOTE(const Note &minNote, const Note &maxNote ) {

    return RND_NOTE( NOTE_TO_INT(minNote) , NOTE_TO_INT(maxNote) );
}


//PRIVE
short int Note::nbDemiTonDepuisA4() const {
    short int numA4 = 57;
    short int numNote = NOTE_TO_INT( *this );
    return numNote - numA4;
}

// ------ Subs ------
//PUBLIC
void Note::showInfosNote() const {
    std::cout << std::endl;
    std::cout << "NoteName \t: " << NOTE_TO_STRING( *this ) << m_octave << std::endl;
    std::cout << "Fréquence \t: " << m_frequence << std::endl;
    std::cout << "Numéro \t\t: " << NOTE_TO_INT( *this ) << std::endl;
    std::cout << std::endl;
}
//PRIVE
void Note::calculeFrequence() {
    //Il me faut la distance entre la note et le a4 de reférence
    short int nbDt = nbDemiTonDepuisA4();

    //Pour monter d'un demi-ton = freq * r      (ou r = DT)
    //Pour monter de 2 dt       = freq * r au carré etc...
    //Pour descendre d'un dt    = freq / r = freq * r puissance -2

    m_frequence =  A4 * pow( DT, nbDt );
}


