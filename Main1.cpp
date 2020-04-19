
#include <SFML/Graphics.hpp>
//#include <Sprite.hpp>
#include "Map.h"
#include "Player.h"
#include "Block.h"

#include <iostream>
#include <array>

using namespace std;
using namespace sf;


int main(){


		// run the program as long as the window is open
		while (window.isOpen()) {
			// check all the window's events that were triggered since the last iteration of the loop

			sf::Event event;
			while (window.pollEvent(event)) {	// muss in selbem thread wie createWindow sein


				switch (event.type) {			// check the type of the event...



				case sf::Event::TextEntered:	//gibt text, für eingaben

					if (event.text.unicode < 128) {
						int richtung;
						richtung = event.text.unicode;
						//cout << richtung << " ";
						thisPlayer.Move(richtung);			//...
					}
					//if (event.text.unicode < 128)
					// std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
					break;

					// we don't process other types of events
				default:
					break;
				}
			}
			
			window.clear();

			//player Koordinaten
			float x = thisPlayer.xPos; // x bloecke
			float y = thisPlayer.yPos;
			//cout << x << " ";
			int blockSizeInPixel = 10;
			
/*
			
			for (int i = 0; i != ThisMap.height; i++) {

				for (int j = 0; j != ThisMap.lenght; j++) {


					if (ThisMap.MapMatrix[i][j] == 0) {
						continue;
					}
					else if (ThisMap.MapMatrix[i][j] == 1) {
						sprite.move(sf::Vector2f(j*15, i*15)); // offset relative to the current position
						window.draw(sprite);
						sprite.setPosition(sf::Vector2f(0, 0)); // absolute position
					}
					else cout << ThisMap.MapMatrix[i][j] << ",";
				}
		
			}
*/


			Psprite.setPosition(sf::Vector2f((windowH/8), (windowL/8))); // absolute position

			//m
			int pixeli = ((int)(y*10)) - (windowH / 2);
			int pixelj = ((int)(x*10)) - (windowL / 2);
		
			int i;
			int j;

			if (((int)(y)-windowH / 2  )  -  ((y)-windowH / 2 ) < 0) {
				i = (int)(y) - windowH / 2+1;
			}
			else i = (int)(y)-windowH / 2;
			
			if (((int)(x)-windowL / 2) - ((x)-windowL / 2) < 0) {
				j = (int)(x)-windowL / 2 +1;
			}
			else j = (int)(x)-windowL / 2;

			for (i = 0; i != ThisMap.height; i++) { // TODO vo anderen seiten beschränken
				pixeli = pixeli + 10;
				pixelj = (int)(x * 10) - windowL / 2;
				for (int j = 0; j != ThisMap.lenght; j++) {
					pixelj = pixelj + 10;

					if (ThisMap.MapMatrix[i][j] == 0) {
						continue;
					}
					else if (ThisMap.MapMatrix[i][j] == 1) {
						sprite.move(sf::Vector2f(pixelj, pixeli)); // offset relative to the current position
						window.draw(sprite);
						sprite.setPosition(sf::Vector2f(0, 0)); // absolute position
					}

					//else cout << ThisMap.MapMatrix[i][j] << ",";
				}
		
			}

	
			window.draw(Psprite);
			window.display();

		}
	return EXIT_SUCCESS;
}
