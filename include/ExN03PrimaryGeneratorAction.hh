// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: ExN03PrimaryGeneratorAction.hh,v 1.1.10.1 1999/12/07 20:47:29 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef ExN03PrimaryGeneratorAction_h
#define ExN03PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

class G4ParticleGun;
class G4Event;
class ExN03DetectorConstruction;
class ExN03PrimaryGeneratorMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class ExN03PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    ExN03PrimaryGeneratorAction(ExN03DetectorConstruction*);    
   ~ExN03PrimaryGeneratorAction();

  public:
    void GeneratePrimaries(G4Event*);
    void SetRndmFlag(G4String val) { rndmFlag = val;}


  private:
    G4ParticleGun*                particleGun;	  //pointer a to G4 service class
    ExN03DetectorConstruction*    ExN03Detector;  //pointer to the geometry
    
    ExN03PrimaryGeneratorMessenger* gunMessenger; //messenger of this class
    G4String                      rndmFlag;	  //flag for a random impact point       

  private:
  G4int PSFi;
  G4double PSFTotal;
//  G4double PSFProbability[40401];
//  G4int PositionX[40401];
//  G4int PositionY[40401];
  G4double PSFPosition[201][201];
  G4double Nphotons[201][201];

};

#endif


