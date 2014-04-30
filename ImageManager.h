#include <SFML/Graphics.hpp>
#include <string>

#pragma once

using namespace std;

class ImageManager {
public:
	void addTexture(string, string);
	
	sf::Texture getImage(string);


};