#include "ToggleKey.h"


ToggleKey::ToggleKey(sf::Keyboard::Key key)
	: keyPressed(key){
}

bool ToggleKey::isKeyPressed() {
	if (delayClock.getElapsedTime().asSeconds() > 0.2) {
		if (sf::Keyboard::isKeyPressed(keyPressed)) {
			delayClock.restart();
			return true;
		}
	}
	return false;
}
