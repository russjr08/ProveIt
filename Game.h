//
//  Game.h
//  SFMLGame
//
//  Created by Russell Richardson on 4/24/14.
//  Copyright (c) 2014 KronosAD. All rights reserved.
//

#ifndef GAME_H
#define GAME_H

#pragma once


#include "Entity.h"
#include "SoundManager.h"
#include "ImageManager.h"

using namespace std;


class Game {
 
public:
    Entity* player;

	SoundManager sounds;
	ImageManager images;

    Game(string);
    
    void open();
    void close();
    void update();
    void render();
    

    
    
    
};

#endif /* GAME_H */