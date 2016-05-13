//#pragma once
//
//#include <Games/Game.h>
//#include <Games/GameInterval.h>
//
//#include <iostream>
//
//
//template <class T>
//GameInterval<T>::GameInterval( sf::Uint16 nbQuestions, const std::vector<SimpleIntervalsNames> &listOfInter,const sf::Time &timeNote, bool melodic, Ways ways ) :
//    Game<T>( nbQuestions ,timeNote,melodic,ways ) {
//
//    //I fill my list of possible intervals
//    for ( SimpleIntervalsNames inter : listOfInter ) m_listOfInter.push_back( inter );
//}
//
//
//template <class T>
//bool GameInterval<T>::newQuestion() {
//
//        if (m_currentNumQuestion >= m_totalNbOfQuestions ) {
//            finish();
//            return false;
//        }
//
//        m_currentNumQuestion++;
//
//        m_currentQuestion.clear();
//
//        Interval inter( rndInter() );
//        m_currentQuestion = IntervalNotes(Note::RND_NOTE(40,80),inter);
//
//        if ( m_ways == both ) {
//            m_currentWay = ( Rnd::_bool() ) ? up2down : down2up;
//        } else {
//            m_currentWay = m_ways;
//        }
//
//        m_clock.restart();
//        repeatQuestion();
//
//        return true;
//
//}
//
//
//template <class T>
//void GameInterval<T>::repeatQuestion() {
//
//    play<T>();
//
//}
//
//
//template <class T>
//bool GameInterval<T>::checkAnswere(const Interval &answere) {
//
//    m_totalTime += m_clock.getElapsedTime();
//
//    return true;
//}
//
//template <class T>
//void GameInterval<T>::getAnswere() {
//
//    m_totalTime += m_clock.getElapsedTime();
//    m_currentQuestion.showInfosNotes();
//}
//
//
////Functions
////private
//
//Interval GameInterval<T>::rndInter() {
//
//    return Interval::RND_INTERVAL(m_listOfInter);
//
//}
//
//void GameInterval<T>::finish() {
//
//    calculAverageTime();
//    showScore();
//
//}
//
