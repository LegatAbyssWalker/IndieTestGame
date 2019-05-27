#include "Player.h"
#include "MoreInfo.h"


Player::Player() {
	mTexture.loadFromFile("res/images/skeletonSpriteSheet.png");
	mPlayer.setTexture(mTexture);

	sf::Vector2<unsigned> individualCharacter = mTexture.getSize();
	individualCharacter.x /= 9;
	individualCharacter.y /= 4;

	mPlayer.setTextureRect(sf::IntRect(individualCharacter.x * 0, individualCharacter.y * 2, individualCharacter.x, individualCharacter.y));
	mPlayer.setOrigin(individualCharacter.x / 2, individualCharacter.y / 2);
}

void Player::drawTo(sf::RenderWindow& window) {
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
	if (getX() <= screenWidth)      { setPlayerPos(sf::Vector2<float>(getX() - playerBorderSpeed, getY())); } //Right
	if (getY() <= screenHeight * 0) { setPlayerPos(sf::Vector2<float>(getX(), getY() + playerBorderSpeed)); } //Top
	if (getY() <= screenHeight)     { setPlayerPos(sf::Vector2<float>(getX(), getY() - playerBorderSpeed)); } //Bottom
}

sf::FloatRect Player::getGlobalBounds() {
	return mPlayer.getGlobalBounds();
}