#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include <iostream>
#include <regex>
#include <string>
#include "json.hpp"

using json=nlohmann::json;
extern json bacaData();
extern void simpanData(const json& data);
string trim(const string& str);
string cleanString(const string& str);
void eksporData();
void imporData();

#endif