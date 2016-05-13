#pragma once

#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>
#include <SFML/Graphics.hpp>

#include "Game/ChordGame.h"

class DesktopBase {
public:
    DesktopBase( unsigned int screenWidth = 800, unsigned int screenHeight = 600 );

    void Run();

private:

    void OnChordGameBtnClick();
    void OnFrontClick();

    // Create an SFGUI. This is required before doing anything with SFGUI.
    sfg::SFGUI m_sfgui;

    unsigned int m_screenWidth;
    unsigned int m_screenHeight;

    sfg::Desktop m_desktop;
    sfg::Window::Ptr m_window;
};
