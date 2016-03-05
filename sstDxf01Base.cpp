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
//  sstDxf01Base.cpp   27.02.16  Re.   27.02.16  Re.
//
//  Functions for sst dxf Base Classes
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

//=============================================================================
// Constructor
sstDxf01TypBaseCls::sstDxf01TypBaseCls()
{
  this->color = 0; // int color;
  this->color24 = 0;  // int color24;
  this->width = 0;  // int width;
  // std::string lineType;
  this->handle = 0;  // int handle;
}
//=============================================================================
int sstDxf01TypBaseCls::getColor() const
{
  return color;
}
//=============================================================================
void sstDxf01TypBaseCls::setColor(int value)
{
  color = value;
}
//=============================================================================
void sstDxf01TypBaseCls::BaseReadFromDL(const DL_Attributes oDLAttrib)
{
  this->color = oDLAttrib.getColor();
}
//=============================================================================
void sstDxf01TypBaseCls::BaseWritToDL(DL_Attributes *poDLAttrib)
{
  poDLAttrib->setColor( this->color);
}
//=============================================================================
// Constructor
sstDxf01FncBaseCls::sstDxf01FncBaseCls()
{
  // this->oCsvRow.setDecType(1);  // set decimal point
  this->oCsvRow.SetBracket(0,(char*)"\x22");  // quotation marks
}
//=============================================================================
