//
// Created by Alex Tian on 2/22/2023.
//
#pragma once

#include <string>
#include <vector>
#include "constants.h"

template <typename Out>
void split(const std::string &s, char delim, Out result);

std::vector<std::string> split(const std::string &s, char delim);

Piece piece_to_num(char piece);