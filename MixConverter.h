#pragma once
#include "BaseConverter.h"

class MixConverter : BaseConverter {
public:
	MixConverter() = default;

	virtual Chunk processChunk(const Context& context);
	virtual void process(const Context& context, std::list<std::string> argv);
};
