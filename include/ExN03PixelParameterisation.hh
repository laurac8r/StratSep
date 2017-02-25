
#ifndef ExN03PixelParameterisation_H
#define ExN03PixelParameterisation_H 1

#include "globals.hh"
#include "G4VPVParameterisation.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"
class G4VPhysicalVolume;
class G4Box;

// Dummy declarations to get rid of warnings ...
class G4Trd;
class G4Trap;
class G4Cons;
class G4Sphere;
class G4Torus;
class G4Para;
class G4Hype;
class G4Tubs;


class ExN03PixelParameterisation : public G4VPVParameterisation
{ 
  public:
    ExN03PixelParameterisation();
    ~ExN03PixelParameterisation();
    void ComputeTransformation
    (const G4int NbOfPixelsInX,G4VPhysicalVolume *physVol) const;
    void ComputeDimensions
    (G4Box & pixel, const G4int NbOfPixelsInX,
      const G4VPhysicalVolume * physVol) const;

  private:  // Dummy declarations to get rid of warnings ...
                                                                                                                             
    void ComputeDimensions (G4Trd&,const G4int,const G4VPhysicalVolume*) const {}
    void ComputeDimensions (G4Trap&,const G4int,const G4VPhysicalVolume*) const {}
    void ComputeDimensions (G4Cons&,const G4int,const G4VPhysicalVolume*) const {}
    void ComputeDimensions (G4Sphere&,const G4int,const G4VPhysicalVolume*) const {}
    void ComputeDimensions (G4Torus&,const G4int,const G4VPhysicalVolume*) const {}
    void ComputeDimensions (G4Para&,const G4int,const G4VPhysicalVolume*) const {}
    void ComputeDimensions (G4Hype&,const G4int,const G4VPhysicalVolume*) const {}
    void ComputeDimensions (G4Tubs&,const G4int,const G4VPhysicalVolume*) const {}
    void ComputeDimensions (G4Orb&,const G4int,const G4VPhysicalVolume*) const {}
    void ComputeDimensions (G4Polycone&,const G4int,const G4VPhysicalVolume*) const {}
    void ComputeDimensions (G4Polyhedra&,const G4int,const G4VPhysicalVolume*) const {}


  private:

#include "ExN03DetectorParameterDef.hh"

};

#endif


