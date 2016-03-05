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
// sstDxf01Layer.cpp   26.02.16  Re.   26.02.16  Re.

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
sstDxf01TypLayCls::sstDxf01TypLayCls()
{
  this->ulLayerID = 0;
  memset(this->Nam,0,dSSTDXFLAYERNAMELEN);
  this->flags = 0;
}
//=============================================================================
int sstDxf01TypLayCls::getFlags() const
{
  return flags;
}
//=============================================================================
void sstDxf01TypLayCls::setFlags(int value)
{
  flags = value;
}
//=============================================================================
char* sstDxf01TypLayCls::getName()
{
  return this->Nam;
}
//=============================================================================
void sstDxf01TypLayCls::setName(const char* cTmpName)
{
  strncpy(this->Nam,cTmpName,dSSTDXFLAYERNAMELEN);
}

unsigned long sstDxf01TypLayCls::getLayerID() const
{
return ulLayerID;
}

void sstDxf01TypLayCls::setLayerID(unsigned long value)
{
ulLayerID = value;
}
//=============================================================================
void sstDxf01TypLayCls::ReadFromDL(const DL_LayerData oDlLay)
{
  strncpy(this->Nam, oDlLay.name.c_str(),dSSTDXFLAYERNAMELEN);
  this->flags  = oDlLay.flags;
}
//=============================================================================
void sstDxf01TypLayCls::WritToDL(DL_LayerData *poDlLay)
{
    poDlLay->name = this->getName();
    poDlLay->flags = this->getFlags();
}
//=============================================================================
// Constructor
sstDxf01FncLayCls::sstDxf01FncLayCls()
{

}

// Csv Read Function
int sstDxf01FncLayCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf01TypLayCls *oTypLay)
{
  DL_LayerData sDlLay("",0);
  sstStr01Cls oCsvRow;
  unsigned long ulTmpLayerID = 0;
  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpLayerID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Str( 0, ssstDxfLib_Str, &sDlLay.name);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_Int2( 0, ssstDxfLib_Str, &sDlLay.flags);

  *sErrTxt = oCsvRow.GetErrorString();

  oTypLay->ReadFromDL(sDlLay);
  oTypLay->setLayerID(ulTmpLayerID);

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
int sstDxf01FncLayCls::Csv_Write(int iKey, sstDxf01TypLayCls *poSstLAY, std::string *ssstDxfLib_Str)
{
  // sstStr01Cls oCsvRow;  // Csv String Convert object
  int iStat = 0;

  //  Bloc Function Write Start
  int iRet  = 0;
  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstLAY->getLayerID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Char_2String( 0, poSstLAY->getName(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstLAY->getFlags(), ssstDxfLib_Str);

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
int sstDxf01FncLayCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

//  char Nam[dSSTDXFLAYERNAMELEN]; /**< Layer Name */
//  int flags;               /**< Layer flags. (1 = frozen, 2 = frozen by default, 4 = locked) */

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  oTitelStr = "LayerID";
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
