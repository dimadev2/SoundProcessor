#include "Chunk.h"

Chunk::Chunk() {
	size = 0;
	chunk = new uint16_t[capacity];
	memset(chunk, 0, sizeof(uint16_t) * capacity);
}

Chunk::Chunk(const Chunk& ch) {
	size = ch.size;
	chunk = new uint16_t[capacity];
	memcpy(chunk, ch.chunk, sizeof(uint16_t) * capacity);
}

Chunk::~Chunk() {
	delete[] chunk;
}

const Chunk& Chunk::operator=(const Chunk& ch) {
	delete[] chunk;
	
	size = ch.size;
	chunk = new uint16_t[capacity];
	memcpy(chunk, ch.chunk, sizeof(uint16_t) * capacity);
}
