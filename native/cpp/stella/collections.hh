//  -*- Mode: C++ -*-

// collections.hh

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


namespace stella {

// Class definitions:
class StellaHashTable : public AbstractHashTable {
public:
  KvCons** theTable;
  int size;
  // If supplied, the initial hash table
  // will be sized to hold at least that many elements.
  int initialSize;
  int freeElements;
  // If true use `equal?' as the
  // equality test and `equal-hash-code' as the hash function, otherwise,
  // use `eql?' and `hash-code' (the default).
  boolean equalTestP;
public:
  virtual AbstractIterator* allocateIterator();
  virtual int equalHashCode();
  virtual boolean objectEqualP(Object* y);
  virtual Cons* consify();
  virtual void clear();
  virtual StellaHashTable* copy();
  virtual boolean nonEmptyP();
  virtual boolean emptyP();
  virtual int length();
  virtual void removeAt(Object* key);
  virtual void insertAt(Object* key, Object* value);
  virtual Object* lookup(Object* key);
  virtual void initializeHashTable();
  virtual Surrogate* primaryType();
};

class StellaHashTableIterator : public DictionaryIterator {
// Iterator class for STELLA-HASH-TABLE's.  The only modifying
// operations allowed during iteration are removal of the current element or
// changing its value.  All other removal or insertion operations might lead
// to corruption or undefined results.
public:
  int size;
  KvCons** bucketTable;
  int bucketIndex;
  KvCons* bucketCursor;
public:
  virtual Object* keySetter(Object* key);
  virtual Object* valueSetter(Object* value);
  virtual boolean nextP();
  virtual Surrogate* primaryType();
};

class KeyValueMap : public Dictionary {
// Full-featured dictionary class that supports `eql?' or
// `equal?' equality tests, O(1) access operations even for large numbers
// of entries by using a hash table, light-weight KV-CONS representation for
// small tables and iteration even if the dictionary is represented by a
// hash table.
public:
  Object* theMap;
  // If true use `equal?' as the
  // equality test (and `equal-hash-code' as the hash function), otherwise,
  // use `eql?' (and `hash-code') (the default).
  boolean equalTestP;
  // If supplied, the initial table
  // will be sized to hold at least that many elements.
  int initialSize;
  int crossoverPoint;
public:
  virtual int equalHashCode();
  virtual boolean objectEqualP(Object* y);
  virtual Cons* consify();
  virtual AbstractIterator* allocateIterator();
  virtual void clear();
  virtual KeyValueMap* copy();
  virtual boolean nonEmptyP();
  virtual boolean emptyP();
  virtual int length();
  virtual void removeAt(Object* key);
  virtual void insertAt(Object* key, Object* value);
  virtual Object* lookup(Object* key);
  virtual Surrogate* primaryType();
};

class HashSet : public KeyValueMap {
// Full-featured set class that supports `eql?' or `equal?'
// equality tests, O(1) insert and `member?' operations & O(N) `intersection'
// etc. operations even for large numbers of entries by using a hash table,
// light-weight KV-CONS representation for small sets and iteration even if the
// set is represented by a hash table.  The only minor drawback right now is that
// this wastes a value slot per entry, since we piggy-back off KEY-VALUE-MAP's,
// however, that wastes at most 25% space.
public:
  virtual int equalHashCode();
  virtual boolean objectEqualP(Object* y);
  virtual HashSet* subtract(HashSet* otherset);
  virtual HashSet* difference(HashSet* otherset);
  virtual HashSet* unioN(HashSet* otherset);
  virtual HashSet* intersection(HashSet* otherset);
  virtual boolean equivalentSetsP(HashSet* otherset);
  virtual boolean subsetP(HashSet* otherset);
  virtual Cons* consify();
  virtual KeyValueMap* copy();
  virtual HashSet* substitute(Object* neW, Object* old);
  virtual Object* pop();
  virtual HashSet* removeIf(cpp_function_code testP);
  virtual AbstractCollection* remove(Object* value);
  virtual void insert(Object* value);
  virtual boolean memberP(Object* object);
  virtual Surrogate* primaryType();
};


// Global declarations:
extern boolean oUSE_STELLA_HASH_TABLESpo;
extern double oSTELLA_HASH_TABLE_AVG_BUCKET_LENGTHo;
extern int oKEY_VALUE_MAP_CROSSOVER_POINTo;

// Function signatures:
boolean stellaCollectionP(Object* self);
Set* set(int values, ...);
Vector* stella::vector(int values, ...);
boolean vectorNextP(AllPurposeIterator* self);
StellaHashTable* newStellaHashTable();
Object* accessStellaHashTableSlotValue(StellaHashTable* self, Symbol* slotname, Object* value, boolean setvalueP);
void initializeStellaHashTable(StellaHashTable* self);
void rehashStellaHashTable(StellaHashTable* self, int newsize);
void stellaHashTableInsertAt(StellaHashTable* self, Object* key, Object* value);
void stellaHashTableRemoveAt(StellaHashTable* self, Object* key);
Object* stellaHashTableLookup(StellaHashTable* self, Object* key);
Object* stellaStringHashTableLookup(StellaHashTable* self, char* key);
StellaHashTableIterator* newStellaHashTableIterator();
Object* accessStellaHashTableIteratorSlotValue(StellaHashTableIterator* self, Symbol* slotname, Object* value, boolean setvalueP);
KeyValueMap* newKeyValueMap();
Object* accessKeyValueMapSlotValue(KeyValueMap* self, Symbol* slotname, Object* value, boolean setvalueP);
HashSet* newHashSet();
HashSet* hashSet(int values, ...);
void helpStartupCollections1();
void helpStartupCollections2();
void startupCollections();

// Auxiliary global declarations:
extern Surrogate* SGT_COLLECTIONS_STELLA_COLLECTION;
extern Surrogate* SGT_COLLECTIONS_STELLA_SET;
extern Symbol* SYM_COLLECTIONS_STELLA_VECTOR;
extern Keyword* KWD_COLLECTIONS_CPP;
extern Keyword* KWD_COLLECTIONS_FUNCTION;
extern Surrogate* SGT_COLLECTIONS_STELLA_VECTOR;
extern Surrogate* SGT_COLLECTIONS_STELLA_STELLA_HASH_TABLE;
extern Symbol* SYM_COLLECTIONS_STELLA_SIZE;
extern Symbol* SYM_COLLECTIONS_STELLA_INITIAL_SIZE;
extern Symbol* SYM_COLLECTIONS_STELLA_FREE_ELEMENTS;
extern Symbol* SYM_COLLECTIONS_STELLA_EQUAL_TESTp;
extern Surrogate* SGT_COLLECTIONS_STELLA_STELLA_HASH_TABLE_ITERATOR;
extern Symbol* SYM_COLLECTIONS_STELLA_BUCKET_INDEX;
extern Symbol* SYM_COLLECTIONS_STELLA_BUCKET_CURSOR;
extern Surrogate* SGT_COLLECTIONS_STELLA_KEY_VALUE_MAP;
extern Symbol* SYM_COLLECTIONS_STELLA_THE_MAP;
extern Symbol* SYM_COLLECTIONS_STELLA_CROSSOVER_POINT;
extern Surrogate* SGT_COLLECTIONS_STELLA_HASH_SET;
extern Symbol* SYM_COLLECTIONS_STELLA_STARTUP_COLLECTIONS;
extern Symbol* SYM_COLLECTIONS_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace stella
