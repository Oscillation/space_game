#include "Power.h"

Power::Power(const PowerType & p_type) : m_type(p_type){
	switch (m_type)
	{
	case PowerType::test:
		m_life = 10.f;
		m_powerFunctions.push_back(powerTest);
		m_powerFunctions.push_back(eheheh);
		break;
	default:
		break;
	}
}

Power::~Power(){
	
}