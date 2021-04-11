#pragma once

#include "Vulkan/Sampler.hpp"
#include <memory>
#include <string>

namespace Assets
{
	class Texture final
	{
	public:

		static Texture LoadTexture(const std::string& filename, const Vulkan::SamplerConfig& samplerConfig);

		Texture& operator = (const Texture&) = delete;
		Texture& operator = (Texture&&) = delete;

		Texture() = default;
		Texture(const Texture&) = default;
		Texture(Texture&&) = default;
		~Texture() = default;

		const unsigned char* Pixels() const { return pixels_.get(); }
		int Width() const { return width_; }
		int Height() const { return height_; }

	private:

		Texture(int width, int height, int channels, unsigned char* pixels);

		Vulkan::SamplerConfig samplerConfig_;
		int width_;
		int height_;
		int channels_;
		std::unique_ptr<unsigned char, void (*) (void*)> pixels_;
	};
	/*

	class texture{
		public:
			virtual color value(double u, double v, const vec3& p) const = 0;
	};

	class solid_color : public texture{
		public:
			solid_color(){}
			solid_color(color c) : color_value(c){}

			solid_color(double red, double green, double blue) : solid_color(color(red, green, blue)){}
			virtual  color value(double u, double v, const vec3& p) const override{
				return color_value;
			}
		private:
			color color_value;	
	};

	class noise_texture : public texture{
		public:
			noise_texture(){}
			noise_texture(double sc) : scale(sc){}
			virtual color value(double u, double v, const vec3& p) const override{
				return color(1, 1, 1)*0.5*(1 + sin(scale*p.z() + 10*noise.turb(p)));
			}
		public:
			perlin noise;
			double scale;
	};*/
}
