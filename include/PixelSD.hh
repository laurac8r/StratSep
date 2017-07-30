//
//	PixelSD.hh		CIPHER 3
//


#ifndef PixelSD_h
#define PixelSD_h 1

#include "G4VSensitiveDetector.hh"
#include "globals.hh"
#include "RunAction.hh"
#include "PixelHit.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

#include "G4VProcess.hh"  //to get the process name
class G4ProcessVector;

class DetectorConstruction;
class G4HCofThisEvent;
class G4Step;
class G4TouchableHistory;


class PixelSD : public G4VSensitiveDetector
{
  public:

      PixelSD(G4String name,RunAction*);
     ~PixelSD();

      void Initialize(G4HCofThisEvent*HCE);
      G4bool ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist);
      void EndOfEvent(G4HCofThisEvent*HCE);
      void clear();
      void DrawAll();
      void PrintAll();

  private:

      RunAction*            Run;
      G4VProcess* 		 findprocess;
      PixelHitsCollection*  PixCollection;
      G4int PixelID[5][5];
      G4int evtorder;
      G4int recordY;
      G4int recordZ;
      G4double copyIDinY;
      G4double copyIDinZ;
      G4double edep;
      G4String process;
      const int NbOfPixelsInY;
      const int NbOfPixelsInZ;

      G4VProcess* fCurrentProcess;
};

#endif
