#include "MuteConverter.h"
#include <string>

Chunk MuteConverter::process(const Context& context) {
	Chunk res = context.mainChunk;
	memset(res.chunk, 0, sizeof(uint16_t) * res.size);

	return res;
}
