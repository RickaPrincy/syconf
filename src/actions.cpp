#include "actions.hpp"

#include <cstdlib>
#include <ctime>
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

void commit(){
    auto current_date = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string current_date_string = std::ctime(&current_date);
    std::system("git add --all");
    std::string commit_message = "git commit -m \"" + current_date_string + "\"";
    std::system(commit_message.c_str());
}

void push(){
    std::system("git push origin main");
}
