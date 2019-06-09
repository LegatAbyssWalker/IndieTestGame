#include "PlayingState.h"

#include "State.h"
#include "StateMachine.h"
#include "MoreInfo.h"

class StateMachine;

//Other header files


PlayingState::PlayingState(StateMachine& machine, sf::RenderWindow& window, bool replace) 
	: State{ machine, window, replace }  {


	//Player information
	player.setPlayerPos(sf::Vector2<float>(screenWidth / 3, groundHeight));


	//Enemy information
	enemyVector.push_back(&enemy[0]);
	enemyVector.push_back(&enemy[1]);
	enemyVector.push_back(&enemy[2]);

	enemy[0].setEnemyPos({ screenWidth - 200, groundHeight });
	enemy[1].setEnemyPos({ screenWidth + 200, groundHeight });
	enemy[2].setEnemyPos({ screenWidth + 500, groundHeight });


	//Bullet information
	bulletVector.push_back(&bullet[0]);
	bulletVector.push_back(&bullet[1]);
	bulletVector.push_back(&bullet[2]);
	bulletVector.push_back(&bullet[3]);
	bulletVector.push_back(&bullet[4]);

	
	//Audio information
	//playSound.setMusic("res/audio/gameMusic.wav", 50, true);

}


PlayingState::~PlayingState() {
	//
}

void PlayingState::pause() {
	//
}

void PlayingState::resume() {
	//
}

void PlayingState::handleKeyboardInput(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::A)		{ isMovingLeft = isPressed; }
	if (key == sf::Keyboard::D)		{ isMovingRight = isPressed; }
	if (key == sf::Keyboard::Space) { isBulletFiring = isPressed; }

	/*ADMIN ONLY -- RESET PLAYER POSITION*/
	if (key == sf::Keyboard::R) { player.setPlayerPos(sf::Vector2<float>(window.getSize().x / 2, groundHeight)); }
}

void PlayingState::update() {
	while (window.pollEvent(sfEvent)) {
		switch (sfEvent.type) {
		case sf::Event::Closed:
			machine.quit();
			break;

		case sf::Event::KeyPressed:
			handleKeyboardInput(sfEvent.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handleKeyboardInput(sfEvent.key.code, false);
			break;
		}
	}
	/*------------------------------------------------------------------------------------------------------------------*/
	player.updateBorderBounds();
	fpsCounter.update();

	//Player movement information
	sf::Vector2<float> playerMovement(0.f, 0.f);
	if (isMovingLeft) { playerMovement.x -= playerSpeed; }
	if (isMovingRight) { playerMovement.x += playerSpeed; }
	player.moveTo(playerMovement);

	//Get player coordinates
	//std::cout << "X: " << player.getX() << " Y: " << player.getY() << '\n';

	//Bullet logic
	sf::Vector2<float> bulletMovement(0.f, 0.f);
	if (isBulletFiring) {
		//The player has a bullet limit of 3
		//If the player has 3 or less bullets remaining, use this if statement
		if (bulletCount <= 4) {
			playSound.setSound("res/audio/bulletSound.wav", 20, false);
			switch (bulletCount) {
			case 1:
				bullet[0].addNewBullet("res/images/bulletImage.png", 1, 1, 0, 0);
				bullet[0].setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
				break;

			case 2:
				bullet[1].addNewBullet("res/images/bulletImage.png", 1, 1, 0, 0);
				bullet[1].setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
				break;

			case 3:
				bullet[2].addNewBullet("res/images/bulletImage.png", 1, 1, 0, 0);
				bullet[2].setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
				break;

			case 4:
				bullet[3].addNewBullet("res/images/bulletImage.png", 1, 1, 0, 0);
				bullet[3].setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
				break;

			case 5:
				bullet[4].addNewBullet("res/images/bulletImage.png", 1, 1, 0, 0);
				bullet[4].setBulletPos(sf::Vector2<float>(player.getX() + 50, player.getY() - 20));
				break;
			}

			bulletCount += 1;
			isBulletFiring = false;
		}

		//If not, then use this if statement
		if (bulletCount >= 5) {
			playSound.setSound("res/audio/tankAmmunitionGoneSoundEffect.wav", 20, false);
			isBulletFiring = false;
			bulletTimer = bulletClock.getElapsedTime().asSeconds();

			if (bulletTimer >= 3.000) {
				bulletCount = 0;
				bulletClock.restart();
			}
		}
	}

	for (int i = 0; i < bulletVector.size(); i++) {
		bulletVector[i]->fireBullet(bulletMovement.x + bulletSpeed);
	}


	//Enemy logic
	sf::Vector2<float> enemyMovement(0.f, 0.f);
	for (int i = 0; i < enemyVector.size(); i++) {
		//Bullet collision with enemy
		if (bullet[0].collisionWithEnemy(enemyVector[i])) { enemyVector[i]->setEnemyPos({ 10000, 10000 }); }
		if (bullet[1].collisionWithEnemy(enemyVector[i])) { enemyVector[i]->setEnemyPos({ 10000, 10000 }); }
		if (bullet[2].collisionWithEnemy(enemyVector[i])) { enemyVector[i]->setEnemyPos({ 10000, 10000 }); }
		if (bullet[3].collisionWithEnemy(enemyVector[i])) { enemyVector[i]->setEnemyPos({ 10000, 10000 }); }
		if (bullet[4].collisionWithEnemy(enemyVector[i])) { enemyVector[i]->setEnemyPos({ 10000, 10000 }); }

		//Player collision with enemy
		if (player.collisionWithEnemy(enemyVector[i])) {
			machine.run(machine.buildState<MainMenuState>(machine, window, true));
		}
		
		//Enemy movements
		enemyVector[i]->moveTo(enemyMovement.x -= enemySpeed);
	}
}

void PlayingState::render() {
	window.clear();

	//Render items
	fpsCounter.renderTo(window);
	player.renderTo(window);

	for (int x = 0; x < enemyVector.size(); x++)  { enemyVector[x]->renderTo(window); }
	for (int x = 0; x < bulletVector.size(); x++) { bulletVector[x]->renderTo(window); }



	window.display();
}
