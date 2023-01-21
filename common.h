#pragma once
#include <cstdint>

namespace config {
	const uint16_t numChannels = 1;
	const uint32_t sampleRate = 44100;
	const uint16_t bitPerSample = 16;
	constexpr uint16_t blockAlign = bitPerSample / 8;
}

class Interval {
public:
	class Time {
	public:
		size_t sec;
		size_t sample;
	};

	Time start;
	Time end;
};
