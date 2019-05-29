#include "MainMenuState.h"

#include "State.h"
#include "StateMachine.h"

#include <iostream>

MainMenuState::MainMenuState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	:State{ machine, window, replace } {
	
		//Buttons
		this->quitGameButton = new Button(window.getSize().x / 2, window.getSize().y / 2 + 40, 150, 50, 20, "res/fonts/Arial.ttf", "Quit Game",
			sf::Color(128, 128, 128), sf::Color(192, 192, 192), sf::Color(0, 0, 128), sf::Color(255, 255, 255));

		this->tutorialLevelButton = new Button(window.getSize().x / 2, window.getSize().y / 2 - 40, 150, 50, 20, "res/fonts/Arial.ttf", "Start Tutorial!",
			sf::Color(128, 128, 128), sf::Color(192, 192, 192), sf::Color(0, 0, 128), sf::Color(255, 255, 255));

		//Text
		this->titleText = new Text(window.getSize().x / 2, window.getSize().y / 4, 40, "res/fonts/Arial.ttf", "Indie Game Dev!", sf::Color(0, 139, 139));
}

MainMenuState::~MainMenuState() {
	delete this->quitGameButton;
	delete this->tutorialLevelButton;
	delete this->titleText;
}

void MainMenuState::pause() {

}

void MainMenuState::resume() {
	
}


void MainMenuState::update() {
	//Updating mouse position for button functionality
	this->quitGameButton->update(sf::Vector2<float>(mousePos));
	this->tutorialLevelButton->update(sf::Vector2<float>(mousePos));

	//Event loop
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
	if (sf::Mouse::Left) { std::cout << "Left Click\n"; }
}


void MainMenuState::render() {
	window.clear();

	//Render items
	this->fpsCounter.renderTo(window);
	this->quitGameButton->renderTo(window);
	this->tutorialLevelButton->renderTo(window);
	this->titleText->renderTo(window);


	window.display();
}
