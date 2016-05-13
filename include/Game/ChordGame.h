#pragma once

#include "Solfege/ChordNotes.h"
#include "Musicien.h"
#include <Solfege/Note.h>
#include <Sound.h>

#include <SFGUI/Label.hpp>
#include <SFGUI/Button.hpp>
#include <SFGUI/Box.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFGUI/Window.hpp>
#include <SFGUI/Signal.hpp>
#include <SFML/System/Time.hpp>

#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>


#include <iostream>
using namespace std;

class ChordGame {

//Variables
public:
	sfg::Window::Ptr m_Window;
	sfg::Label::Ptr m_labelRep;
	sfg::Button::Ptr m_btnRnd;
	sfg::Button::Ptr m_btnPlayAgain;
	sfg::Box::Ptr m_layout;

	Musicien m_pianiste;

public:
	ChordGame();

	//Getter
	inline sfg::Window::Ptr getWidget() { return m_Window; }

	//Events
	void onRndChordClick();
	void onPlayAgainClick();

};

