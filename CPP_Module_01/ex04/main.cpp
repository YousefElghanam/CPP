#include "main.hpp"
#include <iostream>
#include <fstream>

// bool	open_file(cosnt char* fileName, std::ifstream *filePtr) {
// 	std::string		line;
// 	std::ifstream	file;

// 	file.open(fileName);
// 	if (file.fail()) {
// 		std::cerr << "Couldn't open file." << std::endl;
// 		return 1;
// 	}
// 	filePtr = &file;
// 	return 0;
// }

bool	sed(std::ifstream& inputFile, std::ofstream& outputFile, char* s1, char* s2) {
	std::string		line;
	size_t			lineLen = line.length();

	while (1) {
		std::getline(inputFile, line);
		if (line.empty())
			break ;
		while (line.find(s1) + 1 < lineLen) {
			
		}
		line.find(s1);

	}
	return 0;
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Needs 3 arguments." << std::endl;
		return 1;
	}

	std::ifstream	inputFile(argv[1]);	
	std::ofstream	outputFile((std::string(argv[1]) + ".replace").c_str());

	if (inputFile.fail()) {
		std::cerr << "Couldn't open input file." << std::endl;
		return 1;
	}
	if (outputFile.fail()) {
		std::cerr << "Couldn't open output file." << std::endl;
		return 1;
	}
	if (sed(inputFile, outputFile, argv[2], argv[3])) {
		std::cerr << "Something went wrong." << std::endl;
	}
	return 0;
}