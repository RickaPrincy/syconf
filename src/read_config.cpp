#include "read_config.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>

#include "JSON/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;

const char* SYCONF_PATH = "SYCONF_PATH";
char* SYCONF_PATH_VALUE = std::getenv(SYCONF_PATH);

Config read_config() {
	if (SYCONF_PATH_VALUE == nullptr) {
		std::cerr << "[ERROR]: Make sure that " << SYCONF_PATH
				  << " env exist on your environment" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (!fs::exists(SYCONF_PATH_VALUE)) {
		std::cerr << "[ERROR]: " << SYCONF_PATH_VALUE
				  << "is not a file configuration for syconf" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string syconf_path_value = SYCONF_PATH_VALUE;
std:
	std::ifstream syconf_config(syconf_path_value);

	if (!syconf_config.is_open()) {
		std::cerr << "[ERROR]: cannot read " << syconf_path_value << std::endl;
		exit(EXIT_FAILURE);
	}
	json config;
	try {
		config = json::parse(syconf_config);
		syconf_config.close();
	} catch (json::exception error) {
		std::cerr << "Your config file is not a valid json" << std::endl;
		syconf_config.close();
		exit(EXIT_FAILURE);
	}

	if (config["repository"].is_null() || !config["repository"].is_string()) {
		std::cerr << "Config must contain repository with a string value"
				  << std::endl;
		exit(EXIT_FAILURE);
	}

	if (config["configs"].is_null() || !config["configs"].is_array()) {
		std::cerr << "Config must contain configs with a array of strings value"
				  << std::endl;
		exit(EXIT_FAILURE);
	}

	std::map<std::string, std::string> configs{};
	for (auto config : config["configs"]) {
		if (!config.is_object() || !config["input"].is_string() ||
			!config["output"].is_string()) {
			std::cerr << "Config must contain configs with a array of object "
						 "with input and output attributes"
					  << std::endl;
			exit(EXIT_FAILURE);
		}
		configs[config["input"]] = config["output"];
	}

	return Config(config["repository"], configs);
}
