// main entry point for powerloom system

#include "powerloom/powerloom-system.hh"

using namespace stella_utilities;
using namespace stella_plx;
using namespace pli;
using namespace logic;
using namespace stella;
using namespace stella_powerloom_code;

int main(int count, char** arguments) {
  std::cout << "Initializing STELLA..." << std::endl;
  startupStellaSystem();
  std::cout << "Initializing PowerLoom..." << std::endl;
  startupLogicSystem();
  startupPowerloomExtensionsSystem();
  startupPowerloomSystem();
  stella::stringChangeModule("PL-USER");
  processCommandLineArguments(count, arguments, KWD_POWERLOOM_WARN);
  if ((!eqlP(getProperty(wrapString("powerloom.runInteractively"), NIL), FALSE_WRAPPER)) &&
      (!eqlP(getProperty(wrapString("stella.showInfoOnly"), NIL), TRUE_WRAPPER))) {
    powerloom();
  }
  runHooks(oSTELLA_EXIT_HOOKSo, NULL);
  return (1);
}

