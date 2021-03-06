
#include <RootConvert/Recon/CalFitParamsConvert.h>
#include <RootConvert/Utilities/Toolkit.h>

namespace RootPersistence {

void convert( const Event::CalFitParams & tdsParams, CalFitParams & rootParams ) {
    rootParams.init
      ( tdsParams.getEnergy(),tdsParams.getEnergyErr(),
        convert(tdsParams.getCentroid()),
        tdsParams.getxPosxPos(),tdsParams.getxPosyPos(),tdsParams.getxPoszPos(),
        tdsParams.getyPosyPos(),tdsParams.getyPoszPos(),tdsParams.getzPoszPos(),
        convert(tdsParams.getAxis()),
        tdsParams.getxDirxDir(),tdsParams.getxDiryDir(),tdsParams.getxDirzDir(),
        tdsParams.getyDiryDir(),tdsParams.getyDirzDir(),tdsParams.getzDirzDir(),
        tdsParams.getFitLayers(),tdsParams.getChiSquare() ) ;
 }
 
void convert( const CalFitParams & rootParams, Event::CalFitParams & tdsParams )
{
    const TVector3 & rootCentroid = rootParams.getCentroid() ;
    const TVector3 & rootAxis = rootParams.getAxis() ;
    tdsParams = Event::CalFitParams
      ( rootParams.getEnergy(), rootParams.getEnergyErr(),
        rootCentroid.X(),rootCentroid.Y(),rootCentroid.Z(),
        rootParams.getxPosxPos(), rootParams.getxPosyPos(), rootParams.getxPoszPos(),
        rootParams.getyPosyPos(), rootParams.getyPoszPos(), rootParams.getzPoszPos(),
        rootAxis.X(),rootAxis.Y(),rootAxis.Z(),
        rootParams.getxDirxDir(), rootParams.getxDiryDir(), rootParams.getxDirzDir(),
        rootParams.getyDiryDir(), rootParams.getyDirzDir(), rootParams.getzDirzDir(),
        rootParams.getFitLayers(), rootParams.getChiSquare() ) ;
}

}
