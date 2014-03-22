#include "State.h"
#include "../Scene/SceneNode.h"
#include "../Scene/Entity.h"
#include "..\Scene\BackgroundNode.h"

#include <SFML\Graphics\View.hpp>

class GameState : public State
{
public:
	GameState(StateStack* p_stateStack, Context p_context);
	~GameState();

	bool update(sf::Time const& p_deltaTime);
	bool handleEvent(sf::Event const& event);
	bool render() const;

private:
	SceneNode baseNode;
	sf::View m_view;
};