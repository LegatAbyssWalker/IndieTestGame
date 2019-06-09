#include "Player.h"
#include "MoreInfo.h"


Player::Player() {
	mTexture.loadFromFile("res/images/playerTank.png");
	mPlayer.setTexture(mTexture);

	sf::Vector2<unsigned> individualCharacter = mTexture.getSize();
	individualCharacter.x /= 1;
	individualCharacter.y /= 1;

	mPlayer.setTextureRect(sf::IntRect(individualCharacter.x * 0, individualCharacter.y * 0, individualCharacter.x, individualCharacter.y));
	mPlayer.setOrigin(individualCharacter.x / 2, individualCharacter.y / 2);
}

void Player::renderTo(sf::RenderWindow& window) {
	window.draw(mPlayer);
}

void Player::moveTo(sf::Vector2<float> distance) {
	mPlayer.move(distance);
}

void Player::setPlayerPos(sf::Vector2<float> newPos) {
	mPlayer.setPosition(newPos);
}

int Player::getX() {
	return mPlayer.getPosition().x;
}

int Player::getY() {
	return mPlayer.getPosition().y;
}

void Player::updateBorderBounds() {
	if (getX() <= screenWidth * 0)  { setPlayerPos(sf::Vector2<float>(getX() + playerBorderSpeed, getY())); } //Left
	if (getX() >= screenWidth)      { setPlayerPos(sf::Vector2<float>(getX() - playerBorderSpeed, getY())); } //Right
}

sf::FloatRect Player::getGlobalBounds() {
	return mPlayer.getGlobalBounds();
}

bool Player::collisionWithEnemy(Enemy* enemy) {
	if (getGlobalBounds().intersects(enemy->getGlobalBounds())) {
		return true;
	}
	return false;
}
