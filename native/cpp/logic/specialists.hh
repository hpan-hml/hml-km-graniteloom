//  -*- Mode: C++ -*-

// specialists.hh

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


namespace logic {
  using namespace stella;

// Class definitions:
class ComputedProcedure : public Thing {
// Each instance denotes a programming language 
// function that computes some procedure.  The slot 'procedure-name'
// provides the name of the procedure.  The slot 'procedure-code'
// points directly to the procedure itself.  Both slots are optional;
// if neither is supplied, the procedure will be invoked by extracting
// its name from the name of the instance.
public:
  Symbol* procedureName;
  cpp_function_code procedureCode;
public:
  virtual Surrogate* primaryType();
};

class SubstringPositionIterator : public Iterator {
public:
  char* superString;
  char* subString;
  int start;
  int subLength;
public:
  virtual Surrogate* primaryType();
  virtual int length();
  virtual boolean nextP();
};

class SavedContextProofAdjunct : public ProofAdjunct {
public:
  Context* savedContext;
public:
  virtual Surrogate* primaryType();
};


// Global declarations:
extern int oPROTOTYPE_ID_COUNTERo;
extern boolean oACCELERATE_FRAME_COMPUTATIONSpo;

// Function signatures:
ComputedProcedure* newComputedProcedure();
Object* accessComputedProcedureSlotValue(ComputedProcedure* self, Symbol* slotname, Object* value, boolean setvalueP);
cpp_function_code functionCodeFromProcedure(Object* p);
cpp_function_code lookupSpecialist(NamedDescription* description);
cpp_function_code lookupConstraint(NamedDescription* description);
cpp_function_code lookupComputation(NamedDescription* description);
cpp_function_code lookupEvaluator(NamedDescription* description);
Keyword* selectTestResult(boolean successP, boolean terminalP, ControlFrame* frame);
Keyword* selectProofResult(boolean successP, boolean continuingP, boolean terminalP);
boolean nullWrapperP(Object* self);
Keyword* nativeSlotReaderSpecialist(ControlFrame* frame, Keyword* lastmove);
SubstringPositionIterator* newSubstringPositionIterator(char* superString, char* subString);
Object* accessSubstringPositionIteratorSlotValue(SubstringPositionIterator* self, Symbol* slotname, Object* value, boolean setvalueP);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* computationSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* constraintSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* squareRootSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* absoluteValueSpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

List* enumerationsContainingMember(Object* self);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* memberOfSpecialist(ControlFrame* frame, Keyword* lastmove);
void memberOfEvaluator(Proposition* self);
Keyword* instanceOfSpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

boolean testDisjointTermsP(Object* term1, Object* term2);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* subsetOfSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* holdsSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* cutSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* boundVariablesSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* forkSpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

Proposition* computeSubqueryOptions(ControlFrame* frame, PropertyList*& _Return1);
QueryIterator* createQuerySpecialistIterator(ControlFrame* frame, boolean& _Return1, boolean& _Return2);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* querySpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* conceptPrototypeSpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

NamedDescription* conceptPrototypeOf(LogicObject* self);
boolean conceptPrototypeP(LogicObject* self);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* closedSpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

boolean closedByAssertionP(Object* self);
boolean closedTermP(Object* self);
boolean helpClosedTermP(Object* self, Cons* activeterms);
boolean closedPropositionP(Proposition* self);
boolean helpClosedPropositionP(Proposition* self, Cons* activeterms);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* singleValuedSpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

boolean singleValuedTermP(Object* self);
boolean nonRecursiveSingleValuedTermP(Object* self);
boolean singleValuedGoalP(Proposition* proposition, Cons* iovariables, Cons* boundvariables);
boolean helpSingleValuedGoalP(Proposition* proposition, Cons* iovariables, Cons* boundvariables, boolean recursiveP);
void helpCollectSinglyBoundVariables(Proposition* proposition, List* boundvariables, boolean recursiveP);
void createCollectDescriptionExtensionFrame(ControlFrame* frame, Description* description);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* collectIntoSetSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* lengthOfListSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* minimumOfNumbersSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* maximumOfNumbersSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* sumOfNumbersSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* meanOfNumbersSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* medianOfNumbersSpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

Keyword* computeVarianceOrStandardDeviation(ControlFrame* frame, Keyword* lastmove, boolean standardDeviationP);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* standardDeviationSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* varianceSpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

void helpDerivePartitionMemberships(LogicObject* self, LogicObject* super, List* tuples);
boolean derivePartitionMembershipsP(LogicObject* self);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* hasPartitionMembershipSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* refutationDisjointSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* emptySpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

boolean emptyTermP(Object* self);
boolean cheapEmptyTermP(LogicObject* self);
boolean expensiveEmptyTermP(LogicObject* self);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Context* contextOfComputation(Object* instance);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

SavedContextProofAdjunct* newSavedContextProofAdjunct();
Object* accessSavedContextProofAdjunctSlotValue(SavedContextProofAdjunct* self, Symbol* slotname, Object* value, boolean setvalueP);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* istSpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

Skolem* getRolesetOf(NamedDescription* relation, Object* instance);
int computeStoredBoundOnRoleset(NamedDescription* relation, Object* instance, Keyword* lowerorupper);
int computeMinimumCardinality(NamedDescription* relation, Object* instance);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* rangeMinCardinalitySpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

int computeMaximumCardinality(NamedDescription* relation, Object* instance);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* rangeMaxCardinalitySpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

boolean testRangeTypeP(NamedDescription* relation, Object* instance, NamedDescription* valuetype);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* rangeTypeSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* reflexiveRelationSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* irreflexiveRelationSpecialist(ControlFrame* frame, Keyword* lastmove);
StringWrapper* objectNameComputation(Object* objectarg);
Object* nameToObjectComputation(StringWrapper* namearg);
IntegerWrapper* arityComputation(Object* descriptionarg);
Keyword* aritySpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* relationHierarchySpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

List* helpProjectNthColumn(int n, List* tuplelist);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* projectColumnSpecialist(ControlFrame* frame, Keyword* lastmove);
void assertSynonymDemon(Proposition* self);
void retractSynonymDemon(Proposition* self);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

Cons* getSynonyms(Object* term);
boolean synonymSurrogateP(Surrogate* name);
void transferSynonyms(Object* oldobject, Object* newobject);

} // end of namespace logic


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

