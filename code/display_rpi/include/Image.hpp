#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <vector>
/*
std::vector<std::vector<std::vector<char>>> image = {
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}}
};*/

std::vector<std::vector<std::vector<char>>> image = {
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0xFF}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}},
        {{0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}, {0x00}}
};


#endif // IMAGE_HPP
