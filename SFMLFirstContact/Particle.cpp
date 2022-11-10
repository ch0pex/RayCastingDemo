#include "Particle.h"

Particle::Particle(sf::Vector2f pos)
{
	shape = new sf::CircleShape(); 
	shape->setRadius(25);
	shape->setFillColor(sf::Color::White); 
	shape->setPosition(pos);
	shape->setOrigin(sf::Vector2f(shape->getRadius(), shape->getRadius()));
	ray = new Ray((sf::Vector2f) position, sf::Vector2f(1, 0)); 
}

void Particle::Update(sf::Vector2i mousePos, sf::Vertex* wall) {
	position = mousePos;
	ray->update((sf::Vector2f)position, wall); 
	shape->setPosition(sf::Vector2f((float)position.x, (float)position.y));
	
}

sf::CircleShape Particle::getShape(){ return *shape; }
Ray Particle::getRay() { return *ray; }
