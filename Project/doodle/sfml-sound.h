// Filename : sfml-sound.h
// Authors : Minki Cho
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.
#pragma once
#include <SFML/Audio.hpp>
#include <vector>

enum class Sounds
{
    hash, play, exit, credit, select, bump, play_again, car_out, menu, how_to_play, eat_apple
};

class Sound
{

    std::vector<sf::SoundBuffer> soundBuffers{};
    std::vector<sf::Sound>       sounds{};
    sf::Music                    music;
public:
	void LoadSound(const std::string& file_path);
    void pre_loadSound();
	void Playsound(int buffer_index);
};
inline Sound game_sound;


