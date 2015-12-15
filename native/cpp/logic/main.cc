// main entry point for logic system

#include "logic/logic-system.hh"

using namespace stella;
using namespace logic;
using namespace pli;

int main() {
  // Main PowerLoom entry point for your code in C++ and Java.
  std::cout << "Initializing STELLA..." << std::endl;
  startupStellaSystem();
  std::cout << "Initializing PowerLoom..." << std::endl;
  startupLogicSystem();
  stella::stringChangeModule("PL-USER");
  powerloom();
  return (1);
}

