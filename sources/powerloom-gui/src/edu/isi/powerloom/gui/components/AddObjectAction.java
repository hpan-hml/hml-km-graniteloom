// -*- Mode: Java -*-

/*---------------------------- BEGIN LICENSE BLOCK ---------------------------+
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
 | Portions created by the Initial Developer are Copyright (C) 2002-2010      |
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
 +----------------------------- END LICENSE BLOCK ---------------------------*/


// Version: AddObjectAction.java,v 1.7 2010/02/04 05:16:36 hans Exp

package edu.isi.powerloom.gui.components;

import javax.swing.*;
import java.awt.event.*;
import java.util.*;

import edu.isi.powerloom.gui.xmlobject.*;
import edu.isi.powerloom.gui.serverinterface.*;
import static edu.isi.powerloom.gui.common.Utils.*;

/**
 * Action to add new objects.
 *
 * @author <a href=mailto:eric@metrotech-consulting.com>Eric Melz</a>
 * @since Tue Apr 09 13:52:07 2002
 */
public class AddObjectAction extends PowerloomAction {
    public AddObjectAction() {
	super();
	putValue(Action.NAME, "Add Object");
    }
    public AddObjectAction(PowerloomApp app) {
	super();
	parentApp = app;
	updateActionName();
    }
    public void actionPerformed(ActionEvent e) {
	PLObject theObject = parentApp.getMostRecentlyTouchedObject();
	debugPrintln(3, "editing object: " + theObject + ", class = " + theObject.getClass());
	if (theObject instanceof PLModule) {
	    addModule((PLModule)theObject);
	}
	if (theObject instanceof PLConcept) {
	    addConcept((PLConcept)theObject);
	}
    }
    public void addConcept(PLConcept theObject) {
	// open editor...
	debugPrintln(3, "editing " + theObject);
	ConceptFrame2 conceptFrame = new ConceptFrame2();
	parentApp.getConceptFrames().add(conceptFrame);
	try {
	    PLSurrogate superSurrogate = KnowledgeManager.getInstance().findOrCreateSurrogate(PLConcept.class, theObject.getID());
	    List surrogateList = new ArrayList();
	    surrogateList.add(superSurrogate);
	    PLSurrogateContainer supers = new PLSurrogateContainer(surrogateList);
	    conceptFrame.setupNewConcept("NEW-CONCEPT", supers);
	    conceptFrame.displayFrame();
	} catch (Exception e) {
	    PowerloomApp.getInstance().handleException(e);
	} // end of try-catch
    }
    public void addModule(PLModule theObject) {
		// open editor...
		try {
		    debugPrintln(3, "editing " + theObject);	
		    ModuleFrame moduleFrame = new ModuleFrame();
		    PLSurrogate superSurrogate = KnowledgeManager.getInstance().findOrCreateSurrogate(PLModule.class, theObject.getID());
		    List surrogateList = new ArrayList();
		    surrogateList.add(superSurrogate);
	 	    PLSurrogateContainer supers = new PLSurrogateContainer(surrogateList);
		    moduleFrame.setupNewModule("NEW-MODULE", supers);
		    moduleFrame.displayFrame();
		} catch (Exception e) {
		    PowerloomApp.getInstance().handleException(e);
		}
    }
    public void updateActionName() {
	if (parentApp.getMostRecentlyTouchedObject() != null) {
	    PLObject plObject = parentApp.getMostRecentlyTouchedObject();
	    if (plObject instanceof PLModule) {
		putValue(Action.NAME, "Add submodule of " + parentApp.getMostRecentlyTouchedObject());		
	    } else if (plObject instanceof PLConcept) {
		putValue(Action.NAME, "Add subconcept of " + parentApp.getMostRecentlyTouchedObject());		
	    } else {
		putValue(Action.NAME, "Add " + parentApp.getMostRecentlyTouchedObject());
	    } 
	} else {
	    putValue(Action.NAME, "Add Object");
	} 
    }
}

