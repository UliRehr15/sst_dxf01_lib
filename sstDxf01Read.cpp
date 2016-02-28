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


/**
 * Default constructor.
 */
sstDxf01ReadCls::sstDxf01ReadCls()
{
  this->poDxfArcMem = new sstRec04Cls(sizeof(sstDxf01TypArcCls));
  this->poDxfLayMem = new sstRec04Cls(sizeof(sstDxf01TypLayCls));
  this->poDxfBlkMem = new sstRec04Cls(sizeof(sstDxf01TypBlkCls));
}
sstDxf01ReadCls::~sstDxf01ReadCls()
{
    sstMisc01AscFilCls oCsvFil;
    // sstAscRow_Cls oCsvRow;

    int iStat = oCsvFil.fopenWr(0,(char*) "TestArc.csv");
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

      oDxfArcCsv.Csv_Write ( 0, &oDxfArc, &oCsvStr);
      oCsvFil.Wr_StrDS1(0, &oCsvStr);
    }

    iStat = oCsvFil.fcloseFil(0);

    iStat = oCsvFil.fopenWr(0,(char*) "TestLayer.csv");
    assert(iStat >= 0);

    sstDxf01FncLayCls oDxfLayCsv;
    // std::string oCsvStr;

    oDxfLayCsv.Csv_WriteHeader(0,&oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);

    for(dREC04RECNUMTYP kk = 1; kk <= this->poDxfLayMem->count(); kk++)
    {
      // int iVal=0;
      // std::string sCsvStr;

      sstDxf01TypLayCls oDxfLay;
      // sstDxf01FncLayCls oDxfLayCsv;
      this->poDxfLayMem->Read(0,kk,&oDxfLay);
      oDxfLayCsv.Csv_Write ( 0, &oDxfLay, &oCsvStr);

      oCsvFil.Wr_StrDS1(0, &oCsvStr);
      // printf("oRecMem_Int.Read(%d) = %d\n", k, iVal);
    }

    iStat = oCsvFil.fcloseFil(0);

    iStat = oCsvFil.fopenWr(0,(char*) "TestBlock.csv");
    assert(iStat >= 0);

    sstDxf01FncBlkCls oDxfBlkCsv;
    // std::string oCsvStr;

    oDxfBlkCsv.Csv_WriteHeader(0,&oCsvStr);
    oCsvFil.Wr_StrDS1(0, &oCsvStr);

    for(dREC04RECNUMTYP kk = 1; kk <= this->poDxfBlkMem->count(); kk++)
    {
      // int iVal=0;
      // std::string sCsvStr;

      sstDxf01TypBlkCls oDxfBlk;
      // sstDxf01FncBlkCls oDxfBlkCsv;
      this->poDxfBlkMem->Read(0,kk,&oDxfBlk);
      oDxfBlkCsv.Csv_Write ( 0, &oDxfBlk, &oCsvStr);

      oCsvFil.Wr_StrDS1(0, &oCsvStr);
      // printf("oRecMem_Int.Read(%d) = %d\n", k, iVal);
    }

    iStat = oCsvFil.fcloseFil(0);

    delete(this->poDxfBlkMem);
    delete(this->poDxfLayMem);
    delete(this->poDxfArcMem);
}


/**
 * Sample implementation of the method which handles layers.
 */
