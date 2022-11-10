#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"	
#include <math.h>
#include <iostream>
class Ray
{
private: 
	sf::Vertex line[2];
	sf::Vector2f dir;
	sf::Vector2f normalize(sf::Vector2f vec);
	sf::Vector2f mulVec(sf::Vector2f vec, float mul);
public:
	Ray(sf::Vector2f pos, sf::Vector2f vec); 
	void lookAt(sf::Vector2f); 
	bool detectColide(sf::Vertex* wall);
	void update(sf::Vector2f pos, sf::Vertex* wall);
	sf::Vertex* getLine(); 


};

