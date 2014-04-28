#include "SoundManager.h"
#include <map>

using namespace std;

map<string, sf::Sound*> game_audio;
std::map<string, sf::Music*> game_music;

void SoundManager::addSound(string name, string file){
	game_audio[name] = new sf::Sound;
	
}

void SoundManager::addMusic(string name, string file){
	game_music[name] = new sf::Music;
	game_music[name]->openFromFile(file);
}



void SoundManager::playMusic(string name){
	game_music[name]->play();
}