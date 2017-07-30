//
// Monolithic PhysicsList.hh
//

#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4UnitsTable.hh"
#include "G4ParticleTable.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

class PhysicsList: public G4VUserPhysicsList
{
  public:
    PhysicsList();
   ~PhysicsList();

  protected:
    // Construct particle and physics
    virtual void ConstructParticle();
    virtual void ConstructProcess();

    virtual void SetCuts();

  public:
    // Set/Get cut values
    void      SetCutForGamma(G4double);
    void      SetCutForElectron(G4double);
    void      SetCutForProton(G4double);
    G4double  GetCutForGamma() const;
    G4double  GetCutForElectron() const;
    G4double  GetCutForProton() const;

  protected:
    // these methods Construct particles
    void ConstructBosons();
    void ConstructLeptons();
    void ConstructBaryons();


  protected:
  // these methods Construct physics processes and register them
    void ConstructGeneral();
    void ConstructEM();

  private:
    G4ParticleTable* theParticleTable;
    G4ParticleTable::G4PTblDicIterator* aParticleIterator;

    G4double cutForGamma;
    G4double cutForElectron;
    G4double cutForProton;
    G4double currentDefaultCut;
};

#endif
