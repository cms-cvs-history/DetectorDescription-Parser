#ifndef DDL_PolyGenerator_H
#define DDL_PolyGenerator_H

#include "DetectorDescription/DDParser/interface/DDLSolid.h"

#include <string>

/// DDLPolyGenerator processes DDL XML Polycone and DDL XML Polyhedra elements.
/** @class DDLPolyGenerator
 * @author Michael Case
 *
 *  DDLPolyGenerator.h  -  description
 *  -------------------
 *  begin: Mon Aug 5 2002
 *  email: case@ucdhep.ucdavis.edu
 *
 *  The PolyGenerator element uses RZPoint elements.  The DDLRZPoint
 *  can return the r and z vectors with the points needed to form the
 *  polycone.  The RZPoint "accumulator" is also used by the Polyhedra
 *  and Polycone elements, and could be used anywhere a pair of vectors
 *  of r and z values are needed.
 *
 */

class DDLPolyGenerator : public DDLSolid
{
 public:

  /// Constructor
  DDLPolyGenerator();

  /// Destructor
  ~DDLPolyGenerator();

  void processElement (const std::string& name, const std::string& nmspace); 

  void preProcessElement (const std::string& name, const std::string& nmspace); 

};

#endif
