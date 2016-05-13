#pragma once

#include <Graphic/Staff.h>

#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Box.hpp>
#include <SFGUI/Canvas.hpp>
#include <SFGUI/Button.hpp>
#include <SFGUI/Window.hpp>
#include <memory>
#include <string>

class StaffWidget {


public :
	//Ctor
	StaffWidget(sf::Window & window);

	void init();

	///Events
	void draw();

	void onCanvasMouseEnter();
	void onCanvasMouseMove();
	void onCanvasMouseLeave();

	inline sfg::Widget::Ptr getWidget() { return m_layout; }

protected :

	//Member data
	sf::Window & m_window;
	sfg::Box::Ptr m_layout;
	sfg::Button::Ptr m_playButton;
	sfg::Button::Ptr m_stopButton;
	sfg::Canvas::Ptr m_canvas;
	Staff m_staff;


};
