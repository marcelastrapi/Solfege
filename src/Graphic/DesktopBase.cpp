#include <Graphic/DesktopBase.h>

DesktopBase::DesktopBase( unsigned int width, unsigned int height ) :
    m_screenWidth( width ),
    m_screenHeight( height ),
    m_desktop(),
    m_window( sfg::Window::Create() )
    { }

void DesktopBase::Run() {

    sf::RenderWindow render_window( sf::VideoMode( m_screenWidth, m_screenHeight ), "Mon desktop perso" );

    render_window.resetGLStates();

    //Init.
//    m_desktop.SetProperty( "Button#interval", "FontSize", 18.f );
    m_desktop.SetProperty( "Button", "FontSize", 18.f );

    //// Main window ////
    // Widgets
    m_window->SetTitle( "La fenetre dans mon desktop" );

    //Je crée autant de bouton de jeux (pour l'instant à défaut de super interface de ouf)
    auto chordGame = sfg::Button::Create("Jeu des accords");


    chordGame->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind( &DesktopBase::OnChordGameBtnClick, this ));

    //Conncecter le clique à l'ouverture de la class chordGame que je n'ai pas encore faite

    m_window->Add(chordGame);
    m_desktop.Add( m_window);

    sf::Event event;
    while ( render_window.isOpen() ) {
        while ( render_window.pollEvent( event ) ) {
            if ( ( event.type == sf::Event::Closed ) || ( event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape ) ) {

                render_window.close();
            } else {
                m_desktop.HandleEvent( event );
            }
        }

        m_desktop.Update( .5f );
        render_window.clear( sf::Color::Black );
        m_sfgui.Display( render_window );
        render_window.display();

    }

}


void DesktopBase::OnChordGameBtnClick() {

	//On crée un nouvelle fenetre avec le jeux chord à l'interieur

  	ChordGame chordGameWindow;
  	m_desktop.Add(chordGameWindow.getWidget());

}


void DesktopBase::OnFrontClick() {
    m_desktop.BringToFront( m_window );
}
