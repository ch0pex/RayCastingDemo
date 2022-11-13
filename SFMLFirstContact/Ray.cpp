#include "Ray.h"

Ray::Ray(sf::Vector2f pos, sf::Vector2f direc)
{
	dir = normalize(direc);
	line[0] = pos;
	line[1].position = line[0].position + mulVec(dir, 10000000);

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

bool Ray::lowerDist(sf::Vector2f vec1, sf::Vector2f vec2) 
{
	float dist1 = sqrt(vec1.x * vec1.x + vec1.y * vec1.y);
	float dist2 = sqrt(vec2.x * vec2.x + vec2.y * vec2.y);
	if (dist1 < dist2) return true; 
	return false; 
}

bool Ray::detectColide(std::vector<sf::Vertex*> walls) {
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;
	float x4;
	float y4;
	float den;
	float t;
	float u;
	size_t i = 0; 
	sf::Vector2f hit = line[0].position + mulVec(dir, 10000); 
	//const float x4 = line[0].position.x + dir.x * sqrt(pow(line[1].position.x, 2) + pow(line[1].position.y, 2));
	//const float y4 = line[0].position.y + dir.y * sqrt(pow(line[1].position.x, 2) + pow(line[1].position.y, 2));
	for (sf::Vertex* wall : walls) {
		x1 = wall->position.x;
		y1 = wall->position.y;
		x2 = (wall + 1)->position.x;
		y2 = (wall + 1)->position.y;
		x3 = line[0].position.x;
		y3 = line[0].position.y;
		x4 = line[0].position.x + dir.x;
		y4 = line[0].position.y + dir.y;
		den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
		if (!den)
			return false;
		t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
		u = - ((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

		if (t > 0 && t < 1 && u > 0) {
	
			sf::Vector2f newHit(x1 + t * (x2 - x1), y1 + t * (y2 - y1));
			if (lowerDist(newHit, hit))
				hit = newHit; 
			
		}
	}
	line[1] = hit; 
	if (hit == line[0].position + mulVec(dir, 10000000)) 
		return false;
	return true; 

}



void Ray::Update(sf::Vector2f pos, std::vector<sf::Vertex*> walls) {
	line[0] = pos;
	detectColide(walls);
	
}

sf::Vertex* Ray::getLine() { return line; }