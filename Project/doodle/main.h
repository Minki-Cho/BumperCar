// Filename : main.h
// Authors : Minjae Yu, Minki Cho, Yeeun Kim
// Course : GAM100F21
// All content 2021 DigiPen(USA) Corporation, all rights reserved.

#pragma once
#include <string>
#include <unordered_map>
#include <doodle/doodle.hpp>
#include <Windows.h>
#include <fstream>
#include <vector>

inline std::string abc{""};
typedef struct doodle_setting
{
    int width{ 1100 };
    int height{ 1000 };
    doodle::HexColor background_color{ 0xf5f5dc99 };
    double version{ 1.00 };
}doodle_set;
inline std::unordered_map<std::string, double> window_title;
constexpr doodle_set set;

inline int get_refresh_rate()
{
    //get monitor refresh rate
    DEVMODE dm{ NULL };
    EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm);
    const int hz = dm.dmDisplayFrequency;

    return hz;
}
inline const int hz = get_refresh_rate();
inline const int skip_ms{ ((hz - 60) / 15) * 2 };
void output_file();

inline unsigned char c{};