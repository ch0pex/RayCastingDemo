#include "Ray.h"

Ray::Ray(sf::Vector2f pos, sf::Vector2f direc)
{
	dir = normalize(direc);
	

}
sf::Vector2f Ray::normalize(sf::Vector2f vec) {
	sf::Vector2f normVec; 
	float len = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
	normVec.x = vec.x / len;
	normVec.y = vec.y / len;
	return normVec; 
}

sf::Vector2f Ray::mulVec(sf::Vector2f vec, float mul)
{
	sf::Vector2f newVec; 
	newVec.x = vec.x * mul; 
	newVec.y = vec.y * mul; 
	return newVec; 
}

void Ray::lookAt(sf::Vector2f)
{
	
}
bool Ray::detectColide(sf::Vertex* wall) {
	const float x1 = wall->position.x; 
	const float y1 = wall->position.y;
	const float x2 = (wall + 1)->position.x; 
	const float y2 = (wall + 1)->position.y;

	const float x3 = line[0].position.x; 
	const float y3 = line[0].position.y; 
	const float x4 = line[1].position.x; 
	const float y4 = line[1].position.y; 

	const float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4); 
	if (!den)
		return false; 
	const float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den; 
	const float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den; 
	if (t > 0 && t < 1 && u > 0) {
		line[1].position.x = x1 + t * (x2 - x1);
		line[1].position.y = y1 + t * (y2 - x1);
		return true;
	}

	return false; 
}



void Ray::update(sf::Vector2f pos, sf::Vertex* wall) {
	line[0] = pos;
	if (!detectColide(wall)) 
		line[1] = pos + mulVec(dir, 2000);
	
	

}

sf::Vertex* Ray::getLine() { return line; }