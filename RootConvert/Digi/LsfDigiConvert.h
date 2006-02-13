#ifndef RootConvert_LsfDigiConvert_H
#define RootConvert_LsfDigiConvert_H 1

#include <LdfEvent/LsfGemTime.h>
#include <LdfEvent/LsfTimeTone.h>
#include <LdfEvent/LsfTime.h>
#include <LdfEvent/LsfRunInfo.h>
#include <LdfEvent/LsfDatagramInfo.h>
#include <LdfEvent/LsfGemScalers.h>
#include <LdfEvent/LsfConfiguration.h>
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
  void convert( const LsfEvent::GemTime&, GemTime& ) ;
  /// Fill transient verison of GemTime
  void convert( const GemTime&, LsfEvent::GemTime& ) ;

  /// Fill persitent verison of TimeTone
  void convert( const LsfEvent::TimeTone&, TimeTone& ) ;
  /// Fill transient verison of TimeTone
  void convert( const TimeTone&, LsfEvent::TimeTone& ) ;

  /// Fill persitent verison of Time
  void convert( const LsfEvent::Time&, Time& ) ;
  /// Fill transient verison of Time
  void convert( const Time&, LsfEvent::Time& ) ;

  /// Fill persitent verison of RunInfo
  void convert( const LsfEvent::RunInfo&, RunInfo& ) ;
  /// Fill transient verison of RunInfo
  void convert( const RunInfo&, LsfEvent::RunInfo& ) ;
  
  /// Fill persitent verison of DatagramInfo
  void convert( const LsfEvent::DatagramInfo&, DatagramInfo& ) ;
  /// Fill transient verison of DatagramInfo
  void convert( const DatagramInfo&, LsfEvent::DatagramInfo& ) ;

  /// Fill persitent verison of GemScalers
  void convert( const LsfEvent::GemScalers&, GemScalers& ) ;
  /// Fill transient verison of GemScalers
  void convert( const GemScalers&, LsfEvent::GemScalers& ) ;

  /// Fill persitent verison of Configuration
  /// this handles the polymorphism of Configuration
  void convert( const LsfEvent::Configuration*, Configuration*& ) ;
  /// Fill transient verison of Configuration
  void convert( const Configuration*, LsfEvent::Configuration*& ) ;

  /// Fill persitent verison of MetaEvent
  void convert( const LsfEvent::MetaEvent&, MetaEvent& ) ;
  /// Fill transient verison of MetaEvent
  void convert( const MetaEvent&, LsfEvent::MetaEvent& ) ;

}

#endif












