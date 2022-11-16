#include "Walls.h"

Walls::Walls(int numWalls) {
	for (size_t i = 0; i < numWalls; i++)
	{
		 quantity = numWalls; 
		createWall(); 
	}
}

void Walls::createWall() {
	sf::Vertex* line = new sf::Vertex[2]();
	line[1] = sf::Vertex(sf::Vector2f(rand() % 1920, rand() % 1080));
	line[0] = sf::Vertex(sf::Vector2f(rand() % 1920, rand() % 1080));
	lines.push_back(line);
}

std::vector<sf::Vertex*> Walls::getWalls() {
	return lines; 
}

void Walls::recalculate() {
	lines.clear(); 
	for (size_t i = 0; i < quantity; i++)
		createWall();

}
