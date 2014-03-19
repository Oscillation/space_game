#include "State.h"
#include "StateStack.h"

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