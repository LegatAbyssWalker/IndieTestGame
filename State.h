#ifndef STATE_H
#define STATE_H

#include <memory>

#include "SFML/Graphics.hpp"

class StateMachine;

class State {
	public:
		State(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
		virtual ~State() = default;

		State(const State&) = delete;
		State& operator = (const State&) = delete;

		virtual void pause() = 0;
		virtual void resume() = 0;

		virtual void update() = 0;
		virtual void render() = 0;

		std::unique_ptr<State> nextState();

		bool isReplacing();

	protected:
		StateMachine& machine;
		sf::RenderWindow& window;

		bool replacing;
		
		std::unique_ptr<State> next;
};

#endif