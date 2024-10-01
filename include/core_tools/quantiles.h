/***********************************************************
 *
 * @file: quantiles.h
 * @breif: Contains an implementation of the quantiles function
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
#ifndef CORE_TOOLS_QUANTILES_H
#define CORE_TOOLS_QUANTILES_H
#include <algorithm>
#include <cmath>
#include <vector>

#include <core_tools/lerp.h>

namespace core_tools
{

template<typename T>
static inline std::vector<T> quantiles(const std::vector<T>& inData, const std::vector<T>& probs)
{
    if (inData.empty())
    {
        return std::vector<T>();
    }

    if (1 == inData.size())
    {
        return std::vector<T>(1, inData[0]);
    }

    std::vector<T> data = inData;
    std::sort(data.begin(), data.end());
    std::vector<T> quantiles;

    for (size_t i = 0; i < probs.size(); ++i)
    {
        T poi = Lerp<T>(-0.5, data.size() - 0.5, probs[i]);

        int64_t left = std::max(int64_t(std::floor(poi)), int64_t(0));
        left = std::min(left,static_cast<int64_t>(data.size())-1);
        int64_t right = std::min(int64_t(std::ceil(poi)), int64_t(data.size() - 1));
        right = std::max(right, static_cast<int64_t>(0));

        T datLeft = data.at(left);
        T datRight = data.at(right);

        T quantile = Lerp<T>(datLeft, datRight, poi - left);

        quantiles.push_back(quantile);
    }

    return quantiles;
}

} // namespace core_tools
#endif