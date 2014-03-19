#pragma once

#include <SFML\System\Time.hpp>

#include "StateIdentifiers.h"

namespace sf
{
	class RenderWindow;
	class Event;
}

class StateStack;

class State
{
public:
	struct Context 
	{
		sf::RenderWindow* window;
	};

	State(StateStack* p_stateStack, Context p_context);
	~State();

	virtual bool update(sf::Time const& p_deltaTime) = 0;
	virtual bool handleEvent(sf::Event const& event) = 0;
	virtual bool render() const = 0;

protected:
	Context getContext() const;

	void pop();
	void push(States::ID p_state);
	void clear();

private:
	Context m_context;
	StateStack* m_stateStack;
};