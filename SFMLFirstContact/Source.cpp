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



int init(int resMode = 1080, float rayRes = 1) {
    sf::Vector2f viewSize;
    switch (resMode)
    {
    case 1080: 
        viewSize = sf::Vector2f(1920, 1080) ;
        break;
    case 800: 
        viewSize = sf::Vector2f(800, 800);
        break;
    case 720: 
        viewSize = sf::Vector2f(1280, 720);
        break;
    default:
        std::cout << "ResMode was wrong, it must be 1080, 800, or 720" << std::endl;
        Sleep(5); 
        return(0); 
    }
    
    sf::VideoMode vm(viewSize.x, viewSize.y);
    srand(time(NULL));
    boundries = new Walls();
    window = new sf::RenderWindow(vm, "Raycasting 2d demo", sf::Style::None);
    particle = new Particle(sf::Vector2f(viewSize.x / 2, viewSize.y / 2), rayRes);
    return (1);
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




int main(int argc, char **argv) {
    int resMode = 1080; 
    float raysRes = 1; 
    
    if (argc == 2 || argc > 5) 
    {
        std::cout << "Wrong arguments" << std::endl; 
        return(0);
    }
    if (argc > 2 ) {
        if (argv[1][0] != '-') 
        {
            std::cout << "Wrong argumentes" << std::endl; 
            return(0); 
        }
        for (size_t i = 1; i < 5; i += 2) 
        {
            if (argv[i] && !strcmp(argv[i], "-s") && argv[i+1])
            {
                if (!strcmp(argv[i+1], "1080")) resMode = 1080;
                else if (!strcmp(argv[i+1], "720")) resMode = 720;
                else if (!strcmp(argv[i+1], "800")) resMode = 800;
                else
                {
                    std::cout << "Resolution mode must be: 1080 or 720 or 800" << std::endl;
                    return(0);
                }
            }
            else if (argv[i] && !strcmp(argv[i], "-r") && argv[i + 1]) {
                if (atoi(argv[i + 1])) 
                {
                    std::cout << "Entro aqui" << std::endl;
                    raysRes = atoi(argv[i + 1]);
                }
            }

        }

    }
       
    if(!init(resMode, raysRes)) return (0);
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






