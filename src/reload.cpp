#include "reload.hpp"

#include <cstdlib>
#include <exception>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void reload(const Config &config) {
	try {
		for (const auto &[input, output] : config._include_paths) {
            fs::create_directory(config._path + "/" + output);
			fs::copy(input, config._path + "/" + output, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
		}
		status();
	} catch (std::exception error) {
		std::cerr << "[ERROR]: Cannot copy somefolder or file configuration" << std::endl;
        stash();
		exit(EXIT_FAILURE);
	}
}

void stash() {
	std::system("git add --all");
	std::system("git stash");
    status();
}

void status() { std::system("git status"); }
