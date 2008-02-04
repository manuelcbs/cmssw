// -*- C++ -*-
//
// Package:    V0Producer
// Class:      V0Producer
// 
/**\class V0Producer V0Producer.cc MyProducers/V0Producer/src/V0Producer.cc

 Description: <one line class summary>

 Implementation:
     <Notes on implementation>
*/
//
// Original Author:  Brian Drell
//         Created:  Fri May 18 22:57:40 CEST 2007
// $Id: V0Producer.cc,v 1.2 2007/07/09 12:58:52 drell Exp $
//
//


// system include files
#include <memory>

#include "RecoVertex/V0Producer/interface/V0Producer.h"

// Constructor
V0Producer::V0Producer(const edm::ParameterSet& iConfig) :
  theParams(iConfig) {

   // Registering V0 Collections
  //produces<reco::VertexCollection>("Kshort");
  //produces<reco::VertexCollection>("Lambda");
  //produces<reco::VertexCollection>("LambdaBar");

  // Trying this with Candidates instead of the simple reco::Vertex
  produces< std::vector<reco::V0Candidate> >("Kshort");
  produces< std::vector<reco::V0Candidate> >("Lambda");
  produces< std::vector<reco::V0Candidate> >("LambdaBar");

}

// (Empty) Destructor
V0Producer::~V0Producer() {

}


//
// Methods
//

// Producer Method
void V0Producer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup) {
   using namespace edm;

   // Create V0Fitter object which reconstructs the vertices and creates
   //  (and contains) collections of Kshorts, Lambda0s, and Lambda0Bars
   V0Fitter theVees(theParams, iEvent, iSetup);

   // Create auto_ptr for each collection to be stored in the Event
   /*std::auto_ptr<reco::VertexCollection> k0sOut(new
	       reco::VertexCollection( theVees.getKshortCollection() ));
   std::auto_ptr<reco::VertexCollection> L0Out(new
	       reco::VertexCollection( theVees.getLambdaCollection() ));
   std::auto_ptr<reco::VertexCollection> L0BarOut(new
   reco::VertexCollection( theVees.getLambdaBarCollection() ));*/

   std::auto_ptr< std::vector<reco::V0Candidate> > 
     kShortCandidates( new std::vector<reco::V0Candidate>( 
						       theVees.getKshorts()) );
   std::auto_ptr< std::vector<reco::V0Candidate> >
     lambdaCandidates( new std::vector<reco::V0Candidate>(
						       theVees.getLambdas()) );
   std::auto_ptr< std::vector<reco::V0Candidate> >
     lambdaBarCandidates( new std::vector<reco::V0Candidate>(
						    theVees.getLambdaBars()) );

   // Write the collections to the Event
   //iEvent.put( k0sOut, std::string("Kshort") );
   //iEvent.put( L0Out, std::string("Lambda") );
   //iEvent.put( L0BarOut, std::string("LambdaBar") );

   iEvent.put( kShortCandidates, std::string("Kshort") );
   iEvent.put( lambdaCandidates, std::string("Lambda") );
   iEvent.put( lambdaBarCandidates, std::string("LambdaBar") );

}


void V0Producer::beginJob(const edm::EventSetup&) {
}


void V0Producer::endJob() {
}

//define this as a plug-in
#include "FWCore/PluginManager/interface/ModuleDef.h"
DEFINE_SEAL_MODULE();
DEFINE_ANOTHER_FWK_MODULE(V0Producer);
//DEFINE_FWK_MODULE(V0finder);
