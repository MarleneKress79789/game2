
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
		unsigned windowL = 640;
		unsigned windowH = 480;
		//Style::Default <-> Resize+Exit+Titlebar
		sf::RenderWindow window(sf::VideoMode(200, 200), "Test!", sf::Style::Default);
		window.setSize(sf::Vector2u(windowL, windowH));	// change the size of the window
		window.setTitle("Game!");			// change the title of the window

		int h = 20;
		int l = 30;

		Map ThisMap = Map(l,h);
		ThisMap.GenerateMapContend(); 

		Player thisPlayer;
		thisPlayer.SetSpawn(l/2, h/2);
		thisPlayer.xPos = thisPlayer.spawnX; // x bloecke
		thisPlayer.xPos = thisPlayer.spawnY;

		thisPlayer.xPos = 32.0; // x bloecke
		thisPlayer.yPos = 32.0;

		// array[100] NpcListe;

		Block bloeke[2];//array mit allenmöglichen blöcken, an der stelle ihres ids.
/* correcte Map ausgabe in konsole

		for (int i = 0; i != ThisMap.height; i++) {
		

			for (int j = 0; j != ThisMap.lenght; j++) {
			
				if (ThisMap.MapMatrix[i][j] == 0) {
					cout << "0" ;
				}
				else if (ThisMap.MapMatrix[i][j] == 1) {
					cout << "1" ;
				}
				else cout << ThisMap.MapMatrix[i][j]<< ",";
			}
			cout << endl;
		}
*/		


		//sf::CircleShape shape(100.f);
		//shape.setFillColor(sf::Color::Green);


		// Load a block sprite to display
		sf::Texture texture;
		if (!texture.loadFromFile("Sprites/ErdBlock.png", sf::IntRect(0, 0, 15, 15)))////, sf::IntRect(0, 0, 15, 15) load a 15x15 rectangle that starts at (0, 0)(nur teil des bildes)
			return EXIT_FAILURE;
		sf::Sprite sprite(texture);
		 sprite.setTextureRect(sf::IntRect(0, 0, 15, 15));
		 sprite.setScale(1, 1);// set the absolute scale of the entity
		//sprite.setPosition(sf::Vector2f(10, 50)); // absolute position



		sf::Texture player;
		if (!player.loadFromFile("Sprites/Player.png"))////, sf::IntRect(0, 0, 15, 15) load a 15x15 rectangle that starts at (0, 0)(nur teil des bildes)
			return EXIT_FAILURE;
		sf::Sprite Psprite(player);
		


		// run the program as long as the window is open
		while (window.isOpen()) {
			// check all the window's events that were triggered since the last iteration of the loop

			sf::Event event;
			while (window.pollEvent(event)) {	// muss in selbem thread wie createWindow sein


				switch (event.type) {			// check the type of the event...

				case sf::Event::Closed:			// window closed
					window.close();
					return 0;


				case sf::Event::LostFocus:
					//myGame.pause();
					break;

				case sf::Event::GainedFocus:
					//myGame.resume();
					break;

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
					
				case sf::Event::KeyPressed:		// key pressed
					/*int a;					//ginge auch hiermit
					a = event.key.code;
					cout << a << " ";*/
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

			sf::Vector2u wSize = window.getSize();	//ret Vector2u
			windowH = wSize.y;
			windowL = wSize.x;
		//	cout << windowL << " ";

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