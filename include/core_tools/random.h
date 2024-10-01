/***********************************************************
 *
 * @file: random.h
 * @breif: Contains functions to generate random numbers and
 *        with a globally initialized random number generator
 * @author: David Morilla-Cabello
 * @update: TODO
 * @version: 1.0
 *
 * Copyright (c) 2023， David Morilla-Cabello
 * All rights reserved.
 * --------------------------------------------------------
 *
 **********************************************************/

#ifndef CORE_TOOLS_RANDOM_H
#define CORE_TOOLS_RANDOM_H

#include <random>

namespace core_tools {

// Global static random number generator
static std::mt19937 eng;

extern std::mt19937& get_global_random_generator() {
    return eng;
}

void set_global_seed(int seed) {
    eng.seed(seed);
}

float generate_random_float() {
    std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
    return distribution(get_global_random_generator());
}

}

#endif