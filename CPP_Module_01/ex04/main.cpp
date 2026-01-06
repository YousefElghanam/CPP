#include "main.hpp"

bool	read_file(std::ifstream& inputFile, std::string& chunk) {
	char	c;

	inputFile.seekg(0, std::ios::end);
	std::streampos	fileSize = inputFile.tellg();
	inputFile.seekg(0, std::ios::beg);
	chunk.clear();
	if (fileSize > 100000000)
		return 1;
	while (chunk.size() < (size_t)fileSize && inputFile.get(c)) {
		chunk.push_back(c);
	}
	if (inputFile.fail())
		return 1;
	return (chunk.empty());
}

bool	sed(std::ifstream& inputFile, std::ofstream& outputFile, char* s1, char* s2) {
	std::string				fileContent;
	std::string::iterator	it;
	size_t					s1Len = std::string(s1).length();
	char					c;

	if (!inputFile.get(c) && s1Len == 0) {
		outputFile << s2;
		return outputFile.fail();
	}
	inputFile.putback(c);
	if (read_file(inputFile, fileContent)) {
		std::cerr << "Couln't read input file or file too big (>100mb)." << std::endl;
		return 1;
	}
	it = fileContent.begin();
	while (it != fileContent.end()) {
		if (s1Len == 0) {
			outputFile << s2 << *it;
			it++;
		}
		else if (std::string(s1).compare(std::string(it, it + s1Len)) == 0) {
			outputFile << s2;
			it += s1Len;
		}
		else {
			outputFile << *it;
			it++;
		}
		if (outputFile.fail())
			return 1;
	}
	return 0;
}

bool	open_files(std::ifstream* inputFile, std::ofstream* outputFile, char *inputFileName) {
	inputFile->open(inputFileName);
	if (inputFile->fail()) {
		std::cerr << "Couldn't open input file." << std::endl;
		return 1;
	}
	outputFile->open((std::string(inputFileName) + ".replace").c_str());
	if (outputFile->fail()) {
		std::cerr << "Couldn't open output file." << std::endl;
		return 1;
	}
	return 0;
}

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Needs 3 arguments." << std::endl;
		return 1;
	}

	std::ifstream	inputFile;	
	std::ofstream	outputFile;
	if (open_files(&inputFile, &outputFile, argv[1]))
		return 1;
	if (sed(inputFile, outputFile, argv[2], argv[3])) {
		std::cerr << "Something went wrong." << std::endl;
		return 1;
	}
	return 0;
}