Keyword* differentSpecialist(ControlFrame* frame, Keyword* lastmove);

} // end of namespace pl_kernel_kb


namespace logic {
  using namespace stella;

cpp_function_code lookupNativeSpecialist(char* nativeName);
void registerSpecialistFunction(char* name, cpp_function_code code);
void registerSpecialistFunctionName(char* stellaName, char* nativeName);
void registerSpecialistFunctionNameEvaluatorWrapper(Cons* arguments);
void helpStartupSpecialists1();
void helpStartupSpecialists2();
void helpStartupSpecialists3();
void startupSpecialists();

// Auxiliary global declarations:
extern Surrogate* SGT_SPECIALISTS_LOGIC_COMPUTED_PROCEDURE;
extern Symbol* SYM_SPECIALISTS_LOGIC_PROCEDURE_NAME;
extern Symbol* SYM_SPECIALISTS_LOGIC_PROCEDURE_CODE;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_RELATION_SPECIALIST;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_HANDLES_REVERSE_POLARITY;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_RELATION_CONSTRAINT;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_RELATION_COMPUTATION;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_RELATION_EVALUATOR;
extern Keyword* KWD_SPECIALISTS_FAIL;
extern Keyword* KWD_SPECIALISTS_TERMINAL_FAILURE;
extern Keyword* KWD_SPECIALISTS_FAILURE;
extern Keyword* KWD_SPECIALISTS_TRUE;
extern Keyword* KWD_SPECIALISTS_FINAL_SUCCESS;
extern Keyword* KWD_SPECIALISTS_CONTINUING_SUCCESS;
extern Surrogate* SGT_SPECIALISTS_STELLA_THING;
extern Surrogate* SGT_SPECIALISTS_STELLA_FUNCTION_CODE_WRAPPER;
extern Surrogate* SGT_SPECIALISTS_STELLA_METHOD_CODE_WRAPPER;
extern Surrogate* SGT_SPECIALISTS_LOGIC_SUBSTRING_POSITION_ITERATOR;
extern Symbol* SYM_SPECIALISTS_LOGIC_SUPER_STRING;
extern Symbol* SYM_SPECIALISTS_LOGIC_SUB_STRING;
extern Symbol* SYM_SPECIALISTS_STELLA_START;
extern Symbol* SYM_SPECIALISTS_LOGIC_SUB_LENGTH;
extern Surrogate* SGT_SPECIALISTS_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_SPECIALISTS_LOGIC_SKOLEM;
extern Symbol* SYM_SPECIALISTS_STELLA_ITERATOR;
extern Surrogate* SGT_SPECIALISTS_STELLA_NUMBER_WRAPPER;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_COLLECTIONOF;
extern Keyword* KWD_SPECIALISTS_UP_TRUE;
extern Keyword* KWD_SPECIALISTS_UP_FAIL;
extern Surrogate* SGT_SPECIALISTS_LOGIC_NAMED_DESCRIPTION;
extern Symbol* SYM_SPECIALISTS_STELLA_ISA;
extern Keyword* KWD_SPECIALISTS_MOVE_DOWN;
extern Surrogate* SGT_SPECIALISTS_LOGIC_DESCRIPTION;
extern Symbol* SYM_SPECIALISTS_LOGIC_EXTERNAL_VARIABLES;
extern Surrogate* SGT_SPECIALISTS_STELLA_COLLECTION;
extern Surrogate* SGT_SPECIALISTS_LOGIC_LOGIC_OBJECT;
extern Keyword* KWD_SPECIALISTS_SCAN_COLLECTION;
extern Keyword* KWD_SPECIALISTS_DOWN;
extern Symbol* SYM_SPECIALISTS_STELLA_PREDICATE;
extern Symbol* SYM_SPECIALISTS_STELLA_FUNCTION;
extern Symbol* SYM_SPECIALISTS_STELLA_DUMMY;
extern Keyword* KWD_SPECIALISTS_FULL_SUBQUERY;
extern Symbol* SYM_SPECIALISTS_LOGIC_DESCRIPTION;
extern Keyword* KWD_SPECIALISTS_FUNCTION;
extern Keyword* KWD_SPECIALISTS_PREDICATE;
extern Keyword* KWD_SPECIALISTS_ISA;
extern Keyword* KWD_SPECIALISTS_AND;
extern Symbol* SYM_SPECIALISTS_STELLA_ARGUMENTS;
extern Surrogate* SGT_SPECIALISTS_LOGIC_PROPOSITION;
extern Keyword* KWD_SPECIALISTS_HOW_MANY;
extern Keyword* KWD_SPECIALISTS_INHERIT;
extern Keyword* KWD_SPECIALISTS_ALL;
extern Keyword* KWD_SPECIALISTS_CURRENT;
extern Symbol* SYM_SPECIALISTS_LOGIC_QUERY_SPECIALIST_IO_VARIABLES;
extern Keyword* KWD_SPECIALISTS_MATCH_MODE;
extern Keyword* KWD_SPECIALISTS_GOAL_TREE;
extern Symbol* SYM_SPECIALISTS_LOGIC_JUSTIFICATION;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_CONCEPT_PROTOTYPE;
extern Symbol* SYM_SPECIALISTS_LOGIC_HYPOTHESIZED_INSTANCEp;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_CLOSED;
extern Symbol* SYM_SPECIALISTS_LOGIC_MONOTONICp;
extern Surrogate* SGT_SPECIALISTS_LOGIC_F_CLOSED_TERMp_MEMO_TABLE_000;
extern Symbol* SYM_SPECIALISTS_LOGIC_EQUIVALENT_VALUE;
extern Surrogate* SGT_SPECIALISTS_LOGIC_F_CLOSED_PROPOSITIONp_MEMO_TABLE_000;
extern Keyword* KWD_SPECIALISTS_OR;
extern Keyword* KWD_SPECIALISTS_NOT;
extern Keyword* KWD_SPECIALISTS_FORALL;
extern Keyword* KWD_SPECIALISTS_EXISTS;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_MEMBER_OF;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_TOTAL;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_SINGLE_VALUED;
extern Surrogate* SGT_SPECIALISTS_LOGIC_F_SINGLE_VALUED_TERMp_MEMO_TABLE_000;
extern Keyword* KWD_SPECIALISTS_EQUIVALENT;
extern Symbol* SYM_SPECIALISTS_LOGIC_pSUPER;
extern Symbol* SYM_SPECIALISTS_LOGIC_pMDC;
extern Symbol* SYM_SPECIALISTS_STELLA_AND;
extern Symbol* SYM_SPECIALISTS_LOGIC_MEMBER_OF;
extern Symbol* SYM_SPECIALISTS_LOGIC_MUTUALLY_DISJOINT_COLLECTION;
extern Symbol* SYM_SPECIALISTS_LOGIC_F_HELP_DERIVE_PARTITION_MEMBERSHIPS_QUERY_000;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_MUTUALLY_DISJOINT_COLLECTION;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_PARTITION_MEMBERSHIP;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_DISJOINT;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_HAS_PARTITION_MEMBERSHIP;
extern Keyword* KWD_SPECIALISTS_ASSERT_TRUE;
extern Keyword* KWD_SPECIALISTS_ASSERT_FALSE;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_EMPTY;
extern Surrogate* SGT_SPECIALISTS_LOGIC_SAVED_CONTEXT_PROOF_ADJUNCT;
extern Symbol* SYM_SPECIALISTS_LOGIC_SAVED_CONTEXT;
extern Symbol* SYM_SPECIALISTS_LOGIC_PROOF_ADJUNCT;
extern Surrogate* SGT_SPECIALISTS_STELLA_CONTEXT;
extern Keyword* KWD_SPECIALISTS_IST_INTRODUCTION;
extern Keyword* KWD_SPECIALISTS_TECHNICAL;
extern Keyword* KWD_SPECIALISTS_LAY;
extern Keyword* KWD_SPECIALISTS_PARTIAL;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_THE_ROLESET;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_CARDINALITY;
extern Keyword* KWD_SPECIALISTS_LOWER;
extern Keyword* KWD_SPECIALISTS_UPPER;
extern Surrogate* SGT_SPECIALISTS_STELLA_INTEGER_WRAPPER;
extern Surrogate* SGT_SPECIALISTS_STELLA_SURROGATE;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_DIRECT_SUBRELATION;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_DIRECT_SUPERRELATION;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_SUBRELATION;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_SUPERRELATION;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_PROPER_SUBRELATION;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_PROPER_SUPERRELATION;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_EQUIVALENT_RELATION;
extern Surrogate* SGT_SPECIALISTS_STELLA_CONS;
extern Surrogate* SGT_SPECIALISTS_STELLA_LIST;
extern Surrogate* SGT_SPECIALISTS_PL_KERNEL_KB_SYNONYM;
extern Surrogate* SGT_SPECIALISTS_STELLA_CS_VALUE;
extern Symbol* SYM_SPECIALISTS_LOGIC_STARTUP_SPECIALISTS;
extern Symbol* SYM_SPECIALISTS_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
