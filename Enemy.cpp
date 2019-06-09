#include "Enemy.h"



Enemy::Enemy() {
	//Enemy texture
	texture.loadFromFile("res/images/enemyTank.png");
	enemy.setTexture(texture);

	sf::Vector2<unsigned> individualCharacter = texture.getSize();
	individualCharacter.x /= 1;
	individualCharacter.y /= 1;

	enemy.setTextureRect(sf::IntRect(individualCharacter.x * 0, individualCharacter.y * 0, individualCharacter.x, individualCharacter.y));
	enemy.setOrigin(individualCharacter.x / 2, individualCharacter.y / 2);
}


Enemy::~Enemy() {
	//
}


void Enemy::renderTo(sf::RenderWindow& window) {
	window.draw(enemy);
}

void Enemy::setEnemyPos(sf::Vector2<float> newPos) {
	enemy.setPosition(newPos);
}

int Enemy::getX() {
	return enemy.getPosition().x;
}

int Enemy::getY() {
	return enemy.getPosition().y;
}

void Enemy::moveTo(int enemySpeed) {
	enemy.move(enemySpeed, 0);
}

sf::FloatRect Enemy::getGlobalBounds() {
	return enemy.getGlobalBounds();
}
