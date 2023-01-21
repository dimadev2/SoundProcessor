#include "FileThread.h"

Reader::Reader(const char* filename) {
	input = fopen(filename, "r");

	char header[44];
	fread(header, 1, 44, input);

	uint32_t datasize;
	fread(&datasize, sizeof(uint32_t), 1, input);
	fileHeader = FileHeader(header, datasize);
}

const Chunk& Reader::getCurrentChunk() const {
	if (chunk.size == 0) {
		throw getchunk_exception("Chunk is empty");
	}
	else {
		return chunk;
	}
}

void Reader::readChunk() {
	chunk.size = fread(chunk.chunk, sizeof(uint16_t), chunk.size, input);
	if (chunk.size == 0) {
		throw read_exception("EOF");
	}
}

Writer::Writer(const char* filename, FileHeader& header) {
	output = fopen(filename, "w");
	fileHeader = header;
}

void Writer::writeChunk(const Chunk& chunk) {
	fwrite(chunk.chunk, sizeof(uint16_t), chunk.size, output);
}
