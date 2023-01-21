#pragma once
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include "ConverterInclude.h"
#include "common.h"

// Fabric

class ConverterManager {
public:
	std::list<std::string> getCommandArgv(const std::string& command);
	std::string getConverterType(const std::string& command);
	Context makeContext(std::string convertertype, std::list<std::string> argv);

	void execute(const std::string& command);
};

