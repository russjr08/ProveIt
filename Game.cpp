//
//  Game.cpp
//  SFMLGame
//
//  Created by Russell Richardson on 4/24/14.
//  Copyright (c) 2014 KronosAD. All rights reserved.
//

#include "Game.h"
#include "SoundManager.h"
#include <iostream>

#include <SFML/Audio.hpp>

using namespace std;

// Initialize a few variables here and there...

sf::Vector2f screen_size(800, 600);

sf::RenderWindow window;

sf::Texture bg_texture;
sf::Sprite bg;

vector<Entity> entities;

sf::View camera(sf::FloatRect(screen_size.x, screen_size.y, screen_size.x/2, screen_size.y/2));
sf::Vector2f camera_pos;

SoundManager sound;



// Constructor and or initializer for game. This is called when the program is ran!
Game::Game(string title){
	// Create a window with a specific width and height, a title, and a title bar with only the close (and minimize) buttons.
    window.create(sf::VideoMode(screen_size.x, screen_size.y), title, sf::Style::Close|sf::Style::Titlebar);
    
	// Initialize the texture by loading it from a file (Temporary texture)
    bg_texture.loadFromFile("res/bg/Level1.png");
    bg_texture.setRepeated(true);
    bg.setTexture(bg_texture);
	bg.setTextureRect(sf::IntRect(800, 600, 800, 600));

    bg.setPosition(0, 0);
	// Upscale the background by a factor of 1.2 on the X axis.
    bg.scale(5, 5);
    
	// Adds a new Entity to the entities array, with the following sprite.
    entities.push_back(Entity("res/player/Robot.png"));

	// Assigns the player pointer value to the memory address of the first entity.
    player = &entities[0];

	// Don't allow the game to run faster than 60 Frames Per Second
    window.setFramerateLimit(60);

	// Use the SoundManager class to add a new sound (Music) to the game music map (Key/Value based)
	sound.addMusic("background", "res/testing-resource/audio/music/new_back_music.wav");
	sound.getMusic("background")->setVolume(25);
	sound.playMusic("background");    
}

// This is called when the game closes. It's job is to make sure all resources are closed properly!
void Game::close(){
    for(Entity& e : entities){
        e.closeResources();
    }
}

// Called on the "opening" state of the game. Sets window title and prepares graphics.
void Game::open(){
    window.setTitle("Prove It! (BETA COPY)");

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
				this->close();
                window.close();
            }
        }
        update();
        window.setView(camera);
        camera_pos.x = 0;
        camera.reset(sf::FloatRect(camera_pos.x, camera_pos.y, screen_size.x, screen_size.y));
        window.clear(sf::Color(200, 0, 0));
        window.draw(bg);
        render();
        window.display();
    }
}

// Called on the "update" state of the game. Updates entities and other components of the game.
void Game::update(){
    for(Entity& e : entities){
        e.update();
    }
    

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        player->position.y -= 5;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        player->position.y += 5;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        player->position.x -= 5;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        player->position.x += 5;
    }
    
    camera_pos.y = player->position.y + player->entity_size.y - (screen_size.y / 2);
    
    if(player->position.x > screen_size.x / 2){
        camera_pos.x = player->position.x + player->entity_size.x - (screen_size.x / 2);
        camera.reset(sf::FloatRect(camera_pos.x, camera_pos.y, screen_size.x, screen_size.y));
    }
    if(player->position.x < screen_size.x / 2){
//        camera_pos.x = player->position.x + player->entity_size.x - (screen_size.x / 2);
//        camera.reset(sf::FloatRect(camera_pos.x, camera_pos.y, screen_size.x, screen_size.y));
    }
}

// The "render" state of the game. Enumerates through all of the entities and calls their draw/render function.
void Game::render(){

    for(Entity& e : entities){
        e.draw(window);
    }
}




