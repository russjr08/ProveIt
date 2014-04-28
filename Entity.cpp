//
//  Entity.cpp
//  SFMLGame
//
//  Created by Russell Richardson on 4/24/14.
//  Copyright (c) 2014 KronosAD. All rights reserved.
//

#include "Entity.h"

sf::Texture texture;

Entity::Entity(std::string textureFile){
    texture.loadFromFile(textureFile);
    sprite.setTexture(texture);
    sprite.scale(3, 3);
    position.x = 0;
    position.y = 0;
    
    entity_size.x = 60;
    entity_size.y = 75;
    
}

void Entity::draw(sf::RenderWindow& target){
    sprite.setPosition(position);
    target.draw(sprite);
}

void Entity::update(){
    
}

void Entity::closeResources(){
    
}