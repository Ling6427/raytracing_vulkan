#pragma once
//#include "Core/Vec3.h"

#include "Vec3.hpp"

class p_texture
{
public:
	virtual Vec3 value(float u, float v, const Vec3& p) const = 0;
};
