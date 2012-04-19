/** 
 * @file ascii_arc_bathy.h
 * Extracts bathymetry data from from ASCII files with an ARC header.
 */
#ifndef USML_OCEAN_ASCII_ARC_BATHY_H
#define USML_OCEAN_ASCII_ARC_BATHY_H

#include <usml/ublas/ublas.h>
#include <usml/types/types.h>

namespace usml {
namespace ocean {

using namespace usml::ublas ;
using namespace usml::types ;

/// @ingroup ascii_arc_files
/// @{

/**
 * Extracts bathymetry data from ASCII files with an ARC header.
 * Stores the latitude, longitude, and depth in spherical earth
 * coordinates for faster interpolation within the WaveQ3D model.
 *
 * An example of this header is shown below.  Each row in the data
 * represents the depth as a function of increasing latitude,
 * which is the Y coordinate. Each column represents the depth
 * as a function of increasing longitude, which is the X coordinate.
 * The first data point is therefore the depth at south-west corner
 * specified by longitude=XLLCENTER and latitude=YLLCENTER).
 * Each depth represents the average value over the
 * CELLSIZE x CELLSIZE area centered on the specified longitude
 * and latitude.
 * <pre>
 * NCOLS   601
 * NROWS  1201
 * XLLCENTER  -80.25000
 * YLLCENTER  26.00000
 * CELLSIZE 0.00083333
 * NODATA_VALUE  999999
 *      6.0      6.0      6.0      6.0      6.0      ...
 *      6.0      6.0      6.0      6.0      6.0      ...
 *      etc.
 * </pre>
 *
 * This format is used by the Geophysical Data System (GEODAS)
 * Search and Data Retrieval web site to produce custom grids
 * of U.S. Coastal Relief Model (CRM) bathymetry.  CRM provides
 * gridded bathymetry, at 3 arc-second resolution, for the
 * U.S. East and West Coasts, the northern coast of the
 * Gulf of Mexico, Puerto Rico, and Hawaii, reaching out
 * to the continental slope.
 */
class USML_DECLSPEC ascii_arc_bathy : public data_grid<float,2> {

  public:  

    /**
     * Load bathymetry from disk from ASCII file with an ARC header.
     * The entire data file is loaded.
     *
     * @param  filename     Name of the ASCII ARC file to load.
     * @param  earth_radius Local earth radius of curvature (meters).
     *                      Set to zero if you want to make depths
     *                      relative to earth's surface.
     */
    ascii_arc_bathy( const char* filename ) ;

} ;

/// @}
}  // end of namespace ocean
}  // end of namespace usml

#endif
