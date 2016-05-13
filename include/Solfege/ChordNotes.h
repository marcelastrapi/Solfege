#pragma once

#include "Note.h"
#include "Rnd.h"
#include <vector>


//ACCORDS
/// \brief enum du noms de tout les accords, commencant toute par c comme chords
enum ChordsNames {

	//Accord à 3 sons 0-6

	maj,                   ///< ChordNotes majeur = M
    maj5Dim,               ///< ChordNotes majeur with 5 dim = b5
    maj5Aug,               ///< ChordNotes majeur with 5 aug = +

    minor,                 ///< ChordNotes mineur = m
    min5Dim,               ///< ChordNotes mineur with 5 dim  = mb5

    sus2,                  ///< ChordNotes with 2 a la place de 3 = sus2
    sus4,                  ///< ChordNotes with 4 a la place de 3 = sus4

    //Accord à 4 sons 	7-20

    maj5Dim7Min,           ///< ChordNotes majeur with 5 dim 7 mineur = 7b5
    min5Dim7Min,           ///< ChordNotes mineur with 5 dim 7 mineur = demi-diminué = rond-barré

    maj5Aug7Min,           ///< ChordNotes majeur with 5 aug 7 mineur = +7
    min5Dim7Dim,           ///< ChordNotes mineur with 5 dim 7 dim      = septième-diminuée = °7

    maj7Min,               ///< ChordNotes majeur with 7 mineur = 7
    maj7Maj,               ///< ChordNotes majeur with 7 majeur = M7
    min7Min,               ///< ChordNotes mineur with 7 mineur   = m7
    min7Maj,               ///< ChordNotes mineur with 7 majeur = m7M

    maj6Maj,               ///< ChordNotes majeur with 6 majeur = 6
    min6Maj,               ///< ChordNotes mineur with 6 majeur = m6

    majAdd2,               ///< ChordNotes majeur with 2 ajoutée = add2
    majAdd4,               ///< ChordNotes majeur with 4 ajoutée = add4
    minAdd2,               ///< ChordNotes mineur with 2 ajoutée = madd2
    minAdd4,               ///< ChordNotes mineur with 4 ajoutée = madd4

    //Accord à 5 sons	21-27

    maj6Maj9Maj,           ///< ChordNotes majeur with 6 majeur 9 majeur = 6/9
    min6Maj9Maj,           ///< ChordNotes mineur with 6 majeur 9 majeur = m6/9

    maj7Min9Maj,           ///< ChordNotes majeur with 7 mineur 9 majeur = 9
    maj7Maj9Maj,           ///< ChordNotes majeur with 7 majeur 9 majeur = M9
    maj7Maj9Aug,           ///< ChordNotes majeur with 7 majeur 9 augmentée = 7#9
    maj7Maj9Dim,           ///< ChordNotes majeur with 7 majeur 9 mineur = 7b9
    min7Min9Maj,           ///< ChordNotes mineur with 7 mineur 9 majeur = m9


};


class  ChordNotes {
    //Variables
private :
    Note m_fondamental;
    ChordsNames m_chordName;
    std::vector<Note> m_chordNotes;

    static constexpr unsigned short int NB_CHORDS = 28;
    static constexpr unsigned short int NB_CHORDS_3NOTES = 7;
    static constexpr unsigned short int NB_CHORDS_4NOTES = 14;
    static constexpr unsigned short int NB_CHORDS_5NOTES = 7;

    //Constructors
public :
    ChordNotes( const Note  &fondamental, const ChordsNames &chordName);
private :
    void initialise();

    //Getter
public:
    inline Note getFondamental() const { return m_fondamental; }
    inline ChordsNames getChordName() const { return m_chordName; }
    inline std::vector<Note> getNotes() const { return m_chordNotes; }
    inline unsigned int getNumberOfNotes() const { return m_chordNotes.size(); }

    //Setter
    void setFondamental(const Note &newFondamental);
    void setChordName(const ChordsNames &newChordName);

    //STATIC FONCTION

    /// \brief Vraiment n'import quel accord, il faut juste spécifier le nombre de notes souhaité
    /// \param number of notes for the chord
    /// \param bool, if true on aurai que des accords du nombres de notes voulue, sinon ou pourra en avoir avec moins
    static ChordNotes RND_CHORD(unsigned short int numberOfNotes = 3, bool exactNumberOfNotes = true);
    static ChordNotes RND_CHORD_IN_SCALE(const Note & fondamental );

};

