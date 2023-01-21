#include "MixConverter.h"
#include <string>

Chunk MixConverter::process(const Context& context) {
	Chunk res;
	const Chunk& first = context.mainChunk;
	const Chunk& second = context.additionalChunks[0];

	unsigned int maxSize = first.size > second.size ? first.size : second.size;

	for (unsigned int i = 0; i < maxSize; i++) {
		res.chunk[i] = (first.chunk[i] + second.chunk[i]) / 2;
	}

	res.size = maxSize;

	return res;
}
