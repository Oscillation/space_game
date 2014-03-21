#pragma once

#include <SFML\System\Time.hpp>

#include "StateIdentifiers.h"
#include "..\Resource Managers\ResourceManager.h"

namespace sf
{
	class RenderWindow;
	class Event;
	class Texture;
}

class StateStack;

class State
{
public:
	struct Context 
	{
		Context(sf::RenderWindow& p_window, ResourceManager<sf::Texture>& p_textures);

		sf::RenderWindow& window;
		ResourceManager<sf::Texture>& textures;
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