#include "ConverterManager.h"

ConverterManager::ConverterManager() {
	converters.push_back(new MuteConverter());
	converters.push_back(new MixConverter());
	converters.push_back(new LouderConverter());
}

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

Context ConverterManager::makeContext(std::string convertertype, std::list<std::string> argv) {
	Context cnt;
	auto iter = argv.begin();

	if (convertertype == "mute" || convertertype == "loud") {
		iter++;
		cnt.interval.start = std::atoi((*iter).c_str());
		iter++;
		cnt.interval.end = std::atoi((*iter).c_str());
	}
	else if (convertertype == "mix") {
		iter++;
		iter++;
		cnt.interval.start = std::atoi((*iter).c_str());
		iter++;
		cnt.interval.end = std::atoi((*iter).c_str());
	}

	return cnt;
}

void ConverterManager::execute(const std::string& command) {
	std::string converterType = getConverterType(command);
	std::list<std::string> argv = getCommandArgv(command);

	Context cnt = makeContext(converterType, argv);

	if (converterType == "mute") {
		converters[0]->process(cnt, argv);
	}
	else if (converterType == "mix") {
		converters[0]->process(cnt, argv);
	}
	else if (converterType == "loud") {
		converters[0]->process(cnt, argv);
	}
}
