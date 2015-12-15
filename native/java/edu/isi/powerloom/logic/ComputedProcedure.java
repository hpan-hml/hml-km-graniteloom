//  -*- Mode: Java -*-
//
// ComputedProcedure.java

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

/** Each instance denotes a programming language 
 * function that computes some procedure.  The slot 'procedure-name'
 * provides the name of the procedure.  The slot 'procedure-code'
 * points directly to the procedure itself.  Both slots are optional;
 * if neither is supplied, the procedure will be invoked by extracting
 * its name from the name of the instance.
 * @author Stella Java Translator
 */
public class ComputedProcedure extends Thing {
    public Symbol procedureName;
    public java.lang.reflect.Method procedureCode;

  public static ComputedProcedure newComputedProcedure() {
    { ComputedProcedure self = null;

      self = new ComputedProcedure();
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.surrogateValueInverse = null;
      self.procedureCode = null;
      self.procedureName = null;
      return (self);
    }
  }

  public static Stella_Object accessComputedProcedureSlotValue(ComputedProcedure self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_PROCEDURE_NAME) {
      if (setvalueP) {
        self.procedureName = ((Symbol)(value));
      }
      else {
        value = self.procedureName;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_PROCEDURE_CODE) {
      if (setvalueP) {
        self.procedureCode = ((FunctionCodeWrapper)(value)).wrapperValue;
      }
      else {
        value = FunctionCodeWrapper.wrapFunctionCode(self.procedureCode);
      }
    }
    else {
      if (setvalueP) {
        KeyValueList.setDynamicSlotValue(self.dynamicSlots, slotname, value, null);
      }
      else {
        value = self.dynamicSlots.lookup(slotname);
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { ComputedProcedure self = this;

      return (Logic.SGT_LOGIC_COMPUTED_PROCEDURE);
    }
  }

}

