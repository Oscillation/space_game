#include "State.h"
#include "../Scene/SceneNode.h"
#include "../Scene/Entity.h"
#include "..\Scene\BackgroundNode.h"

class GameState : public State
{
public:
	GameState(StateStack* p_stateStack, Context p_context);
	~GameState();

	bool update(sf::Time const& p_deltaTime);
	bool handleEvent(sf::Event const& event);
	bool render() const;

	void spawnAsteroids();

private:
	SceneNode baseNode;
};