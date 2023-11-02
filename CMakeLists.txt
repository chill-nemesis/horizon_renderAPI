cmake_minimum_required(VERSION 3.15)
project(horizon_renderAPI VERSION 0.0.0 LANGUAGES CXX C)


MakeHorizonModule(INTERFACE
        INTERFACE_DEPENDENCIES horizon::algorithm
)