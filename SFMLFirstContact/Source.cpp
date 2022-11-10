#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>
#include "Particle.h"
#include "Walls.h"
#include <list>

sf::Vector2f viewSize(1920, 1080); 
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow* window;
Particle* particle; 
sf::Mouse mouse; 
//std::vector<sf::Vertex*> walls;
Walls* boundries; 


void init() {
    srand(time(NULL));
    boundries = new Walls();
    window = new sf::RenderWindow(vm, "Raycasting 2d demo", sf::Style::Default);
    particle = new Particle(sf::Vector2f(viewSize.x / 2, viewSize.y / 2));
    
}

void draw() {

    for (sf::Vertex* wall : boundries->getWalls()) window->draw(wall, 2, sf::Lines); 
    window->draw(particle->getShape());
    window->draw(particle->getRay().getLine(), 2, sf::Lines);

}



void UpdateInput() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if ( event.type == sf::Event::Closed) {
            window->close();        
        }
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::R)
                boundries->recalculate();
            else if (event.key.code == sf::Keyboard::Space)
                window->close();
            else if (event.key.code == sf::Keyboard::C)
                std::cout << particle->getRay().detectColide(boundries->getWalls().at(0)) << std::endl;
        }
                
    }             
}





int main() {
    init();

    //init game objects 
    while (window->isOpen()) {
        // Handle Keyboard events 
        UpdateInput();

        // Update Game Objects in the scene 
        window->clear(sf::Color::Black);
        particle->Update(mouse.getPosition(*window), boundries->getWalls().at(0));
        
        draw(); 

        // Render Game Objects  
        window->display();
    };
    
    return 0;
}