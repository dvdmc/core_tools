/***********************************************************
 *
 * @file: angles.h
 * @breif: Contains an implementation of angles function
 *          source: https://stackoverflow.com/questions/11964552/finding-quartiles
 * @author: David Morilla-Cabello
 * @update: TODO
 * @version: 1.0
 *
 * Copyright (c) 2023， David Morilla-Cabello
 * All rights reserved.
 * --------------------------------------------------------
 *
 **********************************************************/
#ifndef CORE_TOOLS_ANGLES_H
#define CORE_TOOLS_ANGLES_H

#include <math.h>

namespace core_tools
{

/*
 * Normalize angle in the interval [-pi, pi]
 * @param angle angle to normalize
 * @return normalized angle
*/
inline double normalizeAnglePi(double angle)
{
    return angle -= 2*M_PI * floorf((angle + M_PI) * (1.0 / (2*M_PI)));
}
inline float normalizeAnglePi(float angle)
{
    return angle -= 2*M_PI * floorf((angle + M_PI) * (1.0 / (2*M_PI)));
}

/*
 * Normalize angle in the interval [0, 2pi]
 * @param angle angle to normalize
 * @return normalized angle
*/ 
inline double normalizeAngle2Pi(double angle)
{
    return angle -= 2*M_PI * floor(angle * (1.0 / (2*M_PI)));
}

inline float normalizeAngle2Pi(float angle)
{
    return angle -= 2*M_PI * floor(angle * (1.0 / (2*M_PI)));
}

}
#endif