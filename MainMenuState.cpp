#include "MainMenuState.h"

#include "State.h"
#include "StateMachine.h"

#include <iostream>

MainMenuState::MainMenuState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	:State{ machine, window, replace } {
	
		this->quitGameButton = new Button(window.getSize().x / 2, window.getSize().y / 2, 150, 50, 20, "res/fonts/Arial.ttf", "Quit Game",
		sf::Color(128, 128, 128), sf::Color(192, 192, 192), sf::Color(0, 0, 128), sf::Color(255, 255, 255));
}

MainMenuState::~MainMenuState() {
	delete this->quitGameButton;
}

void MainMenuState::pause() {
}

void MainMenuState::resume() {
}


void MainMenuState::update() {
	sf::Vector2<int> mousePos = sf::Mouse::getPosition(window);
	this->quitGameButton->update(sf::Vector2<float>(mousePos));

	while (window.pollEvent(sfEvent)) {
		fpsCounter.update();

		switch (sfEvent.type) {
		case sf::Event::Closed:
			machine.quit();
			break;

		case sf::Event::MouseButtonPressed:
			handleMouseInputs(sfEvent.mouseButton.button, true);
			
			if (quitGameButton->isPressed() == true) { machine.quit(); }

			break;

		case sf::Event::MouseButtonReleased:
			handleMouseInputs(sfEvent.mouseButton.button, false);
			break;

		case sf::Event::MouseMoved:
			//

			/*sf::Vector2<int> mousePos = sf::Mouse::getPosition(window);
			std::cout << "X: " << mousePos.x << ", " << "Y: " << mousePos.y << '\n';*/
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
	fpsCounter.renderTo(window);
	quitGameButton->renderTo(window);


	window.display();
}
