#ifndef RootConvert_LsfDigiConvert_H
#define RootConvert_LsfDigiConvert_H 1

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

namespace RootPersistence {

  /// Fill persitent verison of GemTime
  void convert( const lsfData::GemTime&, GemTime& ) ;
  /// Fill transient verison of GemTime
  void convert( const GemTime&, lsfData::GemTime& ) ;

  /// Fill persitent verison of TimeTone
  void convert( const lsfData::TimeTone&, TimeTone& ) ;
  /// Fill transient verison of TimeTone
  void convert( const TimeTone&, lsfData::TimeTone& ) ;

  /// Fill persitent verison of Time
  void convert( const lsfData::Time&, Time& ) ;
  /// Fill transient verison of Time
  void convert( const Time&, lsfData::Time& ) ;

  /// Fill persitent verison of RunInfo
  void convert( const lsfData::RunInfo&, RunInfo& ) ;
  /// Fill transient verison of RunInfo
  void convert( const RunInfo&, lsfData::RunInfo& ) ;
  
  /// Fill persitent verison of DatagramInfo
  void convert( const lsfData::DatagramInfo&, DatagramInfo& ) ;
  /// Fill transient verison of DatagramInfo
  void convert( const DatagramInfo&, lsfData::DatagramInfo& ) ;

  /// Fill persitent verison of GemScalers
  void convert( const lsfData::GemScalers&, GemScalers& ) ;
  /// Fill transient verison of GemScalers
  void convert( const GemScalers&, lsfData::GemScalers& ) ;

  /// Fill persitent verison of Configuration
  /// this handles the polymorphism of Configuration
  void convert( const lsfData::Configuration*, Configuration*& ) ;
  /// Fill transient verison of Configuration
  void convert( const Configuration*, lsfData::Configuration*& ) ;

  /// Fill persitent verison of MetaEvent
  void convert( const LsfEvent::MetaEvent&, MetaEvent& ) ;
  /// Fill transient verison of MetaEvent
  void convert( const MetaEvent&, LsfEvent::MetaEvent& ) ;

}

#endif












