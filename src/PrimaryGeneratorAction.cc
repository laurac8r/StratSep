//
// PrimaryGenerationAction.cc 	CIPHER 3
//


#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorMessenger.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "Randomize.hh"
#include "fstream"
#include "stdlib.h"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction(
                             DetectorConstruction* DC)
:Detector(DC),rndmFlag("off")
{

  G4int n_particle = 1;
  particleGun  = new G4ParticleGun(n_particle);

  //create a messenger for this class
  gunMessenger = new PrimaryGeneratorMessenger(this);

  // default particle kinematic
  G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
  G4String particleName;
  G4ParticleDefinition* particle
                    = particleTable->FindParticle(particleName="gamma");
  particleGun->SetParticleDefinition(particle);

}



PrimaryGeneratorAction::~PrimaryGeneratorAction()
{

  delete particleGun;
  delete gunMessenger;
}



void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{  //this function is called at the begining of event

  //
  // Energy distributions
  //

  	// Crab distribution
//	G4double minenergy = 100.*keV, maxenergy = 600.*keV;
//	G4double primaryenergy = (minenergy*maxenergy)/(((1-G4UniformRand())*maxenergy)+minenergy);

	//Monochromatic beam
//        G4double primaryenergy=200*keV;

	//Particle gun
  //	particleGun->SetParticleEnergy(primaryenergy);
	//  G4cout << "Energia inicial" << primaryenergy << G4endl;



  //
  // Position
  //
  G4double z0 = -0.5*(Detector->GetWorldSizeZ());
  G4double x0 = 1.0*mm, y0 = 1.0*mm;
   if (rndmFlag == "on")
     {
	x0 = (((x0)*G4UniformRand())-(x0/2));
	y0 = (((y0)*G4UniformRand())-(y0/2));
     }
  particleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));
  particleGun->GeneratePrimaryVertex(anEvent);

 G4cout << "X Position: " << x0 << G4endl;
 G4cout << "Y Position: " << y0 << G4endl;

}
