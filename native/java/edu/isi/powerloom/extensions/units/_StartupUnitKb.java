//  -*- Mode: Java -*-
//
// _StartupUnitKb.java

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
 | The Original Code is the PowerLoom KR&R System.                            |
 |                                                                            |
 | The Initial Developer of the Original Code is                              |
 | UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
 | 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
 |                                                                            |
 | Portions created by the Initial Developer are Copyright (C) 1997-2006      |
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
 +----------------------------- END LICENSE BLOCK ----------------------------+
*/

package edu.isi.powerloom.extensions.units;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.powerloom.logic.*;
import edu.isi.stella.*;
import edu.isi.stella.utilities.*;

public class _StartupUnitKb {
  public static void startupUnitKb() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/UNIT-SUPPORT", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          Units.SYM_UNIT_KB_MEASURE = ((Symbol)(Stella.internRigidSymbolWrtModule("MEASURE", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.KWD_DOCUMENTATION = ((Keyword)(Stella.internRigidSymbolWrtModule("DOCUMENTATION", null, 2)));
          Units.SYM_UNIT_KB_BASE_MEASURE = ((Symbol)(Stella.internRigidSymbolWrtModule("BASE-MEASURE", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.KWD_AXIOMS = ((Keyword)(Stella.internRigidSymbolWrtModule("AXIOMS", null, 2)));
          Units.SYM_UNIT_KB_MEASURE_UNIT = ((Symbol)(Stella.internRigidSymbolWrtModule("MEASURE-UNIT", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_VALUE_MEASURE = ((Symbol)(Stella.internRigidSymbolWrtModule("VALUE-MEASURE", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_NUMERATOR_MEASURES = ((Symbol)(Stella.internRigidSymbolWrtModule("NUMERATOR-MEASURES", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_DENOMINATOR_MEASURES = ((Symbol)(Stella.internRigidSymbolWrtModule("DENOMINATOR-MEASURES", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_COMENSURATE_UNITS = ((Symbol)(Stella.internRigidSymbolWrtModule("COMENSURATE-UNITS", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_UNITS = ((Symbol)(Stella.internRigidSymbolWrtModule("UNITS", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.KWD__g = ((Keyword)(Stella.internRigidSymbolWrtModule("->", null, 2)));
          Units.SYM_UNIT_SUPPORT_pDIM = ((Symbol)(Stella.internRigidSymbolWrtModule("?DIM", null, 0)));
          Units.SYM_UNIT_KB_Ui = ((Symbol)(Stella.internRigidSymbolWrtModule("U+", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_LOGIC_pZ = ((Symbol)(Stella.internRigidSymbolWrtModule("?Z", Stella.getStellaModule("/LOGIC", true), 0)));
          Units.SYM_UNIT_KB_U_ = ((Symbol)(Stella.internRigidSymbolWrtModule("U-", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_U$ = ((Symbol)(Stella.internRigidSymbolWrtModule("U*", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_U_DIV = ((Symbol)(Stella.internRigidSymbolWrtModule("U-DIV", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_U_ABS = ((Symbol)(Stella.internRigidSymbolWrtModule("U-ABS", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_U_SIGNUM = ((Symbol)(Stella.internRigidSymbolWrtModule("U-SIGNUM", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_U_WITHIN_DELTA = ((Symbol)(Stella.internRigidSymbolWrtModule("U-WITHIN-DELTA", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.KWD_eg = ((Keyword)(Stella.internRigidSymbolWrtModule("=>", null, 2)));
          Units.KWD_le = ((Keyword)(Stella.internRigidSymbolWrtModule("<=", null, 2)));
          Units.SYM_UNIT_KB_U_WITHIN_FACTOR = ((Symbol)(Stella.internRigidSymbolWrtModule("U-WITHIN-FACTOR", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_U_MINIMUM_VALUE = ((Symbol)(Stella.internRigidSymbolWrtModule("U-MINIMUM-VALUE", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_U_MAXIMUM_VALUE = ((Symbol)(Stella.internRigidSymbolWrtModule("U-MAXIMUM-VALUE", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_KB_U_SUM = ((Symbol)(Stella.internRigidSymbolWrtModule("U-SUM", Stella.getStellaModule("/UNIT-KB", true), 0)));
          Units.SYM_UNIT_SUPPORT_STARTUP_UNIT_KB = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-UNIT-KB", null, 0)));
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("STARTUP-UNIT-KB", "(DEFUN STARTUP-UNIT-KB () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.extensions.units._StartupUnitKb", "startupUnitKb", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Units.SYM_UNIT_SUPPORT_STARTUP_UNIT_KB);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, edu.isi.powerloom.extensions.Extensions.SYM_STELLA_METHOD_STARTUP_CLASSNAME, StringWrapper.wrapString("_StartupUnitKb"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          { Object old$Module$001 = Stella.$MODULE$.get();
            Object old$Context$001 = Stella.$CONTEXT$.get();

            try {
              Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("PL-KERNEL-KB", true));
              Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
              Logic.defconcept(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_MEASURE))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.NIL))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("A (pre-defined) measure of some physical quantity.")))), Stella.NIL)))));
              Logic.defconcept(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_BASE_MEASURE))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?M /UNIT-KB/MEASURE) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("A base measure.  One that defines fundamental units which\nare not composed of any other units.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((CLOSED /UNIT-KB/BASE-MEASURE) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))));
              Logic.defrelation(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_MEASURE_UNIT))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("(((?M /UNIT-KB/MEASURE) (?U STRING)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("A mapping between a Measure and the unit names that belong\nto that measure.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((CLOSED /UNIT-KB/MEASURE-UNIT) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_VALUE_MEASURE))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?DIM (?M /UNIT-KB/MEASURE)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("A mapping from a dimensioned value to the corresponding measure.\nIt may not, in fact, exist for dimensions that are formed by ad hoc\ncombinations of units or by arithmetic manipulations of dimensions.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/VALUE-MEASURE) (CLOSED /UNIT-KB/VALUE-MEASURE) (RELATION-SPECIALIST /UNIT-KB/VALUE-MEASURE U-VALUE-MEASURE-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_NUMERATOR_MEASURES))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?DIM (?M /PL-KERNEL-KB/LIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("A mapping from a dimensioned value or a measure to\na list of the base measures in the numerator of the expression.\nThe measures will be in a canonical order.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/NUMERATOR-MEASURES) (RELATION-SPECIALIST /UNIT-KB/NUMERATOR-MEASURES U-BASE-MEASURES-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_DENOMINATOR_MEASURES))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?DIM (?M /PL-KERNEL-KB/LIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("A mapping from a dimensioned value or a measure to\na list of the base measures in the denominator of the expression.\nThe measures will be in a canonical order.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/DENOMINATOR-MEASURES) (RELATION-SPECIALIST /UNIT-KB/DENOMINATOR-MEASURES U-BASE-MEASURES-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))));
              Logic.defrelation(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_COMENSURATE_UNITS))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?X ?Y) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("A (computed) relation between units expressions that are\ncomensurate.  That means they can be compared with one another,\nadded or subtracted.  Works with either dimensioned quantities or\nunit expressions (strings)")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/COMENSURATE-UNITS) (RELATION-SPECIALIST /UNIT-KB/COMENSURATE-UNITS COMENSURATE-UNITS-SPECIALIST) (HANDLES-REVERSE-POLARITY COMENSURATE-UNITS-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_UNITS))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("(((?M NUMBER) (?U STRING)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD__g, Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_SUPPORT_pDIM))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Connects a MAGNITUDE STRING representation of a dimensioned number\n to the actual\ninternal representation.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/UNITS) (RELATION-EVALUATOR /UNIT-KB/UNITS UNITS-EVALUATOR) (RELATION-SPECIALIST /UNIT-KB/UNITS UNITS-SPECIALIST) (GOES-TRUE-DEMON /UNIT-KB/UNITS UNITS-EVALUATOR)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_Ui))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?X ?Y) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD__g, Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_LOGIC_pZ))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Function that adds two dim numbers.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/U+) (RELATION-CONSTRAINT /UNIT-KB/U+ U-PLUS-CONSTRAINT) (RELATION-SPECIALIST /UNIT-KB/U+ /PL-KERNEL-KB/CONSTRAINT-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_U_))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?X ?Y) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD__g, Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_LOGIC_pZ))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Function that subtracts two dim numbers.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/U-) (RELATION-CONSTRAINT /UNIT-KB/U- U-MINUS-CONSTRAINT) (RELATION-SPECIALIST /UNIT-KB/U- /PL-KERNEL-KB/CONSTRAINT-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_U$))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?X ?Y) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD__g, Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_LOGIC_pZ))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Function that multiplies two dim numbers.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/U*) (RELATION-CONSTRAINT /UNIT-KB/U* U-TIMES-CONSTRAINT) (RELATION-SPECIALIST /UNIT-KB/U* /PL-KERNEL-KB/CONSTRAINT-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_U_DIV))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?X ?Y) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD__g, Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_LOGIC_pZ))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Function that divides two dim numbers.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/U-DIV) (RELATION-CONSTRAINT /UNIT-KB/U-DIV U-DIVIDE-CONSTRAINT) (RELATION-SPECIALIST /UNIT-KB/U-DIV /PL-KERNEL-KB/CONSTRAINT-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_U_ABS))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?X) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD__g, Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_LOGIC_pZ))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Absolute value of dim number.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/U-ABS) (RELATION-SPECIALIST /UNIT-KB/U-ABS U-ABS-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))))));
              Logic.deffunction(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_U_SIGNUM))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?X) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD__g, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?Z INTEGER) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Signum function of dim number.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED /UNIT-KB/U-SIGNUM) (RELATION-SPECIALIST /UNIT-KB/U-SIGNUM U-SIGNUM-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))))));
              Logic.defrelation(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_U_WITHIN_DELTA))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?X ?Y ?Z) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("?X and ?Y do not differ in value by more than ?Z.\n?Z must be positive.\n\nFor example (/unit-kb/u-within-delta (units 10.0 \"ft\") (units 3.0 \"m\") (units 2 \"in\"))\nis true.  This relation is useful for numeric comparisons where floating point\ncomputations (or other rounding errors) introduce minor inaccuracies\nthat prevent a straight equality test from succeeding.")))), Stella_Object.cons(Units.KWD_eg, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((>= (/UNIT-KB/U-SIGNUM ?Z) 0) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_le, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((=< (/UNIT-KB/U-ABS (/UNIT-KB/U- ?X ?Y)) ?Z) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))))));
              Logic.defrelation(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_U_WITHIN_FACTOR))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((?X ?Y ?Z) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("?X and ?Y are with factor ?Z of each other.  The\nfactor is applied relative to ?X.  ?Z must be positive.\n\nThat means (/unit-kb/u-within-factor (units 100 \"km\") (units 60 \"km\") (units 0.5 \"\"))\nis true (60km is in the range 50km-150km), but the converse\n  (/unit-kb/u-within-factor (units 60 \"km\") (units 100 \"km\") (units 50 \"%\"))\nis not (100km is not in the range 30km-90km).")))), Stella_Object.cons(Units.KWD_eg, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((>= (/UNIT-KB/U-SIGNUM ?Z) 0) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_le, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((=< (/UNIT-KB/U-ABS (/UNIT-KB/U- ?X ?Y)) (/UNIT-KB/U* ?Z (/UNIT-KB/U-ABS ?X))) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))))));
              Logic.defrelation(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_U_MINIMUM_VALUE))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("(((?L /PL-KERNEL-KB/COLLECTION) ?MIN) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Binds ?min to the minimum of the dimensioned numbers in the list ?l.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (RELATION-SPECIALIST /UNIT-KB/U-MINIMUM-VALUE MINIMUM-OF-UNITS-SPECIALIST) (SINGLE-VALUED /UNIT-KB/U-MINIMUM-VALUE)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))));
              Logic.defrelation(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_U_MAXIMUM_VALUE))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("(((?L /PL-KERNEL-KB/COLLECTION) ?MAX) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Binds ?max to the maximum of the dimensioned numbers in the list ?l.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (RELATION-SPECIALIST /UNIT-KB/U-MAXIMUM-VALUE MAXIMUM-OF-UNITS-SPECIALIST) (SINGLE-VALUED /UNIT-KB/U-MAXIMUM-VALUE)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))));
              Logic.defrelation(Stella_Object.cons(((Symbol)(Stella_Object.copyConsTree(Units.SYM_UNIT_KB_U_SUM))), Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("(((?L /PL-KERNEL-KB/COLLECTION) ?SUM) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella_Object.cons(Units.KWD_DOCUMENTATION, Stella_Object.cons(((StringWrapper)(Stella_Object.copyConsTree(StringWrapper.wrapString("Binds ?sum to the sum of the dimensioned numbers in the list ?l.")))), Stella_Object.cons(Units.KWD_AXIOMS, Stella_Object.cons(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (RELATION-SPECIALIST /UNIT-KB/U-SUM SUM-OF-UNITS-SPECIALIST) (SINGLE-VALUED /UNIT-KB/U-SUM)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))), Stella.NIL)))))));
              Logic.renamed_Assert(((Cons)(Stella_Object.copyConsTree(Stella.getQuotedTree("((AND (COMPUTED-PROCEDURE UNITS-EVALUATOR) (COMPUTED-PROCEDURE UNITS-SPECIALIST) (COMPUTED-PROCEDURE U-ABS-SPECIALIST) (COMPUTED-PROCEDURE U-SIGNUM-SPECIALIST) (COMPUTED-PROCEDURE MINIMUM-OF-UNITS-SPECIALIST) (COMPUTED-PROCEDURE MAXIMUM-OF-UNITS-SPECIALIST) (COMPUTED-PROCEDURE SUM-OF-UNITS-SPECIALIST) (COMPUTED-PROCEDURE U-VALUE-MEASURE-SPECIALIST) (COMPUTED-PROCEDURE U-BASE-MEASURES-SPECIALIST) (COMPUTED-PROCEDURE COMENSURATE-UNITS-SPECIALIST)) \"/UNIT-SUPPORT\")", "/UNIT-SUPPORT")))));
              Units.initializeMeasureConcepts();
              Logic.processDefinitions();

            } finally {
              Stella.$CONTEXT$.set(old$Context$001);
              Stella.$MODULE$.set(old$Module$001);
            }
          }
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
