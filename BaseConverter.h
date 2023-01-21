#pragma once
#include <stdio.h>
#include <vector>
#include <string>
#include "FileThread.h"
#include "common.h"
#include "Chunk.h"

class BaseConverter {
public:
	BaseConverter() = default;

	virtual Chunk processChunk(const Context& context) = 0;
	virtual void process(const Context& context, std::list<std::string> argv) = 0;
};
