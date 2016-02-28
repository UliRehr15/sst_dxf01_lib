/**********************************************************************
 *
 * sst_dxf_ - sst library for working with dxf data
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
// dxf2recmem.cpp    09.02.16  Re.    09.02.16  Re.
//


#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "dl_dxf.h"
#include "dl_creationadapter.h"

#include <sstStr01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf01Lib.h>

#include "sstdxf2csv.h"


//=============================================================================
/*
 * @brief Main function for DXFLib test program.
 *
 * @param argc Number of delimited items on command line,
 *		including program name.
 * @param argv Pointer to array of command line items
 *
 * @retval 0 if missing input file argument or
 *		file couldn't be opened
 * @retval 1 if file opened
 */
int main(int argc, char** argv)
{

    // Check given arguments:
    if (argc<2)
    {
        usage();
        return 0;
    }

  sstDxf2CsvCls oDxf2Csv;
  oDxf2Csv.testReading(argv[1]);

  return 0;
}
//=============================================================================
/*
 * @brief Prints error message if file name not specified as command
 * line argument.
 */
void usage() {
    std::cout << "\nUsage: test <DXF file>\n\n";
}
//=============================================================================
void sstDxf2CsvCls::testReading(char* file) {
    // Load DXF file into memory:
    std::cout << "Reading file " << file << "...\n";
    sstDxf01ReadCls* creationClass = new sstDxf01ReadCls();
    DL_Dxf* dxf = new DL_Dxf();
    if (!dxf->in(file, creationClass)) { // if file open failed
        std::cerr << file << " could not be opened.\n";
        return;
    }
    delete dxf;
    delete creationClass;
}
//=============================================================================
sstDxf2CsvCls::sstDxf2CsvCls()
{

}
//=============================================================================
