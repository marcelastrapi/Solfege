#include "Graphic/Staff.h"
#include <iostream>
using namespace std;
// ------- fonctions utile qu'ici ---------
int min(int a, int b){
	return (a<b)?a:b;
}
int max(int a, int b){
	return (a>b)?a:b;
}
int dist(int a,int b){
	return (max(a,b) - min(a,b));
}

// ---------- Constructeur ---------------

Staff::Staff( int backgroundWidth, int backgroundHeight , sf::Color couleurFond ,sf::Color couleurLignes, sf::Color couleurNotes) :
    		portee(sf::Lines,10), //Mes 10 points qui compose mes 5 lignes de ma portée
    		fond(sf::Vector2f(backgroundWidth,backgroundHeight)),
    		m_posX(0),
    		m_posY(0),
    		m_width(backgroundWidth),
    		m_height(backgroundHeight),
    		m_colorFond(couleurFond),
    		m_colorLines(couleurLignes),
    		m_colorNotes(couleurNotes),
    		nbNotes(0) {

	//Initialisation du fond de la portée
	fond.setFillColor(couleurFond);
	fond.setPosition(m_posX,m_posY);



}

// ---------------------------------- EVENTS --------------------------------------
void Staff::showTempNote(int mousePos) {

	//Je récupère les coordonnées de la souris par rapport à la fenetre courante

	//notesADessiner.push_back(dessinNote(ligneOuInterligneLaPlusProche(event.mouseButton.y)));

	//Trouve la ligne OU l'interligne (!) la plus proche de la souris (mouseY)
	int note = ligneOuInterligneLaPlusProche(mousePos);
	//dessiner la note sous la souris à l'endroit qu'il faut (posXNotes)
	noteTemp = dessinNote(note);

}

// ---------------------------------- FONCTIONS ------------------------------------


// -------------------------------- ACCESSEURS ------------------------------
void Staff::setAmbitus(Note & noteBass, Note & noteHigh) {

	m_ambitus.first = noteBass;
	m_ambitus.second = noteHigh;

	//Recalcule le nombre de lignes à ajouter
	int diffBtwNotes = Note::NOTE_TO_INT(noteHigh) - Note::NOTE_TO_INT(noteBass);

	if (diffBtwNotes < 11) {
		//Do nothing, initialise with 5 lines
		return;
	}


}

// --------------------------------- DESSIN DE LA PORTEE ------------------------------

void Staff::draw(sf::RenderTarget& target, sf::RenderStates states) const {

	// on dessine le tableau de vertex
	target.draw(fond);
	target.draw(portee,states);
	for (unsigned short int i(0); i < notesADessiner.size() ; i++){
		target.draw(notesADessiner[i]);
	}
	target.draw(noteTemp);

}

// ---------------- Fonctions privé -------------------
void Staff::initialise(int nbLines){

	//Definition des la tailles des interlignes
		int incrementationVerticale = espaceEntreLigneEtInterligne();
		int posVerticale(m_posY + incrementationVerticale ); //On ajoute le si (1ère interligne)

		//Pour que la largeur et la hauteur soit en fonction du fond et pas de 0,0 de la fenetre
		m_width += m_posX;
		m_height += m_posY;

		//Initialisation du tbl de positions des 7 lignes (1 au dessus et 1 en dessous)
		for (int i = 0; i < 16 ; i++) {
			posYNotes[i]=posVerticale;
			posVerticale += incrementationVerticale;
		}

		//Dessin des lignes de la portée dans le vertex
		portee[0].position = sf::Vector2f(m_posX,posYNotes[3]);       portee[1].position = sf::Vector2f(m_width,posYNotes[3]);
		portee[2].position = sf::Vector2f(m_posX,posYNotes[5]);       portee[3].position = sf::Vector2f(m_width,posYNotes[5]);
		portee[4].position = sf::Vector2f(m_posX,posYNotes[7]);       portee[5].position = sf::Vector2f(m_width,posYNotes[7]);
		portee[6].position = sf::Vector2f(m_posX,posYNotes[9]);       portee[7].position = sf::Vector2f(m_width,posYNotes[9]);
		portee[8].position = sf::Vector2f(m_posX,posYNotes[11]);      portee[9].position = sf::Vector2f(m_width,posYNotes[11]);

		//Et de ses couleurs
		portee[0].color = m_colorLines;    portee[1].color = m_colorLines;
		portee[2].color = m_colorLines;    portee[3].color = m_colorLines;
		portee[4].color = m_colorLines;    portee[5].color = m_colorLines;
		portee[6].color = m_colorLines;    portee[7].color = m_colorLines;
		portee[8].color = m_colorLines;    portee[9].color = m_colorLines;

}


int Staff::posXNewNote() {

	return ( notesADessiner.size() * (espaceEntreLigneEtInterligne() * 2.5 ) + m_posX);

}
int Staff::espaceEntreLigneEtInterligne() {

	return m_height / 16;

}
int Staff::ligneOuInterligneLaPlusProche(int mouseY){

	int minDist = 1000000;
	int rep,note;
	for (int i = 0; i < 15; i++){
		rep = dist(mouseY,posYNotes[i]);
		if (rep < minDist) { minDist = rep; note = i;}
	}
	//A la sortie du for, j'ai la note ou l'internote la plus proche
	return note;

}
sf::CircleShape Staff::dessinNote(int ligneOuInterligneLaPlusProche) {


	sf::CircleShape dessinNote;
	dessinNote.setRadius(espaceEntreLigneEtInterligne());
	dessinNote.setPosition(sf::Vector2f(posXNewNote(), posYNotes[ligneOuInterligneLaPlusProche]-espaceEntreLigneEtInterligne() ));
	dessinNote.setFillColor(m_colorNotes);
	return dessinNote;

}

