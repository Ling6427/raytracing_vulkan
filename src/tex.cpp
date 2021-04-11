#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <cstdint>

#define noiseWidth 1024
#define noiseHeight 1024

using namespace std;

double noise[noiseHeight][noiseWidth]; //the noise array


void generateNoise();
double smoothNoise(double x, double y);
double turbulence(double x, double y, double size);

int main(int argc, char *argv[])
{
	fstream file;
	file.open("tex.jpg", ios::out);
	file << "P3\n" << noiseWidth << " " << noiseHeight << "\n255\n";
	//screen(noiseWidth, noiseHeight, 0, "Random Noise");
	generateNoise();

	//ColorRGB color;

	for(int y = noiseHeight-1; y >=0 ; y--){
		for(int x = 0; x < noiseWidth; x++){
			float r = double(x) / (noiseWidth-1);
			float g = double(y) / (noiseHeight-1);
			float b = 0.25;

			//int ir = uint8_t(256 * noise[x][y]);
			//int ig = uint8_t(256 * noise[x][y]);
			//int ib = uint8_t(256 * noise[x][y]);
			int ir = uint8_t(256 * turbulence(x, y, 8192));
			int ig = uint8_t(256 * turbulence(x, y, 8192));
			int ib = uint8_t(256 * turbulence(x, y, 8192));
			//color.r = color.g = color.b = Uint8(256 * noise[x][y]);
			//pset(x, y, color);

			file << ir << " " << ig << " " << ib << "\n";		
			//cout << ir << " " << ig << " " << ib << endl;
		}

	}
	return 0;
}

void generateNoise()
{
	for (int y = 0; y < noiseHeight; y++){
		for (int x = 0; x < noiseWidth; x++){
			noise[y][x] = (rand() % 32768) / 32768.0;
		}
	}
}
double smoothNoise(double x, double y){
	//get fractional part of x and y
	double fractX = x - int(x);
	double fractY = y - int(y);

	//wrap around
	int x1 = (int(x) + noiseWidth) % noiseWidth;
	int y1 = (int(y) + noiseHeight) % noiseHeight;

	//neighbor values
	int x2 = (x1 + noiseWidth - 1) % noiseWidth;
	int y2 = (y1 + noiseHeight - 1) % noiseHeight;

	//smooth the noise with bilinear interpolation
	double value = 0.0;
	value += fractX * fractY * noise[y1][x1];
	value += (1 - fractX) * fractY * noise[y1][x2];
	value += fractX * (1 - fractY) * noise[y2][x1];
	value += (1 - fractX) * (1 - fractY) * noise[y2][x2];

	return value;
}
double turbulence(double x, double y, double size){
	double value = 0.0, initialSize = size;

	while(size >= 1)
	{
		value += smoothNoise(x / size, y / size) * size;
		size /= 256;
	}

	return(1024.0 * value / initialSize);
}
