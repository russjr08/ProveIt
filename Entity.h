//
//  Entity.h
//  SFMLGame
//
//  Created by Russell Richardson on 4/24/14.
//  Copyright (c) 2014 KronosAD. All rights reserved.
//


#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"


class Entity {
    
public:
    sf::Sprite sprite;

    sf::Vector2f position;
    sf::Vector2f entity_size;

	std::vector<Entity> sub_entities;

	Game* game;

    
    Entity(std::string, Game*);
    
    void draw(sf::RenderWindow&);
    void update();
    
    void closeResources();
    
    
    
};
