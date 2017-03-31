// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: exampleN03.cc,v 1.7.8.1 1999/12/07 20:47:28 gunter Exp $
// GEANT4 tag $Name: geant4-01-00 $
//
// 
// --------------------------------------------------------------
//      GEANT 4 - exampleN02 
//
//      For information related to this code contact:
//      CERN, IT Division, ASD Group
// --------------------------------------------------------------
// Comments
//
// 
// --------------------------------------------------------------

#ifdef G4MULTITHREADED
#include "G4MTRunManager.hh"
#else
#include "G4RunManager.hh"
#endif

#include "G4UImanager.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif

#include "ExN03DetectorConstruction.hh"
#include "ExN03PhysicsList.hh"
#include "ExN03PrimaryGeneratorAction.hh"
#include "ExN03RunAction.hh"
#include "ExN03EventAction.hh"
#include "ExN03SteppingAction.hh"
#include "Randomize.hh"

int main(int argc,char** argv) {

  // choose the Random engine
  CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
   
  // Construct the default run manager
#ifdef G4MULTITHREADED
  G4MTRunManager* runManager = new G4MTRunManager;
  //runManager->SetNumberOfThreads(2); 
#else
  G4RunManager* runManager = new G4RunManager;
#endif

  // set mandatory initialization classes
  ExN03DetectorConstruction* detector = new ExN03DetectorConstruction;
  runManager->SetUserInitialization(detector);
  runManager->SetUserInitialization(new ExN03PhysicsList);
  
  // Set visualization and user interface
#ifdef G4VIS_USE
  // Visualization manager
  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();
#endif
    
  // set user action classes
  runManager->SetUserAction(new ExN03PrimaryGeneratorAction(detector));
  runManager->SetUserAction(new ExN03RunAction);
  runManager->SetUserAction(new ExN03EventAction);
  runManager->SetUserAction(new ExN03SteppingAction);
 
  //Initialize G4 kernel
  runManager->Initialize();

  // Get the pointer to the UI manager
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  // Define UI session for interactive mode.
  if(argc == 1)
    {
#ifdef G4UI_USE
      G4UIExecutive* ui = new G4UIExecutive(argc, argv);
#ifdef G4VIS_USE
      UImanager->ApplyCommand("/control/execute prerunN03.mac");     
#endif
      ui->SessionStart();
      delete ui;
#endif
    }
  // Batch mode
  else
    { 
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);
    }
  

//   if (argc!=1)   // batch mode
//     {
//       G4String command = "/control/execute ";
//       G4String fileName = argv[1];
//       UImanager->ApplyCommand(command+fileName);
//     }
//   else // interactive mode
//     {
// #ifdef G4UI_USE
//       G4UIExecutive* ui = new G4UIExecutive(argc, argv);
//       if (ui->IsGUI())
//   {
//     /* prerunN03.mac is loaded by default */
//     UImanager->ApplyCommand("/control/execute prerunN03.mac");
//     ui->SessionStart();
//   }
//       delete ui;
// #endif

/*  // get the pointer to the User Interface manager 
  G4UImanager* UI = G4UImanager::GetUIpointer();

  if (session)   // Define UI session for interactive mode.
    {
      // G4UIterminal is a (dumb) terminal.
      UI->ApplyCommand("/control/execute prerunN03.mac");    
      session->SessionStart();
      delete session;
    }
  else           // Batch mode
    { 
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UI->ApplyCommand(command+fileName);
    }*/

  // job termination
#ifdef G4VIS_USE
  delete visManager;
#endif
  delete runManager;

  return 0;
}

