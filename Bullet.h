#ifndef BULLET_H
#define BULLET_H

#include "SFML/Graphics.hpp"
#include "SFML/System/Vector2.hpp"

#include "Enemy.h"
#include <iostream>

class Bullet {
	public:
		Bullet();
		~Bullet();

		void renderTo(sf::RenderWindow& window);
		void setBulletPos(sf::Vector2<float> newPos);
		void fireBullet(int speed);
		void addNewBullet(std::string bulletFile, int xDivide, int yDivide, int parameter1, int parameter2);
		sf::FloatRect getGlobalBounds();

		bool collisionWithEnemy(Enemy* enemy);

	private:
		//Class objects
		Enemy enemy;
		PlaySound playSound;

		sf::Texture texture;
		sf::Sprite bullet;
};

#endif