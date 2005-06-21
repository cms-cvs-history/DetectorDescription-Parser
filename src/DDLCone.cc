/***************************************************************************
                          DDLCone.cc  -  description
                             -------------------
    begin                : Mon Oct 29 2001
    email                : case@ucdhep.ucdavis.edu
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *           DDDParser sub-component of DDD                                *
 *                                                                         *
 ***************************************************************************/

namespace std{} using namespace std;

// -------------------------------------------------------------------------
// Includes
// -------------------------------------------------------------------------
#include "DetectorDescription/DDParser/interface/DDLCone.h"
#include "DetectorDescription/DDParser/interface/DDLElementRegistry.h"

// DDCore dependencies
#include "DetectorDescription/DDCore/interface/DDName.h"
#include "DetectorDescription/DDCore/interface/DDSolid.h"
#include "DetectorDescription/DDBase/interface/DDdebug.h"

#include "DetectorDescription/DDExprAlgo/interface/ExprEvalSingleton.h"

//#include <strstream>
#include <string>

// Default constructor.
DDLCone::DDLCone()
{
}

// Default destructor
DDLCone::~DDLCone()
{
}

// Upon encountering the end of the Cone element, call DDCore.
void DDLCone::processElement (const string& type, const string& nmspace)
{  
  DCOUT_V('P', "DDLCone::processElement started");
  ExprEvalInterface & ev = ExprEvalSingleton::instance();
  DDXMLAttribute atts = getAttributeSet();
  try {
    DDSolid ddcone = DDSolidFactory::cons(getDDName(nmspace)
			  , ev.eval(nmspace, atts.find("dz")->second)
			  , ev.eval(nmspace, atts.find("rMin1")->second)
			  , ev.eval(nmspace, atts.find("rMax1")->second)
			  , ev.eval(nmspace, atts.find("rMin2")->second)
			  , ev.eval(nmspace, atts.find("rMax2")->second)
			  , ev.eval(nmspace, atts.find("startPhi")->second)
			  , ev.eval(nmspace, atts.find("deltaPhi")->second));
  } catch (DDException & e) {
    string msg = e.what();
    msg += "\nDDLCone call to DDSolidFactory failed.\n";
    throwError(msg);
  }

  DDLSolid::setReference(nmspace);

  DCOUT_V('P', "DDLCone::processElement completed");

}
