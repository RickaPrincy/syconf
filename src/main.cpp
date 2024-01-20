#include <unistd.h>

#include <cstdlib>
#include <iostream>

#include "CLI/CLI11.hpp"
#include "config.hpp"
#include "read_config.hpp"

int main(int argc, char *argv[]) {
	Config config = read_config();

	CLI::App syconf("Sync your config to repository");
	auto *history = syconf.add_subcommand("history", "Show git log --online")
						->callback([]() { std::system("/bin/git log"); });

	if (chdir(config._path.c_str()) != 0) {
		std::cerr << "Cannot go the the repository\n";
		return EXIT_FAILURE;
	}

	CLI11_PARSE(syconf, argc, argv)
	return 0;
}
