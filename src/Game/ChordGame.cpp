#include <Game/ChordGame.h>

ChordGame::ChordGame() : m_Window(sfg::Window::Create() ),
						 m_labelRep(sfg::Label::Create("Answer will be here")),
						 m_btnRnd(sfg::Button::Create("Play a random Chord")),
						 m_btnPlayAgain(sfg::Button::Create("Play again")),
						 m_layout(sfg::Box::Create(sfg::Box::Orientation::VERTICAL,1)),
						 m_pianiste(Musicien(Sinusoide)) {

	m_Window->SetTitle("Chords Game");

	m_layout->Pack(m_btnRnd,true,true);
	m_layout->Pack(m_btnPlayAgain,true,true);
	m_layout->Pack(m_labelRep,true,true);

	m_Window->Add(m_layout);

	//Event
	m_btnRnd->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind( &ChordGame::onRndChordClick, this ));
	m_btnPlayAgain->GetSignal(sfg::Button::OnLeftClick).Connect(std::bind( &ChordGame::onPlayAgainClick, this));

}

void ChordGame::onRndChordClick() {

//	m_labelRep->SetText(L"J'ai cliqué");

	//On créer un accord aléatoire à 3 sons
	ChordNotes chord(ChordNotes::RND_CHORD(3,true));

	//On vide la tête du pianiste (c'est là que je me suis rendu qu'il y avait un problème, dans la fonction Musicien::clear(), j'ai voulue
	//savoir si m_notesToPlay était vide, et j'ai toujours eu un int énorme comme réponse...
	m_pianiste.clear();
	//J'ajoute l'accord dans la tête du pianiste
	m_pianiste.add(chord.getNotes(),sf::seconds(.5));

	for (Note & note : chord.getNotes() ){
		note.showInfosNote();
	}
	m_pianiste.showInfosNotes();
	m_pianiste.play(true,true);
	cout << "chord : " << chord.getChordName() << endl;

}
void ChordGame::onPlayAgainClick() {

	m_pianiste.play(true,true);

}
