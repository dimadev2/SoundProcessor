#include "FileReader.h"
#include <stdio.h>
#include <iostream>

int main() {
	FILE* test = fopen("file.wav", "w");
	for (unsigned int i = 0; i < 100; i++) {
		fputc(0, test);
	}
	fclose(test);

	Reader r("file.wav");
	try {
		r.readChunk();
	}
	catch (read_exception ex) {
		std::cout << ex.show() << std::endl;
	}

	try {
		const uint16_t* chunk = r.getCurrentChunk();
	}
	catch (getchunk_exception ex) {
		std::cout << ex.show() << std::endl;
	}
	
	return 0;
}
