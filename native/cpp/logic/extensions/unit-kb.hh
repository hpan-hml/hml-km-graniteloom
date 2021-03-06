//  -*- Mode: C++ -*-

// unit-kb.hh

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
 | Portions created by the Initial Developer are Copyright (C) 1997-2014      |
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




namespace units {
  using namespace stella_utilities;
  using namespace stella;
  using namespace logic;

// Function signatures:
void startupUnitKb();

// Auxiliary global declarations:
extern Symbol* SYM_UNIT_KB_UNIT_KB_MEASURE;
extern Keyword* KWD_UNIT_KB_DOCUMENTATION;
extern Symbol* SYM_UNIT_KB_UNIT_KB_BASE_MEASURE;
extern Keyword* KWD_UNIT_KB_AXIOMS;
extern Symbol* SYM_UNIT_KB_UNIT_KB_MEASURE_UNIT;
extern Symbol* SYM_UNIT_KB_UNIT_KB_VALUE_MEASURE;
extern Symbol* SYM_UNIT_KB_UNIT_KB_NUMERATOR_MEASURES;
extern Symbol* SYM_UNIT_KB_UNIT_KB_DENOMINATOR_MEASURES;
extern Symbol* SYM_UNIT_KB_UNIT_KB_COMENSURATE_UNITS;
extern Symbol* SYM_UNIT_KB_UNIT_KB_UNITS;
extern Keyword* KWD_UNIT_KB__g;
extern Symbol* SYM_UNIT_KB_UNIT_SUPPORT_pDIM;
extern Symbol* SYM_UNIT_KB_UNIT_KB_Ui;
extern Symbol* SYM_UNIT_KB_LOGIC_pZ;
extern Symbol* SYM_UNIT_KB_UNIT_KB_U_;
extern Symbol* SYM_UNIT_KB_UNIT_KB_Uo;
extern Symbol* SYM_UNIT_KB_UNIT_KB_U_DIV;
extern Symbol* SYM_UNIT_KB_UNIT_KB_U_ABS;
extern Symbol* SYM_UNIT_KB_UNIT_KB_U_SIGNUM;
extern Symbol* SYM_UNIT_KB_UNIT_KB_U_WITHIN_DELTA;
extern Keyword* KWD_UNIT_KB_eg;
extern Keyword* KWD_UNIT_KB_le;
extern Symbol* SYM_UNIT_KB_UNIT_KB_U_WITHIN_FACTOR;
extern Symbol* SYM_UNIT_KB_UNIT_KB_U_MINIMUM_VALUE;
extern Symbol* SYM_UNIT_KB_UNIT_KB_U_MAXIMUM_VALUE;
extern Symbol* SYM_UNIT_KB_UNIT_KB_U_SUM;
extern Symbol* SYM_UNIT_KB_UNIT_SUPPORT_STARTUP_UNIT_KB;
extern Symbol* SYM_UNIT_KB_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace units
