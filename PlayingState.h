#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System/Vector2.hpp"

#include "State.h"
#include "FPSCounter.h"

#include "Player.h"
#include "Enemy.h"
#include "PlaySound.h"
#include "Bullet.h"


#include "MainMenuState.h"

class StateMachine;

class PlayingState : public State {
	public:
		PlayingState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
		~PlayingState();

		void pause();
		void resume();

		void handleKeyboardInput(sf::Keyboard::Key key, bool isPressed);

		void update();
		void render();

	private:
		//Vectors
		std::vector<Bullet*> bulletVector;
		std::vector<Enemy*> enemyVector;


		//Class objects
		Player player;
		Enemy enemy[3];
		PlaySound playSound;
		Bullet bullet[5];
		FPSCounter fpsCounter;
	


		//Booleans and Variables
		const int playerSpeed = 2;
		const int enemySpeed  = 1;
		const int bulletSpeed = 5;

		unsigned int bulletCount = 1;

		bool isMovingLeft   = false;
		bool isMovingRight  = false;
		bool isBulletFiring = false;
		


		//SFML Events
		sf::Event sfEvent;
		sf::Clock bulletClock;
		float bulletTimer;
};

#endif