#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "GameLoop.h"

void MainLoop() {
	//Style::Default <-> Resize+Exit+Titlebar
	sf::RenderWindow window(sf::VideoMode(200, 200), "Test!", sf::Style::Default);
	window.setSize(sf::Vector2u(640, 480));	// change the size of the window
	window.setTitle("Game!");			// change the title of the window


	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	// run the program as long as the window is open
	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop

		sf::Event event;
		while (window.pollEvent(event)) {	// muss in selbem thread wie createWindow sein


			switch (event.type) {			// check the type of the event...

			case sf::Event::Closed:			// window closed
				window.close();
				break;

			case sf::Event::LostFocus:
				//myGame.pause();
				break;

			case sf::Event::GainedFocus:
				//myGame.resume();
				break;

		/*	case sf::Event::TextEntered:	//gibt text, für eingaben
				if (event.text.unicode < 128)
					std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
				break;
*/
			case sf::Event::KeyPressed:		// key pressed
											//...
				break;

				// we don't process other types of events
			default:
				break;
			}
		}
		window.clear();
		window.draw(shape);
		window.display();

	}


}

GameLoop::GameLoop(){

}


GameLoop::~GameLoop(){

}
