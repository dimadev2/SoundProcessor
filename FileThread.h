#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <cstdint>
#include <string>
#include <stdio.h>
#include "common.h"
#include "Chunk.h"

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
	char fileHeader[44];

	static const uint16_t numChannels = config::numChannels;
	static const uint32_t sampleRate = config::sampleRate;
	static const uint16_t bitPerSample = config::bitPerSample;
	static const uint16_t blockAlign = config::blockAlign;
	uint32_t dataSize;

	FileHeader() = default;
	FileHeader(char* header, uint32_t datasize) {
		FileHeader::dataSize = datasize;
		memcpy(fileHeader, header, 44);
	}
};

class Reader {
public:
	Reader() = default;
	Reader(const char* filename);
	~Reader() { fclose(input); }

	const Chunk& getCurrentChunk() const;
	void readChunk();

private:
	FILE* input;
	FileHeader fileHeader;
	Chunk chunk;
};

class Writer {
public:
	Writer() = default;
	Writer(const char* filename, FileHeader& header);
	~Writer() { fclose(output); }

	void writeChunk(const Chunk& chunk);

private:
	FILE* output;
	FileHeader fileHeader;
};
