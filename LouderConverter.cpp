#include "LouderConverter.h"

Chunk LouderConverter::process(const Context& context) {
	Chunk res = context.mainChunk;
	uint16_t loud = std::stoi(context.argv[0]);

	for (unsigned int i = 0; i < res.size; i++) {
		res.chunk[i] += loud;
	}

	return res;
}