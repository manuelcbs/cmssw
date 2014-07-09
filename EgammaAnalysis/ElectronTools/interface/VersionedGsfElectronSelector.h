#ifndef EgammaAnalysis_ElectronTools_interface_VersionedGsfElectronSelector_h
#define EgammaAnalysis_ElectronTools_interface_VersionedGsfElectronSelector_h

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/BeamSpot/interface/BeamSpot.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "PhysicsTools/SelectorUtils/interface/VersionedSelector.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include <iostream>

class VersionedGsfElectronSelector : public VersionedSelector<reco::GsfElectron> {
 public:
 VersionedGsfElectronSelector() : 
  VersionedSelector<reco::GsfElectron>(),
    initialized_(false) {}
  
 VersionedGsfElectronSelector( const edm::ParameterSet& parameters );
  
 void initialize( const edm::ParameterSet& parameters );

  // Allow for multiple definitions of the cuts.
 bool operator()(const reco::GsfElectron&,pat::strbitset&); 
 using VersionedSelector<reco::GsfElectron>::operator();
 
 private:
 bool initialized_; 
};

#endif
