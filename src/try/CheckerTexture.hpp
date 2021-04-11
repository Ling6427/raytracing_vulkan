#pragma once
#include "p_texture.hpp"

class CheckerTexture : public p_texture
{
public:
	CheckerTexture();
	CheckerTexture(std::shared_ptr<p_texture> t0, std::shared_ptr<p_texture> t1);
    virtual ~CheckerTexture();

	virtual Vec3 value(float u, float v, const Vec3& p) const;

private:
	std::shared_ptr<p_texture> m_odd;
	std::shared_ptr<p_texture> m_even;
};

