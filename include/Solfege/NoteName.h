/*Base of Solfege*/

#pragma once

//NOTE NAME
enum SimpleNotesNames  {
    c = 0,
    d = 2,
    e = 4,
    f = 5,
    g = 7,
    a = 9,
    b = 11,
    UNKNOWN = -1///< Note unknown
};
enum Alterations {
    ees = -2,
    es = -1,
    NONE = 0,
    is = 1,
    iis = 2,
    wtf = -1000 ///< this alteration does not exist
};
class  NoteName {
    //Variables
public:
    SimpleNotesNames nomNote;
    Alterations alteration;

    //Construteur
public :
    NoteName():  nomNote( UNKNOWN ), alteration( NONE ) {}
    NoteName( SimpleNotesNames nom, Alterations alt = NONE ) : nomNote( nom ), alteration( alt ) {}
    //Copie
    NoteName( const NoteName& noteACopier ) :  nomNote( noteACopier.nomNote ), alteration( noteACopier.alteration ) {}
    NoteName& operator=( const NoteName& noteACopier ) {
        nomNote = noteACopier.nomNote;
        alteration = noteACopier.alteration;
        return *this;
    }
};

