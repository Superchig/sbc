#include <iostream>
#include <algorithm>
#include <string>
#include "compiler.hpp"

namespace SBC {
namespace ToC {

// Forward declarations
std::string compile_char_with_newline(const char brainf_char);
size_t array_memory_size(const std::string& program);

std::string compile(const std::string& program) {
	auto mem_size = std::to_string(
		array_memory_size(program)
		);
	
	std::string compiled = "#include <stdio.h>\n"
		"int main(){"
		"char m[" + mem_size;
	compiled += "] = {0};"
		"char* p = m;";

	for (auto character : program) {
		compiled += compile_char_with_newline(character);
	}

	compiled += "}";

	return compiled;
}

// Takes a brainf character and returns its C equivalent, with a newline appended.
std::string compile_char_with_newline(const char brainf_char) {
	switch (brainf_char) {
	case '>':
		return "++p;";
		break;
	case '<':
		return "--p;";
		break;
	case '+':
		return "++*p;";
		break;
	case '-':
		return "--*p;";
		break;
	case '.':
		return "putchar(*p);";
		break;
	case ',':
		return "*p=getchar();";
	case '[':
		return "while (*p) {";
		break;
	case ']':
		return "}";
		break;
	default:
		// Do nothing
		return "";
	}
}

size_t array_memory_size(const std::string& program) {
	size_t length4chars = std::count_if(program.begin(), program.end(),
										[](char character) {
											return character == '>' || character == '<';
										});

	size_t length5chars = std::count_if(program.begin(), program.end(),
										[](char character) {
											return character == '+' || character == '-';
										});

	size_t putchars = std::count_if(program.begin(), program.end(),
									[](char character) {
										return character == '.';
									});

	size_t getchars = std::count_if(program.begin(), program.end(),
									[](char character) {
										return character == ',';
									});

	size_t open_brackets = std::count_if(program.begin(), program.end(),
										 [](char character) {
											 return character == '[';
										 });

	size_t close_brackets = std::count_if(program.begin(), program.end(),
										  [](char character) {
											  return character == ']';
										  });

	size_t size = (4 * length4chars) + (5 * length5chars) +
		(12 * putchars) + (13 * getchars) + (14 * open_brackets) +
		close_brackets;

	return size;
}

}
}
