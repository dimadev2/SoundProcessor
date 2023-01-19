#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <cstdint>
#include <string>
#include <stdio.h>

class read_exception : std::exception {
	std::string msg;
public:
	read_exception(const char* msg) : msg(std::string(msg)) {}

	const std::string show() const {
		return msg;
	}
};

class getchunk_exception : std::exception {
	std::string msg;
public:
	getchunk_exception(const char* msg) : msg(std::string(msg)) {}

	const std::string show() const {
		return msg;
	}
};

class FileHeader {
public:
	static const uint16_t numChannels = 1;
	static const uint32_t sampleRate = 44100;
	static const uint16_t bitPerSample = 16;
	static constexpr uint16_t blockAlign = bitPerSample / 8;
	uint32_t dataSize;

	FileHeader() = default;
	FileHeader(uint32_t datasize) { FileHeader::dataSize = datasize; }
};

class Reader {
public:
	Reader() = default;
	Reader(const char* filename);
	~Reader() { fclose(input); }

	const uint16_t* getCurrentChunk() const;
	void readChunk();

private:
	FILE* input;
	FileHeader fileHeader;
	static const size_t chunkSize = FileHeader::sampleRate * 5;		// 5 seconds
	size_t currentChunkSize = 0;
	uint16_t currentChunk[chunkSize];
};
