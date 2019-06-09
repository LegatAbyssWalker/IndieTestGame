#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include "PlaySound.h"

#include <iostream>

class Enemy {
	public:
		Enemy();
		~Enemy();

		void renderTo(sf::RenderWindow& window);
		void setEnemyPos(sf::Vector2<float> newPos);
		int getX();
		int getY();
		void moveTo(int enemySpeed);
		sf::FloatRect getGlobalBounds();

	private:
		//Class objects
		PlaySound playSound;


		sf::Texture texture;
		sf::Sprite enemy;
};

#endif