void sstDxf01ReadCls::addLayer(const DL_LayerData& data)
{
    // printf("LAYER: %s flags: %d\n", data.name.c_str(), data.flags);
    // printAttributes();
    sstDxf01TypLayCls LayDs;
    dREC04RECNUMTYP dRecNo = 0;
    // dSATZ_NR_TYP SatzNr = 0;
    int LayNamLen = 0;
    // int iStat = 0;
  //-----------------------------------------------------------------------------

    // printf("LAYER: %s flags: %d\n", data.name.c_str(), data.flags);

    // Weiteren User-Datensatz in Datenspeicher schreiben.
    LayNamLen = strlen(data.name.c_str());
    if (LayNamLen < dSSTDXFLAYERNAMELEN)
    {
      // strncpy( LayDs.Nam, data.name.c_str(), dSSTDXFLAYERNAMELEN);
      LayDs.setName(data.name.c_str());
      // LayDs.flags = data.flags;
      LayDs.setFlags( data.flags);

      // Datensatz in Dss einfügen, später ohne Dubletten
      // DS1_DsShrNeu ( 0, CreaLayDss, &LayDs);
      this->poDxfLayMem->WritNew( 0, &LayDs, &dRecNo);
    }
    else
    {
      // iStat = 1;
    }

    // iStat = 0;

      // printAttributes();

}
void sstDxf01ReadCls::addBlock(const DL_BlockData& data)
{
  sstDxf01TypBlkCls oBlk;
  dREC04RECNUMTYP dRecNo = 0;
  // dSATZ_NR_TYP SatzNr = 0;
  // DL_BlockData locData("",0,0.0,0.0,0.0);
  // locData = data;  // Umkopieren wg. const
  // strncpy ( oBlk.Nam, data.name.c_str(), dLAYERNAMELEN);
  oBlk.setName( data.name.c_str());

  // SatzNr = DS1_DsShrNeu ( 0, CreaBlkDss, &locData);
  // DS1_DsShrNeu ( 0, CreaBlkDss, &oBlk);
  this->poDxfBlkMem->WritNew( 0, &oBlk, &dRecNo);
  // printf("POINT    (%6.3f, %6.3f, %6.3f)\n",
  //          data.x, data.y, data.z);
  // printAttributes();
}

/**
 * Sample implementation of the method which handles point entities.
 */
void sstDxf01ReadCls::addPoint(const DL_PointData& data) {
    printf("POINT    (%6.3f, %6.3f, %6.3f)\n",
           data.x, data.y, data.z);
    printAttributes();
}

/**
 * Sample implementation of the method which handles line entities.
 */
void sstDxf01ReadCls::addLine(const DL_LineData& data) {
    printf("LINE     (%6.3f, %6.3f, %6.3f) (%6.3f, %6.3f, %6.3f)\n",
           data.x1, data.y1, data.z1, data.x2, data.y2, data.z2);
    printAttributes();
}

/**
 * Sample implementation of the method which handles arc entities.
 */
void sstDxf01ReadCls::addArc(const DL_ArcData& data) {
    printf("ARC      (%6.3f, %6.3f, %6.3f) %6.3f, %6.3f, %6.3f\n",
           data.cx, data.cy, data.cz,
           data.radius, data.angle1, data.angle2);
    printAttributes();
    sstDxf01TypArcCls oDxfArc;
    oDxfArc.ReadFromDL(data);
    dREC04RECNUMTYP dRecNo=0;
    this->poDxfArcMem->WritNew(0,&oDxfArc,&dRecNo);
}

/**
 * Sample implementation of the method which handles circle entities.
 */
void sstDxf01ReadCls::addCircle(const DL_CircleData& data) {
    printf("CIRCLE   (%6.3f, %6.3f, %6.3f) %6.3f\n",
           data.cx, data.cy, data.cz,
           data.radius);
    printAttributes();
}


/**
 * Sample implementation of the method which handles polyline entities.
 */
void sstDxf01ReadCls::addPolyline(const DL_PolylineData& data) {
    printf("POLYLINE \n");
    printf("flags: %d\n", (int)data.flags);
    printAttributes();
}


/**
 * Sample implementation of the method which handles vertices.
 */
void sstDxf01ReadCls::addVertex(const DL_VertexData& data) {
    printf("VERTEX   (%6.3f, %6.3f, %6.3f) %6.3f\n",
           data.x, data.y, data.z,
           data.bulge);
    printAttributes();
}


void sstDxf01ReadCls::add3dFace(const DL_3dFaceData& data) {
    printf("3DFACE\n");
    for (int i=0; i<4; i++) {
        printf("   corner %d: %6.3f %6.3f %6.3f\n", 
            i, data.x[i], data.y[i], data.z[i]);
    }
    printAttributes();
}


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
    
    

// EOF
