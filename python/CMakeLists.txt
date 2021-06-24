cmake_minimum_required(VERSION 3.19)
project(python)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(python
        asjibdajisbda.hpp
        BaseException.hpp
        Char.hpp
        Dict.hpp
        Exception.hpp
        Float.hpp
        Int.hpp
        List.hpp
        main.cpp
        NotImplementedError.hpp
        Object.hpp
        pybuiltins.hpp
        pymath.hpp
        RuntimeError.hpp
        STLVectorImplementation.hpp
        String.hpp
        Type.hpp
        TypeError.hpp
        ValueError.hpp)
