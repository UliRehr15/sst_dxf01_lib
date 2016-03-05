/**********************************************************************
 *
 * sstDxf01Lib - sst dxf library
 * Hosted on github
 *
 * Copyright (C) 2016 Uli Rehr
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/
// sstDxf2Csv.h   26.02.16  Re.   26.02.16  Re.
//
// Datastructures and Prototypes for system "sstDxf01Lib"
//

#ifndef SSTDXF2CSV_HEADER
#define SSTDXF2CSV_HEADER



//==============================================================================
/**
* @brief Definition Class sstDxf2CsvCls
*
* template for sst base class <BR>
*
* Changed: 09.07.15  Re.
*
* @ingroup sstTemplateLib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf2CsvCls : public sstMisc01PrtFilCls
{
  public:   // Public functions
     sstDxf2CsvCls();  // Constructor
   //  ~sstDxf2CsvCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory  <BR>
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     void testReading(char* file);
     void usage();
     // sstMisc01PrtFilCls oPrt; /**< output protocol file */
// ----------------------------------------------------------------------------
  private:  // Private functions
};
//-----------------------------------------------------------------------------

#endif // SSTDXF2CSV_H

