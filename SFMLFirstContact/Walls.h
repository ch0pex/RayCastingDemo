#pragma once
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include <list>

class Walls {
private: 
	std::vector<sf::Vertex*> lines; 
	void createWall();
	int quantity; 
public: 
	Walls(int numWalls); 
	std::vector<sf::Vertex*> getWalls();
	void recalculate(); 
};