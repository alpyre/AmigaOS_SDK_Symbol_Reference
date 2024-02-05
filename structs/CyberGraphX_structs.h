CyberGraphX structs from cybergrapics.h

List of CyberGraphX structs:
struct CyberModeNode
struct CDrawMsg

/******************************************************************************/

/* Definition of CyberModeNode (Returned in AllocModeList) */
struct CyberModeNode
{
  struct Node Node;
  char   ModeText[DISPLAYNAMELEN]; /* name for this mode */
  ULONG  DisplayID;                /* display id associated with the node */
  UWORD  Width;                    /* visible width */
  UWORD  Height;                   /* visible height */
  UWORD  Depth;                    /* display depth */
  struct TagItem *DisplayTagList;  /* taglist with extended ModeID information */
};


/* Message passed to the DoCDrawMethodTagList() hook function	*/
struct CDrawMsg
{
  APTR  cdm_MemPtr;
  ULONG cdm_offx;
  ULONG cdm_offy;
  ULONG cdm_xsize;
  ULONG cdm_ysize;
  UWORD cdm_BytesPerRow;
  UWORD cdm_BytesPerPix;
  UWORD cdm_ColorModel;
};

/******************************************************************************/
/******************************************************************************/

CGXVideo structs from cgxvideo_intern.h

List of CGXVideo structs:
struct IntCGXVBase
struct VLayerHandle

/******************************************************************************/

/* Definition of CGXVideo library base */
struct IntCGXVBase
{
  struct Library     libnode;
  OOP_AttrBase       HiddBitMapAttrBase;
  OOP_AttrBase       HiddOverlayAttrBase;
  struct OOP_ABDescr attrbases[3];
};

/* struct returned by CreateVLayerHandleTagList() */
struct VLayerHandle
{
  OOP_Object *obj;	/* Overlay object	  */
  OOP_Object *drv;	/* Graphics driver object */
};
