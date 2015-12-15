//  -*- Mode: Java -*-
//
// SystemDefinition.java

/*
+---------------------------- BEGIN LICENSE BLOCK ---------------------------+
|                                                                            |
| Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          |
|                                                                            |
| The contents of this file are subject to the Mozilla Public License        |
| Version 1.1 (the "License"); you may not use this file except in           |
| compliance with the License. You may obtain a copy of the License at       |
| http://www.mozilla.org/MPL/                                                |
|                                                                            |
| Software distributed under the License is distributed on an "AS IS" basis, |
| WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   |
| for the specific language governing rights and limitations under the       |
| License.                                                                   |
|                                                                            |
| The Original Code is the STELLA Programming Language.                      |
|                                                                            |
| The Initial Developer of the Original Code is                              |
| UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
| 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
|                                                                            |
| Portions created by the Initial Developer are Copyright (C) 1996-2006      |
| the Initial Developer. All Rights Reserved.                                |
|                                                                            |
| Contributor(s):                                                            |
|                                                                            |
| Alternatively, the contents of this file may be used under the terms of    |
| either the GNU General Public License Version 2 or later (the "GPL"), or   |
| the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   |
| in which case the provisions of the GPL or the LGPL are applicable instead |
| of those above. If you wish to allow use of your version of this file only |
| under the terms of either the GPL or the LGPL, and not to allow others to  |
| use your version of this file under the terms of the MPL, indicate your    |
| decision by deleting the provisions above and replace them with the notice |
| and other provisions required by the GPL or the LGPL. If you do not delete |
| the provisions above, a recipient may use your version of this file under  |
| the terms of any one of the MPL, the GPL or the LGPL.                      |
|                                                                            |
+---------------------------- END LICENSE BLOCK -----------------------------+
*/

package edu.isi.stella;

import edu.isi.stella.javalib.*;

/** The System-Definition class is used to define systems of files
 * that constitute Stella applications.
 * @author Stella Java Translator
 */
public class SystemDefinition extends StandardObject {
    public String name;
    public String directory;
    public Cons files;
    public Cons lispOnlyFiles;
    public Cons cppOnlyFiles;
    public Cons javaOnlyFiles;
    public Cons preprocessedFiles;
    public Cons requiredSystems;
    public boolean loadedP;
    public boolean upToDateP;
    public String cardinalModule;
    public String sourceRootDirectory;
    public String nativeRootDirectory;
    public String binaryRootDirectory;
    public String banner;
    public Cons productionSettings;
    public Cons developmentSettings;
    public Symbol finalizationFunction;

  public static SystemDefinition newSystemDefinition() {
    { SystemDefinition self = null;

      self = new SystemDefinition();
      self.finalizationFunction = null;
      self.developmentSettings = null;
      self.productionSettings = null;
      self.banner = null;
      self.binaryRootDirectory = null;
      self.nativeRootDirectory = null;
      self.sourceRootDirectory = null;
      self.cardinalModule = null;
      self.upToDateP = false;
      self.loadedP = false;
      self.requiredSystems = null;
      self.preprocessedFiles = null;
      self.javaOnlyFiles = null;
      self.cppOnlyFiles = null;
      self.lispOnlyFiles = null;
      self.files = null;
      self.directory = null;
      self.name = null;
      return (self);
    }
  }

