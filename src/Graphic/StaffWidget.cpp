/*
 * StaffWidget.cpp
 *
 *  Created on: 1 avr. 2016
 *      Author: astrapi
 */

#include <Graphic/StaffWidget.h>

#include <iostream>
using std::cout;
using std::endl;


//Ctor
StaffWidget::StaffWidget(sf::Window & window) :
		m_window(window),
		m_layout(sfg::Box::Create(sfg::Box::Orientation::VERTICAL)),
		m_playButton(sfg::Button::Create(">")),
		m_stopButton(sfg::Button::Create("×")),
		m_canvas(sfg::Canvas::Create()),
		m_staff(300,50){


	m_canvas->SetRequisition(m_staff.getSize());

	m_canvas->GetSignal(sfg::Widget::OnMouseEnter).Connect(std::bind( &StaffWidget::onCanvasMouseEnter,this));
	m_canvas->GetSignal(sfg::Widget::OnMouseMove).Connect(std::bind( &StaffWidget::onCanvasMouseMove,this));
	m_canvas->GetSignal(sfg::Widget::OnMouseLeave).Connect(std::bind( &StaffWidget::onCanvasMouseLeave,this));

	//Layout
	m_layout->Pack(m_playButton,false,false);
	m_layout->Pack(m_stopButton,false,false);
	m_layout->Pack(m_canvas,false,false);

}


void StaffWidget::draw() {

	m_canvas->Clear(sf::Color(0,0,0,0));
	m_canvas->Draw(m_staff);

}

void StaffWidget::init() {

	//Layout
	auto main_box = sfg::Box::Create( sfg::Box::Orientation::VERTICAL, 5.f );
	main_box->Pack( m_canvas , false);


}

///////////////
// EVENTS
/////////////////

void StaffWidget::onCanvasMouseEnter() {

	cout << "I'm in !" << endl;

}
void StaffWidget::onCanvasMouseMove() {

	m_staff.showTempNote(sf::Mouse::getPosition(m_window).y - m_canvas->GetAbsolutePosition().y);

}
void StaffWidget::onCanvasMouseLeave() {

	m_staff.hideTempNote();

}
