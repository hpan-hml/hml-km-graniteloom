// main entry point for powerloom system

#include "powerloom/powerloom-system.hh"

using namespace stella_utilities;
using namespace stella_plx;
using namespace pli;
using namespace logic;
using namespace stella;
using namespace stella_powerloom_code;

int main(int count, char** arguments) {
  // Main PowerLoom entry point.
  std::cout << "Initializing STELLA..." << std::endl;
  startupStellaSystem();
  std::cout << "Initializing PowerLoom..." << std::endl;
  startupLogicSystem();
  startupPowerloomExtensionsSystem();
  stella::stringChangeModule("PL-USER");
  interpretCommandLineArguments(count, arguments);
  if (!(consifyCommandLineArguments(count, arguments)->memberP(wrapString("--batch")))) {
    powerloom();
  }
  return (1);
}

