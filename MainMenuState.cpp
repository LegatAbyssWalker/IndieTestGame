#include "MainMenuState.h"

#include "State.h"
#include "StateMachine.h"

#include <iostream>

MainMenuState::MainMenuState(StateMachine& machine, sf::RenderWindow& window, bool replace) 
	:State{ machine, window, replace } {
}

void MainMenuState::pause() {
}

void MainMenuState::resume() {
}


void MainMenuState::update() {
	while (window.pollEvent(sfEvent)) {
		fpsCounter.update();

		switch (sfEvent.type) {
		case sf::Event::Closed:
			machine.quit();
			break;

		case sf::Event::MouseButtonPressed:
			handleMouseInputs(sfEvent.mouseButton.button, true);
			break;

		case sf::Event::MouseButtonReleased:
			handleMouseInputs(sfEvent.mouseButton.button, false);
			break;
		}
	}




	/*-----------------------------------------------------------------------------------------*/
}

void MainMenuState::handleMouseInputs(sf::Mouse::Button mouseButton, bool isMousePressed) {
	if (mouseButton == sf::Mouse::Left) { isFRPressed = isMousePressed; }
}


void MainMenuState::render() {
	window.clear();

	//Render items
	if (isFRPressed) { fpsCounter.drawTo(window); }

	window.display();
}
