#pragma once

#include <vector>
#include <queue>
#include <map>
#include <memory>
#include <functional>

#include <SFML\System\NonCopyable.hpp>
#include <SFML\System\Time.hpp>
#include <SFML\Window\Event.hpp>

#include "State.h"
#include "StateIdentifiers.h"

namespace sf
{
	class RenderWindow;
}

class StateStack : private sf::NonCopyable
{
public:
	StateStack(sf::RenderWindow* p_window);
	~StateStack();

	void update(sf::Time& p_deltaTime);
	void render();
	void handleEvent(sf::Event const& event);

	enum Operation
	{
		Pop,
		Push,
		Clear,
	};

	struct Action 
	{
		Operation operation;
		States::ID state;
	};

	template <class T>
	void registerState(States::ID p_state)
	{
		m_factories[p_state] = [this]() 
		{
			return std::unique_ptr<State>( new T(this, m_context));
		};
	}

	void push(States::ID p_state);
	void pop();
	void clear();

	bool isEmpty() const;

	void applyPendingChanges();

private:
	std::vector<std::unique_ptr<State> > m_stack;
	std::queue<Action> m_actions;
	std::map<States::ID, std::function<std::unique_ptr<State>()> > m_factories;

	State::Context m_context;

	

	std::unique_ptr<State> createState(States::ID p_state);
};

