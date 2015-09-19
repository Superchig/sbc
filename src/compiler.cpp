#include <iostream>
#include "compiler.hpp"

namespace SBC {
namespace ToC {

// Forward declare
std::string compile_char_with_newline(const char brainf_char);

std::string compile(const std::string& program) {
	std::string compiled = "int main(){\n"
		"char m[1000] = {0};\n"
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
		return "++p;\n";
		break;
	case '<':
		return "--p;\n";
		break;
	case '+':
		return "++*p;\n";
		break;
	case '-':
		return "--*p;\n";
		break;
	case '.':
		return "putchar(*p);\n";
		break;
	case ',':
		return "*p=getchar();\n";
	case '[':
		return "while (*p) {\n";
		break;
	case ']':
		return "}\n";
		break;
	default:
		// Do nothing
		return "";
	}
}

}
}
