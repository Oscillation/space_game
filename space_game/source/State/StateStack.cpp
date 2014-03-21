#include "StateStack.h"
#include "State.h"

StateStack::StateStack(sf::RenderWindow& p_window, ResourceManager<sf::Texture>& p_textures)
	:
	m_context(p_window, p_textures)
{
	
}

StateStack::~StateStack()
{
}

void StateStack::update(sf::Time& p_deltaTime)
{
	for (auto itr = m_stack.begin(); itr != m_stack.end(); ++itr)
	{
		if (!(*itr)->update(p_deltaTime))
			break;
	}
	applyPendingChanges();
}

void StateStack::render()
{
	for (auto itr = m_stack.begin(); itr != m_stack.end(); ++itr)
	{
		if (!(*itr)->render())
			break;
	}
}

void StateStack::handleEvent(sf::Event const& event)
{
	for (auto itr = m_stack.begin(); itr != m_stack.end(); ++itr)
	{
		if (!(*itr)->handleEvent(event))
			break;
	}
}

void StateStack::push(States::ID p_state)
{
	Action action;
	action.operation = Operation::Push;
	action.state = p_state;
	m_actions.push(action);
}

void StateStack::pop()
{
	Action action;
	action.operation = Operation::Pop;
	action.state = States::NOSTATE;
	m_actions.push(action);
}

void StateStack::clear()
{
	Action action;
	action.operation = Operation::Clear;
	action.state = States::NOSTATE;
	m_actions.push(action);
}

bool StateStack::isEmpty() const
{
	return m_stack.empty();
}

void StateStack::applyPendingChanges()
{
	while (!m_actions.empty())
	{
		Action action = m_actions.front();
		m_actions.pop();

		switch (action.operation)
		{
		case Operation::Pop:
			m_stack.pop_back();
			break;

		case Operation::Push:
			m_stack.push_back(createState(action.state));
			break;

		case Operation::Clear:
			m_stack.clear();
			break;

		default:
			break;
		}
	}
}

std::unique_ptr<State> StateStack::createState(States::ID p_state)
{
	auto foundState = m_factories.find(p_state);
	return foundState->second();
}