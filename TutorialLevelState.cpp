#include "TutorialLevelState.h"

#include "State.h"
#include "StateMachine.h"

#include "PlayingState.h"

class StateMachine;

TutorialLevelState::TutorialLevelState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	: State{ machine, window, replace } {
		
		//Buttons
		this->backButton = new Button(window.getSize().x / 2, window.getSize().y - 200, 150, 50, 20, arialFont, "Back",
			sf::Color(128, 128, 128), sf::Color(192, 192, 192), sf::Color(0, 0, 225), sf::Color(255, 255, 255));

		this->startButton = new Button(window.getSize().x / 2, window.getSize().y / 2 + 150, 150, 50, 20, arialFont, "Start Game",
			sf::Color(128, 128, 128), sf::Color(192, 192, 192), sf::Color(0, 0, 255), sf::Color(255, 255, 255));


		//Text
		this->gameInstructions = new Text(window.getSize().x / 2, window.getSize().y / 3, 30, arialFont, "			To move, use 'W', 'A', 'S', and 'D'.\n					Use 'SPACE' to shoot! \n'CLICK' buttons when you need to! Have fun!",
			sf::Color(0, 128, 0));
}


TutorialLevelState::~TutorialLevelState() {
	delete this->backButton;
	delete this->gameInstructions;
	delete this->startButton;
}

void TutorialLevelState::pause() {
	//
}

void TutorialLevelState::resume() {
	//
}



void TutorialLevelState::update() {
	sf::Vector2<int> mousePos = sf::Mouse::getPosition(window);
	//Button logic
	this->startButton->update(sf::Vector2<float>(mousePos));
	this->backButton->update(sf::Vector2<float>(mousePos));


	while (window.pollEvent(sfEvent)) {
		switch (sfEvent.type) {
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseButtonPressed:
				if (this->backButton->isPressed() == true) { machine.run(machine.buildState<MainMenuState>(machine, window, true)); }
				if (this->startButton->isPressed() == true) { machine.run(machine.buildState<PlayingState>(machine, window, true)); }
				break;
		}
	}

	this->fpsCounter.update();
}

void TutorialLevelState::render() {
	window.clear();

	//Render items
	this->fpsCounter.renderTo(window);
	
	this->startButton->renderTo(window);
	this->backButton->renderTo(window);

	this->gameInstructions->renderTo(window);

	window.display();
}
