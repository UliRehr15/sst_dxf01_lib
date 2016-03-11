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
//  sstDxf01Insert.cpp   27.02.16  Re.   27.02.16  Re.
//
//  Functions for sst Dxf Insert Classes
//
 
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

 
// Constructor
sstDxf01TypInsertCls::sstDxf01TypInsertCls()
{
  this->ulInsertID = 0;
  this->ulLayerID = 0;
  this->ulBlockID = 0;
}
 
// Set Test Data
int sstDxf01TypInsertCls::SetTestData(int iKey)
{
  if ( iKey != 0) return -1;

  return 0;
}

void sstDxf01TypInsertCls::ReadFromDL(const DL_InsertData oDLInsert)
{
  this->ipx = oDLInsert.ipx;
  this->ipy  = oDLInsert.ipy;
  this->ipz  = oDLInsert.ipz;
  this->sx = oDLInsert.sx;
  this->sy = oDLInsert.sy;
  this->sz = oDLInsert.sz;
  this->angle = oDLInsert.angle;
  this->cols = oDLInsert.cols;
  this->rows = oDLInsert.rows;
  this->colSp = oDLInsert.colSp;
  this->rowSp = oDLInsert.rowSp;
}
//=============================================================================
void sstDxf01TypInsertCls::WritToDL(DL_InsertData *poDLInsert)
{
  poDLInsert->ipx = this->ipx;
  poDLInsert->ipy = this->ipy;
  poDLInsert->ipz = this->ipz;
  poDLInsert->sx = this->sx;
  poDLInsert->sy = this->sy;
  poDLInsert->sz = this->sz;
  poDLInsert->angle = this->angle;
  poDLInsert->cols = this->cols;
  poDLInsert->rows = this->rows;
  poDLInsert->colSp = this->colSp;
  poDLInsert->rowSp = this->rowSp;
}
//=============================================================================
unsigned long sstDxf01TypInsertCls::getLayerID() const
{
return ulLayerID;
}
//=============================================================================
void sstDxf01TypInsertCls::setLayerID(unsigned long value)
{
ulLayerID = value;
}
//=============================================================================
unsigned long sstDxf01TypInsertCls::getBlockID() const
{
return ulBlockID;
}
//=============================================================================
void sstDxf01TypInsertCls::setBlockID(unsigned long value)
{
ulBlockID = value;
}
//=============================================================================
unsigned long sstDxf01TypInsertCls::getInsertID() const
{
return ulInsertID;
}
//=============================================================================
void sstDxf01TypInsertCls::setInsertID(unsigned long value)
{
ulInsertID = value;
}
//=============================================================================
double sstDxf01TypInsertCls::getIpx() const
{
return ipx;
}
//=============================================================================
void sstDxf01TypInsertCls::setIpx(double value)
{
ipx = value;
}
//=============================================================================
double sstDxf01TypInsertCls::getIpy() const
{
return ipy;
}
//=============================================================================
void sstDxf01TypInsertCls::setIpy(double value)
{
ipy = value;
}
//=============================================================================
double sstDxf01TypInsertCls::getIpz() const
{
return ipz;
}
//=============================================================================
void sstDxf01TypInsertCls::setIpz(double value)
{
ipz = value;
}
//=============================================================================
// Constructor
sstDxf01FncInsertCls::sstDxf01FncInsertCls()
{

}
//=============================================================================
// Csv Read Function
int sstDxf01FncInsertCls::Csv_Read(int iKey, std::string *sErrTxt, std::string *ssstDxfLib_Str, sstDxf01TypInsertCls *osstDxf01TypInsertCls)
{
  DL_InsertData sDLInsert("",0,0,0,0,0,0,0,0,0,0,0);
  unsigned long ulTmpInsertID = 0;
  unsigned long ulTmpLayerID = 0;
  unsigned long ulTmpBlockID = 0;
  sstStr01Cls oCsvRow;
  int iStat = 0;
  int iRet  = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpInsertID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpLayerID);
  if (iStat >= 0)
    iStat = oCsvRow.CsvString2_UInt4( 0, ssstDxfLib_Str, &ulTmpBlockID);
//  if (iStat >= 0)
//    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.cx);
//  if (iStat >= 0)
//    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.cy);
//  if (iStat >= 0)
//    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.cz);
//  if (iStat >= 0)
//    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.radius);
//  if (iStat >= 0)
//    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.angle1);
//  if (iStat >= 0)
//    iStat = oCsvRow.CsvString2_Dbl( 0, ssstDxfLib_Str, &sDLInsert.angle2);

  *sErrTxt = oCsvRow.GetErrorString();

  osstDxf01TypInsertCls->ReadFromDL(sDLInsert);

  osstDxf01TypInsertCls->setInsertID(ulTmpInsertID);
  osstDxf01TypInsertCls->setLayerID(ulTmpLayerID);
  osstDxf01TypInsertCls->setBlockID(ulTmpBlockID);

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
//=============================================================================
// Csv Write Function
int sstDxf01FncInsertCls::Csv_Write(int iKey, sstDxf01TypInsertCls *poSstInsert, std::string *ssstDxfLib_Str)
{
  int iStat = 0;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstInsert->getInsertID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstInsert->getLayerID(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_UInt4_2String( 0, poSstInsert->getBlockID(), ssstDxfLib_Str);

  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String( 0, poSstInsert->getIpx(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getIpy(), ssstDxfLib_Str);
  if (iStat >= 0)
    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getIpz(), ssstDxfLib_Str);

  if (iStat >= 0)
    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstInsert->getColor(), ssstDxfLib_Str);


//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String( 0, poSstInsert->getCx(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getCy(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getCz(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getRadius(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getAngle1(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Dbl_2String ( 0, poSstInsert->getAngle2(), ssstDxfLib_Str);
//  if (iStat >= 0)
//    iStat = oCsvRow.Csv_Int2_2String ( 0, poSstInsert->getColor(), ssstDxfLib_Str);

  return iStat;
}
//=============================================================================
int sstDxf01FncInsertCls::Csv_WriteHeader(int iKey, std::string *ssstDxfLib_Str)
{
  std::string oTitelStr;
  int iStat = 0;

//  unsigned long ulLayerID;
//  unsigned long ulBlockID;
//  double cx;
//  double cy;
//  double cz;
//  double radius;
//  double angle1;
//  double angle2;
//  int    color;

  if ( iKey != 0) return -1;

  ssstDxfLib_Str->clear();

  oTitelStr = "TypeID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "LayerID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "BlockID";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  oTitelStr = "ipx";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ipy";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
  oTitelStr = "ipz";
  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

//  oTitelStr = "radius";
//  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
//  oTitelStr = "angle1";
//  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);
//  oTitelStr = "angle2";
//  iStat = oCsvRow.Csv_Str_2String( 0, oTitelStr, ssstDxfLib_Str);

  oTitelStr = "color";
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
