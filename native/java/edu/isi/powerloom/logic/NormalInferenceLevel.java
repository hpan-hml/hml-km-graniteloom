//  -*- Mode: Java -*-
//
// NormalInferenceLevel.java

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

package edu.isi.powerloom.logic;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.stella.*;

/** The normal inference level employs all proof strategies
 * except disjunctive implication introduction and refutation.
 * @author Stella Java Translator
 */
public class NormalInferenceLevel extends InferenceLevel {
  public static NormalInferenceLevel newNormalInferenceLevel() {
    { NormalInferenceLevel self = null;

      self = new NormalInferenceLevel();
      self.keyword = null;
      return (self);
    }
  }

  public Cons levellizedAllSlotValueTypes(LogicObject self, Surrogate relation) {
    { NormalInferenceLevel level = this;

      return (Logic.applyCachedRetrieve(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pOBJECT, Stella_Object.cons(Logic.SYM_LOGIC_pTYPE, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.list$(Stella_Object.cons(Logic.SYM_STELLA_AND, Stella_Object.cons(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_RANGE_TYPE, Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pOBJECT, Stella_Object.cons(Logic.SYM_LOGIC_pTYPE, Stella_Object.cons(Stella.NIL, Stella.NIL)))))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_BOUND_VARIABLES, Stella_Object.cons(Logic.SYM_LOGIC_pTYPE, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_CONCEPT, Stella_Object.cons(Logic.SYM_LOGIC_pTYPE, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.NIL, Stella.NIL)))))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(self, Stella_Object.cons(null, Stella.NIL)))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_ALL_SLOT_VALUE_TYPES_QUERY_000, new Object[1]));
    }
  }

  public int levellizedGetSlotMaximumCardinality(LogicObject self, Surrogate relation) {
    { NormalInferenceLevel level = this;

      { Cons n = Logic.applyCachedRetrieve(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pOBJECT, Stella_Object.cons(Logic.SYM_LOGIC_pN, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_RANGE_MAX_CARDINALITY, Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pOBJECT, Stella_Object.cons(Logic.SYM_LOGIC_pN, Stella_Object.cons(Stella.NIL, Stella.NIL)))))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(self, Stella_Object.cons(null, Stella.NIL)))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_GET_SLOT_MAXIMUM_CARDINALITY_QUERY_000, new Object[1]);

        if (n == Stella.NIL) {
          return (Stella.NULL_INTEGER);
        }
        else {
          return (IntegerWrapper.unwrapInteger(((IntegerWrapper)(n.value))));
        }
      }
    }
  }

  public int levellizedGetSlotMinimumCardinality(LogicObject self, Surrogate relation) {
    { NormalInferenceLevel level = this;

      { Cons n = Logic.applyCachedRetrieve(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pOBJECT, Stella_Object.cons(Logic.SYM_LOGIC_pN, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_RANGE_MIN_CARDINALITY, Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pOBJECT, Stella_Object.cons(Logic.SYM_LOGIC_pN, Stella_Object.cons(Stella.NIL, Stella.NIL)))))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(self, Stella_Object.cons(null, Stella.NIL)))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_GET_SLOT_MINIMUM_CARDINALITY_QUERY_000, new Object[1]);

        if (n == Stella.NIL) {
          return (0);
        }
        else {
          return (IntegerWrapper.unwrapInteger(((IntegerWrapper)(n.value))));
        }
      }
    }
  }

  public boolean levellizedTestRelationOnArgumentsP(Surrogate relation, Cons arguments) {
    { NormalInferenceLevel level = this;

      switch (arguments.length()) {
        case 1: 
          { Stella_Object arg1 = arguments.value;

            return (Logic.applyCachedAsk(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(arg1, Stella.NIL))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_TEST_RELATION_ON_ARGUMENTSp_QUERY_000, new Object[1]));
          }
        case 2: 
          { Stella_Object arg1 = arguments.value;
            Stella_Object arg2 = arguments.rest.value;

            return (Logic.applyCachedAsk(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(arg1, Stella_Object.cons(arg2, Stella.NIL)))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_TEST_RELATION_ON_ARGUMENTSp_QUERY_001, new Object[1]));
          }
        case 3: 
          { Stella_Object arg1 = arguments.value;
            Stella_Object arg2 = arguments.rest.value;
            Stella_Object arg3 = arguments.rest.rest.value;

            return (Logic.applyCachedAsk(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(arg1, Stella_Object.cons(arg2, Stella_Object.cons(arg3, Stella.NIL))))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_TEST_RELATION_ON_ARGUMENTSp_QUERY_002, new Object[1]));
          }
        case 4: 
          { Stella_Object arg1 = arguments.value;
            Stella_Object arg2 = arguments.rest.value;
            Stella_Object arg3 = arguments.rest.rest.value;
            Stella_Object arg4 = arguments.fourth();

            return (Logic.applyCachedAsk(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pW, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Logic.SYM_LOGIC_pZ, Stella_Object.cons(Stella.NIL, Stella.NIL))))))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pW, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Logic.SYM_LOGIC_pZ, Stella_Object.cons(Stella.NIL, Stella.NIL))))))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(arg1, Stella_Object.cons(arg2, Stella_Object.cons(arg3, Stella_Object.cons(arg4, Stella.NIL)))))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_TEST_RELATION_ON_ARGUMENTSp_QUERY_003, new Object[1]));
          }
        default:
          return (TruthValue.trueTruthValueP(Logic.callAsk(Stella_Object.cons(Stella_Object.cons(Stella.internSymbolInModule(relation.symbolName, ((Module)(relation.homeContext)), false), arguments.concatenate(Stella.NIL, Stella.NIL)), Stella.NIL))));
      }
    }
  }

  public Cons levellizedAllRelationValues(Surrogate relation, Cons nminusonearguments) {
    { NormalInferenceLevel level = this;

      switch (nminusonearguments.length()) {
        case 0: 
          return (Logic.applyCachedRetrieve(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(null, Stella.NIL))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_ALL_RELATION_VALUES_QUERY_000, new Object[1]));
        case 1: 
          { Stella_Object arg1 = nminusonearguments.value;

            return (Logic.applyCachedRetrieve(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(arg1, Stella_Object.cons(null, Stella.NIL)))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_ALL_RELATION_VALUES_QUERY_001, new Object[1]));
          }
        case 2: 
          { Stella_Object arg1 = nminusonearguments.value;
            Stella_Object arg2 = nminusonearguments.rest.value;

            return (Logic.applyCachedRetrieve(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Logic.SYM_LOGIC_pZ, Stella_Object.cons(Stella.NIL, Stella.NIL)))))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Logic.SYM_LOGIC_pZ, Stella_Object.cons(Stella.NIL, Stella.NIL)))))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(arg1, Stella_Object.cons(arg2, Stella_Object.cons(null, Stella.NIL))))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_ALL_RELATION_VALUES_QUERY_002, new Object[1]));
          }
        case 3: 
          { Stella_Object arg1 = nminusonearguments.value;
            Stella_Object arg2 = nminusonearguments.rest.value;
            Stella_Object arg3 = nminusonearguments.rest.rest.value;

            return (Logic.applyCachedRetrieve(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pW, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Logic.SYM_LOGIC_pZ, Stella_Object.cons(Stella.NIL, Stella.NIL))))))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pRELATION, Stella_Object.cons(Logic.SYM_LOGIC_pW, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Logic.SYM_LOGIC_pY, Stella_Object.cons(Logic.SYM_LOGIC_pZ, Stella_Object.cons(Stella.NIL, Stella.NIL))))))), Stella.consList(Stella_Object.cons(relation, Stella_Object.cons(arg1, Stella_Object.cons(arg2, Stella_Object.cons(arg3, Stella_Object.cons(null, Stella.NIL)))))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_ALL_RELATION_VALUES_QUERY_003, new Object[1]));
          }
        default:
          return (Logic.callRetrieve(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_ALL, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Stella_Object.cons(Stella.internSymbolInModule(relation.symbolName, ((Module)(relation.homeContext)), false), nminusonearguments.concatenate(Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella.NIL), Stella.NIL)), Stella_Object.cons(Stella.NIL, Stella.NIL)))))).consify());
      }
    }
  }

  public Cons levellizedAllClassInstances(Surrogate type) {
    { NormalInferenceLevel level = this;

      return (Logic.applyCachedRetrieve(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pCONCEPT, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pCONCEPT, Stella_Object.cons(Logic.SYM_LOGIC_pX, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.consList(Stella_Object.cons(type, Stella_Object.cons(null, Stella.NIL))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_ALL_CLASS_INSTANCES_QUERY_000, new Object[1]));
    }
  }

  public boolean levellizedTestTypeOnInstanceP(Stella_Object self, Surrogate type) {
    { NormalInferenceLevel level = this;

      return (Logic.applyCachedAsk(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pCONCEPT, Stella_Object.cons(Logic.SYM_LOGIC_pINSTANCE, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_pCONCEPT, Stella_Object.cons(Logic.SYM_LOGIC_pINSTANCE, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.consList(Stella_Object.cons(type, Stella_Object.cons(self, Stella.NIL))), Stella.consList(Stella.NIL), Logic.SYM_LOGIC_M_NORMAL_INFERENCE_LEVELdLEVELLIZED_TEST_TYPE_ON_INSTANCEp_QUERY_000, new Object[1]));
    }
  }

  public Surrogate primaryType() {
    { NormalInferenceLevel self = this;

      return (Logic.SGT_LOGIC_NORMAL_INFERENCE_LEVEL);
    }
  }

}

