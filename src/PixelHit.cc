// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: CalorHit.cc,v 1.1.10.1 1999/12/07 20:47:29 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
//


#include "PixelHit.hh"
#include "G4ios.hh"
#include "G4VVisManager.hh"
#include "G4VHit.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4LogicalVolume.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

G4Allocator<PixelHit> PixelHitAllocator;


PixelHit::PixelHit()
{pLogV=NULL;}

PixelHit::PixelHit(G4LogicalVolume* logVol,G4double y,G4double z)
:pLogV(logVol),YPixelID(y),ZPixelID(z)
{;}

PixelHit::~PixelHit()
{;}


PixelHit::PixelHit(const PixelHit& right)
  : G4VHit()
{
  YPixelID = right.YPixelID;
  ZPixelID = right.ZPixelID;
  EdepPix = right.EdepPix;
  TrackLengthPix = right.TrackLengthPix;

  Pos = right.Pos;
  pLogV = right.pLogV;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

const PixelHit& PixelHit::operator=(const PixelHit& right)
{
  YPixelID = right.YPixelID;
  ZPixelID = right.ZPixelID;
  EdepPix = right.EdepPix;
  TrackLengthPix = right.TrackLengthPix;

  Pos = right.Pos;
  return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

int PixelHit::operator==(const PixelHit& right) const
{
  return ((YPixelID==right.YPixelID)&&(ZPixelID==right.ZPixelID));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void PixelHit::Draw()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void PixelHit::Print()
{;}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
