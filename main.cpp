#include <iostream>

#include "Game.h"

using namespace std;

int main(){
    
    // TODO: (Windows: OpenAL libs)
    printf("Starting game!");
    Game game ("SFML Test Game");
    game.open();
    return 0;
}