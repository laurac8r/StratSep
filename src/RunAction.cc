//
//			CIPHER
// RunAction.cc
//

#include "RunAction.hh"

#include "G4Run.hh"
#include "G4UImanager.hh"
#include "G4UIsession.hh"
#include "G4strstreambuf.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"
#include "G4VVisManager.hh"
#include "G4strstreambuf.hh"
#include "G4ios.hh"

#include "iomanip"
#include <assert.h>

#include "sstream"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

RunAction::RunAction()
:NbOfPixelsInX(32),NbOfPixelsInY(32)
{
}

RunAction::~RunAction()
{}



void RunAction::BeginOfRunAction(const G4Run* aRun)
{

  G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;

  if (G4VVisManager::GetConcreteInstance())
    {
      G4UImanager* UI = G4UImanager::GetUIpointer();
      UI->ApplyCommand("/vis/scene/notifyHandlers");
    }
}



void RunAction::EndOfRunAction(const G4Run*)
{

  if (G4VVisManager::GetConcreteInstance()) {
     G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/update");
  }
}
