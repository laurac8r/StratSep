// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1


#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"
#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

class G4Box;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4Material;
class DetectorMessenger;
class PixelSD;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    DetectorConstruction();
   ~DetectorConstruction();

  public:

     void PrintPixelParameters();
     void SetPixelThickness(G4double);
     void SetPixelMaterial(G4String);
     void SetCeramicMaterial(G4String);

     G4VPhysicalVolume* Construct();

     void UpdateGeometry();

  public:

//     void PrintCalorParameters();

     G4double GetWorldSizeX()           {return WorldSizeX;};
     G4double GetWorldSizeY()           {return WorldSizeY;};
     G4double GetWorldSizeZ()           {return WorldSizeZ;};

     G4double GetMatrixThickness()      {return MatrixThickness;};
     G4double GetMatrixSizeY()          {return MatrixSizeY;};
     G4double GetMatrixSizeX()          {return MatrixSizeX;};


     G4double GetPixelThickness()      {return PixelThickness;};
     G4double GetPixelSizeY()          {return PixelSizeY;};
     G4double GetPixelSizeX()          {return PixelSizeX;};


     const G4VPhysicalVolume* GetphysiWorld()  {return physiWorld;};
     const G4VPhysicalVolume* GetphysiMatrix() {return physiMatrix;};


  private:

#include "DetectorParameterDef.hh"


  G4Box*             solidWorld;    //pointer to the solid World
  G4LogicalVolume*   logicWorld;    //pointer to the logical World
  G4VPhysicalVolume* physiWorld;    //pointer to the physical World

  G4Box*             solidMatrix;   //pointer to the solid Matrix
  G4LogicalVolume*   logicMatrix;   //pointer to the logical Matrix
  G4VPhysicalVolume* physiMatrix;   //pointer to the physical Matrix

  G4Box*             solidPixel;    //pointer to the solid Pixel
  G4LogicalVolume*   logicPixel;
  G4VPhysicalVolume* physiPixel;

     G4Material*        PixelMaterial;
     G4Material*        CeramicMaterial;
     G4Material*        defaultMaterial;



  DetectorMessenger* detectorMessenger;  //pointer to the Messenger
  PixelSD* pixelSD;  //pointer to the sensitive detector

  private:

     void DefineMaterials();
  //   void ComputePixelParameters();
     G4VPhysicalVolume* ConstructPixel();
};

#endif
