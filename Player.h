#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"


class Player {
	public:
		Player();

		//Functions
		void drawTo(sf::RenderWindow& window);
		void moveTo(sf::Vector2<float> distance);
		void setPlayerPos(sf::Vector2<float> newPos);
		int getX();
		int getY();
		void updateBorderBounds();
		sf::FloatRect getGlobalBounds();

		//


	private:
		sf::Texture mTexture;
		sf::Sprite mPlayer;

		const unsigned int playerBorderSpeed = 30;

		//Class objects

};

#endif