  public static void createSystemStartupFile(SystemDefinition system) {
    if (((SystemDefinition)(Stella.$CURRENTSYSTEMDEFINITION$.get())) == null) {
      {
        System.out.println("Must be within a system environment to create startup file ");
        System.out.println("   for system `" + system.name + "'.");
        System.out.println();
      }
;
      return;
    }
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, SystemDefinition.getCardinalModule(system));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        { String file = Stella.makeFileName(SystemDefinition.systemStartupFileName(system), Stella.KWD_STELLA, true);
          Cons startupfnnames = Stella.NIL;
          Cons startupforms = Stella.NIL;

          { OutputFileStream outputstream = null;

            try {
              outputstream = Stella.openOutputFile(file, Stella.NIL);
              { StringWrapper f = null;
                Cons iter000 = SystemDefinition.systemDefinitionSourceFiles(system);
                Cons collect000 = null;

                for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
                  f = ((StringWrapper)(iter000.value));
                  if (collect000 == null) {
                    {
                      collect000 = Stella_Object.cons(Stella.startupNameFromFile(f.wrapperValue), Stella.NIL);
                      if (startupfnnames == Stella.NIL) {
                        startupfnnames = collect000;
                      }
                      else {
                        Cons.addConsToEndOfConsList(startupfnnames, collect000);
                      }
                    }
                  }
                  else {
                    {
                      collect000.rest = Stella_Object.cons(Stella.startupNameFromFile(f.wrapperValue), Stella.NIL);
                      collect000 = collect000.rest;
                    }
                  }
                }
              }
              OutputStream.clOutputFileHeader(outputstream, file, false);
              startupforms = Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_IN_MODULE, Stella_Object.cons(StringWrapper.wrapString(SystemDefinition.getCardinalModule(system).moduleFullName), Stella_Object.cons(Stella.NIL, Stella.NIL)))), startupforms);
              startupforms = Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_DEFUN, Stella_Object.cons(SystemDefinition.systemStartupFunctionSymbol(system), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.NIL, Stella_Object.cons(Stella.KWD_PUBLICp, Stella_Object.cons(Stella.SYM_STELLA_TRUE, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.NIL)))), startupforms);
              if (Stella.stringEqualP(system.name, "STELLA")) {
                startupforms = Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_STARTUP_TIME_PROGN, Stella_Object.cons(Stella.KWD_EARLY_INITS, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_UNLESS, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SYSTEM_STARTED_UPp, Stella_Object.cons(StringWrapper.wrapString("stella"), Stella_Object.cons(StringWrapper.wrapString("/STELLA"), Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_STARTUP, Stella_Object.cons(Stella.SYM_STELLA_FALSE, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella_Object.cons(Stella.NIL, Stella.NIL))))), startupforms);
              }
              else {
                if (system.requiredSystems != null) {
                  startupforms = Stella_Object.cons(SystemDefinition.yieldStartupRequiredSystems(system), startupforms);
                }
                { Cons form = null;
                  Cons iter001 = SystemDefinition.collectStartupFormsFromSystemFile(system);

                  for (;!(iter001 == Stella.NIL); iter001 = iter001.rest) {
                    form = ((Cons)(iter001.value));
                    startupforms = Stella_Object.cons(form, startupforms);
                  }
                }
                { Symbol startupfn = null;
                  Cons iter002 = startupfnnames;

                  for (;!(iter002 == Stella.NIL); iter002 = iter002.rest) {
                    startupfn = ((Symbol)(iter002.value));
                    if (Symbol.lookupFunction(startupfn) == null) {
                      { Object old$Module$001 = Stella.$MODULE$.get();
                        Object old$Context$001 = Stella.$CONTEXT$.get();

                        try {
                          Native.setSpecial(Stella.$MODULE$, startupfn.homeModule());
                          Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
                          Cons.defineMethodFromParseTree(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_DEFUN, Stella_Object.cons(startupfn, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.NIL, Stella_Object.cons(Stella.KWD_PUBLICp, Stella_Object.cons(Stella.SYM_STELLA_TRUE, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.NIL)))));

                        } finally {
                          Stella.$CONTEXT$.set(old$Context$001);
                          Stella.$MODULE$.set(old$Module$001);
                        }
                      }
                    }
                  }
                }
                { Cons startupfncalls = Stella.NIL;

                  { Symbol startupfn = null;
                    Cons iter003 = startupfnnames;
                    Cons collect001 = null;

                    for (;!(iter003 == Stella.NIL); iter003 = iter003.rest) {
                      startupfn = ((Symbol)(iter003.value));
                      if (collect001 == null) {
                        {
                          collect001 = Stella_Object.cons(Stella_Object.cons(startupfn, Stella.NIL), Stella.NIL);
                          if (startupfncalls == Stella.NIL) {
                            startupfncalls = collect001;
                          }
                          else {
                            Cons.addConsToEndOfConsList(startupfncalls, collect001);
                          }
                        }
                      }
                      else {
                        {
                          collect001.rest = Stella_Object.cons(Stella_Object.cons(startupfn, Stella.NIL), Stella.NIL);
                          collect001 = collect001.rest;
                        }
                      }
                    }
                  }
                  startupforms = Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_STARTUP_TIME_PROGN, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_FOREACH, Stella_Object.cons(Stella.SYM_STELLA_PHASE, Stella_Object.cons(Stella.SYM_STELLA_IN, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_INTERVAL, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_PHASE_TO_INTEGER, Stella_Object.cons(Stella.KWD_EARLY_INITS, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_PHASE_TO_INTEGER, Stella_Object.cons(Stella.KWD_FINAL, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella_Object.cons(Stella.SYM_STELLA_DO, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SETQ, Stella_Object.cons(Stella.SYM_STELLA_$STARTUP_TIME_PHASE$, Stella_Object.cons(Stella.SYM_STELLA_PHASE, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella_Object.cons(startupfncalls.concatenate(Stella.NIL, Stella.NIL), Stella.NIL)))))))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SETQ, Stella_Object.cons(Stella.SYM_STELLA_$STARTUP_TIME_PHASE$, Stella_Object.cons(IntegerWrapper.wrapInteger(999), Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella_Object.cons(Stella.NIL, Stella.NIL))))), startupforms);
                }
              }
              { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();
                Object old$PrintprettyP$000 = Stella.$PRINTPRETTYp$.get();

                try {
                  Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, true);
                  Native.setBooleanSpecial(Stella.$PRINTPRETTYp$, true);
                  { Cons form = null;
                    Cons iter004 = startupforms.reverse();

                    for (;!(iter004 == Stella.NIL); iter004 = iter004.rest) {
                      form = ((Cons)(iter004.value));
                      {
                        outputstream.nativeStream.println(form);
                        outputstream.nativeStream.println();
                      }
;
                    }
                  }

                } finally {
                  Stella.$PRINTPRETTYp$.set(old$PrintprettyP$000);
                  Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
                }
              }

            } finally {
              if (outputstream != null) {
                outputstream.free();
              }
            }
          }
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

  public static Cons collectStartupFormsFromSystemFile(SystemDefinition system) {
    { String systemfilename = Stella.makeSystemDefinitionFileName(system.name);
      Module module = null;
      Cons startupform = null;
      Cons startupforms = Stella.NIL;

      { Object old$Module$000 = Stella.$MODULE$.get();
        Object old$Context$000 = Stella.$CONTEXT$.get();

        try {
          Native.setSpecial(Stella.$MODULE$, ((Module)(Stella.$MODULE$.get())));
          Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
          { InputFileStream inputstream = null;

            try {
              inputstream = Stella.openInputFile(systemfilename, Stella.NIL);
              { Stella_Object tree = null;
                SExpressionIterator iter000 = InputStream.sExpressions(inputstream);
                Cons collect000 = null;

                loop000 : while (iter000.nextP()) {
                  tree = iter000.value;
                  startupform = null;
                  if (Stella_Object.safePrimaryType(tree) == Stella.SGT_STELLA_CONS) {
                    { Cons tree000 = ((Cons)(tree));

                      if (tree000.value == Stella.SYM_STELLA_DEFMODULE) {
                        Stella_Object.evaluate(tree000);
                        module = Stella.getStellaModule(Stella_Object.coerceToModuleName(tree000.rest.value, true), true);
                        if (module != null) {
                          startupform = Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_STARTUP_TIME_PROGN, Stella_Object.cons(Stella.KWD_MODULES, Stella_Object.cons(Module.yieldDefineModule(module), Stella_Object.cons(Stella.NIL, Stella.NIL)))));
                        }
                      }
                      if (tree000.value == Stella.SYM_STELLA_IN_MODULE) {
                        Stella_Object.evaluate(tree000);
                      }
                    }
                  }
                  else {
                  }
                  if (startupform == null) {
                    continue loop000;
                  }
                  if (collect000 == null) {
                    {
                      collect000 = Stella_Object.cons(startupform, Stella.NIL);
                      if (startupforms == Stella.NIL) {
                        startupforms = collect000;
                      }
                      else {
                        Cons.addConsToEndOfConsList(startupforms, collect000);
                      }
                    }
                  }
                  else {
                    {
                      collect000.rest = Stella_Object.cons(startupform, Stella.NIL);
                      collect000 = collect000.rest;
                    }
                  }
                }
              }

            } finally {
              if (inputstream != null) {
                inputstream.free();
              }
            }
          }
          return (startupforms);

        } finally {
          Stella.$CONTEXT$.set(old$Context$000);
          Stella.$MODULE$.set(old$Module$000);
        }
      }
    }
  }

  public static Cons yieldStartupRequiredSystems(SystemDefinition system) {
    { Cons startupforms = Stella.NIL;

      { StringWrapper systemname = null;
        Cons iter000 = system.requiredSystems;
        Cons collect000 = null;

        for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
          systemname = ((StringWrapper)(iter000.value));
          if (collect000 == null) {
            {
              collect000 = Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_UNLESS, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SYSTEM_STARTED_UPp, Stella_Object.cons(systemname, Stella_Object.cons(Stella_Object.cons(StringWrapper.wrapString(SystemDefinition.getCardinalModule(Stella.getSystemDefinition(systemname.wrapperValue)).moduleFullName), Stella.NIL), Stella.NIL)))), Stella_Object.cons(Stella_Object.cons(SystemDefinition.systemStartupFunctionSymbol(Stella.getSystemDefinition(systemname.wrapperValue)), Stella.NIL), Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.NIL);
              if (startupforms == Stella.NIL) {
                startupforms = collect000;
              }
              else {
                Cons.addConsToEndOfConsList(startupforms, collect000);
              }
            }
          }
          else {
            {
              collect000.rest = Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_UNLESS, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SYSTEM_STARTED_UPp, Stella_Object.cons(systemname, Stella_Object.cons(Stella_Object.cons(StringWrapper.wrapString(SystemDefinition.getCardinalModule(Stella.getSystemDefinition(systemname.wrapperValue)).moduleFullName), Stella.NIL), Stella.NIL)))), Stella_Object.cons(Stella_Object.cons(SystemDefinition.systemStartupFunctionSymbol(Stella.getSystemDefinition(systemname.wrapperValue)), Stella.NIL), Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.NIL);
              collect000 = collect000.rest;
            }
          }
        }
      }
      return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_STARTUP_TIME_PROGN, Stella_Object.cons(Stella.KWD_EARLY_INITS, Stella_Object.cons(startupforms.concatenate(Stella.NIL, Stella.NIL), Stella.NIL)))));
    }
  }

  public static String systemStartupFileName(SystemDefinition system) {
    if (system == null) {
      system = ((SystemDefinition)(Stella.$CURRENTSYSTEMDEFINITION$.get()));
    }
    if (system != null) {
      return ("startup-system");
    }
    else {
      return (null);
    }
  }

  public static Symbol systemStartupFunctionSymbol(SystemDefinition system) {
    return (Stella.internSymbolInModule(system.systemStartupFunctionName(), SystemDefinition.getCardinalModule(system), true));
  }

  public String systemStartupFunctionName() {
    { SystemDefinition system = this;

      return (Stella.string_systemStartupFunctionName(system.name));
    }
  }

  public static void runSystemStartupFunction(SystemDefinition system) {
    if (!Stella.runningAsLispP()) {
      return;
    }
  }

  public static Cons systemDefinitionNativeFiles(SystemDefinition system) {
    { Cons files = Cons.copyConsList(system.files);

      if (((Keyword)(Stella.$TRANSLATOROUTPUTLANGUAGE$.get())) == Stella.KWD_COMMON_LISP) {
        files = files.union(system.lispOnlyFiles);
        if (((List)(Stella.$CURRENT_STELLA_FEATURES$.get())).membP(Stella.KWD_USE_COMMON_LISP_STRUCTS)) {
          files = Stella_Object.cons(StringWrapper.wrapString(Stella.clYieldStructClassFileName(system.name)), files);
        }
      }
      else if (((Keyword)(Stella.$TRANSLATOROUTPUTLANGUAGE$.get())) == Stella.KWD_JAVA) {
        files = files.union(system.javaOnlyFiles);
      }
      else if (((Keyword)(Stella.$TRANSLATOROUTPUTLANGUAGE$.get())) == Stella.KWD_CPP) {
        files = files.union(system.cppOnlyFiles);
      }
      else {
        { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

          stream000.nativeStream.print("`" + ((Keyword)(Stella.$TRANSLATOROUTPUTLANGUAGE$.get())) + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
        }
      }
      return (files);
    }
  }

  public static Cons systemDefinitionSourceFiles(SystemDefinition system) {
    { Cons files = Cons.copyConsList(system.files);

      if (((Keyword)(Stella.$TRANSLATOROUTPUTLANGUAGE$.get())) == Stella.KWD_COMMON_LISP) {
        files = files.subtract(system.javaOnlyFiles);
        files = files.subtract(system.cppOnlyFiles);
      }
      else if (((Keyword)(Stella.$TRANSLATOROUTPUTLANGUAGE$.get())) == Stella.KWD_JAVA) {
        files = files.subtract(system.lispOnlyFiles);
        files = files.subtract(system.cppOnlyFiles);
      }
      else if (((Keyword)(Stella.$TRANSLATOROUTPUTLANGUAGE$.get())) == Stella.KWD_CPP) {
        files = files.subtract(system.lispOnlyFiles);
        files = files.subtract(system.javaOnlyFiles);
      }
      else {
        { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

          stream000.nativeStream.print("`" + ((Keyword)(Stella.$TRANSLATOROUTPUTLANGUAGE$.get())) + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
        }
      }
      return (files);
    }
  }

  public static void runSystemFinalization(SystemDefinition system) {
    { String fnname = null;
      MethodSlot finalizationfn = null;

      if (fnname != null) {
        finalizationfn = Stella.lookupFunctionByName(fnname);
      }
      if (finalizationfn != null) {
        edu.isi.stella.javalib.Native.funcall(finalizationfn.functionCode, null, new java.lang.Object [] {});
      }
    }
  }

  public static void computeOptimizationLevels(SystemDefinition system, boolean productionmodeP) {
    { Cons settings = null;

      if (productionmodeP) {
        settings = system.productionSettings;
      }
      else {
        settings = system.developmentSettings;
      }
      if (settings == null) {
        settings = Stella.getQuotedTree("((3 2 3 3) \"/STELLA\")", "/STELLA");
      }
      Stella.setOptimizationLevels(((IntegerWrapper)(settings.nth(0))).wrapperValue, ((IntegerWrapper)(settings.nth(1))).wrapperValue, ((IntegerWrapper)(settings.nth(2))).wrapperValue, ((IntegerWrapper)(settings.nth(3))).wrapperValue);
    }
  }

  public static List getSystemFiles(SystemDefinition system, Keyword type, boolean probefilesP) {
    { List files = List.newList();
      String filename = null;

      { Object old$Currentsystemdefinition$000 = Stella.$CURRENTSYSTEMDEFINITION$.get();
        Object old$Currentsystemdefinitionsubdirectory$000 = Stella.$CURRENTSYSTEMDEFINITIONSUBDIRECTORY$.get();

        try {
          Native.setSpecial(Stella.$CURRENTSYSTEMDEFINITION$, Stella.getSystemDefinition(system.name));
          Native.setSpecial(Stella.$CURRENTSYSTEMDEFINITIONSUBDIRECTORY$, ((((SystemDefinition)(Stella.$CURRENTSYSTEMDEFINITION$.get())) != null) ? ((SystemDefinition)(Stella.$CURRENTSYSTEMDEFINITION$.get())).directory : null));
          if (((SystemDefinition)(Stella.$CURRENTSYSTEMDEFINITION$.get())) != null) {
            {
              { StringWrapper f = null;
                Cons iter000 = ((SystemDefinition)(Stella.$CURRENTSYSTEMDEFINITION$.get())).files;

                for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
                  f = ((StringWrapper)(iter000.value));
                  if (type == Stella.KWD_JAVA) {
                    filename = StringWrapper.javaTranslateClassNamestring(StringWrapper.wrapString("_STARTUP-" + Native.stringUpcase(f.wrapperValue))).wrapperValue;
                  }
                  else {
                    filename = Stella_Object.makeFileNameFromRelativePath(f, type);
                  }
                  Stella.helpGetSystemFiles(filename, files, probefilesP);
                }
              }
              if (type == Stella.KWD_JAVA) {
                if (SystemDefinition.getCardinalModule(((SystemDefinition)(Stella.$CURRENTSYSTEMDEFINITION$.get()))) == null) {
                  {
                    System.out.println("No cardinal module defined for system `" + system.name + "'");
                    System.out.println();
                  }
;
                  return (Stella.NIL_LIST);
                }
                { Stella_Class renamed_Class = null;
                  Iterator iter001 = Module.allClasses(SystemDefinition.getCardinalModule(((SystemDefinition)(Stella.$CURRENTSYSTEMDEFINITION$.get()))), true);

                  while (iter001.nextP()) {
                    renamed_Class = ((Stella_Class)(iter001.value));
                    filename = renamed_Class.javaMakeCodeOutputFileName(false);
                    Stella.helpGetSystemFiles(filename, files, probefilesP);
                  }
                }
                filename = Stella.string_javaMakeCodeOutputFileName(Module.javaYieldFlotsamClassName(SystemDefinition.getCardinalModule(((SystemDefinition)(Stella.$CURRENTSYSTEMDEFINITION$.get())))), false);
                Stella.helpGetSystemFiles(filename, files, probefilesP);
              }
              else {
              }
            }
          }
          else {
            {
              Stella.STANDARD_WARNING.nativeStream.println("Warning: Can't find a system named `" + system.name + "'");
              Stella.STANDARD_WARNING.nativeStream.println();
            }
;
          }

        } finally {
          Stella.$CURRENTSYSTEMDEFINITIONSUBDIRECTORY$.set(old$Currentsystemdefinitionsubdirectory$000);
          Stella.$CURRENTSYSTEMDEFINITION$.set(old$Currentsystemdefinition$000);
        }
      }
      return (files);
    }
  }

  public static Module getCardinalModule(SystemDefinition system) {
    { String name = system.cardinalModule;
      Module module = null;

      if (name != null) {
        module = Stella.getStellaModule(name, false);
        if (module == null) {
          module = Stella.getStellaModule(Native.stringUpcase(name), false);
        }
      }
      if (module == null) {
        {
          Stella.STANDARD_WARNING.nativeStream.println("Warning: No cardinal module defined for system: `" + system + "'");
          Stella.STANDARD_WARNING.nativeStream.println();
        }
;
      }
      return (module);
    }
  }

  public void printObject(java.io.PrintStream stream) {
    { SystemDefinition self = this;

      stream.print("|SYSTEM|" + self.name);
    }
  }

  public static Stella_Object accessSystemDefinitionSlotValue(SystemDefinition self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Stella.SYM_STELLA_NAME) {
      if (setvalueP) {
        self.name = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = StringWrapper.wrapString(self.name);
      }
    }
    else if (slotname == Stella.SYM_STELLA_DIRECTORY) {
      if (setvalueP) {
        self.directory = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = StringWrapper.wrapString(self.directory);
      }
    }
    else if (slotname == Stella.SYM_STELLA_FILES) {
      if (setvalueP) {
        self.files = ((Cons)(value));
      }
      else {
        value = self.files;
      }
    }
    else if (slotname == Stella.SYM_STELLA_LISP_ONLY_FILES) {
      if (setvalueP) {
        self.lispOnlyFiles = ((Cons)(value));
      }
      else {
        value = self.lispOnlyFiles;
      }
    }
    else if (slotname == Stella.SYM_STELLA_CPP_ONLY_FILES) {
      if (setvalueP) {
        self.cppOnlyFiles = ((Cons)(value));
      }
      else {
        value = self.cppOnlyFiles;
      }
    }
    else if (slotname == Stella.SYM_STELLA_JAVA_ONLY_FILES) {
      if (setvalueP) {
        self.javaOnlyFiles = ((Cons)(value));
      }
      else {
        value = self.javaOnlyFiles;
      }
    }
    else if (slotname == Stella.SYM_STELLA_PREPROCESSED_FILES) {
      if (setvalueP) {
        self.preprocessedFiles = ((Cons)(value));
      }
      else {
        value = self.preprocessedFiles;
      }
    }
    else if (slotname == Stella.SYM_STELLA_REQUIRED_SYSTEMS) {
      if (setvalueP) {
        self.requiredSystems = ((Cons)(value));
      }
      else {
        value = self.requiredSystems;
      }
    }
    else if (slotname == Stella.SYM_STELLA_LOADEDp) {
      if (setvalueP) {
        self.loadedP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.loadedP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else if (slotname == Stella.SYM_STELLA_UP_TO_DATEp) {
      if (setvalueP) {
        self.upToDateP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.upToDateP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else if (slotname == Stella.SYM_STELLA_CARDINAL_MODULE) {
      if (setvalueP) {
        self.cardinalModule = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = StringWrapper.wrapString(self.cardinalModule);
      }
    }
    else if (slotname == Stella.SYM_STELLA_SOURCE_ROOT_DIRECTORY) {
      if (setvalueP) {
        self.sourceRootDirectory = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = StringWrapper.wrapString(self.sourceRootDirectory);
      }
    }
    else if (slotname == Stella.SYM_STELLA_NATIVE_ROOT_DIRECTORY) {
      if (setvalueP) {
        self.nativeRootDirectory = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = StringWrapper.wrapString(self.nativeRootDirectory);
      }
    }
    else if (slotname == Stella.SYM_STELLA_BINARY_ROOT_DIRECTORY) {
      if (setvalueP) {
        self.binaryRootDirectory = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = StringWrapper.wrapString(self.binaryRootDirectory);
      }
    }
    else if (slotname == Stella.SYM_STELLA_BANNER) {
      if (setvalueP) {
        self.banner = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = StringWrapper.wrapString(self.banner);
      }
    }
    else if (slotname == Stella.SYM_STELLA_COPYRIGHT_HEADER) {
      if (setvalueP) {
        self.banner = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = StringWrapper.wrapString(self.banner);
      }
    }
    else if (slotname == Stella.SYM_STELLA_PRODUCTION_SETTINGS) {
      if (setvalueP) {
        self.productionSettings = ((Cons)(value));
      }
      else {
        value = self.productionSettings;
      }
    }
    else if (slotname == Stella.SYM_STELLA_DEVELOPMENT_SETTINGS) {
      if (setvalueP) {
        self.developmentSettings = ((Cons)(value));
      }
      else {
        value = self.developmentSettings;
      }
    }
    else if (slotname == Stella.SYM_STELLA_FINALIZATION_FUNCTION) {
      if (setvalueP) {
        self.finalizationFunction = ((Symbol)(value));
      }
      else {
        value = self.finalizationFunction;
      }
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + slotname + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { SystemDefinition self = this;

      return (Stella.SGT_STELLA_SYSTEM_DEFINITION);
    }
  }

}

