#ifndef __SYCONF_CONFIG__
#define __SYCONF_CONFIG__

#include <map>
#include <string>

class Config {
public:
	std::string _path;
	std::map<std::string, std::string> _include_paths;
	explicit Config(std::string path,
					std::map<std::string, std::string> include_paths)
		: _path(path), _include_paths(include_paths) {}

	Config operator=(const Config &other) {
		_path = other._path;
		_include_paths = other._include_paths;
		return *this;
	}
};

#endif	// !__SYCONF_CONFIG__
