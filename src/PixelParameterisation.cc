
#include "PixelParameterisation.hh"

#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4Box.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

PixelParameterisation::PixelParameterisation()
{

#include "DetectorParameterDef.icc"

}

PixelParameterisation::~PixelParameterisation()
{;}

void PixelParameterisation::ComputeTransformation
(const G4int NbOfPixelsInX,G4VPhysicalVolume *physVol) const
{
  G4double Xposition = ((NbOfPixelsInX*PixelSizeX)-(MatrixSizeX/2))+(PixelSizeX/2);

  G4ThreeVector origin ((Xposition-Xposition),0.0,0.0);

//  G4cout << " X-> " << Xposition << " CpN " << NbOfPixelsInX << endl;
  physVol->SetTranslation(origin);
}


void PixelParameterisation::ComputeDimensions
(G4Box & pixel, const G4int NbOfPixelsInX,
 const G4VPhysicalVolume* ) const
{
  pixel.SetXHalfLength((PixelSizeX/2)-NbOfPixelsInX+NbOfPixelsInX);
  pixel.SetYHalfLength(PixelSizeY/2);
  pixel.SetZHalfLength(PixelThickness/2);
}
