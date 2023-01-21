#pragma once
#include <stdio.h>
#include <vector>
#include "common.h"
#include "Chunk.h"

struct Context {
	Chunk mainChunk;
	std::vector<Chunk> additionalChunks;
	std::list<std::string> argv;
};

class BaseConverter {
public:
	BaseConverter(Interval interval) { interval = interval; }

	virtual Chunk process(const Context& context) = 0;

	const Interval& getInterval() const { return interval; }
private:
	Interval interval;
};
