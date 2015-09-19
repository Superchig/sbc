#include <iostream>
#include "compiler.hpp"

int main(const int, const char**)
{
	using SBC::ToC::compile;
	using std::cout;

	std::string hello_world = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>"
		".>---.++++potatoes are awesome+++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

	cout << compile(hello_world) << '\n';

	return 0;
}
