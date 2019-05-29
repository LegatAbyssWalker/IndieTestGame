#ifndef TEXT_H
#define TEXT_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include <iostream>

class Text {
	public:
		//Necessary information for text creation
		Text(float x, float y, int characterSize, std::string fontFile, std::string text, sf::Color textColor);

		void renderTo(sf::RenderWindow& window);

	private:
		sf::Font textFont;
		sf::Text text;
};

#endif