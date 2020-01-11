#pragma once
#include <iostream>
#include "element.h"
#include "attribute.h"
#include <SFML/Graphics.hpp>

class Renderer {
    private:
        Element e;
    public:
        Renderer(Element e) {
            this->e = e;
        }

        void init() {
            sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
            sf::CircleShape shape(100.f);
            shape.setFillColor(sf::Color::Green);

            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                window.clear();
                window.draw(shape);
                window.display();
            }
        }
};