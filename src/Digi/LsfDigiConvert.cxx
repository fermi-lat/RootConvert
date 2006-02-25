//#include <LdfEvent/LsfGemTime.h>
//#include <LdfEvent/LsfTimeTone.h>
//#include <LdfEvent/LsfTime.h>
//#include <LdfEvent/LsfRunInfo.h>
//#include <LdfEvent/LsfDatagramInfo.h>
//#include <LdfEvent/LsfGemScalers.h>
//#include <LdfEvent/LsfConfiguration.h>
#include <LdfEvent/LsfMetaEvent.h>

#include <digiRootData/LsfGemTime.h>
#include <digiRootData/LsfTimeTone.h>
#include <digiRootData/LsfTime.h>
#include <digiRootData/LsfRunInfo.h>
#include <digiRootData/LsfDatagramInfo.h>
#include <digiRootData/LsfGemScalers.h>
#include <digiRootData/LsfConfiguration.h>
#include <digiRootData/LsfMetaEvent.h>

#include <RootConvert/Utilities/Toolkit.h>

namespace RootPersistence {

  void convert( const lsfData::GemTime& tdsObj, GemTime& rootObj) {
    rootObj.initialize(tdsObj.hacks(),tdsObj.ticks());
  }; 
  void convert( const GemTime& rootObj, lsfData::GemTime& tdsObj) {    
    tdsObj.set(rootObj.hacks(),rootObj.ticks());
  };
  
  void convert( const lsfData::TimeTone& tdsObj, TimeTone& rootObj) {
    GemTime rootHack;
    convert(tdsObj.timeHack(),rootHack);
    rootObj.initialize(tdsObj.incomplete(),tdsObj.timeSecs(),tdsObj.flywheeling(),tdsObj.flags(),rootHack);
  };
  void convert( const TimeTone& rootObj, lsfData::TimeTone& tdsObj) {
    lsfData::GemTime tdsHack;
    convert(rootObj.timeHack(),tdsHack);
    tdsObj.set(rootObj.incomplete(),rootObj.timeSecs(),rootObj.flywheeling(),rootObj.flags(),tdsHack);
  };
  
  void convert( const lsfData::Time& tdsObj, Time& rootObj) {
    TimeTone current;
    TimeTone previous;
    GemTime hack;
    convert(tdsObj.current(),current);
    convert(tdsObj.previous(),previous);
    convert(tdsObj.timeHack(),hack);
    rootObj.initialize(current,previous,hack,tdsObj.timeTicks());    
  };
  void convert( const Time& rootObj, lsfData::Time& tdsObj) {
    lsfData::TimeTone current;
    lsfData::TimeTone previous;
    lsfData::GemTime hack;
    convert(rootObj.current(),current);
    convert(rootObj.previous(),previous);
    convert(rootObj.timeHack(),hack);
    tdsObj.set(current,previous,hack,rootObj.timeTicks());
  };

  void convert( const lsfData::RunInfo& tdsObj, RunInfo& rootObj) {
    rootObj.initialize(tdsObj.platform(),tdsObj.dataOrigin(),tdsObj.id(),tdsObj.startTime());
  };
  void convert( const RunInfo& rootObj, lsfData::RunInfo& tdsObj) {
    tdsObj.set(rootObj.platform(),rootObj.dataOrigin(),rootObj.id(),rootObj.startTime());
  };
   
  void convert( const lsfData::DatagramInfo& tdsObj, DatagramInfo& rootObj) {
    rootObj.initialize(tdsObj.openAction(),tdsObj.openReason(),
		       tdsObj.crate(),tdsObj.mode(),
		       tdsObj.closeAction(),tdsObj.closeReason(),
		       tdsObj.datagrams(),tdsObj.modeChanges());    
  };
  void convert( const DatagramInfo& rootObj, lsfData::DatagramInfo& tdsObj) {
    tdsObj.set(rootObj.openAction(),rootObj.openReason(),
	       rootObj.crate(),rootObj.mode(),
	       rootObj.closeAction(),rootObj.closeReason(),
	       rootObj.datagrams(),rootObj.modeChanges());
  };

  void convert( const lsfData::GemScalers& tdsObj, GemScalers& rootObj) {
    rootObj.initialize(tdsObj.elapsed(),tdsObj.livetime(),
		       tdsObj.prescaled(),tdsObj.discarded(),
		       tdsObj.sequence(),tdsObj.deadzone());
  };
  void convert( const GemScalers& rootObj, lsfData::GemScalers& tdsObj) {
    tdsObj.set(rootObj.elapsed(),rootObj.livetime(),
	       rootObj.prescaled(),rootObj.discarded(),
	       rootObj.sequence(),rootObj.deadzone());
  };

  // this handles the polymorphism of Configuration
  void convert( const lsfData::Configuration* tdsPtr, Configuration*& rootPtr ) {
    rootPtr = 0;
    if ( tdsPtr == 0 ) return;
    const lsfData::LpaConfiguration* asLpaTds(0);
    switch ( tdsPtr->type() ) {
    case enums::Lsf::LPA:
      asLpaTds = tdsPtr->castToLpaConfig();
      rootPtr = new LpaConfiguration(asLpaTds->hardwareKey(),asLpaTds->softwareKey());
      break;
    default:
      return;
    }
  }
  void convert( const Configuration* rootPtr, lsfData::Configuration*& tdsPtr) {
    tdsPtr = 0;
    if ( rootPtr == 0 ) return;
    const LpaConfiguration* asLpaRoot(0);
    switch ( rootPtr->runType() ) {
    case enums::Lsf::LPA:
      asLpaRoot = rootPtr->castToLpaConfig();
      tdsPtr = new lsfData::LpaConfiguration(asLpaRoot->hardwareKey(),asLpaRoot->softwareKey());
      break;
    default:
      return;
    }
  }

  void convert( const LsfEvent::MetaEvent& tdsObj, MetaEvent& rootObj) {
    RunInfo run;
    DatagramInfo datagram;
    GemScalers scalers;
    Time time;
    Configuration* configuration(0);
    convert(tdsObj.run(),run);
    convert(tdsObj.datagram(),datagram);
    convert(tdsObj.scalers(),scalers);
    convert(tdsObj.time(),time);
    convert(tdsObj.configuration(),configuration);
    rootObj.initialize(run,datagram,scalers,time,*configuration);
    delete configuration;
  };
  void convert( const MetaEvent& rootObj, LsfEvent::MetaEvent& tdsObj) {
    lsfData::RunInfo run;
    lsfData::DatagramInfo datagram;
    lsfData::GemScalers scalers;
    lsfData::Time time;
    lsfData::Configuration* configuration(0);
    convert(rootObj.run(),run);
    convert(rootObj.datagram(),datagram);
    convert(rootObj.scalers(),scalers);
    convert(rootObj.time(),time);
    convert(rootObj.configuration(),configuration);
    tdsObj.set(run,datagram,scalers,time,*configuration);
    delete configuration;
  };

}
