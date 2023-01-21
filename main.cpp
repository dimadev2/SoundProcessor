#include "FileThread.h"
#include "ConverterManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using std::cout;
using std::cin;

void showHelp();

int main() {
	ConverterManager manager;
	while (true) {
		cout << "!#: ";
		char command[64];
		cin.getline(command, 64);
		if (strcmp(command, "-q") == 0) {
			break;
		}
		else if (strcmp(command, "-h") == 0) {
			showHelp();
		}
		else {
			manager.execute(command);
		}
		cout << "\n";
	}
	
	return 0;
}

void showHelp() {
	cout << "WAV Converter\n";
	cout << "mute filename start end - mute a part of file\n";
	cout << "mix filename1 filename2 start end - mix a parts of two files\n";
	cout << "loud filename start end - make a part of file louder\n";
}
