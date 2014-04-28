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

sf::Vector2f screen_size(800, 600);

sf::RenderWindow window;

sf::Texture bg_texture;
sf::Sprite bg;

vector<Entity> entities;

sf::View camera(sf::FloatRect(screen_size.x, screen_size.y, screen_size.x/2, screen_size.y/2));
sf::Vector2f camera_pos;

SoundManager sound;




Game::Game(string title){
    window.create(sf::VideoMode(screen_size.x, screen_size.y), title);
    
    bg_texture.loadFromFile("res/testing-resource/bg/Galaxy.jpg");
    bg_texture.setRepeated(true);
    bg.setTexture(bg_texture);
    bg.setPosition(0, 0);
    bg.scale(1.2, 1);
    
    entities.push_back(Entity("res/player/Robot.png"));
    player = &entities[0];
    window.setFramerateLimit(60);

	sound.addMusic("background", "res/testing-resource/audio/music/new_back_music.wav");
	sound.playMusic("background");

    //game_music["background"] = new sf::Music;
    
    //game_music["background"]->openFromFile("res/testing-resource/audio/music/new_back_music.wav");
    //game_music["background"]->setVolume(25);
    //game_music["background"]->play();

    
//    game_music["old_background"] = new sf::Music;
//    game_music["old_background"]->openFromFile("res/testing-resource/audio/music/back_music.wav");
//    game_music["old_background"]->play();
//    game_music["old_background"]->setVolume(50);
    
}

void Game::close(){
    for(Entity& e : entities){
        e.closeResources();
    }
}

void Game::open(){
    window.setTitle("Prove It! (BETA COPY)");

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
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

void Game::render(){

    for(Entity& e : entities){
        e.draw(window);
    }
}




