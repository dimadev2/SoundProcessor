#include "MixConverter.h"
#include <string>

Chunk MixConverter::processChunk(const Context& context) {
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

void MixConverter::process(const Context& context, std::list<std::string> argv) {
	Reader r1(argv.front().c_str());
	argv.pop_front();
	Reader r2(argv.front().c_str());
	argv.pop_front();
	Writer w(argv.front().c_str(), r1.fileHeader);

	Context cnt = context;

	if (context.interval.end - 1 < r1.fileHeader.dataSize / (r1.fileHeader.blockAlign * r1.fileHeader.sampleRate)) {
		size_t secs = 0;
		while (true) {
			try {
				r1.readChunk();
				r2.readChunk();
				cnt.mainChunk = r1.chunk;
				cnt.additionalChunks.push_back(r2.chunk);
				secs++;
				if (secs >= context.interval.start && secs <= context.interval.end) {
					w.writeChunk(processChunk(cnt));
				}
				else {
					w.writeChunk(cnt.mainChunk);
				}
			}
			catch (read_exception) {
				break;
			}
		}
	}
}
