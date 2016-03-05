/**********************************************************************
 *
 * sstDxf01Lib - cpp Dxf library for sst
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
// sstDxf01Block.cpp   26.02.16  Re.   26.02.16  Re.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <dl_creationadapter.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf01Lib.h>

//=============================================================================
sstDxf01TypBlkCls::sstDxf01TypBlkCls()
{
  this->ulBlockID = 0;
  memset(this->Nam,0,dSSTDXFBLOCKNAMELEN);
  this->flags = 0;
}
//=============================================================================
int sstDxf01TypBlkCls::getFlags() const
{
return flags;
}
//=============================================================================
void sstDxf01TypBlkCls::setFlags(int value)
{
flags = value;
}
//=============================================================================
char* sstDxf01TypBlkCls::getName()
{
  return this->Nam;
}
//=============================================================================
void sstDxf01TypBlkCls::setName(const char* cTmpName)
{
  strncpy(this->Nam,cTmpName,dSSTDXFLAYERNAMELEN);
}

unsigned long sstDxf01TypBlkCls::getBlockID() const
{
return ulBlockID;
}

void sstDxf01TypBlkCls::setBlockID(unsigned long value)
{
ulBlockID = value;
}
//=============================================================================
void sstDxf01TypBlkCls::ReadFromDL(const DL_BlockData oDlBlk)
{
  strncpy(this->Nam, oDlBlk.name.c_str(), dSSTDXFBLOCKNAMELEN);
  this->flags = oDlBlk.flags;
}
//=============================================================================
void sstDxf01TypBlkCls::WritToDL(DL_BlockData *poDlBlk)
{
    poDlBlk->name = this->getName();
    poDlBlk->flags = this->getFlags();
}
//=============================================================================
// Constructor
sstDxf01FncBlkCls::sstDxf01FncBlkCls()
{

}

// Csv Read Function
int sstDxf01FncBlkCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf01TypBlkCls *oSstBlk)
{
  DL_BlockData sDlBlk("",0,0.0,0.0,0.0);
  sstStr01Cls oCsvRow;
  unsigned long ulTmpBlockID = 0;
  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpBlockID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Str( 0, ssstDxfLib_Str, &sDlBlk.name);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &sDlBlk.flags);
  if (iStat >= 0)

  *sErrTxt = oCsvRow.GetErrorString();

  oSstBlk->ReadFromDL(sDlBlk);
  oSstBlk->setBlockID(ulTmpBlockID);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

//  Bloc Function1 End
  return iStat;
}

// Csv Write Function
int sstDxf01FncBlkCls::Csv_Write(int iKey, sstDxf01TypBlkCls *poSstBlk, std::string *ssstDxfLib_Str)
{
  // sstStr01Cls oCsvRow;  // Csv String Convert object
  int iStat = 0;

  //  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstBlk->getBlockID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Char_2String( 0, poSstBlk->getName(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstBlk->getFlags(), ssstDxfLib_Str);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

//  Bloc Function Write End
  return iStat;
}
//=============================================================================
int sstDxf01FncBlkCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

//  char Nam[dSSTDXFBLOCKNAMELEN];  /**< Block Name */
//  int  flags;               /**< Block Flags */

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  oTitelStr = "BlockID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "name";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "flags";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  // Fatal Errors goes to an assert
  if (iStat < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  return iStat;
}
//=============================================================================
