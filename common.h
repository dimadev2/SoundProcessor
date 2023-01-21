#pragma once
#include <cstdint>
#include <list>

namespace config {
	const uint16_t numChannels = 1;
	const uint32_t sampleRate = 44100;
	const uint16_t bitPerSample = 16;
	constexpr uint16_t blockAlign = bitPerSample / 8;
}

class Interval {
public:
	size_t start;
	size_t end;
};

struct Context {
	Chunk mainChunk;
	std::vector<Chunk> additionalChunks;
	std::list<std::string> argv;

	Interval interval;
};
