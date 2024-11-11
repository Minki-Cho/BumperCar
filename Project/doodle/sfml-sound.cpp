// Filename : sfml-sound.cpp
// Authors : Minki Cho
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include "sfml-sound.h"

using namespace doodle;


[[noreturn]] void error(const std::string& s)
{
    throw std::runtime_error(s);
}
void Sound::Playsound(int buffer_index)
{
    for (auto& sound : sounds)
    {
        if (sound.getStatus() != sf::SoundSource::Playing)
        {
            sound.setBuffer(soundBuffers[buffer_index]);
            sound.play();
            return;
        }    
    }
    sounds.emplace_back(soundBuffers[buffer_index]);
    sounds.back().play();
}

void Sound::LoadSound(const std::string& file_path)
{
    soundBuffers.emplace_back();
    sf::SoundBuffer& buffer = soundBuffers.back();
    if (!buffer.loadFromFile(file_path))
    {
        error("Failed to load " + file_path);
    }
}
void Sound::pre_loadSound()
{
    game_sound.LoadSound("assets/sounds/hash.ogg");
    game_sound.LoadSound("assets/sounds/play.ogg");
    game_sound.LoadSound("assets/sounds/exit.ogg");
    game_sound.LoadSound("assets/sounds/credit.ogg");
    game_sound.LoadSound("assets/sounds/select.ogg");
    game_sound.LoadSound("assets/sounds/bump.ogg");
    game_sound.LoadSound("assets/sounds/play_again.ogg");
    game_sound.LoadSound("assets/sounds/car_out.ogg");
    game_sound.LoadSound("assets/sounds/menu.ogg");
    game_sound.LoadSound("assets/sounds/how-to-play.ogg");
    game_sound.LoadSound("assets/sounds/eat-apple.ogg");
}