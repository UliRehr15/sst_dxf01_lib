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
// sstDxf01Read.cpp   27.02.16  Re.   26.02.16  Re.

#include <iostream>
#include <stdio.h>
#include <assert.h>

#include <dl_creationadapter.h>

#include <sstStr01Lib.h>
#include <sstMisc01Lib.h>
#include <sstRec04Lib.h>
#include <sstDxf01Lib.h>

//=============================================================================
sstDxf01ReadCls::sstDxf01ReadCls()
{
  sstDxf01TypLayCls oLayRec;
  sstDxf01TypBlkCls oBlkRec;
  int iStat=0;

  this->poDxfArcMem = new sstRec04Cls(sizeof(sstDxf01TypArcCls));
  this->poDxfInsertMem = new sstRec04Cls(sizeof(sstDxf01TypInsertCls));

  this->poDxfLayMem = new sstRec04Cls(sizeof(sstDxf01TypLayCls));
  this->poDxfBlkMem = new sstRec04Cls(sizeof(sstDxf01TypBlkCls));

  // Init new name Tree sorting object for Layer RecMem object
  iStat = this->poDxfLayMem->TreIni( 0, &oLayRec, &oLayRec.Nam, sizeof(oLayRec.Nam), sstRecTyp_CC, &this->oLayerTree);
  assert(iStat == 0);

  // Init new name Tree sorting object for Block RecMem object
  iStat = this->poDxfBlkMem->TreIni( 0, &oBlkRec, &oBlkRec.Nam, sizeof(oBlkRec.Nam), sstRecTyp_CC, &this->oBlockTree);
  assert(iStat == 0);

}
//=============================================================================
sstDxf01ReadCls::~sstDxf01ReadCls()
{
    sstMisc01AscFilCls oCsvFil;
    std::string oCsvFilNam;
    // sstAscRow_Cls oCsvRow;

    // Write all Arcs to Csv file

    oCsvFilNam = this->oDxfFilNam + "_Arc.csv";
    int iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
    assert(iStat >= 0);

    sstDxf01FncArcCls oDxfArcCsv;
    std::string oCsvStr;

    oDxfArcCsv.Csv_WriteHeader(0,&oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);

    for(dREC04RECNUMTYP kk = 1; kk <= this->poDxfArcMem->count(); kk++)
    {
      // int iVal=0;

      sstDxf01TypArcCls oDxfArc;
      this->poDxfArcMem->Read(0,kk,&oDxfArc);

      oDxfArc.setArcID(kk);

      oDxfArcCsv.Csv_Write ( 0, &oDxfArc, &oCsvStr);
      oCsvFil.Wr_StrDS1(0, &oCsvStr);
    }

    iStat = oCsvFil.fcloseFil(0);

    // Write all Inserts to Csv file

    oCsvFilNam = this->oDxfFilNam + "_Insert.csv";
    iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
    assert(iStat >= 0);

    sstDxf01FncInsertCls oDxfInsertCsv;
    oCsvStr.clear();

    oDxfInsertCsv.Csv_WriteHeader(0,&oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);

    for(dREC04RECNUMTYP kk = 1; kk <= this->poDxfInsertMem->count(); kk++)
    {
      // int iVal=0;

      sstDxf01TypInsertCls oDxfInsert;
      this->poDxfInsertMem->Read(0,kk,&oDxfInsert);

      oDxfInsert.setInsertID(kk);

      oDxfInsertCsv.Csv_Write ( 0, &oDxfInsert, &oCsvStr);
      oCsvFil.Wr_StrDS1(0, &oCsvStr);
    }

    iStat = oCsvFil.fcloseFil(0);

    // === Write all Layer to Csv file

    oCsvFilNam = this->oDxfFilNam + "_Layer.csv";
    iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
    assert(iStat >= 0);

    sstDxf01FncLayCls oDxfLayCsv;

    oDxfLayCsv.Csv_WriteHeader(0,&oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);

    for(dREC04RECNUMTYP kk = 1; kk <= this->poDxfLayMem->count(); kk++)
    {
      sstDxf01TypLayCls oDxfLay;
      this->poDxfLayMem->Read(0,kk,&oDxfLay);

      oDxfLay.setLayerID(kk);

      oDxfLayCsv.Csv_Write ( 0, &oDxfLay, &oCsvStr);

      oCsvFil.Wr_StrDS1(0, &oCsvStr);
    }

    iStat = oCsvFil.fcloseFil(0);

    // === Write all Block to Csv file

    oCsvFilNam = this->oDxfFilNam + "_Block.csv";
    iStat = oCsvFil.fopenWr(0,(char*) oCsvFilNam.c_str());
    assert(iStat >= 0);

    sstDxf01FncBlkCls oDxfBlkCsv;

    oDxfBlkCsv.Csv_WriteHeader(0,&oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);

    for(dREC04RECNUMTYP kk = 1; kk <= this->poDxfBlkMem->count(); kk++)
    {
      sstDxf01TypBlkCls oDxfBlk;
      this->poDxfBlkMem->Read(0,kk,&oDxfBlk);

      oDxfBlk.setBlockID(kk);

      oDxfBlkCsv.Csv_Write ( 0, &oDxfBlk, &oCsvStr);

      oCsvFil.Wr_StrDS1(0, &oCsvStr);
    }

    iStat = oCsvFil.fcloseFil(0);

    delete(this->poDxfBlkMem);
    delete(this->poDxfLayMem);
    delete(this->poDxfInsertMem);
    delete(this->poDxfArcMem);
}
//=============================================================================
void sstDxf01ReadCls::addLayer(const DL_LayerData& data)
{
    sstDxf01TypLayCls LayDs;
    dREC04RECNUMTYP dRecNo = 0;
    int LayNamLen = 0;
    int iStat = 0;
  //-----------------------------------------------------------------------------

    // printf("LAYER: %s flags: %d\n", data.name.c_str(), data.flags);

    // Weiteren User-Datensatz in Datenspeicher schreiben.
    LayNamLen = strlen(data.name.c_str());
    if (LayNamLen < dSSTDXFLAYERNAMELEN)
    {
      // strncpy( LayDs.Nam, data.name.c_str(), dSSTDXFLAYERNAMELEN);
      LayDs.setName(data.name.c_str());
      LayDs.setFlags( data.flags);

      // Write new record into record memory and update all trees
      iStat = this->poDxfLayMem->TreWriteNew ( 0, &LayDs, &dRecNo);
      assert(iStat == 0);
    }
    else
    {
      assert(0);
    }
}
//=============================================================================
void sstDxf01ReadCls::addBlock(const DL_BlockData& data)
{
  int iStat = 0;
  sstDxf01TypBlkCls oBlk;
  dREC04RECNUMTYP dRecNo = 0;

  oBlk.setName( data.name.c_str());
  oActBlockNam = data.name;

  // Write new record into record memory and update all trees
  iStat = this->poDxfBlkMem->TreWriteNew ( 0, &oBlk, &dRecNo);
  assert(iStat == 0);
}
//=============================================================================
void sstDxf01ReadCls::endBlock()
{
  oActBlockNam.clear();
}
//=============================================================================
void sstDxf01ReadCls::addPoint(const DL_PointData& data) {
    printf("POINT    (%6.3f, %6.3f, %6.3f)\n",
           data.x, data.y, data.z);
    printAttributes();
}
//=============================================================================
void sstDxf01ReadCls::addInsert(const DL_InsertData& data)
{
  int iStat = 0;
  std::string oLayerStr;
  std::string oBlockStr;

  sstDxf01TypInsertCls oDxfInsert;
  oDxfInsert.ReadFromDL(data);
  oDxfInsert.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;
  dREC04RECNUMTYP dBlkRecNo=0;

  // is it element in section entities or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dREC04RECNUMTYP dNumBlocks = this->poDxfBlkMem->count();
    oDxfInsert.setBlockID(dNumBlocks);
  }
  else
  {  // entities
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = this->poDxfLayMem->TreSeaEQ( 0, &this->oLayerTree, (char*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat >= 0);
    if (iStat == 0)
    {
      // layer not found in layer table
      // write new layer data record with new name, take attributes from layer 0
      oLayerStr = "0";
      sstDxf01TypLayCls oLayRec;
      iStat = this->poDxfLayMem->TreSeaEQ( 0, &this->oLayerTree, (char*) oLayerStr.c_str(), &dLayRecNo);
      this->poDxfLayMem->Read(0,dLayRecNo,&oLayRec);
      oLayerStr = attributes.getLayer();
      oLayRec.setName(oLayerStr.c_str());
      // Write new record into record memory and update all trees
      iStat = this->poDxfLayMem->TreWriteNew ( 0, &oLayRec, &dLayRecNo);

    }
    oDxfInsert.setLayerID(dLayRecNo);

    // Find block record with block name
    oBlockStr = data.name;
    iStat = this->poDxfBlkMem->TreSeaEQ( 0, &this->oBlockTree, (void*) oBlockStr.c_str(), &dBlkRecNo);
    // assert(iStat >= 0);
    assert(iStat == 1);  // exit, if block not found in block table
    oDxfInsert.setBlockID(dBlkRecNo);
  }
  // write new insert record in insert table
  iStat = this->poDxfInsertMem->WritNew(0,&oDxfInsert,&dRecNo);
  assert(iStat == 0);
}
//=============================================================================
void sstDxf01ReadCls::addLine(const DL_LineData& data) {
    printf("LINE     (%6.3f, %6.3f, %6.3f) (%6.3f, %6.3f, %6.3f)\n",
           data.x1, data.y1, data.z1, data.x2, data.y2, data.z2);
    printAttributes();
}
//=============================================================================
void sstDxf01ReadCls::addArc(const DL_ArcData& data) {
  int iStat = 0;
  std::string oLayerStr;

  sstDxf01TypArcCls oDxfArc;
  oDxfArc.ReadFromDL(data);
  oDxfArc.BaseReadFromDL(attributes);
  dREC04RECNUMTYP dRecNo=0;
  dREC04RECNUMTYP dLayRecNo=0;

  // is it layer or block??
  if (this->oActBlockNam.length() > 0)
  {  // Block
    dREC04RECNUMTYP dNumBlocks = this->poDxfBlkMem->count();
    oDxfArc.setBlockID(dNumBlocks);
  }
  else
  {  // Layer
    oLayerStr = attributes.getLayer();
    // Find record with exact search value
    iStat = this->poDxfLayMem->TreSeaEQ( 0, &this->oLayerTree, (void*) oLayerStr.c_str(), &dLayRecNo);
    assert(iStat == 1);
    oDxfArc.setLayerID(dLayRecNo);
  }
    this->poDxfArcMem->WritNew(0,&oDxfArc,&dRecNo);
}
//=============================================================================
void sstDxf01ReadCls::addCircle(const DL_CircleData& data) {
    printf("CIRCLE   (%6.3f, %6.3f, %6.3f) %6.3f\n",
           data.cx, data.cy, data.cz,
           data.radius);
    printAttributes();
}
//=============================================================================
void sstDxf01ReadCls::addPolyline(const DL_PolylineData& data) {
    printf("POLYLINE \n");
    printf("flags: %d\n", (int)data.flags);
    printAttributes();
}
//=============================================================================
void sstDxf01ReadCls::addVertex(const DL_VertexData& data) {
    printf("VERTEX   (%6.3f, %6.3f, %6.3f) %6.3f\n",
           data.x, data.y, data.z,
           data.bulge);
    printAttributes();
}
//=============================================================================
void sstDxf01ReadCls::add3dFace(const DL_3dFaceData& data) {
    printf("3DFACE\n");
    for (int i=0; i<4; i++) {
        printf("   corner %d: %6.3f %6.3f %6.3f\n",
            i, data.x[i], data.y[i], data.z[i]);
    }
    printAttributes();
}
//=============================================================================
void sstDxf01ReadCls::printAttributes() {
    printf("  Attributes: Layer: %s, ", attributes.getLayer().c_str());
    printf(" Color: ");
    if (attributes.getColor()==256)	{
        printf("BYLAYER");
    } else if (attributes.getColor()==0) {
        printf("BYBLOCK");
    } else {
        printf("%d", attributes.getColor());
    }
    printf(" Width: ");
    if (attributes.getWidth()==-1) {
        printf("BYLAYER");
    } else if (attributes.getWidth()==-2) {
        printf("BYBLOCK");
    } else if (attributes.getWidth()==-3) {
        printf("DEFAULT");
    } else {
        printf("%d", attributes.getWidth());
    }
    printf(" Type: %s\n", attributes.getLineType().c_str());
}
//=============================================================================
void sstDxf01ReadCls::SetDxfFilNam(char* cTmpDxfFilNam)
{
  std::string oTmpStr;
  sstMisc01FilNamCls oFilNam;
  oTmpStr = cTmpDxfFilNam;
  // Remove extension from dxf file name and store in sst dxf read object
  oFilNam.RemoveExtension(0,"dxf",oTmpStr,&this->oDxfFilNam);
}
//=============================================================================


// EOF
