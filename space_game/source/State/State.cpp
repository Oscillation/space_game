#include "State.h"
#include "StateStack.h"
#include "..\Resource Managers\ResourceManager.h"

State::Context::Context(sf::RenderWindow& p_window, ResourceManager<sf::Texture>& p_textures)
	:
	window(p_window),
	textures(p_textures)
{
}

State::State(StateStack* p_stateStack, State::Context p_context)
	: 
	m_stateStack(p_stateStack),
	m_context(p_context)
{
}

State::~State()
{
}

State::Context State::getContext() const
{
	return m_context;
}

void State::pop()
{
	m_stateStack->pop();
}

void State::push(States::ID p_state)
{
	m_stateStack->push(p_state);
}

void State::clear()
{
	m_stateStack->clear();
}