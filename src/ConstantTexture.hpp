#pragma once
#include "p_texture.hpp"

class ConstantTexture : public p_texture
{
public:
	ConstantTexture();
	ConstantTexture(Vec3 color);
    virtual ~ConstantTexture();

	virtual Vec3 value(float u, float v, const Vec3& p) const;

private:
	Vec3 m_color;
};

