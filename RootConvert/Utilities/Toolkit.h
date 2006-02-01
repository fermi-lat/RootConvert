
#ifndef RootConvert_Toolkit_H
#define RootConvert_Toolkit_H 1

#include <idents/VolumeIdentifier.h>
#include <commonRootData/idents/VolumeIdentifier.h>
#include <geometry/Point.h>
#include <geometry/Vector.h>
#include <CLHEP/Geometry/Point3D.h>
#include <CLHEP/Vector/LorentzVector.h>
#include "TVector.h"
#include "TLorentzVector.h"
#include <string>

// Hack for CLHEP 1.9.2.2
#ifndef HepPoint3D
typedef HepGeom::Point3D<double> HepPoint3D;
#endif

namespace RootPersistence {

idents::VolumeIdentifier convert( const VolumeIdentifier & ) ;
VolumeIdentifier convert( const idents::VolumeIdentifier & ) ;
CLHEP::HepLorentzVector convert( const TLorentzVector & ) ;
TLorentzVector convert( const CLHEP::HepLorentzVector & ) ;
HepPoint3D convert( const TVector3 & ) ;
TVector3 convert( const HepPoint3D & ) ;
Point convertPoint( const TVector3 & ) ;
TVector3 convertPoint( const Point & ) ;
Vector convertVector( const TVector3 & ) ;
TVector3 convertVector( const Vector & ) ;

}

#endif

