/***********************************************************
 *
 * @file: actions.h
 * @breif: Contains common action structures and functions
 *          such as to define action spaces, etc.
 * @author: David Morilla-Cabello
 * @update: TODO
 * @version: 1.0
 *
 * Copyright (c) 2023， David Morilla-Cabello
 * All rights reserved.
 * --------------------------------------------------------
 *
 **********************************************************/
#ifndef CORE_TOOLS_ACTIONS_H
#define CORE_TOOLS_ACTIONS_H

#include <Eigen/Dense>

#include <core_tools/limits.h>

namespace core_tools {

/**
 * @brief Action space in ND
 *
 * @tparam N Dimension of the action space
 *
 * @param names Names of the action dimensions
 * @param min minimum values for the action space
 * @param max maximum values for the action space
 */
template <int N>
struct ActionSpace : public Limits<N> {

    public:

        ActionSpace(std::vector<std::string> names, Eigen::Matrix<float, N, 1> min,
                    Eigen::Matrix<float, N, 1> max)
            : Limits<N>(min, max), names(names) {}
        std::vector<std::string> names;

        // Overlead the << operator to print the action space
        friend std::ostream& operator<<(std::ostream& os,
                                        const ActionSpace<N>& action_space) {
            os << "ActionSpace: " << std::endl;
            for (int i = 0; i < N; i++) {
                os << "  " << action_space.names[i] << ": [" << action_space.min(i)
                   << ", " << action_space.max(i) << "]" << std::endl;
            }
            return os;
        }
};

}  // namespace core_tools

#endif  // CORE_TOOLS_ACTIONS_H
