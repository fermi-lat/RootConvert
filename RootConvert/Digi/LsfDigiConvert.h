#ifndef RootConvert_LsfDigiConvert_H
#define RootConvert_LsfDigiConvert_H 1

#include <LdfEvent/LsfMetaEvent.h>

#include <digiRootData/GemTime.h>
#include <digiRootData/TimeTone.h>
#include <digiRootData/LsfTime.h>
#include <digiRootData/RunInfo.h>
#include <digiRootData/DatagramInfo.h>
#include <digiRootData/GemScalers.h>
#include <digiRootData/Configuration.h>
#include <digiRootData/MetaEvent.h>

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
  void convert( const lsfData::Time&, LsfTime& ) ;
  /// Fill transient verison of Time
  void convert( const LsfTime&, lsfData::Time& ) ;

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












