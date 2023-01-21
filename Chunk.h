#pragma once
#include <string>
#include "common.h"

class Chunk {
public:
	Chunk();
	Chunk(const Chunk& ch);
	~Chunk();

	const Chunk& operator=(const Chunk& ch);

	static const size_t capacity = config::sampleRate * 5;	// 5 seconds
	uint16_t* chunk;
	size_t size;
};
