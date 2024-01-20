#include <unistd.h>

#include <cstdlib>
#include <iostream>

#include "CLI/CLI11.hpp"
#include "config.hpp"
#include "read_config.hpp"
#include "actions.hpp"

int main(int argc, char *argv[]) {
	Config config = read_config();

	if (chdir(config._path.c_str()) != 0) {
		std::cerr << "Cannot go the the repository\n";
		return EXIT_FAILURE;
	}

	CLI::App syconf("Sync your config to repository");

	syconf.add_subcommand("history", "Show git log")->callback([]() {
		std::system("git log");
	});
	
    syconf.add_subcommand("commit", "Commit changes")->callback([]() {
        commit();
	});

	syconf.add_subcommand("reload", "Retrieve config show git status")
		->callback([&config]() { reload(config); });

	syconf.add_subcommand("stash", "Stash change")->callback([&config]() {
		stash();
	});

	syconf.add_subcommand("push", "Stash change")->callback([&config]() {
		push();
	});

	syconf.add_subcommand("status", "Show git status")->callback([&config]() {
		status();
	});

	CLI11_PARSE(syconf, argc, argv)
	return 0;
}
