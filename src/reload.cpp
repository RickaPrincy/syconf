#include "reload.hpp"
#include <cstdlib>
#include <exception>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void reload(const Config &config){
    try{
        for(const auto &[input, output]: config._include_paths){
            fs::copy(input, output);
        }
        status();
    }catch(std::exception error){
        std::cerr << error.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void status(){
    std::system("git status");
}
