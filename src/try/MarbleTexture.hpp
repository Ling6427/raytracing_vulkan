//#pragma once
//#include "Textures/Texture.h"
//#include "Utils/PerlinNoise.h"

#include "p_texture.hpp"
#include "PerlinNoise.hpp"

class MarbleTexture : public p_texture
{
	public:
    	MarbleTexture(float scale = 1.f);
    virtual ~MarbleTexture();

		virtual Vec3 value(float u, float v, const Vec3& p) const;
	
	private:
		float m_scale;
		PerlinNoise m_perlinNoise;
};
