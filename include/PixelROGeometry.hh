#ifndef PixelROGeometry_h
#define PixelROGeometry_h 1

#include "G4VReadOutGeometry.hh"
#include "DetectorConstruction.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

class PixelROGeometry : public G4VReadOutGeometry
{
public:
  PixelROGeometry();
  PixelROGeometry(G4String);
  ~PixelROGeometry();

private:
  G4VPhysicalVolume* Build();

#include "DetectorParameterDef.hh"

//  G4double           PixelSizeY;
//  G4double           PixelSizeZ;
//  G4double           PixelThickness;

//  G4double           LinlayerSizeY;
//  G4double           LinlayerSizeZ;
//  G4double           LinlayerThickness;

//  G4double           MatrixSizeY;
//  G4double           MatrixSizeZ;
//  G4double           MatrixThickness;

//  G4double           WorldSizeY;
//  G4double           WorldSizeZ;
//  G4double           WorldSizeX;

//  G4int              NbOfPixelsInY;
//  G4int              NbOfPixelsInZ;

  G4Box*             solidROWorld;    //pointer to the solid World
  G4LogicalVolume*   logicROWorld;    //pointer to the logical World
  G4VPhysicalVolume* physiROWorld;    //pointer to the physical World

  G4Box*             solidROMatrix;    //pointer to the solid Matrix
  G4LogicalVolume*   logicROMatrix;
  G4VPhysicalVolume* physiROMatrix;

  G4Box*             solidROLinlayer;    //pointer to the solid Linlayer
  G4LogicalVolume*   logicROLinlayer;
  G4VPhysicalVolume* physiROLinlayer;

  G4Box*             solidROPixel;    //pointer to the solid Pixel
  G4LogicalVolume*   logicROPixel;
  G4VPhysicalVolume* physiROPixel;

};

#endif
