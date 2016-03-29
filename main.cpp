#include <iostream>
#include <SFML/Graphics.hpp>

#include "Solfege.h" //All my include for solfege (Note Notes chord scale )
#include "Sound.h"
#include "Games.h"
#include "Rnd.h"
#include <string>

using namespace std;
using namespace sf;


int main() {

//    ContextSettings settings;
//    settings.depthBits = 16;
//    settings.antialiasingLevel = 4;
//    RenderWindow app( VideoMode( 500, 500 ), "Jeu de l'oreille", Style::Default, settings );

    Rnd::randomize();


    bool melodic(true);
    bool downToUp(true);
    sf::Time tps(sf::seconds( 1 ));

    Notes groupeDeNotes;
    groupeDeNotes.add(Note("c",4));
    groupeDeNotes.add(Note("e",4));
    groupeDeNotes.play();
    groupeDeNotes.showInfosNotes();

//    while (true) {
//
//        string rep;
//        cin >> rep;
//
//        if (rep == "r") {
//            jeu.repeatQuestion();
//        } else if (rep == "rep") {
//            jeu.getAnswere();
//        } else if (rep == "n") {
//            jeu.newQuestion();
//        }
//
//    }


    int num;
    cin >> num;

//    while ( app.isOpen() ) {
//        Event event;
//        while ( app.pollEvent( event ) ) {
//            switch ( event.type ) {
//            case Event::Closed:
//                app.close();
//                break;
//            }
//        }
//        app.clear();
//        app.display();
//    }

    return 0;
}
///< pour la convertion des int double en string : boost::lexical_cast<std::string>(mondouble);
///< ou std::to_string()
