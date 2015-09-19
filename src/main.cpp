#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "compiler.hpp"

int main(const int argc, const char** argv)
{
	using SBC::ToC::compile;
	using std::cout;
	using std::ifstream;

	if (argc != 2) {
		cout << "Usage: " << argv[0] << " [file]" << '\n';
		return 1;
	}

	const auto source_file_name = std::string(argv[1]);
	auto source_file_length = source_file_name.length();

	if (source_file_name[source_file_length - 2] != '.' ||
		source_file_name[source_file_length - 1] != 'b') {
		cout << "Input file (" << argv[1] << ") must have .b file extension." << '\n';
		return 2;
	}

	auto source_file = ifstream(argv[1]);
	auto source = std::stringstream();
	source << source_file.rdbuf();

	auto c_file_name = source_file_name;
	c_file_name[source_file_length - 1] = 'c';

	auto c_file = std::ofstream(c_file_name);

	c_file << compile(source.str()) << '\n';

	c_file.close();
	source_file.close();
	
	return 0;
}
