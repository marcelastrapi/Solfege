#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Solfege/Note.h>

#include <vector>

class Staff : public sf::Drawable, public sf::Transformable {
    public :
        Staff(  int backgroundWidth = 300,
                int backgroundHeight = 30,
                sf::Color couleurFond = sf::Color::White,
                sf::Color couleurLignes = sf::Color::Black,
                sf::Color couleurNotes = sf::Color::Black);


        // ------------- ACCESSEURS -------------------
        	//Getter
        inline const sf::Vector2f& getSize() const { return fond.getSize(); }
        inline const sf::Vector2f& getPosition() const { return fond.getPosition(); }
        inline const sf::Color& getBackgroundColor() const { return fond.getFillColor(); }
        inline const sf::Color& getLinesColor() const { return m_colorLines; }
        	//Setter
        void setSize(sf::Vector2f & newSize); // A FAIRE
        void setPosition(sf::Vector2f & newPos); // A FAIRE
        void setAmbitus(Note & noteBass, Note & noteHigh);

        // ------------ FONCTIONS ---------------

        /// \brief add a new note to the staff
        /// verify if it's in the good ambitus, say something if it doesn't
        void addNote(Note & newNote); //A faire
        /// \brief remove the last note
        void removeNote(); //A faire

        /// \brief show the note under the mouse
        void showTempNote(int mousePos);  ///A mettre dans la boucle principale pour les evenements particulier de la portée
        /// \brief hide the note under the mouse
        inline void hideTempNote() { noteTemp.setFillColor(sf::Color::Transparent); }

    private :
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        // ------------ Fonctions privées ------------
        /// \brief initialise the staff (make the background, and the vertex with the good number of lines)
        void initialise(int nbLines = 5);

        int posXNewNote(); ///Donne la position x  ou sera mise la nouvelle note
        int espaceEntreLigneEtInterligne();
        int ligneOuInterligneLaPlusProche(int mouseY);
        sf::CircleShape dessinNote(int ligneOuInterligneLaPlusProche);

        // ------------ MEMBRES -----------

            //Le fond et la portee
        sf::VertexArray portee;
        sf::RectangleShape fond;

            //Leurs settings
        int m_posX;
        int m_posY;
        int m_width;
        int m_height;
        sf::Color m_colorFond;
        sf::Color m_colorLines;
        sf::Color m_colorNotes;

            //Les variables liées à la portée
        int posYNotes[16];          ///Le tableau des PosY des 7 lignes
        int nbNotes;
        std::vector<Note> posXNotes; ///Le tableau des notes qui seront affichées sur la portée
        std::vector<sf::CircleShape> notesADessiner;
        sf::CircleShape noteTemp;

        	//Au solfège
        //int m_nbLinesAroundStaff;
        std::pair<Note,Note> m_ambitus;

};


/* il y a 11 notes entre ré sous la portée et sol au dessus
 *
 *Je suis en train de faire en sorte que l'on puisse choisir le nombre de ligne (et de donc de note que comporte la portée)
 * à l'aide d'un argument ambitus
 *
 * JE SUIS DANS LA FONCTION  INITIALISE !
 *
 * A faire :
 * tout les set
 * pouvoir mettre une clé de sol ut fa
 */

