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
	bool lowerDist(sf::Vector2f vec1, sf::Vector2f vec2); 
	
public:
	Ray(sf::Vector2f pos, sf::Vector2f vec); 
	bool detectColide(std::vector<sf::Vertex*> walls);
	void Update(sf::Vector2f pos, std::vector<sf::Vertex*> walls);
	sf::Vertex* getLine(); 
	sf::CircleShape circle;

};

 