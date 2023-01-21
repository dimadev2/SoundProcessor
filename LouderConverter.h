#pragma once
#include "BaseConverter.h"

class LouderConverter : BaseConverter {
public:
	LouderConverter() = default;

	virtual Chunk processChunk(const Context& context);
	virtual void process(const Context& context, std::list<std::string> argv);
};
