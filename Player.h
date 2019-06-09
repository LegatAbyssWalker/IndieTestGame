#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include "Enemy.h"

class Player {
	public:
		Player();

		//Functions
		void renderTo(sf::RenderWindow& window);
		void moveTo(sf::Vector2<float> distance);
		void setPlayerPos(sf::Vector2<float> newPos);
		int getX();
		int getY();
		void updateBorderBounds();
		sf::FloatRect getGlobalBounds();
		bool collisionWithEnemy(Enemy* enemy);


	private:
		sf::Texture mTexture;
		sf::Sprite mPlayer;

		const unsigned int playerBorderSpeed = 30;

		//Class objects

};

#endif