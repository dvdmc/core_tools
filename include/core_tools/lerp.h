/***********************************************************
 *
 * @file: lerp.h
 * @breif: Contains an implementation of the lerp function
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
#ifndef CORE_TOOLS_LERP_H
#define CORE_TOOLS_LERP_H

namespace core_tools
{
template<typename T>
static inline double Lerp(T v0, T v1, T t)
{
    return (1 - t)*v0 + t*v1;
}
}
#endif