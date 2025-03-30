#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include <iostream>
#include "json.hpp"

using json=nlohmann::json;
extern json bacaData();
extern void simpanData(const json& data);
void eksporData();
void imporData();

#endif