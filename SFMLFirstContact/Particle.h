#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"	
#include <list>
#include "Ray.h"

class Particle 
{
private: 
	sf::Vector2i position; 
	sf::CircleShape* shape; 
	Ray* ray; 
	


public:
	Particle(sf::Vector2f pos);
	void Update(sf::Vector2i, sf::Vertex* wall);
	sf::CircleShape getShape(); 
	Ray getRay(); 
};

