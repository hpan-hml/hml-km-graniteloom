// -*- Mode: Java -*-

/*--------------------------- BEGIN LICENSE BLOCK ---------------------------+
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
| Portions created by the Initial Developer are Copyright (C) 1996-2010      |
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
+---------------------------- END LICENSE BLOCK ----------------------------*/

// Version: PrintStringStream.java,v 1.8 2010/02/10 22:15:39 hans Exp

// Native Print String Stream
//
// Combines the java.io.PrintStream functionality with 
//   the java.io.ByteArrayOutputStream functionality.
//
// The only method implemented in this file is the "toString" method and
//   the constructor.
//
// Strategy:  Use new to create a new PrintStream with a ByteArrayOutputStream
//    as an encapsulated stream.  The toString method will then access the
//    embedded ByteArrayOutputStream in order to do the string conversion.
//


package edu.isi.stella.javalib;

import java.io.*;

public class PrintStringStream extends java.io.PrintStream {

  public PrintStringStream () {
    // Create a new PrintStream containing a new ByteArrayOutputStream.
    super (new ByteArrayOutputStream());
      }

  public String toString() {
    // Return the String that the encapsulated ByteArrayOutputStream contains.
    return (this.out.toString());
  }

  public byte[] toByteArray() {
    // Return the bare byte array the encapsulated ByteArrayOutputStream contains.
    return ((ByteArrayOutputStream)this.out).toByteArray();
  }
}
