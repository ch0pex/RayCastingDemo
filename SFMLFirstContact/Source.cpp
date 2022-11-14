#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include <iostream>
#include "Particle.h"
#include "Walls.h"
#include <list>
#include<windows.h>

 

sf::RenderWindow* window;
Particle* particle; 
sf::Mouse mouse; 
Walls* boundries; 


void init(int resMode = 1080, float rayRes = 1) {
    switch (resMode)
    {
    case 1080: 
        sf::Vector2f viewSize(1920, 1080);
        break;
    case 800: 
        sf::Vector2f viewSize(800, 800);
        break;
    case 720: 
        sf::Vector2f viewSize(1280, 720);
        break;
    default:
        std::cout << "ResMode was wrong, it must be 1080, 800, or 720" << std::endl;
        Sleep(5); 
        exit(-1);
        break;
    }
    sf::Vector2f viewSize(1920, 1080);
    sf::VideoMode vm(viewSize.x, viewSize.y);
    srand(time(NULL));
    boundries = new Walls();
    window = new sf::RenderWindow(vm, "Raycasting 2d demo", sf::Style::Default);
    particle = new Particle(sf::Vector2f(viewSize.x / 2, viewSize.y / 2));
    
}

void draw() {

    for (sf::Vertex* wall : boundries->getWalls()) window->draw(wall, 2, sf::Lines); 
    window->draw(particle->getShape());
    for (Ray* ray : particle->getRays()) window->draw(ray->getLine(), 2, sf::Lines); 
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
        }
                
    }             
}




int main(int argc, char* argv[]) {
    if (argc == 2 && argc > 5) {
        std::cout << "Wrong arguments" << std::endl; 
        exit(-1); 
    }

        

    init();
    //init game objects 
    while (window->isOpen()) {
        // Handle Keyboard events 
        UpdateInput(); 
        // Update Game Objects in the scene 
        window->clear(sf::Color::Black);
        particle->Update(mouse.getPosition(*window), boundries->getWalls());
        
        draw(); 

        // Render Game Objects  
        window->display();
    };
    
    return 0;
}






