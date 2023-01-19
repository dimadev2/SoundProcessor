#include "FileReader.h"

Reader::Reader(const char* filename) {
	input = fopen(filename, "r");

	// miss header cause already know it
	for (unsigned int i = 0; i < 40; i++) {
		fgetc(input);
	}

	uint32_t datasize;
	fread(&datasize, 1, 4, input);
	fileHeader = FileHeader(datasize);

	memset(currentChunk, 0, sizeof(uint16_t) * chunkSize);
}

const uint16_t* Reader::getCurrentChunk() const {
	if (currentChunkSize == 0) {
		throw getchunk_exception("Chunk is empty");
	}
	else {
		return currentChunk;
	}
}

void Reader::readChunk() {
	currentChunkSize = fread(currentChunk, sizeof(uint16_t), chunkSize, input);
	if (currentChunkSize == 0) {
		throw read_exception("EOF");
	}
}
