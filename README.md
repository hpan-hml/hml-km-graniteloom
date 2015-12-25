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


### STELLA System Definitions - Notes

Representation in Common Lisp:

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
* `STELLA::*SYSTEMDEFINITIONS*` [`STELLA::LIST`]
* `STELLA::*FILE-LOAD-PATH*`
* `STELLA::STRING-WRAPPER`
* `STELLA::WRAPPER-VALUE-TYPE`
* `STELLA::SURROGATE`
* `"pl:native;lisp;*;startup-system.lisp"` [directory]
* Source files: `systems.slisp`, `systems.lisp`

Representation in C++:

_Refer to native C++ source files_, `systems.cc`

Representation in Java:

_Refer to native Java source files_, `systems.java`


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

_To Do: ASDF integration with XSD Shared MIME Info_

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
