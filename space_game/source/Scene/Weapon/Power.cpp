#include "Power.h"

Power::Power(const PowerType & p_type) : m_type(p_type){
	switch (m_type)
	{
	case PowerType::test:
		m_powerFunctions.push_back(powerTest);
		break;
	default:
		break;
	}
}

Power::~Power(){
	
}