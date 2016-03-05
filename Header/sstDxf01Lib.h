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
// sstDxf01Lib.h   22.02.16  Re.   22.02.16  Re.
//
// Datastructures and Prototypes for system "sstDxf01Lib"
//
  
#ifndef   _SST_DXF01LIB_HEADER
#define   _SST_DXF01LIB_HEADER

/**
 * @defgroup sstDxf01Lib sstDxf01Lib: cpp sst dxf library (Version 1)
 *
 * cpp sst dxf library <BR>
 *
 */


#define dSSTDXFLAYERNAMELEN   256  /**< Layer Name length @ingroup sstDxf01Lib */
#define dSSTDXFBLOCKNAMELEN   256  /**< Block Name length @ingroup sstDxf01Lib */

//==============================================================================
/**
* @brief sst dxf base class for dxf types
*
* More Comment
*
* Changed: 03.03.16  Re.
*
* @ingroup sstDxf01Lib
*
* @author Re.
*
* @date 03.03.16
**/
//------------------------------------------------------------------------
class sstDxf01TypBaseCls
{
  public:
    sstDxf01TypBaseCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    int getColor() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setColor(int value);
    //==============================================================================
    /**
    * @brief // read attribu data from dxflib arc <BR>
    * oSstDxfArc.BaseReadFromDL(oDLAttrib);
    *
    * @param oDLAttrib [in] dxflib attribut structure
    */
    // ----------------------------------------------------------------------------
    void BaseReadFromDL(const DL_Attributes oDLAttrib);
    //==============================================================================
    /**
    * @brief // write attribute data to dxflib attribut <BR>
    * oSstDxfBase.BaseWritToDL(poDLAttrib);
    *
    * @param poDLAttrib [out] dxflib arc structure
    */
    // ----------------------------------------------------------------------------
    void BaseWritToDL(DL_Attributes *poDLAttrib);

private:
    // standard attributes
    // std::string layer;
    int color;
    int color24;
    int width;
    // std::string lineType;
    int handle;

};


