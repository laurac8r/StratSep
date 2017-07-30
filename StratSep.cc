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

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"

#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "Randomize.hh"

int main(int argc,char** argv) {

  // Choose the random engine.
  // CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
  G4Random::setTheEngine(new CLHEP::RanecuEngine);

  // Initiate the multithreaded run manager if Geant4 is run in multithreaded
  //  mode. Otherwise, initiate the regular run manager.
  #ifdef G4MULTITHREADED

    G4MTRunManager* runManager = new G4MTRunManager;
    //runManager->SetNumberOfThreads(2);

  #else

    G4RunManager* runManager = new G4RunManager;

  #endif

  // Instantiate the geometry.
  DetectorConstruction* detector = new DetectorConstruction;
  runManager->SetUserInitialization(detector);

  // Instantiate the physics list.
  runManager->SetUserInitialization(new PhysicsList);

  // Set the action initialization.
  runManager->SetUserInitialization(new ActionInitialization(detector));

  // Set visualization and user interface
  #ifdef G4VIS_USE

    // Visualization manager
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();

  #endif

  // // set user action classes
  // runManager->SetUserAction(new PrimaryGeneratorAction(detector));
  // runManager->SetUserAction(new RunAction);
  // runManager->SetUserAction(new EventAction);
  // runManager->SetUserAction(new SteppingAction);

  // Initialize Geant4 kernel.
  runManager->Initialize();

  // Open an UI session: It will stay open until the user types "exit" or
  //  simply uses a keyboard interrupt.
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

  #ifdef G4UI_USE

    // Run the default macro file if no macro has been specified as an argument
    //  to the executable. The executable is set to use an UI and visualization
    //  is turned on.
    //
    //  aka., run in interactive mode if it was used
    if(argc == 1)
    {

        // Create a new UI executive object to start the simulation session if the
        //  executable has been run in interactive mode.
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);

      #ifdef G4VIS_USE

        // Run the visualization macro.
        UImanager->ApplyCommand("/control/execute init.mac");

      #endif

        // Start the simulation session.
        ui->SessionStart();

        // Delete the UI executive object after the session is over.
        delete ui;

    }

    // Run the executable with the specified macro provided as an argument to the
    //   executable if one or more arguments have been provided by the user.
    //
    //  aka., run in batch mode
    else
    {
      G4String command = "/control/execute ";
      G4String fileName = argv[1];
      UImanager->ApplyCommand(command+fileName);
    }

  #endif

  // Terminate the visualization if it was used.
  #ifdef G4VIS_USE

    delete visManager;

  #endif

  // Terminate the simulation.
  delete runManager;

  // Exit the main function with no errors.
  return 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
