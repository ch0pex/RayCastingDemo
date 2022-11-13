#include "Particle.h"

Particle::Particle(sf::Vector2f pos)
{
	shape = new sf::CircleShape(); 
	shape->setRadius(10);
	shape->setFillColor(sf::Color::White); 
	shape->setPosition(pos);
	shape->setOrigin(sf::Vector2f(shape->getRadius(), shape->getRadius()));
	genRays(); 
}

void Particle::Update(sf::Vector2i mousePos, std::vector<sf::Vertex*> walls) {
	position = mousePos;
	for(Ray* ray : getRays()) ray->Update((sf::Vector2f)position, walls); 
	shape->setPosition(sf::Vector2f((float)position.x, (float)position.y));
	
}

void Particle::genRays() {
	for (size_t i = 0; i < 360; i++)
	{
		float rad = (i * 3.141592f) / 180;
		std::cout << sin(rad) << "," << cos(rad) << std::endl;
		rays.push_back(new Ray((sf::Vector2f) position, sf::Vector2f(sin(rad), cos(rad)))); 
	}
}



sf::CircleShape Particle::getShape(){ return *shape; }
std::vector<Ray*> Particle::getRays() { return rays; }
