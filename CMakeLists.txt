cmake_minimum_required(VERSION 3.15)
project(core_tools)

set(CMAKE_CXX_STANDARD 17)
# Add -o3 to compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

## Find system libraries
find_package(Eigen3 REQUIRED)
find_package(catkin REQUIRED)

find_package(catkin REQUIRED
)

catkin_package(
  INCLUDE_DIRS include
  ${EIGEN3_INCLUDE_DIRS}
  LIBRARIES
  CATKIN_DEPENDS
  DEPENDS Eigen3
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS} # Includes voxblox
  ${EIGEN3_INCLUDE_DIRS}
)

# add_library(core_tools
# )
# target_link_libraries(ipp_tools  
#   ${catkin_LIBRARIES}
#   Eigen3::Eigen
# )
