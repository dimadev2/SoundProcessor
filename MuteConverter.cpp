#include "MuteConverter.h"

Chunk MuteConverter::processChunk(const Context& context) {
	Chunk res = context.mainChunk;
	memset(res.chunk, 0, sizeof(uint16_t) * res.size);

	return res;
}

void MuteConverter::process(const Context& context, std::list<std::string> argv) {
	Reader r(argv.front().c_str());
	argv.pop_front();
	Writer w(argv.front().c_str(), r.fileHeader);

	Context cnt = context;

	if (context.interval.end - 1 < r.fileHeader.dataSize / (r.fileHeader.blockAlign * r.fileHeader.sampleRate)) {
		size_t secs = 0;
		while (true) {
			try {
				r.readChunk();
				cnt.mainChunk = r.chunk;
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
