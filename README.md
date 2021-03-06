GraniteLoom Project
===================


# Overview

GraniteLoom is a fork of [PowerLoom][pl]. [PowerLoom][pl] is a
free/open source software (FOSS) project developed originally at the
[Information Sciences Institute][isi] (ISI) of the
[University of Southern California][usc] (USC). The GraniteLoom fork
is developed independent of the original [PowerLoom][pl] project.

# Components

[PowerLoom][PL] is distribued with the following components

* [STELLA Programming Language][stella]
* ...

# Goals in GraniteLoom Fork M1

* Add ASDF System Definitions - STELLA, PowerLoom

* Ensure Portability of Common Lisp code generated from STELLA Source Forms

* Provide API for defining STELLA Knowledge Bases with ASDF System Definitions

* Develop Documentation (DITA XML format)

* Prototype of software component architecture model in STELLA KIF

Later goals may include:

* Define a distributed object service model for application of STELLA
  in a context of CORBA Object Services

    * Proof of Concept: Definition of a logical inference model for
      programmed reflection about software component architectures
    
* Define a normative transform algorithm for RDF, RDFS, OWL  transform
  to STELLA KIF


# Documentation

**Local files:**

* `sources/stella/README` - STELLA Overview
* `sources/stella/doc/`
    * `sources/stella/doc/manual.pdf`
* `sources/logic/README` - PowerLoom Overview
* `sources/logic/doc/PowerLoom-Overview-Slides.ppt`
* `sources/powerloom/doc/`
    * `sources/powerloom/doc/manual.pdf`
* `native/cpp/stella/cpp-lib/gc/doc/`
* `sources/powerloom-gui/src/overview.html`
* `htdocs/ontosaurus/help/`
* `sources/powerloom-server/plsoap/README`
* `sources/webtools/tomcat/README`


## Additional Documentary Information

### STELLA Programming Language

[STELLA][stella] is a _Strongly Typed, Lisp-like LAnguage_ comprising
a _typed_ dialect of the  [Knowledge Interchange Format][kif3]
([KIF][kif3]) [version 3.0][kif3].

[STELLA][stella] source code may be transformed into into C++,
Java, and Common Lisp source code.

#### Type Definitions - Stella and C++, Java, Common Lisp

...

#### Value Wrappers in Stella

...

### Knowledge Interchange Format (KIF)

An overview about the Knowledge Interchange Format (KIF) is
[available via Wikipedia][kifpedia].

See also: [Knowledge Interchange Format][stankif] at the
[Stanford Logic Group][stanlog]

#### Additional KIF Implementations

* [kifparser][kifparser] from the [Center for Design Research][cdr] at 
  the [Stanford School of Engineering][staneng]


### STELLA System Definitions

#### STELLA::DEFINE-SYSTEM [Function]

Syntax:
> STELLA::DEFINE-SYSTEM NAME ARGS

Known ARGS keywords:
* `:CARDINAL-MODULE`
* `:DIRECTORY`
* `:REQUIRED-SYSTEMS`
* `:CPP-ONLY-FILES`
* `:JAVA-ONLY-FILES`
* `:LISP-ONLY-FILES`
* `:PREPROCESSED-FILES`
* `:FILES`
* `:DEVELOPMENT-SETTINGS`
* `:PRODUCTION-SETTINGS`


See also:
* `STELLA::MAKE-SYSTEM` [Function]
* `STELLA::*SYSTEMDEFINITIONS*` [STELLA::LIST]

#### STELLA::MAKE-SYSTEM [Function]

e.g.

> (STELLA::MAKE-SYSTEM "logic")

#### STELLA::GET-SYSTEM-DEFINITION

e.g.

> (STELLA::GET-SYSTEM-DEFINITION "powerloom")


#### STELLA::*SYSTEMDEFINITIONS* [STELLA::LIST]

Translating the value to a CL:LIST

> (STELLA::%THE-CONS-LIST STELLA::*SYSTEMDEFINITIONS*)


### Relation of STELLA System Definitions and STELLA Module Definitions

Symbolic expression: `System Definition =[*][Cardinal Module][1]=> Module`

See also:

