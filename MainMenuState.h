#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System/Vector2.hpp"

#include "State.h"
#include "FPSCounter.h"
#include "Button.h"

class StateMachine;


class MainMenuState : public State {
	public:
		MainMenuState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
		~MainMenuState();

		void pause();
		void resume();

		void update();
		void render();
	
		void handleMouseInputs(sf::Mouse::Button mouseButton, bool isMousePressed);


	private:
		//Class objects
		FPSCounter fpsCounter;
		Button* quitGameButton;


		//Booleans and Variables
		bool isFRPressed;


		sf::Event sfEvent;

		sf::Texture backgroundTexture;
		sf::Sprite backgroundImage;
};

#endif