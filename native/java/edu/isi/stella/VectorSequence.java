//  -*- Mode: Java -*-
//
// VectorSequence.java

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

public abstract class VectorSequence extends Vector {
    public int sequenceLength;

  public int length() {
    { VectorSequence self = this;

      return (self.sequenceLength);
    }
  }

  /** Remove <code>value</code> from the sequence <code>self</code>, and left shift
   * the values after it to close the gap.
   * @param value
   * @return AbstractCollection
   */
  public AbstractCollection remove(Stella_Object value) {
    { VectorSequence self = this;

      { edu.isi.stella.Stella_Object[] array = self.theArray;
        int firstshiftoffset = -1;
        int lastshiftoffset = self.sequenceLength - 1;

        { int i = Stella.NULL_INTEGER;
          int iter000 = 0;
          int upperBound000 = lastshiftoffset;
          boolean unboundedP000 = upperBound000 == Stella.NULL_INTEGER;

          loop000 : for (;unboundedP000 ||
                    (iter000 <= upperBound000); iter000 = iter000 + 1) {
            i = iter000;
            if (Stella_Object.eqlP(array[i], value)) {
              firstshiftoffset = i + 1;
              break loop000;
            }
          }
        }
        if (firstshiftoffset == -1) {
          return (self);
        }
        if (firstshiftoffset <= lastshiftoffset) {
          { int j = Stella.NULL_INTEGER;
            int iter001 = firstshiftoffset;
            int upperBound001 = lastshiftoffset;
            boolean unboundedP001 = upperBound001 == Stella.NULL_INTEGER;

            for (;unboundedP001 ||
                      (iter001 <= upperBound001); iter001 = iter001 + 1) {
              j = iter001;
              array[(j - 1)] = (array[j]);
            }
          }
        }
        array[lastshiftoffset] = null;
        self.sequenceLength = lastshiftoffset;
        return (self);
      }
    }
  }

  /** Append <code>value</code> to the END of the sequence <code>self</code>.  
   * Resize the array if necessary.
   * @param value
   */
  public void insert(Stella_Object value) {
    { VectorSequence self = this;

      { int oldlength = self.sequenceLength;

        if (oldlength == self.arraySize) {
          Vector.resizeVector(self, self.arraySize + self.resizeIncrement());
        }
        (self.theArray)[oldlength] = value;
        self.sequenceLength = oldlength + 1;
      }
    }
  }

  public static Stella_Object accessVectorSequenceSlotValue(VectorSequence self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Stella.SYM_STELLA_RESIZE_INCREMENT) {
      value = IntegerWrapper.wrapInteger(self.resizeIncrement());
    }
    else if (slotname == Stella.SYM_STELLA_SEQUENCE_LENGTH) {
      if (setvalueP) {
        self.sequenceLength = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = IntegerWrapper.wrapInteger(self.sequenceLength);
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

  public int resizeIncrement() {
    { VectorSequence self = this;

      return (Stella.$HARDWIRED_RESIZE_INCREMENT_ON_VECTOR_SEQUENCE$);
    }
  }

}