* `STELLA::%CARDINAL-MODULE` [Generic Function]
* `STELLA::GET-CARDINAL-MODULE` [Function]
* `STELLA::STANDARD-OBJECT` [Standard Class]

e.g.

> `(STELLA::%CARDINAL-MODULE (car (STELLA::%THE-CONS-LIST STELLA::*SYSTEMDEFINITIONS*)))`


#### STELLA System Definitions

* `STELLA::DEFSYSTEM`
* `STELLA::%DEFSYSTEM`
* `STELLA::DEFINE-SYSTEM`
* `STELLA::MAKE-SYSTEM`
    * Applied in upstream `./load-powerlooom.lisp`
    * May result in files being compiled, when evaluated
* `STELLA::%MAKE-SYSTEM`
    * e.g. `(STELLA::%MAKE-SYSTEM "powerloom" STELLA::NIL)`
* `STELLA::GET-SYSTEM-DEFINITION`
    * e.g. `(STELLA::GET-SYSTEM-DEFINITION "powerloom")`
* `STELLA::*FILE-LOAD-PATH*`
* `"pl:native;lisp;*;startup-system.lisp"` [directory]
* Source files: `systems.slisp`, `systems.lisp`


Representation in Common Lisp:

_Refer to Lisp source files_, `systems.slisp`, `systems.lisp`

Representation in C++:

_Refer to native C++ source files_, `systems.cc`

Representation in Java:

_Refer to native Java source files_, `systems.java`

### STELLA Modules

* `STELLA::GET-STELLA-MODULE <NAME>`- 'name' being a conventional SIMPLE-STRING

### Value Wrapping in STELLA

_Notes_ - Lisp representation

* `STELLA::STRING-WRAPPER`
* `STELLA::WRAPPER-VALUE-TYPE`
* `STELLA::SURROGATE` as an effective subclass of `STELLA::CONTEXT-SENSITIVE-OBJECT`
* `STELLA::WRAP-LITERAL`

_Wrapper_ classses

* `STELLA::WRAPPER` and subclasses

Literal Value Wrapping - _Unwrap_ Functions

* `STELLA::UNWRAP-BOOLEAN`
* `STELLA::INLINE-UNWRAP-BOOLEAN` (?)
* `STELLA::UNWRAP-CHARACTER`
* `STELLA::UNWRAP-FLOAT`
* `STELLA::UNWRAP-INTEGER`
* `STELLA::UNWRAP-LONG-INTEGER`
* `STELLA::UNWRAP-MUTABLE-STRING`
* `STELLA::UNWRAP-STRING`

Code Wrapping

* `STELLA::ACCESS-FUNCTION-CODE-WRAPPER-SLOT-VALUE`
* `STELLA::ACCESS-METHOD-CODE-WRAPPER-SLOT-VALUE`
* `STELLA::UNWRAP-FUNCTION-CODE`
* `STELLA::UNWRAP-METHOD-CODE`
* `STELLA::UNWRAP-WRAPPED-TYPE`


Stella Collection Types

* `STELLA::ABSTRACT-COLLECTION`
* `STELLA::COLLECTION`
* `STELLA::SEQUENCE`
* `STELLA::VECTOR` ...
* `STELLA::RECYCLE-LIST` ...
* `STELLA::LIST` ...
* `STELLA::%THE-CONS-LIST`

### STELLA Offset Tables

...?

### STELLA C++ Generator

> :USE-CPP-GARBAGE-COLLECTION in STELLA::*DEFAULT-STELLA-FEATURES*

...

### STELLA Java Generator

> STELLA::*CURRENT-JAVA-OUTPUT-CLASS*

...

### STELLA Lisp Generator

...

### STELLA XML Parser

...

### Misc

Transcript of an interactive session with STELLA in SBCL

