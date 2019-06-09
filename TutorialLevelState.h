#ifndef TUTORIALLEVELSTATE_H
#define TUTORIALLEVELSTATE_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System/Vector2.hpp"

#include "State.h"
#include "FPSCounter.h"
#include "Button.h"
#include "Text.h"

#include "MainMenuState.h"

class StateMachine;

class TutorialLevelState : public State {
	public:
		TutorialLevelState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
		~TutorialLevelState();

		void pause();
		void resume();

		void update();
		void render();

	private:
		//Buttons
		Button* backButton;
		Button* startButton;


		//Text
		Text* gameInstructions;


		//Class objects
		FPSCounter fpsCounter;



		//Variables
		std::string arialFont = "res/fonts/arial.ttf";
		sf::Event sfEvent;
};

#endif