//
//  Game.h
//  SFMLGame
//
//  Created by Russell Richardson on 4/24/14.
//  Copyright (c) 2014 KronosAD. All rights reserved.
//


#pragma once


#include "Entity.h"

using namespace std;


class Game {
 
public:
    Entity* player;

    Game(string);
    
    void open();
    void close();
    void update();
    void render();
    

    
    
    
};