> (in-package #:CL-USER)
>
>
> (stella::in-module "/STELLA") ;; n.b case sensitive module name
>
>
> (describe stella::*module*)
>
> |MDL|/STELLA
>  [standard-object]
>
>Slots with :INSTANCE allocation:
>  SURROGATE-VALUE-INVERSE    = /PL-KERNEL-KB/@STELLA
>  DYNAMIC-SLOTS              = |kv|(</LOGIC/DEPENDENT-PROPOSITIONS-INDEX,|i|/LOGIC/@BACKLINKS-INDEX> ..
>  CHILD-CONTEXTS             = |l|()
>  BASE-MODULE                = |MDL|/STELLA
>  ALL-SUPER-CONTEXTS         = NIL
>  CONTEXT-NUMBER             = 2
>  PARENT-MODULES             = |l|()
>  DOCUMENTATION              = " "
>  NICKNAMES                  = :NULL_VALUE
>  USES                       = |l|()
>  USED-BY                    = |l|(|MDL|/SDBC..
>  REQUIRES                   = :NULL_VALUE
>  CASE-SENSITIVE?            = NIL
>  MODULE-FULL-NAME           = "/STELLA"
>  MODULE-NAME                = "STELLA"
>  MODULE-STRINGIFIED-SOURCE  = " "
>  STRINGIFIED-OPTIONS        = ""
>  CARDINAL-MODULE            = |MDL|/STELLA
>  SYMBOL-OFFSET-TABLE        = |i|@STRING-TO-INTEGER-HASH-TABLE
>  SURROGATE-OFFSET-TABLE     = |i|@STRING-TO-INTEGER-HASH-TABLE
>  STRICT-INFERENCE-CACHE     = :NULL_VALUE
>  DEFAULT-INFERENCE-CACHE    = :NULL_VALUE
>  PROTOTYPE-INFERENCE-CACHE  = :NULL_VALUE
>
>
> (type-of (stella::%dynamic-slots stella::*module*))
> => STELLA::KEY-VALUE-LIST
>
> (stella::%the-kv-list (stella::%dynamic-slots stella::*module*))
> => </LOGIC/DEPENDENT-PROPOSITIONS-INDEX,|i|/LOGIC/@BACKLINKS-INDEX>
>
> (defparameter *kv* (stella::%the-kv-list (stella::%dynamic-slots stella::*module*)))
>
> (stella::%key *kv*)
> => /LOGIC/DEPENDENT-PROPOSITIONS-INDEX
>
> (type-of (stella::%key *kv*))
> => STELLA::SYMBOL
>
> (stella::%symbol-value-and-plist (stella::%key *kv*))
> => NIL
>
> (stella::%value *kv*))
> => |i|/LOGIC/@BACKLINKS-INDEX
>
> (type-of (stella::%value *kv*))
> => STELLA::BACKLINKS-INDEX
>
> (type-of *kv*)
> => STELLA::KV-CONS
>
> (maphash #'(lambda (k v) (format t "~%~S ~S" k v))
>                   (stella::%the-hash-table (stella::%symbol-offset-table stella::*module*)))
>
> (stella::module-lisp-package stella::*module*)
> => "STELLA"

> (let (buff)
>           (do-symbols (v (find-package "STELLA") buff)
>              (when (boundp v) (unless (symbolp v) (push v buff )))))
> => NIL ;; all bound symbols in the module's package are bound to a symbol

> STELLA::*SYSTEMDEFINITIONS*

> STELLA::*BUILT-IN-MODULE-NAMES*

> STELLA::*STARTUP-TIME-PHASES*

> STELLA::*FUNCTION-LOOKUP-TABLE*

> STELLA::*ALL-MEASURES*
> STELLA::*DATE-TIME-PATTERNS*
> STELLA::*MONTH-ABBREVIATION-VECTOR* 
> STELLA::*PRIME-NUMBERS*

> STELLA::*AVAILABLE-POWERLOOM-FEATURES*
> STELLA::*CURRENT-POWERLOOM-FEATURES*
> STELLA::*AVAILABLE-STELLA-FEATURES*
> STELLA::*CURRENT-STELLA-FEATURES*
> STELLA::*DEFAULT-STELLA-FEATURES*

> STELLA::*ALL-MEMOIZATION-TABLES*

> STELLA::*CL-OPERATOR-TABLE*
> STELLA::*KIF-SENTENCE-OPERATORS*
> STELLA::*TYPE-PREDICATE-TABLE*

> STELLA::*XML-BASE-ENTITY-TABLE*

> STELLA::*CLASS-TAXONOMY-GRAPH*

> STELLA::*REGISTERED-COMMAND-LINE-OPTIONS*

> STELLA::*DEMO-FILES*

> STELLA::*SPECIAL-STRINGS*

> STELLA::/PL-KERNEL-KB/*PL-KERNEL-KB-DEFINITIONS*

See also: _Canonical Names_ in STELLA [Concept]

### Knowledge Representation - A Bibliography


* Marchetti, Andrea, F Ronzano, M Tesconi, and M
  Minutoli. “Formalizing Knowledge by Ontologies: OWL and KIF.”
  Relatório Apresentado L’Istituto Di Informatica E Telematica
  (IIT). Consiglio Nazionale Delle Ricerche
  (CNR). Italia, 2008.
  {[URL](https://www.iit.cnr.it/sites/default/files/TechnicalReport_IIT_FormalizingKnowledgeByOntologies.pdf)}.
  
* Niles, Ian, and Adam Pease. “Towards a Standard Upper Ontology.” In
  Proceedings of the International Conference on Formal Ontology in
  Information Systems-Volume 2001,
  2–9. ACM, 2001.
  {[URL](http://www.adampease.org/professional/FOIS.pdf)}.
  
* Alavi, Maryam, and Dorothy Leidner. “Review: Knowledge Management
  and Knowledge Management Systems: Conceptual Foundations and
  Research Issues.” MIS Quarterly 25, no. June (2001):
  107–36. doi:10.2307/3250961.
  {[URL](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.472.8815)}.



### GraniteLoom Integeration with ASDF

#### Dependencies

* `stella.asd` - **Stella System Definition** (GraniteLoom) [ASDF::System]

    * **Dependencies:** Each of [USocket][usocket], [Bordeaux Threads][bthread]

    * **Features and Parameters Affecting System Definition**

        * Feature `:STELLA-STRUCT` - newly defined in GraniteLoom,
          this feature provides an alternative to appilcations of the
          variable `CL-USER::*LOAD-CL-STRUCT-STELLA*?`. If the feature
          is defined, the `stella-system-structs` Common Lisp source
          file will be compiled and loaded with the containing
          `stella.asd` system definition

        * Variable `CL-USER::*LOAD-CL-STRUCT-STELLA*?` - in
          `stella.asd`, the value of this variable is set to `T` when
          the feature `:STELLA-STRUCT` is defined. 

        * Variable `CL-USER::*STELLA-VERBOSE?*` - this variable's
          value will affect the printing of messages during compiling
          and loading of system components, and may affect the
          printing of some informative messages

        * `CL:*READ-DEFAULT-FLOAT-FORMAT*` - refer to file
          `native/lisp/stella/cl-lib/cl-setup.lisp` (TO DO -
          PORTABILITY, NO USERSPACE SIDE EFECTS)

    * **Side Effects - Behaviors During Evaluation of System Definition**
        * Common Lisp Package `STELLA-SYSTEM` defined
        * Common Lisp Package `STELLA` defined
        * Macro `STELLA::WITH-REDEFINITION-WARNINGS-SUPPRESSED`
          defined (implementation-specific)
        * Macro `STELLA::WITH-UNDEFINED-FUNCTION-WARNINGS-SUPPRESSED`
          defined (implementation-specific)
        * Fxtensions for ASDF in STELLA, PowerLoom defined


    * **Side Effects - Behaviors Before `ASDF:COMPILE-OP` of System Definition**
        * Set `CL-USER::*LOAD-CL-STRUCT-STELLA*?` value to `T` when
          the feature `:STELLA-STRUCT` is defined

    * **Side Effects - Behaviors After `ASDF:LOAD-OP` of System Definition**
        * Function Call Evaluated: `STELLA::STARTUP-STELLA-SYSTEM`
        * Function Call Evaluated `STELLA::STARTUP-STELLA-TO-CL`
        * Informative message printed to `CL:*STANDARD-OUTPUT*` when
        `CL-USER::*STELLA-VERBORE?*`
        * `#+ALLEGRO` `(tpl:setq-default cl-user::*redefinition-warnings* nil)`

    * **Side Effects - Behaviors during Normal Upstream System Evaluation**
    
        * Logical pathname host `PL:` defined
    
            * In GraniteLoom, this logical pathname is defined with
              pathname translations as deriving from ASDF
              source/output component pathname translations
              
            * See alo: `CL-USER::*STELLA-NATIVE-DIRECTORY*`
      

* `powerloom.asd` (TO DO) - Powerloom System Definition (GraniteLoom) [ASDF::System]

    * Dependencies: `stella.asd`

* KB System Definitions (GraniteLoom): TBD

* Integration with C, C++ Toolchains for ASDF: TBD

* Integration wtih Java Toolchains for ASDF: TBD

* Integration with Makefile Implementations (GNU Make, bmake, pmake,
  fmake) for ASDF: TBD

#### GraniteLoom System Definitions

GraniteLoom develops a set of _system definitions_ in a format
compatible with the popular [ASDF][asdf] _system definition_
framework.

The respective `<component>.asd` files may be applied as, each, an
alternative to the original/upstream `<component>-loader.lisp` file

#### GraniteLoom Extensions to the ASDF Object Model

[ASDF][asdf] is effectively extended in the GraniteLoom System
Definitions.

_Ed. Note: The following classes are deined essentially as prototypes
for later design work, in GraniteLoom_

* `STELLA-SOURCE-FILE`
* `JAVA-SOURCE-FILE`
* `C++-HEADER-FILE`
* `C-HEADER-FILE`
* `MAKEFILE`

_To Do: ASDF integration with XDG Shared MIME Info_

* `STELLA-LISP-FILE` - Special Handling in GraniteLoom System Definitions

    * Derive a lexical binding for the value of each of
      `CL:*COMPILE-VERBOSE*` and `CL:*LOAD-VERBOSE*` both from  the
      value of the variable, `CL-USER:*STELLA-VERBOSE?*` , as
      respectively during  each of an `ASDF:LOAD-OP` or
      `ASDF:COMPILE-OP` applied onto the respective `STELLA-LISP-FILE`
      component
      
    * Compile/Load the component in a context in which the value of
      `*STELLA-SYSTEM*` is lexically bound to the _component system_
      referenced by the respective `STELLA-LISP-FILE` component
      
    * Compile/Load the component in a context in which the value of
      `*SOURCE-TRUENAME-SYSTEM*` is lexically bound to the _truename_
      _namestring_ of the _source file_ of the respective
      `STELLA-LISP-FILE` component

    * Compile/Load the component in a context _with redefinition
      warnings surpressed_ and _with undefined function warnings
      surpressed_ for _supported implementations_ - refer to source
      code, for more detail


# Licensing

Quoting the [Powerloom Download Page][pldl] (December 2015)

> Since 2005, PowerLoom® is available free-of-charge under a triple
> disjunctive open-source licensing scheme that allows you to pick the
> Mozilla Public License v. 1.1 (MPL), the GNU General Public License
> v. 2.0 (GPL) or the the GNU Lesser Public License v. 2.1 (LGPL) to
> fit your needs. This scheme is similar to what's used for the
> Mozilla web browser and should give people maximum flexibility to
> use PowerLoom even for commercial development while still retaining
> the advantages of open-source licensing.

Such a license is retained, throughout the works contributed in the
GraniteLoom fork of [PowerLoom][PL]

[pl]: http://www.isi.edu/isd/LOOM/PowerLoom/
[usc]: http://www.usc.edu/
[isi]: http://www.isi.edu/
[stella]: http://www.isi.edu/isd/LOOM/Stella/index.html
[kif3]: http://logic.stanford.edu/kif/Hypertext/kif-manual.html
[kifpedia]: https://en.wikipedia.org/wiki/Knowledge_Interchange_Format
[kifparser]: http://www.ksl.stanford.edu/knowledge-sharing/lib/kifparser/
[stankif]: http://logic.stanford.edu/kif/
[stanlog]: http://logic.stanford.edu/
[cdr]: https://me.stanford.edu/research/labs-and-centers/center-design-research
[staneng]: http://engineering.stanford.edu/
[pldl]: http://www.isi.edu/isd/LOOM/PowerLoom/download.html
[asdf]: https://common-lisp.net/project/asdf/
[usocket]: https://github.com/usocket/usocket
[bthread]: https://gitlab.common-lisp.net/bordeaux-threads/bordeaux-threads
