// Filename : main.cpp
// Authors : Minki Cho, Minjae Yu, Yeeun Kim
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#include <doodle/doodle.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <stdexcept>
#include <string>
#include "main.h"
#include "player.h"
#include "item.h"
#include "state.h"
#include "splash_screen.h"
#include "map.h"
#include "gameover.h"
#include "credit.h"
#include "mapSelection.h"
#include "howtoplay.h"
#include "sfml-sound.h"

using namespace doodle;

[[noreturn]] void error(std::string s)
{
	throw std::runtime_error{ s };
}


int main(void) try
{

	std::ifstream text;
	text.open("team.txt");
	if (!text.is_open())
	{
		std::cerr << "Error: file doesn't exist";
		return -1;
	}
	while (text >> c)
	{
		abc = c;
	}
	text.close();

	game_sound.pre_loadSound();

	create_window(set.width, set.height);
	//window title
	window_title.insert(std::pair("HASH - Bumper Car ver.", set.version));
	auto [title, version] = *window_title.find("HASH - Bumper Car ver.");
	set_window_title(title + std::to_string(version));

	while (!is_window_closed())
	{
		update_window();
		clear_background(set.background_color);

		switch (game_state)
		{
		case gamestate::state_logo:
		{
			splash_screen();
			break;
		}
		case gamestate::state_menu:
		{
			menu.states_main_menu();
			break;
		}
		case gamestate::state_mapSelection:
		{
			mapSelection.draw_map_selection();
			break;
		}
		case gamestate::state_map1:
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(skip_ms));
			map.rectangleMap_draw();
			p.draw_player();
			p.player_movement();
			p.player_collision();
			p.map_player_collision();
			output_file();
			break;
		}
		case gamestate::state_map2:
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(skip_ms));
			map.doughnutMap_draw();
			p.draw_player();
			p.player_movement();
			p.player_collision();
			map.doughnutMap_collision();
			output_file();
			break;
		}
		case gamestate::state_map3:
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(skip_ms));
			map.rectangleMap_draw();
			item.item_draw();
			item.item_collision();
			item2.item_draw();
			item2.item_collision();
			p.draw_player();
			p.player_movement();
			p.player_collision();
			p.map_player_collision();
			output_file();
			break;
		}
		case gamestate::state_map4:
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(skip_ms));
			map.rectangleMap_draw();
			map.random_sink_hole();
			p.draw_player();
			p.player_movement();
			p.player_collision();
			p.map_player_collision();
			output_file();
			break;
		}
		case gamestate::state_gameover1:
		{
			gameover.draw_gameover();
			break;
		}
		case gamestate::state_gameover2:
		{
			gameover.draw_gameover();
			break;
		}
		case gamestate::state_credit:
		{
			credit.draw_credit();
			break;
		}
		case gamestate::state_how_to_play:
		{
			ht.draw_howto();
			break;
		}
		case gamestate::state_gameover3:
		{
			gameover.draw_gameover();
			break;
		}
		}
	}
	return 0;
}
catch (const std::exception& e)
{
	std::cerr << "Error : " << e.what() << '\n';
	return -1;
}

void on_key_pressed(doodle::KeyboardButtons button)
{
	p.keyboard_pressed(button);
}

void on_key_released(doodle::KeyboardButtons button)
{
	p.keyboard_released(button);
}

void on_mouse_released(doodle::MouseButtons button)
{
	gameover.gameover_mouse_released(button);
	menu.menu_mouse_released(button);
	credit.credit_mouse_released(button);
	mapSelection.mapselection_mouse_released(button);
	ht.howto_mouse_released(button);
	car_mouse_released(button);
}

void output_file()
{
	std::ofstream who_wins;
	who_wins.open("results.txt");
	if (is_player1_lose == true)
	{
		who_wins << "Player2 Wins!\n";
		who_wins.close();
	}
	else if (is_player2_lose == true)
	{
		who_wins << "Player1 Wins!\n";
		who_wins.close();
	}
}