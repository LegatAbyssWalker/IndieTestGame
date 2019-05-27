#include "Game.h"
#include "MoreInfo.h"

void Game::run() {
	window.create(sf::VideoMode(screenWidth, screenHeight), "Indie Game Development");
	window.setPosition({ window.getPosition().x, window.getPosition().y - 50 });
	window.setFramerateLimit(120);

	machine.run(StateMachine::buildState<MainMenuState>(machine, window, true));

	//Main game loop
	while (window.isOpen() && machine.running()) {
		machine.nextState();
		machine.update();
		machine.render();
	}
}
