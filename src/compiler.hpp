#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <iostream>
#include <algorithm>

namespace SBC {
namespace ToC {

// Compiles a brainf program into a C one.
std::string compile(std::string& program);

}
}

#endif // COMPILER_HPP
