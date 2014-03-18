#include "State.h"

State::State(State::Context p_context)
	: 
	m_context(p_context)
{
	
}

State::~State()
{

}

State::Context State::getContext()
{
	return m_context;
}