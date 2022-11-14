#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"	
#include <list>
#include "Ray.h"
#include <iostream>

class Particle 
{
private: 
	
	sf::CircleShape* shape; 
	std::vector<Ray*> rays;
	sf::CircleShape circle;
	void genRays(float res); 

public:
	Particle(sf::Vector2f pos, float res);
	void Update(sf::Vector2i, std::vector<sf::Vertex*> walls);
	sf::CircleShape getShape(); 
	std::vector<Ray*> getRays(); 
	sf::Vector2i position;
};

