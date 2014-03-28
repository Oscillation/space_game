#pragma once
#include <functional>
#include "Bullet.h"
#include "..\World.h"

enum PowerType{
	test,
};

struct Power{
	Power(const PowerType & p_type);
	~Power();

	///<summary>In seconds. Terminate when == 0.</summary>
	float m_life;

	///<summary>Functions that modify the bullet.</summary>
	std::vector<std::function<void(Bullet* ptr_bullet, World & p_world)>> m_powerFunctions;

private:
	PowerType m_type;
};

static void powerTest(Bullet* ptr_bullet, World & p_world){
	
}