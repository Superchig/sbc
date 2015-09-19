#include <iostream>
#include "catch.hpp"
#include "../src/compiler.hpp"

SCENARIO("A hello world program is compiled.", "[program]") {
	GIVEN("A hello world program in brainf") {
		auto hello_world = std::string { R"(
++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.
)" };

		WHEN("The program is compiled") {
			
		}
	}
}
