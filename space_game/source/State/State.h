#pragma once

#include <SFML\System\Time.hpp>

namespace sf
{
	class RenderWindow;
	class Event;
}

class State 
{
public:
	class Context 
	{
		sf::RenderWindow* window;
	};

	State(Context p_context);
	~State();

	virtual void update(sf::Time const& p_deltaTime) = 0;
	virtual void handleEvent(sf::Event& event) = 0;
	virtual void render() const = 0;

	Context getContext();

private:
	Context m_context;
};