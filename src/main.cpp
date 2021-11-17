#include <cmath>
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include "World.hpp"


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;
    // create the window
    sf::RenderWindow window(sf::VideoMode(160, 100), "Netting-cut", sf::Style::Default);
    window.setVerticalSyncEnabled(false);

    World world;

    // world.addCloth(20, 20, 50, 50);
    // world.addCloth(1000, 20, 50, 50);
    world.addCloth(0, 50, 80, 80);
    bool click = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Esc is exist the windows
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                click = true;
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                click = false;
            }

        }

        window.clear(sf::Color::White);

        sf::Vector2i localPosition = sf::Mouse::getPosition(window);

        if (click)
            world.cut_update(localPosition.x, localPosition.y);
        else
            world.cut_update(-10000.0f, -10000.0f);

        world.render(window);
        window.display();

    }

    return 0;
}
