// logic-system.hh

#ifndef _STELLA_LOGIC_SYSTEM_HH
#define _STELLA_LOGIC_SYSTEM_HH

// Required systems:
#include "stella/stella-system.hh"

// System-wide forward declarations:
namespace logic {
  using namespace stella;

class LogicException;
class PropositionError;
class ParsingError;
class Clash;
class FailException;
class QueryThreadLimitViolation;
class SequenceIndex;
class NonPagingIndex;
class PagingIndex;
class ObjectStore;
class SequenceIndexIterator;
class PagingIndexIterator;
class NamedDescription;
class Proposition;
class LogicObject;
class BacklinksIndex;
class BacklinksMixin;
class Description;
class LogicThing;
class PatternVariable;
class Skolem;
class ForwardChainingIndex;
class TruthValue;
class PartialSupport;
class PropositionNeuralNetwork;
class QuantityLogicWrapper;
class IntegerLogicWrapper;
class FloatLogicWrapper;
class StringLogicWrapper;
class ObjectAlreadyExistsException;
class CheckTypesRecord;
class InferenceLevel;
class NormalInferenceLevel;
class BacktrackingInferenceLevel;
class SubsumptionInferenceLevel;
class ShallowInferenceLevel;
class AssertionInferenceLevel;
class RefutationInferenceLevel;
class QueryIterator;
class QuerySolution;
class QuerySolutionTable;
class ControlFrame;
class PatternRecord;
class ParallelThread;
class ControlFramePriorityQueue;
class GoalCache;
class PartialMatchFrame;
class GoalRecord;
class ProofAdjunct;
class Justification;
class ParallelControlFrame;
class BooleanVectorIndexNode;
class NnPartialMatch;
class DescriptionExtensionIterator;
class QuerySolutionTableIterator;
class AtomicGoalCache;
class IncrementalPartialMatch;
class TrainingExample;
class DecisionTree;
class twoDArray;
class MultiDimensionalArray;
class FloatVector;
class twoDFloatArray;
class AtomicGoalCacheIterator;
class ConditionalAntecedentProofAdjunct;
class ClusteredConjunctionProofAdjunct;
class PrimitiveStrategy;
class ForwardGoalRecord;
class ForwardJustification;
class ExplainException;
class ExplainNoQueryException;
class ExplainNoSolutionException;
class ExplainNoMoreSolutionsException;
class ExplainNotEnabledException;
class ExplainNoSuchLabelException;
class ExplainQueryTrueException;
class ExplanationInfo;
class WhynotPartialMatch;
class WhynotDeepPartialMatch;
class WhynotProofClass;
class AlternativeBindingsSet;
class TermGenerationException;
class ComputedProcedure;
class SubstringPositionIterator;
class SavedContextProofAdjunct;
class AbstractPropositionsIterator;
class TruePropositionsIterator;
class SpecializingPropositionsIterator;
class TransitiveClosureIterator;
class SupportedClosureIterator;
class DirectlyLinkedObjectsIterator;
class ClashingPropositionsIterator;
class MarkerTable;
class ClassificationCache;
class ClassificationSession;

} // end of namespace logic


// System components:
#include "logic/logic-macros.hh"
#include "logic/sequence-indices.hh"
#include "logic/kif-in.hh"
#include "logic/propositions.hh"
#include "logic/backlinks.hh"
#include "logic/propagate.hh"
#include "logic/inference-caches.hh"
#include "logic/descriptions.hh"
#include "logic/normalize.hh"
#include "logic/rules.hh"
#include "logic/query.hh"
#include "logic/partial-match.hh"
#include "logic/machine-learning.hh"
#include "logic/rule-induction.hh"
#include "logic/neural-network.hh"
#include "logic/case-based.hh"
#include "logic/goal-caches.hh"
#include "logic/strategies.hh"
#include "logic/justifications.hh"
#include "logic/explanations.hh"
#include "logic/whynot.hh"
#include "logic/kif-out.hh"
#include "logic/print.hh"
#include "logic/generate.hh"
#include "logic/specialists.hh"
#include "logic/specialize.hh"
#include "logic/optimize.hh"
#include "logic/classify.hh"
#include "logic/logic-in.hh"
#include "logic/pl-kernel-kb.hh"
#include "logic/arithmetic.hh"
#include "logic/frame-support.hh"
#include "logic/loom-support.hh"
#include "logic/loom-to-kif.hh"
#include "logic/api-support.hh"
#include "logic/pli.hh"
#include "logic/powerloom.hh"
#include "logic/tools.hh"
#include "logic/startup-system.hh"

#endif
