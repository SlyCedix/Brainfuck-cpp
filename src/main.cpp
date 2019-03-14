#include <iostream>
#include <string>
#include <fstream>
#include <register.h>
#include <brainfuck.h>

std::ifstream fin;
std::string fStr;
size_t RegSize = UINT16_MAX;
bool dump , valid = false;
std::string code = "";

void ProcessArgs(int argc, char **argv);

int main(int argc, char *argv[]) 
{
	if (argc > 2) {
		ProcessArgs(argc, argv);
	} else {
		std::cout << "Usage: \'brainfuck -f /path/to/file/*.bf <-m RegisterSize> <-d>\'\n";
		exit(0);
	}


	if (valid) {
		Brainfuck bf(code, RegSize, dump);
		std::cout << "Running " << fStr << " with a register size of " << RegSize << '\n';
		bf.Run();
	}	else {
		std::cout << "Usage: \'brainfuck -f /path/to/file/*.bf <-m RegisterSize> <-d>\'\n";
		exit(0);
	}
	return 0;
}

void ProcessArgs(int argc, char ** argv)
{
	std::cout << argv[0];
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		std::cout << " " << arg;
	}
	std::cout << ": \n";

	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-' && ((std::string)argv[i]).length() == 2) {
			char arg = argv[i][1];

			switch (arg) {
				case 'f':
					fin.open(argv[i + 1]);
					if (fin) {
						valid = true;
						while (!fin.eof()) {
							std::string inStr;
							fin >> inStr;
							code += inStr;
						}
						fin.close();
					}
					else {
						std::cout << "Invalid file: " << argv[i + 1] << '\n';
					}
					break;

				case 'm':
					RegSize = atoi(argv[i + 1]);
					break;

				case 'd':
					dump = true;
					break;

				default:
					std::cout << "Invalid argument: " << argv[i + 1] << '\n';
					break;
			}
		}
	}
}