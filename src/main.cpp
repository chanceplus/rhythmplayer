#include <SFML/Graphics.hpp>

#include "parse/osuparser.h"

int main(void){
    // Create window
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "SFML works!", sf::State::Fullscreen);
    
    // Clocks initialization
    sf::Clock inputClock; // Clock used for timing inputs
    sf::Clock frameClock; // Clock used for frame times

    // Map initialization
    OsuParser osuParser;
    Map testMap = osuParser.parseMap("./assets/test/maps/4key/4key.osu");

    while (window.isOpen())
    {
        // Get time between end of last frame and start of new frame
        sf::Time frameTimeElapsed = frameClock.restart();

        // Poll events
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Render
        window.clear();



        window.display();
    }

    // Close window
    window.close();

    return 0;
}