//==============================================================================
/**
* @brief sst Dxf Arc Class
*
* More Comment
*
* Changed: 12.03.13  Re.
*
* @ingroup sstDxf01Lib
*
* @author Re.
*
* @date 12.03.13
*/
// ----------------------------------------------------------------------------
class sstDxf01TypArcCls : public sstDxf01TypBaseCls
{
  public:
    sstDxf01TypArcCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Set Test Data <BR>
    * iStat= oSstDxfArc.SetTestData(iKey);
    *
    * @param iKey [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    int SetTestData(int iKey);
    //==============================================================================
    /**
    * @brief // read arc data from dxflib arc <BR>
    * oSstDxfArc.ReadFromDL(poDLArc);
    *
    * @param poDLArc [in] dxflib arc structure
    */
    // ----------------------------------------------------------------------------
    void ReadFromDL(const DL_ArcData poDLArc);
    //==============================================================================
    /**
    * @brief // write arc data to dxflib arc <BR>
    * oSstDxfArc.WritToDL(poDLArc);
    *
    * @param poDLArc [out] dxflib arc structure
    */
    // ----------------------------------------------------------------------------
    void WritToDL(DL_ArcData *poDLArc);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getCx() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setCx(double value);

    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getCy() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setCy(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getCz() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setCz(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getRadius() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setRadius(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getAngle1() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setAngle1(double value);
    //==============================================================================
    /**
    * @brief // Get Cx Value  <BR>
    *
    * @return Cx
    */
    // ----------------------------------------------------------------------------
    double getAngle2() const;
    //==============================================================================
    /**
    * @brief // Set Cx Value  <BR>
    *
    * @param value [in] Set Cx
    */
    // ----------------------------------------------------------------------------
    void setAngle2(double value);
    //==============================================================================
    /**
    * @brief // Get Layer ID  <BR>
    *
    * @return LayerID
    */
    // ----------------------------------------------------------------------------
    unsigned long getLayerID() const;
    //==============================================================================
    /**
    * @brief // Set Layer ID  <BR>
    *
    * @param value [in] Set Layer ID
    */
    // ----------------------------------------------------------------------------
    void setLayerID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get Block ID  <BR>
    *
    * @return BlockID
    */
    // ----------------------------------------------------------------------------
    unsigned long getBlockID() const;
    //==============================================================================
    /**
    * @brief // Set Block ID  <BR>
    *
    * @param value [in] Set Block ID
    */
    // ----------------------------------------------------------------------------
    void setBlockID(unsigned long value);
    //==============================================================================
    /**
    * @brief // Get Arc ID  <BR>
    *
    * @return unsigned long Arc ID
    */
    // ----------------------------------------------------------------------------
    unsigned long getArcID() const;
    //==============================================================================
    /**
    * @brief // Set Arc ID  <BR>
    *
    * @param value [in] Arc ID
    */
    // ----------------------------------------------------------------------------
    void setArcID(unsigned long value);
    //==============================================================================

private:
    unsigned long ulArcID;
    unsigned long ulLayerID;
    unsigned long ulBlockID;
    double cx;
    double cy;
    double cz;
    double radius;
    double angle1;
    double angle2;
    // standard attributes
    std::string layer;
    int color;
    int color24;
    int width;
    std::string lineType;
    int handle;
};
//==============================================================================
/**
* @brief sst Dxf Layer Class
*
* template for sst base class <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf01Lib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf01TypLayCls
{
  public:   // Public functions
     sstDxf01TypLayCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @param cName [in] Set Name
     */
     // ----------------------------------------------------------------------------
     void setName(const char* cName);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @return char Name
     */
     // ----------------------------------------------------------------------------
     char* getName();
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @return int flags
     */
     // ----------------------------------------------------------------------------
     int getFlags() const;
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @param value [in] Flags
     */
     // ----------------------------------------------------------------------------
     void setFlags(int value);
     //==============================================================================
     /**
     * @brief // Set Test Data <BR>
     * iStat= oSstDxfLay.SetTestData(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     int SetTestData(int iKey);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.ReadFromDL(poDLArc);
     *
     * @param poDlLay [in] dxflib Layer structure
     */
     void ReadFromDL(const DL_LayerData poDlLay);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfLay.WritToDL(poDLArc);
     *
     * @param poDlLay [out] dxflib layer structure
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     void WritToDL(DL_LayerData *poDlLay);
     //==============================================================================
     /**
     * @brief // Get Layer ID <BR>
     * ulLayerID = oSstDxfLay.GetLayerID();
     *
     * @return unsigned long Layer ID
     */
     // ----------------------------------------------------------------------------
     unsigned long getLayerID() const;
     //==============================================================================
     /**
     * @brief // Set Layer ID <BR>
     * oSstDxfLay.Func_1(iKey)
     *
     * @param value [in] Layer ID
     */
     // ----------------------------------------------------------------------------
     void setLayerID(unsigned long value);
     //==============================================================================

     char Nam[dSSTDXFLAYERNAMELEN]; /**< Layer Name */
private:  // Private functions
     unsigned long ulLayerID;
  int flags;               /**< Layer flags. (1 = frozen, 2 = frozen by default, 4 = locked) */

};
//-----------------------------------------------------------------------------
//==============================================================================
/**
* @brief sst Dxf Block Class
*
* template for sst base class <BR>
*
* Changed: 08.07.15  Re.
*
* @ingroup sstDxf01Lib
*
* @author Re.
*
* @date 08.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf01TypBlkCls
{
  public:   // Public functions
     sstDxf01TypBlkCls();  // Constructor
    //~sstTestBaseCls();  // Destructor
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @param cName [in] For the moment 0
     */
     // ----------------------------------------------------------------------------
     void setName(const char* cName);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @return char Name
     */
     // ----------------------------------------------------------------------------
     char* getName();
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @return int flags
     */
     // ----------------------------------------------------------------------------
     int getFlags() const;
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @param value [in] Flags
     */
     // ----------------------------------------------------------------------------
     void setFlags(int value);
     //==============================================================================
     /**
     * @brief // Set Test Data <BR>
     * iStat= oSstDxfBlk.SetTestData(iKey);
     *
     * @param iKey [in] For the moment 0
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     int SetTestData(int iKey);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.ReadFromDL(poDlBlk);
     *
     * @param poDlBlk [in] dxflib arc structure
     */
     void ReadFromDL(const DL_BlockData poDlBlk);
     //==============================================================================
     /**
     * @brief // Shortstory <BR>
     * oSstDxfBlk.WritToDL(poDlBlk);
     *
     * @param poDlBlk [out] dxflib arc structure
     */
     void WritToDL(DL_BlockData *poDlBlk);
     //==============================================================================
     /**
     * @brief // Get Block ID <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @return unsigned long ulBlockID
     */
     // ----------------------------------------------------------------------------
     unsigned long getBlockID() const;
     //==============================================================================
     /**
     * @brief // Set Block ID <BR>
     * oSstDxfBlk.Func_1(iKey)
     *
     * @param value [in] Block ID
     */
     // ----------------------------------------------------------------------------
     void setBlockID(unsigned long value);
     //==============================================================================

     char Nam[dSSTDXFBLOCKNAMELEN];  /**< Block Name */
private:  // Private functions
     unsigned long ulBlockID;
     int  flags;               /**< Block Flags */
  // D3Pkt_stru Pkt;           /**< Block center point */

};
//-----------------------------------------------------------------------------


//==============================================================================
/**
* @brief Base Class for sst DXF function class
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf01Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf01FncBaseCls
{
  public:
    sstDxf01FncBaseCls();  // Constructor
    sstStr01Cls oCsvRow;   /**< Csv String Convert object */
  private:
};

 
//==============================================================================
/**
* @brief Definition Class sstDxf01FncArcCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf01Lib
*
* @author Re.
*
* @date 
*/
// ----------------------------------------------------------------------------
class sstDxf01FncArcCls : public sstDxf01FncBaseCls
{
  public:
    sstDxf01FncArcCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oCsvArc.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param sErrTxt [in] For the moment 0
    * @param ssstDxfLib_Str [in] For the moment 0
    * @param osstDxf01TypArcCls [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int iKey,
                 std::string *sErrTxt,
                 std::string *ssstDxfLib_Str,
                 sstDxf01TypArcCls *osstDxf01TypArcCls);  // Csv Read Function
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * iStat = oCsvArc.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param osstDxf01TypArcCls [in] For the moment 0
    * @param ssstDxfLib_Str [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int iKey,
                  sstDxf01TypArcCls *osstDxf01TypArcCls,
                  std::string *ssstDxfLib_Str);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Definition Class sstDxf01FncArcCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf01Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf01FncLayCls : public sstDxf01FncBaseCls
{
  public:
    sstDxf01FncLayCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * oTestBase.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param sErrTxt [in] For the moment 0
    * @param sSstDxfLib_Str [in] For the moment 0
    * @param oSstDxf01TypLay [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int iKey,
                 std::string *sErrTxt,
                 std::string *sSstDxfLib_Str,
                 sstDxf01TypLayCls *oSstDxf01TypLay);  // Csv Read Function
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * oTestBase.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param oSstDxf01TypLayCls [in] For the moment 0
    * @param sSstDxfLib_Str [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                iKey,
                  sstDxf01TypLayCls *oSstDxf01TypLayCls,
                  std::string       *sSstDxfLib_Str);
    //==============================================================================
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================

  private:
};
//==============================================================================
/**
* @brief Definition Class sstDxf01FncArcCls
*
* More Comment
*
* Changed:   Re.
*
* @ingroup sstDxf01Lib
*
* @author Re.
*
* @date
*/
// ----------------------------------------------------------------------------
class sstDxf01FncBlkCls : public sstDxf01FncBaseCls
{
  public:
    sstDxf01FncBlkCls();  // Constructor
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * oTestBase.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param sErrTxt [in] For the moment 0
    * @param sSstDxfLib_Str [in] For the moment 0
    * @param oSstDxf01TypBlk [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Read(int                iKey,
                 std::string       *sErrTxt,
                 std::string       *sSstDxfLib_Str,
                 sstDxf01TypBlkCls *oSstDxf01TypBlk);
    //==============================================================================
    /**
    * @brief // Shortstory <BR>
    * oTestBase.Func_1(iKey)
    *
    * @param iKey [in] For the moment 0
    * @param oSstDxf01TypBlk [in] For the moment 0
    * @param sSstDxfLib_Str [in] For the moment 0
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_Write(int                iKey,
                  sstDxf01TypBlkCls *oSstDxf01TypBlk,
                  std::string       *sSstDxfLib_Str);  // Csv Write Function
    //==============================================================================
    /**
    * @brief // write ARC titel row to csv file <BR>
    * iStat = oCsvArc.Csv_WriteHeader ( 0, &oCsvStr)
    *
    * @param iKey    [in]  For the moment 0
    * @param oCsvStr [out] return string titel row
    *
    * @return Errorstate
    *
    * @retval   = 0: OK
    * @retval   < 0: Unspecified Error
    */
    // ----------------------------------------------------------------------------
    int Csv_WriteHeader(int iKey, std::string *oCsvStr);
    //==============================================================================

  private:
};


//==============================================================================
/**
* @brief Definition Class sstTestInterfaceCls
*
* template for sst base class <BR>
*
* Changed: 09.07.15  Re.
*
* @ingroup sstDxf01Lib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstDxf01ReadCls : public DL_CreationAdapter {
public:
    sstDxf01ReadCls();
    ~sstDxf01ReadCls();

    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addLayer(const DL_LayerData& data);
    //==============================================================================
    /**
    * @brief // Process imported Block data <BR>
    * oSstDxfReadDL.addBlock(data)
    *
    * @param data [in] BlockData
    */
    // ----------------------------------------------------------------------------
    virtual void addBlock(const DL_BlockData& data);
    //==============================================================================
    /**
    * @brief // process end block situation <BR>
    * oSstDxfReadDL.endBlock()
    */
    // ----------------------------------------------------------------------------
    virtual void endBlock();
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addPoint(const DL_PointData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addLine(const DL_LineData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addArc(const DL_ArcData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addCircle(const DL_CircleData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addPolyline(const DL_PolylineData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void addVertex(const DL_VertexData& data);
    //==============================================================================
    /**
    * @brief // Process imported Layer data <BR>
    * oSstDxfReadDL.addLayer(data)
    *
    * @param data [in] LayerData
    */
    // ----------------------------------------------------------------------------
    virtual void add3dFace(const DL_3dFaceData& data);
    //==============================================================================
    /**
    * @brief // Print Attributes <BR>
    * oSstDxfReadDL.printAttributes()
    */
    // ----------------------------------------------------------------------------
    void printAttributes();
    //==============================================================================
    /**
    * @brief // Set Dxf File Name into object <BR>
    * oSstDxfReadDL.SetDxfFilNam(cDxfFilNam);
    *
    * @param cDxfFilNam [in] Set Dxf File Name
    *
    */
    // ----------------------------------------------------------------------------
    void SetDxfFilNam(char* cDxfFilNam);
    //==============================================================================
private:
    sstRec04Cls *poDxfArcMem;  /**< record memory for sst dxf arc elements */
    sstRec04Cls *poDxfLayMem;  /**< record memory for sst dxf layer elements */
    sstRec04Cls *poDxfBlkMem;  /**< record memory for sst dxf block elements */
    std::string oDxfFilNam;    /**< dxf file name without extension */
    std::string oActBlockNam;    /**< actual block name */
    sstRec04TreeKeyCls oLayerTree;
    sstRec04TreeKeyCls oBlockTree;
};
 
#endif
//
// --------------------------------------------------------------- File End ----


