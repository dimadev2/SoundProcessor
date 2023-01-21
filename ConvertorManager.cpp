#include "ConverterManager.h"

std::list<std::string> ConverterManager::getCommandArgv(const std::string& command) {
	std::istringstream istream(command);

	std::string converterType;
	istream >> converterType;

	std::list<std::string> argv;
	std::string tmp;
	while (istream >> tmp) {
		argv.push_back(tmp);
	}

	return argv;
}

std::string ConverterManager::getConverterType(const std::string& command) {
	std::istringstream istream(command);

	std::string converterType;
	istream >> converterType;

	return converterType;
}

void ConverterManager::execute(const std::string& command) {
	std::string converterType = getConverterType(command);
	std::list<std::string> argv = getCommandArgv(command);

	Context cnt = makeContext(converterType, argv);


}
