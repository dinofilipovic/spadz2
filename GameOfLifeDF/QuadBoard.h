#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <vector>

#include "Config.h"

class QuadBoard
{
    public:
        QuadBoard(const Config& config);

        void addQuad        (unsigned x, unsigned y, sf::Color& colour);
        void setQuadColour  (unsigned x, unsigned y, sf::Color& colour);

        void draw(sf::RenderWindow& window);

    private:
        unsigned getQuadIndex(unsigned x, unsigned y) const;
        void makeGrid();

        std::vector<sf::Vertex>     m_grid;
        std::vector<sf::Vertex>     m_pixels;

        const Config CONFIG;
};
