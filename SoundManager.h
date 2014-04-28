#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

class SoundManager{
public:
	void addSound(string, string);
	void addMusic(string, string);

	sf::Sound getSound(string);
	sf::Music getMusic(string);

	void playSound(string);
	void playMusic(string);

	void disposeAudio(sf::SoundSource);



};