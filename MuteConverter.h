#pragma once
#include "BaseConverter.h"

class MuteConverter : BaseConverter {
public:
	MuteConverter() = default;

	virtual Chunk processChunk(const Context& context);
	virtual void process(const Context& context, std::list<std::string> argv);
};
