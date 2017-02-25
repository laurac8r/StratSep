// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: ExN03EventAction.hh,v 1.3.8.1 1999/12/07 20:47:28 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#ifndef ExN03EventAction_h
#define ExN03EventAction_h 1

#include "G4UserEventAction.hh"
#include "ExN03RunAction.hh"
#include "globals.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

class ExN03EventActionMessenger;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class ExN03EventAction : public G4UserEventAction
{
  public:
    ExN03EventAction();
//    ExN03EventAction(ExN03RunAction*);
    virtual ~ExN03EventAction();

  private:
//    ExN03RunAction*           ExN03Run;
    G4int                       pixelCollID;
    G4String                    drawFlag;
    ExN03EventActionMessenger*  eventMessenger;
    G4int                       printModulo;


  public:
    virtual void   BeginOfEventAction(const G4Event*);
    virtual void   EndOfEventAction(const G4Event*);
//    virtual void   EndOfEventAction(const G4Event*,G4TouchableHistory *);
    
    void SetDrawFlag   (G4String val)  {drawFlag = val;};
    void SetPrintModulo(G4int    val)  {printModulo = val;};
    
};

#endif

    
