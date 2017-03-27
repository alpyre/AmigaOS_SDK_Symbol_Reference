/*******************************************************************************
These are AmigaOS4 specific data structure definitions extracted from SDK_53.30.
This file is not a part of the official SDK. It is made just to provide
online reference for language-amigaos-c atom package.
*******************************************************************************/

struct _CIAResource
{
    struct Library cr_Library;
    APTR           private1;
    APTR           private2;
};

/**********************************************************************************************/

struct AATextFont
{
    struct ColorTextFont aatf_CTF;
    UWORD                aatf_Modulo;      /* Row modulo for the
                                              strike font data */
    UWORD                aatf_FreeMe;      /* Private, defaults to 0 */
    APTR                 aatf_CharData;    /* Chunky alpha maps
                                              for characters */
    APTR                 aatf_CharLoc;     /* Pointer to location data for the
                                              strike font. Two words:
                                              pixel offset then size */
    struct AATextFont   *aatf_SelfPtr;     /* Pointer to the structure itself
                                              to be able to detect modified
                                              TextFont copies that are no real
                                              AATextFonts */
    ULONG                aatf_Reserved[2]; /* For future expansion,
                                              default to 0 */
};

/**********************************************************************************************/

struct AddressAndSize
{
    uint32  aas_Address;
    uint32  aas_Size;
};

/**********************************************************************************************/

struct AIN_IFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct AIN_IFace *Self);
	uint32 APICALL (*Release)(struct AIN_IFace *Self);
	void APICALL (*Expunge)(struct AIN_IFace *Self);
	struct Interface * APICALL (*Clone)(struct AIN_IFace *Self);
	ULONG APICALL (*AIN_GetError)(struct AIN_IFace *Self, APTR ctx);
	STRPTR APICALL (*AIN_GetErrorString)(struct AIN_IFace *Self, ULONG error_code);
	APTR APICALL (*AIN_CreateContext)(struct AIN_IFace *Self, ULONG api_version, struct TagItem * tags);
	VOID APICALL (*AIN_DeleteContext)(struct AIN_IFace *Self, APTR ctx);
	BOOL APICALL (*AIN_EnumDevices)(struct AIN_IFace *Self, APTR ctx, APTR enumfunc, APTR user_data);
	BOOL APICALL (*AIN_Query)(struct AIN_IFace *Self, APTR ctx, AIN_DeviceID device_id, ULONG qParameter, ULONG qArg, APTR result, ULONG result_length);
	AIN_DeviceHandle * APICALL (*AIN_ObtainDevice)(struct AIN_IFace *Self, APTR ctx, AIN_DeviceID device_id);
	VOID APICALL (*AIN_ReleaseDevice)(struct AIN_IFace *Self, APTR ctx, AIN_DeviceHandle * handle);
	BOOL APICALL (*AIN_SetDeviceParameter)(struct AIN_IFace *Self, APTR ctx, AIN_DeviceHandle * handle, ULONG dParameter, ULONG dArg);
	AIN_InputEvent * APICALL (*AIN_GetEvent)(struct AIN_IFace *Self, APTR ctx);
	VOID APICALL (*AIN_FreeEvent)(struct AIN_IFace *Self, APTR ctx, AIN_InputEvent * event);
	BOOL APICALL (*AIN_ReadDevice)(struct AIN_IFace *Self, APTR ctx, AIN_DeviceHandle * handle, APTR * data);
	BOOL APICALL (*AIN_Set)(struct AIN_IFace *Self, APTR ctx, struct TagItem * tags);
	struct _AIN_RequesterResult * APICALL (*AIN_RequestDevice)(struct AIN_IFace *Self, APTR ctx, struct TagItem * tags);
	VOID APICALL (*AIN_FreeRequest)(struct AIN_IFace *Self, APTR ctx, struct _AIN_RequesterResult * result);
};

/**********************************************************************************************/

struct AlphaHookMsg
{
    ULONG             Action;
    struct ClipRect  *NewAlphaCR;
    struct ClipRect  *OldAlphaCR;
    struct Rectangle *NewBounds;
    struct Rectangle *OldBounds;
};

/**********************************************************************************************/

struct ALPOBinData
{
	uint8 *data;
	int32 size;
};

/**********************************************************************************************/

struct ALPOGetProcInfo
{
	int32 (*getChProc)(struct ALPOGetProcInfo *pi);
	int32 (*unGetChProc)(int32 c, struct ALPOGetProcInfo *pi);
	APTR basePtr;
	APTR handlePtr;
	STRPTR key_otag; // must have a size of at least TAGBUFFER_SIZE

	uint32 encoding;  // enum enALPOEncodings
};

/**********************************************************************************************/

struct ALPOObjIndex
{
	PrefsObject *obj;
	int32 index;
};

/**********************************************************************************************/

struct ALPOObjKey
{
	PrefsObject *obj;
	STRPTR key;
};

/**********************************************************************************************/

struct ALPOObjKeyIndex
{
	PrefsObject *obj;
	STRPTR key;
	int32 index;
};

/**********************************************************************************************/

struct ALPOPutProcInfo
{
	void (*putChProc)(int32 c, struct ALPOPutProcInfo *pi);
	APTR basePtr;
	APTR handlePtr;
	int32 tabDepth;  // set to 0

	uint32 encoding; // enum enALPOEncodings
};

/**********************************************************************************************/

struct ALPOString
{
	STRPTR string;
	uint32 length;
};

/**********************************************************************************************/

struct ALPOUniString
{
	uint32 *string;
	uint32 length;
};

/**********************************************************************************************/

struct AmigaGuideIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct AmigaGuideIFace *Self);
	uint32 APICALL (*Release)(struct AmigaGuideIFace *Self);
	void APICALL (*Expunge)(struct AmigaGuideIFace *Self);
	struct Interface * APICALL (*Clone)(struct AmigaGuideIFace *Self);
	APTR Private1;
	LONG APICALL (*LockAmigaGuideBase)(struct AmigaGuideIFace *Self, APTR handle);
	VOID APICALL (*UnlockAmigaGuideBase)(struct AmigaGuideIFace *Self, LONG key);
	APTR Private2;
	APTR APICALL (*OpenAmigaGuideA)(struct AmigaGuideIFace *Self, struct NewAmigaGuide * nag, struct TagItem * tags);
	APTR APICALL (*OpenAmigaGuide)(struct AmigaGuideIFace *Self, struct NewAmigaGuide * nag, ...);
	APTR APICALL (*OpenAmigaGuideAsyncA)(struct AmigaGuideIFace *Self, struct NewAmigaGuide * nag, struct TagItem * attrs);
	APTR APICALL (*OpenAmigaGuideAsync)(struct AmigaGuideIFace *Self, struct NewAmigaGuide * nag, ...);
	VOID APICALL (*CloseAmigaGuide)(struct AmigaGuideIFace *Self, APTR cl);
	ULONG APICALL (*AmigaGuideSignal)(struct AmigaGuideIFace *Self, APTR cl);
	struct AmigaGuideMsg * APICALL (*GetAmigaGuideMsg)(struct AmigaGuideIFace *Self, APTR cl);
	VOID APICALL (*ReplyAmigaGuideMsg)(struct AmigaGuideIFace *Self, struct AmigaGuideMsg * amsg);
	LONG APICALL (*SetAmigaGuideContextA)(struct AmigaGuideIFace *Self, APTR cl, ULONG id, struct TagItem * attrs);
	LONG APICALL (*SetAmigaGuideContext)(struct AmigaGuideIFace *Self, APTR cl, ULONG id, ...);
	LONG APICALL (*SendAmigaGuideContextA)(struct AmigaGuideIFace *Self, APTR cl, struct TagItem * attrs);
	LONG APICALL (*SendAmigaGuideContext)(struct AmigaGuideIFace *Self, APTR cl, ...);
	LONG APICALL (*SendAmigaGuideCmdA)(struct AmigaGuideIFace *Self, APTR cl, STRPTR cmd, struct TagItem * attrs);
	LONG APICALL (*SendAmigaGuideCmd)(struct AmigaGuideIFace *Self, APTR cl, STRPTR cmd, ...);
	LONG APICALL (*SetAmigaGuideAttrsA)(struct AmigaGuideIFace *Self, APTR cl, struct TagItem * attrs);
	LONG APICALL (*SetAmigaGuideAttrs)(struct AmigaGuideIFace *Self, APTR cl, ...);
	LONG APICALL (*GetAmigaGuideAttr)(struct AmigaGuideIFace *Self, Tag tag, APTR cl, ULONG * storage);
	APTR Private3;
	LONG APICALL (*LoadXRef)(struct AmigaGuideIFace *Self, BPTR lock, STRPTR name);
	VOID APICALL (*ExpungeXRef)(struct AmigaGuideIFace *Self);
	APTR APICALL (*AddAmigaGuideHostA)(struct AmigaGuideIFace *Self, struct Hook * h, STRPTR name, struct TagItem * attrs);
	APTR APICALL (*AddAmigaGuideHost)(struct AmigaGuideIFace *Self, struct Hook * h, STRPTR name, ...);
	LONG APICALL (*RemoveAmigaGuideHostA)(struct AmigaGuideIFace *Self, APTR hh, struct TagItem * attrs);
	LONG APICALL (*RemoveAmigaGuideHost)(struct AmigaGuideIFace *Self, APTR hh, ...);
	APTR Private4;
	APTR Private5;
	APTR Private6;
	APTR Private7;
	APTR Private8;
	APTR Private9;
	APTR Private10;
	APTR Private11;
	APTR Private12;
	APTR Private13;
	CONST_STRPTR APICALL (*GetAmigaGuideString)(struct AmigaGuideIFace *Self, LONG id);
};

/**********************************************************************************************/

struct AnchorPathOld
{
    struct AChain *      ap_Base;       /* pointer to first anchor */
    struct AChain *      ap_Last;       /* pointer to last anchor */
    int32                ap_BreakBits;  /* Bits we want to break on */
    int32                ap_FoundBreak; /* Bits we broke on. Also returns ERROR_BREAK */
    int8                 ap_Flags;      /* New use for extra word. */
    int8                 ap_Reserved;
    int16                ap_Strlen;     /* This is what ap_Length used to be */
    struct FileInfoBlock ap_Info;
    TEXT                 ap_Buf[1];     /* Buffer for path name, allocated by user */
};

/**********************************************************************************************/

struct ApplicationCustomMsg
{
	struct ApplicationMsg almsg;
	STRPTR customMsg;
};

/**********************************************************************************************/

struct ApplicationIconInfo
{
	int32 iconType; // enum enAppIconType
	union
	{
		struct DiskObject *customIcon; // for APPICONT_CustomIcon
		struct Library *dockyBase;     // for APPICONT_Docky
		uint32 reserved[8];
	} info;
};

/**********************************************************************************************/

struct ApplicationIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct ApplicationIFace *Self);
	uint32 APICALL (*Release)(struct ApplicationIFace *Self);
	void APICALL (*Expunge)(struct ApplicationIFace *Self);
	struct Interface * APICALL (*Clone)(struct ApplicationIFace *Self);
	BOOL APICALL (*SetAppLibAttrsA)(struct ApplicationIFace *Self, struct TagItem * tags);
	BOOL APICALL (*SetAppLibAttrs)(struct ApplicationIFace *Self, ...);
	BOOL APICALL (*GetAppLibAttrsA)(struct ApplicationIFace *Self, struct TagItem * tags);
	BOOL APICALL (*GetAppLibAttrs)(struct ApplicationIFace *Self, ...);
	uint32 APICALL (*RegisterApplicationA)(struct ApplicationIFace *Self, CONST_STRPTR appName, struct TagItem * tags);
	uint32 APICALL (*RegisterApplication)(struct ApplicationIFace *Self, CONST_STRPTR appName, ...);
	BOOL APICALL (*UnregisterApplicationA)(struct ApplicationIFace *Self, uint32 appID, struct TagItem * tags);
	BOOL APICALL (*UnregisterApplication)(struct ApplicationIFace *Self, uint32 appID, ...);
	BOOL APICALL (*SetApplicationAttrsA)(struct ApplicationIFace *Self, uint32 appID, struct TagItem * tags);
	BOOL APICALL (*SetApplicationAttrs)(struct ApplicationIFace *Self, uint32 appID, ...);
	BOOL APICALL (*GetApplicationAttrsA)(struct ApplicationIFace *Self, uint32 appID, struct TagItem * tags);
	BOOL APICALL (*GetApplicationAttrs)(struct ApplicationIFace *Self, uint32 appID, ...);
	uint32 APICALL (*FindApplicationA)(struct ApplicationIFace *Self, struct TagItem * tags);
	uint32 APICALL (*FindApplication)(struct ApplicationIFace *Self, ...);
	BOOL APICALL (*LockApplicationIcon)(struct ApplicationIFace *Self, uint32 appID);
	void APICALL (*UnlockApplicationIcon)(struct ApplicationIFace *Self, uint32 appID);
	struct MinList * APICALL (*GetApplicationList)(struct ApplicationIFace *Self);
	void APICALL (*FreeApplicationList)(struct ApplicationIFace *Self, struct MinList * list);
	BOOL APICALL (*SendApplicationMsg)(struct ApplicationIFace *Self, uint32 senderAppID, uint32 receiverAppID, struct ApplicationMsg * msg, uint32 msgType);
	uint32 APICALL (*NotifyA)(struct ApplicationIFace *Self, uint32 appID, struct TagItem * tags);
	uint32 APICALL (*Notify)(struct ApplicationIFace *Self, uint32 appID, ...);
};

/**********************************************************************************************/

struct ApplicationMsg
{
	struct Message msg;
	uint32 senderAppID; // the application (or 0 [no app]) which sent this message
	uint32 type;        // enum enAppLibMessageType
};

/**********************************************************************************************/

struct ApplicationNode
{
	struct MinNode node;
	uint32 appID;
	STRPTR name;
};

/**********************************************************************************************/

struct ApplicationOpenPrintDocMsg
{
	struct ApplicationMsg almsg;
	STRPTR fileName;
};

/**********************************************************************************************/

struct ARexxIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ARexxIFace *Self);
	ULONG APICALL (*Release)(struct ARexxIFace *Self);
	void APICALL (*Expunge)(struct ARexxIFace *Self);
	struct Interface * APICALL (*Clone)(struct ARexxIFace *Self);
	Class * APICALL (*AREXX_GetClass)(struct ARexxIFace *Self);
};

/**********************************************************************************************/

struct AslIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct AslIFace *Self);
	uint32 APICALL (*Release)(struct AslIFace *Self);
	void APICALL (*Expunge)(struct AslIFace *Self);
	struct Interface * APICALL (*Clone)(struct AslIFace *Self);
	struct FileRequester * APICALL (*OBSOLETE_AllocFileRequest)(struct AslIFace *Self);
	VOID APICALL (*OBSOLETE_FreeFileRequest)(struct AslIFace *Self, struct FileRequester * fileReq);
	BOOL APICALL (*OBSOLETE_RequestFile)(struct AslIFace *Self, struct FileRequester * fileReq);
	APTR APICALL (*AllocAslRequest)(struct AslIFace *Self, uint32 reqType, const struct TagItem * tagList);
	APTR APICALL (*AllocAslRequestTags)(struct AslIFace *Self, uint32 reqType, ...);
	VOID APICALL (*FreeAslRequest)(struct AslIFace *Self, APTR requester);
	BOOL APICALL (*AslRequest)(struct AslIFace *Self, APTR requester, const struct TagItem * tagList);
	BOOL APICALL (*AslRequestTags)(struct AslIFace *Self, APTR requester, ...);
	VOID APICALL (*AslFreeVec)(struct AslIFace *Self, APTR memory);
	APTR APICALL (*AslAllocVec)(struct AslIFace *Self, uint32 byteSize, uint32 attributes);
	VOID APICALL (*AbortAslRequest)(struct AslIFace *Self, APTR requester);
	VOID APICALL (*ActivateAslRequest)(struct AslIFace *Self, APTR requester);
	uint32 APICALL (*AslControl)(struct AslIFace *Self, const struct TagItem * tags);
	uint32 APICALL (*AslControlTags)(struct AslIFace *Self, ...);
};

/**********************************************************************************************/

struct AssignNode      /* ASSIGN struct; DLT_LOCK, DLT_LATE, DLT_NONBINDING */
{
    BPTR                an_Next;         /* bptr to next doslist entry      */
    int32               an_Type;         /* DLT_LOCK,DLT_LATE,DLT_NONBINDING */
    struct MsgPort *    an_Port;         /* ptr to handler process port     */
    BPTR                an_Lock;         /* For DLT_LOCK assignments only   */
    STRPTR              an_AssignName;   /* name for non or late-binding assigns */
    struct MultiAssign *an_MultiAssignList;/* for multi-directory assigns (regular) */
    int32               an_Unused[4];    /* not currently used, leave as 0  */
    BSTR                an_Name;         /* BSTR assignment node name       */
    int32               an_StructSize;   /* FULL allocated size of this structure. */
    int32               an_Reserved[4];  /* DOS reserved expansion space.   */
};

/**********************************************************************************************/

struct BackFillMessage
{
    struct Layer     *Layer;
    struct Rectangle  Bounds;
    LONG              OffsetX;
    LONG              OffsetY;
};

/**********************************************************************************************/

struct BattClockIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct BattClockIFace *Self);
	ULONG APICALL (*Release)(struct BattClockIFace *Self);
	void APICALL (*Expunge)(struct BattClockIFace *Self);
	struct Interface * APICALL (*Clone)(struct BattClockIFace *Self);
	VOID APICALL (*ResetBattClock)(struct BattClockIFace *Self);
	ULONG APICALL (*ReadBattClock)(struct BattClockIFace *Self);
	VOID APICALL (*WriteBattClock)(struct BattClockIFace *Self, ULONG time);
	ULONG APICALL (*ReadBattClockMem)(struct BattClockIFace *Self, ULONG offset, ULONG length);
	VOID APICALL (*WriteBattClockMem)(struct BattClockIFace *Self, ULONG data, ULONG offset, ULONG length);
};

/**********************************************************************************************/

struct BattMemIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct BattMemIFace *Self);
	ULONG APICALL (*Release)(struct BattMemIFace *Self);
	void APICALL (*Expunge)(struct BattMemIFace *Self);
	struct Interface * APICALL (*Clone)(struct BattMemIFace *Self);
	VOID APICALL (*ObtainBattSemaphore)(struct BattMemIFace *Self);
	VOID APICALL (*ReleaseBattSemaphore)(struct BattMemIFace *Self);
	ULONG APICALL (*ReadBattMem)(struct BattMemIFace *Self, APTR buffer, ULONG offset, ULONG length);
	ULONG APICALL (*WriteBattMem)(struct BattMemIFace *Self, CONST_APTR buffer, ULONG offset, ULONG length);
};

/**********************************************************************************************/

struct BevelIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct BevelIFace *Self);
	ULONG APICALL (*Release)(struct BevelIFace *Self);
	void APICALL (*Expunge)(struct BevelIFace *Self);
	struct Interface * APICALL (*Clone)(struct BevelIFace *Self);
	Class * APICALL (*BEVEL_GetClass)(struct BevelIFace *Self);
	void APICALL (*Reserved1)(struct BevelIFace *Self);
	void APICALL (*Reserved2)(struct BevelIFace *Self);
	void APICALL (*NewBevelPrefs)(struct BevelIFace *Self);
};

/**********************************************************************************************/

struct BIOSVersionResource
{
	struct Node	bvr_Node;           /* on resource list */
	TEXT		bvr_Version[90];    /* Full version string, READ_ONLY. */
	uint32		bvr_DecodedMajor;	/* Decoded version, major */
	uint32		bvr_DecodedMinor;	/* Decoded version, minor */
	uint32		bvr_DecodedPLevel;	/* Decoded version, patchlevel or otherwise third value */
						/* Something like "U-Boot 1.1.4" would become
						bvr_DecodedMajor = 1, bvr_DecodedMinor = 1, bvr_DecodedPLevel = 4 */
	struct DateStamp bvr_BuildDate; /* As the name says. */
	struct ExecIFace * bvr_IExec;
	BOOL (* bvr_Refresh)(struct BIOSVersionResource * base);
};

/**********************************************************************************************/

struct BitMapIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct BitMapIFace *Self);
	ULONG APICALL (*Release)(struct BitMapIFace *Self);
	void APICALL (*Expunge)(struct BitMapIFace *Self);
	struct Interface * APICALL (*Clone)(struct BitMapIFace *Self);
	Class * APICALL (*BITMAP_GetClass)(struct BitMapIFace *Self);
};

/**********************************************************************************************/

struct BlankerModuleIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct BlankerModuleIFace *Self);
	uint32 APICALL (*Release)(struct BlankerModuleIFace *Self);
	void APICALL (*Expunge)(struct BlankerModuleIFace *Self);
	struct BlankerModuleIFace * APICALL (*Clone)(struct BlankerModuleIFace *Self);
	BOOL APICALL (*BlankerModuleGet)(struct BlankerModuleIFace *Self, uint32 msgType, uint32 * msgData);
	BOOL APICALL (*BlankerModuleSet)(struct BlankerModuleIFace *Self, uint32 msgType, uint32 msgData);
	void APICALL (*BlankerModuleBlankTask)(struct BlankerModuleIFace *Self);
};

/**********************************************************************************************/

struct BlankerPrefsWindowInfo
{
	Object *object;
	struct Window *window;
};

/**********************************************************************************************/

struct BlankerPrefsWindowSetup
{
	uint32 winWidth;
	uint32 winHeight;
	struct Hook *eventHook;     // your own event hook for gadget events
	struct Hook *idcmpHook;     // your own idcmp hook
	struct Hook *mainIDCMPHook; // this one is set by the framework (you might need it)
	uint32 idcmpHookBits;
	Object *rootLayout;
};

/**********************************************************************************************/

struct BlankerPrefsWinGUIEvent
{
	Object *winObject;
	uint32 result;
	uint16 code;
};

/**********************************************************************************************/

struct BlankerPrefsWinIDCMPEvent
{
	APTR obj;
	struct IntuiMessage *msg;
};

/**********************************************************************************************/

struct BlankerRender
{
	struct Task *task;
	uint32 taskSigBreak;

	struct Screen *screen;   // may be NULL in case of the preview
	struct RastPort *rp;     // RastPort where the image data has to be rendered to
	struct Layer *layer;
	struct Hook *renderHook;
	uint32 colorTableSize;   // number of entries within the color table
	uint32 *colorTable;      // colorTable -> array of uint32 (0xAARRGGBB order)

	uint32 screenWidth;      // if in preview mode, this width/height gives you an idea about the
	uint32 screenHeight;     // screen size the blanker will have render in the real mode

	uint32 blankWidth;       // this is the actual with/height of the drawing
	uint32 blankHeight;      // context allocated for the blanker

	BOOL isPreview;          // TRUE if the blanker has to render in preview mode

	/* New for V53 */
	uint32 *colorPenTable;   // Array of pens corresponding to colorTable ARGB colors
};

/**********************************************************************************************/

struct BootstrapCodeBlock
{
    ULONG bcb_ID;            /* 4 character identifier */
    ULONG bcb_SummedLongs;   /* size of this checksummed structure */
    LONG  bcb_ChkSum;        /* block checksum (longword sum to zero) */
    ULONG bcb_HostID;        /* SCSI Target ID of host */
    ULONG bcb_Next;          /* block number of the next BootstrapCodeBlock */
    ULONG bcb_LoadData[123]; /* binary data of the bootstrapper */
    /* note [123] assumes 512 byte blocks */
};

/**********************************************************************************************/

struct BulletIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct BulletIFace *Self);
	ULONG APICALL (*Release)(struct BulletIFace *Self);
	void APICALL (*Expunge)(struct BulletIFace *Self);
	struct Interface * APICALL (*Clone)(struct BulletIFace *Self);
	struct GlyphEngine * APICALL (*OpenEngine)(struct BulletIFace *Self);
	VOID APICALL (*CloseEngine)(struct BulletIFace *Self, struct GlyphEngine * glyphEngine);
	ULONG APICALL (*SetInfoA)(struct BulletIFace *Self, struct GlyphEngine * glyphEngine, const struct TagItem * tagList);
	ULONG APICALL (*SetInfo)(struct BulletIFace *Self, struct GlyphEngine * glyphEngine, ...);
	ULONG APICALL (*ObtainInfoA)(struct BulletIFace *Self, struct GlyphEngine * glyphEngine, const struct TagItem * tagList);
	ULONG APICALL (*ObtainInfo)(struct BulletIFace *Self, struct GlyphEngine * glyphEngine, ...);
	ULONG APICALL (*ReleaseInfoA)(struct BulletIFace *Self, struct GlyphEngine * glyphEngine, const struct TagItem * tagList);
	ULONG APICALL (*ReleaseInfo)(struct BulletIFace *Self, struct GlyphEngine * glyphEngine, ...);
	ULONG APICALL (*GetGlyphMap)(struct BulletIFace *Self, struct GlyphEngine * glyphEngine, ULONG glyphCode, struct GlyphMap ** glyphMap);
};

/**********************************************************************************************/

struct ButtonIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ButtonIFace *Self);
	ULONG APICALL (*Release)(struct ButtonIFace *Self);
	void APICALL (*Expunge)(struct ButtonIFace *Self);
	struct Interface * APICALL (*Clone)(struct ButtonIFace *Self);
	Class * APICALL (*BUTTON_GetClass)(struct ButtonIFace *Self);
};

/**********************************************************************************************/

struct CamdBase
{
    struct Library Lib;
    uint16 pad0;
	/* private stuff below here */
};

/**********************************************************************************************/

struct CamdIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct CamdIFace *Self);
	uint32 APICALL (*Release)(struct CamdIFace *Self);
	void APICALL (*Expunge)(struct CamdIFace *Self);
	struct Interface * APICALL (*Clone)(struct CamdIFace *Self);
	APTR APICALL (*LockCAMD)(struct CamdIFace *Self, uint32 locktype);
	void APICALL (*UnlockCAMD)(struct CamdIFace *Self, APTR lock);
	struct MidiNode * APICALL (*CreateMidiA)(struct CamdIFace *Self, struct TagItem * TagList);
	struct MidiNode * APICALL (*CreateMidi)(struct CamdIFace *Self, ... );
	void APICALL (*DeleteMidi)(struct CamdIFace *Self, struct MidiNode * mn);
	BOOL APICALL (*SetMidiAttrsA)(struct CamdIFace *Self, struct MidiNode * mi, struct TagItem * tags);
	BOOL APICALL (*SetMidiAttrs)(struct CamdIFace *Self, struct MidiNode * mi, ... );
	uint32 APICALL (*GetMidiAttrsA)(struct CamdIFace *Self, struct MidiNode * mi, struct TagItem * attrs);
	uint32 APICALL (*GetMidiAttrs)(struct CamdIFace *Self, struct MidiNode * mi, ... );
	struct MidiNode * APICALL (*NextMidi)(struct CamdIFace *Self, struct MidiNode * last);
	struct MidiNode * APICALL (*FindMidi)(struct CamdIFace *Self, STRPTR name);
	void APICALL (*FlushMidi)(struct CamdIFace *Self, struct MidiNode * mi);
	struct MidiLink * APICALL (*AddMidiLinkA)(struct CamdIFace *Self, struct MidiNode * mi, int32 type, struct TagItem * TagsList);
	struct MidiLink * APICALL (*AddMidiLink)(struct CamdIFace *Self, struct MidiNode * mi, int32 type, ... );
	void APICALL (*RemoveMidiLink)(struct CamdIFace *Self, struct MidiLink * ml);
	BOOL APICALL (*SetMidiLinkAttrsA)(struct CamdIFace *Self, struct MidiLink * ml, struct TagItem * tags);
	BOOL APICALL (*SetMidiLinkAttrs)(struct CamdIFace *Self, struct MidiLink * ml, ... );
	uint32 APICALL (*GetMidiLinkAttrsA)(struct CamdIFace *Self, struct MidiLink * ml, struct TagItem * attrs);
	uint32 APICALL (*GetMidiLinkAttrs)(struct CamdIFace *Self, struct MidiLink * ml, ... );
	struct MidiLink * APICALL (*NextClusterLink)(struct CamdIFace *Self, struct MidiCluster * mc, struct MidiLink * last, int32 type);
	struct MidiLink * APICALL (*NextMidiLink)(struct CamdIFace *Self, struct MidiNode * mi, struct MidiLink * last, int32 type);
	BOOL APICALL (*MidiLinkConnected)(struct CamdIFace *Self, struct MidiLink * ml);
	struct MidiCluster * APICALL (*NextCluster)(struct CamdIFace *Self, struct MidiCluster * last);
	struct MidiCluster * APICALL (*FindCluster)(struct CamdIFace *Self, STRPTR name);
	void APICALL (*PutMidi)(struct CamdIFace *Self, struct MidiLink * link, uint32 Msg);
	BOOL APICALL (*GetMidi)(struct CamdIFace *Self, struct MidiNode * mn, MidiMsg * msg);
	BOOL APICALL (*WaitMidi)(struct CamdIFace *Self, struct MidiNode * mn, MidiMsg * msg);
	void APICALL (*PutSysEx)(struct CamdIFace *Self, struct MidiLink * ml, uint8 * Buffer);
	uint32 APICALL (*GetSysEx)(struct CamdIFace *Self, struct MidiNode * mn, uint8 * Buf, uint32 Len);
	uint32 APICALL (*QuerySysEx)(struct CamdIFace *Self, struct MidiNode * mn);
	void APICALL (*SkipSysEx)(struct CamdIFace *Self, struct MidiNode * mn);
	uint8 APICALL (*GetMidiErr)(struct CamdIFace *Self, struct MidiNode * mn);
	int16 APICALL (*MidiMsgType)(struct CamdIFace *Self, MidiMsg * Msg);
	int16 APICALL (*MidiMsgLen)(struct CamdIFace *Self, uint32 StatusByte);
	void APICALL (*ParseMidi)(struct CamdIFace *Self, struct MidiLink * ml, CONST uint8 * Buffer, uint32 Length);
	struct MidiDeviceData * APICALL (*OpenMidiDevice)(struct CamdIFace *Self, STRPTR Name);
	void APICALL (*CloseMidiDevice)(struct CamdIFace *Self, struct MidiDeviceData * MidiDeviceData);
	int32 APICALL (*RethinkCAMD)(struct CamdIFace *Self);
	void APICALL (*StartClusterNotify)(struct CamdIFace *Self, struct ClusterNotifyNode * cn);
	void APICALL (*EndClusterNotify)(struct CamdIFace *Self, struct ClusterNotifyNode * cn);
};

/**********************************************************************************************/

struct CapturedExpression
{
    struct CapturedExpression *
                          cape_Next;
    STRPTR                cape_Match;
    STRPTR                cape_Start;
    STRPTR                cape_End;
    APTR                  cape_Pool;   /* private */
};

/**********************************************************************************************/

struct CardIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct CardIFace *Self);
	ULONG APICALL (*Release)(struct CardIFace *Self);
	void APICALL (*Expunge)(struct CardIFace *Self);
	struct Interface * APICALL (*Clone)(struct CardIFace *Self);
	struct CardHandle * APICALL (*OwnCard)(struct CardIFace *Self, struct CardHandle * handle);
	VOID APICALL (*ReleaseCard)(struct CardIFace *Self, struct CardHandle * handle, ULONG flags);
	struct CardMemoryMap * APICALL (*GetCardMap)(struct CardIFace *Self);
	BOOL APICALL (*BeginCardAccess)(struct CardIFace *Self, struct CardHandle * handle);
	BOOL APICALL (*EndCardAccess)(struct CardIFace *Self, struct CardHandle * handle);
	UBYTE APICALL (*ReadCardStatus)(struct CardIFace *Self);
	BOOL APICALL (*CardResetRemove)(struct CardIFace *Self, struct CardHandle * handle, ULONG flag);
	UBYTE APICALL (*CardMiscControl)(struct CardIFace *Self, struct CardHandle * handle, UBYTE control_bits);
	ULONG APICALL (*CardAccessSpeed)(struct CardIFace *Self, struct CardHandle * handle, ULONG nanoseconds);
	LONG APICALL (*CardProgramVoltage)(struct CardIFace *Self, struct CardHandle * handle, ULONG voltage);
	BOOL APICALL (*CardResetCard)(struct CardIFace *Self, struct CardHandle * handle);
	BOOL APICALL (*CopyTuple)(struct CardIFace *Self, const struct CardHandle * handle, UBYTE * buffer, ULONG tuplecode, ULONG size);
	ULONG APICALL (*DeviceTuple)(struct CardIFace *Self, const UBYTE * tuple_data, struct DeviceTData * storage);
	struct Resident * APICALL (*IfAmigaXIP)(struct CardIFace *Self, const struct CardHandle * handle);
	BOOL APICALL (*CardForceChange)(struct CardIFace *Self);
	ULONG APICALL (*CardChangeCount)(struct CardIFace *Self);
	ULONG APICALL (*CardInterface)(struct CardIFace *Self);
};

/**********************************************************************************************/

struct CheckBoxIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct CheckBoxIFace *Self);
	ULONG APICALL (*Release)(struct CheckBoxIFace *Self);
	void APICALL (*Expunge)(struct CheckBoxIFace *Self);
	struct Interface * APICALL (*Clone)(struct CheckBoxIFace *Self);
	Class * APICALL (*CHECKBOX_GetClass)(struct CheckBoxIFace *Self);
};

/**********************************************************************************************/

struct ChooserIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ChooserIFace *Self);
	ULONG APICALL (*Release)(struct ChooserIFace *Self);
	void APICALL (*Expunge)(struct ChooserIFace *Self);
	struct Interface * APICALL (*Clone)(struct ChooserIFace *Self);
	Class * APICALL (*CHOOSER_GetClass)(struct ChooserIFace *Self);
	struct Node * APICALL (*AllocChooserNodeA)(struct ChooserIFace *Self, struct TagItem * tags);
	struct Node * APICALL (*AllocChooserNode)(struct ChooserIFace *Self, ...);
	VOID APICALL (*FreeChooserNode)(struct ChooserIFace *Self, struct Node * node);
	VOID APICALL (*SetChooserNodeAttrsA)(struct ChooserIFace *Self, struct Node * node, struct TagItem * tags);
	VOID APICALL (*SetChooserNodeAttrs)(struct ChooserIFace *Self, struct Node * node, ...);
	VOID APICALL (*GetChooserNodeAttrsA)(struct ChooserIFace *Self, struct Node * node, struct TagItem * tags);
	VOID APICALL (*GetChooserNodeAttrs)(struct ChooserIFace *Self, struct Node * node, ...);
};

/**********************************************************************************************/

struct CIAIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct CIAIFace *Self);
	ULONG APICALL (*Release)(struct CIAIFace *Self);
	void APICALL (*Expunge)(struct CIAIFace *Self);
	struct Interface * APICALL (*Clone)(struct CIAIFace *Self);
	struct Interrupt * APICALL (*AddICRVector)(struct CIAIFace *Self, struct Library * resource, WORD iCRBit, struct Interrupt * interrupt);
	VOID APICALL (*RemICRVector)(struct CIAIFace *Self, struct Library * resource, WORD iCRBit, struct Interrupt * interrupt);
	WORD APICALL (*AbleICR)(struct CIAIFace *Self, struct Library * resource, WORD mask);
	WORD APICALL (*SetICR)(struct CIAIFace *Self, struct Library * resource, WORD mask);
};

/**********************************************************************************************/

struct ClickTabIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct ClickTabIFace *Self);
	uint32 APICALL (*Release)(struct ClickTabIFace *Self);
	void APICALL (*Expunge)(struct ClickTabIFace *Self);
	struct Interface * APICALL (*Clone)(struct ClickTabIFace *Self);
	Class * APICALL (*CLICKTAB_GetClass)(struct ClickTabIFace *Self);
	struct Node * APICALL (*AllocClickTabNodeA)(struct ClickTabIFace *Self, struct TagItem * tags);
	struct Node * APICALL (*AllocClickTabNode)(struct ClickTabIFace *Self, ...);
	void APICALL (*FreeClickTabNode)(struct ClickTabIFace *Self, struct Node * node);
	int32 APICALL (*SetClickTabNodeAttrsA)(struct ClickTabIFace *Self, struct Node * node, struct TagItem * tags);
	int32 APICALL (*SetClickTabNodeAttrs)(struct ClickTabIFace *Self, struct Node * node, ...);
	int32 APICALL (*GetClickTabNodeAttrsA)(struct ClickTabIFace *Self, struct Node * node, struct TagItem * tags);
	int32 APICALL (*GetClickTabNodeAttrs)(struct ClickTabIFace *Self, struct Node * node, ...);
	void APICALL (*FreeClickTabList)(struct ClickTabIFace *Self, struct List * list);
};

/**********************************************************************************************/

struct ClusterNotifyNode
{
    struct MinNode  cnn_Node;		/* the usual node		*/
    struct Task	    *cnn_Task;		/* task to signal		*/
    int8	    cnn_SigBit;		/* sigbit to use		*/
    uint8	    pad[3];
};

/**********************************************************************************************/

struct cmLink
{
    uint32 cml_MethodID;
    uint32 cml_Action;
};

/**********************************************************************************************/

struct ColorWheelIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ColorWheelIFace *Self);
	ULONG APICALL (*Release)(struct ColorWheelIFace *Self);
	void APICALL (*Expunge)(struct ColorWheelIFace *Self);
	struct Interface * APICALL (*Clone)(struct ColorWheelIFace *Self);
	VOID APICALL (*ConvertHSBToRGB)(struct ColorWheelIFace *Self, struct ColorWheelHSB * hsb, struct ColorWheelRGB * rgb);
	VOID APICALL (*ConvertRGBToHSB)(struct ColorWheelIFace *Self, struct ColorWheelRGB * rgb, struct ColorWheelHSB * hsb);
};

/**********************************************************************************************/

struct CommoditiesIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct CommoditiesIFace *Self);
	uint32 APICALL (*Release)(struct CommoditiesIFace *Self);
	void APICALL (*Expunge)(struct CommoditiesIFace *Self);
	struct Interface * APICALL (*Clone)(struct CommoditiesIFace *Self);
	CxObj * APICALL (*CreateCxObj)(struct CommoditiesIFace *Self, uint32 type, int32 arg1, int32 arg2);
	CxObj * APICALL (*CxBroker)(struct CommoditiesIFace *Self, const struct NewBroker * nb, int32 * error);
	int32 APICALL (*ActivateCxObj)(struct CommoditiesIFace *Self, CxObj * co, int32 doIt);
	VOID APICALL (*DeleteCxObj)(struct CommoditiesIFace *Self, CxObj * co);
	VOID APICALL (*DeleteCxObjAll)(struct CommoditiesIFace *Self, CxObj * co);
	uint32 APICALL (*CxObjType)(struct CommoditiesIFace *Self, const CxObj * co);
	int32 APICALL (*CxObjError)(struct CommoditiesIFace *Self, const CxObj * co);
	VOID APICALL (*ClearCxObjError)(struct CommoditiesIFace *Self, CxObj * co);
	int32 APICALL (*SetCxObjPri)(struct CommoditiesIFace *Self, CxObj * co, int32 pri);
	VOID APICALL (*AttachCxObj)(struct CommoditiesIFace *Self, CxObj * headObj, CxObj * co);
	VOID APICALL (*EnqueueCxObj)(struct CommoditiesIFace *Self, CxObj * headObj, CxObj * co);
	VOID APICALL (*InsertCxObj)(struct CommoditiesIFace *Self, CxObj * headObj, CxObj * co, CxObj * pred);
	VOID APICALL (*RemoveCxObj)(struct CommoditiesIFace *Self, CxObj * co);
	VOID APICALL (*CxReserved0)(struct CommoditiesIFace *Self);
	VOID APICALL (*SetTranslate)(struct CommoditiesIFace *Self, CxObj * translator, struct InputEvent * events);
	VOID APICALL (*SetFilter)(struct CommoditiesIFace *Self, CxObj * filter, CONST_STRPTR text);
	VOID APICALL (*SetFilterIX)(struct CommoditiesIFace *Self, CxObj * filter, const IX * ix);
	int32 APICALL (*ParseIX)(struct CommoditiesIFace *Self, CONST_STRPTR description, IX * ix);
	uint32 APICALL (*CxMsgType)(struct CommoditiesIFace *Self, const CxMsg * cxm);
	APTR APICALL (*CxMsgData)(struct CommoditiesIFace *Self, const CxMsg * cxm);
	int32 APICALL (*CxMsgID)(struct CommoditiesIFace *Self, const CxMsg * cxm);
	VOID APICALL (*DivertCxMsg)(struct CommoditiesIFace *Self, CxMsg * cxm, CxObj * headObj, CxObj * returnObj);
	VOID APICALL (*RouteCxMsg)(struct CommoditiesIFace *Self, CxMsg * cxm, CxObj * co);
	VOID APICALL (*DisposeCxMsg)(struct CommoditiesIFace *Self, CxMsg * cxm);
	BOOL APICALL (*InvertKeyMap)(struct CommoditiesIFace *Self, uint32 ansiCode, struct InputEvent * event, const struct KeyMap * km);
	VOID APICALL (*AddIEvents)(struct CommoditiesIFace *Self, struct InputEvent * events);
	int32 APICALL (*CopyBrokerList)(struct CommoditiesIFace *Self, struct List * blist);
	VOID APICALL (*FreeBrokerList)(struct CommoditiesIFace *Self, struct List * list);
	int32 APICALL (*BrokerCommand)(struct CommoditiesIFace *Self, CONST_STRPTR name, int32 id);
	BOOL APICALL (*MatchIX)(struct CommoditiesIFace *Self, const struct InputEvent * event, const IX * ix);
};

/**********************************************************************************************/

struct ConsoleIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ConsoleIFace *Self);
	ULONG APICALL (*Release)(struct ConsoleIFace *Self);
	void APICALL (*Expunge)(struct ConsoleIFace *Self);
	struct Interface * APICALL (*Clone)(struct ConsoleIFace *Self);
	struct InputEvent * APICALL (*CDInputHandler)(struct ConsoleIFace *Self, const struct InputEvent * events, struct Library * consoleDevice);
	LONG APICALL (*RawKeyConvert)(struct ConsoleIFace *Self, const struct InputEvent * events, STRPTR buffer, LONG length, const struct KeyMap * keyMap);
	STRPTR APICALL (*GetConSnip)(struct ConsoleIFace *Self);
	BOOL APICALL (*SetConSnip)(struct ConsoleIFace *Self, STRPTR snip);
	VOID APICALL (*AddConSnipHook)(struct ConsoleIFace *Self, struct Hook * hook);
	VOID APICALL (*RemConSnipHook)(struct ConsoleIFace *Self, struct Hook * hook);
};

/**********************************************************************************************/

struct ConsoleKeyMapPointers
{
    APTR               keymapHandle;
    struct KeyMapNode *keymapNode;
    struct KeyMap     *keymap;
    APTR               reserved; /* Must be set to NULL
                                  * for CD_SETKEYMAP_POINTERS */
};

/**********************************************************************************************/

struct ConsoleWindowData
{
    uint32          Reserved[4];   /* For use by the console handler */
    struct Window * ConsoleWindow; /* Pointer to console window; this
                                      may be NULL for console handlers
                                      which are not bound to a window,
                                      or if that window is currently
                                      closed. */
    struct IORequest * ConsoleIO;  /* Pointer to console.device I/O
                                      request; this may be NULL for
                                      console handlers which are not
                                      bound to a window, or if that
                                      window is currently closed. */
    uint32          ConsoleType;   /* Identifies the type of console,
                                      e.g. ID_RAWCON or ID_CON */

    APTR            DOSPrivate[2]; /* Private fields for use by DOS only */
};

/**********************************************************************************************/

struct CW3FloppyIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct CW3FloppyIFace *Self);
	ULONG APICALL (*Release)(struct CW3FloppyIFace *Self);
	void APICALL (*Expunge)(struct CW3FloppyIFace *Self);
	struct Interface * APICALL (*Clone)(struct CW3FloppyIFace *Self);
	UBYTE APICALL (*InByte)(struct CW3FloppyIFace *Self, ULONG offset);
	void APICALL (*OutByte)(struct CW3FloppyIFace *Self, ULONG offset, UBYTE value);
};

/**********************************************************************************************/

struct CW3GameportIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct CW3GameportIFace *Self);
	ULONG APICALL (*Release)(struct CW3GameportIFace *Self);
	void APICALL (*Expunge)(struct CW3GameportIFace *Self);
	struct Interface * APICALL (*Clone)(struct CW3GameportIFace *Self);
	UBYTE APICALL (*InByte)(struct CW3GameportIFace *Self, ULONG offset);
	void APICALL (*OutByte)(struct CW3GameportIFace *Self, ULONG offset, UBYTE value);
};

/**********************************************************************************************/

struct CW3KeyboardIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct CW3KeyboardIFace *Self);
	ULONG APICALL (*Release)(struct CW3KeyboardIFace *Self);
	void APICALL (*Expunge)(struct CW3KeyboardIFace *Self);
	struct Interface * APICALL (*Clone)(struct CW3KeyboardIFace *Self);
	UBYTE APICALL (*InByte)(struct CW3KeyboardIFace *Self, ULONG offset);
	void APICALL (*OutByte)(struct CW3KeyboardIFace *Self, ULONG offset, UBYTE value);
};

/**********************************************************************************************/

struct CW3SIDIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct CW3SIDIFace *Self);
	ULONG APICALL (*Release)(struct CW3SIDIFace *Self);
	void APICALL (*Expunge)(struct CW3SIDIFace *Self);
	struct Interface * APICALL (*Clone)(struct CW3SIDIFace *Self);
	UBYTE APICALL (*InByte)(struct CW3SIDIFace *Self, ULONG offset);
	void APICALL (*OutByte)(struct CW3SIDIFace *Self, ULONG offset, UBYTE value);
};

/**********************************************************************************************/

struct CWIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct CWIFace *Self);
	ULONG APICALL (*Release)(struct CWIFace *Self);
	void APICALL (*Expunge)(struct CWIFace *Self);
	struct Interface * APICALL (*Clone)(struct CWIFace *Self);
	BOOL APICALL (*CW3Present)(struct CWIFace *Self);
	BOOL APICALL (*CW4Present)(struct CWIFace *Self);
	BOOL APICALL (*CW3GameportAvail)(struct CWIFace *Self);
	BOOL APICALL (*CW3KeyboardAvail)(struct CWIFace *Self);
	BOOL APICALL (*CW3SIDAvail)(struct CWIFace *Self);
	BOOL APICALL (*CW3FloppyAvail)(struct CWIFace *Self);
};

/**********************************************************************************************/

struct CxBrokerCopy
{
    struct Node   Node;        // Embedded Node
    uint32        StructSize;  // Size of this structure
    struct Task  *Owner;       // Task which created the broker
    CONST_STRPTR  Name;        // Name of the broker
    CONST_STRPTR  Title;       // Title of the broker
    CONST_STRPTR  Description; // Short broker description
    uint32        Flags;       // See COF prefixed flags above
};

/**********************************************************************************************/

struct CyberGfxIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct CyberGfxIFace *Self);
	ULONG APICALL (*Release)(struct CyberGfxIFace *Self);
	void APICALL (*Expunge)(struct CyberGfxIFace *Self);
	struct Interface * APICALL (*Clone)(struct CyberGfxIFace *Self);
	void APICALL (*Reserved1)(struct CyberGfxIFace *Self);
	void APICALL (*Reserved2)(struct CyberGfxIFace *Self);
	void APICALL (*Reserved3)(struct CyberGfxIFace *Self);
	void APICALL (*Reserved4)(struct CyberGfxIFace *Self);
	BOOL APICALL (*IsCyberModeID)(struct CyberGfxIFace *Self, ULONG displayID);
	ULONG APICALL (*BestCModeIDTagList)(struct CyberGfxIFace *Self, struct TagItem * BestModeIDTags);
	ULONG APICALL (*BestCModeIDTags)(struct CyberGfxIFace *Self, ...);
	ULONG APICALL (*CModeRequestTagList)(struct CyberGfxIFace *Self, APTR ModeRequest, struct TagItem * ModeRequestTags);
	ULONG APICALL (*CModeRequestTags)(struct CyberGfxIFace *Self, APTR ModeRequest, ...);
	struct List * APICALL (*AllocCModeListTagList)(struct CyberGfxIFace *Self, struct TagItem * ModeListTags);
	struct List * APICALL (*AllocCModeListTags)(struct CyberGfxIFace *Self, ...);
	void APICALL (*FreeCModeList)(struct CyberGfxIFace *Self, struct List * ModeList);
	void APICALL (*Reserved5)(struct CyberGfxIFace *Self);
	LONG APICALL (*ScalePixelArray)(struct CyberGfxIFace *Self, APTR srcRect, UWORD SrcW, UWORD SrcH, UWORD SrcMod, struct RastPort * a1arg, WORD DestX, WORD DestY, UWORD DestW, UWORD DestH, UBYTE SrcFormat);
	ULONG APICALL (*GetCyberMapAttr)(struct CyberGfxIFace *Self, struct BitMap * CyberGfxBitmap, ULONG CyberAttrTag);
	ULONG APICALL (*GetCyberIDAttr)(struct CyberGfxIFace *Self, ULONG CyberIDAttr, ULONG CyberDisplayModeID);
	ULONG APICALL (*ReadRGBPixel)(struct CyberGfxIFace *Self, struct RastPort * a1arg, WORD x, WORD y);
	LONG APICALL (*WriteRGBPixel)(struct CyberGfxIFace *Self, struct RastPort * a1arg, WORD x, WORD y, ULONG argb);
	ULONG APICALL (*ReadPixelArray)(struct CyberGfxIFace *Self, APTR destRect, WORD destX, WORD destY, UWORD destMod, struct RastPort * a1arg, WORD SrcX, WORD SrcY, UWORD SizeX, UWORD SizeY, UBYTE DestFormat);
	ULONG APICALL (*WritePixelArray)(struct CyberGfxIFace *Self, APTR srcRect, WORD SrcX, WORD SrcY, UWORD SrcMod, struct RastPort * a1arg, WORD DestX, WORD DestY, UWORD SizeX, UWORD SizeY, UBYTE SrcFormat);
	ULONG APICALL (*MovePixelArray)(struct CyberGfxIFace *Self, WORD SrcX, WORD SrcY, struct RastPort * a1arg, WORD DestX, WORD DestY, UWORD SizeX, UWORD SizeY);
	void APICALL (*Reserved6)(struct CyberGfxIFace *Self);
	ULONG APICALL (*InvertPixelArray)(struct CyberGfxIFace *Self, struct RastPort * a1arg, WORD DestX, WORD DestY, UWORD SizeX, UWORD SizeY);
	ULONG APICALL (*FillPixelArray)(struct CyberGfxIFace *Self, struct RastPort * a1arg, WORD DestX, WORD DestY, UWORD SizeX, UWORD SizeY, ULONG ARGB);
	void APICALL (*DoCDrawMethodTagList)(struct CyberGfxIFace *Self, struct Hook * Hook, struct RastPort * a1arg, struct TagItem * TagList);
	void APICALL (*DoCDrawMethodTags)(struct CyberGfxIFace *Self, struct Hook * Hook, struct RastPort * a1arg, ...);
	void APICALL (*CVideoCtrlTagList)(struct CyberGfxIFace *Self, struct ViewPort * ViewPort, struct TagItem * TagList);
	void APICALL (*CVideoCtrlTags)(struct CyberGfxIFace *Self, struct ViewPort * ViewPort, ...);
	APTR APICALL (*LockBitMapTagList)(struct CyberGfxIFace *Self, APTR BitMap, struct TagItem * TagList);
	APTR APICALL (*LockBitMapTags)(struct CyberGfxIFace *Self, APTR BitMap, ...);
	void APICALL (*UnLockBitMap)(struct CyberGfxIFace *Self, APTR Handle);
	void APICALL (*UnLockBitMapTagList)(struct CyberGfxIFace *Self, APTR Handle, struct TagItem * TagList);
	void APICALL (*UnLockBitMapTags)(struct CyberGfxIFace *Self, APTR Handle, ...);
	ULONG APICALL (*ExtractColor)(struct CyberGfxIFace *Self, struct RastPort * a0arg, struct BitMap * BitMap, ULONG Colour, ULONG SrcX, ULONG SrcY, ULONG Width, ULONG Height);
	void APICALL (*Reserved7)(struct CyberGfxIFace *Self);
	ULONG APICALL (*WriteLUTPixelArray)(struct CyberGfxIFace *Self, APTR srcRect, WORD SrcX, WORD SrcY, UWORD SrcMod, struct RastPort * a1arg, APTR ColorTab, WORD DestX, WORD DestY, UWORD SizeX, UWORD SizeY, UBYTE CTFormat);
	void APICALL (*Reserved8)(struct CyberGfxIFace *Self);
	void APICALL (*Reserved9)(struct CyberGfxIFace *Self);
	ULONG APICALL (*WritePixelArrayAlpha)(struct CyberGfxIFace *Self, APTR srcRect, WORD SrcX, WORD SrcY, WORD SrcMod, struct RastPort * rp, WORD DestX, WORD DestY, UWORD SizeX, UWORD SizeY, ULONG globalAlpha);
	VOID APICALL (*BltTemplateAlpha)(struct CyberGfxIFace *Self, APTR srcTemplate, WORD SrcX, WORD SrcY, struct RastPort * rp, WORD DestX, WORD DestY, UWORD SizeX, UWORD SizeY);
};

/**********************************************************************************************/

struct DataTypesIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct DataTypesIFace *Self);
	ULONG APICALL (*Release)(struct DataTypesIFace *Self);
	void APICALL (*Expunge)(struct DataTypesIFace *Self);
	struct Interface * APICALL (*Clone)(struct DataTypesIFace *Self);
	LONG APICALL (*RLDispatch)(struct DataTypesIFace *Self, struct RexxMsg * rmsg, STRPTR * result);
	struct DataType * APICALL (*ObtainDataTypeA)(struct DataTypesIFace *Self, ULONG type, APTR handle, CONST struct TagItem * attrs);
	struct DataType * APICALL (*ObtainDataType)(struct DataTypesIFace *Self, ULONG type, APTR handle, ...);
	VOID APICALL (*ReleaseDataType)(struct DataTypesIFace *Self, struct DataType * dt);
	Object * APICALL (*NewDTObjectA)(struct DataTypesIFace *Self, CONST_STRPTR name, CONST struct TagItem * attrs);
	Object * APICALL (*NewDTObject)(struct DataTypesIFace *Self, CONST_STRPTR name, ...);
	VOID APICALL (*DisposeDTObject)(struct DataTypesIFace *Self, Object * o);
	ULONG APICALL (*SetDTAttrsA)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, CONST struct TagItem * attrs);
	ULONG APICALL (*SetDTAttrs)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, ...);
	ULONG APICALL (*GetDTAttrsA)(struct DataTypesIFace *Self, Object * o, CONST struct TagItem * attrs);
	ULONG APICALL (*GetDTAttrs)(struct DataTypesIFace *Self, Object * o, ...);
	LONG APICALL (*AddDTObject)(struct DataTypesIFace *Self, struct Window * win, struct Requester * req, Object * o, LONG pos);
	VOID APICALL (*RefreshDTObjectA)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, CONST struct TagItem * attrs);
	VOID APICALL (*RefreshDTObjects)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, ...);
	VOID APICALL (*RefreshDTObject)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, ...);
	ULONG APICALL (*DoAsyncLayout)(struct DataTypesIFace *Self, Object * o, struct gpLayout * gpl);
	ULONG APICALL (*DoDTMethodA)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, Msg msg);
	ULONG APICALL (*DoDTMethod)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, ...);
	LONG APICALL (*RemoveDTObject)(struct DataTypesIFace *Self, struct Window * win, Object * o);
	ULONG * APICALL (*GetDTMethods)(struct DataTypesIFace *Self, Object * object);
	struct DTMethod * APICALL (*GetDTTriggerMethods)(struct DataTypesIFace *Self, Object * object);
	ULONG APICALL (*PrintDTObjectA)(struct DataTypesIFace *Self, Object * o, struct Window * w, struct Requester * r, struct dtPrint * msg);
	ULONG APICALL (*PrintDTObject)(struct DataTypesIFace *Self, Object * o, struct Window * w, struct Requester * r, ...);
	APTR APICALL (*ObtainDTDrawInfoA)(struct DataTypesIFace *Self, Object * o, CONST struct TagItem * attrs);
	APTR APICALL (*ObtainDTDrawInfo)(struct DataTypesIFace *Self, Object * o, ...);
	LONG APICALL (*DrawDTObjectA)(struct DataTypesIFace *Self, struct RastPort * rp, Object * o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, CONST struct TagItem * attrs);
	LONG APICALL (*DrawDTObject)(struct DataTypesIFace *Self, struct RastPort * rp, Object * o, LONG x, LONG y, LONG w, LONG h, LONG th, LONG tv, ...);
	VOID APICALL (*ReleaseDTDrawInfo)(struct DataTypesIFace *Self, Object * o, APTR handle);
	CONST_STRPTR APICALL (*GetDTString)(struct DataTypesIFace *Self, ULONG id);
	void APICALL (*Reserved1)(struct DataTypesIFace *Self);
	void APICALL (*Reserved2)(struct DataTypesIFace *Self);
	void APICALL (*Reserved3)(struct DataTypesIFace *Self);
	void APICALL (*Reserved4)(struct DataTypesIFace *Self);
	void APICALL (*Reserved5)(struct DataTypesIFace *Self);
	void APICALL (*Reserved6)(struct DataTypesIFace *Self);
	void APICALL (*Reserved7)(struct DataTypesIFace *Self);
	void APICALL (*Reserved8)(struct DataTypesIFace *Self);
	void APICALL (*Reserved9)(struct DataTypesIFace *Self);
	void APICALL (*Reserved10)(struct DataTypesIFace *Self);
	void APICALL (*Reserved11)(struct DataTypesIFace *Self);
	void APICALL (*Reserved12)(struct DataTypesIFace *Self);
	ULONG APICALL (*SaveDTObject)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, CONST_STRPTR file, ULONG mode, BOOL saveicon, ...);
	ULONG APICALL (*DoDTDomain)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, struct RastPort * rport, ULONG which, struct IBox * domain, ...);
	struct ToolNode * APICALL (*FindToolNode)(struct DataTypesIFace *Self, struct List * tl, ...);
	ULONG APICALL (*LaunchTool)(struct DataTypesIFace *Self, struct Tool * t, CONST_STRPTR project, ...);
	VOID APICALL (*LockDataType)(struct DataTypesIFace *Self, struct DataType * dt);
	struct ToolNode * APICALL (*FindToolNodeA)(struct DataTypesIFace *Self, struct List * tl, CONST struct TagItem * attrs);
	ULONG APICALL (*LaunchToolA)(struct DataTypesIFace *Self, struct Tool * t, CONST_STRPTR project, CONST struct TagItem * attrs);
	ULONG * APICALL (*FindMethod)(struct DataTypesIFace *Self, ULONG * methods, ULONG searchmethodid);
	struct DTMethod * APICALL (*FindTriggerMethod)(struct DataTypesIFace *Self, struct DTMethod * dtm, CONST_STRPTR command, ULONG method);
	ULONG * APICALL (*CopyDTMethods)(struct DataTypesIFace *Self, ULONG * methods, ULONG * include, ULONG * exclude);
	struct DTMethod * APICALL (*CopyDTTriggerMethods)(struct DataTypesIFace *Self, struct DTMethod * methods, struct DTMethod * include, struct DTMethod * exclude);
	VOID APICALL (*FreeDTMethods)(struct DataTypesIFace *Self, APTR methods);
	ULONG APICALL (*GetDTTriggerMethodDataFlags)(struct DataTypesIFace *Self, ULONG triggermethod);
	ULONG APICALL (*SaveDTObjectA)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, CONST_STRPTR file, ULONG mode, BOOL saveicon, CONST struct TagItem * attrs);
	ULONG APICALL (*StartDragSelect)(struct DataTypesIFace *Self, Object * o);
	ULONG APICALL (*DoDTDomainA)(struct DataTypesIFace *Self, Object * o, struct Window * win, struct Requester * req, struct RastPort * rport, ULONG which, struct IBox * domain, CONST struct TagItem * attrs);
	ULONG APICALL (*datatypesPrivate001)(struct DataTypesIFace *Self);
	ULONG APICALL (*datatypesPrivate002)(struct DataTypesIFace *Self);
};

/**********************************************************************************************/

struct DateBrowserIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct DateBrowserIFace *Self);
	ULONG APICALL (*Release)(struct DateBrowserIFace *Self);
	void APICALL (*Expunge)(struct DateBrowserIFace *Self);
	struct Interface * APICALL (*Clone)(struct DateBrowserIFace *Self);
	Class * APICALL (*DATEBROWSER_GetClass)(struct DateBrowserIFace *Self);
	UWORD APICALL (*JulianWeekDay)(struct DateBrowserIFace *Self, UWORD day, UWORD month, LONG year);
	UWORD APICALL (*JulianMonthDays)(struct DateBrowserIFace *Self, UWORD month, LONG year);
	BOOL APICALL (*JulianLeapYear)(struct DateBrowserIFace *Self, LONG year);
};

/**********************************************************************************************/

struct DeathMessage
{
    struct Message dm_Msg;    /* Embedded exec message structure.           */
    int32  dm_ReturnCode;     /* Primary process return code, set by DOS    */
    int32  dm_Result2;        /* The value returned from IoErr(),set by DOS */
};

/**********************************************************************************************/

struct DebugIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct DebugIFace *Self);
	ULONG APICALL (*Release)(struct DebugIFace *Self);
	void APICALL (*Expunge)(struct DebugIFace *Self);
	struct Interface * APICALL (*Clone)(struct DebugIFace *Self);
	BOOL APICALL (*AddDebugHook)(struct DebugIFace *Self, struct Task * task, struct Hook * debugHook);
	APTR APICALL (*DisassembleNative)(struct DebugIFace *Self, APTR targetAddress, STRPTR opcodeName, STRPTR operands);
	APTR APICALL (*Disassemble68k)(struct DebugIFace *Self, APTR targetAddress, STRPTR opcodeName, STRPTR operands);
	uint32 APICALL (*GetDebugLevel)(struct DebugIFace *Self);
	uint32 APICALL (*ReadTaskContext)(struct DebugIFace *Self, struct Task * targetTask, struct ExceptionContext * contextStore, uint32 flags);
	uint32 APICALL (*WriteTaskContext)(struct DebugIFace *Self, struct Task * targetTask, struct ExceptionContext * contextStore, uint32 flags);
	int32 APICALL (*StackTrace)(struct DebugIFace *Self, struct Task * task, struct Hook * hook);
	struct DebugSymbol * APICALL (*ObtainDebugSymbol)(struct DebugIFace *Self, CONST_APTR address, struct TagItem * tagList);
	struct DebugSymbol * APICALL (*ObtainDebugSymbolTags)(struct DebugIFace *Self, CONST_APTR address, ...);
	void APICALL (*ReleaseDebugSymbol)(struct DebugIFace *Self, struct DebugSymbol * sym);
};

/**********************************************************************************************/

struct DebugSymbol
{
    uint32 StructSize;               // Size of the data structure
    uint32 Type;                     // Type of debug symbol

    CONST_STRPTR Name;               // Module name (may be NULL)
    uint32 Offset;                   // Offset into the module
    uint32 SegmentNumber;            // DOS segment number
    uint32 SegmentOffset;            // DOS segment offset

    CONST_STRPTR SourceFileName;     // Source code file name (may be NULL)
    uint32 SourceLineNumber;         // Source code line number (may be zero)
    CONST_STRPTR SourceFunctionName; // Source code function name (may be NULL)
    CONST_STRPTR SourceBaseName;     // Source code base name (may be NULL)
};

/**********************************************************************************************/

struct DeviceManagerInterface
{
    struct InterfaceData Data;

    uint32             APICALL (*Obtain) (struct DeviceManagerInterface *Self);
    uint32             APICALL (*Release)(struct DeviceManagerInterface *Self);
    VOID               APICALL (*Expunge)(struct DeviceManagerInterface *Self);
    struct Interface * APICALL (*Clone)  (struct DeviceManagerInterface *Self);

    /* the return value from Open() must be placed in ior->io_Error. In earlier
     * releases of this include the function was returning an int32 which was/is
     * wrong.
     */
    VOID               APICALL (*Open)        (struct DeviceManagerInterface *Self,
                                               struct IORequest *ior, uint32 unit,
                                               uint32 flags);
    APTR               APICALL (*Close)       (struct DeviceManagerInterface *Self,
                                               struct IORequest *ior);
    APTR               APICALL (*LibExpunge)  (struct DeviceManagerInterface *Self);
    struct Interface * APICALL (*GetInterface)(struct DeviceManagerInterface *Self,
                                               STRPTR name, uint32 version,
                                               struct TagItem *taglist);

    VOID               APICALL (*BeginIO)     (struct DeviceManagerInterface *Self,
                                               struct IORequest *ior);
    VOID               APICALL (*AbortIO)     (struct DeviceManagerInterface *Self,
                                               struct IORequest *ior);
};

/**********************************************************************************************/

struct DiskfontIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct DiskfontIFace *Self);
	ULONG APICALL (*Release)(struct DiskfontIFace *Self);
	void APICALL (*Expunge)(struct DiskfontIFace *Self);
	struct Interface * APICALL (*Clone)(struct DiskfontIFace *Self);
	struct TextFont * APICALL (*OpenDiskFont)(struct DiskfontIFace *Self, const struct TextAttr * textAttr);
	LONG APICALL (*AvailFonts)(struct DiskfontIFace *Self, STRPTR buffer, LONG bufBytes, ULONG flags);
	struct FontContentsHeader * APICALL (*NewFontContents)(struct DiskfontIFace *Self, BPTR fontsLock, CONST_STRPTR fontName);
	VOID APICALL (*DisposeFontContents)(struct DiskfontIFace *Self, struct FontContentsHeader * fontContentsHeader);
	struct DiskFontHeader * APICALL (*NewScaledDiskFont)(struct DiskfontIFace *Self, struct TextFont * sourceFont, struct TextAttr * destTextAttr);
	LONG APICALL (*GetDiskFontCtrl)(struct DiskfontIFace *Self, LONG tagid);
	VOID APICALL (*SetDiskFontCtrlA)(struct DiskfontIFace *Self, const struct TagItem * taglist);
	VOID APICALL (*SetDiskFontCtrl)(struct DiskfontIFace *Self, ...);
	LONG APICALL (*EOpenEngine)(struct DiskfontIFace *Self, struct EGlyphEngine * EEngine);
	VOID APICALL (*ECloseEngine)(struct DiskfontIFace *Self, struct EGlyphEngine * EEngine);
	ULONG APICALL (*ESetInfoA)(struct DiskfontIFace *Self, struct EGlyphEngine * EEngine, const struct TagItem * taglist);
	ULONG APICALL (*ESetInfo)(struct DiskfontIFace *Self, struct EGlyphEngine * EEngine, ...);
	ULONG APICALL (*EObtainInfoA)(struct DiskfontIFace *Self, struct EGlyphEngine * EEngine, const struct TagItem * taglist);
	ULONG APICALL (*EObtainInfo)(struct DiskfontIFace *Self, struct EGlyphEngine * EEngine, ...);
	ULONG APICALL (*EReleaseInfoA)(struct DiskfontIFace *Self, struct EGlyphEngine * EEngine, const struct TagItem * taglist);
	ULONG APICALL (*EReleaseInfo)(struct DiskfontIFace *Self, struct EGlyphEngine * EEngine, ...);
	struct OutlineFont * APICALL (*OpenOutlineFont)(struct DiskfontIFace *Self, CONST_STRPTR name, struct List * list, ULONG flags);
	VOID APICALL (*CloseOutlineFont)(struct DiskfontIFace *Self, struct OutlineFont * olf, struct List * list);
	LONG APICALL (*WriteFontContents)(struct DiskfontIFace *Self, BPTR fontsLock, CONST_STRPTR fontName, struct FontContentsHeader * fontContentsHeader);
	LONG APICALL (*WriteDiskFontHeaderA)(struct DiskfontIFace *Self, struct TextFont * font, CONST_STRPTR fileName, const struct TagItem * taglist);
	LONG APICALL (*WriteDiskFontHeader)(struct DiskfontIFace *Self, struct TextFont * font, CONST_STRPTR fileName, ...);
	ULONG APICALL (*ObtainCharsetInfo)(struct DiskfontIFace *Self, ULONG knownTag, ULONG knownValue, ULONG wantedTag);
	struct TTextAttr * APICALL (*ObtainTTextAttr)(struct DiskfontIFace *Self, struct TextFont * textFont);
	VOID APICALL (*FreeTTextAttr)(struct DiskfontIFace *Self, struct TTextAttr * tta);
};

/**********************************************************************************************/

struct DMAEntry
{
    APTR   PhysicalAddress; /* Physically mapped address */
    uint32 BlockLength;     /* Length of the block in physical memory */
};

/**********************************************************************************************/

struct DockyAbsPosition
{
	struct DockyPosition absPos;
	struct DockyPosition dockyPos;
};

/**********************************************************************************************/

struct DockyAttention
{
	struct Task *amidockTask;
	BYTE attentionSignalBit;
};

/**********************************************************************************************/

struct DockyCategoryInfo
{
	struct DockyCategoryNr cat;
	STRPTR categoryName;
};

/**********************************************************************************************/

struct DockyCategoryMove
{
	int32 dockNr;
	int32 oldCategoryNr;
	int32 newCategoryNr;
};

/**********************************************************************************************/

struct DockyCategoryNr
{
	int32 dockNr;
	int32 categoryNr;
};

/**********************************************************************************************/

struct DockyDebug
{
	struct DockyObjectNr obj;
	STRPTR dockyName;
	uint32 mode;

	uint32 turnCount;
	uint32 msgType;
	uint32 msgData;
	BOOL anotherTurn;

	STRPTR message;
};

/**********************************************************************************************/

struct DockyDockBackground
{
	int32 dockNr;
	STRPTR imagePath;
};

/**********************************************************************************************/

struct DockyDockFont
{
	int32 dockNr;
	struct TextAttr *ta;
	uint8 frontPen;
	uint8 backPen;
	uint8 drawMode;
};

/**********************************************************************************************/

struct DockyDockInfo
{
	int32 dockNr;
	STRPTR dockName;
};

/**********************************************************************************************/

struct DockyDockMove
{
	int32 oldDockNr;
	int32 newDockNr;
};

/**********************************************************************************************/

struct DockyDockPosition
{
	int32 dockNr;
	struct DockyPosition pos;
};

/**********************************************************************************************/

struct DockyDockSize
{
	struct DockyCategoryNr cat;
	struct DockySize size;
};

/**********************************************************************************************/

struct DockyDockState
{
	int32 dockNr;
	int32 state;
};

/**********************************************************************************************/

struct DockyDockType
{
	int32 dockNr;
	uint32 dockType; // enum enAmiDockDockType
};

/**********************************************************************************************/

struct DockyDockyDND
{
	struct DockyPosition pos;
	STRPTR objectPath;
};

/**********************************************************************************************/

struct DockyIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct DockyIFace *Self);
	uint32 APICALL (*Release)(struct DockyIFace *Self);
	void APICALL (*Expunge)(struct DockyIFace *Self);
	struct DockyIFace * APICALL (*Clone)(struct DockyIFace *Self);
	BOOL APICALL (*DockyGet)(struct DockyIFace *Self, uint32 msgType, uint32 * msgData);
	BOOL APICALL (*DockySet)(struct DockyIFace *Self, uint32 msgType, uint32 msgData);
	BOOL APICALL (*DockyProcess)(struct DockyIFace *Self, uint32 turnCount, uint32 * msgType, uint32 * msgData, BOOL * anotherTurn);
};

/**********************************************************************************************/

struct DockyObjectClick
{
	struct DockyObjectNr obj;
	STRPTR objectPath;
};

/**********************************************************************************************/

struct DockyObjectDND
{
	struct DockyObjectNr obj;
	STRPTR objectPath;
};

/**********************************************************************************************/

struct DockyObjectInfo
{
	struct DockyObjectNr obj;
	STRPTR objectPath;
	STRPTR objectName; // ignored on insert!
	STRPTR objectIcon; // 53.1
};

/**********************************************************************************************/

struct DockyObjectMove
{
	struct DockyCategoryNr cat;
	int32 oldObjectNr;
	int32 newObjectNr;
};

/**********************************************************************************************/

struct DockyObjectNr
{
	int32 dockNr;
	int32 categoryNr;
	int32 objectNr;
};

/**********************************************************************************************/

struct DockyPosition
{
	int32 x, y;
};

/**********************************************************************************************/

struct DockyPosSize
{
	struct DockyPosition pos;
	struct DockySize size;
};

/**********************************************************************************************/

struct DockyRenderDestination
{
	uint32 renderMode; // enum enDockyRenderMode
	struct DockySize renderSize;

	UBYTE pad[4]; // for future extension

	union
	{
		UBYTE *map; // currently unused
		struct RastPort *RP; // RP->BitMap is of type RGBFB_ALPHA8
	} alpha;

	union
	{
		UBYTE *RGB;
		struct RastPort *RP;
	} render;
};

/**********************************************************************************************/

struct DockyRunWB
{
	STRPTR fileName; // program or directory
	STRPTR argument; // additional argument for a program
};

/**********************************************************************************************/

struct DockySize
{
	int32 width, height;
};

/**********************************************************************************************/

struct DockyUnHideAnim
{
	int32 dockNr;
	int32 fromX, fromY;
};

/**********************************************************************************************/

struct DosEventMsg
{
    struct Message  MN;           /* message struct */
    struct TimeVal  TV;           /* Time stamp when event message was sent  */
    CONST_STRPTR    FuncName;     /* DOS function name called to cause event */
    uint32          ProcessID;    /* PID (ProcessID) that caused the event   */
    CONST_STRPTR    TaskName;     /* Name of the task that caused the event  */
    struct MsgPort *MsgPort;      /* filesystem message port for the object  */
    int32           NHM_Action;   /* NHM_Action flags used for notify hooks  */
    CONST_STRPTR    FullName;     /* full device-centric path & object name. */
    uint32          Reserved[4];  /* reserved fields for dos expansion.      */
};

/**********************************************************************************************/

struct DOSIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct DOSIFace *Self);
	ULONG APICALL (*Release)(struct DOSIFace *Self);
	void APICALL (*Expunge)(struct DOSIFace *Self);
	struct Interface * APICALL (*Clone)(struct DOSIFace *Self);
	BPTR APICALL (*Open)(struct DOSIFace *Self, CONST_STRPTR name, LONG accessMode);
	LONG APICALL (*Close)(struct DOSIFace *Self, BPTR file);
	LONG APICALL (*Read)(struct DOSIFace *Self, BPTR file, APTR buffer, LONG length);
	LONG APICALL (*Write)(struct DOSIFace *Self, BPTR file, CONST_APTR buffer, LONG length);
	BPTR APICALL (*Input)(struct DOSIFace *Self);
	BPTR APICALL (*Output)(struct DOSIFace *Self);
	DEPRECATED LONG APICALL (*Seek)(struct DOSIFace *Self, BPTR file, LONG position, LONG offset);
	LONG APICALL (*Delete)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*Rename)(struct DOSIFace *Self, CONST_STRPTR oldName, CONST_STRPTR newName);
	BPTR APICALL (*Lock)(struct DOSIFace *Self, CONST_STRPTR name, LONG type);
	VOID APICALL (*UnLock)(struct DOSIFace *Self, BPTR lock);
	BPTR APICALL (*DupLock)(struct DOSIFace *Self, BPTR lock);
	DEPRECATED LONG APICALL (*Examine)(struct DOSIFace *Self, BPTR lock, struct FileInfoBlock * fileInfoBlock);
	DEPRECATED LONG APICALL (*ExNext)(struct DOSIFace *Self, BPTR lock, struct FileInfoBlock * fileInfoBlock);
	LONG APICALL (*Info)(struct DOSIFace *Self, BPTR lock, struct InfoData * parameterBlock);
	BPTR APICALL (*CreateDir)(struct DOSIFace *Self, CONST_STRPTR name);
	BPTR APICALL (*CurrentDir)(struct DOSIFace *Self, BPTR lock);
	LONG APICALL (*IoErr)(struct DOSIFace *Self);
	DEPRECATED struct MsgPort * APICALL (*CreateProc)(struct DOSIFace *Self, CONST_STRPTR name, LONG pri, BPTR segList, LONG stackSize);
	DEPRECATED VOID APICALL (*OBSOLETEExit)(struct DOSIFace *Self, LONG returnCode);
	DEPRECATED BPTR APICALL (*OBSOLETELoadSeg)(struct DOSIFace *Self, CONST_STRPTR name, BPTR hunktab, BPTR stream);
	LONG APICALL (*UnLoadSeg)(struct DOSIFace *Self, BPTR seglist);
	int32 APICALL (*PRIVATEDoPkt32)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4, LONG arg5, LONG arg6, LONG arg7);
	BPTR APICALL (*LoadSeg)(struct DOSIFace *Self, CONST_STRPTR name);
	DEPRECATED struct MsgPort * APICALL (*DeviceProc)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*SetComment)(struct DOSIFace *Self, CONST_STRPTR name, CONST_STRPTR comment);
	LONG APICALL (*SetProtection)(struct DOSIFace *Self, CONST_STRPTR name, ULONG protect);
	struct DateStamp * APICALL (*DateStamp)(struct DOSIFace *Self, struct DateStamp * date);
	VOID APICALL (*Delay)(struct DOSIFace *Self, LONG timeout);
	LONG APICALL (*WaitForChar)(struct DOSIFace *Self, BPTR file, LONG timeout);
	BPTR APICALL (*ParentDir)(struct DOSIFace *Self, BPTR lock);
	LONG APICALL (*IsInteractive)(struct DOSIFace *Self, BPTR file);
	DEPRECATED LONG APICALL (*Execute)(struct DOSIFace *Self, CONST_STRPTR string, BPTR file, BPTR file2);
	APTR APICALL (*AllocDosObject)(struct DOSIFace *Self, ULONG type, const struct TagItem * tags);
	APTR APICALL (*AllocDosObjectTagList)(struct DOSIFace *Self, ULONG type, const struct TagItem * tags);
	APTR APICALL (*AllocDosObjectTags)(struct DOSIFace *Self, ULONG type, ...);
	VOID APICALL (*FreeDosObject)(struct DOSIFace *Self, ULONG type, APTR ptr);
	LONG APICALL (*DoPkt)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4, LONG arg5);
	LONG APICALL (*DoPkt0)(struct DOSIFace *Self, struct MsgPort * port, LONG action);
	LONG APICALL (*DoPkt1)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1);
	LONG APICALL (*DoPkt2)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1, LONG arg2);
	LONG APICALL (*DoPkt3)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1, LONG arg2, LONG arg3);
	LONG APICALL (*DoPkt4)(struct DOSIFace *Self, struct MsgPort * port, LONG action, LONG arg1, LONG arg2, LONG arg3, LONG arg4);
	VOID APICALL (*SendPkt)(struct DOSIFace *Self, struct DosPacket * dp, struct MsgPort * port, struct MsgPort * replyport);
	struct DosPacket * APICALL (*WaitPkt)(struct DOSIFace *Self, struct MsgPort * task_replyport);
	LONG APICALL (*ReplyPkt)(struct DOSIFace *Self, struct DosPacket * dp, LONG res1, LONG res2);
	void APICALL (*Reserved2)(struct DOSIFace *Self);
	DEPRECATED LONG APICALL (*OBSOLETELockRecord)(struct DOSIFace *Self, BPTR fh, ULONG offset, ULONG length, ULONG mode, ULONG timeout);
	LONG APICALL (*LockRecords)(struct DOSIFace *Self, struct RecordLock * recArray, ULONG timeout);
	DEPRECATED LONG APICALL (*OBSOLETEUnLockRecord)(struct DOSIFace *Self, BPTR fh, ULONG offset, ULONG length);
	LONG APICALL (*UnLockRecords)(struct DOSIFace *Self, struct RecordLock * recArray);
	BPTR APICALL (*SelectInput)(struct DOSIFace *Self, BPTR fh);
	BPTR APICALL (*SelectOutput)(struct DOSIFace *Self, BPTR fh);
	LONG APICALL (*FGetC)(struct DOSIFace *Self, BPTR fh);
	LONG APICALL (*FPutC)(struct DOSIFace *Self, BPTR fh, LONG ch);
	LONG APICALL (*UnGetC)(struct DOSIFace *Self, BPTR fh, LONG character);
	ULONG APICALL (*FRead)(struct DOSIFace *Self, BPTR fh, APTR block, ULONG blocklen, ULONG number);
	ULONG APICALL (*FWrite)(struct DOSIFace *Self, BPTR fh, CONST_APTR block, ULONG blocklen, ULONG number);
	STRPTR APICALL (*FGets)(struct DOSIFace *Self, BPTR fh, STRPTR buf, ULONG buflen);
	LONG APICALL (*FPuts)(struct DOSIFace *Self, BPTR fh, CONST_STRPTR str);
	DEPRECATED VOID APICALL (*OBSOLETEVFWritef)(struct DOSIFace *Self, BPTR fh, CONST_STRPTR format, LONG * argarray);
	DEPRECATED VOID APICALL (*OBSOLETEFWritef)(struct DOSIFace *Self, BPTR fh, CONST_STRPTR format, ...);
	LONG APICALL (*VFPrintf)(struct DOSIFace *Self, BPTR fh, CONST_STRPTR format, CONST_APTR argarray);
	LONG APICALL (*FPrintf)(struct DOSIFace *Self, BPTR fh, CONST_STRPTR format, ...);
	LONG APICALL (*FFlush)(struct DOSIFace *Self, BPTR fh);
	DEPRECATED LONG APICALL (*SetVBuf)(struct DOSIFace *Self, BPTR fh, STRPTR buff, LONG type, LONG size);
	BPTR APICALL (*DupLockFromFH)(struct DOSIFace *Self, BPTR fh);
	BPTR APICALL (*OpenFromLock)(struct DOSIFace *Self, BPTR lock);
	BPTR APICALL (*ParentOfFH)(struct DOSIFace *Self, BPTR fh);
	DEPRECATED LONG APICALL (*ExamineFH)(struct DOSIFace *Self, BPTR fh, struct FileInfoBlock * fib);
	LONG APICALL (*SetDate)(struct DOSIFace *Self, CONST_STRPTR name, const struct DateStamp * date);
	LONG APICALL (*NameFromLock)(struct DOSIFace *Self, BPTR lock, STRPTR buffer, LONG len);
	LONG APICALL (*NameFromFH)(struct DOSIFace *Self, BPTR fh, STRPTR buffer, LONG len);
	LONG APICALL (*SplitName)(struct DOSIFace *Self, CONST_STRPTR name, LONG seperator, STRPTR buf, LONG oldpos, LONG size);
	LONG APICALL (*SameLock)(struct DOSIFace *Self, BPTR lock1, BPTR lock2);
	LONG APICALL (*SetMode)(struct DOSIFace *Self, BPTR fh, LONG mode);
	DEPRECATED LONG APICALL (*ExAll)(struct DOSIFace *Self, BPTR lock, struct ExAllData * buffer, LONG size, LONG data, struct ExAllControl * control);
	LONG APICALL (*ReadSoftLink)(struct DOSIFace *Self, struct MsgPort * port, BPTR lock, CONST_STRPTR path, STRPTR buffer, ULONG size);
	LONG APICALL (*MakeLink)(struct DOSIFace *Self, CONST_STRPTR name, APTR dest, LONG soft);
	LONG APICALL (*ChangeMode)(struct DOSIFace *Self, LONG type, BPTR fh, LONG newmode);
	DEPRECATED LONG APICALL (*SetFileSize)(struct DOSIFace *Self, BPTR fh, LONG pos, LONG mode);
	LONG APICALL (*SetIoErr)(struct DOSIFace *Self, LONG result);
	LONG APICALL (*Fault)(struct DOSIFace *Self, LONG code, CONST_STRPTR header, STRPTR buffer, LONG len);
	LONG APICALL (*PrintFault)(struct DOSIFace *Self, LONG code, CONST_STRPTR header);
	LONG APICALL (*ErrorReport)(struct DOSIFace *Self, LONG code, LONG type, ULONG arg1, struct MsgPort * device);
	LONG APICALL (*PRIVATERequester)(struct DOSIFace *Self, CONST_STRPTR s1, CONST_STRPTR s2, CONST_STRPTR s3, LONG idcmp);
	struct CommandLineInterface * APICALL (*Cli)(struct DOSIFace *Self);
	struct Process * APICALL (*CreateNewProc)(struct DOSIFace *Self, const struct TagItem * tags);
	struct Process * APICALL (*CreateNewProcTagList)(struct DOSIFace *Self, const struct TagItem * tags);
	struct Process * APICALL (*CreateNewProcTags)(struct DOSIFace *Self, ...);
	LONG APICALL (*RunCommand)(struct DOSIFace *Self, BPTR seg, ULONG stack, CONST_STRPTR paramptr, LONG paramlen);
	struct MsgPort * APICALL (*GetConsoleTask)(struct DOSIFace *Self);
	struct MsgPort * APICALL (*SetConsoleTask)(struct DOSIFace *Self, const struct MsgPort * task);
	struct MsgPort * APICALL (*GetFileSysTask)(struct DOSIFace *Self);
	struct MsgPort * APICALL (*SetFileSysTask)(struct DOSIFace *Self, const struct MsgPort * task);
	STRPTR APICALL (*GetArgStr)(struct DOSIFace *Self);
	STRPTR APICALL (*SetArgStr)(struct DOSIFace *Self, CONST_STRPTR string);
	struct Process * APICALL (*FindCliProc)(struct DOSIFace *Self, ULONG num);
	ULONG APICALL (*MaxCli)(struct DOSIFace *Self);
	LONG APICALL (*SetCliCurrentDirName)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*GetCliCurrentDirName)(struct DOSIFace *Self, STRPTR buf, LONG len);
	LONG APICALL (*SetCliProgramName)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*GetCliProgramName)(struct DOSIFace *Self, STRPTR buf, LONG len);
	LONG APICALL (*SetCliPrompt)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*GetCliPrompt)(struct DOSIFace *Self, STRPTR buf, LONG len);
	BPTR APICALL (*SetProgramDir)(struct DOSIFace *Self, BPTR lock);
	BPTR APICALL (*GetProgramDir)(struct DOSIFace *Self);
	LONG APICALL (*SystemTagList)(struct DOSIFace *Self, CONST_STRPTR command, const struct TagItem * tags);
	LONG APICALL (*System)(struct DOSIFace *Self, CONST_STRPTR command, const struct TagItem * tags);
	LONG APICALL (*SystemTags)(struct DOSIFace *Self, CONST_STRPTR command, ...);
	LONG APICALL (*AssignLock)(struct DOSIFace *Self, CONST_STRPTR name, BPTR lock);
	LONG APICALL (*AssignLate)(struct DOSIFace *Self, CONST_STRPTR name, CONST_STRPTR path);
	LONG APICALL (*AssignPath)(struct DOSIFace *Self, CONST_STRPTR name, CONST_STRPTR path);
	LONG APICALL (*AssignAdd)(struct DOSIFace *Self, CONST_STRPTR name, BPTR lock);
	LONG APICALL (*RemAssignList)(struct DOSIFace *Self, CONST_STRPTR name, BPTR lock);
	struct DevProc * APICALL (*GetDeviceProc)(struct DOSIFace *Self, CONST_STRPTR name, struct DevProc * dp);
	VOID APICALL (*FreeDeviceProc)(struct DOSIFace *Self, struct DevProc * dp);
	struct DosList * APICALL (*LockDosList)(struct DOSIFace *Self, ULONG flags);
	VOID APICALL (*UnLockDosList)(struct DOSIFace *Self, ULONG flags);
	struct DosList * APICALL (*AttemptLockDosList)(struct DOSIFace *Self, ULONG flags);
	LONG APICALL (*RemDosEntry)(struct DOSIFace *Self, struct DosList * dlist);
	LONG APICALL (*AddDosEntry)(struct DOSIFace *Self, struct DosList * dlist);
	struct DosList * APICALL (*FindDosEntry)(struct DOSIFace *Self, const struct DosList * dlist, CONST_STRPTR name, ULONG flags);
	struct DosList * APICALL (*NextDosEntry)(struct DOSIFace *Self, const struct DosList * dlist, ULONG flags);
	struct DosList * APICALL (*MakeDosEntry)(struct DOSIFace *Self, CONST_STRPTR name, LONG type);
	VOID APICALL (*FreeDosEntry)(struct DOSIFace *Self, struct DosList * dlist);
	LONG APICALL (*IsFileSystem)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*Format)(struct DOSIFace *Self, CONST_STRPTR filesystem, CONST_STRPTR volumename, ULONG dostype);
	LONG APICALL (*Relabel)(struct DOSIFace *Self, CONST_STRPTR drive, CONST_STRPTR newname);
	LONG APICALL (*Inhibit)(struct DOSIFace *Self, CONST_STRPTR name, LONG onoff);
	LONG APICALL (*AddBuffers)(struct DOSIFace *Self, CONST_STRPTR name, LONG number);
	LONG APICALL (*CompareDates)(struct DOSIFace *Self, const struct DateStamp * date1, const struct DateStamp * date2);
	LONG APICALL (*DateToStr)(struct DOSIFace *Self, struct DateTime * datetime);
	LONG APICALL (*StrToDate)(struct DOSIFace *Self, struct DateTime * datetime);
	DEPRECATED BPTR APICALL (*OBSOLETEInternalLoadSeg)(struct DOSIFace *Self, BPTR fh, BPTR table, const LONG * funcarray);
	DEPRECATED LONG APICALL (*OBSOLETEInternalUnLoadSeg)(struct DOSIFace *Self, BPTR seglist, VOID (*freefunc )());
	BPTR APICALL (*OBSOLETENewLoadSeg)(struct DOSIFace *Self, CONST_STRPTR file, const struct TagItem * tags);
	BPTR APICALL (*OBSOLETENewLoadSegTagList)(struct DOSIFace *Self, CONST_STRPTR file, const struct TagItem * tags);
	BPTR APICALL (*OBSOLETENewLoadSegTags)(struct DOSIFace *Self, CONST_STRPTR file, ...);
	LONG APICALL (*AddSegment)(struct DOSIFace *Self, CONST_STRPTR name, BPTR seg, LONG type);
	struct DosResidentSeg * APICALL (*FindSegment)(struct DOSIFace *Self, CONST_STRPTR name, const struct DosResidentSeg * seg, LONG sys);
	LONG APICALL (*RemSegment)(struct DOSIFace *Self, struct DosResidentSeg * seg);
	ULONG APICALL (*CheckSignal)(struct DOSIFace *Self, ULONG mask);
	struct RDArgs * APICALL (*ReadArgs)(struct DOSIFace *Self, CONST_STRPTR arg_template, LONG * array, struct RDArgs * args);
	LONG APICALL (*FindArg)(struct DOSIFace *Self, CONST_STRPTR arg_template, CONST_STRPTR keyword);
	LONG APICALL (*ReadItem)(struct DOSIFace *Self, STRPTR buffer, LONG maxchars, struct CSource * cSource);
	LONG APICALL (*StrToLong)(struct DOSIFace *Self, CONST_STRPTR string, LONG * value);
	LONG APICALL (*MatchFirst)(struct DOSIFace *Self, CONST_STRPTR pat, struct AnchorPath * anchor);
	LONG APICALL (*MatchNext)(struct DOSIFace *Self, struct AnchorPath * anchor);
	VOID APICALL (*MatchEnd)(struct DOSIFace *Self, struct AnchorPath * anchor);
	LONG APICALL (*ParsePattern)(struct DOSIFace *Self, CONST_STRPTR pat, STRPTR buf, LONG buflen);
	LONG APICALL (*MatchPattern)(struct DOSIFace *Self, CONST_STRPTR pat, CONST_STRPTR str);
	void APICALL (*Reserved3)(struct DOSIFace *Self);
	VOID APICALL (*FreeArgs)(struct DOSIFace *Self, struct RDArgs * args);
	void APICALL (*Reserved4)(struct DOSIFace *Self);
	STRPTR APICALL (*FilePart)(struct DOSIFace *Self, CONST_STRPTR path);
	STRPTR APICALL (*PathPart)(struct DOSIFace *Self, CONST_STRPTR path);
	LONG APICALL (*AddPart)(struct DOSIFace *Self, STRPTR destdirname, CONST_STRPTR filename, ULONG size);
	LONG APICALL (*StartNotify)(struct DOSIFace *Self, struct NotifyRequest * notify);
	LONG APICALL (*EndNotify)(struct DOSIFace *Self, struct NotifyRequest * notify);
	LONG APICALL (*SetVar)(struct DOSIFace *Self, CONST_STRPTR name, CONST_STRPTR buffer, LONG size, ULONG flags);
	LONG APICALL (*GetVar)(struct DOSIFace *Self, CONST_STRPTR name, STRPTR buffer, LONG size, ULONG flags);
	LONG APICALL (*DeleteVar)(struct DOSIFace *Self, CONST_STRPTR name, ULONG flags);
	struct LocalVar * APICALL (*FindVar)(struct DOSIFace *Self, CONST_STRPTR name, ULONG type);
	LONG APICALL (*PRIVATECliInit)(struct DOSIFace *Self, struct DosPacket * dp);
	LONG APICALL (*CliInitNewcli)(struct DOSIFace *Self, struct DosPacket * dp);
	LONG APICALL (*CliInitRun)(struct DOSIFace *Self, struct DosPacket * dp);
	LONG APICALL (*WriteChars)(struct DOSIFace *Self, CONST_STRPTR buf, ULONG buflen);
	LONG APICALL (*PutStr)(struct DOSIFace *Self, CONST_STRPTR str);
	LONG APICALL (*VPrintf)(struct DOSIFace *Self, CONST_STRPTR format, CONST_APTR argarray);
	LONG APICALL (*Printf)(struct DOSIFace *Self, CONST_STRPTR format, ...);
	void APICALL (*Reserved5)(struct DOSIFace *Self);
	LONG APICALL (*ParsePatternNoCase)(struct DOSIFace *Self, CONST_STRPTR pat, STRPTR buf, LONG buflen);
	LONG APICALL (*MatchPatternNoCase)(struct DOSIFace *Self, CONST_STRPTR pat, CONST_STRPTR str);
	STRPTR APICALL (*PRIVATEDosGetString)(struct DOSIFace *Self, LONG num);
	LONG APICALL (*SameDevice)(struct DOSIFace *Self, BPTR lock1, BPTR lock2);
	DEPRECATED VOID APICALL (*ExAllEnd)(struct DOSIFace *Self, BPTR lock, struct ExAllData * buffer, LONG size, LONG data, struct ExAllControl * control);
	DEPRECATED LONG APICALL (*SetOwner)(struct DOSIFace *Self, CONST_STRPTR name, ULONG owner_info);
	LONG APICALL (*GetEntryData)(struct DOSIFace *Self);
	LONG APICALL (*ReadLineItem)(struct DOSIFace *Self, STRPTR buffer, LONG maxchars, const struct TagItem * taglist);
	LONG APICALL (*ReadLineItemTags)(struct DOSIFace *Self, STRPTR buffer, LONG maxchars, ...);
	LONG APICALL (*PRIVATEInternalRunCommand)(struct DOSIFace *Self, BPTR seg, ULONG stksize, CONST_STRPTR args, LONG arglen);
	BPTR APICALL (*GetCurrentDir)(struct DOSIFace *Self);
	LONG APICALL (*NonBlockingModifyDosEntry)(struct DOSIFace *Self, struct DosList * dl, LONG mode, APTR arg1, APTR arg2);
	struct DateStamp * APICALL (*SecondsToDateStamp)(struct DOSIFace *Self, ULONG seconds, struct DateStamp * ds);
	ULONG APICALL (*DateStampToSeconds)(struct DOSIFace *Self, const struct DateStamp * ds);
	LONG APICALL (*FixDateStamp)(struct DOSIFace *Self, struct DateStamp * ds);
	LONG APICALL (*AddDates)(struct DOSIFace *Self, struct DateStamp * to, const struct DateStamp * from);
	LONG APICALL (*SubtractDates)(struct DOSIFace *Self, struct DateStamp * to, const struct DateStamp * from);
	LONG APICALL (*AddSegmentTagList)(struct DOSIFace *Self, CONST_STRPTR name, LONG type, const struct TagItem * tags);
	LONG APICALL (*ParseCapturePattern)(struct DOSIFace *Self, CONST_STRPTR pat, STRPTR dst, LONG length, LONG casesen);
	LONG APICALL (*CapturePattern)(struct DOSIFace *Self, CONST_STRPTR pat, CONST_STRPTR str, LONG casesen, struct CapturedExpression ** cap);
	VOID APICALL (*ReleaseCapturedExpressions)(struct DOSIFace *Self, struct CapturedExpression * first);
	VOID APICALL (*FindTrackedAddress)(struct DOSIFace *Self, CONST_APTR address, struct Hook * hook);
	LONG APICALL (*TrackAddressList)(struct DOSIFace *Self, CONST_STRPTR name, BPTR segment, CONST_APTR extra_info, LONG extra_info_size, const struct AddressAndSize * aas, LONG num_pairs);
	LONG APICALL (*TrackSegmentList)(struct DOSIFace *Self, CONST_STRPTR name, BPTR segment, CONST_APTR extra_info, LONG extra_info_size);
	VOID APICALL (*UnTrackAddress)(struct DOSIFace *Self, APTR address);
	VOID APICALL (*UnTrackSegmentList)(struct DOSIFace *Self, BPTR segment);
	LONG APICALL (*GetExitData)(struct DOSIFace *Self);
	LONG APICALL (*PutErrStr)(struct DOSIFace *Self, CONST_STRPTR str);
	BPTR APICALL (*ErrorOutput)(struct DOSIFace *Self);
	BPTR APICALL (*SelectErrorOutput)(struct DOSIFace *Self, BPTR fh);
	LONG APICALL (*MountDevice)(struct DOSIFace *Self, CONST_STRPTR name, LONG type, const struct TagItem * tags);
	LONG APICALL (*MountDeviceTags)(struct DOSIFace *Self, CONST_STRPTR name, LONG type, ...);
	APTR APICALL (*SetProcWindow)(struct DOSIFace *Self, CONST_APTR win);
	ULONG APICALL (*FindSegmentStackSize)(struct DOSIFace *Self, BPTR segment);
	ULONG APICALL (*CalculateSegmentChecksum)(struct DOSIFace *Self, BPTR segment);
	BPTR APICALL (*AllocSegList)(struct DOSIFace *Self, CONST_APTR entry, CONST_APTR data, ULONG datalen, ULONG identkey);
	LONG APICALL (*GetSegListInfo)(struct DOSIFace *Self, BPTR seglist, const struct TagItem * tags);
	LONG APICALL (*GetSegListInfoTags)(struct DOSIFace *Self, BPTR seglist, ...);
	LONG APICALL (*AddSegListTail)(struct DOSIFace *Self, BPTR bseglist_head, BPTR bseg_new);
	LONG APICALL (*DevNameFromLock)(struct DOSIFace *Self, BPTR lock, STRPTR buffer, LONG buflen, LONG mode);
	struct MsgPort * APICALL (*GetProcMsgPort)(struct DOSIFace *Self, const struct Process * proc);
	LONG APICALL (*WaitForData)(struct DOSIFace *Self, BPTR stream, LONG data_direction, LONG timeout);
	LONG APICALL (*SetBlockingMode)(struct DOSIFace *Self, BPTR stream, LONG new_blocking_mode);
	struct PathNode * APICALL (*SetCurrentCmdPathList)(struct DOSIFace *Self, struct PathNode * pn);
	struct PathNode * APICALL (*AllocateCmdPathList)(struct DOSIFace *Self, BPTR first_lock);
	VOID APICALL (*FreeCmdPathList)(struct DOSIFace *Self, struct PathNode * pn);
	struct PathNode * APICALL (*RemoveCmdPathNode)(struct DOSIFace *Self, struct PathNode * pn, BPTR lock);
	struct PathNode * APICALL (*AddCmdPathNode)(struct DOSIFace *Self, struct PathNode * pn, BPTR lock, LONG where);
	LONG APICALL (*SearchCmdPathList)(struct DOSIFace *Self, const struct PathNode * pn, const struct Hook * h, CONST_STRPTR name, const struct TagItem * tags);
	LONG APICALL (*SearchCmdPathListTags)(struct DOSIFace *Self, const struct PathNode * pn, const struct Hook * h, CONST_STRPTR name, ...);
	LONG APICALL (*ScanVars)(struct DOSIFace *Self, const struct Hook * hook, ULONG flags, CONST_APTR userdata);
	BPTR APICALL (*GetProcSegList)(struct DOSIFace *Self, const struct Process * proc, ULONG flags);
	LONG APICALL (*HexToLong)(struct DOSIFace *Self, CONST_STRPTR string, ULONG * value_ptr);
	struct DevProc * APICALL (*GetDeviceProcFlags)(struct DOSIFace *Self, CONST_STRPTR name, struct DevProc * odp, ULONG flags);
	LONG APICALL (*DosControl)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*DosControlTags)(struct DOSIFace *Self, ...);
	BPTR APICALL (*CreateDirTree)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*NotifyVar)(struct DOSIFace *Self, CONST_STRPTR name, const struct Hook * hook, LONG flags, CONST_APTR userdata);
	struct FileSystemData * APICALL (*GetDiskFileSystemData)(struct DOSIFace *Self, CONST_STRPTR name);
	VOID APICALL (*FreeDiskFileSystemData)(struct DOSIFace *Self, struct FileSystemData * fsd);
	BPTR APICALL (*FOpen)(struct DOSIFace *Self, CONST_STRPTR name, LONG mode, LONG bufsize);
	LONG APICALL (*FClose)(struct DOSIFace *Self, BPTR scb);
	BPTR APICALL (*FOpenFromLock)(struct DOSIFace *Self, BPTR lock, LONG bufsize);
	void APICALL (*Reserved6)(struct DOSIFace *Self);
	LONG APICALL (*TimedDosRequester)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*TimedDosRequesterTags)(struct DOSIFace *Self, ...);
	LONG APICALL (*RenameDosEntry)(struct DOSIFace *Self, struct DosList * dlist, CONST_STRPTR newname);
	LONG APICALL (*DismountDevice)(struct DOSIFace *Self, CONST_STRPTR name, ULONG flags, APTR reserved);
	BPTR APICALL (*DupFileHandle)(struct DOSIFace *Self, BPTR scb);
	LONG APICALL (*DevNameFromFH)(struct DOSIFace *Self, BPTR scb, STRPTR buffer, LONG buflen, LONG mode);
	LONG APICALL (*AssignAddToList)(struct DOSIFace *Self, CONST_STRPTR name, BPTR lock, LONG endpos);
	LONG APICALL (*SetFileHandleAttr)(struct DOSIFace *Self, BPTR fh, const struct TagItem * tags);
	LONG APICALL (*SetFileHandleAttrTags)(struct DOSIFace *Self, BPTR fh, ...);
	LONG APICALL (*FileSystemAttr)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*FileSystemAttrTags)(struct DOSIFace *Self, ...);
	LONG APICALL (*FReadLine)(struct DOSIFace *Self, BPTR fh, struct FReadLineData * frld);
	ULONG APICALL (*CopyStringBSTRToC)(struct DOSIFace *Self, BSTR bsrc, STRPTR dst, ULONG siz);
	ULONG APICALL (*CopyStringCToBSTR)(struct DOSIFace *Self, CONST_STRPTR src, BSTR bdest, ULONG siz);
	int64 APICALL (*GetFilePosition)(struct DOSIFace *Self, BPTR fh);
	int32 APICALL (*ChangeFilePosition)(struct DOSIFace *Self, BPTR file, int64 position, int32 offset);
	int32 APICALL (*ChangeFileSize)(struct DOSIFace *Self, BPTR fh, int64 pos, int32 mode);
	int64 APICALL (*GetFileSize)(struct DOSIFace *Self, BPTR fh);
	void APICALL (*Reserved7)(struct DOSIFace *Self);
	int64 APICALL (*PRIVATEDoPkt64)(struct DOSIFace *Self, struct MsgPort * sendport, int32 type, int32 arg1, int64 arg2, int32 arg3, int32 arg4, int64 arg5);
	void APICALL (*Reserved8)(struct DOSIFace *Self);
	void APICALL (*Reserved9)(struct DOSIFace *Self);
	void APICALL (*Reserved10)(struct DOSIFace *Self);
	LONG APICALL (*ProcessScan)(struct DOSIFace *Self, const struct Hook * hook, CONST_APTR userdata, ULONG reserved);
	LONG APICALL (*NotifyDosListChange)(struct DOSIFace *Self, struct Process * process, ULONG signalnum, ULONG reserved);
	LONG APICALL (*NotifyProcListChange)(struct DOSIFace *Self, struct Process * process, ULONG signalnum, ULONG reserved);
	LONG APICALL (*GetDiskInfo)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*GetDiskInfoTags)(struct DOSIFace *Self, ...);
	LONG APICALL (*WriteProtectVolume)(struct DOSIFace *Self, CONST_STRPTR name, LONG on_off, ULONG passkey, LONG reserved);
	struct ExamineData * APICALL (*ExamineObject)(struct DOSIFace *Self, const struct TagItem * ctags);
	struct ExamineData * APICALL (*ExamineObjectTags)(struct DOSIFace *Self, ...);
	struct ExamineData * APICALL (*ExamineDir)(struct DOSIFace *Self, APTR context);
	APTR APICALL (*ObtainDirContext)(struct DOSIFace *Self, const struct TagItem * ctags);
	APTR APICALL (*ObtainDirContextTags)(struct DOSIFace *Self, ...);
	VOID APICALL (*ReleaseDirContext)(struct DOSIFace *Self, APTR contx);
	LONG APICALL (*GetOwnerInfo)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*GetOwnerInfoTags)(struct DOSIFace *Self, ...);
	LONG APICALL (*SetOwnerInfo)(struct DOSIFace *Self, const struct TagItem * tags);
	LONG APICALL (*SetOwnerInfoTags)(struct DOSIFace *Self, ...);
	BPTR APICALL (*LockTagList)(struct DOSIFace *Self, const struct TagItem * tags);
	BPTR APICALL (*LockTags)(struct DOSIFace *Self, ...);
	ULONG APICALL (*GetPID)(struct DOSIFace *Self, struct Process * process, LONG which);
	LONG APICALL (*FlushVolume)(struct DOSIFace *Self, CONST_STRPTR name);
	struct ConsoleWindowData * APICALL (*ObtainConsoleData)(struct DOSIFace *Self, const struct TagItem * ctags);
	struct ConsoleWindowData * APICALL (*ObtainConsoleDataTags)(struct DOSIFace *Self, ...);
	VOID APICALL (*ReleaseConsoleData)(struct DOSIFace *Self, struct ConsoleWindowData * data);
	LONG APICALL (*Serialize)(struct DOSIFace *Self, CONST_STRPTR name);
	LONG APICALL (*NameFromPort)(struct DOSIFace *Self, struct MsgPort * port, STRPTR buffer, LONG buflen, LONG add_colon);
	LONG APICALL (*DevNameFromPort)(struct DOSIFace *Self, struct MsgPort * port, STRPTR buffer, LONG buflen, LONG add_colon);
	LONG APICALL (*SameFH)(struct DOSIFace *Self, BPTR scb1, BPTR scb2);
	int32 APICALL (*LockRecord)(struct DOSIFace *Self, BPTR fh, int64 offset, int64 length, uint32 mode, uint32 timeout);
	int32 APICALL (*UnLockRecord)(struct DOSIFace *Self, BPTR fh, int64 offset, int64 length);
	int32 APICALL (*IsFileSystemPort)(struct DOSIFace *Self, struct MsgPort * port);
	int32 APICALL (*InhibitPort)(struct DOSIFace *Self, struct MsgPort * port, int32 state);
	int32 APICALL (*FormatPort)(struct DOSIFace *Self, struct MsgPort * port, CONST_STRPTR volumename, uint32 dostype);
	int32 APICALL (*SerializePort)(struct DOSIFace *Self, struct MsgPort * port);
	int32 APICALL (*FlushVolumePort)(struct DOSIFace *Self, struct MsgPort * port);
	LONG APICALL (*FileHandleScan)(struct DOSIFace *Self, const struct Hook * hook, CONST_APTR userdata, ULONG reserved);
	struct FileSystemVectorPort * APICALL (*GetFileSystemVectorPort)(struct DOSIFace *Self, struct MsgPort * port, uint32 min_version);
	int32 APICALL (*ResolvePath)(struct DOSIFace *Self, struct MsgPort * port, CONST_STRPTR path, BPTR inlock, STRPTR out, uint32 outlen, BPTR * outdir, uint32 * slcount);
	void APICALL (*Reserved14)(struct DOSIFace *Self);
	void APICALL (*Reserved15)(struct DOSIFace *Self);
	void APICALL (*Reserved16)(struct DOSIFace *Self);
	void APICALL (*Reserved17)(struct DOSIFace *Self);
	void APICALL (*Reserved18)(struct DOSIFace *Self);
};

/**********************************************************************************************/

struct DosPacket64
{
    struct Message *dp_Link;    /* EXEC message                    */
    struct MsgPort *dp_Port;    /* Reply port for the packet,      */
                                /* must be filled in on each send. */
    int32           dp_Type;    /* See ACTION_... below            */

    int32           dp_Res0;    /* Special compatibility field. [See below] */

    int32           dp_Res2;    /* This is returned for IoErr()    */
    int64           dp_Res1;    /* This is the 64 bit primary result */

    int32           dp_Arg1;    /* 32 bit argument */
    int64           dp_Arg2;    /* 64 bit argument */
    int32           dp_Arg3;    /* 32 bit argument */
    int32           dp_Arg4;    /* 32 bit argument */
    int64           dp_Arg5;    /* 64 bit argument */
};

/**********************************************************************************************/

struct DOSPrefs
{
    LONG dp_FHBufferSize;       /* size in bytes for all FileHandle buffers. */
    LONG dp_MinProcStack;       /* minimum stack bytes for all processes */
    LONG dp_WarnWaitTime;       /* number of seconds to wait between warnings. */
    LONG dp_WarnPostTime;       /* number of seconds to post warning for.  */
    LONG dp_WildStar;           /* BOOLEAN - see doscontrol  */
    LONG dp_AssignMount;        /* BOOLEAN - see errorreport()  */
    LONG dp_BootCliFontSize;    /* Set to: TOPAZ_EIGHTY or TOPAZ_SIXTY (8 or 9) */
                                /* The define for this is in intuition/preferences.h */
    LONG dp_BootCliCloseGadget; /* BOOLEAN - see doscontrol */
    LONG dp_Reserved[6];        /* reserved for future expansion.  */
};

/**********************************************************************************************/

struct DosResidentSeg
{
    BPTR    seg_Next;     /* BCPL pointer to next DosResidentSeg, or zero */
    int32   seg_UC;       /* Use Count */
    BPTR    seg_Seg;      /* BCPL pointer to seglist of command. */
    TEXT    seg_Name[4];  /* First 4 chars of BCPL style formatted name */
};

/**********************************************************************************************/

struct DrawListIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct DrawListIFace *Self);
	ULONG APICALL (*Release)(struct DrawListIFace *Self);
	void APICALL (*Expunge)(struct DrawListIFace *Self);
	struct Interface * APICALL (*Clone)(struct DrawListIFace *Self);
	Class * APICALL (*DRAWLIST_GetClass)(struct DrawListIFace *Self);
};

/**********************************************************************************************/

struct DTClassIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct DTClassIFace *Self);
	ULONG APICALL (*Release)(struct DTClassIFace *Self);
	void APICALL (*Expunge)(struct DTClassIFace *Self);
	struct Interface * APICALL (*Clone)(struct DTClassIFace *Self);
	Class * APICALL (*ObtainEngine)(struct DTClassIFace *Self);
};

/**********************************************************************************************/

struct DTMethod
{
    STRPTR dtm_Label;
    STRPTR dtm_Command;
    ULONG  dtm_Method;
};

/**********************************************************************************************/

struct EGlyphEngine
{
    struct BulletIFace *ege_IBullet;    /* NULL for 68K font engines */
    struct Library     *ege_BulletBase;
    struct GlyphEngine *ege_GlyphEngine;
};

/**********************************************************************************************/

struct Elf32_SymbolQuery
{
    uint32    Flags;      /* Flag value qualifying the search            */
    STRPTR    Name;       /* Name of symbol to search                    */
    uint32    NameLength; /* Length of the name buffer for BYVALUE query */
    uint32    Value;      /* Value of the symbol                         */
    BOOL      Found;      /* FALSE if symbol was not found               */
    uint16    pad1;       /* Pad for longword alignment                  */
    Elf32_Sym Sym;        /* Copy of the symbol's SymTable entry         */
};

/**********************************************************************************************/

struct ElfHookMsg
{
    ULONG OpCode;
    ULONG Arg1;
    ULONG Arg2;
    ULONG Arg3;
};

/**********************************************************************************************/

struct ElfIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ElfIFace *Self);
	ULONG APICALL (*Release)(struct ElfIFace *Self);
	void APICALL (*Expunge)(struct ElfIFace *Self);
	struct Interface * APICALL (*Clone)(struct ElfIFace *Self);
	Elf32_Handle APICALL (*OpenElf)(struct ElfIFace *Self, struct TagItem * taglist);
	Elf32_Handle APICALL (*OpenElfTags)(struct ElfIFace *Self, ...);
	void APICALL (*CloseElf)(struct ElfIFace *Self, Elf32_Handle ElfHandle, struct TagItem * TagList);
	void APICALL (*CloseElfTags)(struct ElfIFace *Self, Elf32_Handle ElfHandle, ...);
	ULONG APICALL (*GetElfAttrs)(struct ElfIFace *Self, Elf32_Handle ElfHandle, struct TagItem * taglist);
	ULONG APICALL (*GetElfAttrsTags)(struct ElfIFace *Self, Elf32_Handle ElfHandle, ...);
	ULONG APICALL (*SetElfAttrs)(struct ElfIFace *Self, Elf32_Handle ElfHandle, struct TagItem * taglist);
	ULONG APICALL (*SetElfAttrsTags)(struct ElfIFace *Self, Elf32_Handle ElfHandle, ...);
	Elf32_Shdr * APICALL (*GetSectionHeader)(struct ElfIFace *Self, Elf32_Handle ElfHandle, struct TagItem * TagList);
	Elf32_Shdr * APICALL (*GetSectionHeaderTags)(struct ElfIFace *Self, Elf32_Handle ElfHandle, ...);
	APTR APICALL (*GetSection)(struct ElfIFace *Self, Elf32_Handle ElfHandle, struct TagItem * TagList);
	APTR APICALL (*GetSectionTags)(struct ElfIFace *Self, Elf32_Handle ElfHandle, ...);
	Elf32_Error APICALL (*ElfLoadSeg)(struct ElfIFace *Self, Elf32_Handle ElfHandle, struct TagItem * taglist);
	Elf32_Error APICALL (*ElfLoadSegTags)(struct ElfIFace *Self, Elf32_Handle ElfHandle, ...);
	CONST_STRPTR APICALL (*GetElfString)(struct ElfIFace *Self, Elf32_Handle ElfHandle, UWORD SectionIndex, UWORD StringIndex);
	ULONG APICALL (*SymbolQuery)(struct ElfIFace *Self, Elf32_Handle ElfHandle, ULONG NumQueries, struct Elf32_SymbolQuery * Queries);
	void APICALL (*UnloadSection)(struct ElfIFace *Self, Elf32_Handle ElfHandle, struct TagItem * taglist);
	void APICALL (*UnloadSectionTags)(struct ElfIFace *Self, Elf32_Handle ElfHandle, ...);
	uint32 APICALL (*AddressToSection)(struct ElfIFace *Self, Elf32_Handle ElfHandle, APTR Address);
	void APICALL (*ScanSymbolTable)(struct ElfIFace *Self, Elf32_Handle ElfHandle, struct Hook * hook, struct TagItem * tagList);
	void APICALL (*ScanSymbolTableTags)(struct ElfIFace *Self, Elf32_Handle ElfHandle, struct Hook * hook, ...);
	BOOL APICALL (*RelocateSection)(struct ElfIFace *Self, Elf32_Handle ElfHandle, struct TagItem * taglist);
	BOOL APICALL (*RelocateSectionTags)(struct ElfIFace *Self, Elf32_Handle ElfHandle, ...);
	void * APICALL (*CopyDataSegment)(struct ElfIFace *Self, Elf32_Handle ElfHandle, uint32 * baseOffset);
	void APICALL (*FreeDataSegmentCopy)(struct ElfIFace *Self, Elf32_Handle ElfHandle, void * SegmentCopy);
	void APICALL (*InitSHLibs)(struct ElfIFace *Self, Elf32_Handle ElfHandle, BOOL DoInit);
	APTR APICALL (*DLOpen)(struct ElfIFace *Self, Elf32_Handle RootHandle, CONST_STRPTR Name, uint32 Flags);
	Elf32_Error APICALL (*DLClose)(struct ElfIFace *Self, Elf32_Handle RootHandle, APTR Handle);
	Elf32_Error APICALL (*DLSym)(struct ElfIFace *Self, Elf32_Handle RootHandle, APTR Handle, CONST_STRPTR SymbolName, APTR * Result);
};

/**********************************************************************************************/

struct EmulatorResource
{
    struct Node Node;
    APTR        EnterPPC;
    APTR        Enter68K;
    APTR        EnterPPCQuick;
    APTR        Enter68KQuick;
    APTR        EnterPPCQuickSP;
    APTR        EnterPPCNew;
    APTR        EnterPPCDirectly;
    ULONG       PrivateDontMove;
    ULONG       Reserved[3];
};

/**********************************************************************************************/

struct EmuTrap
{
    uint32  Instruction;                 /* TRAPINST, see below    */
    uint16  Type;                        /* TRAPTYPE or TRAPTYPENR */
    uint32  (*Function)(uint32 *Reg68K); /* PPC function address,
                                          * also see "enRegConst" below
                                          * but watch out byteoffsets!
                                          */
};

/**********************************************************************************************/

struct ExamineData
{
    struct MinNode   EXDnode;      /* MinList node.                           */
    uint32           EXDinfo;      /* Extra list data, general purpose use.   */

    /* These are private members exclusively for the FS & DOS.                */
    uint32           FSPrivate;    /* FILESYSTEM ONLY - Private usage.        */
    uint32           Reserved0;    /* DOS RESERVED - Private usage.           */
    APTR             DOSPrivate;   /* DOSLIB ONLY - Private usage.            */
                                   /*                                         */
    /* The following are public fields.                                       */
    uint32           StructSize;   /* (RO) Full size of the structure.        */
    uint32           Type;         /* Entry type; use EXD_IS_ macros below.   */
    int64            FileSize;     /* Size of a file, otherwise set to -1LL.  */
    struct DateStamp Date;         /* Days, Mins, Ticks.                      */
    uint32           UseCount;     /* Filesystem linked object count.[Note 1] */
    uint64           ObjectID;     /* Unique object identifier.      [Note 2] */
    STRPTR           Name;         /* (RO) Nul-terminated object name.        */
    uint32           NameSize;     /* (RO) Allocated size of the name buffer. */
    STRPTR           Comment;      /* (RO) Nul-terminated comment string.     */
    uint32           CommentSize;  /* (RO) Allocated size of comment buffer.  */
    STRPTR           Link;         /* (RO) Nul-terminated target name string. */
    uint32           LinkSize;     /* (RO) Allocated size of target buffer.   */
    uint32           Protection;   /* Protection status bitmask.              */
    uint32           OwnerUID;     /* Owner info. [Note 3]                    */
    uint32           OwnerGID;     /* Group info. [Note 3]                    */
    uint32           Reserved2;    /* DOS reserved field.                     */
    uint32           Reserved3;    /* DOS reserved field.                     */
    uint32           Reserved4;    /* DOS reserved field.                     */
};

/**********************************************************************************************/

struct ExceptionContext
{
    uint32  Flags;    /* Flags, describing the context (READ-ONLY)*/
    uint32  Traptype; /* Type of trap (READ-ONLY) */
    uint32  msr;      /* Machine state */
    uint32  ip;       /* Return instruction pointer */
    uint32  gpr[32];  /* r0 - r31 */
    uint32  cr;       /* Condition code register */
    uint32  xer;      /* Extended exception register */
    uint32  ctr;      /* Count register */
    uint32  lr;       /* Link register */
    uint32  dsisr;    /* DSI status register. Only set when valid */
    uint32  dar;      /* Data address register. Only set when valid */
    float64 fpr[32];  /* Floating point registers */
    uint64  fpscr;    /* Floating point control and status register */
    /* The following are only used on AltiVec */
    uint8   vscr[16]; /* AltiVec vector status and control register */
    uint8   vr[512];  /* AltiVec vector register storage */
    uint32  vrsave;   /* AltiVec VRSAVE register */
};

/**********************************************************************************************/

struct ExecIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ExecIFace *Self);
	ULONG APICALL (*Release)(struct ExecIFace *Self);
	void APICALL (*Expunge)(struct ExecIFace *Self);
	struct Interface * APICALL (*Clone)(struct ExecIFace *Self);
	void APICALL (*AddHead)(struct ExecIFace *Self, struct List * list, struct Node * node);
	VOID APICALL (*AddMemHandler)(struct ExecIFace *Self, struct Interrupt * memHandler);
	DEPRECATED void APICALL (*AddMemList)(struct ExecIFace *Self, ULONG size, ULONG attributes, LONG pri, APTR base, CONST_STRPTR name);
	void APICALL (*AddTail)(struct ExecIFace *Self, struct List * list, struct Node * node);
	DEPRECATED APTR APICALL (*AllocAbs)(struct ExecIFace *Self, ULONG byteSize, APTR location);
	DEPRECATED APTR APICALL (*Allocate)(struct ExecIFace *Self, struct MemHeader * memHeader, ULONG byteSize);
	DEPRECATED struct MemList * APICALL (*AllocEntry)(struct ExecIFace *Self, struct MemList * memList);
	DEPRECATED APTR APICALL (*AllocMem)(struct ExecIFace *Self, ULONG byteSize, ULONG attributes);
	APTR APICALL (*AllocPooled)(struct ExecIFace *Self, APTR poolHeader, ULONG memSize);
	DEPRECATED APTR APICALL (*AllocVec)(struct ExecIFace *Self, ULONG byteSize, ULONG attributes);
	APTR APICALL (*AllocVecPooled)(struct ExecIFace *Self, APTR poolHeader, ULONG size);
	ULONG APICALL (*AvailMem)(struct ExecIFace *Self, ULONG attributes);
	void APICALL (*CopyMem)(struct ExecIFace *Self, CONST_APTR source, APTR dest, ULONG size);
	void APICALL (*CopyMemQuick)(struct ExecIFace *Self, CONST_APTR source, APTR dest, ULONG size);
	DEPRECATED APTR APICALL (*CreatePool)(struct ExecIFace *Self, ULONG memFlags, ULONG puddleSize, ULONG threshSize);
	DEPRECATED void APICALL (*Deallocate)(struct ExecIFace *Self, struct MemHeader * memHeader, APTR memoryBlock, ULONG byteSize);
	DEPRECATED void APICALL (*DeletePool)(struct ExecIFace *Self, APTR poolHeader);
	void APICALL (*Enqueue)(struct ExecIFace *Self, struct List * list, struct Node * node);
	struct Node * APICALL (*FindName)(struct ExecIFace *Self, struct List * start, CONST_STRPTR name);
	struct Node * APICALL (*FindIName)(struct ExecIFace *Self, struct List * start, CONST_STRPTR name);
	void APICALL (*Forbid)(struct ExecIFace *Self);
	void APICALL (*FreeEntry)(struct ExecIFace *Self, struct MemList * memList);
	DEPRECATED void APICALL (*FreeMem)(struct ExecIFace *Self, APTR memoryBlock, ULONG byteSize);
	void APICALL (*FreePooled)(struct ExecIFace *Self, APTR poolHeader, APTR memory, ULONG memSize);
	void APICALL (*FreeVec)(struct ExecIFace *Self, APTR memoryBlock);
	void APICALL (*FreeVecPooled)(struct ExecIFace *Self, APTR poolHeader, APTR memory);
	DEPRECATED void APICALL (*InitData)(struct ExecIFace *Self, CONST_APTR initTab, APTR memory, ULONG size);
	DEPRECATED void APICALL (*InitStruct)(struct ExecIFace *Self, CONST_APTR initTable, APTR memory, ULONG size);
	void APICALL (*Insert)(struct ExecIFace *Self, struct List * list, struct Node * node, struct Node * listNode);
	struct Interface * APICALL (*MakeInterface)(struct ExecIFace *Self, struct Library * library, const struct TagItem * taglist);
	struct Interface * APICALL (*MakeInterfaceTags)(struct ExecIFace *Self, struct Library * library, ...);
	void APICALL (*Permit)(struct ExecIFace *Self);
	APTR APICALL (*RawDoFmt)(struct ExecIFace *Self, CONST_STRPTR formatString, CONST_APTR dataStream, void (*PutChProc)(), APTR PutChData);
	struct Node * APICALL (*RemHead)(struct ExecIFace *Self, struct List * list);
	VOID APICALL (*RemMemHandler)(struct ExecIFace *Self, struct Interrupt * memHandler);
	void APICALL (*Remove)(struct ExecIFace *Self, struct Node * node);
	struct Node * APICALL (*RemTail)(struct ExecIFace *Self, struct List * list);
	ULONG APICALL (*TypeOfMem)(struct ExecIFace *Self, CONST_APTR address);
	APTR APICALL (*InitResident)(struct ExecIFace *Self, const struct Resident * resident, ULONG segList);
	void APICALL (*InitCode)(struct ExecIFace *Self, ULONG startClass, ULONG version);
	ULONG APICALL (*SumKickData)(struct ExecIFace *Self);
	APTR APICALL (*AddTask)(struct ExecIFace *Self, struct Task * task, CONST_APTR initialPC, CONST_APTR finalPC, const struct TagItem * tagList);
	APTR APICALL (*AddTaskTags)(struct ExecIFace *Self, struct Task * task, CONST_APTR initialPC, CONST_APTR finalPC, ...);
	void APICALL (*Disable)(struct ExecIFace *Self);
	void APICALL (*Enable)(struct ExecIFace *Self);
	void APICALL (*Reschedule)(struct ExecIFace *Self);
	struct Task * APICALL (*FindTask)(struct ExecIFace *Self, CONST_STRPTR name);
	void APICALL (*RemTask)(struct ExecIFace *Self, struct Task * task);
	BYTE APICALL (*SetTaskPri)(struct ExecIFace *Self, struct Task * task, BYTE priority);
	DEPRECATED void APICALL (*StackSwap)(struct ExecIFace *Self, struct StackSwapStruct * newstack);
	BYTE APICALL (*AllocSignal)(struct ExecIFace *Self, BYTE signalNum);
	void APICALL (*FreeSignal)(struct ExecIFace *Self, BYTE signalNum);
	ULONG APICALL (*SetExcept)(struct ExecIFace *Self, ULONG newSignals, ULONG signalMask);
	ULONG APICALL (*SetSignal)(struct ExecIFace *Self, ULONG newSignals, ULONG signalMask);
	void APICALL (*Signal)(struct ExecIFace *Self, struct Task * task, ULONG signals);
	ULONG APICALL (*Wait)(struct ExecIFace *Self, ULONG signalSet);
	void APICALL (*AddPort)(struct ExecIFace *Self, struct MsgPort * port);
	DEPRECATED struct MsgPort * APICALL (*CreatePort)(struct ExecIFace *Self, CONST_STRPTR name, BYTE pri);
	DEPRECATED struct MsgPort * APICALL (*CreateMsgPort)(struct ExecIFace *Self);
	DEPRECATED void APICALL (*DeletePort)(struct ExecIFace *Self, struct MsgPort * port);
	DEPRECATED void APICALL (*DeleteMsgPort)(struct ExecIFace *Self, struct MsgPort * port);
	struct MsgPort * APICALL (*FindPort)(struct ExecIFace *Self, CONST_STRPTR name);
	struct Message * APICALL (*GetMsg)(struct ExecIFace *Self, struct MsgPort * port);
	void APICALL (*PutMsg)(struct ExecIFace *Self, struct MsgPort * port, struct Message * message);
	void APICALL (*RemPort)(struct ExecIFace *Self, struct MsgPort * port);
	void APICALL (*ReplyMsg)(struct ExecIFace *Self, struct Message * message);
	struct Message * APICALL (*WaitPort)(struct ExecIFace *Self, struct MsgPort * port);
	void APICALL (*Cause)(struct ExecIFace *Self, struct Interrupt * interrupt);
	void APICALL (*AddSemaphore)(struct ExecIFace *Self, struct SignalSemaphore * semaphore);
	LONG APICALL (*AttemptSemaphore)(struct ExecIFace *Self, struct SignalSemaphore * semaphore);
	LONG APICALL (*AttemptSemaphoreShared)(struct ExecIFace *Self, struct SignalSemaphore * semaphore);
	struct SignalSemaphore * APICALL (*FindSemaphore)(struct ExecIFace *Self, CONST_STRPTR name);
	void APICALL (*InitSemaphore)(struct ExecIFace *Self, struct SignalSemaphore * semaphore);
	void APICALL (*ObtainSemaphore)(struct ExecIFace *Self, struct SignalSemaphore * semaphore);
	void APICALL (*ObtainSemaphoreList)(struct ExecIFace *Self, struct List * list);
	void APICALL (*ObtainSemaphoreShared)(struct ExecIFace *Self, struct SignalSemaphore * semaphore);
	void APICALL (*Procure)(struct ExecIFace *Self, struct SignalSemaphore * semaphore, struct SemaphoreMessage * bidMessage);
	void APICALL (*ReleaseSemaphore)(struct ExecIFace *Self, struct SignalSemaphore * semaphore);
	void APICALL (*ReleaseSemaphoreList)(struct ExecIFace *Self, struct List * list);
	void APICALL (*RemSemaphore)(struct ExecIFace *Self, struct SignalSemaphore * semaphore);
	void APICALL (*Vacate)(struct ExecIFace *Self, struct SignalSemaphore * semaphore, struct SemaphoreMessage * bidMessage);
	struct Task * APICALL (*CreateTask)(struct ExecIFace *Self, CONST_STRPTR name, LONG pri, CONST_APTR initPC, ULONG stackSize, const struct TagItem * tagList);
	struct Task * APICALL (*CreateTaskTags)(struct ExecIFace *Self, CONST_STRPTR name, LONG pri, CONST_APTR initPC, ULONG stackSize, ...);
	void APICALL (*DeleteTask)(struct ExecIFace *Self, struct Task * task);
	void APICALL (*SumLibrary)(struct ExecIFace *Self, struct Library * library);
	struct Library * APICALL (*CreateLibrary)(struct ExecIFace *Self, const struct TagItem * taglist);
	struct Library * APICALL (*CreateLibraryTags)(struct ExecIFace *Self, ULONG dataSize, ...);
	struct Library * APICALL (*OpenLibrary)(struct ExecIFace *Self, CONST_STRPTR name, ULONG version);
	APTR APICALL (*CloseLibrary)(struct ExecIFace *Self, struct Library * library);
	void APICALL (*AddLibrary)(struct ExecIFace *Self, struct Library * library);
	ULONG APICALL (*RemLibrary)(struct ExecIFace *Self, struct Library * library);
	void APICALL (*AddDevice)(struct ExecIFace *Self, struct Device * device);
	ULONG APICALL (*RemDevice)(struct ExecIFace *Self, struct Device * device);
	struct Interface * APICALL (*GetInterface)(struct ExecIFace *Self, struct Library * library, CONST_STRPTR name, ULONG version, const struct TagItem * taglist);
	struct Interface * APICALL (*GetInterfaceTags)(struct ExecIFace *Self, struct Library * library, CONST_STRPTR name, ULONG version, ...);
	void APICALL (*DropInterface)(struct ExecIFace *Self, struct Interface * interface);
	void APICALL (*AddInterface)(struct ExecIFace *Self, struct Library * library, struct Interface * interface);
	void APICALL (*RemInterface)(struct ExecIFace *Self, struct Interface * interface);
	void APICALL (*SumInterface)(struct ExecIFace *Self, struct Interface * interface);
	struct Resident * APICALL (*FindResident)(struct ExecIFace *Self, CONST_STRPTR name);
	APTR APICALL (*SetMethod)(struct ExecIFace *Self, struct Interface * interface, LONG funcOffset, CONST_APTR newFunc);
	void APICALL (*DeleteInterface)(struct ExecIFace *Self, struct Interface * interface);
	void APICALL (*DeleteLibrary)(struct ExecIFace *Self, struct Library * library);
	APTR APICALL (*SetFunction)(struct ExecIFace *Self, struct Library * library, LONG funcOffset, CONST_APTR newFunc);
	void APICALL (*CacheClearE)(struct ExecIFace *Self, APTR address, ULONG length, ULONG caches);
	DEPRECATED void APICALL (*CacheClearU)(struct ExecIFace *Self);
	ULONG APICALL (*MakeFunctions)(struct ExecIFace *Self, APTR target, CONST_APTR functionArray, CONST_APTR funcDispBase);
	LONG APICALL (*OpenDevice)(struct ExecIFace *Self, CONST_STRPTR devName, ULONG unitNumber, struct IORequest * ioRequest, ULONG flags);
	APTR APICALL (*CloseDevice)(struct ExecIFace *Self, struct IORequest * ioRequest);
	DEPRECATED struct IORequest * APICALL (*CreateIORequest)(struct ExecIFace *Self, const struct MsgPort * ioReplyPort, ULONG size);
	DEPRECATED void APICALL (*DeleteIORequest)(struct ExecIFace *Self, struct IORequest * ioRequest);
	void APICALL (*AbortIO)(struct ExecIFace *Self, struct IORequest * ioRequest);
	struct IORequest * APICALL (*CheckIO)(struct ExecIFace *Self, struct IORequest * ioRequest);
	BYTE APICALL (*DoIO)(struct ExecIFace *Self, struct IORequest * ioRequest);
	void APICALL (*SendIO)(struct ExecIFace *Self, struct IORequest * ioRequest);
	void APICALL (*BeginIO)(struct ExecIFace *Self, struct IORequest * ioRequest);
	BYTE APICALL (*WaitIO)(struct ExecIFace *Self, struct IORequest * ioRequest);
	void APICALL (*AddResource)(struct ExecIFace *Self, APTR resource);
	void APICALL (*RemResource)(struct ExecIFace *Self, APTR resource);
	APTR APICALL (*OpenResource)(struct ExecIFace *Self, CONST_STRPTR resName);
	BOOL APICALL (*AddIntServer)(struct ExecIFace *Self, ULONG intNum, struct Interrupt * interrupt);
	void APICALL (*RemIntServer)(struct ExecIFace *Self, ULONG intNum, struct Interrupt * interrupt);
	struct Interrupt * APICALL (*SetIntVector)(struct ExecIFace *Self, ULONG intNum, const struct Interrupt * interrupt);
	DEPRECATED ULONG APICALL (*ObtainQuickVector)(struct ExecIFace *Self, APTR interruptCode);
	void APICALL (*Alert)(struct ExecIFace *Self, ULONG alertNum);
	APTR APICALL (*SuperState)(struct ExecIFace *Self);
	void APICALL (*UserState)(struct ExecIFace *Self, APTR sysStack);
	ULONG APICALL (*Supervisor)(struct ExecIFace *Self, APTR userFunc);
	BOOL APICALL (*SetTaskTrap)(struct ExecIFace *Self, ULONG trapNum, CONST_APTR trapCode, CONST_APTR trapData);
	DEPRECATED LONG APICALL (*AllocTrap)(struct ExecIFace *Self, ULONG trapNum);
	DEPRECATED void APICALL (*FreeTrap)(struct ExecIFace *Self, ULONG trapNum);
	DEPRECATED UWORD APICALL (*GetCC)(struct ExecIFace *Self);
	DEPRECATED ULONG APICALL (*SetSR)(struct ExecIFace *Self, ULONG newSR, ULONG mask);
	struct AVLNode * APICALL (*AVL_AddNode)(struct ExecIFace *Self, struct AVLNode ** root, struct AVLNode * node, AVLNODECOMP func);
	struct AVLNode * APICALL (*AVL_FindFirstNode)(struct ExecIFace *Self, const struct AVLNode * root);
	struct AVLNode * APICALL (*AVL_FindLastNode)(struct ExecIFace *Self, const struct AVLNode * root);
	struct AVLNode * APICALL (*AVL_FindNextNodeByAddress)(struct ExecIFace *Self, const struct AVLNode * root);
	struct AVLNode * APICALL (*AVL_FindNextNodeByKey)(struct ExecIFace *Self, const struct AVLNode * root, AVLKey key, AVLKEYCOMP func);
	struct AVLNode * APICALL (*AVL_FindNode)(struct ExecIFace *Self, const struct AVLNode * root, AVLKey key, AVLKEYCOMP func);
	struct AVLNode * APICALL (*AVL_FindPrevNodeByAddress)(struct ExecIFace *Self, const struct AVLNode * root);
	struct AVLNode * APICALL (*AVL_FindPrevNodeByKey)(struct ExecIFace *Self, const struct AVLNode * root, AVLKey key, AVLKEYCOMP func);
	struct AVLNode * APICALL (*AVL_RemNodeByAddress)(struct ExecIFace *Self, struct AVLNode ** root, struct AVLNode * node);
	struct AVLNode * APICALL (*AVL_RemNodeByKey)(struct ExecIFace *Self, struct AVLNode ** root, AVLKey key, AVLKEYCOMP func);
	ULONG APICALL (*CacheControl)(struct ExecIFace *Self, ULONG cacheBits, ULONG cacheMask);
	BOOL APICALL (*LockMem)(struct ExecIFace *Self, APTR baseAddress, ULONG size);
	void APICALL (*UnlockMem)(struct ExecIFace *Self, APTR baseAddress, ULONG size);
	ULONG APICALL (*ReallocVec)(struct ExecIFace *Self, APTR memBlock, ULONG newSize, ULONG flags);
	APTR APICALL (*CachePreDMA)(struct ExecIFace *Self, CONST_APTR vaddr, ULONG * length, ULONG flags);
	void APICALL (*CachePostDMA)(struct ExecIFace *Self, CONST_APTR vaddr, ULONG * length, ULONG flags);
	ULONG APICALL (*StartDMA)(struct ExecIFace *Self, CONST_APTR startAddr, ULONG blockSize, ULONG flags);
	void APICALL (*EndDMA)(struct ExecIFace *Self, CONST_APTR startAddr, ULONG blockSize, ULONG flags);
	void APICALL (*GetDMAList)(struct ExecIFace *Self, CONST_APTR startAddr, ULONG blockSize, ULONG flags, struct DMAEntry * dmaList);
	struct Trackable * APICALL (*AddTrackable)(struct ExecIFace *Self, struct Task * usingTask, APTR object, struct Hook * destFunc);
	struct Trackable * APICALL (*FindTrackable)(struct ExecIFace *Self, struct Task * usingTask, APTR object);
	struct Trackable * APICALL (*RemTrackable)(struct ExecIFace *Self, struct Task * usingTask, struct Trackable * trackable);
	void APICALL (*DeleteTrackable)(struct ExecIFace *Self, struct Trackable * trackable);
	APTR APICALL (*AllocSysObject)(struct ExecIFace *Self, ULONG type, const struct TagItem * tags);
	APTR APICALL (*AllocSysObjectTags)(struct ExecIFace *Self, ULONG type, ...);
	void APICALL (*FreeSysObject)(struct ExecIFace *Self, ULONG type, APTR object);
	void APICALL (*SuspendTask)(struct ExecIFace *Self, struct Task * whichTask, ULONG flags);
	void APICALL (*RestartTask)(struct ExecIFace *Self, struct Task * whichTask, ULONG flags);
	void APICALL (*MoveList)(struct ExecIFace *Self, struct List * destinationList, struct List * sourceList);
	void APICALL (*NewList)(struct ExecIFace *Self, struct List * list);
	void APICALL (*NewMinList)(struct ExecIFace *Self, struct MinList * list);
	void APICALL (*ColdReboot)(struct ExecIFace *Self);
	struct Library * APICALL (*MakeLibrary)(struct ExecIFace *Self, CONST_APTR vectors, CONST_APTR structure, CONST_APTR init, ULONG dataSize, APTR segList);
	ULONG APICALL (*Emulate)(struct ExecIFace *Self, CONST_APTR InitPC, const struct TagItem * tagList);
	ULONG APICALL (*EmulateTags)(struct ExecIFace *Self, CONST_APTR InitPC, ...);
	void APICALL (*DebugPrintF)(struct ExecIFace *Self, CONST_STRPTR format, ...);
	BOOL APICALL (*IsNative)(struct ExecIFace *Self, CONST_APTR code);
	DEPRECATED LONG APICALL (*RawMayGetChar)(struct ExecIFace *Self);
	DEPRECATED void APICALL (*RawPutChar)(struct ExecIFace *Self, UBYTE c);
	void APICALL (*GetCPUInfo)(struct ExecIFace *Self, const struct TagItem * TagList);
	void APICALL (*GetCPUInfoTags)(struct ExecIFace *Self, ...);
	struct Task * APICALL (*OwnerOfMem)(struct ExecIFace *Self, CONST_APTR Address);
	BOOL APICALL (*AddResetCallback)(struct ExecIFace *Self, struct Interrupt * resetCallback);
	void APICALL (*RemResetCallback)(struct ExecIFace *Self, struct Interrupt * resetCallback);
	APTR APICALL (*ItemPoolAlloc)(struct ExecIFace *Self, APTR itemPool);
	void APICALL (*ItemPoolFree)(struct ExecIFace *Self, APTR itemPool, APTR item);
	void APICALL (*ItemPoolGC)(struct ExecIFace *Self, APTR itemPool);
	uint32 APICALL (*ItemPoolControl)(struct ExecIFace *Self, APTR itemPool, const struct TagItem * tagList);
	uint32 APICALL (*ItemPoolControlTags)(struct ExecIFace *Self, APTR itemPool, ...);
	void APICALL (*ItemPoolFlush)(struct ExecIFace *Self, APTR itemPool);
	struct Node * APICALL (*GetHead)(struct ExecIFace *Self, struct List * list);
	struct Node * APICALL (*GetTail)(struct ExecIFace *Self, struct List * list);
	struct Node * APICALL (*GetSucc)(struct ExecIFace *Self, struct Node * node);
	struct Node * APICALL (*GetPred)(struct ExecIFace *Self, struct Node * node);
	void APICALL (*IceColdReboot)(struct ExecIFace *Self);
	APTR APICALL (*KMemCacheCreate)(struct ExecIFace *Self, APTR VMA, CONST_STRPTR Name, uint32 Size, uint32 Align, CONST_APTR Constructor, CONST_APTR Destructor, uint32 Flag, APTR UserData);
	void APICALL (*KMemCacheDestroy)(struct ExecIFace *Self, APTR Cache);
	APTR APICALL (*KMemCacheAlloc)(struct ExecIFace *Self, APTR Cache, uint32 Flags);
	void APICALL (*KMemCacheFree)(struct ExecIFace *Self, APTR Cache, APTR object);
	void APICALL (*KMemCacheGrow)(struct ExecIFace *Self, APTR Cache, uint32 Flags);
	uint32 APICALL (*KMemCacheReap)(struct ExecIFace *Self, APTR Cache, uint32 NumPages, uint32 Flags);
	APTR APICALL (*KMemCacheFind)(struct ExecIFace *Self, CONST_STRPTR Name);
	APTR APICALL (*PageGet)(struct ExecIFace *Self, APTR VMA, uint32 numPages, uint32 alignment);
	BOOL APICALL (*PageMap)(struct ExecIFace *Self, APTR pageList, uint32 numPages, uint32 attrs, uint32 Flags);
	void APICALL (*PageUnmap)(struct ExecIFace *Self, APTR pageList, uint32 numPages);
	void APICALL (*PageDrop)(struct ExecIFace *Self, APTR pageList, uint32 numPages);
	APTR APICALL (*PageFindByVA)(struct ExecIFace *Self, APTR addressSpace, APTR virtualAddress);
	void APICALL (*PageHash)(struct ExecIFace *Self, APTR page);
	void APICALL (*PageUnhash)(struct ExecIFace *Self, APTR page);
	APTR APICALL (*PageBackendAlloc)(struct ExecIFace *Self, uint32 order, uint32 flags);
	void APICALL (*PageBackendFree)(struct ExecIFace *Self, APTR addr, uint32 order);
	void APICALL (*PageBackendLock)(struct ExecIFace *Self);
	void APICALL (*PageBackendUnlock)(struct ExecIFace *Self);
	void APICALL (*Obsolete1)(struct ExecIFace *Self);
	void APICALL (*Obsolete2)(struct ExecIFace *Self);
	void APICALL (*Obsolete3)(struct ExecIFace *Self);
	APTR APICALL (*RMapAlloc)(struct ExecIFace *Self, APTR Map, uint32 size, uint32 flags);
	void APICALL (*RMapFree)(struct ExecIFace *Self, APTR Map, APTR addr, uint32 size);
	BOOL APICALL (*VMAreaInit)(struct ExecIFace *Self, APTR addrspace, BOOL shared, APTR area, const struct TagItem * TagList);
	BOOL APICALL (*VMAreaInitTags)(struct ExecIFace *Self, APTR addrspace, BOOL shared, APTR area, ...);
	void APICALL (*VMAreaTerm)(struct ExecIFace *Self, APTR area);
	APTR APICALL (*AllocVecTagList)(struct ExecIFace *Self, uint32 size, const struct TagItem * tags);
	APTR APICALL (*AllocVecTags)(struct ExecIFace *Self, uint32 size, ...);
	BOOL APICALL (*PageMapAligned)(struct ExecIFace *Self, void * pageList, uint32 numPages, uint32 alignment, uint32 attrs, uint32 Flags);
	APTR APICALL (*RMapExtAlloc)(struct ExecIFace *Self, APTR Map, uint32 size, uint32 alignment, uint32 flags);
	void APICALL (*RMapExtFree)(struct ExecIFace *Self, APTR Map, APTR addr, uint32 size);
	APTR APICALL (*PageBackendAllocAligned)(struct ExecIFace *Self, uint32 order, uint32 alignment, uint32 flags);
	APTR APICALL (*AllocNamedMemory)(struct ExecIFace *Self, uint32 byteSize, CONST_STRPTR space, CONST_STRPTR name, struct TagItem * tagList);
	APTR APICALL (*AllocNamedMemoryTags)(struct ExecIFace *Self, uint32 byteSize, CONST_STRPTR space, CONST_STRPTR name, ...);
	BOOL APICALL (*FreeNamedMemory)(struct ExecIFace *Self, CONST_STRPTR space, CONST_STRPTR name);
	void * APICALL (*FindNamedMemory)(struct ExecIFace *Self, CONST_STRPTR space, CONST_STRPTR name);
	void APICALL (*UpdateNamedMemory)(struct ExecIFace *Self, CONST_STRPTR space, CONST_STRPTR name);
	void * APICALL (*LockNamedMemory)(struct ExecIFace *Self, CONST_STRPTR space, CONST_STRPTR name);
	void * APICALL (*AttemptNamedMemory)(struct ExecIFace *Self, CONST_STRPTR space, CONST_STRPTR name);
	void APICALL (*UnlockNamedMemory)(struct ExecIFace *Self, CONST_STRPTR space, CONST_STRPTR name);
	uint32 APICALL (*ScanNamedMemory)(struct ExecIFace *Self, struct Hook * scHook, uint32 flags, APTR user);
	struct MemList * APICALL (*AllocTaskMemEntry)(struct ExecIFace *Self, struct MemList * memList);
	APTR APICALL (*PagerFindPageOut)(struct ExecIFace *Self, uint32 nFlags);
	BOOL APICALL (*PagerPageIn)(struct ExecIFace *Self, APTR pPage, uint32 nFlags);
	BOOL APICALL (*PagerPageOut)(struct ExecIFace *Self, APTR pPage, uint32 nFlags, APTR pReceiver);
	BOOL APICALL (*PagerAssignPager)(struct ExecIFace *Self, APTR pPage, uint32 nFlags);
	VOID APICALL (*MutexObtain)(struct ExecIFace *Self, APTR Mutex);
	BOOL APICALL (*MutexAttempt)(struct ExecIFace *Self, APTR Mutex);
	VOID APICALL (*MutexRelease)(struct ExecIFace *Self, APTR Mutex);
	uint32 APICALL (*MutexAttemptWithSignal)(struct ExecIFace *Self, APTR Mutex, uint32 SigSet);
	int32 APICALL (*NewStackRun)(struct ExecIFace *Self, APTR initPC, const struct TagItem * TagList);
	int32 APICALL (*NewStackRunTags)(struct ExecIFace *Self, APTR initPC, ...);
};

/**********************************************************************************************/

struct ExpansionIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ExpansionIFace *Self);
	ULONG APICALL (*Release)(struct ExpansionIFace *Self);
	void APICALL (*Expunge)(struct ExpansionIFace *Self);
	struct Interface * APICALL (*Clone)(struct ExpansionIFace *Self);
	void APICALL (*AddConfigDev)(struct ExpansionIFace *Self, struct ConfigDev * configDev);
	BOOL APICALL (*AddBootNode)(struct ExpansionIFace *Self, LONG bootPri, ULONG flags, APTR deviceNode, struct ConfigDev * configDev);
	ULONG APICALL (*AllocBoardMem)(struct ExpansionIFace *Self, ULONG slotSpec);
	struct ConfigDev * APICALL (*AllocConfigDev)(struct ExpansionIFace *Self);
	APTR APICALL (*AllocExpansionMem)(struct ExpansionIFace *Self, ULONG numSlots, ULONG slotAlign);
	ULONG APICALL (*ConfigBoard)(struct ExpansionIFace *Self, APTR board, struct ConfigDev * configDev);
	ULONG APICALL (*ConfigChain)(struct ExpansionIFace *Self, APTR baseAddr);
	struct ConfigDev * APICALL (*FindConfigDev)(struct ExpansionIFace *Self, const struct ConfigDev * oldConfigDev, LONG manufacturer, LONG product);
	void APICALL (*FreeBoardMem)(struct ExpansionIFace *Self, ULONG startSlot, ULONG slotSpec);
	void APICALL (*FreeConfigDev)(struct ExpansionIFace *Self, struct ConfigDev * configDev);
	void APICALL (*FreeExpansionMem)(struct ExpansionIFace *Self, ULONG startSlot, ULONG numSlots);
	UBYTE APICALL (*ReadExpansionByte)(struct ExpansionIFace *Self, CONST_APTR board, ULONG offset);
	ULONG APICALL (*ReadExpansionRom)(struct ExpansionIFace *Self, CONST_APTR board, struct ConfigDev * configDev);
	void APICALL (*RemConfigDev)(struct ExpansionIFace *Self, struct ConfigDev * configDev);
	void APICALL (*WriteExpansionByte)(struct ExpansionIFace *Self, APTR board, ULONG offset, UBYTE byte);
	void APICALL (*ObtainConfigBinding)(struct ExpansionIFace *Self);
	void APICALL (*ReleaseConfigBinding)(struct ExpansionIFace *Self);
	void APICALL (*SetCurrentBinding)(struct ExpansionIFace *Self, struct CurrentBinding * currentBinding, ULONG bindingSize);
	ULONG APICALL (*GetCurrentBinding)(struct ExpansionIFace *Self, const struct CurrentBinding * currentBinding, ULONG bindingSize);
	struct DeviceNode * APICALL (*MakeDosNode)(struct ExpansionIFace *Self, CONST_APTR parmPacket);
	BOOL APICALL (*AddDosNode)(struct ExpansionIFace *Self, LONG bootPri, ULONG flags, struct DeviceNode * deviceNode);
	void APICALL (*WriteExpansionWord)(struct ExpansionIFace *Self, APTR board, ULONG offset, UWORD word);
	ULONG APICALL (*GetMachineInfo)(struct ExpansionIFace *Self, const struct TagItem * tagList);
	ULONG APICALL (*GetMachineInfoTags)(struct ExpansionIFace *Self, ...);
};

/**********************************************************************************************/

struct ExtendedDeadKey
{
    ULONG Reserved;
    UWORD Prev1DownClass;
    UWORD Prev1DownCode;
    UWORD Prev1DownQual;
    UWORD Prev2DownClass;
    UWORD Prev2DownCode;
    UWORD Prev2DownQual;
};

/**********************************************************************************************/

struct ExtendedLibrary
{
    struct Library *                 Parent;     /* Back pointer to self */
    struct LibraryManagerInterface * ILibrary;   /* Library interface */
    struct DeviceManagerInterface *  IDevice;    /* Device interface */
    struct List                      Interfaces; /* List of interfaces
                                                  * exported by this library */
    uint32                           ExtFlags;   /* Extended flags */
    struct Interface *               MainIFace;  /* For 68k cross-calls */
};

/**********************************************************************************************/

struct FDNResource
{
    struct Library  ResourceNode;


    /*
    ** Notification request list functions
    ** This resource was added in doslib 53.23
    */
    struct List * VARARGS68K (*ObtainNotifyList)  (void);
    void          VARARGS68K (*ReleaseNotifyList) (struct List *);


    /*
    ** DOS event monitoring functions.
    ** These vectors were added in doslib 53.81 - previously NULL pointers.
    */
    void          VARARGS68K (*AddEventHook)      (struct Hook *);
    void          VARARGS68K (*RemoveEventHook)   (struct Hook *);


    int32         Reserved[4];
};

/**********************************************************************************************/

struct FileSystemData
{
    uint32             fsd_Size;           /* the size of this structure   */
    STRPTR             fsd_FileSystemName;
    STRPTR             fsd_DeviceName;
    uint32             fsd_DeviceUnit;
    uint32             fsd_DeviceFlags;
    struct DosEnvec *  fsd_Environment;    /* WARNING: See (Note 1) below    */
    APTR               fsd_DosPrivate[4];  /* this really is dos private ! */
    APTR               fsd_Reserved[4];
};

/**********************************************************************************************/

struct FileSystemVectorPort
{
   struct MsgPort            MP;
   struct FileSystemVectors  FSV;
};

/**********************************************************************************************/

struct FileSystemVectors
{
    uint32         StructSize;  /* Filesystem must initialise this to; sizeof(struct FileSystemVectors) */
    uint32         Version;     /* Filesystem must initialise this to; FS_VECTORPORT_VERSION  */

    APTR           FSPrivate;   /* Private field for exclusive use by the filesystem, this is generally */
                                /* used to point to the filesystems private global data structure to    */
                                /* make it accessible from the vector-port functions.                   */
                                /* Optionally, the filesystem may just initialise this to zero and then */
                                /* after the AllocDosObject() call, place your required data in there.  */

    uint32         Reserved[3]; /* Filesystems initialise these to 0 - reserved expansion */

    APTR           DOSPrivate;  /* Filesystems initialise this  to 0 - private DOS usage */

    void           (*DOSEmulatePacket)(struct FSVP *vp, struct DosPacket *dp);
                   /* Filesystems shall initialise this to NULL.  */
                   /* AllocDosObject() will insert a function pointer here for the filesystem to use.  */
                   /* This function is to be called from the packet handler process of the filesystem  */
                   /* to provide legacy emulation support for old applications that send Dospackets    */
                   /* directly to the filesystem message port.                                         */
                   /* See; "dos.dospacket.doc" for further details and example source code for this.   */


    /***************************************************************************************************/

    struct Lock * (*FSLock)(struct FSVP *vp, int32 *res2, struct Lock *rel_lock, CONST_STRPTR obj, int32 mode);
                  /* Equivalent function for ACTION_LOCK.
                   * Always returns a SHARED_LOCK for directories no matter what 'mode' is requested.
                   * The EXCLUSIVE_LOCK mode is for files only.
                   */

    int32         (*FSUnLock)(struct FSVP *vp, int32 *res2, struct Lock *lock);
                  /* Equivalent function for ACTION_UNLOCK */

    struct Lock * (*FSDupLock)(struct FSVP *vp, int32 *res2, struct Lock *lock);
                  /* Equivalent function for ACTION_COPY_LOCK */

    struct Lock * (*FSCreateDir)(struct FSVP *vp, int32 *res2, struct Lock *rel_lock, CONST_STRPTR obj);
                  /* Equivalent function for ACTION_CREATE_DIR - always returns a SHARED_LOCK */

    struct Lock * (*FSParentDir)(struct FSVP *vp, int32 *res2, struct Lock *dirlock);
                  /* Equivalent function for ACTION_PARENT - always returns a SHARED_LOCK */


    struct Lock * (*FSDupLockFromFH)(struct FSVP *vp, int32 *res2, struct FileHandle *filehandle);
                  /* Equivalent function for ACTION_COPY_LOCK_FH */

    int32         (*FSOpenFromLock)(struct FSVP *vp, int32 *res2, struct FileHandle *file, struct Lock *lock);
                  /* Equivalent function for ACTION_FH_FROM_LOCK */

    struct Lock * (*FSParentOfFH)(struct FSVP *vp, int32 *res2, struct FileHandle *file);
                  /* Equivalent function for ACTION_PARENT_FH   */


    int32         (*FSOpen)(struct FSVP *vp, int32 *res2, struct FileHandle *fh, struct Lock *rel_dir, CONST_STRPTR obj, int32 mode);
                  /* Equivalent function for ACTION_FINDUPDATE, ACTION_FINDINPUT, ACTION_FINDOUTPUT */

    int32         (*FSClose)(struct FSVP *vp, int32 *res2, struct FileHandle *file);
                  /* Equivalent function for ACTION_END */

    int32         (*FSDelete)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR obj);
                  /* Equivalent function for ACTION_DELETE_OBJECT */

    int32         (*FSRead)(struct FSVP *vp, int32 *res2, struct FileHandle *file, STRPTR buffer, int32 numbytes);
                  /* Equivalent function for ACTION_READ */

    int32         (*FSWrite)(struct FSVP *vp, int32 *res2, struct FileHandle *file, STRPTR buffer, int32 numbytes);
                  /* Equivalent function for ACTION_WRITE */

    int32         (*FSFlush)(struct FSVP *vp, int32 *res2);
                  /* Equivalent function for ACTION_FLUSH  */


    int32         (*FSChangeFilePosition)(struct FSVP *vp, int32 *res2, struct FileHandle *file, int32 mode, int64 position);
                  /* Equivalent function for ACTION_CHANGE_FILE_POSITION64  */

    int32         (*FSChangeFileSize)(struct FSVP *vp, int32 *res2, struct FileHandle *file, int32 mode, int64 size);
                  /* Equivalent function for ACTION_CHANGE_FILE_SIZE64 */


    int64         (*FSGetFilePosition)(struct FSVP *vp, int32 *res2, struct FileHandle *file );
                  /* Equivalent function for ACTION_GET_FILE_POSITION64 */

    int64         (*FSGetFileSize)(struct FSVP *vp, int32 *res2, struct FileHandle *file );
                  /* Equivalent function for ACTION_GET_FILE_SIZE64 */


    int32         (*FSChangeLockMode)(struct FSVP *vp, int32 *res2, struct Lock *lock, int32 new_lock_mode);
                  /* Equivalent function for ACTION_CHANGE_MODE (LOCK) - never changes directories from a SHARED_LOCK */

    int32         (*FSChangeFileMode)(struct FSVP *vp, int32 *res2, struct FileHandle *fh, int32 new_lock_mode);
                  /* Equivalent function for ACTION_CHANGE_MODE (FILE) */


    int32         (*FSSetDate)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, const struct DateStamp *ds);
                  /* Equivalent function for ACTION_SET_DATE */

    int32         (*FSSetProtection)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, uint32 mask);
                  /* Equivalent function for ACTION_SET_PROTECT */

    int32         (*FSSetComment)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, CONST_STRPTR comment);
                  /* Equivalent function for ACTION_SET_COMMENT */

    int32         (*FSSetGroup)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, uint32 group);
                  /* Equivalent function for ACTION_SET_OWNER / ACTION_SET_OWNER_INFO */

    int32         (*FSSetOwner)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock, CONST_STRPTR name, uint32 owner);
                  /* Equivalent function for ACTION_SET_OWNER / ACTION_SET_OWNER_INFO */

    int32         (*FSRename)(struct FSVP *vp, int32 *res2, struct Lock *src_rel, CONST_STRPTR src,
                              struct Lock *dst_rel, CONST_STRPTR dst);
                  /* Equivalent function for ACTION_RENAME_OBJECT */


    int32         (*FSCreateSoftLink)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock,
                                      CONST_STRPTR linkname, CONST_STRPTR dest_obj);
                  /* Equivalent function for ACTION_MAKE_LINK (SOFT) */

    int32         (*FSCreateHardLink)(struct FSVP *vp, int32 *res2, struct Lock *rel_dirlock,
                                      CONST_STRPTR linkname, struct Lock *dest_obj);
                  /* Equivalent function for ACTION_MAKE_LINK (HARD) */

    int32         (*FSReadSoftLink)(struct FSVP *vp, int32 *res2, struct Lock *rel_dir,
                                    CONST_STRPTR linkname, STRPTR buf, int32 bufsize);
                  /* Equivalent function for ACTION_READ_SOFT_LINK */


    int32         (*FSSameLock)(struct FSVP *vp, int32 *res2, struct Lock *lock1, struct Lock *lock2);
                  /* Equivalent function for ACTION_SAME_LOCK */

    int32         (*FSSameFile)(struct FSVP *vp, int32 *res2, struct FileHandle *fh1, struct FileHandle *fh2);
                  /* Equivalent function for ACTION_SAME_FH */


    int32         (*FSFileSystemAttr)(struct FSVP *vp, int32 *res2, struct TagItem *taglist);
                  /* Equivalent function for ACTION_FILESYSTEM_ATTR  */

    int32         (*FSVolumeInfoData)(struct FSVP *vp, int32 *res2, struct InfoData *info);
                  /* Equivalent function for ACTION_INFO. */

    int32         (*FSDeviceInfoData)(struct FSVP *vp, int32 *res2, struct InfoData *info);
                  /* Equivalent function for ACTION_DISK_INFO. */


    int32         (*FSReserved1)(struct FSVP *vp, int32 *res2);
                  /* Spare function slot, Filesystems initialise this to NULL */

    int32         (*FSReserved2)(struct FSVP *vp, int32 *res2);
                  /* Spare function slot, Filesystems initialise this to NULL */


    struct ExamineData *
                  (*FSExamineLock)(struct FSVP *vp, int32 *res2, struct Lock *lock);
                  /* Equivalent function for ACTION_EXAMINEDATA */

    struct ExamineData *
                  (*FSExamineFile)(struct FSVP *vp, int32 *res2, struct FileHandle *file);
                  /* Equivalent function for ACTION_EXAMINEDATA_FH */

    int32         (*FSExamineDir)(struct FSVP *vp, int32 *res2, struct PRIVATE_ExamineDirContext *ctx);
                  /* Equivalent function for ACTION_EXAMINEDATA_DIR */



    int32         (*FSInhibit)(struct FSVP *vp, int32 *res2, int32 inhibit_state);
                  /* Equivalent function for ACTION_INHIBIT  */

    int32         (*FSWriteProtect)(struct FSVP *vp, int32 *res2, int32 wp_state, uint32 passkey);
                  /* Equivalent function for ACTION_WRITE_PROTECT */

    int32         (*FSFormat)(struct FSVP *vp, int32 *res2, CONST_STRPTR new_volname, uint32 dostype);
                  /* Equivalent function for ACTION_FORMAT */

    int32         (*FSSerialize)(struct FSVP *vp, int32 *res2);
                  /* Equivalent function for ACTION_SERIALIZE_DISK */

    int32         (*FSRelabel)(struct FSVP *vp, int32 *res2, CONST_STRPTR new_volumename);
                  /* Equivalent function for ACTION_RENAME_DISK */


    int32         (*FSReserved3)(struct FSVP *vp, int32 *res2);
                  /* Spare function slot, Filesystems initialise this to NULL */



   /*************************************************************************
    **  OPTIONAL FUNCTIONS
    **  ==================
    **  The following two notification functions are optional, the dos.library
    **  provides these functions internally when these functions returns FALSE
    **  and Result2 = ERROR_ACTION_NOT_KNOWN.
    **  These vectors have been provided for remote filesystem implementations.
    */

    int32         (*FSAddNotify)(struct FSVP *vp, int32 *res2, struct NotifyRequest *nr);
                  /* Equivalent function for ACTION_ADD_NOTIFY */

    int32         (*FSRemoveNotify)(struct FSVP *vp, int32 *res2, struct NotifyRequest *nr);
                  /* Equivalent function for ACTION_REMOVE_NOTIFY */



  /*************************************************************************
    **  OPTIONAL FUNCTIONS
    **  ==================
    **  The following two record locking functions are optional, the dos.library
    **  provides these functions internally when these vector functions returns
    **  FALSE and Result2 = ERROR_ACTION_NOT_KNOWN.
    **  These vectors have been provided for remote filesystem implementations.
    */

    int32         (*FSLockRecord)(struct FSVP *vp, int32 *res2, struct FileHandle *file,
                                  int64 offset, int64 length, uint32 mode, uint32 timeout);
                  /* Equivalent function for ACTION_LOCK_RECORD64 */

    int32         (*FSUnLockRecord)(struct FSVP *vp, int32 *res2, struct FileHandle *file,
                                    int64 offset, int64 length);
                  /* Equivalent function for ACTION_FREE_RECORD64 */




    /*=== End of V53 vectors, - New V54 vectors to be added after this line ===*/

    int32         End_Marker;  /* This must always be at vector table end, set to -1 */
};

/**********************************************************************************************/

struct FillerIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct FillerIFace *Self);
	ULONG APICALL (*Release)(struct FillerIFace *Self);
	void APICALL (*Expunge)(struct FillerIFace *Self);
	struct Interface * APICALL (*Clone)(struct FillerIFace *Self);
	Class * APICALL (*FILLER_GetClass)(struct FillerIFace *Self);
};

/**********************************************************************************************/

struct FindTrackedAddressMsg
{
    int32                 ftam_Size;
    STRPTR                ftam_Name;
    struct DateStamp      ftam_Date;
    BPTR                  ftam_SegList;
    uint32                ftam_SegmentNumber;
    uint32                ftam_SegmentOffset;
    APTR                  ftam_ExtraInfo;
    int32                 ftam_ExtraInfoSize;
/* 40 bytes @ V50 */
    struct AddressAndSize ftam_AAS;
/* 48 bytes @ 53.118 */
};

/**********************************************************************************************/

struct FReadLineData
{
    STRPTR   frld_Line;           /* NUL-terminated string */
    uint32   frld_LineLength;     /* what strlen(frld_Line) would return */
    uint32   frld_DosPrivate[8];  /* -- internal dos.library use only */
};

/**********************************************************************************************/

struct FuelGaugeIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct FuelGaugeIFace *Self);
	ULONG APICALL (*Release)(struct FuelGaugeIFace *Self);
	void APICALL (*Expunge)(struct FuelGaugeIFace *Self);
	struct Interface * APICALL (*Clone)(struct FuelGaugeIFace *Self);
	Class * APICALL (*FUELGAUGE_GetClass)(struct FuelGaugeIFace *Self);
};

/**********************************************************************************************/

struct GadgetGeometryMsg
{
    ULONG            ggm_MethodID;     /* One of the SG_ definitions above  */
    struct Window   *ggm_Window;       /* Reference window (may be NULL)    */
    struct DrawInfo *ggm_DrawInfo;     /* Context information               */
    struct IBox      ggm_BoundingBox;  /* (Output) Box computed by the hook */
    struct IBox      ggm_HitBox;       /* (Output) Box computed by the hook */
    APTR             ggm_IAddress;     /* Gadget-specific data (see below)  */
    ULONG            ggm_Flags;        /* More information                  */
};

/**********************************************************************************************/

struct GadToolsIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct GadToolsIFace *Self);
	ULONG APICALL (*Release)(struct GadToolsIFace *Self);
	void APICALL (*Expunge)(struct GadToolsIFace *Self);
	struct Interface * APICALL (*Clone)(struct GadToolsIFace *Self);
	struct Gadget * APICALL (*CreateGadgetA)(struct GadToolsIFace *Self, ULONG kind, struct Gadget * gad, const struct NewGadget * ng, const struct TagItem * taglist);
	struct Gadget * APICALL (*CreateGadget)(struct GadToolsIFace *Self, ULONG kind, struct Gadget * gad, const struct NewGadget * ng, ...);
	VOID APICALL (*FreeGadgets)(struct GadToolsIFace *Self, struct Gadget * gad);
	VOID APICALL (*GT_SetGadgetAttrsA)(struct GadToolsIFace *Self, struct Gadget * gad, struct Window * win, struct Requester * req, const struct TagItem * taglist);
	VOID APICALL (*GT_SetGadgetAttrs)(struct GadToolsIFace *Self, struct Gadget * gad, struct Window * win, struct Requester * req, ...);
	struct Menu * APICALL (*CreateMenusA)(struct GadToolsIFace *Self, const struct NewMenu * newmenu, const struct TagItem * taglist);
	struct Menu * APICALL (*CreateMenus)(struct GadToolsIFace *Self, const struct NewMenu * newmenu, ...);
	VOID APICALL (*FreeMenus)(struct GadToolsIFace *Self, struct Menu * menu);
	BOOL APICALL (*LayoutMenuItemsA)(struct GadToolsIFace *Self, struct MenuItem * firstitem, APTR vi, const struct TagItem * taglist);
	BOOL APICALL (*LayoutMenuItems)(struct GadToolsIFace *Self, struct MenuItem * firstitem, APTR vi, ...);
	BOOL APICALL (*LayoutMenusA)(struct GadToolsIFace *Self, struct Menu * firstmenu, APTR vi, const struct TagItem * taglist);
	BOOL APICALL (*LayoutMenus)(struct GadToolsIFace *Self, struct Menu * firstmenu, APTR vi, ...);
	struct IntuiMessage * APICALL (*GT_GetIMsg)(struct GadToolsIFace *Self, struct MsgPort * iport);
	VOID APICALL (*GT_ReplyIMsg)(struct GadToolsIFace *Self, struct IntuiMessage * imsg);
	VOID APICALL (*GT_RefreshWindow)(struct GadToolsIFace *Self, struct Window * win, struct Requester * req);
	VOID APICALL (*GT_BeginRefresh)(struct GadToolsIFace *Self, struct Window * win);
	VOID APICALL (*GT_EndRefresh)(struct GadToolsIFace *Self, struct Window * win, BOOL complete);
	struct IntuiMessage * APICALL (*GT_FilterIMsg)(struct GadToolsIFace *Self, const struct IntuiMessage * imsg);
	struct IntuiMessage * APICALL (*GT_PostFilterIMsg)(struct GadToolsIFace *Self, struct IntuiMessage * imsg);
	struct Gadget * APICALL (*CreateContext)(struct GadToolsIFace *Self, struct Gadget ** glistptr);
	VOID APICALL (*DrawBevelBoxA)(struct GadToolsIFace *Self, struct RastPort * rport, WORD left, WORD top, WORD width, WORD height, const struct TagItem * taglist);
	VOID APICALL (*DrawBevelBox)(struct GadToolsIFace *Self, struct RastPort * rport, WORD left, WORD top, WORD width, WORD height, ...);
	APTR APICALL (*GetVisualInfoA)(struct GadToolsIFace *Self, struct Screen * screen, const struct TagItem * taglist);
	APTR APICALL (*GetVisualInfo)(struct GadToolsIFace *Self, struct Screen * screen, ...);
	VOID APICALL (*FreeVisualInfo)(struct GadToolsIFace *Self, APTR vi);
	VOID APICALL (*GTReserved0)(struct GadToolsIFace *Self);
	VOID APICALL (*GTReserved1)(struct GadToolsIFace *Self);
	VOID APICALL (*GTReserved2)(struct GadToolsIFace *Self);
	VOID APICALL (*GTReserved3)(struct GadToolsIFace *Self);
	VOID APICALL (*GTReserved4)(struct GadToolsIFace *Self);
	VOID APICALL (*GTReserved5)(struct GadToolsIFace *Self);
	LONG APICALL (*GT_GetGadgetAttrsA)(struct GadToolsIFace *Self, struct Gadget * gad, struct Window * win, struct Requester * req, const struct TagItem * taglist);
	LONG APICALL (*GT_GetGadgetAttrs)(struct GadToolsIFace *Self, struct Gadget * gad, struct Window * win, struct Requester * req, ...);
};

/**********************************************************************************************/

struct gcRequest
{
    ULONG           MethodID;   /* GCOLOR_REQUEST */
    struct Window * gcr_Window; /* The window that will be locked when
                                   the requester is active.
                                   MUST be provided! */
};

/**********************************************************************************************/

struct GetColorIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct GetColorIFace *Self);
	ULONG APICALL (*Release)(struct GetColorIFace *Self);
	void APICALL (*Expunge)(struct GetColorIFace *Self);
	struct Interface * APICALL (*Clone)(struct GetColorIFace *Self);
	Class * APICALL (*GETCOLOR_GetClass)(struct GetColorIFace *Self);
};

/**********************************************************************************************/

struct GetFileIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct GetFileIFace *Self);
	ULONG APICALL (*Release)(struct GetFileIFace *Self);
	void APICALL (*Expunge)(struct GetFileIFace *Self);
	struct Interface * APICALL (*Clone)(struct GetFileIFace *Self);
	Class * APICALL (*GETFILE_GetClass)(struct GetFileIFace *Self);
};

/**********************************************************************************************/

struct GetFontIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct GetFontIFace *Self);
	ULONG APICALL (*Release)(struct GetFontIFace *Self);
	void APICALL (*Expunge)(struct GetFontIFace *Self);
	struct Interface * APICALL (*Clone)(struct GetFontIFace *Self);
	Class * APICALL (*GETFONT_GetClass)(struct GetFontIFace *Self);
};

/**********************************************************************************************/

struct GetScreenModeIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct GetScreenModeIFace *Self);
	ULONG APICALL (*Release)(struct GetScreenModeIFace *Self);
	void APICALL (*Expunge)(struct GetScreenModeIFace *Self);
	struct Interface * APICALL (*Clone)(struct GetScreenModeIFace *Self);
	Class * APICALL (*GETSCREENMODE_GetClass)(struct GetScreenModeIFace *Self);
};

/**********************************************************************************************/

struct GlyphIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct GlyphIFace *Self);
	ULONG APICALL (*Release)(struct GlyphIFace *Self);
	void APICALL (*Expunge)(struct GlyphIFace *Self);
	struct Interface * APICALL (*Clone)(struct GlyphIFace *Self);
	Class * APICALL (*GLYPH_GetClass)(struct GlyphIFace *Self);
};

/**********************************************************************************************/

struct GlyphWidthEntry32
{
    struct MinNode gwe32_Node;     /* on list returned by OT_WidthList32 inquiry */
    UWORD          gwe32_reserved; /* for alignment and backwards compatibility */
    FIXED          gwe32_Width;    /* character advance, as fraction of em width */
    ULONG          gwe32_Code;     /* entry's character code value */
};

/**********************************************************************************************/

struct gpExtent
{
   ULONG              MethodID;
   struct GadgetInfo *gpe_GInfo;
   struct RastPort   *gpe_RPort;  /* NULL if masking not supported */
   struct Region     *gpe_Region; /* NULL if clipping not supported */
   ULONG              gpe_Action; /* Requested operation */
   ULONG              gpe_Flags;  /* Control flags, see below */
   struct TagItem    *gpe_Attrs;  /* Additional attributes */
};

/**********************************************************************************************/

struct gpQuery
{
   ULONG              MethodID;   /* always GM_QUERY */
   struct GadgetInfo *gpq_GInfo;  /* filled in by Intuition */
   struct InputEvent *gpq_IEvent; /* positional data is here */
   ULONG              gpq_Type;   /* see below */
   LONG              *gpq_Data;   /* the data being returned */
};

/**********************************************************************************************/

struct GradientSpec
{
    ULONG Direction; /* X:Y ratio as returned by DirectionVector(angle) */
    UWORD Mode;      /* See definitions below */
    union
    {
        struct
        {
            UWORD BasePen;     /* Base DrawInfo pen to be shaded */
            UBYTE Contrast[2]; /* Shade levels for gradient ends */
        } Rel;
        struct
        {
            UBYTE RGBStart[3]; /* Starting color of gradient */
            UBYTE RGBEnd[3];   /* Ending color of gradient */
        } Abs;
    } Specs;
    UBYTE Reserved[4];         /* For future use, leave to zero */
};

/**********************************************************************************************/

struct GraphicsIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct GraphicsIFace *Self);
	ULONG APICALL (*Release)(struct GraphicsIFace *Self);
	void APICALL (*Expunge)(struct GraphicsIFace *Self);
	struct Interface * APICALL (*Clone)(struct GraphicsIFace *Self);
	ULONG APICALL (*BltBitMap)(struct GraphicsIFace *Self, CONST struct BitMap * srcBitMap, WORD xSrc, WORD ySrc, struct BitMap * destBitMap, WORD xDest, WORD yDest, WORD xSize, WORD ySize, UBYTE minterm, UBYTE mask, PLANEPTR tempA);
	VOID APICALL (*BltTemplate)(struct GraphicsIFace *Self, CONST PLANEPTR source, WORD xSrc, WORD srcMod, struct RastPort * destRP, WORD xDest, WORD yDest, WORD xSize, WORD ySize);
	VOID APICALL (*ClearEOL)(struct GraphicsIFace *Self, struct RastPort * rp);
	VOID APICALL (*ClearScreen)(struct GraphicsIFace *Self, struct RastPort * rp);
	WORD APICALL (*TextLength)(struct GraphicsIFace *Self, struct RastPort * rp, CONST_STRPTR string, UWORD count);
	VOID APICALL (*Text)(struct GraphicsIFace *Self, struct RastPort * rp, CONST_STRPTR string, UWORD count);
	VOID APICALL (*SetFont)(struct GraphicsIFace *Self, struct RastPort * rp, struct TextFont * textFont);
	struct TextFont * APICALL (*OpenFont)(struct GraphicsIFace *Self, CONST struct TextAttr * textAttr);
	VOID APICALL (*CloseFont)(struct GraphicsIFace *Self, struct TextFont * textFont);
	ULONG APICALL (*AskSoftStyle)(struct GraphicsIFace *Self, struct RastPort * rp);
	ULONG APICALL (*SetSoftStyle)(struct GraphicsIFace *Self, struct RastPort * rp, ULONG style, ULONG enable);
	VOID APICALL (*AddBob)(struct GraphicsIFace *Self, struct Bob * bob, struct RastPort * rp);
	VOID APICALL (*AddVSprite)(struct GraphicsIFace *Self, struct VSprite * vSprite, struct RastPort * rp);
	VOID APICALL (*DoCollision)(struct GraphicsIFace *Self, struct RastPort * rp);
	VOID APICALL (*DrawGList)(struct GraphicsIFace *Self, struct RastPort * rp, struct ViewPort * vp);
	VOID APICALL (*InitGels)(struct GraphicsIFace *Self, struct VSprite * head, struct VSprite * tail, struct GelsInfo * gelsInfo);
	VOID APICALL (*InitMasks)(struct GraphicsIFace *Self, struct VSprite * vSprite);
	VOID APICALL (*RemIBob)(struct GraphicsIFace *Self, struct Bob * bob, struct RastPort * rp, struct ViewPort * vp);
	VOID APICALL (*RemVSprite)(struct GraphicsIFace *Self, struct VSprite * vSprite);
	VOID APICALL (*SetCollision)(struct GraphicsIFace *Self, ULONG num, VOID (*routine)(struct VSprite *gelA, struct VSprite *gelB), struct GelsInfo * gelsInfo);
	VOID APICALL (*SortGList)(struct GraphicsIFace *Self, struct RastPort * rp);
	VOID APICALL (*AddAnimOb)(struct GraphicsIFace *Self, struct AnimOb * anOb, struct AnimOb ** anKey, struct RastPort * rp);
	VOID APICALL (*Animate)(struct GraphicsIFace *Self, struct AnimOb ** anKey, struct RastPort * rp);
	BOOL APICALL (*GetGBuffers)(struct GraphicsIFace *Self, struct AnimOb * anOb, struct RastPort * rp, BOOL flag);
	VOID APICALL (*InitGMasks)(struct GraphicsIFace *Self, struct AnimOb * anOb);
	VOID APICALL (*DrawEllipse)(struct GraphicsIFace *Self, struct RastPort * rp, WORD xCenter, WORD yCenter, WORD a, WORD b);
	LONG APICALL (*AreaEllipse)(struct GraphicsIFace *Self, struct RastPort * rp, WORD xCenter, WORD yCenter, WORD a, WORD b);
	VOID APICALL (*LoadRGB4)(struct GraphicsIFace *Self, struct ViewPort * vp, CONST UWORD * colors, UWORD count);
	VOID APICALL (*InitRastPort)(struct GraphicsIFace *Self, struct RastPort * rp);
	VOID APICALL (*InitVPort)(struct GraphicsIFace *Self, struct ViewPort * vp);
	ULONG APICALL (*MrgCop)(struct GraphicsIFace *Self, struct View * view);
	ULONG APICALL (*MakeVPort)(struct GraphicsIFace *Self, struct View * view, struct ViewPort * vp);
	VOID APICALL (*LoadView)(struct GraphicsIFace *Self, struct View * view);
	VOID APICALL (*WaitBlit)(struct GraphicsIFace *Self);
	VOID APICALL (*SetRast)(struct GraphicsIFace *Self, struct RastPort * rp, UBYTE pen);
	VOID APICALL (*Move)(struct GraphicsIFace *Self, struct RastPort * rp, WORD x, WORD y);
	VOID APICALL (*Draw)(struct GraphicsIFace *Self, struct RastPort * rp, WORD x, WORD y);
	LONG APICALL (*AreaMove)(struct GraphicsIFace *Self, struct RastPort * rp, WORD x, WORD y);
	LONG APICALL (*AreaDraw)(struct GraphicsIFace *Self, struct RastPort * rp, WORD x, WORD y);
	LONG APICALL (*AreaEnd)(struct GraphicsIFace *Self, struct RastPort * rp);
	VOID APICALL (*WaitTOF)(struct GraphicsIFace *Self);
	VOID APICALL (*QBlit)(struct GraphicsIFace *Self, struct bltnode * blit);
	VOID APICALL (*InitArea)(struct GraphicsIFace *Self, struct AreaInfo * areaInfo, APTR vectorBuffer, WORD maxVectors);
	VOID APICALL (*SetRGB4)(struct GraphicsIFace *Self, struct ViewPort * vp, UWORD colindex, UBYTE red, UBYTE green, UBYTE blue);
	VOID APICALL (*QBSBlit)(struct GraphicsIFace *Self, struct bltnode * blit);
	VOID APICALL (*BltClear)(struct GraphicsIFace *Self, PLANEPTR memBlock, ULONG byteCount, ULONG flags);
	VOID APICALL (*RectFill)(struct GraphicsIFace *Self, struct RastPort * rp, WORD xMin, WORD yMin, WORD xMax, WORD yMax);
	VOID APICALL (*BltPattern)(struct GraphicsIFace *Self, struct RastPort * rp, CONST PLANEPTR mask, WORD xMin, WORD yMin, WORD xMax, WORD yMax, UWORD maskBPR);
	LONG APICALL (*ReadPixel)(struct GraphicsIFace *Self, struct RastPort * rp, WORD x, WORD y);
	LONG APICALL (*WritePixel)(struct GraphicsIFace *Self, struct RastPort * rp, WORD x, WORD y);
	BOOL APICALL (*Flood)(struct GraphicsIFace *Self, struct RastPort * rp, ULONG mode, WORD x, WORD y);
	VOID APICALL (*PolyDraw)(struct GraphicsIFace *Self, struct RastPort * rp, WORD count, CONST WORD * polyTable);
	VOID APICALL (*SetAPen)(struct GraphicsIFace *Self, struct RastPort * rp, UBYTE pen);
	VOID APICALL (*SetBPen)(struct GraphicsIFace *Self, struct RastPort * rp, UBYTE pen);
	VOID APICALL (*SetDrMd)(struct GraphicsIFace *Self, struct RastPort * rp, UBYTE drawMode);
	VOID APICALL (*InitView)(struct GraphicsIFace *Self, struct View * view);
	VOID APICALL (*CBump)(struct GraphicsIFace *Self, struct UCopList * copList);
	VOID APICALL (*CMove)(struct GraphicsIFace *Self, struct UCopList * copList, WORD destoffset, WORD data);
	VOID APICALL (*CWait)(struct GraphicsIFace *Self, struct UCopList * copList, WORD v, WORD h);
	LONG APICALL (*VBeamPos)(struct GraphicsIFace *Self);
	VOID APICALL (*InitBitMap)(struct GraphicsIFace *Self, struct BitMap * bitMap, BYTE depth, UWORD width, UWORD height);
	VOID APICALL (*ScrollRaster)(struct GraphicsIFace *Self, struct RastPort * rp, WORD dx, WORD dy, WORD xMin, WORD yMin, WORD xMax, WORD yMax);
	VOID APICALL (*WaitBOVP)(struct GraphicsIFace *Self, struct ViewPort * vp);
	WORD APICALL (*GetSprite)(struct GraphicsIFace *Self, struct SimpleSprite * sprite, WORD num);
	VOID APICALL (*FreeSprite)(struct GraphicsIFace *Self, WORD num);
	VOID APICALL (*ChangeSprite)(struct GraphicsIFace *Self, struct ViewPort * vp, struct SimpleSprite * sprite, APTR newData);
	VOID APICALL (*MoveSprite)(struct GraphicsIFace *Self, struct ViewPort * vp, struct SimpleSprite * sprite, WORD x, WORD y);
	VOID APICALL (*LockLayerRom)(struct GraphicsIFace *Self, struct Layer * layer);
	VOID APICALL (*UnlockLayerRom)(struct GraphicsIFace *Self, struct Layer * layer);
	VOID APICALL (*SyncSBitMap)(struct GraphicsIFace *Self, struct Layer * layer);
	VOID APICALL (*CopySBitMap)(struct GraphicsIFace *Self, struct Layer * layer);
	VOID APICALL (*OwnBlitter)(struct GraphicsIFace *Self);
	VOID APICALL (*DisownBlitter)(struct GraphicsIFace *Self);
	struct TmpRas * APICALL (*InitTmpRas)(struct GraphicsIFace *Self, struct TmpRas * tmpRas, PLANEPTR buffer, LONG size);
	VOID APICALL (*AskFont)(struct GraphicsIFace *Self, struct RastPort * rp, struct TextAttr * textAttr);
	VOID APICALL (*AddFont)(struct GraphicsIFace *Self, struct TextFont * textFont);
	VOID APICALL (*RemFont)(struct GraphicsIFace *Self, struct TextFont * textFont);
	PLANEPTR APICALL (*AllocRaster)(struct GraphicsIFace *Self, UWORD width, UWORD height);
	VOID APICALL (*FreeRaster)(struct GraphicsIFace *Self, PLANEPTR p, UWORD width, UWORD height);
	VOID APICALL (*AndRectRegion)(struct GraphicsIFace *Self, struct Region * region, CONST struct Rectangle * rectangle);
	BOOL APICALL (*OrRectRegion)(struct GraphicsIFace *Self, struct Region * region, CONST struct Rectangle * rectangle);
	struct Region * APICALL (*NewRegion)(struct GraphicsIFace *Self);
	BOOL APICALL (*ClearRectRegion)(struct GraphicsIFace *Self, struct Region * region, CONST struct Rectangle * rectangle);
	VOID APICALL (*ClearRegion)(struct GraphicsIFace *Self, struct Region * region);
	VOID APICALL (*DisposeRegion)(struct GraphicsIFace *Self, struct Region * region);
	VOID APICALL (*FreeVPortCopLists)(struct GraphicsIFace *Self, struct ViewPort * vp);
	VOID APICALL (*FreeCopList)(struct GraphicsIFace *Self, struct CopList * copList);
	VOID APICALL (*ClipBlit)(struct GraphicsIFace *Self, struct RastPort * srcRP, WORD xSrc, WORD ySrc, struct RastPort * destRP, WORD xDest, WORD yDest, WORD xSize, WORD ySize, UBYTE minterm);
	BOOL APICALL (*XorRectRegion)(struct GraphicsIFace *Self, struct Region * region, CONST struct Rectangle * rectangle);
	VOID APICALL (*FreeCprList)(struct GraphicsIFace *Self, struct cprlist * cprList);
	struct ColorMap * APICALL (*GetColorMap)(struct GraphicsIFace *Self, UWORD entries);
	VOID APICALL (*FreeColorMap)(struct GraphicsIFace *Self, struct ColorMap * colorMap);
	LONG APICALL (*GetRGB4)(struct GraphicsIFace *Self, struct ColorMap * colorMap, UWORD entry);
	VOID APICALL (*ScrollVPort)(struct GraphicsIFace *Self, struct ViewPort * vp);
	struct CopList * APICALL (*UCopperListInit)(struct GraphicsIFace *Self, struct UCopList * uCopList, WORD n);
	VOID APICALL (*FreeGBuffers)(struct GraphicsIFace *Self, struct AnimOb * anOb, struct RastPort * rp, BOOL flag);
	BOOL APICALL (*BltBitMapRastPort)(struct GraphicsIFace *Self, CONST struct BitMap * srcBitMap, WORD xSrc, WORD ySrc, struct RastPort * destRP, WORD xDest, WORD yDest, WORD xSize, WORD ySize, UBYTE minterm);
	BOOL APICALL (*OrRegionRegion)(struct GraphicsIFace *Self, CONST struct Region * srcRegion, struct Region * destRegion);
	BOOL APICALL (*XorRegionRegion)(struct GraphicsIFace *Self, CONST struct Region * srcRegion, struct Region * destRegion);
	BOOL APICALL (*AndRegionRegion)(struct GraphicsIFace *Self, CONST struct Region * srcRegion, struct Region * destRegion);
	VOID APICALL (*SetRGB4CM)(struct GraphicsIFace *Self, struct ColorMap * colorMap, UWORD colindex, UBYTE red, UBYTE green, UBYTE blue);
	VOID APICALL (*BltMaskBitMapRastPort)(struct GraphicsIFace *Self, struct BitMap * srcBitMap, WORD xSrc, WORD ySrc, struct RastPort * destRP, WORD xDest, WORD yDest, WORD xSize, WORD ySize, UBYTE minterm, PLANEPTR bltMask);
	VOID APICALL (*GfxInternal1)(struct GraphicsIFace *Self);
	VOID APICALL (*GfxInternal2)(struct GraphicsIFace *Self);
	BOOL APICALL (*AttemptLockLayerRom)(struct GraphicsIFace *Self, struct Layer * layer);
	APTR APICALL (*GfxNew)(struct GraphicsIFace *Self, ULONG gfxNodeType);
	VOID APICALL (*GfxFree)(struct GraphicsIFace *Self, struct ExtendedNode * gfxNodePtr);
	VOID APICALL (*GfxAssociate)(struct GraphicsIFace *Self, CONST APTR associateNode, struct ExtendedNode * gfxNodePtr);
	VOID APICALL (*BitMapScale)(struct GraphicsIFace *Self, struct BitScaleArgs * bitScaleArgs);
	UWORD APICALL (*ScalerDiv)(struct GraphicsIFace *Self, UWORD factor, UWORD numerator, UWORD denominator);
	VOID APICALL (*TextExtent)(struct GraphicsIFace *Self, struct RastPort * rp, CONST_STRPTR string, UWORD count, struct TextExtent * textExtent);
	UWORD APICALL (*TextFit)(struct GraphicsIFace *Self, struct RastPort * rp, CONST_STRPTR string, UWORD strLen, struct TextExtent * textExtent, CONST struct TextExtent * constrainingExtent, WORD strDirection, UWORD constrainingBitWidth, UWORD constrainingBitHeight);
	APTR APICALL (*GfxLookUp)(struct GraphicsIFace *Self, CONST APTR associateNode);
	ULONG APICALL (*VideoControl)(struct GraphicsIFace *Self, struct ColorMap * colorMap, struct TagItem * tagarray);
	BOOL APICALL (*VideoControlTags)(struct GraphicsIFace *Self, struct ColorMap * colorMap, ...);
	struct MonitorSpec * APICALL (*OpenMonitor)(struct GraphicsIFace *Self, CONST_STRPTR monitorName, ULONG displayID);
	LONG APICALL (*CloseMonitor)(struct GraphicsIFace *Self, struct MonitorSpec * monitorSpec);
	DisplayInfoHandle APICALL (*FindDisplayInfo)(struct GraphicsIFace *Self, ULONG displayID);
	ULONG APICALL (*NextDisplayInfo)(struct GraphicsIFace *Self, ULONG displayID);
	VOID APICALL (*AddDisplayInfo)(struct GraphicsIFace *Self, APTR displayInfoRecord);
	VOID APICALL (*AddDisplayInfoData)(struct GraphicsIFace *Self, DisplayInfoHandle handle, UBYTE * buf, ULONG size, ULONG tagID, ULONG displayID);
	VOID APICALL (*SetDisplayInfoData)(struct GraphicsIFace *Self, DisplayInfoHandle handle, UBYTE * buf, ULONG size, ULONG tagID, ULONG displayID);
	ULONG APICALL (*GetDisplayInfoData)(struct GraphicsIFace *Self, CONST DisplayInfoHandle handle, APTR buf, ULONG size, ULONG tagID, ULONG displayID);
	VOID APICALL (*FontExtent)(struct GraphicsIFace *Self, CONST struct TextFont * font, struct TextExtent * fontExtent);
	LONG APICALL (*ReadPixelLine8)(struct GraphicsIFace *Self, struct RastPort * rp, UWORD xstart, UWORD ystart, UWORD width, UBYTE * array, struct RastPort * tempRP);
	LONG APICALL (*WritePixelLine8)(struct GraphicsIFace *Self, struct RastPort * rp, UWORD xstart, UWORD ystart, UWORD width, UBYTE * array, struct RastPort * tempRP);
	LONG APICALL (*ReadPixelArray8)(struct GraphicsIFace *Self, struct RastPort * rp, UWORD xstart, UWORD ystart, UWORD xstop, UWORD ystop, UBYTE * array, struct RastPort * temprp);
	LONG APICALL (*WritePixelArray8)(struct GraphicsIFace *Self, struct RastPort * rp, UWORD xstart, UWORD ystart, UWORD xstop, UWORD ystop, UBYTE * array, struct RastPort * temprp);
	ULONG APICALL (*GetVPModeID)(struct GraphicsIFace *Self, CONST struct ViewPort * vp);
	ULONG APICALL (*ModeNotAvailable)(struct GraphicsIFace *Self, ULONG modeID);
	WORD APICALL (*WeighTAMatch)(struct GraphicsIFace *Self, struct TextAttr * reqTextAttr, struct TextAttr * targetTextAttr, CONST struct TagItem * targetTags);
	WORD APICALL (*WeighTAMatchTags)(struct GraphicsIFace *Self, struct TextAttr * reqTextAttr, struct TextAttr * targetTextAttr, ...);
	VOID APICALL (*EraseRect)(struct GraphicsIFace *Self, struct RastPort * rp, WORD xMin, WORD yMin, WORD xMax, WORD yMax);
	ULONG APICALL (*ExtendFont)(struct GraphicsIFace *Self, struct TextFont * font, CONST struct TagItem * fontTags);
	ULONG APICALL (*ExtendFontTags)(struct GraphicsIFace *Self, struct TextFont * font, ...);
	VOID APICALL (*StripFont)(struct GraphicsIFace *Self, struct TextFont * font);
	UWORD APICALL (*CalcIVG)(struct GraphicsIFace *Self, struct View * v, struct ViewPort * vp);
	LONG APICALL (*AttachPalExtra)(struct GraphicsIFace *Self, struct ColorMap * cm, struct ViewPort * vp);
	LONG APICALL (*ObtainBestPenA)(struct GraphicsIFace *Self, struct ColorMap * cm, ULONG r, ULONG g, ULONG b, CONST struct TagItem * tags);
	LONG APICALL (*ObtainBestPen)(struct GraphicsIFace *Self, struct ColorMap * cm, ULONG r, ULONG g, ULONG b, ...);
	VOID APICALL (*GfxInternal3)(struct GraphicsIFace *Self);
	VOID APICALL (*SetRGB32)(struct GraphicsIFace *Self, struct ViewPort * vp, ULONG n, ULONG r, ULONG g, ULONG b);
	ULONG APICALL (*GetAPen)(struct GraphicsIFace *Self, struct RastPort * rp);
	ULONG APICALL (*GetBPen)(struct GraphicsIFace *Self, struct RastPort * rp);
	ULONG APICALL (*GetDrMd)(struct GraphicsIFace *Self, struct RastPort * rp);
	ULONG APICALL (*GetOutlinePen)(struct GraphicsIFace *Self, struct RastPort * rp);
	VOID APICALL (*LoadRGB32)(struct GraphicsIFace *Self, struct ViewPort * vp, CONST ULONG * table);
	ULONG APICALL (*SetChipRev)(struct GraphicsIFace *Self, ULONG want);
	VOID APICALL (*SetABPenDrMd)(struct GraphicsIFace *Self, struct RastPort * rp, ULONG apen, ULONG bpen, ULONG drawmode);
	VOID APICALL (*GetRGB32)(struct GraphicsIFace *Self, CONST struct ColorMap * cm, UWORD firstcolor, UWORD ncolors, ULONG * table);
	LONG APICALL (*BltBitMapTagList)(struct GraphicsIFace *Self, CONST struct TagItem * tags);
	BOOL APICALL (*SetDefaultMonitor)(struct GraphicsIFace *Self, UWORD mon);
	struct BitMap * APICALL (*AllocBitMap)(struct GraphicsIFace *Self, ULONG sizex, ULONG sizey, ULONG depth, ULONG flags, CONST struct BitMap * friend_bitmap);
	VOID APICALL (*FreeBitMap)(struct GraphicsIFace *Self, struct BitMap * bm);
	LONG APICALL (*GetExtSpriteA)(struct GraphicsIFace *Self, struct ExtSprite * ss, CONST struct TagItem * tags);
	LONG APICALL (*GetExtSprite)(struct GraphicsIFace *Self, struct ExtSprite * ss, ...);
	ULONG APICALL (*CoerceMode)(struct GraphicsIFace *Self, struct ViewPort * vp, ULONG monitorid, ULONG flags);
	VOID APICALL (*ChangeVPBitMap)(struct GraphicsIFace *Self, struct ViewPort * vp, struct BitMap * bm, struct DBufInfo * db);
	VOID APICALL (*ReleasePen)(struct GraphicsIFace *Self, struct ColorMap * cm, LONG n);
	LONG APICALL (*ObtainPen)(struct GraphicsIFace *Self, struct ColorMap * cm, LONG n, ULONG r, ULONG g, ULONG b, LONG f);
	ULONG APICALL (*GetBitMapAttr)(struct GraphicsIFace *Self, CONST struct BitMap * bm, ULONG attrnum);
	struct DBufInfo * APICALL (*AllocDBufInfo)(struct GraphicsIFace *Self, struct ViewPort * vp);
	VOID APICALL (*FreeDBufInfo)(struct GraphicsIFace *Self, struct DBufInfo * dbi);
	ULONG APICALL (*SetOutlinePen)(struct GraphicsIFace *Self, struct RastPort * rp, ULONG pen);
	ULONG APICALL (*SetWriteMask)(struct GraphicsIFace *Self, struct RastPort * rp, ULONG msk);
	VOID APICALL (*SetMaxPen)(struct GraphicsIFace *Self, struct RastPort * rp, ULONG maxpen);
	VOID APICALL (*SetRGB32CM)(struct GraphicsIFace *Self, struct ColorMap * cm, UWORD n, ULONG r, ULONG g, ULONG b);
	VOID APICALL (*ScrollRasterBF)(struct GraphicsIFace *Self, struct RastPort * rp, WORD dx, WORD dy, WORD xMin, WORD yMin, WORD xMax, WORD yMax);
	UWORD APICALL (*FindColor)(struct GraphicsIFace *Self, struct ColorMap * cm, ULONG r, ULONG g, ULONG b, LONG maxcolor);
	LONG APICALL (*BltBitMapTags)(struct GraphicsIFace *Self, ...);
	struct ExtSprite * APICALL (*AllocSpriteDataA)(struct GraphicsIFace *Self, CONST struct BitMap * bm, CONST struct TagItem * tags);
	struct ExtSprite * APICALL (*AllocSpriteData)(struct GraphicsIFace *Self, CONST struct BitMap * bm, ...);
	LONG APICALL (*ChangeExtSpriteA)(struct GraphicsIFace *Self, struct ViewPort * vp, struct ExtSprite * oldsprite, struct ExtSprite * newsprite, CONST struct TagItem * tags);
	LONG APICALL (*ChangeExtSprite)(struct GraphicsIFace *Self, struct ViewPort * vp, struct ExtSprite * oldsprite, struct ExtSprite * newsprite, ...);
	VOID APICALL (*FreeSpriteData)(struct GraphicsIFace *Self, struct ExtSprite * sp);
	VOID APICALL (*SetRPAttrsA)(struct GraphicsIFace *Self, struct RastPort * rp, CONST struct TagItem * tags);
	VOID APICALL (*SetRPAttrs)(struct GraphicsIFace *Self, struct RastPort * rp, ...);
	VOID APICALL (*GetRPAttrsA)(struct GraphicsIFace *Self, CONST struct RastPort * rp, CONST struct TagItem * tags);
	VOID APICALL (*GetRPAttrs)(struct GraphicsIFace *Self, CONST struct RastPort * rp, ...);
	ULONG APICALL (*BestModeIDA)(struct GraphicsIFace *Self, CONST struct TagItem * tags);
	ULONG APICALL (*BestModeID)(struct GraphicsIFace *Self, ...);
	VOID APICALL (*WriteChunkyPixels)(struct GraphicsIFace *Self, struct RastPort * rp, UWORD xstart, UWORD ystart, UWORD xstop, UWORD ystop, CONST UBYTE * array, LONG bytesperrow);
	uint32 APICALL (*CompositeTagList)(struct GraphicsIFace *Self, CONST uint32 Operator, CONST struct BitMap * Source, CONST struct BitMap * Destination, CONST struct TagItem * tags);
	uint32 APICALL (*CompositeTags)(struct GraphicsIFace *Self, CONST uint32 Operator, CONST struct BitMap * Source, CONST struct BitMap * Destination, ...);
	struct BitMap * APICALL (*AllocBitMapTagList)(struct GraphicsIFace *Self, uint32 sizex, uint32 sizey, uint32 depth, CONST struct TagItem * tags);
	struct BitMap * APICALL (*AllocBitMapTags)(struct GraphicsIFace *Self, uint32 sizex, uint32 sizey, uint32 depth, ...);
};

/**********************************************************************************************/

struct GroupInfo
{
    TEXT  gi_GroupName[32];
    UWORD gi_GroupID;
};

/**********************************************************************************************/

struct GUIPlugin
{
   struct Node     Node;         /* Reserved, don't use             */
   ULONG           Version;      /* Version of the plugin           */
   ULONG           Type;         /* Type of plugin                  */
   ULONG           Attrs;        /* Type-specific attributes        */
   ULONG           Flags;        /* Additional information          */
   struct TagItem *AttrList;     /* Optional list of GUI attributes */
   ULONG           Reserved[4];  /* For future expansion            */

   /* Plugin-specific fields follow here */
};

/**********************************************************************************************/

struct GUIPrefs
{
    LONG     gp_Reserved[4];                /* System reserved                        */
    UWORD    gp_Version;                    /* Version of the GUIPrefs structure      */
    ULONG    gp_GlobalFlags;                /* Global control flags                   */
    ULONG    gp_ScreenFlags;                /* Screen control flags                   */
    UBYTE    gp_STitlePos;                  /* Position of screen title               */
    UBYTE    gp_STitlebarHIncr;             /* Increment to screen titlebar height    */
    UWORD    gp_MenuType;                   /* PULLDOWN, POPUP or RELATIVE            */
    UWORD    gp_MenuStyle;                  /* SQUARE, ROUNDED...                     */
    ULONG    gp_MenuFlags;                  /* MENUSHADOW, MENUTRANSP...              */
    TEXT     gp_MenuBackfill[256];          /* Menu backfill picture path             */
    TEXT     gp_MenuStylePlugin[40];        /* Menu style plugin name                 */
    ULONG    gp_STitlebarGSize;             /* Size of screen titlebar gadgets        */
    UWORD    gp_SysISubStyles[32];          /* Sub-style indices for style plugins    */
    UWORD    gp_MenuSelectedItemFrame;      /* How to draw selected menu items        */
    UWORD    gp_ReqPosition;                /* Opening position of system requesters  */
    UBYTE    gp_LayoutSpacing[2];           /* RA layout spacing in virtual pixels    */
    UWORD    gp_GroupLabelPlace;            /* Position of layout group labels        */
    UWORD    gp_GroupLabelLook;             /* Appearance of layout group labels      */
    UWORD    gp_WindowRefresh;              /* Preferred refresh type for windows     */
    UWORD    gp_GroupLabelVAlign;           /* Vert. alignment of layout group labels */
    UWORD    gp_ListHierNodeStyle;          /* Style of hierarchical list nodes       */
    UWORD    gp_ListHierConnectType;        /* How to connect hierarchical list nodes */
    ULONG    gp_GaugeLook[2];               /* Look of level/progress gauges          */
    UWORD    gp_GadgetRedraw;               /* Options for gadget redraw              */
    UBYTE    gp_Reserved2[120];             /* System reserved                        */
    UWORD    gp_DRIPens[96];                /* DrawInfo pens                          */
    UBYTE    gp_EdgesContrast[16][2];       /* Contrast levels for edges              */
    UBYTE    gp_HalfCurve[16][2];           /* Gradient curves for intermediate pens  */
    UBYTE    gp_PropKnobHighlight[2];       /* Look of selected prop knob             */
    UWORD    gp_WindowPropLook;             /* Look of window border scrollers        */
    UBYTE    gp_FrameProperties[20];        /* Various properties for frameiclass     */
    TEXT     gp_FrameBackfill[2][256];      /* Frameiclass backfill picture paths     */
    UBYTE    gp_WindowFlags;                /* Window control flags                   */
    UBYTE    gp_WTitlePos;                  /* Position of window title               */
    UBYTE    gp_WTitlebarHIncr;             /* Increment to window titlebar height    */
    BYTE     gp_SizeSize[2];                /* Width and height of sizing gadget      */
    BYTE     gp_ArrowSize[2];               /* Width and height of arrow gadgets      */
    BYTE     gp_BorderSize[4];              /* Sizes of gadgetless window borders     */
    UWORD    gp_SizeBorder;                 /* Preferred position for sizing gadget   */
    UWORD    gp_SysIFrameType;              /* Type of frame for system images        */
    UBYTE    gp_PropBorder[2];              /* Do scrollers have a border?            */
    UWORD    gp_PropKnobHandle[2];          /* Type of border scroller knob handle    */
    UWORD    gp_PropKnobColor[2];           /* Color of scroller knobs                */
    UWORD    gp_PropBackground[2];          /* Type of background for prop gadgets    */
    UBYTE    gp_PropSpacing[2];             /* Spacing for scroller borders           */
    TEXT     gp_PropBackfill[8][256];       /* Prop gadgets backfill picture paths    */
    TEXT     gp_TBarBackfill[3][256];       /* Screen/window titlebar texture paths   */
    TEXT     gp_BorderBackfill[2][256];     /* Window borders texture paths           */
    UBYTE    gp_Reserved3[256];             /* System reserved                        */
    TEXT     gp_WBorderStylePlugin[40];     /* Window border style plugin name        */
    TEXT     gp_WGadgetStylePlugin[40];     /* Window gadget symbol style plugin name */
    TEXT     gp_WGFrameStylePlugin[40];     /* Window gadget frame style plugin name  */
    TEXT     gp_GadgetStylePlugin[4][40];   /* GT/RA gadget symbol style plugin names */
    TEXT     gp_DefaultStylePlugin[40];     /* Fallback style plugin name             */
    ULONG    gp_WTitlebarGSize;             /* Size of window titlebar gadgets        */
    UWORD    gp_SFrameThickness;            /* Screen titlebar frame thickness        */
    UWORD    gp_WFrameThickness[2];         /* Window titlebar/border frame thickness */
    UWORD    gp_WindowBorderLook;           /* Window border outline look             */
    UWORD    gp_PropOuterSpacing;           /* Spacing around scrollers (in windows)  */
    UWORD    gp_SliderDisplayMode;          /* Where to display slider levels         */
    UWORD    gp_CycleLabelJustify;          /* Justification of cycle/chooser labels  */
    ULONG    gp_ClickTabLook;               /* Flags affecting clicktab look          */
    UBYTE    gp_FramePadding[2];            /* Horizontal/vertical gadget padding     */
    UWORD    gp_WFlatFrameThickness[2];     /* Window outer/inner flat thickness      */
    ULONG    gp_CycleLook;                  /* Flags affecting cycle/chooser look     */
    ULONG    gp_WindowFadeTime[8];          /* Fade time for window state transitions */
    TEXT     gp_FrameBackfill2[256];        /* Frameiclass backfill picture path (2)  */
    TEXT     gp_WGadgetGeometryPlugin[40];  /* Window gadget geometry plugin name     */
    TEXT     gp_GadgetGeometryPlugin[40];   /* GT/RA gadget geometry plugin name      */
    TEXT     gp_DefaultGeometryPlugin[40];  /* Fallback geometry plugin name          */
    TEXT     gp_BitmapSet[256];             /* Bitmap set path                        */
    UWORD    gp_OffScreenResistance;        /* Resistance of screen edges             */
    UBYTE    gp_MenuTranspLevel;            /* Level of menu transparency             */
    UBYTE    gp_Reserved4[5];               /* System reserved                        */
    TEXT     gp_WindowBackfill[256];        /* Window backfill picture path           */
    TEXT     gp_RequesterBackfill[256];     /* Requester backfill picture path        */
    GRADSPEC gp_GradientSpecs[30];          /* Various gradient specifications        */
    UBYTE    gp_WindowAlpha[8];             /* Alpha levels for various window types  */
    BYTE     gp_WindowShadowSizes[4];       /* Sizes of window drop shadows           */
    UBYTE    gp_WindowShadowStrength[8];    /* Intensity of window drop shadows       */
    UWORD    gp_WindowShadowType;           /* Type of built-in window drop shadow    */
    ULONG    gp_WindowShadowColor;          /* Color of window drop shadows           */
    BYTE     gp_WindowShadowDispl[4];       /* Window drop shadows X/Y displacement   */
    UWORD    gp_WindowShadowSmoothness;     /* Smoothness of window drop shadows      */
    UWORD    gp_STitlebarShadowDispl;       /* Screen bar drop shadow Y displacement  */
    UWORD    gp_STitlebarShadowStrength;    /* Intensity of screen bar drop shadow    */
    ULONG    gp_STitlebarShadowColor;       /* Color of screen bar drop shadow        */
    UWORD    gp_STitlebarShadowSmoothness;  /* Smoothness of screen bar drop shadow   */
    UBYTE    gp_Reserved5[110];             /* System reserved                        */
    FONTSPEC gp_GadgetFont;                 /* Font for RA gadgets                    */
    FONTSPEC gp_LabelFont;                  /* Font for RA labels (outside gadgets)   */
    FONTSPEC gp_GroupLabelFont;             /* Font for RA layout group title labels  */
    FONTSPEC gp_FallbackFont;               /* Fallback (small) font for RA GUIs      */
};

/**********************************************************************************************/

struct HunkIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct HunkIFace *Self);
	ULONG APICALL (*Release)(struct HunkIFace *Self);
	void APICALL (*Expunge)(struct HunkIFace *Self);
	struct Interface * APICALL (*Clone)(struct HunkIFace *Self);
	BPTR APICALL (*LoadHunk)(struct HunkIFace *Self, const struct TagItem * tags);
	BPTR APICALL (*LoadHunkTags)(struct HunkIFace *Self, ...);
	VOID APICALL (*UnLoadHunk)(struct HunkIFace *Self, const struct TagItem * tags);
	VOID APICALL (*UnLoadHunkTags)(struct HunkIFace *Self, ...);
};

/**********************************************************************************************/

struct HunkMessage
{
    uint32 hm_StructureSize; /* Always the size of this structure.      */

    APTR   hm_Handle;        /* Set by tag; LH_Handle in LoadHunk().    */
                             /* Set to overlay handle in UnLoadHunk().  */

    APTR   hm_Library;       /* Set by tag; LH_Library exclusively.     */

    APTR   hm_Memory;        /* The memory or buffer parameter.         */

    uint32 hm_MemoryAttr;    /* The memory attributes for allocations.  */

    uint32 hm_Length;        /* The size/length parameter.              */
};

/**********************************************************************************************/

struct IconIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct IconIFace *Self);
	ULONG APICALL (*Release)(struct IconIFace *Self);
	void APICALL (*Expunge)(struct IconIFace *Self);
	struct Interface * APICALL (*Clone)(struct IconIFace *Self);
	APTR Private1;
	APTR Private2;
	APTR Private3;
	APTR Private4;
	VOID APICALL (*FreeFreeList)(struct IconIFace *Self, struct FreeList * freelist);
	APTR Private5;
	APTR Private6;
	BOOL APICALL (*AddFreeList)(struct IconIFace *Self, struct FreeList * freelist, CONST_APTR mem, ULONG size);
	struct DiskObject * APICALL (*GetDiskObject)(struct IconIFace *Self, CONST_STRPTR name);
	BOOL APICALL (*PutDiskObject)(struct IconIFace *Self, CONST_STRPTR name, CONST struct DiskObject * diskobj);
	VOID APICALL (*FreeDiskObject)(struct IconIFace *Self, struct DiskObject * diskobj);
	STRPTR APICALL (*FindToolType)(struct IconIFace *Self, STRPTR * toolTypeArray, CONST_STRPTR typeName);
	BOOL APICALL (*MatchToolValue)(struct IconIFace *Self, CONST_STRPTR typeString, CONST_STRPTR value);
	STRPTR APICALL (*BumpRevision)(struct IconIFace *Self, STRPTR newname, CONST_STRPTR oldname);
	APTR APICALL (*FreeAlloc)(struct IconIFace *Self, struct FreeList * freelist, ULONG len, ULONG type);
	struct DiskObject * APICALL (*GetDefDiskObject)(struct IconIFace *Self, LONG type);
	BOOL APICALL (*PutDefDiskObject)(struct IconIFace *Self, CONST struct DiskObject * diskObject);
	struct DiskObject * APICALL (*GetDiskObjectNew)(struct IconIFace *Self, CONST_STRPTR name);
	BOOL APICALL (*DeleteDiskObject)(struct IconIFace *Self, CONST_STRPTR name);
	BOOL APICALL (*FreeFree)(struct IconIFace *Self, struct FreeList * fl, APTR address);
	struct DiskObject * APICALL (*DupDiskObjectA)(struct IconIFace *Self, CONST struct DiskObject * diskObject, CONST struct TagItem * tags);
	struct DiskObject * APICALL (*DupDiskObject)(struct IconIFace *Self, CONST struct DiskObject * diskObject, ...);
	ULONG APICALL (*IconControlA)(struct IconIFace *Self, struct DiskObject * icon, CONST struct TagItem * tags);
	ULONG APICALL (*IconControl)(struct IconIFace *Self, struct DiskObject * icon, ...);
	VOID APICALL (*DrawIconStateA)(struct IconIFace *Self, struct RastPort * rp, CONST struct DiskObject * icon, CONST_STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, CONST struct TagItem * tags);
	VOID APICALL (*DrawIconState)(struct IconIFace *Self, struct RastPort * rp, CONST struct DiskObject * icon, CONST_STRPTR label, LONG leftOffset, LONG topOffset, ULONG state, ...);
	BOOL APICALL (*GetIconRectangleA)(struct IconIFace *Self, struct RastPort * rp, CONST struct DiskObject * icon, CONST_STRPTR label, struct Rectangle * rect, CONST struct TagItem * tags);
	BOOL APICALL (*GetIconRectangle)(struct IconIFace *Self, struct RastPort * rp, CONST struct DiskObject * icon, CONST_STRPTR label, struct Rectangle * rect, ...);
	struct DiskObject * APICALL (*NewDiskObject)(struct IconIFace *Self, LONG type);
	struct DiskObject * APICALL (*GetIconTagList)(struct IconIFace *Self, CONST_STRPTR name, CONST struct TagItem * tags);
	struct DiskObject * APICALL (*GetIconTags)(struct IconIFace *Self, CONST_STRPTR name, ...);
	BOOL APICALL (*PutIconTagList)(struct IconIFace *Self, CONST_STRPTR name, CONST struct DiskObject * icon, CONST struct TagItem * tags);
	BOOL APICALL (*PutIconTags)(struct IconIFace *Self, CONST_STRPTR name, CONST struct DiskObject * icon, ...);
	BOOL APICALL (*LayoutIconA)(struct IconIFace *Self, struct DiskObject * icon, struct Screen * screen, CONST struct TagItem * tags);
	BOOL APICALL (*LayoutIcon)(struct IconIFace *Self, struct DiskObject * icon, struct Screen * screen, ...);
	VOID APICALL (*ChangeToSelectedIconColor)(struct IconIFace *Self, struct ColorRegister * cr);
	STRPTR APICALL (*BumpRevisionLength)(struct IconIFace *Self, STRPTR newname, CONST_STRPTR oldname, uint32 maxlength);
};

/**********************************************************************************************/

struct IconModuleIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct IconModuleIFace *Self);
	uint32 APICALL (*Release)(struct IconModuleIFace *Self);
	void APICALL (*Expunge)(struct IconModuleIFace *Self);
	struct Interface * APICALL (*Clone)(struct IconModuleIFace *Self);
	uint32 APICALL (*ModuleControlA)(struct IconModuleIFace *Self, APTR object, struct TagItem * taglist);
	uint32 APICALL (*ModuleControl)(struct IconModuleIFace *Self, APTR object, ...);
	struct DiskObject * APICALL (*LoadIconA)(struct IconModuleIFace *Self, CONST_STRPTR name, struct DiskObject * icon, struct TagItem * taglist);
	struct DiskObject * APICALL (*LoadIcon)(struct IconModuleIFace *Self, CONST_STRPTR name, struct DiskObject * icon, ...);
	uint32 APICALL (*SaveIconA)(struct IconModuleIFace *Self, CONST_STRPTR name, struct DiskObject * icon, struct TagItem * taglist);
	uint32 APICALL (*SaveIcon)(struct IconModuleIFace *Self, CONST_STRPTR name, struct DiskObject * icon, ...);
	uint32 APICALL (*AllocIconDataA)(struct IconModuleIFace *Self, struct DiskObject * icon, struct TagItem * taglist);
	uint32 APICALL (*AllocIconData)(struct IconModuleIFace *Self, struct DiskObject * icon, ...);
	void APICALL (*FreeIconDataA)(struct IconModuleIFace *Self, struct DiskObject * icon, struct TagItem * taglist);
	void APICALL (*FreeIconData)(struct IconModuleIFace *Self, struct DiskObject * icon, ...);
	APTR APICALL (*DupIconDataA)(struct IconModuleIFace *Self, struct DiskObject * icon, struct TagItem * taglist);
	APTR APICALL (*DupIconData)(struct IconModuleIFace *Self, struct DiskObject * icon, ...);
	uint32 APICALL (*ScaleIconA)(struct IconModuleIFace *Self, struct DiskObject * icon, struct IconScaleRequest * isr, struct TagItem * taglist);
	uint32 APICALL (*ScaleIcon)(struct IconModuleIFace *Self, struct DiskObject * icon, struct IconScaleRequest * isr, ...);
};

/**********************************************************************************************/

struct IconScaleRequest
{
   uint16  Version, Size;  /* Allow for future extension */
   uint16  Width, Height;  /* The requested icon size */
   uint16  State;          /* The requested icon state */
   uint16  BytesPerPixel;  /* To be filled in by the module (1 or 4) */
   uint8  *ImageBuffer;    /* To be filled in by the module (CLUT or ARGB) */
};

/**********************************************************************************************/

struct IDKeyboardDeviceNotifyMsg
{
    LONG   idnm_Type; /* Set to IDNOTIFY_KeyboardDevice */
    STRPTR idnm_Name; /* The name of the keyboard.device
                         driver key events are obtained
                         from. */
    LONG   idnm_Unit; /* The unit number of the
                         keyboard.device driver */
};

/**********************************************************************************************/

struct IDMouseDeviceNotifyMsg
{
    LONG   idnm_Type; /* Set to IDNOTIFY_MouseDevice */
    STRPTR idnm_Name; /* The name of the gameport.device
                         driver mouse events are obtained
                         from */
    LONG   idnm_Unit; /* The mouse port or unit number
                         of the gameport.device driver */
};

/**********************************************************************************************/

struct IDMousePortNotifyMsg
{
    LONG idnm_Type;      /* Set to IDNOTIFY_MousePort */
    LONG idnm_MousePort; /* Mouse port number; otherwise
                           identical to gameport.device
                           unit number to obtain mouse
                           events from. */
};

/**********************************************************************************************/

struct IDMouseTriggerNotifyMsg
{
    LONG                   idnm_Type;    /* Set to IDNOTIFY_MouseTrigger */
    struct GamePortTrigger idnm_Trigger; /* Conditions for a mouse port
                                            report. */
};

/**********************************************************************************************/

struct IDMouseTypeNotifyMsg
{
    LONG idnm_Type;      /* Set to IDNOTIFY_MouseType */
    LONG idnm_MouseType; /* Controller type, as defined
                            in <devices/gameport.h> by
                            the GPCT_[..] symbols. */
};

/**********************************************************************************************/

struct IDPeriodNotifyMsg
{
    LONG           idnm_Type;   /* Set to IDNOTIFY_Period */
    struct TimeVal idnm_Period; /* Key repeat period */
};

/**********************************************************************************************/

struct IDThresholdNotifyMsg
{
    LONG           idnm_Type;      /* Set to IDNOTIFY_Threshold */
    struct TimeVal idnm_Threshold; /* Key repeat threshold */
};

/**********************************************************************************************/

struct IFFParseIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct IFFParseIFace *Self);
	ULONG APICALL (*Release)(struct IFFParseIFace *Self);
	void APICALL (*Expunge)(struct IFFParseIFace *Self);
	struct Interface * APICALL (*Clone)(struct IFFParseIFace *Self);
	struct IFFHandle * APICALL (*AllocIFF)(struct IFFParseIFace *Self);
	LONG APICALL (*OpenIFF)(struct IFFParseIFace *Self, struct IFFHandle * iff, LONG rwMode);
	LONG APICALL (*ParseIFF)(struct IFFParseIFace *Self, struct IFFHandle * iff, LONG control);
	VOID APICALL (*CloseIFF)(struct IFFParseIFace *Self, struct IFFHandle * iff);
	VOID APICALL (*FreeIFF)(struct IFFParseIFace *Self, struct IFFHandle * iff);
	LONG APICALL (*ReadChunkBytes)(struct IFFParseIFace *Self, struct IFFHandle * iff, APTR buf, LONG numBytes);
	LONG APICALL (*WriteChunkBytes)(struct IFFParseIFace *Self, struct IFFHandle * iff, CONST_APTR buf, LONG numBytes);
	LONG APICALL (*ReadChunkRecords)(struct IFFParseIFace *Self, struct IFFHandle * iff, APTR buf, LONG bytesPerRecord, LONG numRecords);
	LONG APICALL (*WriteChunkRecords)(struct IFFParseIFace *Self, struct IFFHandle * iff, CONST_APTR buf, LONG bytesPerRecord, LONG numRecords);
	LONG APICALL (*PushChunk)(struct IFFParseIFace *Self, struct IFFHandle * iff, LONG type, LONG id, LONG size);
	LONG APICALL (*PopChunk)(struct IFFParseIFace *Self, struct IFFHandle * iff);
	LONG APICALL (*EntryHandler)(struct IFFParseIFace *Self, struct IFFHandle * iff, LONG type, LONG id, LONG position, struct Hook * handler, APTR object);
	LONG APICALL (*ExitHandler)(struct IFFParseIFace *Self, struct IFFHandle * iff, LONG type, LONG id, LONG position, struct Hook * handler, APTR object);
	LONG APICALL (*PropChunk)(struct IFFParseIFace *Self, struct IFFHandle * iff, LONG type, LONG id);
	LONG APICALL (*PropChunks)(struct IFFParseIFace *Self, struct IFFHandle * iff, const LONG * propArray, LONG numPairs);
	LONG APICALL (*StopChunk)(struct IFFParseIFace *Self, struct IFFHandle * iff, LONG type, LONG id);
	LONG APICALL (*StopChunks)(struct IFFParseIFace *Self, struct IFFHandle * iff, const LONG * propArray, LONG numPairs);
	LONG APICALL (*CollectionChunk)(struct IFFParseIFace *Self, struct IFFHandle * iff, LONG type, LONG id);
	LONG APICALL (*CollectionChunks)(struct IFFParseIFace *Self, struct IFFHandle * iff, const LONG * propArray, LONG numPairs);
	LONG APICALL (*StopOnExit)(struct IFFParseIFace *Self, struct IFFHandle * iff, LONG type, LONG id);
	struct StoredProperty * APICALL (*FindProp)(struct IFFParseIFace *Self, const struct IFFHandle * iff, LONG type, LONG id);
	struct CollectionItem * APICALL (*FindCollection)(struct IFFParseIFace *Self, const struct IFFHandle * iff, LONG type, LONG id);
	struct ContextNode * APICALL (*FindPropContext)(struct IFFParseIFace *Self, const struct IFFHandle * iff);
	struct ContextNode * APICALL (*CurrentChunk)(struct IFFParseIFace *Self, const struct IFFHandle * iff);
	struct ContextNode * APICALL (*ParentChunk)(struct IFFParseIFace *Self, const struct ContextNode * contextNode);
	struct LocalContextItem * APICALL (*AllocLocalItem)(struct IFFParseIFace *Self, LONG type, LONG id, LONG ident, LONG dataSize);
	APTR APICALL (*LocalItemData)(struct IFFParseIFace *Self, const struct LocalContextItem * localItem);
	VOID APICALL (*SetLocalItemPurge)(struct IFFParseIFace *Self, struct LocalContextItem * localItem, const struct Hook * purgeHook);
	VOID APICALL (*FreeLocalItem)(struct IFFParseIFace *Self, struct LocalContextItem * localItem);
	struct LocalContextItem * APICALL (*FindLocalItem)(struct IFFParseIFace *Self, const struct IFFHandle * iff, LONG type, LONG id, LONG ident);
	LONG APICALL (*StoreLocalItem)(struct IFFParseIFace *Self, struct IFFHandle * iff, struct LocalContextItem * localItem, LONG position);
	VOID APICALL (*StoreItemInContext)(struct IFFParseIFace *Self, struct IFFHandle * iff, struct LocalContextItem * localItem, struct ContextNode * contextNode);
	VOID APICALL (*InitIFF)(struct IFFParseIFace *Self, struct IFFHandle * iff, LONG flags, const struct Hook * streamHook);
	VOID APICALL (*InitIFFasDOS)(struct IFFParseIFace *Self, struct IFFHandle * iff);
	VOID APICALL (*InitIFFasClip)(struct IFFParseIFace *Self, struct IFFHandle * iff);
	struct ClipboardHandle * APICALL (*OpenClipboard)(struct IFFParseIFace *Self, LONG unitNumber);
	VOID APICALL (*CloseClipboard)(struct IFFParseIFace *Self, struct ClipboardHandle * clipHandle);
	LONG APICALL (*GoodID)(struct IFFParseIFace *Self, LONG id);
	LONG APICALL (*GoodType)(struct IFFParseIFace *Self, LONG type);
	STRPTR APICALL (*IDtoStr)(struct IFFParseIFace *Self, LONG id, STRPTR buf);
};

/**********************************************************************************************/

struct ImageGeometryMsg
{
    ULONG            igm_MethodID;   /* One of the SG_ definitions above  */
    struct RastPort *igm_RastPort;   /* Reference RastPort (for the font) */
    struct DrawInfo *igm_DrawInfo;   /* Context information               */
    struct IBox      igm_ImageBox;   /* (Output) Box computed by the hook */
    struct IBox      igm_RenderBox;  /* (Output) Box computed by the hook */
    ULONG            igm_Reserved;   /* Reserved for future use           */
    ULONG            igm_Flags;      /* More information                  */
};

/**********************************************************************************************/

struct InputDeviceOption
{
    STRPTR Name;     /* Device name */
    LONG   NameSize; /* Size of name buffer (for queries) */
    LONG   Unit;     /* Unit number */
};

/**********************************************************************************************/

struct InputIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct InputIFace *Self);
	ULONG APICALL (*Release)(struct InputIFace *Self);
	void APICALL (*Expunge)(struct InputIFace *Self);
	struct Interface * APICALL (*Clone)(struct InputIFace *Self);
	UWORD APICALL (*PeekQualifier)(struct InputIFace *Self);
};

/**********************************************************************************************/

struct IntegerIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct IntegerIFace *Self);
	ULONG APICALL (*Release)(struct IntegerIFace *Self);
	void APICALL (*Expunge)(struct IntegerIFace *Self);
	struct Interface * APICALL (*Clone)(struct IntegerIFace *Self);
	Class * APICALL (*INTEGER_GetClass)(struct IntegerIFace *Self);
};

/**********************************************************************************************/

struct Interface
{
    struct InterfaceData Data; /* Interface data area */

    uint32 APICALL             (*Obtain) (struct Interface *Self); /* Increment reference count */
    uint32 APICALL             (*Release)(struct Interface *Self); /* Decrement reference count */
    void APICALL               (*Expunge)(struct Interface *Self); /* Destroy interface. May be NULL */
    struct Interface * APICALL (*Clone)  (struct Interface *Self); /* Clone interface. May be NULL */
};

/**********************************************************************************************/

struct InterfaceData
{
    struct Node     Link;              /* Node for linking several interfaces */
    struct Library *LibBase;           /* Library this interface belongs to */

    uint32          RefCount;          /* Reference count */
    uint32          Version;           /* Version number of the interface */
    uint32          Flags;             /* Various flags (see below) */
    uint32          CheckSum;          /* Checksum of the interface */
    uint32          PositiveSize;      /* Size of the function pointer part */
    uint32          NegativeSize;      /* Size of the data area */
    APTR            IExecPrivate;      /* Private copy of IExec */
    APTR            EnvironmentVector; /* Base address for base relative code */
    uint32          Reserved3;
    uint32          Reserved4;
};

/**********************************************************************************************/

struct IntuiRawKeyData
{
    UWORD Version;  /* version of this structure (see below) */
    UWORD Reserved; /* always 0, reserved for future use     */
    UWORD Class;    /* copy of ie_SubClass (see IECLASS_EXTENDED_RAWKEY) */
    UWORD Code;     /* rawkey code */
    struct ExtendedDeadKey DeadKeys; /* deadkey information */
};

/**********************************************************************************************/

struct IntuitionIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct IntuitionIFace *Self);
	uint32 APICALL (*Release)(struct IntuitionIFace *Self);
	void APICALL (*Expunge)(struct IntuitionIFace *Self);
	struct Interface * APICALL (*Clone)(struct IntuitionIFace *Self);
	VOID APICALL (*OpenIntuition)(struct IntuitionIFace *Self);
	VOID APICALL (*Intuition)(struct IntuitionIFace *Self, struct InputEvent * iEvent);
	UWORD APICALL (*AddGadget)(struct IntuitionIFace *Self, struct Window * window, struct Gadget * gadget, UWORD position);
	BOOL APICALL (*ClearDMRequest)(struct IntuitionIFace *Self, struct Window * window);
	VOID APICALL (*ClearMenuStrip)(struct IntuitionIFace *Self, struct Window * window);
	VOID APICALL (*ClearPointer)(struct IntuitionIFace *Self, struct Window * window);
	BOOL APICALL (*CloseScreen)(struct IntuitionIFace *Self, struct Screen * screen);
	VOID APICALL (*CloseWindow)(struct IntuitionIFace *Self, struct Window * window);
	LONG APICALL (*CloseWorkBench)(struct IntuitionIFace *Self);
	VOID APICALL (*CurrentTime)(struct IntuitionIFace *Self, ULONG * seconds, ULONG * micros);
	BOOL APICALL (*DisplayAlert)(struct IntuitionIFace *Self, uint32 alertNumber, CONST_STRPTR string, uint16 height);
	VOID APICALL (*DisplayBeep)(struct IntuitionIFace *Self, struct Screen * screen);
	BOOL APICALL (*DoubleClick)(struct IntuitionIFace *Self, ULONG sSeconds, ULONG sMicros, ULONG cSeconds, ULONG cMicros);
	VOID APICALL (*DrawBorder)(struct IntuitionIFace *Self, struct RastPort * rp, const struct Border * border, WORD leftOffset, WORD topOffset);
	VOID APICALL (*DrawImage)(struct IntuitionIFace *Self, struct RastPort * rp, struct Image * image, WORD leftOffset, WORD topOffset);
	VOID APICALL (*EndRequest)(struct IntuitionIFace *Self, struct Requester * requester, struct Window * window);
	struct Preferences * APICALL (*GetDefPrefs)(struct IntuitionIFace *Self, struct Preferences * preferences, WORD size);
	struct Preferences * APICALL (*GetPrefs)(struct IntuitionIFace *Self, struct Preferences * preferences, WORD size);
	VOID APICALL (*InitRequester)(struct IntuitionIFace *Self, struct Requester * requester);
	struct MenuItem * APICALL (*ItemAddress)(struct IntuitionIFace *Self, const struct Menu * menuStrip, UWORD menuNumber);
	BOOL APICALL (*ModifyIDCMP)(struct IntuitionIFace *Self, struct Window * window, ULONG flags);
	VOID APICALL (*ModifyProp)(struct IntuitionIFace *Self, struct Gadget * gadget, struct Window * window, struct Requester * requester, UWORD flags, UWORD horizPot, UWORD vertPot, UWORD horizBody, UWORD vertBody);
	VOID APICALL (*MoveScreen)(struct IntuitionIFace *Self, struct Screen * screen, WORD dx, WORD dy);
	VOID APICALL (*MoveWindow)(struct IntuitionIFace *Self, struct Window * window, WORD dx, WORD dy);
	VOID APICALL (*OffGadget)(struct IntuitionIFace *Self, struct Gadget * gadget, struct Window * window, struct Requester * requester);
	VOID APICALL (*OffMenu)(struct IntuitionIFace *Self, struct Window * window, UWORD menuNumber);
	VOID APICALL (*OnGadget)(struct IntuitionIFace *Self, struct Gadget * gadget, struct Window * window, struct Requester * requester);
	VOID APICALL (*OnMenu)(struct IntuitionIFace *Self, struct Window * window, UWORD menuNumber);
	struct Screen * APICALL (*OpenScreen)(struct IntuitionIFace *Self, const struct NewScreen * newScreen);
	struct Window * APICALL (*OpenWindow)(struct IntuitionIFace *Self, const struct NewWindow * newWindow);
	ULONG APICALL (*OpenWorkBench)(struct IntuitionIFace *Self);
	VOID APICALL (*PrintIText)(struct IntuitionIFace *Self, struct RastPort * rp, const struct IntuiText * iText, WORD left, WORD top);
	VOID APICALL (*RefreshGadgets)(struct IntuitionIFace *Self, struct Gadget * gadgets, struct Window * window, struct Requester * requester);
	UWORD APICALL (*RemoveGadget)(struct IntuitionIFace *Self, struct Window * window, struct Gadget * gadget);
	VOID APICALL (*ReportMouse)(struct IntuitionIFace *Self, BOOL flag, struct Window * window);
	VOID APICALL (*ReportMouse1)(struct IntuitionIFace *Self, struct Window * window, BOOL flag);
	BOOL APICALL (*Request)(struct IntuitionIFace *Self, struct Requester * requester, struct Window * window);
	VOID APICALL (*ScreenToBack)(struct IntuitionIFace *Self, struct Screen * screen);
	VOID APICALL (*ScreenToFront)(struct IntuitionIFace *Self, struct Screen * screen);
	BOOL APICALL (*SetDMRequest)(struct IntuitionIFace *Self, struct Window * window, struct Requester * requester);
	BOOL APICALL (*SetMenuStrip)(struct IntuitionIFace *Self, struct Window * window, struct Menu * menu);
	VOID APICALL (*SetPointer)(struct IntuitionIFace *Self, struct Window * window, UWORD * pointer, WORD height, WORD width, WORD xOffset, WORD yOffset);
	void APICALL (*SetWindowTitles)(struct IntuitionIFace *Self, struct Window * window, CONST_STRPTR windowTitle, CONST_STRPTR screenTitle);
	VOID APICALL (*ShowTitle)(struct IntuitionIFace *Self, struct Screen * screen, BOOL showIt);
	VOID APICALL (*SizeWindow)(struct IntuitionIFace *Self, struct Window * window, WORD dx, WORD dy);
	struct View * APICALL (*ViewAddress)(struct IntuitionIFace *Self);
	struct ViewPort * APICALL (*ViewPortAddress)(struct IntuitionIFace *Self, const struct Window * window);
	VOID APICALL (*WindowToBack)(struct IntuitionIFace *Self, struct Window * window);
	VOID APICALL (*WindowToFront)(struct IntuitionIFace *Self, struct Window * window);
	BOOL APICALL (*WindowLimits)(struct IntuitionIFace *Self, struct Window * window, LONG widthMin, LONG heightMin, ULONG widthMax, ULONG heightMax);
	struct Preferences * APICALL (*SetPrefs)(struct IntuitionIFace *Self, const struct Preferences * preferences, LONG size, BOOL inform);
	LONG APICALL (*IntuiTextLength)(struct IntuitionIFace *Self, const struct IntuiText * iText);
	BOOL APICALL (*WBenchToBack)(struct IntuitionIFace *Self);
	BOOL APICALL (*WBenchToFront)(struct IntuitionIFace *Self);
	BOOL APICALL (*AutoRequest)(struct IntuitionIFace *Self, struct Window * window, const struct IntuiText * body, const struct IntuiText * posText, const struct IntuiText * negText, ULONG pFlag, ULONG nFlag, UWORD width, UWORD height);
	VOID APICALL (*BeginRefresh)(struct IntuitionIFace *Self, struct Window * window);
	struct Window * APICALL (*BuildSysRequest)(struct IntuitionIFace *Self, struct Window * window, const struct IntuiText * body, const struct IntuiText * posText, const struct IntuiText * negText, ULONG flags, UWORD width, UWORD height);
	VOID APICALL (*EndRefresh)(struct IntuitionIFace *Self, struct Window * window, LONG complete);
	VOID APICALL (*FreeSysRequest)(struct IntuitionIFace *Self, struct Window * window);
	LONG APICALL (*MakeScreen)(struct IntuitionIFace *Self, struct Screen * screen);
	LONG APICALL (*RemakeDisplay)(struct IntuitionIFace *Self);
	LONG APICALL (*RethinkDisplay)(struct IntuitionIFace *Self);
	APTR APICALL (*AllocRemember)(struct IntuitionIFace *Self, struct Remember ** rememberKey, ULONG size, ULONG flags);
	VOID APICALL (*AlohaWorkbench)(struct IntuitionIFace *Self, LONG wbport);
	VOID APICALL (*FreeRemember)(struct IntuitionIFace *Self, struct Remember ** rememberKey, BOOL reallyForget);
	ULONG APICALL (*LockIBase)(struct IntuitionIFace *Self, ULONG dontknow);
	VOID APICALL (*UnlockIBase)(struct IntuitionIFace *Self, ULONG ibLock);
	LONG APICALL (*GetScreenData)(struct IntuitionIFace *Self, APTR buffer, UWORD size, UWORD type, const struct Screen * screen);
	VOID APICALL (*RefreshGList)(struct IntuitionIFace *Self, struct Gadget * gadgets, struct Window * window, struct Requester * requester, WORD numGad);
	UWORD APICALL (*AddGList)(struct IntuitionIFace *Self, struct Window * window, struct Gadget * gadget, UWORD position, WORD numGad, struct Requester * requester);
	UWORD APICALL (*RemoveGList)(struct IntuitionIFace *Self, struct Window * remPtr, struct Gadget * gadget, WORD numGad);
	VOID APICALL (*ActivateWindow)(struct IntuitionIFace *Self, struct Window * window);
	VOID APICALL (*RefreshWindowFrame)(struct IntuitionIFace *Self, struct Window * window);
	BOOL APICALL (*ActivateGadget)(struct IntuitionIFace *Self, struct Gadget * gadgets, struct Window * window, struct Requester * requester);
	VOID APICALL (*NewModifyProp)(struct IntuitionIFace *Self, struct Gadget * gadget, struct Window * window, struct Requester * requester, UWORD flags, UWORD horizPot, UWORD vertPot, UWORD horizBody, UWORD vertBody, WORD numGad);
	LONG APICALL (*QueryOverscan)(struct IntuitionIFace *Self, ULONG displayID, struct Rectangle * rect, WORD oScanType);
	VOID APICALL (*MoveWindowInFrontOf)(struct IntuitionIFace *Self, struct Window * window, struct Window * behindWindow);
	VOID APICALL (*ChangeWindowBox)(struct IntuitionIFace *Self, struct Window * window, WORD left, WORD top, WORD width, WORD height);
	struct Hook * APICALL (*SetEditHook)(struct IntuitionIFace *Self, struct Hook * hook);
	LONG APICALL (*SetMouseQueue)(struct IntuitionIFace *Self, struct Window * window, UWORD queueLength);
	VOID APICALL (*ZipWindow)(struct IntuitionIFace *Self, struct Window * window);
	struct Screen * APICALL (*LockPubScreen)(struct IntuitionIFace *Self, CONST_STRPTR name);
	void APICALL (*UnlockPubScreen)(struct IntuitionIFace *Self, CONST_STRPTR name, struct Screen * screen);
	struct List * APICALL (*LockPubScreenList)(struct IntuitionIFace *Self);
	VOID APICALL (*UnlockPubScreenList)(struct IntuitionIFace *Self);
	STRPTR APICALL (*NextPubScreen)(struct IntuitionIFace *Self, const struct Screen * screen, STRPTR namebuf);
	void APICALL (*SetDefaultPubScreen)(struct IntuitionIFace *Self, CONST_STRPTR name);
	UWORD APICALL (*SetPubScreenModes)(struct IntuitionIFace *Self, UWORD modes);
	UWORD APICALL (*PubScreenStatus)(struct IntuitionIFace *Self, struct Screen * screen, UWORD statusFlags);
	struct RastPort * APICALL (*ObtainGIRPort)(struct IntuitionIFace *Self, struct GadgetInfo * gInfo);
	VOID APICALL (*ReleaseGIRPort)(struct IntuitionIFace *Self, struct RastPort * rp);
	VOID APICALL (*GadgetMouse)(struct IntuitionIFace *Self, struct Gadget * gadget, struct GadgetInfo * gInfo, WORD * mousePoint);
	APTR APICALL (*SetIPrefs)(struct IntuitionIFace *Self, APTR ptr, LONG size, LONG type);
	VOID APICALL (*GetDefaultPubScreen)(struct IntuitionIFace *Self, STRPTR nameBuffer);
	LONG APICALL (*EasyRequestArgs)(struct IntuitionIFace *Self, struct Window * window, const struct EasyStruct * easyStruct, ULONG * idcmpPtr, const APTR args);
	LONG APICALL (*EasyRequest)(struct IntuitionIFace *Self, struct Window * window, const struct EasyStruct * easyStruct, ULONG * idcmpPtr, ...);
	struct Window * APICALL (*BuildEasyRequestArgs)(struct IntuitionIFace *Self, struct Window * window, const struct EasyStruct * easyStruct, ULONG idcmp, const APTR args);
	struct Window * APICALL (*BuildEasyRequest)(struct IntuitionIFace *Self, struct Window * window, const struct EasyStruct * easyStruct, ULONG idcmp, ...);
	LONG APICALL (*SysReqHandler)(struct IntuitionIFace *Self, struct Window * window, ULONG * idcmpPtr, BOOL waitInput);
	struct Window * APICALL (*OpenWindowTagList)(struct IntuitionIFace *Self, const struct NewWindow * newWindow, const struct TagItem * tagList);
	struct Window * APICALL (*OpenWindowTags)(struct IntuitionIFace *Self, const struct NewWindow * newWindow, ...);
	struct Screen * APICALL (*OpenScreenTagList)(struct IntuitionIFace *Self, const struct NewScreen * newScreen, const struct TagItem * tagList);
	struct Screen * APICALL (*OpenScreenTags)(struct IntuitionIFace *Self, const struct NewScreen * newScreen, ...);
	VOID APICALL (*DrawImageState)(struct IntuitionIFace *Self, struct RastPort * rp, struct Image * image, WORD leftOffset, WORD topOffset, ULONG state, const struct DrawInfo * drawInfo);
	BOOL APICALL (*PointInImage)(struct IntuitionIFace *Self, ULONG point, struct Image * image);
	VOID APICALL (*EraseImage)(struct IntuitionIFace *Self, struct RastPort * rp, struct Image * image, WORD leftOffset, WORD topOffset);
	Object * APICALL (*NewObjectA)(struct IntuitionIFace *Self, Class * cl, ClassID classID, const struct TagItem * tagList);
	Object * APICALL (*NewObject)(struct IntuitionIFace *Self, Class * cl, ClassID classID, ...);
	void APICALL (*DisposeObject)(struct IntuitionIFace *Self, Object * object);
	uint32 APICALL (*SetAttrsA)(struct IntuitionIFace *Self, Object * object, const struct TagItem * tagList);
	uint32 APICALL (*SetAttrs)(struct IntuitionIFace *Self, APTR object, ...);
	uint32 APICALL (*GetAttr)(struct IntuitionIFace *Self, uint32 attrID, Object * object, uint32 * storagePtr);
	uint32 APICALL (*SetGadgetAttrsA)(struct IntuitionIFace *Self, struct Gadget * gadget, struct Window * window, struct Requester * requester, const struct TagItem * tagList);
	uint32 APICALL (*SetGadgetAttrs)(struct IntuitionIFace *Self, struct Gadget * gadget, struct Window * window, struct Requester * requester, ...);
	Object * APICALL (*NextObject)(struct IntuitionIFace *Self, Object ** objectPtrPtr);
	Class * APICALL (*FindClass)(struct IntuitionIFace *Self, ClassID classID);
	Class * APICALL (*MakeClass)(struct IntuitionIFace *Self, ClassID classID, ClassID superClassID, const Class * superClassPtr, uint16 instanceSize, uint32 flags);
	void APICALL (*AddClass)(struct IntuitionIFace *Self, Class * cl);
	struct DrawInfo * APICALL (*GetScreenDrawInfo)(struct IntuitionIFace *Self, struct Screen * screen);
	VOID APICALL (*FreeScreenDrawInfo)(struct IntuitionIFace *Self, struct Screen * screen, struct DrawInfo * drawInfo);
	BOOL APICALL (*ResetMenuStrip)(struct IntuitionIFace *Self, struct Window * window, struct Menu * menu);
	void APICALL (*RemoveClass)(struct IntuitionIFace *Self, Class * cl);
	BOOL APICALL (*FreeClass)(struct IntuitionIFace *Self, Class * cl);
	struct List * APICALL (*LockClassList)(struct IntuitionIFace *Self);
	VOID APICALL (*UnlockClassList)(struct IntuitionIFace *Self);
	void APICALL (*Reserved1)(struct IntuitionIFace *Self);
	void APICALL (*Reserved2)(struct IntuitionIFace *Self);
	void APICALL (*Reserved3)(struct IntuitionIFace *Self);
	void APICALL (*Reserved4)(struct IntuitionIFace *Self);
	void APICALL (*Reserved5)(struct IntuitionIFace *Self);
	void APICALL (*Reserved6)(struct IntuitionIFace *Self);
	struct ScreenBuffer * APICALL (*AllocScreenBuffer)(struct IntuitionIFace *Self, struct Screen * sc, struct BitMap * bm, ULONG flags);
	VOID APICALL (*FreeScreenBuffer)(struct IntuitionIFace *Self, struct Screen * sc, struct ScreenBuffer * sb);
	ULONG APICALL (*ChangeScreenBuffer)(struct IntuitionIFace *Self, struct Screen * sc, struct ScreenBuffer * sb);
	VOID APICALL (*ScreenDepth)(struct IntuitionIFace *Self, struct Screen * screen, ULONG flags, APTR reserved);
	VOID APICALL (*ScreenPosition)(struct IntuitionIFace *Self, struct Screen * screen, ULONG flags, LONG x1, LONG y1, LONG x2, LONG y2);
	VOID APICALL (*ScrollWindowRaster)(struct IntuitionIFace *Self, struct Window * win, WORD dx, WORD dy, WORD xMin, WORD yMin, WORD xMax, WORD yMax);
	VOID APICALL (*LendMenus)(struct IntuitionIFace *Self, struct Window * fromwindow, struct Window * towindow);
	uint32 APICALL (*DoGadgetMethodA)(struct IntuitionIFace *Self, struct Gadget * gad, struct Window * win, struct Requester * req, Msg message);
	uint32 APICALL (*DoGadgetMethod)(struct IntuitionIFace *Self, struct Gadget * gad, struct Window * win, struct Requester * req, ...);
	VOID APICALL (*SetWindowPointerA)(struct IntuitionIFace *Self, struct Window * win, const struct TagItem * taglist);
	VOID APICALL (*SetWindowPointer)(struct IntuitionIFace *Self, struct Window * win, ...);
	BOOL APICALL (*TimedDisplayAlert)(struct IntuitionIFace *Self, uint32 alertNumber, CONST_STRPTR string, uint16 height, uint32 Time);
	VOID APICALL (*HelpControl)(struct IntuitionIFace *Self, struct Window * win, ULONG flags);
	BOOL APICALL (*ShowWindow)(struct IntuitionIFace *Self, struct Window * window, struct Window * other);
	BOOL APICALL (*HideWindow)(struct IntuitionIFace *Self, struct Window * window);
	uint32 APICALL (*GetAttrsA)(struct IntuitionIFace *Self, Object * object, struct TagItem * tagList);
	uint32 APICALL (*GetAttrs)(struct IntuitionIFace *Self, APTR object, ...);
	APTR APICALL (*LockGUIPrefs)(struct IntuitionIFace *Self, ULONG reserved);
	VOID APICALL (*UnlockGUIPrefs)(struct IntuitionIFace *Self, APTR lock);
	ULONG APICALL (*SetGUIAttrsA)(struct IntuitionIFace *Self, APTR reserved, struct DrawInfo * drawinfo, struct TagItem * taglist);
	ULONG APICALL (*SetGUIAttrs)(struct IntuitionIFace *Self, APTR reserved, struct DrawInfo * drawinfo, ...);
	ULONG APICALL (*GetGUIAttrsA)(struct IntuitionIFace *Self, APTR reserved, struct DrawInfo * drawinfo, struct TagItem * taglist);
	ULONG APICALL (*GetGUIAttrs)(struct IntuitionIFace *Self, APTR reserved, struct DrawInfo * drawinfo, ...);
	ULONG APICALL (*GetHalfPens)(struct IntuitionIFace *Self, struct DrawInfo * drawinfo, ULONG basepen, UWORD * halfshineptr, UWORD * halfshadowptr);
	ULONG APICALL (*GadgetBox)(struct IntuitionIFace *Self, struct Gadget * gadget, APTR domain, ULONG domaintype, ULONG flags, APTR box);
	void APICALL (*RefreshSetGadgetAttrsA)(struct IntuitionIFace *Self, struct Gadget * gadget, struct Window * window, struct Requester * req, struct TagItem * taglist);
	void APICALL (*RefreshSetGadgetAttrs)(struct IntuitionIFace *Self, struct Gadget * gadget, struct Window * window, struct Requester * req, ...);
	uint32 APICALL (*IDoSuperMethodA)(struct IntuitionIFace *Self, Class * cl, Object * object, Msg msg);
	uint32 APICALL (*IDoSuperMethod)(struct IntuitionIFace *Self, Class * cl, Object * object, ...);
	uint32 APICALL (*ISetSuperAttrsA)(struct IntuitionIFace *Self, Class * cl, Object * object, struct TagItem * taglist);
	uint32 APICALL (*ISetSuperAttrs)(struct IntuitionIFace *Self, Class * cl, Object * object, ...);
	uint32 APICALL (*ICoerceMethodA)(struct IntuitionIFace *Self, Class * cl, Object * object, Msg msg);
	uint32 APICALL (*ICoerceMethod)(struct IntuitionIFace *Self, Class * cl, Object * object, ...);
	uint32 APICALL (*IDoMethodA)(struct IntuitionIFace *Self, Object * object, Msg msg);
	uint32 APICALL (*IDoMethod)(struct IntuitionIFace *Self, Object * object, ...);
	struct ClassLibrary * APICALL (*OpenClass)(struct IntuitionIFace *Self, CONST_STRPTR name, uint32 version, Class ** cl_ptr);
	void APICALL (*CloseClass)(struct IntuitionIFace *Self, struct ClassLibrary * cl);
	struct Hook * APICALL (*SetDisplayBeepHook)(struct IntuitionIFace *Self, struct Hook * hook);
	BOOL APICALL (*LockScreen)(struct IntuitionIFace *Self, struct Screen * screen, ULONG micros);
	VOID APICALL (*UnlockScreen)(struct IntuitionIFace *Self, struct Screen * screen);
	LONG APICALL (*GetWindowAttrsA)(struct IntuitionIFace *Self, struct Window * win, struct TagItem * taglist);
	LONG APICALL (*GetWindowAttrs)(struct IntuitionIFace *Self, struct Window * win, ...);
	LONG APICALL (*SetWindowAttrsA)(struct IntuitionIFace *Self, struct Window * win, struct TagItem * taglist);
	LONG APICALL (*SetWindowAttrs)(struct IntuitionIFace *Self, struct Window * win, ...);
	LONG APICALL (*GetWindowAttr)(struct IntuitionIFace *Self, struct Window * win, ULONG attr, APTR data, ULONG size);
	LONG APICALL (*SetWindowAttr)(struct IntuitionIFace *Self, struct Window * win, ULONG attr, APTR data, ULONG size);
	VOID APICALL (*StripIntuiMessages)(struct IntuitionIFace *Self, struct MsgPort * port, struct Window * win);
	void APICALL (*Reserved7)(struct IntuitionIFace *Self);
	void APICALL (*Reserved8)(struct IntuitionIFace *Self);
	LONG APICALL (*GetScreenAttrsA)(struct IntuitionIFace *Self, struct Screen * scr, struct TagItem * taglist);
	LONG APICALL (*GetScreenAttrs)(struct IntuitionIFace *Self, struct Screen * scr, ...);
	LONG APICALL (*SetScreenAttrsA)(struct IntuitionIFace *Self, struct Screen * scr, struct TagItem * taglist);
	LONG APICALL (*SetScreenAttrs)(struct IntuitionIFace *Self, struct Screen * scr, ...);
	LONG APICALL (*GetScreenAttr)(struct IntuitionIFace *Self, struct Screen * scr, ULONG attr, APTR data, ULONG size);
	LONG APICALL (*SetScreenAttr)(struct IntuitionIFace *Self, struct Screen * scr, ULONG attr, APTR data, ULONG size);
	struct Screen * APICALL (*LockScreenList)(struct IntuitionIFace *Self);
	VOID APICALL (*UnlockScreenList)(struct IntuitionIFace *Self);
	struct RastPort * APICALL (*LockScreenGI)(struct IntuitionIFace *Self, struct GadgetInfo * gi, ULONG micros);
	VOID APICALL (*UnlockScreenGI)(struct IntuitionIFace *Self, struct GadgetInfo * gi, struct RastPort * rp);
	ULONG APICALL (*GetMarkedBlock)(struct IntuitionIFace *Self, struct SGWork * sgw);
	VOID APICALL (*SetMarkedBlock)(struct IntuitionIFace *Self, struct SGWork * sgw, ULONG block);
	APTR APICALL (*ObtainBitMapSourceA)(struct IntuitionIFace *Self, CONST_STRPTR name, struct TagItem * taglist);
	APTR APICALL (*ObtainBitMapSource)(struct IntuitionIFace *Self, CONST_STRPTR name, ...);
	VOID APICALL (*ReleaseBitMapSource)(struct IntuitionIFace *Self, APTR bitmapsource);
	APTR APICALL (*ObtainBitMapInstanceA)(struct IntuitionIFace *Self, APTR bitmapsource, struct Screen * screen, struct TagItem * taglist);
	APTR APICALL (*ObtainBitMapInstance)(struct IntuitionIFace *Self, APTR bitmapsource, struct Screen * screen, ...);
	VOID APICALL (*ReleaseBitMapInstance)(struct IntuitionIFace *Self, APTR bitmapinstance);
	void APICALL (*EmbossDisableRect)(struct IntuitionIFace *Self, struct RastPort * rp, int32 minx, int32 miny, int32 maxx, int32 maxy, uint32 backtype, uint32 contrast, struct DrawInfo * dri);
	void APICALL (*EmbossDisableText)(struct IntuitionIFace *Self, struct RastPort * rp, CONST_STRPTR text, uint32 len, uint32 backtype, uint32 contrast, struct DrawInfo * dri);
	VOID APICALL (*PrintEmbossedDisabledIText)(struct IntuitionIFace *Self, struct RastPort * rp, struct IntuiText * itext, LONG left, LONG top, ULONG backtype, ULONG contrast, struct DrawInfo * dri);
	ULONG APICALL (*IntuiTextExtent)(struct IntuitionIFace *Self, struct RastPort * rp, struct IntuiText * itext, struct TextExtent * textent);
	ULONG APICALL (*ShadeRectOld)(struct IntuitionIFace *Self, struct RastPort * rp, LONG minx, LONG miny, LONG maxx, LONG maxy, ULONG shadelevel, ULONG backtype, ULONG state, struct DrawInfo * dri);
	VOID APICALL (*DisableTemplateRGB)(struct IntuitionIFace *Self, struct RastPort * rp, LONG left, LONG top, LONG width, LONG height, PLANEPTR template_ptr, ULONG brightlevel, ULONG darklevel);
	ULONG APICALL (*SetScreenBitMapInstance)(struct IntuitionIFace *Self, struct Screen * scr, ULONG id, APTR source);
	UWORD APICALL (*FindMenuKey)(struct IntuitionIFace *Self, struct Menu * menu, LONG code);
	ULONG APICALL (*BitMapInstanceControlA)(struct IntuitionIFace *Self, APTR bitmapinstance, struct TagItem * taglist);
	ULONG APICALL (*BitMapInstanceControl)(struct IntuitionIFace *Self, APTR bitmapinstance, ...);
	struct List * APICALL (*ObtainIPluginList)(struct IntuitionIFace *Self, ULONG type, ULONG attrmask, ULONG applymask);
	VOID APICALL (*ReleaseIPluginList)(struct IntuitionIFace *Self, struct List * list);
	struct GUIPlugin * APICALL (*OpenGUIPlugin)(struct IntuitionIFace *Self, STRPTR name, ULONG version, ULONG type, ULONG attrmask, ULONG applymask);
	VOID APICALL (*CloseGUIPlugin)(struct IntuitionIFace *Self, struct GUIPlugin * plugin);
	ULONG APICALL (*DrawSysImageA)(struct IntuitionIFace *Self, struct RastPort * rp, LONG left, LONG top, LONG width, LONG height, ULONG which, ULONG backtype, ULONG state, struct DrawInfo * dri, struct TagItem * taglist);
	ULONG APICALL (*DrawSysImage)(struct IntuitionIFace *Self, struct RastPort * rp, LONG left, LONG top, LONG width, LONG height, ULONG which, ULONG backtype, ULONG state, struct DrawInfo * dri, ...);
	uint32 APICALL (*DoRender)(struct IntuitionIFace *Self, Object * o, struct GadgetInfo * gi, uint32 flags);
	ULONG APICALL (*SetRenderDomain)(struct IntuitionIFace *Self, struct RastPort * rp, struct Rectangle * domain);
	ULONG APICALL (*GetRenderDomain)(struct IntuitionIFace *Self, struct RastPort * rp, struct Rectangle * domain);
	ULONG APICALL (*DrawGradient)(struct IntuitionIFace *Self, struct RastPort * rp, LONG left, LONG top, LONG width, LONG height, struct IBox * domain, ULONG reserved, struct GradientSpec * gradientspec, struct DrawInfo * dri);
	ULONG APICALL (*DirectionVector)(struct IntuitionIFace *Self, ULONG degrees);
	ULONG APICALL (*ShadeRectA)(struct IntuitionIFace *Self, struct RastPort * rp, LONG minx, LONG miny, LONG maxx, LONG maxy, ULONG shadelevel, ULONG backtype, ULONG state, struct DrawInfo * dri, struct TagItem * taglist);
	ULONG APICALL (*ShadeRect)(struct IntuitionIFace *Self, struct RastPort * rp, LONG minx, LONG miny, LONG maxx, LONG maxy, ULONG shadelevel, ULONG backtype, ULONG state, struct DrawInfo * dri, ...);
	VOID APICALL (*DoScrollHook)(struct IntuitionIFace *Self, struct ScrollHook * scrollhook, LONG scrollmode);
	struct Hook * APICALL (*ObtainIBackFill)(struct IntuitionIFace *Self, struct DrawInfo * dri, ULONG element, ULONG state, ULONG flags);
	VOID APICALL (*ReleaseIBackFill)(struct IntuitionIFace *Self, struct Hook * hook);
	ULONG APICALL (*IntuitionControlA)(struct IntuitionIFace *Self, APTR object, struct TagItem * taglist);
	ULONG APICALL (*IntuitionControl)(struct IntuitionIFace *Self, APTR object, ...);
	APTR APICALL (*StartScreenNotifyTagList)(struct IntuitionIFace *Self, struct TagItem * taglist);
	APTR APICALL (*StartScreenNotifyTags)(struct IntuitionIFace *Self, ...);
	BOOL APICALL (*EndScreenNotify)(struct IntuitionIFace *Self, APTR request);
	VOID APICALL (*DisableTemplate)(struct IntuitionIFace *Self, struct RastPort * rp, LONG left, LONG top, LONG width, LONG height, APTR template_ptr, LONG offx, ULONG template_type, ULONG bytesperrow, ULONG backtype, struct DrawInfo * dri);
};

/**********************************************************************************************/

struct IntuiWheelData
{
    UWORD Version;  /* version of this structure (see below) */
    UWORD Reserved; /* always 0, reserved for future use     */
    WORD  WheelX;   /* horizontal wheel movement delta       */
    WORD  WheelY;   /* vertical wheel movement delta         */
};

/**********************************************************************************************/

struct IOSana2Req
{
    struct IORequest ios2_Req;

    ULONG ios2_WireError;                     /* wire type specific error */
    ULONG ios2_PacketType;                    /* packet type */
    UBYTE ios2_SrcAddr[SANA2_MAX_ADDR_BYTES]; /* source address */
    UBYTE ios2_DstAddr[SANA2_MAX_ADDR_BYTES]; /* dest address */
    ULONG ios2_DataLength;                    /* length of packet data */
    APTR  ios2_Data;                          /* packet data */
    APTR  ios2_StatData;                      /* statistics data pointer */
    APTR  ios2_BufferManagement;              /* see SANA-II OpenDevice adoc */
};

/**********************************************************************************************/

struct impExtent
{
    ULONG            MethodID;
    struct DrawInfo *imp_DrInfo; /* May be NULL */
    struct RastPort *imp_RPort;  /* NULL if masking not supported */
    struct Region   *imp_Region; /* NULL if clipping not supported */
    ULONG            imp_Action; /* Requested operation */
    ULONG            imp_Flags;  /* Control flags, see below */
    struct TagItem  *imp_Attrs;  /* Additional attributes */
    ULONG            imp_State;  /* Rendering state */
    struct IBox      imp_Frame;  /* Sizes only valid for IM_EXTENTFRAME */
};

/**********************************************************************************************/

struct KeymapIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct KeymapIFace *Self);
	ULONG APICALL (*Release)(struct KeymapIFace *Self);
	void APICALL (*Expunge)(struct KeymapIFace *Self);
	struct Interface * APICALL (*Clone)(struct KeymapIFace *Self);
	VOID APICALL (*SetKeyMapDefault)(struct KeymapIFace *Self, const struct KeyMap * keyMap);
	struct KeyMap * APICALL (*AskKeyMapDefault)(struct KeymapIFace *Self);
	WORD APICALL (*MapRawKey)(struct KeymapIFace *Self, const struct InputEvent * event, STRPTR buffer, WORD length, const struct KeyMap * keyMap);
	LONG APICALL (*MapANSI)(struct KeymapIFace *Self, CONST_STRPTR string, LONG count, STRPTR buffer, LONG length, const struct KeyMap * keyMap);
	APTR APICALL (*OpenKeyMapHandleA)(struct KeymapIFace *Self, CONST_STRPTR filename, const struct TagItem * taglist);
	APTR APICALL (*OpenKeyMapHandle)(struct KeymapIFace *Self, CONST_STRPTR filename, ...);
	VOID APICALL (*CloseKeyMapHandle)(struct KeymapIFace *Self, APTR handle);
	ULONG APICALL (*ObtainKeyMapInfoA)(struct KeymapIFace *Self, APTR handle, const struct TagItem * taglist);
	ULONG APICALL (*ObtainKeyMapInfo)(struct KeymapIFace *Self, APTR handle, ...);
	VOID APICALL (*ReleaseKeyMapInfoA)(struct KeymapIFace *Self, APTR handle, const struct TagItem * taglist);
	VOID APICALL (*ReleaseKeyMapInfo)(struct KeymapIFace *Self, APTR handle, ...);
	VOID APICALL (*ObtainRawKeyInfoA)(struct KeymapIFace *Self, const struct TagItem * taglist);
	VOID APICALL (*ObtainRawKeyInfo)(struct KeymapIFace *Self, ...);
};

/**********************************************************************************************/

struct LabelIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct LabelIFace *Self);
	ULONG APICALL (*Release)(struct LabelIFace *Self);
	void APICALL (*Expunge)(struct LabelIFace *Self);
	struct Interface * APICALL (*Clone)(struct LabelIFace *Self);
	Class * APICALL (*LABEL_GetClass)(struct LabelIFace *Self);
};

/**********************************************************************************************/

struct LayerComposeMsg
{
   ULONG Action;
   struct Layer_Info *LayerInfo;
   struct BitMap *BackBitMap;
   struct Rectangle Bounds;
};

/**********************************************************************************************/

struct LayersIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct LayersIFace *Self);
	ULONG APICALL (*Release)(struct LayersIFace *Self);
	void APICALL (*Expunge)(struct LayersIFace *Self);
	struct Interface * APICALL (*Clone)(struct LayersIFace *Self);
	VOID APICALL (*InitLayers)(struct LayersIFace *Self, struct Layer_Info * li);
	struct Layer * APICALL (*CreateUpfrontLayer)(struct LayersIFace *Self, struct Layer_Info * li, struct BitMap * bm, LONG x0, LONG y0, LONG x1, LONG y1, LONG flags, struct BitMap * bm2);
	struct Layer * APICALL (*CreateBehindLayer)(struct LayersIFace *Self, struct Layer_Info * li, struct BitMap * bm, LONG x0, LONG y0, LONG x1, LONG y1, LONG flags, struct BitMap * bm2);
	LONG APICALL (*UpfrontLayer)(struct LayersIFace *Self, LONG dummy, struct Layer * layer);
	LONG APICALL (*BehindLayer)(struct LayersIFace *Self, LONG dummy, struct Layer * layer);
	LONG APICALL (*MoveLayer)(struct LayersIFace *Self, LONG dummy, struct Layer * layer, LONG dx, LONG dy);
	LONG APICALL (*SizeLayer)(struct LayersIFace *Self, LONG dummy, struct Layer * layer, LONG dx, LONG dy);
	VOID APICALL (*ScrollLayer)(struct LayersIFace *Self, LONG dummy, struct Layer * layer, LONG dx, LONG dy);
	LONG APICALL (*BeginUpdate)(struct LayersIFace *Self, struct Layer * l);
	VOID APICALL (*EndUpdate)(struct LayersIFace *Self, struct Layer * layer, UWORD flag);
	LONG APICALL (*DeleteLayer)(struct LayersIFace *Self, LONG dummy, struct Layer * layer);
	VOID APICALL (*LockLayer)(struct LayersIFace *Self, LONG dummy, struct Layer * layer);
	VOID APICALL (*UnlockLayer)(struct LayersIFace *Self, struct Layer * layer);
	VOID APICALL (*LockLayers)(struct LayersIFace *Self, struct Layer_Info * li);
	BOOL APICALL (*UnlockLayers)(struct LayersIFace *Self, struct Layer_Info * li);
	VOID APICALL (*LockLayerInfo)(struct LayersIFace *Self, struct Layer_Info * li);
	VOID APICALL (*SwapBitsRastPortClipRect)(struct LayersIFace *Self, struct RastPort * rp, struct ClipRect * cr);
	struct Layer * APICALL (*WhichLayer)(struct LayersIFace *Self, struct Layer_Info * li, WORD x, WORD y);
	VOID APICALL (*UnlockLayerInfo)(struct LayersIFace *Self, struct Layer_Info * li);
	struct Layer_Info * APICALL (*NewLayerInfo)(struct LayersIFace *Self);
	VOID APICALL (*DisposeLayerInfo)(struct LayersIFace *Self, struct Layer_Info * li);
	LONG APICALL (*FattenLayerInfo)(struct LayersIFace *Self, struct Layer_Info * li);
	VOID APICALL (*ThinLayerInfo)(struct LayersIFace *Self, struct Layer_Info * li);
	LONG APICALL (*MoveLayerInFrontOf)(struct LayersIFace *Self, struct Layer * layer_to_move, struct Layer * other_layer);
	struct Region * APICALL (*InstallClipRegion)(struct LayersIFace *Self, struct Layer * layer, CONST struct Region * region);
	LONG APICALL (*MoveSizeLayer)(struct LayersIFace *Self, struct Layer * layer, LONG dx, LONG dy, LONG dw, LONG dh);
	struct Layer * APICALL (*CreateUpfrontHookLayer)(struct LayersIFace *Self, struct Layer_Info * li, struct BitMap * bm, LONG x0, LONG y0, LONG x1, LONG y1, LONG flags, struct Hook * hook, struct BitMap * bm2);
	struct Layer * APICALL (*CreateBehindHookLayer)(struct LayersIFace *Self, struct Layer_Info * li, struct BitMap * bm, LONG x0, LONG y0, LONG x1, LONG y1, LONG flags, struct Hook * hook, struct BitMap * bm2);
	struct Hook * APICALL (*InstallLayerHook)(struct LayersIFace *Self, struct Layer * layer, struct Hook * hook);
	struct Hook * APICALL (*InstallLayerInfoHook)(struct LayersIFace *Self, struct Layer_Info * li, CONST struct Hook * hook);
	VOID APICALL (*SortLayerCR)(struct LayersIFace *Self, struct Layer * layer, WORD dx, WORD dy);
	VOID APICALL (*DoHookClipRects)(struct LayersIFace *Self, CONST struct Hook * hook, struct RastPort * rport, CONST struct Rectangle * rect);
	LONG APICALL (*LayerOccluded)(struct LayersIFace *Self, struct Layer * layer);
	LONG APICALL (*HideLayer)(struct LayersIFace *Self, struct Layer * layer);
	LONG APICALL (*ShowLayer)(struct LayersIFace *Self, struct Layer * layer, struct Layer * infront_of);
	LONG APICALL (*SetLayerInfoBounds)(struct LayersIFace *Self, struct Layer_Info * li, struct Rectangle * bounds);
	struct ClipRect * APICALL (*AllocClipRect)(struct LayersIFace *Self, struct Layer_Info * li);
	VOID APICALL (*FreeClipRect)(struct LayersIFace *Self, struct Layer_Info * li, struct ClipRect * cr);
	struct Layer * APICALL (*CreateLayerA)(struct LayersIFace *Self, struct Layer_Info * li, struct TagItem * tlist);
	struct Layer * APICALL (*CreateLayer)(struct LayersIFace *Self, struct Layer_Info * li, ...);
	struct Region * APICALL (*ChangeLayerShape)(struct LayersIFace *Self, struct Layer * layer, struct Region * region, struct Hook * hook);
	struct Hook * APICALL (*CreateBackFillHookA)(struct LayersIFace *Self, struct TagItem * tlist);
	struct Hook * APICALL (*CreateBackFillHook)(struct LayersIFace *Self, ...);
	VOID APICALL (*DeleteBackFillHook)(struct LayersIFace *Self, struct Hook * hook);
	ULONG APICALL (*SetBackFillHookAttrsA)(struct LayersIFace *Self, struct Hook * h, struct TagItem * tags);
	ULONG APICALL (*SetBackFillHookAttrs)(struct LayersIFace *Self, struct Hook * h, ...);
	ULONG APICALL (*GetBackFillHookAttrsA)(struct LayersIFace *Self, struct Hook * h, struct TagItem * tags);
	ULONG APICALL (*GetBackFillHookAttrs)(struct LayersIFace *Self, struct Hook * h, ...);
	ULONG APICALL (*ComposeLayersA)(struct LayersIFace *Self, struct Layer * l, struct Rectangle * rect, struct TagItem * taglist);
	ULONG APICALL (*ComposeLayers)(struct LayersIFace *Self, struct Layer * l, struct Rectangle * rect, ...);
	struct BitMap * APICALL (*GetOffScreenLayerBitMap)(struct LayersIFace *Self, struct Layer * l, struct BitMap * fallback, struct Rectangle * bounds);
	ULONG APICALL (*SetLayerInfoAttrsA)(struct LayersIFace *Self, struct Layer_Info * li, struct TagItem * taglist);
	ULONG APICALL (*SetLayerInfoAttrs)(struct LayersIFace *Self, struct Layer_Info * li, ...);
	ULONG APICALL (*GetLayerInfoAttrsA)(struct LayersIFace *Self, struct Layer_Info * li, struct TagItem * taglist);
	ULONG APICALL (*GetLayerInfoAttrs)(struct LayersIFace *Self, struct Layer_Info * li, ...);
	struct ClipRect * APICALL (*ChangeLayerAlpha)(struct LayersIFace *Self, struct Layer * layer, struct ClipRect * clips, struct Hook * hook);
	ULONG APICALL (*SetForegroundAlpha)(struct LayersIFace *Self, struct Layer * layer, APTR templateptr, ULONG templatetype, ULONG bytesperrow, LONG left, LONG top, ULONG width, ULONG height, ULONG flags);
	ULONG APICALL (*SetLayerOpaqueness)(struct LayersIFace *Self, struct Layer * layer, ULONG opaqueness);
	ULONG APICALL (*SetLayerOverlayRect)(struct LayersIFace *Self, struct Layer * layer, LONG left, LONG top, LONG width, LONG height, ULONG flags);
};

/**********************************************************************************************/

struct LayoutIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct LayoutIFace *Self);
	ULONG APICALL (*Release)(struct LayoutIFace *Self);
	void APICALL (*Expunge)(struct LayoutIFace *Self);
	struct Interface * APICALL (*Clone)(struct LayoutIFace *Self);
	Class * APICALL (*LAYOUT_GetClass)(struct LayoutIFace *Self);
	BOOL APICALL (*ActivateLayoutGadget)(struct LayoutIFace *Self, struct Gadget * gadget, struct Window * window, struct Requester * requester, ULONG object);
	VOID APICALL (*FlushLayoutDomainCache)(struct LayoutIFace *Self, struct Gadget * gadget);
	BOOL APICALL (*RethinkLayout)(struct LayoutIFace *Self, struct Gadget * gadget, struct Window * window, struct Requester * requester, BOOL refresh);
	VOID APICALL (*LayoutLimits)(struct LayoutIFace *Self, struct Gadget * gadget, struct LayoutLimits * limits, struct TextFont * font, struct Screen * screen);
	Class * APICALL (*PAGE_GetClass)(struct LayoutIFace *Self);
	ULONG APICALL (*SetPageGadgetAttrsA)(struct LayoutIFace *Self, struct Gadget * gadget, Object * object, struct Window * window, struct Requester * requester, struct TagItem * tags);
	ULONG APICALL (*SetPageGadgetAttrs)(struct LayoutIFace *Self, struct Gadget * gadget, Object * object, struct Window * window, struct Requester * requester, ...);
	VOID APICALL (*RefreshPageGadget)(struct LayoutIFace *Self, struct Gadget * gadget, Object * object, struct Window * window, struct Requester * requester);
};

/**********************************************************************************************/

struct LibraryManagerInterface
{
    struct InterfaceData Data;

    uint32             APICALL (*Obtain) (struct LibraryManagerInterface *Self);
    uint32             APICALL (*Release)(struct LibraryManagerInterface *Self);
    VOID               APICALL (*Expunge)(struct LibraryManagerInterface *Self);
    struct Interface * APICALL (*Clone)  (struct LibraryManagerInterface *Self);

    struct Library *   APICALL (*Open)        (struct LibraryManagerInterface *Self,
                                               uint32 version);
    APTR               APICALL (*Close)       (struct LibraryManagerInterface *Self);
    APTR               APICALL (*LibExpunge)  (struct LibraryManagerInterface *Self);
    struct Interface * APICALL (*GetInterface)(struct LibraryManagerInterface *Self,
                                               STRPTR name, uint32 version,
                                               struct TagItem *taglist);
};

/**********************************************************************************************/

struct ListBrowserIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ListBrowserIFace *Self);
	ULONG APICALL (*Release)(struct ListBrowserIFace *Self);
	void APICALL (*Expunge)(struct ListBrowserIFace *Self);
	struct Interface * APICALL (*Clone)(struct ListBrowserIFace *Self);
	struct IClass * APICALL (*LISTBROWSER_GetClass)(struct ListBrowserIFace *Self);
	struct Node * APICALL (*AllocListBrowserNodeA)(struct ListBrowserIFace *Self, UWORD columns, struct TagItem * tags);
	struct Node * APICALL (*AllocListBrowserNode)(struct ListBrowserIFace *Self, UWORD columns, ...);
	VOID APICALL (*FreeListBrowserNode)(struct ListBrowserIFace *Self, struct Node * node);
	VOID APICALL (*SetListBrowserNodeAttrsA)(struct ListBrowserIFace *Self, struct Node * node, struct TagItem * tags);
	VOID APICALL (*SetListBrowserNodeAttrs)(struct ListBrowserIFace *Self, struct Node * node, ...);
	VOID APICALL (*GetListBrowserNodeAttrsA)(struct ListBrowserIFace *Self, struct Node * node, struct TagItem * tags);
	VOID APICALL (*GetListBrowserNodeAttrs)(struct ListBrowserIFace *Self, struct Node * node, ...);
	VOID APICALL (*ListBrowserSelectAll)(struct ListBrowserIFace *Self, struct List * list);
	VOID APICALL (*ShowListBrowserNodeChildren)(struct ListBrowserIFace *Self, struct Node * node, WORD depth);
	VOID APICALL (*HideListBrowserNodeChildren)(struct ListBrowserIFace *Self, struct Node * node);
	VOID APICALL (*ShowAllListBrowserChildren)(struct ListBrowserIFace *Self, struct List * list);
	VOID APICALL (*HideAllListBrowserChildren)(struct ListBrowserIFace *Self, struct List * list);
	VOID APICALL (*FreeListBrowserList)(struct ListBrowserIFace *Self, struct List * list);
	struct ColumnInfo * APICALL (*AllocLBColumnInfoA)(struct ListBrowserIFace *Self, UWORD columns, struct TagItem * tags);
	struct ColumnInfo * APICALL (*AllocLBColumnInfo)(struct ListBrowserIFace *Self, UWORD columns, ...);
	LONG APICALL (*SetLBColumnInfoAttrsA)(struct ListBrowserIFace *Self, struct ColumnInfo * columninfo, struct TagItem * tags);
	LONG APICALL (*SetLBColumnInfoAttrs)(struct ListBrowserIFace *Self, struct ColumnInfo * columninfo, ...);
	LONG APICALL (*GetLBColumnInfoAttrsA)(struct ListBrowserIFace *Self, struct ColumnInfo * columninfo, struct TagItem * tags);
	LONG APICALL (*GetLBColumnInfoAttrs)(struct ListBrowserIFace *Self, struct ColumnInfo * columninfo, ...);
	VOID APICALL (*FreeLBColumnInfo)(struct ListBrowserIFace *Self, struct ColumnInfo * columninfo);
	VOID APICALL (*ListBrowserClearAll)(struct ListBrowserIFace *Self, struct List * list);
};

/**********************************************************************************************/

struct ListLabelNode
{
    struct Node    lvn_Node;             /* Exec Node structure */
    ULONG          lvn_UserData;

    WORD           lvn_RenderForeground; /* Render foreground pen */
    WORD           lvn_RenderBackground; /* Render background pen */

    WORD           lvn_SelectForeground; /* Select foreground pen */
    WORD           lvn_SelectBackground; /* Select background pen */

    struct Image * lvn_RenderImage;      /* Optional rendered imagery */
    struct Image * lvn_SelectImage;      /* Optional selected imagery */

    /* PRIVATE FIELDS - CRASH & BURN! */
    WORD           lvn_TextLength;
    WORD           lvn_LeftEdge;
    WORD           lvn_TopEdge;
    WORD           lvn_Width;
    WORD           lvn_Height;
    WORD           lvn_Justification;    /* text/image justification */
    WORD           lvn_Selected;         /* is node selected? */
};

/**********************************************************************************************/

struct lmAddChild
{
    uint32           MethodID;
    struct Window *  lm_Window;      // Window pointer (may be NULL)
    Object *         lm_Object;      // Gadget object
    struct TagItem * lm_ObjectAttrs; // CHILD_#? tag list (may be NULL)
};

/**********************************************************************************************/

struct lmAddImage
{
    uint32           MethodID;
    struct Window *  lm_Window;      // Window pointer (may be NULL)
    Object *         lm_Object;      // Image object
    struct TagItem * lm_ObjectAttrs; // CHILD_#? tag list (may be NULL)
};

/**********************************************************************************************/

struct lmModifyChild
{
    uint32           MethodID;
    struct Window *  lm_Window;      // Window pointer (may be NULL)
    Object *         lm_Object;      // Object to modify
    struct TagItem * lm_ObjectAttrs; // CHILD_#? tag list (may be NULL)
};

/**********************************************************************************************/

struct lmRemoveChild
{
    uint32          MethodID;
    struct Window * lm_Window;   // Window pointer (may be NULL)
    Object *        lm_Object;   // Object to remove and dispose
};

/**********************************************************************************************/

struct LocaleIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct LocaleIFace *Self);
	ULONG APICALL (*Release)(struct LocaleIFace *Self);
	void APICALL (*Expunge)(struct LocaleIFace *Self);
	struct Interface * APICALL (*Clone)(struct LocaleIFace *Self);
	APTR Private1;
	VOID APICALL (*CloseCatalog)(struct LocaleIFace *Self, struct Catalog * catalog);
	VOID APICALL (*CloseLocale)(struct LocaleIFace *Self, struct Locale * locale);
	uint32 APICALL (*ConvToLower)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	uint32 APICALL (*ConvToUpper)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	VOID APICALL (*FormatDate)(struct LocaleIFace *Self, struct Locale * locale, CONST_STRPTR fmtTemplate, struct DateStamp * date, struct Hook * putCharFunc);
	APTR APICALL (*FormatString)(struct LocaleIFace *Self, struct Locale * locale, CONST_STRPTR fmtTemplate, APTR dataStream, struct Hook * putCharFunc);
	CONST_STRPTR APICALL (*GetCatalogStr)(struct LocaleIFace *Self, struct Catalog * catalog, int32 stringNum, CONST_STRPTR defaultString);
	CONST_STRPTR APICALL (*GetLocaleStr)(struct LocaleIFace *Self, struct Locale * locale, uint32 stringNum);
	int32 APICALL (*IsAlNum)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	int32 APICALL (*IsAlpha)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	int32 APICALL (*IsCntrl)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	int32 APICALL (*IsDigit)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	int32 APICALL (*IsGraph)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	int32 APICALL (*IsLower)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	int32 APICALL (*IsPrint)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	int32 APICALL (*IsPunct)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	int32 APICALL (*IsSpace)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	int32 APICALL (*IsUpper)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	int32 APICALL (*IsXDigit)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	struct Catalog * APICALL (*OpenCatalogA)(struct LocaleIFace *Self, struct Locale * locale, CONST_STRPTR name, const struct TagItem * tags);
	struct Catalog * APICALL (*OpenCatalog)(struct LocaleIFace *Self, struct Locale * locale, CONST_STRPTR name, ...);
	struct Locale * APICALL (*OpenLocale)(struct LocaleIFace *Self, CONST_STRPTR name);
	int32 APICALL (*ParseDate)(struct LocaleIFace *Self, struct Locale * locale, struct DateStamp * date, CONST_STRPTR fmtTemplate, struct Hook * getCharFunc);
	APTR Private2;
	uint32 APICALL (*StrConvert)(struct LocaleIFace *Self, struct Locale * locale, CONST_STRPTR string, APTR buffer, uint32 bufferSize, uint32 type);
	int32 APICALL (*StrnCmp)(struct LocaleIFace *Self, struct Locale * locale, CONST_STRPTR string1, CONST_STRPTR string2, int32 length, uint32 type);
	int32 APICALL (*Locale_DateToStr)(struct LocaleIFace *Self, struct DateTime * datetime);
	int32 APICALL (*Locale_StrToDate)(struct LocaleIFace *Self, struct DateTime * datetime);
	int32 APICALL (*IsBlank)(struct LocaleIFace *Self, struct Locale * locale, uint32 character);
	APTR APICALL (*FormatString32)(struct LocaleIFace *Self, struct Locale * locale, CONST_STRPTR fmtTemplate, APTR dataStream, struct Hook * putCharFunc);
};

/**********************************************************************************************/

struct Lock
{
    BPTR             fl_Link;        /* PRIVATE - filesystem use only.      */
    int32            fl_Key;         /* PRIVATE - filesystem use only.      */
    int32            fl_Access;      /* PRIVATE - filesystem use only.      */

    struct MsgPort * fl_Port;        /* handler process message port        */
    BPTR             fl_Volume;      /* BPTR to DLT_VOLUME DosList entry    */

                                     /* -- V51 additions -- */
    APTR             fl_FSPrivate1;  /* PRIVATE - filesystem use only.      */
    APTR             fl_FSPrivate2;  /* PRIVATE - filesystem use only.      */

    uint32           fl_DOSType;     /* The DOSType of the filesystem,      */
                                     /*   AllocDosObject() inits this.      */

    uint32           fl_StructSize;  /* Full DOS allocated size of struct,  */
                                     /*   AllocDosObject() inits this.      */

    int32            fl_DosPrivate;  /* PRIVATE - dos library use only.     */

                                     /* -- V53 additions -- */
    int32            fl_Reserved[2]; /* RESERVED for expansion. V53         */
};

/**********************************************************************************************/

struct LowLevelIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct LowLevelIFace *Self);
	ULONG APICALL (*Release)(struct LowLevelIFace *Self);
	void APICALL (*Expunge)(struct LowLevelIFace *Self);
	struct Interface * APICALL (*Clone)(struct LowLevelIFace *Self);
	ULONG APICALL (*ReadJoyPort)(struct LowLevelIFace *Self, ULONG port);
	UBYTE APICALL (*GetLanguageSelection)(struct LowLevelIFace *Self);
	APTR Private1;
	ULONG APICALL (*GetKey)(struct LowLevelIFace *Self);
	VOID APICALL (*QueryKeys)(struct LowLevelIFace *Self, struct KeyQuery * queryArray, UBYTE arraySize);
	APTR APICALL (*AddKBInt)(struct LowLevelIFace *Self, const APTR intRoutine, const APTR intData);
	VOID APICALL (*RemKBInt)(struct LowLevelIFace *Self, APTR intHandle);
	ULONG APICALL (*SystemControlA)(struct LowLevelIFace *Self, const struct TagItem * tagList);
	ULONG APICALL (*SystemControl)(struct LowLevelIFace *Self, ...);
	APTR APICALL (*AddTimerInt)(struct LowLevelIFace *Self, const APTR intRoutine, const APTR intData);
	VOID APICALL (*RemTimerInt)(struct LowLevelIFace *Self, APTR intHandle);
	VOID APICALL (*StopTimerInt)(struct LowLevelIFace *Self, APTR intHandle);
	VOID APICALL (*StartTimerInt)(struct LowLevelIFace *Self, APTR intHandle, ULONG timeInterval, BOOL continuous);
	ULONG APICALL (*ElapsedTime)(struct LowLevelIFace *Self, struct EClockVal * context);
	APTR APICALL (*AddVBlankInt)(struct LowLevelIFace *Self, const APTR intRoutine, const APTR intData);
	VOID APICALL (*RemVBlankInt)(struct LowLevelIFace *Self, APTR intHandle);
	APTR Private2;
	APTR Private3;
	BOOL APICALL (*SetJoyPortAttrsA)(struct LowLevelIFace *Self, ULONG portNumber, const struct TagItem * tagList);
	BOOL APICALL (*SetJoyPortAttrs)(struct LowLevelIFace *Self, ULONG portNumber, ...);
};

/**********************************************************************************************/

struct MessageDigest_SHA
{
    UBYTE mdsha_Code[20];
    UBYTE mdsha_Reserved[328];
};

/**********************************************************************************************/

struct MidiCluster
{
    struct Node         mcl_Node;               /* linked list node */
    int16               mcl_Participants;
    struct List         mcl_Receivers,          /* list of receivers */
                        mcl_Senders;            /* list of senders */
    int16               mcl_PublicParticipants; /* if >0, cluster is public */
    uint16              mcl_Flags;              /* flags for this location */
        /* NOTE: Cluster name follows structure, and is pointed to by ln_Name */
};

/**********************************************************************************************/

struct MidiDeviceData
{
    uint32 Magic;	    /* MDD_Magic */
    char  *Name; 	    /* driver name */
    char  *IDString;
    uint16 Version;
    uint16 Revision;

    BOOL (*Init)(void);     /* called after LoadSeg() */
    void (*Expunge)(void);  /* called before UnLoadSeg() */
    struct MidiPortData *(*OpenPort)();
    void (*ClosePort)();

    uint8 NPorts;	    /* number of ports */
    uint8 Flags;	    /* currently none */

    struct Library          *CamdDriverBase;
    struct CamdDriverIFace  *ICamdDriver;
};

/**********************************************************************************************/

struct MidiLink
{
    struct Node         ml_Node;                /* node for cluster list */
    int16               ml_Pad;
    struct MinNode      ml_OwnerNode;           /* node for interface list */
    struct MidiNode     *ml_MidiNode;           /* interface we belong to... */
    struct MidiCluster  *ml_Location;           /* location we are a member of */
    char                *ml_ClusterComment;     /* comment for cluster */
    uint8               ml_Flags;               /* general flags */
    uint8               ml_PortID;              /* number of this port */
    uint16              ml_ChannelMask;         /* mask flags for channel */
    uint32              ml_EventTypeMask;       /* mask flags for events */

    union SysExFilter {
        uint8           b[4];                   /* 1 byte mode, 3 bytes for match id(s) */
        uint32          sxf_Packed;
    } ml_SysExFilter;

    APTR                ml_ParserData;          /* private MIDI parser data */
    APTR                ml_UserData;            /* attached to events... */
};

/**********************************************************************************************/

struct MidiNode
{
    struct Node         mi_Node;                /* linked list node */
    uint16              mi_ClientType;          /* type of application */
    struct Image        *mi_Image;              /* image for patch panel */

    struct MinList      mi_OutLinks,            /* list of output links */
                        mi_InLinks;             /* list of input links */

    struct Task         *mi_SigTask;            /* task to signal */
    struct Hook         *mi_ReceiveHook,        /* hook (and list node) */
                        *mi_ParticipantHook;    /* hook for participant change */
    int8                mi_ReceiveSigBit,       /* signalmask for new data */
                        mi_ParticipantSigBit;   /* signalmask for part change */
    uint8               mi_ErrFilter;           /* CMEF_ error filter for ErrFlags */
    uint8               mi_Alignment[1];        /* for longword alignment */

    uint32              *mi_TimeStamp;          /* where timestamps come from */

    uint32              mi_MsgQueueSize,        /* size of buffers */
                        mi_SysExQueueSize;

    /* private stuff below here */
};

/**********************************************************************************************/

struct MidiPortData
{
    void (*ActivateXmit)(); /* function to activate transmitter interrupt when idle */
};

/**********************************************************************************************/

struct MidiPrefs
{
    uint8 NUnits;
    uint8 pad0[3];
    struct MidiUnitDef UnitDef[1];
};

/**********************************************************************************************/

struct MidiUnitDef
{
    uint8 MidiDeviceName[32];	/* Name of MIDI device driver for this Unit (ignored for MUDF_Internal) */
    uint8 MidiClusterInName[32];/* Name of Cluster for input from MIDI device driver */
    uint8 MidiClusterOutName[32];/* Name of Cluster for output to MIDI device driver */
    uint8 MidiDeviceComment[34]; /* Comment field */
    uint8 MidiDevicePort;	/* MIDI device driver port number for this Unit */
    uint8 Flags;
    uint32 XmitQueueSize;
    uint32 RecvQueueSize;
    uint32 Reserved[4];
};

/**********************************************************************************************/

struct MiscIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct MiscIFace *Self);
	ULONG APICALL (*Release)(struct MiscIFace *Self);
	void APICALL (*Expunge)(struct MiscIFace *Self);
	struct Interface * APICALL (*Clone)(struct MiscIFace *Self);
	CONST_STRPTR APICALL (*AllocMiscResource)(struct MiscIFace *Self, ULONG unitNum, CONST_STRPTR name);
	VOID APICALL (*FreeMiscResource)(struct MiscIFace *Self, ULONG unitNum);
};

/**********************************************************************************************/

struct MMUIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct MMUIFace *Self);
	ULONG APICALL (*Release)(struct MMUIFace *Self);
	void APICALL (*Expunge)(struct MMUIFace *Self);
	struct Interface * APICALL (*Clone)(struct MMUIFace *Self);
	BOOL APICALL (*MapMemory)(struct MMUIFace *Self, APTR virtualAddress, APTR phyiscal, ULONG length, ULONG attrib);
	void APICALL (*UnmapMemory)(struct MMUIFace *Self, APTR virtualAddress, ULONG length);
	void APICALL (*RemapMemory)(struct MMUIFace *Self, APTR virtualAddress, APTR phyiscal, ULONG length, ULONG attrib);
	void APICALL (*SetMemoryAttrs)(struct MMUIFace *Self, APTR virtualAddress, ULONG length, ULONG attrib);
	ULONG APICALL (*GetMemoryAttrs)(struct MMUIFace *Self, APTR virtualAddress, ULONG flags);
	APTR APICALL (*GetPhysicalAddress)(struct MMUIFace *Self, APTR virtualAddress);
};

/**********************************************************************************************/

struct MultiAssign
{
    struct MultiAssign *ma_Next;         /* next multi-assign entry, or 0.  */
    BPTR                ma_Lock;
};

/**********************************************************************************************/

struct NIPCBuff
{
    struct MinNode nbuff_Link;
    struct MinList nbuff_Entries;

    /* Anything below here is NIPC Private! Do NOT touch */
};

/**********************************************************************************************/

struct NIPCBuffEntry
{
    struct MinNode  nbe_Link;
    ULONG           nbe_Offset;
    ULONG           nbe_Length;
    ULONG           nbe_PhysicalLength;
    UBYTE          *nbe_Data;

    /* Anything below here is NIPC Private! Do NOT touch */
};

/**********************************************************************************************/

struct NotifyHookMsg
{
    int32   nhm_Size;        /* Size of data structure */
    int32   nhm_Action;      /* What happened (see below) */
    STRPTR  nhm_Name;        /* The name of the object */
};

/**********************************************************************************************/

struct NSDeviceQueryResult
{
    /*
    ** Standard information, must be reset for every query
    */
    ULONG   DevQueryFormat;         /* this is type 0 */
    ULONG   SizeAvailable;          /* bytes available */

    /*
    ** Common information (READ ONLY!)
    */
    UWORD   DeviceType;             /* what the device does */
    UWORD   DeviceSubType;          /* depends on the main type */
    UWORD * SupportedCommands;      /* 0 terminated list of cmd's */

    /* May be extended in the future! Check SizeAvailable! */
};

/**********************************************************************************************/

struct NVIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct NVIFace *Self);
	uint32 APICALL (*Release)(struct NVIFace *Self);
	void APICALL (*Expunge)(struct NVIFace *Self);
	struct Interface * APICALL (*Clone)(struct NVIFace *Self);
	APTR APICALL (*GetCopyNV)(struct NVIFace *Self, CONST_STRPTR appName, CONST_STRPTR itemName, BOOL killRequesters);
	VOID APICALL (*FreeNVData)(struct NVIFace *Self, APTR data);
	UWORD APICALL (*StoreNV)(struct NVIFace *Self, CONST_STRPTR appName, CONST_STRPTR itemName, const APTR data, ULONG length, BOOL killRequesters);
	BOOL APICALL (*DeleteNV)(struct NVIFace *Self, CONST_STRPTR appName, CONST_STRPTR itemName, BOOL killRequesters);
	struct NVInfo * APICALL (*GetNVInfo)(struct NVIFace *Self, BOOL killRequesters);
	struct MinList * APICALL (*GetNVList)(struct NVIFace *Self, CONST_STRPTR appName, BOOL killRequesters);
	BOOL APICALL (*SetNVProtection)(struct NVIFace *Self, CONST_STRPTR appName, CONST_STRPTR itemName, LONG mask, BOOL killRequesters);
	ULONG APICALL (*SetUBootVar)(struct NVIFace *Self, CONST_STRPTR name, CONST_STRPTR value);
	CONST_STRPTR APICALL (*GetUBootVar)(struct NVIFace *Self, CONST_STRPTR name);
	void APICALL (*FreeUBootVar)(struct NVIFace *Self, CONST_STRPTR value);
};

/**********************************************************************************************/

struct OpenFirmwareIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct OpenFirmwareIFace *Self);
	ULONG APICALL (*Release)(struct OpenFirmwareIFace *Self);
	void APICALL (*Expunge)(struct OpenFirmwareIFace *Self);
	struct Interface * APICALL (*Clone)(struct OpenFirmwareIFace *Self);
	uint32 APICALL (*CallRTAS)(struct OpenFirmwareIFace *Self, uint32 * packet);
	uint32 APICALL (*GetRTASService)(struct OpenFirmwareIFace *Self, CONST_STRPTR serviceName);
	OFNode APICALL (*Root)(struct OpenFirmwareIFace *Self);
	OFNode APICALL (*Peer)(struct OpenFirmwareIFace *Self, OFNode node);
	OFNode APICALL (*Child)(struct OpenFirmwareIFace *Self, OFNode node);
	OFNode APICALL (*Parent)(struct OpenFirmwareIFace *Self, OFNode node);
	OFProperty APICALL (*FindProp)(struct OpenFirmwareIFace *Self, OFNode node, CONST_STRPTR propname);
	OFProperty APICALL (*FirstProp)(struct OpenFirmwareIFace *Self, OFNode node);
	OFProperty APICALL (*NextProp)(struct OpenFirmwareIFace *Self, OFNode node, OFProperty property);
	uint32 APICALL (*GetPropName)(struct OpenFirmwareIFace *Self, OFProperty property, STRPTR buffer, uint32 bufSize);
	uint32 APICALL (*PropDataSize)(struct OpenFirmwareIFace *Self, OFProperty property);
	uint32 APICALL (*GetPropData)(struct OpenFirmwareIFace *Self, OFProperty property, APTR buffer, uint32 bufSize);
	uint32 APICALL (*GetNumAddressCells)(struct OpenFirmwareIFace *Self, OFNode node);
	uint32 APICALL (*GetNumSizeCells)(struct OpenFirmwareIFace *Self, OFNode node);
	OFNode APICALL (*FindNodeByStrProp)(struct OpenFirmwareIFace *Self, OFNode searchFrom, CONST_STRPTR propName, CONST_STRPTR propVal, BOOL caseIsSignificant);
	OFNode APICALL (*FindNodeByName)(struct OpenFirmwareIFace *Self, OFNode searchFrom, CONST_STRPTR name);
	OFNode APICALL (*FindNodeByDeviceType)(struct OpenFirmwareIFace *Self, OFNode searchFrom, CONST_STRPTR device);
	OFNode APICALL (*FindCompatibleNode)(struct OpenFirmwareIFace *Self, OFNode searchFrom, CONST_STRPTR compat);
	OFNode APICALL (*FindNodeByPath)(struct OpenFirmwareIFace *Self, CONST_STRPTR path);
	uint32 APICALL (*GetPropDataLong)(struct OpenFirmwareIFace *Self, OFNode node, CONST_STRPTR propName, uint32 index, uint32 defaultVal);
};

/**********************************************************************************************/

struct OutlineFont
{
    STRPTR               olf_OTagPath;    /* full path & name of the .otag file */
    struct TagItem      *olf_OTagList;    /* relocated .otag file in memory     */
    STRPTR               olf_EngineName;  /* OT_Engine name                     */
    STRPTR               olf_LibraryName; /* OT_Engine name + ".library"        */
    struct EGlyphEngine  olf_EEngine;     /* All NULL if OFF_OPEN not specified */
    APTR                 olf_Reserved;    /* for future expansion               */
    APTR                 olf_UserData;    /* for private use                    */
};

/**********************************************************************************************/

struct OverlayHunk
{
   BPTR   ov_NextSeg;        /* BPTR to the next segment.                    */
   uint32 ov_BRA;            /* Usually a 68K branch instruction to ov_User  */
   uint32 ov_Ident;          /* Identifier value; 0xABCD                     */
   BPTR   ov_Handle;         /* The open filehandle, must close it on unload.*/
   APTR   ov_OverlayTable;   /* APTR pointer to the overlay table.           */
   BPTR   ov_HunkTable;      /* A BPTR to the hunk table.                    */
   int32  ov_GlobVec;        /* Was the BCPL global vector, now -1 as of V50 */
   APTR   ov_User;           /* Actual start of user space, and following... */
};

/**********************************************************************************************/

struct P96IFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct P96IFace *Self);
	ULONG APICALL (*Release)(struct P96IFace *Self);
	void APICALL (*Expunge)(struct P96IFace *Self);
	struct Interface * APICALL (*Clone)(struct P96IFace *Self);
	struct BitMap * APICALL (*p96AllocBitMap)(struct P96IFace *Self, ULONG SizeX, ULONG SizeY, ULONG Depth, ULONG Flags, struct BitMap * friendBitMap, RGBFTYPE RGBFormat);
	void APICALL (*p96FreeBitMap)(struct P96IFace *Self, struct BitMap * bitMap);
	ULONG APICALL (*p96GetBitMapAttr)(struct P96IFace *Self, struct BitMap * bitMap, ULONG Attribute);
	LONG APICALL (*p96LockBitMap)(struct P96IFace *Self, struct BitMap * bitMap, UBYTE * Buffer, ULONG Size);
	void APICALL (*p96UnlockBitMap)(struct P96IFace *Self, struct BitMap * bitMap, LONG Lock);
	ULONG APICALL (*p96BestModeIDTagList)(struct P96IFace *Self, struct TagItem * Tags);
	ULONG APICALL (*p96BestModeIDTags)(struct P96IFace *Self, ...);
	ULONG APICALL (*p96RequestModeIDTagList)(struct P96IFace *Self, struct TagItem * Tags);
	ULONG APICALL (*p96RequestModeIDTags)(struct P96IFace *Self, ...);
	struct List * APICALL (*p96AllocModeListTagList)(struct P96IFace *Self, struct TagItem * Tags);
	struct List * APICALL (*p96AllocModeListTags)(struct P96IFace *Self, ...);
	void APICALL (*p96FreeModeList)(struct P96IFace *Self, struct List * list);
	ULONG APICALL (*p96GetModeIDAttr)(struct P96IFace *Self, ULONG Mode, ULONG Attribute);
	struct Screen * APICALL (*p96OpenScreenTagList)(struct P96IFace *Self, struct TagItem * Tags);
	struct Screen * APICALL (*p96OpenScreenTags)(struct P96IFace *Self, ...);
	BOOL APICALL (*p96CloseScreen)(struct P96IFace *Self, struct Screen * screen);
	void APICALL (*p96WritePixelArray)(struct P96IFace *Self, struct RenderInfo * ri, UWORD SrcX, UWORD SrcY, struct RastPort * rp, UWORD DestX, UWORD DestY, UWORD SizeX, UWORD SizeY);
	void APICALL (*p96ReadPixelArray)(struct P96IFace *Self, struct RenderInfo * ri, UWORD DestX, UWORD DestY, struct RastPort * rp, UWORD SrcX, UWORD SrcY, UWORD SizeX, UWORD SizeY);
	ULONG APICALL (*p96WritePixel)(struct P96IFace *Self, struct RastPort * rp, UWORD x, UWORD y, ULONG color);
	ULONG APICALL (*p96ReadPixel)(struct P96IFace *Self, struct RastPort * rp, UWORD x, UWORD y);
	void APICALL (*p96RectFill)(struct P96IFace *Self, struct RastPort * rp, UWORD MinX, UWORD MinY, UWORD MaxX, UWORD MaxY, ULONG color);
	void APICALL (*p96WriteTrueColorData)(struct P96IFace *Self, struct TrueColorInfo * tci, UWORD SrcX, UWORD SrcY, struct RastPort * rp, UWORD DestX, UWORD DestY, UWORD SizeX, UWORD SizeY);
	void APICALL (*p96ReadTrueColorData)(struct P96IFace *Self, struct TrueColorInfo * tci, UWORD DestX, UWORD DestY, struct RastPort * rp, UWORD SrcX, UWORD SrcY, UWORD SizeX, UWORD SizeY);
	struct Window * APICALL (*p96PIP_OpenTagList)(struct P96IFace *Self, struct TagItem * Tags);
	struct Window * APICALL (*p96PIP_OpenTags)(struct P96IFace *Self, ...);
	BOOL APICALL (*p96PIP_Close)(struct P96IFace *Self, struct Window * window);
	LONG APICALL (*p96PIP_SetTagList)(struct P96IFace *Self, struct Window * window, struct TagItem * Tags);
	LONG APICALL (*p96PIP_SetTags)(struct P96IFace *Self, struct Window * window, ...);
	LONG APICALL (*p96PIP_GetTagList)(struct P96IFace *Self, struct Window * window, struct TagItem * Tags);
	LONG APICALL (*p96PIP_GetTags)(struct P96IFace *Self, struct Window * window, ...);
	struct IntuiMessage * APICALL (*p96PIP_GetIMsg)(struct P96IFace *Self, struct MsgPort * port);
	void APICALL (*p96PIP_ReplyIMsg)(struct P96IFace *Self, struct IntuiMessage * intuiMessage);
	LONG APICALL (*p96GetRTGDataTagList)(struct P96IFace *Self, struct TagItem * Tags);
	LONG APICALL (*p96GetRTGDataTags)(struct P96IFace *Self, ...);
	LONG APICALL (*p96GetBoardDataTagList)(struct P96IFace *Self, ULONG board, struct TagItem * Tags);
	LONG APICALL (*p96GetBoardDataTags)(struct P96IFace *Self, ULONG board, ...);
	ULONG APICALL (*p96EncodeColor)(struct P96IFace *Self, RGBFTYPE RGBFormat, ULONG Color);
	BOOL APICALL (*p96LockBitMapToBoard)(struct P96IFace *Self, struct BitMap * bm, ULONG board_number, UBYTE * buf, ULONG size);
	void APICALL (*p96UnlockBitMapFromBoard)(struct P96IFace *Self, struct BitMap * bm, BOOL modified);
};

/**********************************************************************************************/

struct P96Mode
{
	struct Node	Node;
	char			Description[MODENAMELENGTH];
	UWORD			Width;
	UWORD			Height;
	UWORD			Depth;
	ULONG			DisplayID;
};

/**********************************************************************************************/

struct PaletteIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PaletteIFace *Self);
	ULONG APICALL (*Release)(struct PaletteIFace *Self);
	void APICALL (*Expunge)(struct PaletteIFace *Self);
	struct Interface * APICALL (*Clone)(struct PaletteIFace *Self);
	Class * APICALL (*PALETTE_GetClass)(struct PaletteIFace *Self);
};

/**********************************************************************************************/

struct PartitionIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PartitionIFace *Self);
	ULONG APICALL (*Release)(struct PartitionIFace *Self);
	void APICALL (*Expunge)(struct PartitionIFace *Self);
	struct Interface * APICALL (*Clone)(struct PartitionIFace *Self);
	Class * APICALL (*PARTITION_GetClass)(struct PartitionIFace *Self);
	struct Node * APICALL (*AllocPartitionNodeA)(struct PartitionIFace *Self, struct TagItem * last);
	struct Node * APICALL (*AllocPartitionNode)(struct PartitionIFace *Self, ...);
	void APICALL (*FreePartitionNode)(struct PartitionIFace *Self, struct Node * last);
	void APICALL (*SetPartitionNodeAttrsA)(struct PartitionIFace *Self, struct Node * par1, struct TagItem * last);
	void APICALL (*SetPartitionNodeAttrs)(struct PartitionIFace *Self, struct Node * par1, ...);
	void APICALL (*GetPartitionNodeAttrsA)(struct PartitionIFace *Self, struct Node * par1, struct TagItem * last);
	void APICALL (*GetPartitionNodeAttrs)(struct PartitionIFace *Self, struct Node * par1, ...);
};

/**********************************************************************************************/

struct PathNode
{
    BPTR pn_Next;    /* Pointer to next path node */
    BPTR pn_Lock;    /* Directory lock */
};

/**********************************************************************************************/

struct PBoxDrawMsg
{
    ULONG             pbdm_MethodID;  /* PB_DRAW */
    struct RastPort * pbdm_RastPort;  /* Where to render to */
    struct DrawInfo * pbdm_DrawInfo;  /* Useful to have around */
    struct Rectangle  pbdm_Bounds;    /* Limits of where to render */
    ULONG             pbdm_State;     /* How to render */
    ULONG             pbdm_Color;     /* Color index in palette */
    struct Gadget *   pbdm_Gadget;    /* The palette gadget */
};

/**********************************************************************************************/

struct PCIDevice
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PCIDevice *Self);
	ULONG APICALL (*Release)(struct PCIDevice *Self);
	void APICALL (*Expunge)(struct PCIDevice *Self);
	struct Interface * APICALL (*Clone)(struct PCIDevice *Self);
	UBYTE APICALL (*ReadConfigByte)(struct PCIDevice *Self, ULONG Offset);
	UWORD APICALL (*ReadConfigWord)(struct PCIDevice *Self, ULONG Offset);
	ULONG APICALL (*ReadConfigLong)(struct PCIDevice *Self, ULONG Offset);
	void APICALL (*WriteConfigByte)(struct PCIDevice *Self, ULONG Offset, UBYTE Value);
	void APICALL (*WriteConfigWord)(struct PCIDevice *Self, ULONG Offset, UWORD Value);
	void APICALL (*WriteConfigLong)(struct PCIDevice *Self, ULONG Offset, ULONG Value);
	UBYTE APICALL (*InByte)(struct PCIDevice *Self, ULONG Port);
	UWORD APICALL (*InWord)(struct PCIDevice *Self, ULONG Port);
	ULONG APICALL (*InLong)(struct PCIDevice *Self, ULONG Port);
	void APICALL (*OutByte)(struct PCIDevice *Self, ULONG Port, UBYTE Value);
	void APICALL (*OutWord)(struct PCIDevice *Self, ULONG Port, UWORD Value);
	void APICALL (*OutLong)(struct PCIDevice *Self, ULONG Port, ULONG Value);
	struct PCIResourceRange * APICALL (*GetResourceRange)(struct PCIDevice *Self, UBYTE BaseNum);
	void APICALL (*FreeResourceRange)(struct PCIDevice *Self, struct PCIResourceRange * ResourceRange);
	ULONG APICALL (*GetCapabilities)(struct PCIDevice *Self);
	ULONG APICALL (*SetCapabilities)(struct PCIDevice *Self, ULONG Flags);
	void APICALL (*SetHALData)(struct PCIDevice *Self, APTR HALData);
	APTR APICALL (*GetHALData)(struct PCIDevice *Self);
	void APICALL (*SetResourceRange)(struct PCIDevice *Self, UBYTE BaseNum, struct PCIResourceRange * Range);
	struct Node * APICALL (*GetNode)(struct PCIDevice *Self);
	void APICALL (*SetAddress)(struct PCIDevice *Self, UBYTE Bus, UBYTE Dev, UBYTE Fn);
	void APICALL (*GetAddress)(struct PCIDevice *Self, UBYTE * Bus, UBYTE * Dev, UBYTE * Fn);
	BOOL APICALL (*Autoconfig)(struct PCIDevice *Self);
	APTR APICALL (*GetUserData)(struct PCIDevice *Self, UBYTE ItemNum);
	void APICALL (*SetUserData)(struct PCIDevice *Self, UBYTE ItemNum, APTR UserData);
	BOOL APICALL (*Lock)(struct PCIDevice *Self, UBYTE Mode);
	void APICALL (*Unlock)(struct PCIDevice *Self);
	ULONG APICALL (*MapInterrupt)(struct PCIDevice *Self);
	void APICALL (*SetEndian)(struct PCIDevice *Self, uint32 Mode);
	void APICALL (*InByteBlock)(struct PCIDevice *Self, uint32 Port, uint8 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	void APICALL (*InWordBlock)(struct PCIDevice *Self, uint32 Port, uint16 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	void APICALL (*InLongBlock)(struct PCIDevice *Self, uint32 Port, uint32 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	void APICALL (*OutByteBlock)(struct PCIDevice *Self, uint32 Port, uint8 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	void APICALL (*OutWordBlock)(struct PCIDevice *Self, uint32 Port, uint16 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
	void APICALL (*OutLongBlock)(struct PCIDevice *Self, uint32 Port, uint32 * Block, uint32 PortInc, uint32 BlockInc, uint32 NumUnits);
};

/**********************************************************************************************/

struct PCIIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PCIIFace *Self);
	ULONG APICALL (*Release)(struct PCIIFace *Self);
	void APICALL (*Expunge)(struct PCIIFace *Self);
	struct Interface * APICALL (*Clone)(struct PCIIFace *Self);
	struct PCIDevice * APICALL (*FindDevice)(struct PCIIFace *Self, const struct TagItem * tagList);
	struct PCIDevice * APICALL (*FindDeviceTags)(struct PCIIFace *Self, ...);
	void APICALL (*FreeDevice)(struct PCIIFace *Self, struct PCIDevice * device);
	struct PCIResourceRange * APICALL (*AllocResource)(struct PCIIFace *Self, ULONG ResType, ULONG NumBytes);
	void APICALL (*FreeResource)(struct PCIIFace *Self, struct PCIResourceRange * Resource);
};

/**********************************************************************************************/

struct PCIResourceRange
{
    struct Node Node;        /* Node for chaining. ln_Name */
                             /* contains the name of the range */

    ULONG       BaseAddress; /* Base address of resource range */
    ULONG       Size;        /* Size of the base */

    ULONG       Physical;    /* Physical base address of the range. */

    ULONG       Flags;       /* Flags. See below */
};

/**********************************************************************************************/

struct PenMapIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PenMapIFace *Self);
	ULONG APICALL (*Release)(struct PenMapIFace *Self);
	void APICALL (*Expunge)(struct PenMapIFace *Self);
	struct Interface * APICALL (*Clone)(struct PenMapIFace *Self);
	Class * APICALL (*PENMAP_GetClass)(struct PenMapIFace *Self);
};

/**********************************************************************************************/

struct PerformanceMonitorIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PerformanceMonitorIFace *Self);
	ULONG APICALL (*Release)(struct PerformanceMonitorIFace *Self);
	void APICALL (*Expunge)(struct PerformanceMonitorIFace *Self);
	struct Interface * APICALL (*Clone)(struct PerformanceMonitorIFace *Self);

	uint32 APICALL (*CounterGet)(struct PerformanceMonitorIFace *Self, uint32 whatCount);
	uint32 APICALL (*CounterMatch)(struct PerformanceMonitorIFace *Self, uint32 itemNum);
	BOOL APICALL (*CounterControl)(struct PerformanceMonitorIFace *Self, uint32 whichCount, int32 value, uint32 what);

	uint32 APICALL (*EventControl)(struct PerformanceMonitorIFace *Self, struct TagItem *tagList);
	uint32 APICALL (*EventControlTags)(struct PerformanceMonitorIFace *Self,  ...);
	struct Interrupt * APICALL (*SetInterruptVector)(struct PerformanceMonitorIFace *Self, uint32 event, struct Interrupt *handler);

	void APICALL (*Mark)(struct PerformanceMonitorIFace *Self, struct Task *task);
	void APICALL (*Unmark)(struct PerformanceMonitorIFace *Self, struct Task *task);

	uint32 APICALL (*MonitorControl)(struct PerformanceMonitorIFace *Self, struct TagItem *tagList);
	uint32 APICALL (*MonitorControlTags)(struct PerformanceMonitorIFace *Self, ...);
	uint32 APICALL (*Query)(struct PerformanceMonitorIFace *Self, uint32 item);

	void APICALL (*SetSampledAddress)(struct PerformanceMonitorIFace *Self, APTR addr);
	APTR APICALL (*GetSampledAddress)(struct PerformanceMonitorIFace *Self);
	void APICALL (*SetBreakpoint)(struct PerformanceMonitorIFace *Self, uint32 type, APTR instAddr, uint32 instMask, BOOL except);
};

/**********************************************************************************************/

struct pgpAddNode
{
   ULONG               MethodID;        /* PM_ADDNODE */
   struct GadgetInfo * pgpan_GInfo;     /* Required GadgetInfo pointer */
   struct TagItem    * pgpan_NodeAttrs; /* AllocPartitionNodeA() taglist */
};

/**********************************************************************************************/

struct pgpEditNode
{
   ULONG               MethodID;        /* PM_EDITNODE */
   struct GadgetInfo * pgpen_GInfo;     /* Required GadgetInfo pointer */
   struct Node *       pgpen_Node;      /* Modify this node */
   struct TagItem *    pgpen_NodeAttrs; /* SetPartitionNodeAttrsA() taglist */
};

/**********************************************************************************************/

struct pgpGetZoneBounds
{
   ULONG               MethodID;         /* PM_GETZONEBOUNDS */
   struct GadgetInfo * pgpgzb_GInfo;     /* Required GadgetInfo pointer */
   ULONG               pgpgzb_ZoneIndex; /* Zone to inquire about */
   ULONG *             pgpgzb_MinCyl;    /* Minimum usable cylinder */
   ULONG *             pgpgzb_MaxCyl;    /* Maximum usable cylinder */
   struct Rectangle *  pgpgzb_Bounds;    /* Bounds of the zone in pixels */
};

/**********************************************************************************************/

struct pgpGetZoneInfo
{
   ULONG               MethodID;         /* PM_GETZONEINFO */
   struct GadgetInfo * pgpgzi_GInfo;     /* Required GadgetInfo pointer */
   ULONG               pgpgzi_ZoneIndex; /* Zone to inquire about */
   ULONG *             pgpgzi_Start;     /* Start of the zone */
   ULONG *             pgpgzi_End;       /* End of the zone */
   ULONG *             pgpgzi_Type;      /* Zone type - see below */
   struct Node **      pgpgzi_Partition; /* NULL if empty space */
   struct IBox *       pgpgzi_ZoneBox;   /* Actual box of the zone */
};

/**********************************************************************************************/

struct pgpMakeNode
{
   ULONG               MethodID;        /* PM_MAKENODE */
   struct GadgetInfo * pgpmn_GInfo;     /* Required GadgetInfo pointer */
   ULONG               pgpmn_ZoneIndex; /* Zone to convert - must be a space! */
   struct TagItem *    pgpmn_NodeAttrs; /* AllocPartitionNodeA() taglist */
};

/**********************************************************************************************/

struct pgpRemNode
{
   ULONG               MethodID;    /* PM_REMNODE */
   struct GadgetInfo * pgprn_GInfo; /* Required GadgetInfo pointer */
   struct Node *       pgprn_Node;  /* Remove() this node */
};

/**********************************************************************************************/

struct PictureIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PictureIFace *Self);
	ULONG APICALL (*Release)(struct PictureIFace *Self);
	void APICALL (*Expunge)(struct PictureIFace *Self);
	struct Interface * APICALL (*Clone)(struct PictureIFace *Self);
	Class * APICALL (*PICTURE_GetClass)(struct PictureIFace *Self);
	VOID APICALL (*PICTURE_Private)(struct PictureIFace *Self);
};

/**********************************************************************************************/

struct PixieIFace
{
	struct InterfaceData Data;

	PixieField APICALL (*NewPixieFieldA)(struct PixieIFace *Self, CONST struct TagItem * tags);
	PixieField APICALL (*NewPixieField)(struct PixieIFace *Self, ...);
	VOID APICALL (*DisposePixieField)(struct PixieIFace *Self, PixieField pixief);
	BOOL APICALL (*SetupPixieFieldA)(struct PixieIFace *Self, PixieField pixief, struct RastPort * rp, CONST struct TagItem * tags);
	BOOL APICALL (*SetupPixieField)(struct PixieIFace *Self, PixieField pixief, struct RastPort * rp, ...);
	VOID APICALL (*CleanupPixieField)(struct PixieIFace *Self, PixieField pixief);
	VOID APICALL (*DrawPixieFieldA)(struct PixieIFace *Self, PixieField pixief, LONG x, LONG y, CONST struct TagItem * tags);
	VOID APICALL (*DrawPixieField)(struct PixieIFace *Self, PixieField pixief, LONG x, LONG y, ...);
	VOID APICALL (*UndrawPixieField)(struct PixieIFace *Self, PixieField pixief);
	Pixie APICALL (*NewPixieA)(struct PixieIFace *Self, CONST struct TagItem * tags);
	Pixie APICALL (*NewPixie)(struct PixieIFace *Self, ...);
	VOID APICALL (*DisposePixie)(struct PixieIFace *Self, Pixie pixie);
	BOOL APICALL (*AttachPixie)(struct PixieIFace *Self, Pixie pixie, PixieField pixief);
	VOID APICALL (*DetachPixie)(struct PixieIFace *Self, Pixie pixie);
	BOOL APICALL (*SetPixieAttrsA)(struct PixieIFace *Self, Pixie pixie, CONST struct TagItem * tags);
	BOOL APICALL (*SetPixieAttrs)(struct PixieIFace *Self, Pixie pixie, ...);
	VOID APICALL (*GetPixieAttrsA)(struct PixieIFace *Self, Pixie pixie, CONST struct TagItem * tags);
	VOID APICALL (*GetPixieAttrs)(struct PixieIFace *Self, Pixie pixie, ...);
};

/**********************************************************************************************/

struct PixieRenderMsg
{
    struct RastPort  *RastPort; /* where to render to        */
    struct Rectangle  Bounds;   /* limits of where to render */
    WORD              OffsetX;  /* horizontal offset         */
    WORD              OffsetY;  /* vertical offset           */

    APTR              Image;    /* PIXIE_Image/PIXIE_BitMap  */
    PLANEPTR          Mask;     /* PIXIE_Mask                */
};

/**********************************************************************************************/

struct pmChangeState
{
    ULONG MethodID;
    APTR  IDList;
    ULONG Action;
};

/**********************************************************************************************/

struct pmCheckAbort
{
    ULONG MethodID;
    APTR  Handle;
};

/**********************************************************************************************/

struct pmFindItem
{
    ULONG MethodID;
    ULONG ID;
};

/**********************************************************************************************/

struct pmHandleInput
{
    ULONG                MethodID;
    struct IntuiMessage *IMsg;
};

/**********************************************************************************************/

struct pmInsert
{
    ULONG   MethodID;
    Object *object;   /* "Object *Object;" caused problems with C++ */
    Object *Pred;
};

/**********************************************************************************************/

struct pmLayout
{
    ULONG           MethodID;
    struct Window  *Window;
    struct TagItem *AttrList; /* unused, set to NULL */
};

/**********************************************************************************************/

struct pmLocaleHookMsg
{
    ULONG LocaleID;
};

/**********************************************************************************************/

struct pmOpen
{
    ULONG          MethodID;
    struct Window *Window;
};

/**********************************************************************************************/

struct PNDrawMsg
{
    ULONG             pndm_MethodID;   /* PN_DRAW */
    struct RastPort  *pndm_RastPort;   /* Where to render to */
    struct DrawInfo  *pndm_DrawInfo;   /* Useful to have around */
    struct Rectangle  pndm_Bounds;     /* Limits of where to render */
    ULONG             pndm_State;      /* How to render */
};

/**********************************************************************************************/

struct PNQueryMsg
{
    ULONG             pnqm_MethodID;   /* PN_QUERY */
    struct RastPort  *pnqm_RastPort;   /* Where to render to */
    struct DrawInfo  *pnqm_DrawInfo;   /* Useful to have around */
    struct Rectangle  pnqm_Bounds;     /* Limits of where to render */
    ULONG             pnqm_State;      /* How to render */
    ULONG            *pnqm_AttrFlags;  /* Fill in with your properties */
};

/**********************************************************************************************/

struct PopupMenuIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PopupMenuIFace *Self);
	ULONG APICALL (*Release)(struct PopupMenuIFace *Self);
	void APICALL (*Expunge)(struct PopupMenuIFace *Self);
	struct Interface * APICALL (*Clone)(struct PopupMenuIFace *Self);
	Class * APICALL (*POPUPMENU_GetClass)(struct PopupMenuIFace *Self);
	Class * APICALL (*POPUPMENU_GetItemClass)(struct PopupMenuIFace *Self);
	APTR APICALL (*POPUPMENU_MakeMXListA)(struct PopupMenuIFace *Self, ULONG * ids);
	APTR APICALL (*POPUPMENU_MakeMXList)(struct PopupMenuIFace *Self, ...);
	VOID APICALL (*POPUPMENU_FreeIDList)(struct PopupMenuIFace *Self, APTR idlist);
	APTR APICALL (*POPUPMENU_MakeIDListA)(struct PopupMenuIFace *Self, struct TagItem * tags);
	APTR APICALL (*POPUPMENU_MakeIDList)(struct PopupMenuIFace *Self, ...);
};

/**********************************************************************************************/

struct PopupMenuPrefs
{
    UBYTE pmp_Flags;            /* Enable shadows, transparency, etc. */
    UBYTE pmp_SubMenuDelay;     /* Delay before opening submenus      */
    UBYTE pmp_Animation;        /* Animation, see below for defines   */
                                /* (Only one animation effect implemented currently) */
    UBYTE pmp_PulldownPos;      /* Where to show pulldownmenus        */
    BOOL  pmp_Sticky;           /* Use 'sticky' mode                  */
    BOOL  pmp_SameHeight;       /* Try to give all items same height  */
                                /* (not used currently)               */
    UBYTE pmp_MenuBorder;       /* Menu border                        */
    UBYTE pmp_SelItemBorder;    /* Border around selected item        */
    UBYTE pmp_SeparatorBar;     /* Separator bar style                */
    UBYTE pmp_MenuTitles;       /* Flags for drawing menu texts       */
    UBYTE pmp_MenuItems;        /* Flags for drawing menu item texts  */
    UBYTE pmp_XOffset;
    UBYTE pmp_YOffset;
    UBYTE pmp_XSpace;
    UBYTE pmp_YSpace;
    UBYTE pmp_Intermediate;
    BYTE  pmp_TextDisplace;
    BYTE  pmp_ShadowR;
    BYTE  pmp_ShadowG;
    BYTE  pmp_ShadowB;
    BYTE  pmp_TransparencyR;    /* not used currently      */
    BYTE  pmp_TransparencyG;    /* not used currently      */
    BYTE  pmp_TransparencyB;    /* not used currently      */
    UBYTE pmp_TransparencyBlur; /* not used currently      */
    UBYTE pmp_AnimationSpeed;   /* not used currently      */
    UBYTE pmp_IntArrow;         /* Use internal arrow image, instead of SYSICLASS one */
    UBYTE pmp_Reserved[15];     /* Reserved for future use */
};

/**********************************************************************************************/

struct PotgoIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct PotgoIFace *Self);
	ULONG APICALL (*Release)(struct PotgoIFace *Self);
	void APICALL (*Expunge)(struct PotgoIFace *Self);
	struct Interface * APICALL (*Clone)(struct PotgoIFace *Self);
	UWORD APICALL (*AllocPotBits)(struct PotgoIFace *Self, UWORD bits);
	VOID APICALL (*FreePotBits)(struct PotgoIFace *Self, UWORD bits);
	VOID APICALL (*WritePotgo)(struct PotgoIFace *Self, UWORD word, UWORD mask);
};

/**********************************************************************************************/

struct PrefsObjectsIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct PrefsObjectsIFace *Self);
	uint32 APICALL (*Release)(struct PrefsObjectsIFace *Self);
	void APICALL (*Expunge)(struct PrefsObjectsIFace *Self);
	struct Interface * APICALL (*Clone)(struct PrefsObjectsIFace *Self);
	uint32 APICALL (*BeginDeserialization)(struct PrefsObjectsIFace *Self, struct ALPOGetProcInfo * info);
	PrefsObject * APICALL (*PrefsBaseObjectA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsBaseObject)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsStringA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsString)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsNumberA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsNumber)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsDateA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsDate)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsBinaryA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsBinary)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsDictionaryA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsDictionary)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	PrefsObject * APICALL (*PrefsArrayA)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, struct TagItem * tags);
	PrefsObject * APICALL (*PrefsArray)(struct PrefsObjectsIFace *Self, PrefsObject * obj, uint32 * error, ...);
	BOOL APICALL (*DictSetObjectForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, PrefsObject * obj, CONST_STRPTR key);
	PrefsObject * APICALL (*DictGetObjectForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, CONST_STRPTR key);
	CONST_STRPTR APICALL (*DictGetStringForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, CONST_STRPTR key, CONST_STRPTR defStr);
	int32 APICALL (*DictGetIntegerForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, CONST_STRPTR key, int32 defInt);
	BOOL APICALL (*DictGetBoolForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, CONST_STRPTR key, BOOL defBool);
	int32 APICALL (*DictGetOptionForKey)(struct PrefsObjectsIFace *Self, PrefsObject * dict, CONST_STRPTR key, CONST_STRPTR * optionsTable, int32 defaultOption);
	uint32 APICALL (*ReadPrefsA)(struct PrefsObjectsIFace *Self, PrefsObject * dict, struct TagItem * tags);
	uint32 APICALL (*ReadPrefs)(struct PrefsObjectsIFace *Self, PrefsObject * dict, ...);
	uint32 APICALL (*WritePrefsA)(struct PrefsObjectsIFace *Self, PrefsObject * dict, struct TagItem * tags);
	uint32 APICALL (*WritePrefs)(struct PrefsObjectsIFace *Self, PrefsObject * dict, ...);
};

/**********************************************************************************************/

struct PRIVATE_ExamineDirContext
{
    uint32              StructSize;
    struct MinList      FreshNodeList;
    struct MinList      StaleNodeList;
    uint32              DataRequestFlags;
    struct Lock *       ReferenceLock;
    struct MsgPort *    MessagePort;
    APTR                MemoryPool;

    BPTR                DOSPrivateCD;
    BPTR                DOSPrivateLock;
    STRPTR              DOSPrivateName;
    int32               DOSPrivateResult2;
    APTR                DOSPrivateFallback;
    struct Hook *       DOSPrivateMatchFunc;
    STRPTR              DOSPrivateMatchString;

    APTR                FSPrivateMemPtr;
    uint32              FSPrivate[8];
};

/**********************************************************************************************/

struct PseudoSegList
{
    BPTR    ps_Next;       /* BPTR   - Pointer to next segment. Or 0.       */
    uint32  ps_Jump;       /* uint32 - Internal compatibility magic.        */
    APTR    ps_Entry;      /* APTR   - The function entry pointer.          */
    uint32  ps_Ikey;       /* uint32 - UnLoadSeg() Identification key.      */
    uint32  ps_DosPrivate; /* uint32 - DOS Private use only.                */
    uint32  ps_Reserved1;  /* uint32 - Block alignment - reserved.          */
    uint32  ps_Reserved2;  /* uint32 - Block alignment - reserved.          */
    uint8   ps_Data[4];    /* uint8  - First 4 bytes of data area.          */
};

/**********************************************************************************************/

struct radeon_dev_t
{
	struct Node Link;						//!< PRIVATE
	volatile uint32 *registers;				//!< Pointer to the Radeon's register array
	volatile uint32 *framebuffer_physical;	//!< Physical framebuffer address
	volatile uint32 *framebuffer;			//!< PCI Address of the framebuffer
};

/**********************************************************************************************/

struct RadeonCPRes
{
	struct Node Link;
	uint32 Version;

	radeon_dev 	(*open)				(char *busId);
	void 		(*close)			(radeon_dev dev);
	int 		(*wait_idle)		(radeon_dev dev);
	int 		(*lock)				(radeon_dev dev);
	void 		(*unlock)			(radeon_dev dev);
	void 		(*submit)			(radeon_dev dev, void *package, uint32 size);
	int 		(*getclass)			(radeon_dev dev);
	int 		(*getchip)			(radeon_dev dev);
	void* 		(*alloc_3d_state)	(radeon_dev dev);
	void 		(*free_3d_state)	(radeon_dev dev, void *state);
	void 		(*set_3d_state)		(radeon_dev dev, void *state);
	void 		(*submit_indirect)	(radeon_dev dev, void *package, uint32 size);

	/* New for version 2 of the structure */
	void		(*flush)			(radeon_dev dev); // Flush pending packages

};

/**********************************************************************************************/

struct RadioButtonIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct RadioButtonIFace *Self);
	ULONG APICALL (*Release)(struct RadioButtonIFace *Self);
	void APICALL (*Expunge)(struct RadioButtonIFace *Self);
	struct Interface * APICALL (*Clone)(struct RadioButtonIFace *Self);
	Class * APICALL (*RADIOBUTTON_GetClass)(struct RadioButtonIFace *Self);
	struct Node * APICALL (*AllocRadioButtonNodeA)(struct RadioButtonIFace *Self, UWORD columns, struct TagItem * tags);
	struct Node * APICALL (*AllocRadioButtonNode)(struct RadioButtonIFace *Self, UWORD columns, ...);
	VOID APICALL (*FreeRadioButtonNode)(struct RadioButtonIFace *Self, struct Node * node);
	VOID APICALL (*SetRadioButtonNodeAttrsA)(struct RadioButtonIFace *Self, struct Node * node, struct TagItem * tags);
	VOID APICALL (*SetRadioButtonNodeAttrs)(struct RadioButtonIFace *Self, struct Node * node, ...);
	VOID APICALL (*GetRadioButtonNodeAttrsA)(struct RadioButtonIFace *Self, struct Node * node, struct TagItem * tags);
	VOID APICALL (*GetRadioButtonNodeAttrs)(struct RadioButtonIFace *Self, struct Node * node, ...);
};

/**********************************************************************************************/

struct RamdriveIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct RamdriveIFace *Self);
	ULONG APICALL (*Release)(struct RamdriveIFace *Self);
	void APICALL (*Expunge)(struct RamdriveIFace *Self);
	struct Interface * APICALL (*Clone)(struct RamdriveIFace *Self);
	STRPTR APICALL (*KillRAD0)(struct RamdriveIFace *Self);
	STRPTR APICALL (*KillRAD)(struct RamdriveIFace *Self, ULONG unit);
};

/**********************************************************************************************/

struct RandomState
{
    LONG rs_High;
    LONG rs_Low;
};

/**********************************************************************************************/

struct RastPortExtra
{
    struct ExtendedNode     Node;         /* graphics extended node */
    struct RastPort        *RastPort;     /* backlink */
    ULONG                   Reserved[16]; /* avoid recompilation ;-) */
};

/**********************************************************************************************/

struct RealTimeIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct RealTimeIFace *Self);
	ULONG APICALL (*Release)(struct RealTimeIFace *Self);
	void APICALL (*Expunge)(struct RealTimeIFace *Self);
	struct Interface * APICALL (*Clone)(struct RealTimeIFace *Self);
	APTR APICALL (*LockRealTime)(struct RealTimeIFace *Self, ULONG lockType);
	VOID APICALL (*UnlockRealTime)(struct RealTimeIFace *Self, APTR lock);
	struct Player * APICALL (*CreatePlayerA)(struct RealTimeIFace *Self, const struct TagItem * tagList);
	struct Player * APICALL (*CreatePlayer)(struct RealTimeIFace *Self, ...);
	VOID APICALL (*DeletePlayer)(struct RealTimeIFace *Self, struct Player * player);
	BOOL APICALL (*SetPlayerAttrsA)(struct RealTimeIFace *Self, struct Player * player, const struct TagItem * tagList);
	BOOL APICALL (*SetPlayerAttrs)(struct RealTimeIFace *Self, struct Player * player, ...);
	LONG APICALL (*SetConductorState)(struct RealTimeIFace *Self, struct Player * player, ULONG state, LONG time);
	BOOL APICALL (*ExternalSync)(struct RealTimeIFace *Self, struct Player * player, LONG minTime, LONG maxTime);
	struct Conductor * APICALL (*NextConductor)(struct RealTimeIFace *Self, const struct Conductor * previousConductor);
	struct Conductor * APICALL (*FindConductor)(struct RealTimeIFace *Self, CONST_STRPTR name);
	ULONG APICALL (*GetPlayerAttrsA)(struct RealTimeIFace *Self, const struct Player * player, const struct TagItem * tagList);
	ULONG APICALL (*GetPlayerAttrs)(struct RealTimeIFace *Self, const struct Player * player, ...);
};

/**********************************************************************************************/

struct RecordLock32
{
    BPTR     rec_FH;         /* filehandle */
    uint32   rec_Offset;     /* 32 bit offset in file */
    uint32   rec_Length;     /* 32 bit length of file to be locked */
    uint32   rec_Mode;       /* Type of lock */
};

/**********************************************************************************************/

struct RenderInfo
{
	APTR			Memory;
	WORD			BytesPerRow;
	WORD			pad;
	RGBFTYPE		RGBFormat;
};

/**********************************************************************************************/

struct RenderMsg
{
    ULONG             rm_MethodID;   /* Type of rendering to perform */
    struct RastPort  *rm_RastPort;   /* Where to render to           */
    struct DrawInfo  *rm_DrawInfo;   /* Context information          */
    struct Rectangle  rm_Bounds;     /* Limits of where to render    */
    ULONG             rm_State;      /* How to render                */
    APTR              rm_IAddress;   /* Subsystem-specific data      */
    ULONG             rm_Flags;      /* Subsystem-specific flags     */
    struct TagItem   *rm_TagList;    /* Additional information       */
};

/**********************************************************************************************/

struct RequesterIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct RequesterIFace *Self);
	ULONG APICALL (*Release)(struct RequesterIFace *Self);
	void APICALL (*Expunge)(struct RequesterIFace *Self);
	struct Interface * APICALL (*Clone)(struct RequesterIFace *Self);
	Class * APICALL (*REQUESTER_GetClass)(struct RequesterIFace *Self);
};

/**********************************************************************************************/

struct ResourceIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ResourceIFace *Self);
	ULONG APICALL (*Release)(struct ResourceIFace *Self);
	void APICALL (*Expunge)(struct ResourceIFace *Self);
	struct Interface * APICALL (*Clone)(struct ResourceIFace *Self);
	RESOURCEFILE APICALL (*RL_OpenResource)(struct ResourceIFace *Self, APTR resource, struct Screen * screen, struct Catalog * catalog);
	VOID APICALL (*RL_CloseResource)(struct ResourceIFace *Self, RESOURCEFILE resfile);
	Object * APICALL (*RL_NewObjectA)(struct ResourceIFace *Self, RESOURCEFILE resfile, RESOURCEID resid, struct TagItem * tags);
	Object * APICALL (*RL_NewObject)(struct ResourceIFace *Self, RESOURCEFILE resfile, RESOURCEID resid, ...);
	VOID APICALL (*RL_DisposeObject)(struct ResourceIFace *Self, RESOURCEFILE resfile, Object * obj);
	Object ** APICALL (*RL_NewGroupA)(struct ResourceIFace *Self, RESOURCEFILE resfile, RESOURCEID id, struct TagItem * taglist);
	Object ** APICALL (*RL_NewGroup)(struct ResourceIFace *Self, RESOURCEFILE resfile, RESOURCEID id, ...);
	VOID APICALL (*RL_DisposeGroup)(struct ResourceIFace *Self, RESOURCEFILE resfile, Object ** obj);
	Object ** APICALL (*RL_GetObjectArray)(struct ResourceIFace *Self, RESOURCEFILE resfile, Object * obj, RESOURCEID id);
	BOOL APICALL (*RL_SetResourceScreen)(struct ResourceIFace *Self, RESOURCEFILE resfile, struct Screen * screen);
};

/**********************************************************************************************/

struct RexxSysIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct RexxSysIFace *Self);
	uint32 APICALL (*Release)(struct RexxSysIFace *Self);
	void APICALL (*Expunge)(struct RexxSysIFace *Self);
	struct Interface * APICALL (*Clone)(struct RexxSysIFace *Self);
	APTR Private1;
	APTR Private2;
	APTR Private3;
	APTR Private4;
	APTR Private5;
	APTR Private6;
	APTR Private7;
	APTR Private8;
	APTR Private9;
	APTR Private10;
	APTR Private11;
	APTR Private12;
	APTR Private13;
	APTR Private14;
	APTR Private15;
	APTR Private16;
	STRPTR APICALL (*CreateArgstring)(struct RexxSysIFace *Self, CONST_STRPTR string, ULONG length);
	VOID APICALL (*DeleteArgstring)(struct RexxSysIFace *Self, STRPTR argstring);
	LONG APICALL (*LengthArgstring)(struct RexxSysIFace *Self, CONST_STRPTR argstring);
	struct RexxMsg * APICALL (*CreateRexxMsg)(struct RexxSysIFace *Self, struct MsgPort * port, CONST_STRPTR extension, CONST_STRPTR host);
	VOID APICALL (*DeleteRexxMsg)(struct RexxSysIFace *Self, struct RexxMsg * packet);
	VOID APICALL (*ClearRexxMsg)(struct RexxSysIFace *Self, struct RexxMsg * msgptr, ULONG count);
	BOOL APICALL (*FillRexxMsg)(struct RexxSysIFace *Self, struct RexxMsg * msgptr, ULONG count, ULONG mask);
	BOOL APICALL (*IsRexxMsg)(struct RexxSysIFace *Self, struct RexxMsg * msgptr);
	APTR Private17;
	APTR Private18;
	APTR Private19;
	APTR Private20;
	APTR Private21;
	APTR Private22;
	APTR Private23;
	APTR Private24;
	APTR Private25;
	APTR Private26;
	APTR Private27;
	APTR Private28;
	APTR Private29;
	APTR Private30;
	APTR Private31;
	APTR Private32;
	APTR Private33;
	APTR Private34;
	APTR Private35;
	APTR Private36;
	APTR Private37;
	APTR Private38;
	APTR Private39;
	APTR Private40;
	APTR Private41;
	APTR Private42;
	APTR Private43;
	APTR Private44;
	APTR Private45;
	APTR Private46;
	APTR Private47;
	APTR Private48;
	APTR Private49;
	APTR Private50;
	APTR Private51;
	APTR Private52;
	APTR Private53;
	APTR Private54;
	APTR Private55;
	APTR Private56;
	APTR Private57;
	APTR Private58;
	APTR Private59;
	APTR Private60;
	APTR Private61;
	APTR Private62;
	VOID APICALL (*LockRexxBase)(struct RexxSysIFace *Self, ULONG resource);
	VOID APICALL (*UnlockRexxBase)(struct RexxSysIFace *Self, ULONG resource);
	APTR Private63;
	APTR Private64;
	APTR Private65;
	struct MsgPort * APICALL (*CreateRexxHostPort)(struct RexxSysIFace *Self, STRPTR base_name);
	VOID APICALL (*DeleteRexxHostPort)(struct RexxSysIFace *Self, struct MsgPort * port);
	LONG APICALL (*GetRexxVarFromMsg)(struct RexxSysIFace *Self, STRPTR name, STRPTR buffer, struct RexxMsg * message);
	LONG APICALL (*SetRexxVarFromMsg)(struct RexxSysIFace *Self, STRPTR name, STRPTR value, struct RexxMsg * message);
	struct RexxMsg * APICALL (*LaunchRexxScript)(struct RexxSysIFace *Self, STRPTR script_name, struct MsgPort * host_port, STRPTR extension, BPTR input_handle, BPTR output_handle);
	VOID APICALL (*FreeRexxMsg)(struct RexxSysIFace *Self, struct RexxMsg * message);
};

/**********************************************************************************************/

struct S2LogMessage
{
   LONG   s2lm_Size;
   ULONG  s2lm_Priority;
   STRPTR s2lm_Name;
   STRPTR s2lm_Message;
};

/**********************************************************************************************/

struct Sana2Connection
{
   ULONG          s2c_Size;
   struct MinList s2c_Options;
   struct Hook    s2c_ErrorHook;
   struct Hook    s2c_ConnectHook;
   struct Hook    s2c_DisconnectHook;
   STRPTR         s2c_Login;
   STRPTR         s2c_Password;
};

/**********************************************************************************************/

struct Sana2ConnectionMessage
{
   ULONG                    s2cm_Size;
   struct Sana2Connection * s2cm_Connection;
   struct IORequest *       s2cm_Request[2];
   LONG                     s2cm_RequestType;
};

/**********************************************************************************************/

struct Sana2ConnectionOption
{
   struct MinNode s2co_MinNode;
   STRPTR         s2co_Name;
   STRPTR         s2co_Value;
};

/**********************************************************************************************/

struct SANA2CopyHookMsg
{
    ULONG schm_Method;  /* S2_CopyToBuff, S2_CopyFromBuff, etc. */
    ULONG schm_MsgSize; /* Size of message (in bytes) */

    APTR  schm_To;      /* Data destination */
    APTR  schm_From;    /* Data source */
    ULONG schm_Size;    /* Number of bytes involved */
};

/**********************************************************************************************/

struct Sana2DeviceQuery
{
    /*
    ** Standard information
    */
    ULONG   SizeAvailable;  /* bytes available */
    ULONG   SizeSupplied;   /* bytes supplied */
    ULONG   DevQueryFormat; /* this is type 0 */
    ULONG   DeviceLevel;    /* this document is level 0 */
    /*
    ** Common information
    */
    UWORD   AddrFieldSize;  /* address size in bits */
    ULONG   MTU;            /* maximum packet data size */
    ULONG   BPS;            /* line rate (bits/sec) */
    ULONG   HardwareType;   /* what the wire is (see below) */
    ULONG   RawMTU;         /* maximum raw packet data size */
    /*
    ** Format specific information
    */
};

/**********************************************************************************************/

struct Sana2DeviceStats
{
    ULONG          PacketsReceived;      /* received count */
    ULONG          PacketsSent;          /* transmitted count */
    ULONG          BadData;              /* bad packets received */
    ULONG          Overruns;             /* hardware miss count */
    ULONG          Unused;               /* Unused field */
    ULONG          UnknownTypesReceived; /* orphan count */
    ULONG          Reconfigurations;     /* network reconfigurations */
    struct TimeVal LastStart;            /* time of last online */
};

/**********************************************************************************************/

struct Sana2ExtDeviceStats
{
    ULONG          s2xds_Length;
    ULONG          s2xds_Actual;

    S2QUAD         s2xds_PacketsReceived;
    S2QUAD         s2xds_PacketsSent;
    S2QUAD         s2xds_BadData;
    S2QUAD         s2xds_Overruns;
    S2QUAD         s2xds_UnknownTypesReceived;
    S2QUAD         s2xds_Reconfigurations;
    struct TimeVal s2xds_LastStart;

    struct TimeVal s2xds_LastConnected;
    struct TimeVal s2xds_LastDisconnected;
    struct TimeVal s2xds_TimeConnected;
};

/**********************************************************************************************/

struct Sana2Hook
{
   struct Hook s2h_Hook;    /* The hook to invoke */
   Tag *       s2h_Methods; /* Which methods the hook supports */
};

/**********************************************************************************************/

struct SANA2HookMsg
{
   ULONG shm_Method;  /* S2_CopyToBuff, S2_CopyFromBuff, etc. */
   ULONG shm_MsgSize; /* Size of message (in bytes) */
};

/**********************************************************************************************/

struct SANA2LogHookMsg
{
    ULONG  slhm_Method;   /* S2_Log */
    ULONG  slhm_MsgSize;  /* Size of message (in bytes) */

    ULONG  slhm_Priority; /* Severity (S2LOG_Emergency, etc.) */
    STRPTR slhm_Name;     /* Identifies the source of the message */
    STRPTR slhm_Message;  /* The log message itself */
};

/**********************************************************************************************/

struct Sana2PacketTypeStats
{
    ULONG PacketsSent;     /* transmitted count */
    ULONG PacketsReceived; /* received count */
    ULONG BytesSent;       /* bytes transmitted count */
    ULONG BytesReceived;   /* bytes received count */
    ULONG PacketsDropped;  /* packets dropped count */
};

/**********************************************************************************************/

struct Sana2SpecialStatHeader
{
    ULONG RecordCountMax;      /* room available */
    ULONG RecordCountSupplied; /* number supplied */
    /* struct Sana2SpecialStatRecord[RecordCountMax]; */
};

/**********************************************************************************************/

struct Sana2SpecialStatRecord
{
    ULONG  Type;   /* statistic identifier */
    ULONG  Count;  /* the statistic */
    STRPTR String; /* statistic name */
};

/**********************************************************************************************/

struct Sana2ThroughputStats
{
   ULONG          s2ts_Length;
   ULONG          s2ts_Actual;

   struct Task *  s2ts_NotifyTask;
   ULONG          s2ts_NotifyMask;

   struct TimeVal s2ts_StartTime;
   struct TimeVal s2ts_EndTime;
   S2QUAD         s2ts_BytesSent;
   S2QUAD         s2ts_BytesReceived;
   S2QUAD         s2ts_Updates;
};

/**********************************************************************************************/

struct sbSetNodeAttrs
{
    ULONG               MethodID;    /* SBM_SETNODEATTRS */
    struct GadgetInfo * sb_GInfo;
    struct Node *       sb_Node;     /* node whose attributes
                                        you are changing. */
    struct TagItem *    sb_AttrList; /* list of attributes to change. */
};

/**********************************************************************************************/

struct ScanVarsMsg
{
    uint32   sv_SVMSize;
    uint32   sv_Flags;
    STRPTR   sv_GDir;
    STRPTR   sv_Name;
    STRPTR   sv_Var;
    uint32   sv_VarLen;
	APTR     sv_DosPrivate;
};

/**********************************************************************************************/

struct ScreenBlankerIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct ScreenBlankerIFace *Self);
	uint32 APICALL (*Release)(struct ScreenBlankerIFace *Self);
	void APICALL (*Expunge)(struct ScreenBlankerIFace *Self);
	struct IScreenBlanker * APICALL (*Clone)(struct ScreenBlankerIFace *Self);
	BOOL APICALL (*OpenBlankerModuleA)(struct ScreenBlankerIFace *Self, CONST_STRPTR name, struct TagItem * tags);
	BOOL APICALL (*OpenBlankerModule)(struct ScreenBlankerIFace *Self, CONST_STRPTR name, ...);
	void APICALL (*CloseBlankerModule)(struct ScreenBlankerIFace *Self);
	BOOL APICALL (*SetBlankingMode)(struct ScreenBlankerIFace *Self, uint32 mode);
	BOOL APICALL (*SetScreenBlankerAttrsA)(struct ScreenBlankerIFace *Self, struct TagItem * tags);
	BOOL APICALL (*SetScreenBlankerAttrs)(struct ScreenBlankerIFace *Self, ...);
	BOOL APICALL (*GetScreenBlankerAttrsA)(struct ScreenBlankerIFace *Self, struct TagItem * tags);
	BOOL APICALL (*GetScreenBlankerAttrs)(struct ScreenBlankerIFace *Self, ...);
};

/**********************************************************************************************/

struct ScreenBlankerNotificationTask
{
	struct Task *task;
	uint32 signal;
};

/**********************************************************************************************/

struct ScreenDefinition
{
    ULONG           sd_Flags;            /* Screen specific flags      */
    TEXT            sd_ScreenName[128];  /* Screen public name         */
    TEXT            sd_ScreenTitle[128]; /* Screen title               */
    TEXT            sd_BaseName[32];     /* Screen database base name  */
    ULONG           sd_DisplayID;        /* Screen display mode        */
    UWORD           sd_Width;            /* Screen width               */
    UWORD           sd_Height;           /* Screen height              */
    UWORD           sd_Depth;            /* Screen depth               */
    UWORD           sd_Control;          /* Screen control flags       */
    struct TextAttr sd_Font;             /* Screen font attributes     */
    TEXT            sd_FontName[128];    /* Screen font name buffer    */
    ULONG           sd_Reserved[8];
    struct
    {
        UWORD Type;
        UWORD Flags;
    }               sd_Settings[4];      /* Screen settings attributes */
    ULONG           sd_Reserved2[16];
};

/**********************************************************************************************/

struct ScreenNotifyMessage
{
    struct Message snm_Message;     /* embedded message */
    ULONG          snm_Class;       /* see above */
    ULONG          snm_Code;
    APTR           snm_Object;      /* either a pointer to struct Window
                                     * or struct Screen (READ-ONLY).
                                     * For SNRF_#?PUBSCREEN this the
                                     * name of the public screen
                                     */
    APTR           snm_UserData;    /* SNA_UserData */
    APTR           snm_Request;     /* pointer returned by
                                     * StartScreenNotify()
                                     */
    ULONG          snm_Reserved[5]; /* don't touch! */
};

/**********************************************************************************************/

struct ScreensPrefs
{
    LONG  sp_Reserved[4]; /* System reserved                       */
    UWORD sp_Version;     /* Version of the ScreensPrefs structure */
    ULONG sp_GlobalFlags; /* Global screens flags                  */
};

/**********************************************************************************************/

struct ScrollerIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct ScrollerIFace *Self);
	ULONG APICALL (*Release)(struct ScrollerIFace *Self);
	void APICALL (*Expunge)(struct ScrollerIFace *Self);
	struct Interface * APICALL (*Clone)(struct ScrollerIFace *Self);
	Class * APICALL (*SCROLLER_GetClass)(struct ScrollerIFace *Self);
};

/**********************************************************************************************/

struct ScrollHook
{
    struct Hook sh_Hook;

    LONG        sh_Top;     /* This is the number of the first
                               visible item. */
    LONG        sh_Total;   /* This is the total number of items
                               available for display. */
    LONG        sh_Visible; /* This is how many entries can be
                               visible at a time. */
    LONG        sh_Size;    /* This is how many pixels high/wide
                               each item is. */
};

/**********************************************************************************************/

struct ScrollMsg
{
    ULONG sm_Action;    /* The action to perform */

    LONG  sm_NumItems;  /* Number of items to render */
    LONG  sm_NumPixels; /* Number of pixels to scroll */
    LONG  sm_TopItem;   /* The first visible item */
    LONG  sm_TopPixel;  /* The first visible pixel */
};

/**********************************************************************************************/

struct SearchCmdPathListMsg
{
    int32     splm_Size;
    BPTR      splm_Lock;
    STRPTR    splm_Name;
};

/**********************************************************************************************/

struct ShapeHookMsg
{
    ULONG             Action;
    struct Region    *NewShape;
    struct Region    *OldShape;
    struct Rectangle *NewBounds;
    struct Rectangle *OldBounds;
};

/**********************************************************************************************/

struct SizedBuffer
{
   APTR   SB_Buffer;
   uint32 SB_Size;
};

/**********************************************************************************************/

struct SketchBoardIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct SketchBoardIFace *Self);
	ULONG APICALL (*Release)(struct SketchBoardIFace *Self);
	void APICALL (*Expunge)(struct SketchBoardIFace *Self);
	struct Interface * APICALL (*Clone)(struct SketchBoardIFace *Self);
	Class * APICALL (*SKETCHBOARD_GetClass)(struct SketchBoardIFace *Self);
};

/**********************************************************************************************/

struct SkipList
{
    LONG sl_Error; /* If an insertion fails, here is why */
};

/**********************************************************************************************/

struct SkipNode
{
    APTR sn_Reserved;
    APTR sn_Key;      /* Unique key associated with this node */
};

/**********************************************************************************************/

struct SliderIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct SliderIFace *Self);
	ULONG APICALL (*Release)(struct SliderIFace *Self);
	void APICALL (*Expunge)(struct SliderIFace *Self);
	struct Interface * APICALL (*Clone)(struct SliderIFace *Self);
	Class * APICALL (*SLIDER_GetClass)(struct SliderIFace *Self);
};

/**********************************************************************************************/

struct SNMMessage
{
	STRPTR      Namespace;
	STRPTR      Name;
	APTR        Memory;
	uint32      Size;
	uint32      Flags;
};

/**********************************************************************************************/

struct SpaceIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct SpaceIFace *Self);
	ULONG APICALL (*Release)(struct SpaceIFace *Self);
	void APICALL (*Expunge)(struct SpaceIFace *Self);
	struct Interface * APICALL (*Clone)(struct SpaceIFace *Self);
	Class * APICALL (*SPACE_GetClass)(struct SpaceIFace *Self);
};

/**********************************************************************************************/

struct SpeedBarIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct SpeedBarIFace *Self);
	ULONG APICALL (*Release)(struct SpeedBarIFace *Self);
	void APICALL (*Expunge)(struct SpeedBarIFace *Self);
	struct Interface * APICALL (*Clone)(struct SpeedBarIFace *Self);
	Class * APICALL (*SPEEDBAR_GetClass)(struct SpeedBarIFace *Self);
	struct Node * APICALL (*AllocSpeedButtonNodeA)(struct SpeedBarIFace *Self, UWORD number, struct TagItem * tags);
	struct Node * APICALL (*AllocSpeedButtonNode)(struct SpeedBarIFace *Self, UWORD number, ...);
	VOID APICALL (*FreeSpeedButtonNode)(struct SpeedBarIFace *Self, struct Node * node);
	VOID APICALL (*SetSpeedButtonNodeAttrsA)(struct SpeedBarIFace *Self, struct Node * node, struct TagItem * tags);
	VOID APICALL (*SetSpeedButtonNodeAttrs)(struct SpeedBarIFace *Self, struct Node * node, ...);
	VOID APICALL (*GetSpeedButtonNodeAttrsA)(struct SpeedBarIFace *Self, struct Node * node, struct TagItem * tags);
	VOID APICALL (*GetSpeedButtonNodeAttrs)(struct SpeedBarIFace *Self, struct Node * node, ...);
};

/**********************************************************************************************/

struct spGeneral
{
    ULONG             MethodID; /* SGM_Undo, SGM_Clear, SGM_Redo */
    struct GadgetInfo GInfo;
};

/**********************************************************************************************/

struct SplayNode
{
    APTR sn_UserData; /* Points to user data area for this node */
};

/**********************************************************************************************/

struct SplayTree
{
    LONG st_Error; /* If an insertion fails, here is why */
};

/**********************************************************************************************/

struct spScrollRaster
{
    ULONG               MethodID; /* SGM_Scroll */
    struct GadgetInfo * GInfo;
    LONG                DeltaX;
    LONG                DeltaY;
};

/**********************************************************************************************/

struct StackFrameMsg
{
    uint32 StructSize;           // Size of the data structure
    uint32 State;                // State of the stack frame
    CONST_APTR MemoryAddress;    // Memory address being pointed to
    const uint32 *StackPointer;  // The stack pointer itself
};

/**********************************************************************************************/

struct StandardPacket64
{
    struct Message      sp_Msg;
    struct DosPacket64  sp_Pkt;
};

/**********************************************************************************************/

struct StringIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct StringIFace *Self);
	ULONG APICALL (*Release)(struct StringIFace *Self);
	void APICALL (*Expunge)(struct StringIFace *Self);
	struct Interface * APICALL (*Clone)(struct StringIFace *Self);
	Class * APICALL (*STRING_GetClass)(struct StringIFace *Self);
};

/**********************************************************************************************/

struct SubStyle
{
   CONST_STRPTR Name;      /* Name of the sub-style           */
   UWORD        Category;  /* Category it belongs to          */
   UWORD        ID;        /* Unique style ID for this plugin */
};

/**********************************************************************************************/

struct SymbolMsg
{
    Elf32_Sym *Sym;
    uint32     AbsValue;
    STRPTR     Name;
};

/**********************************************************************************************/

struct SysIPlugin
{
   struct Node        Node;          /* Reserved, don't use                  */
   ULONG              Version;       /* Version of the plugin                */
   ULONG              Type;          /* PLUGIN_SYSI                          */
   ULONG              Attrs;         /* Type-specific attributes (see below) */
   ULONG              Flags;         /* Additional information               */
   struct TagItem    *AttrList;      /* Optional list of GUI attributes      */
   ULONG              Reserved[4];   /* For future expansion                 */
   struct Hook       *RenderHook;    /* Optional rendering hook              */
   struct VectorInfo *VIArray;       /* Optional array of struct VectorInfo  */
   UWORD              Reserved1;     /* For future expansion                 */
   struct Hook       *GeometryHook;  /* Optional geometry hook (see below)   */
   struct SubStyle   *SubStyles;     /* Table of available sub-styles        */
   ULONG              Reserved2[4];  /* For future expansion                 */
};

/**********************************************************************************************/

struct TBGadgetData
{
   struct Gadget *DomainGadgetList;  /* Gadgets already attached to
                                      * window/screen
                                      * Note: this may be NULL
                                      */
   struct Gadget *GadgetGadgetList;  /* The gadget list containing the gadget
                                      * we receive as object
                                      * (this cannot be NULL)
                                      */
};

/**********************************************************************************************/

struct TextClipIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct TextClipIFace *Self);
	ULONG APICALL (*Release)(struct TextClipIFace *Self);
	void APICALL (*Expunge)(struct TextClipIFace *Self);
	struct Interface * APICALL (*Clone)(struct TextClipIFace *Self);
	LONG APICALL (*WriteClipVector)(struct TextClipIFace *Self, CONST_STRPTR vector, ULONG size);
	LONG APICALL (*ReadClipVector)(struct TextClipIFace *Self, STRPTR * bufptr, ULONG * sizptr);
	VOID APICALL (*DisposeClipVector)(struct TextClipIFace *Self, STRPTR vector);
};

/**********************************************************************************************/

struct TextEditorIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct TextEditorIFace *Self);
	ULONG APICALL (*Release)(struct TextEditorIFace *Self);
	void APICALL (*Expunge)(struct TextEditorIFace *Self);
	struct Interface * APICALL (*Clone)(struct TextEditorIFace *Self);
	Class * APICALL (*TEXTEDITOR_GetClass)(struct TextEditorIFace *Self);
};

/**********************************************************************************************/

struct TimePrefs
{
    ULONG            tp_Seconds;
    struct ClockData tp_ClockData;
    TEXT             tp_TimeServer[80];
    UWORD            tp_PortNumber;
    LONG             tp_UTCOffset;
};

/**********************************************************************************************/

struct TimeRequest
{
    struct IORequest Request;
    struct TimeVal   Time;
};

/**********************************************************************************************/

struct TimerIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct TimerIFace *Self);
	uint32 APICALL (*Release)(struct TimerIFace *Self);
	void APICALL (*Expunge)(struct TimerIFace *Self);
	struct Interface * APICALL (*Clone)(struct TimerIFace *Self);
	VOID APICALL (*AddTime)(struct TimerIFace *Self, struct TimeVal * dest, const struct TimeVal * src);
	VOID APICALL (*SubTime)(struct TimerIFace *Self, struct TimeVal * dest, const struct TimeVal * src);
	LONG APICALL (*CmpTime)(struct TimerIFace *Self, struct TimeVal * dest, const struct TimeVal * src);
	ULONG APICALL (*ReadEClock)(struct TimerIFace *Self, struct EClockVal * dest);
	VOID APICALL (*GetSysTime)(struct TimerIFace *Self, struct TimeVal * dest);
	VOID APICALL (*GetUpTime)(struct TimerIFace *Self, struct TimeVal * dest);
	VOID APICALL (*MicroDelay)(struct TimerIFace *Self, ULONG microseconds);
};

/**********************************************************************************************/

struct TimesyncIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct TimesyncIFace *Self);
	ULONG APICALL (*Release)(struct TimesyncIFace *Self);
	void APICALL (*Expunge)(struct TimesyncIFace *Self);
	struct Interface * APICALL (*Clone)(struct TimesyncIFace *Self);
	ULONG APICALL (*RemoteSyncA)(struct TimesyncIFace *Self, const struct TagItem * taglist);
	ULONG APICALL (*RemoteSync)(struct TimesyncIFace *Self, ...);
};

/**********************************************************************************************/

struct TimeVal
{
    uint32 Seconds;
    uint32 Microseconds;
};

/**********************************************************************************************/

struct TimezoneIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct TimezoneIFace *Self);
	uint32 APICALL (*Release)(struct TimezoneIFace *Self);
	void APICALL (*Expunge)(struct TimezoneIFace *Self);
	struct Interface * APICALL (*Clone)(struct TimezoneIFace *Self);
	uint32 APICALL (*GetTimezoneAttrsA)(struct TimezoneIFace *Self, APTR unused, const struct TagItem * taglist);
	uint32 APICALL (*GetTimezoneAttrs)(struct TimezoneIFace *Self, APTR unused, ...);
	BOOL APICALL (*ParseZone)(struct TimezoneIFace *Self, CONST_STRPTR zone);
	BOOL APICALL (*GetUTCTime)(struct TimezoneIFace *Self, struct TimeVal * dest);
	uint32 APICALL (*SetTimezoneAttrsA)(struct TimezoneIFace *Self, APTR unused, const struct TagItem * taglist);
	uint32 APICALL (*SetTimezoneAttrs)(struct TimezoneIFace *Self, APTR unused, ...);
};

/**********************************************************************************************/

struct TimezonePrefs
{
    uint16  tzp_Version;                     /* Version of TimezonePrefs structure  */
    uint16  tzp_Reserved;                    /* System reserved                     */
    uint32  tzp_Reserved0[3];                /* System reserved                     */
    uint32  tzp_CountryCode;                 /* 3-letter country code (ISO 3166-1)  */
    TEXT    tzp_TZ[MAX_ZONE_SIZE];           /* time zone string                    */
    TEXT    tzp_RuleName[MAX_ZONE_SIZE];     /* rule name                           */
    uint16  tzp_Flags;                       /* see below                           */
};

/**********************************************************************************************/

struct Trackable
{
    struct Hook        Destructor;
    APTR               Object;
    uint32             Flags;
    struct Trackable * HashChain;
    /* Long word aligned */
};

/**********************************************************************************************/

struct Transaction
{
   struct Message trans_Msg;            /* Messages are used as the carrier for local transactions */
   struct Entity *trans_SourceEntity;   /* Filled in by nipc.library */
   struct Entity *trans_DestinationEntity;
                                        /* Filled in by nipc.library */
   UBYTE          trans_Command;        /* A field that's server-proprietary */
   UBYTE          trans_Type;           /* Req, Response */
   ULONG          trans_Error;          /* any error values */
   ULONG          trans_Flags;          /* see below */
   ULONG          trans_Sequence;       /* Used by the library to maintain sequences (nipc internal) */
   APTR           trans_RequestData;    /* ptr to request data buffer */
   ULONG          trans_ReqDataLength;  /* The length of data in the above buffer */
   ULONG          trans_ReqDataActual;  /* The length of valid data in the request buffer */
   APTR           trans_ResponseData;   /* ptr to response data buffer */
   ULONG          trans_RespDataLength; /* The size of the buffer above */
   ULONG          trans_RespDataActual; /* When data is returned in a response, the amount of the buffer used */
   UWORD          trans_Timeout;        /* Number of seconds before a timeout */
   UWORD          trans_Reserved;       /* Reserved for future use */
   ULONG          trans_ClientPrivate;  /* Client specific user data field */
   ULONG          trans_ServerPrivate;  /* Server specific user data field */
};

/**********************************************************************************************/

struct TrueColorInfo
{
	ULONG	PixelDistance, BytesPerRow;
	UBYTE	*RedData, *GreenData, *BlueData;
};

/**********************************************************************************************/

struct USBBusCfgDsc
{
    struct USBBusDscHead    Head;

    UWORD   cd_TotalLength; // Total length of all descriptors returned with the Configuration
                            // descriptor (Configuration, interface, endpoints etc.)
    UBYTE   cd_NumInterfaces; // Number of interfaces supported by Configuration
    UBYTE   cd_ConfigID; // Value used for identifying this Configuration in a SetConfiguration() call
    UBYTE   cd_ConfigStr; // Index of string holding Configuration description
    UBYTE   cd_Attributes; // Attributes of Configuration (see flags below)
    UBYTE   cd_MaxPower; // Max power consumption (in 2mA unit counts) by device if using this Configuration (5 = 10mA consumed)
};

/**********************************************************************************************/

struct USBBusDevDsc
{
    struct USBBusDscHead    Head;

    UWORD   dd_USBVer; // USB Specification Version the device is compliant with (BCD)

    UBYTE   dd_Class; // Device class
    UBYTE   dd_Subclass; // Device subclass
    UBYTE   dd_Protocol; // Protocol used by device

    UBYTE   dd_MaxPacketSize0; // EndPoint Zero max packet size

    UWORD   dd_VendorID; // Device vendor's ID number
    UWORD   dd_Product; // Vendor's product code for device
    UWORD   dd_DevVer; // Device version (BCD)

    UBYTE   dd_ManufacturerStr; // Index of string holding manufacturer name
    UBYTE   dd_ProductStr; // Index of string holding product name/description
    UBYTE   dd_SerialStr; // Index of string holding serial number

    UBYTE   dd_NumConfigs; // Number of possible configurations this device supports
};

/**********************************************************************************************/

struct USBBusDscHead
{
    UBYTE   dh_Length; // Byte size of descriptor (including this header)
    UBYTE   dh_Type; // Type of descriptor following this header. One of the USBDESC_xxx constants.
};

/**********************************************************************************************/

struct USBBusEPDsc
{
    struct USBBusDscHead    Head;

    UBYTE   ed_Address; // EndPoint address in the USB device of the described EndPoint
    UBYTE   ed_Attributes; // EndPoint attributes (see defs. below)

    UWORD   ed_MaxPacketSize; // Maximum packet size supported by EndPoint
    UBYTE   ed_Interval; // Polling interval needed by EndPoint. Expressed in milliseconds.
};

/**********************************************************************************************/

struct USBBusHubDsc
{
    struct USBBusDscHead    Head; // Descriptor header

    UBYTE   hd_NumPorts; // Number of hub ports
    pack( UWORD   hd_Characteristics ); // Hub characteristics
    UBYTE   hd_PwrOn2PwrGood; // PwrOnToPwrGood time in 2ms intervals
    UBYTE   hd_HubCtrlCurrent; // Hub controller current req. in mA
    UBYTE   hd_DevRemovable[1]; // Bitmap indicating if ports contain detachable or
                                // non-detachable devices. One bit per port, rounded to bytes.
    // A USB1.0 compatibility PwrCtrlMask bitmask is also present, but unused.
};

/**********************************************************************************************/

struct USBBusHubPortStatus
{
    UWORD   Status;
    UWORD   Change;
};

/**********************************************************************************************/

struct USBBusHubStatus
{
    UWORD   Status;
    UWORD   Change;
};

/**********************************************************************************************/

struct USBBusIntDsc
{
    struct USBBusDscHead    Head;

    UBYTE   id_InterfaceID; // ID number of Interface descriptor
    UBYTE   id_AltSetting; // Value used for selecting alternate setting for Interface
    UBYTE   id_NumEndPoints; // Number of EndPoints (excluding EndPoint zero)

    UBYTE   id_Class; // Interface class code
    UBYTE   id_Subclass; // Interface subclass code
    UBYTE   id_Protocol; // Protocol used by Interface

    UBYTE   id_InterfaceStr; // Index of string describing the Interface
};

/**********************************************************************************************/

struct USBBusSetupData
{
    UBYTE   sd_RequestType; // Type of request (Direction, Type and Recipient information)
    UBYTE   sd_Request; // Request code
    UWORD   sd_Value; // Request value argument
    UWORD   sd_Index; // Request index argument
    UWORD   sd_Length; // Length of data to transfer in data stage
};

/**********************************************************************************************/

struct UsbEndPoint
{
	uint32	I_Am_Private;
};

/**********************************************************************************************/

struct USBFDIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct USBFDIFace *Self);
	uint32 APICALL (*Release)(struct USBFDIFace *Self);
	void APICALL (*Expunge)(struct USBFDIFace *Self);
	struct Interface * APICALL (*Clone)(struct USBFDIFace *Self);
	void APICALL (*USBFDGetAttrsA)(struct USBFDIFace *Self, struct TagItem * taglist);
	void APICALL (*USBFDGetAttrs)(struct USBFDIFace *Self, ...);
	int32 APICALL (*USBFDRunFunction)(struct USBFDIFace *Self, struct USBFDStartupMsg * startmsg);
	int32 APICALL (*USBFDRunInterface)(struct USBFDIFace *Self, struct USBFDStartupMsg * startmsg);
};

/**********************************************************************************************/

struct USBFDStartupMsg
{
    struct IORequest       *USBReq; /* Reference for already-opened "usbsys.device" (do NOT close the device after use!)
                                       The ReplyPort has been specifically created for this use. If the FD decides
                                       to handle the USB Function it may use the port at its own discretion - except
                                       deleting the port.
                                    */

    APTR                    Object; /* The USB objectto handle in the FD (USS reference).
                                       All FDs must allow this field to hold a NULL pointer.
                                       If this is the case the FD should return as if it didn't support the given
                                       USB object. That is, return USBERR_UNSUPPORTED.

                                       When the USS calls an FDs USBFDRunFunction() this field
                                        points to a struct UsbRawFunction.
                                       When the USS calls an FDs USBFDRunInterface() this field
                                        points to a struct UsbRawInterface.
                                     */
    struct USBBusDscHead   *Descriptor; /* Ptr to USB descriptor for the Object:
                                           For a UsbRawFunction this is a Function descriptor (struct USBBusDevDsc) ptr.
                                           For a UsbRawInterface this is an Interface descriptor (struct USBBusIntDsc) ptr
                                         */

};

/**********************************************************************************************/

struct UsbFunction
{
	uint32	I_Am_Private;
};

/**********************************************************************************************/

struct USBHCDIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct USBHCDIFace *Self);
	uint32 APICALL (*Release)(struct USBHCDIFace *Self);
	void APICALL (*Expunge)(struct USBHCDIFace *Self);
	struct Interface * APICALL (*Clone)(struct USBHCDIFace *Self);
	APTR APICALL (*USBHCAddFunctionA)(struct USBHCDIFace *Self, APTR hcunit, APTR hchub, APTR usfkt, struct TagItem * taglist);
	APTR APICALL (*USBHCAddFunction)(struct USBHCDIFace *Self, APTR hcunit, APTR hchub, APTR usfkt, ...);
	void APICALL (*USBHCRemFunction)(struct USBHCDIFace *Self, APTR hcunit, APTR hcfkt);
	APTR APICALL (*USBHCAddEndPointA)(struct USBHCDIFace *Self, APTR hcunit, APTR hcfkt, APTR usep, int32 epnum, struct TagItem * taglist);
	APTR APICALL (*USBHCAddEndPoint)(struct USBHCDIFace *Self, APTR hcunit, APTR hcfkt, APTR usep, int32 epnum, ...);
	void APICALL (*USBHCRemEndPoint)(struct USBHCDIFace *Self, APTR hcunit, APTR hcep);
	void APICALL (*USBHCGetAttrsA)(struct USBHCDIFace *Self, struct TagItem * taglist);
	void APICALL (*USBHCGetAttrs)(struct USBHCDIFace *Self, ...);
	int32 APICALL (*USBHCInitRootHubA)(struct USBHCDIFace *Self, APTR hcunit, struct UsbRawInterface * usifc, APTR * hcfkt, struct TagItem * taglist);
	int32 APICALL (*USBHCInitRootHub)(struct USBHCDIFace *Self, APTR hcunit, struct UsbRawInterface * usifc, APTR * hcfkt, ...);
	void APICALL (*USBHCUninitRootHub)(struct USBHCDIFace *Self, APTR hcunit, APTR hcfkt);
};

/**********************************************************************************************/

struct USBHCDQuery
{
	uint32					HCDIndex;			/* This is set before sending Query.
												   A value of -1 indicate to get a total all HCDs */
	uint64					ReadPackets;
	uint64					ReadBytes;
	uint64					SendPackets;
	uint64					SendBytes;
};

/**********************************************************************************************/

struct UsbInterface
{
	uint32	I_Am_Private;
};

/**********************************************************************************************/

struct USBIOReq
{
    // *** IOStdReq structure
	struct Message			io_Message;
	struct Device *			io_Device;			/* Device node pointer  */
	struct Unit *			io_Unit;			/* Unit (USS private) */
	uint16					io_Command;			/* Device command */
	uint8					io_Flags;
	int8					io_Error;			/* Error or warning num */
	uint32					io_Actual;			/* Actual number of bytes transferred */
	uint32					io_Length;			/* Requested number bytes transferred
											   If non-zero the USS may use the io_Data pointer for memory accesses */
	APTR					io_Data;			/* Points to data area.
											   A non-NULL ptr results in a USB data stage for the request */
	uint32					io_Offset;			/* Offset for block structured devices (USS private) */

    // *** USB Extension
	struct UsbEndPoint *	io_EndPoint;		/* EndPoint reference (USS's reference)*/
	APTR                	io_SetupData;		/* Ptr to Control EndPoint SETUP packet data, or NULL for no SETUP */
	uint32					io_SetupLength;		/* Bytesize of io_SetupData block. */

	/* -- v53.6 -- */
	uint32					io_TimeOut;			/* Value in Micro Seconds */
};

/**********************************************************************************************/

struct USBIOReqHCD
{
    // *** IOStdReq structure
	struct Message			io_Message;
	struct Device *			io_Device;			/* Device node pointer  */
	struct Unit *			io_Unit;			/* Unit (HCD private) */
	uint16					io_Command;			/* Device command */
	uint8					io_Flags;
	int8					io_Error;			/* Error or warning num */

	uint32					io_Actual;			/* Actual number of bytes transferred */
	uint32					io_Length;			/* Requested number bytes transferred
												   If non-zero the HCD may use the io_Data pointer for memory accesses */
	APTR					io_Data;			/* Points to data area.
												   Generate USB data stage if non-NULL.
												   Only touch data area if io_Length!=0 !!! */
	uint32					io_Offset;			/* Offset for block structured devices (HCD private) */

    // *** USB Extension
	APTR					io_EndPoint;		/* EndPoint reference (HCD's reference) */

	APTR					io_SetupData;		/* Ptr to Control EndPoint SETUP packet data, or NULL for no SETUP */
	uint32					io_SetupLength;     /* Bytesize of io_SetupData block. */

	struct USBBusDevDsc *	io_DevDsc;			/* USB Device Descriptor for USB Function. Always non-NULL */
	struct USBBusCfgDsc *	io_CfgDsc;			/* USB Descriptor for Configuration the Interface is part of (NULL if not Configured) */
	struct USBBusIntDsc *	io_IntDsc;			/* USB Descriptor for Interface the EndPoint is part of (NULL for EndPoint 0!!) */
	struct USBBusEPDsc *	io_EPDsc;			/* USB Descriptor for EndPoint (NULL for EndPoint 0!!) */

	/* -- v53.5 -- */
	uint32					io_TimeOut;			/* Value in Micro Seconds */
};

/**********************************************************************************************/

struct USBNotifyMsg
{
	struct Message	Msg;
	APTR			ObjRef;		/* Receiver's private reference for object in question */
	uint16			Type;		/* Type of notification */
	uint16			pad;
};

/**********************************************************************************************/

struct UsbRawFunction
{
	uint32	I_Am_Private;
};

/**********************************************************************************************/

struct UsbRawInterface
{
	uint32	I_Am_Private;
};

/**********************************************************************************************/

struct USBResourceIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct USBResourceIFace *Self);
	uint32 APICALL (*Release)(struct USBResourceIFace *Self);
	void APICALL (*Expunge)(struct USBResourceIFace *Self);
	struct Interface * APICALL (*Clone)(struct USBResourceIFace *Self);
	APTR APICALL (*USBResRegisterFDA)(struct USBResourceIFace *Self, struct TagItem * taglist);
	APTR APICALL (*USBResRegisterFD)(struct USBResourceIFace *Self, ...);
	void APICALL (*USBResUnregisterFD)(struct USBResourceIFace *Self, APTR fdkey);
	APTR APICALL (*USBResRegisterHCDA)(struct USBResourceIFace *Self, struct TagItem * taglist);
	APTR APICALL (*USBResRegisterHCD)(struct USBResourceIFace *Self, ...);
	void APICALL (*USBResUnregisterHCD)(struct USBResourceIFace *Self, APTR hcdkey);
	void APICALL (*Reserved1)(struct USBResourceIFace *Self);
	void APICALL (*Reserved2)(struct USBResourceIFace *Self);
	void APICALL (*Reserved3)(struct USBResourceIFace *Self);
	void APICALL (*Reserved4)(struct USBResourceIFace *Self);
	void APICALL (*Reserved5)(struct USBResourceIFace *Self);
	void APICALL (*Reserved6)(struct USBResourceIFace *Self);
	APTR APICALL (*USBResAddNotify)(struct USBResourceIFace *Self, uint32 type, struct MsgPort * port);
	void APICALL (*USBResRemNotify)(struct USBResourceIFace *Self, APTR subs);
	void APICALL (*Reserved7)(struct USBResourceIFace *Self);
	void APICALL (*Reserved8)(struct USBResourceIFace *Self);
	void APICALL (*Reserved9)(struct USBResourceIFace *Self);
	void APICALL (*Reserved10)(struct USBResourceIFace *Self);
	void APICALL (*Reserved11)(struct USBResourceIFace *Self);
	void APICALL (*Reserved12)(struct USBResourceIFace *Self);
};

/**********************************************************************************************/

struct USBSysIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct USBSysIFace *Self);
	uint32 APICALL (*Release)(struct USBSysIFace *Self);
	void APICALL (*Expunge)(struct USBSysIFace *Self);
	struct Interface * APICALL (*Clone)(struct USBSysIFace *Self);
	struct USBIOReq * APICALL (*USBAllocRequestA)(struct USBSysIFace *Self, struct IORequest * openreq, struct TagItem * taglist);
	struct USBIOReq * APICALL (*USBAllocRequest)(struct USBSysIFace *Self, struct IORequest * openreq, ...);
	void APICALL (*USBFreeRequest)(struct USBSysIFace *Self, struct USBIOReq * req);
	struct UsbRawFunction * APICALL (*USBFindFunctionA)(struct USBSysIFace *Self, struct UsbRawFunction * curfkt, struct TagItem * taglist);
	struct UsbRawFunction * APICALL (*USBFindFunction)(struct USBSysIFace *Self, struct UsbRawFunction * curfkt, ...);
	void APICALL (*USBLockFunction)(struct USBSysIFace *Self, struct UsbRawFunction * rawfkt);
	void APICALL (*USBUnlockFunction)(struct USBSysIFace *Self, struct UsbRawFunction * rawfkt);
	struct UsbFunction * APICALL (*USBClaimFunction)(struct USBSysIFace *Self, struct UsbRawFunction * rawfkt, APTR fdfkt, struct MsgPort * port);
	void APICALL (*USBDeclaimFunction)(struct USBSysIFace *Self, struct UsbFunction * usfkt);
	struct UsbRawFunction * APICALL (*USBAddFunctionA)(struct USBSysIFace *Self, struct UsbInterface * ushubifc, struct TagItem * taglist);
	struct UsbRawFunction * APICALL (*USBAddFunction)(struct USBSysIFace *Self, struct UsbInterface * ushubifc, ...);
	void APICALL (*USBRemFunction)(struct USBSysIFace *Self, struct UsbRawFunction * rawfkt, struct UsbInterface * ushubifc);
	struct UsbEndPoint * APICALL (*USBGetEndPoint)(struct USBSysIFace *Self, struct UsbFunction * usfkt, struct UsbInterface * usifc, LONG epnum);
	LONG APICALL (*USBEPControlXferA)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbEndPoint * usep, ULONG rcmd, ULONG rtype, ULONG rval, ULONG ridx, APTR buf, ULONG buflen, struct TagItem * taglist);
	LONG APICALL (*USBEPControlXfer)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbEndPoint * usep, ULONG rcmd, ULONG rtype, ULONG rval, ULONG ridx, APTR buf, ULONG buflen, ...);
	struct USBBusDscHead * APICALL (*USBEPGetDescriptorA)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbEndPoint * usep, ULONG rtype, LONG dtyp, LONG didx, struct TagItem * taglist);
	struct USBBusDscHead * APICALL (*USBEPGetDescriptor)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbEndPoint * usep, ULONG rtype, LONG dtyp, LONG didx, ...);
	struct USBBusCfgDsc * APICALL (*USBFktGetCfgDescriptorsA)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbFunction * usfkt, ULONG cfgid, struct TagItem * taglist);
	struct USBBusCfgDsc * APICALL (*USBFktGetCfgDescriptors)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbFunction * usfkt, ULONG cfgid, ...);
	LONG APICALL (*USBFktSetConfigurationA)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbFunction * fkt, struct USBBusCfgDsc * cfgdsc, struct TagItem * taglist);
	LONG APICALL (*USBFktSetConfiguration)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbFunction * fkt, struct USBBusCfgDsc * cfgdsc, ...);
	struct USBBusDscHead * APICALL (*USBParseDescriptors)(struct USBSysIFace *Self, struct USBBusDscHead * buffer, ULONG buflen);
	void APICALL (*USBFreeDescriptors)(struct USBSysIFace *Self, struct USBBusDscHead * dscr);
	struct USBBusDscHead * APICALL (*USBNextDescriptor)(struct USBSysIFace *Self, struct USBBusDscHead * dscr);
	struct USBBusDscHead * APICALL (*USBPrevDescriptor)(struct USBSysIFace *Self, struct USBBusDscHead * dscr);
	LONG APICALL (*USBObtainResourceA)(struct USBSysIFace *Self, ULONG type, APTR object, struct TagItem * taglist);
	LONG APICALL (*USBObtainResource)(struct USBSysIFace *Self, ULONG type, APTR object, ...);
	void APICALL (*USBReleaseResource)(struct USBSysIFace *Self, ULONG type, APTR object);
	struct UsbRawInterface * APICALL (*USBFindInterfaceA)(struct USBSysIFace *Self, struct UsbRawInterface * curifc, struct TagItem * taglist);
	struct UsbRawInterface * APICALL (*USBFindInterface)(struct USBSysIFace *Self, struct UsbRawInterface * curifc, ...);
	void APICALL (*USBLockInterface)(struct USBSysIFace *Self, struct UsbRawInterface * rawifc);
	void APICALL (*USBUnlockInterface)(struct USBSysIFace *Self, struct UsbRawInterface * rawifc);
	struct UsbInterface * APICALL (*USBClaimInterface)(struct USBSysIFace *Self, struct UsbRawInterface * rawifc, APTR fdifc, struct MsgPort * port);
	void APICALL (*USBDeclaimInterface)(struct USBSysIFace *Self, struct UsbInterface * usifc);
	struct UsbInterface * APICALL (*USBGetInterface)(struct USBSysIFace *Self, struct UsbFunction * usfkt, LONG ifcnum);
	struct USBBusDscHead * APICALL (*USBIntGetConfigurationA)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbInterface * usifc, struct TagItem * taglist);
	struct USBBusDscHead * APICALL (*USBIntGetConfiguration)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbInterface * usifc, ...);
	struct USBBusDscHead * APICALL (*USBIntGetAltSettingA)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbInterface * usifc, struct TagItem * taglist);
	struct USBBusDscHead * APICALL (*USBIntGetAltSetting)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbInterface * usifc, ...);
	LONG APICALL (*USBIntSetAltSettingA)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbInterface * usifc, ULONG altnum, struct TagItem * taglist);
	LONG APICALL (*USBIntSetAltSetting)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbInterface * usifc, ULONG altnum, ...);
	void APICALL (*USBLogPuts)(struct USBSysIFace *Self, LONG err, CONST_STRPTR context, CONST_STRPTR msg);
	void APICALL (*USBLogVPrintf)(struct USBSysIFace *Self, LONG err, CONST_STRPTR context, CONST_STRPTR msg, ULONG * fmtargs);
	LONG APICALL (*USBSetFunctionAttrsA)(struct USBSysIFace *Self, struct UsbFunction * clfkt, struct TagItem * taglist);
	LONG APICALL (*USBSetFunctionAttrs)(struct USBSysIFace *Self, struct UsbFunction * clfkt, ...);
	LONG APICALL (*USBSetInterfaceAttrsA)(struct USBSysIFace *Self, struct UsbInterface * clifc, struct TagItem * taglist);
	LONG APICALL (*USBSetInterfaceAttrs)(struct USBSysIFace *Self, struct UsbInterface * clifc, ...);
	void APICALL (*USBGetStackAttrsA)(struct USBSysIFace *Self, struct TagItem * taglist);
	void APICALL (*USBGetStackAttrs)(struct USBSysIFace *Self, ...);
	void APICALL (*USBGetRawFunctionAttrsA)(struct USBSysIFace *Self, struct UsbRawFunction * rawfkt, struct TagItem * taglist);
	void APICALL (*USBGetRawFunctionAttrs)(struct USBSysIFace *Self, struct UsbRawFunction * rawfkt, ...);
	void APICALL (*USBGetRawInterfaceAttrsA)(struct USBSysIFace *Self, struct UsbRawInterface * rawifc, struct TagItem * taglist);
	void APICALL (*USBGetRawInterfaceAttrs)(struct USBSysIFace *Self, struct UsbRawInterface * rawifc, ...);
	void APICALL (*USBFktDriverRunning)(struct USBSysIFace *Self, struct UsbFunction * fkt);
	void APICALL (*USBIfcDriverRunning)(struct USBSysIFace *Self, struct UsbInterface * ifc);
	LONG APICALL (*USBEPDestall)(struct USBSysIFace *Self, struct IORequest * openreq, struct UsbEndPoint * usep);
	APTR APICALL (*USBAllocObjectTags)(struct USBSysIFace *Self, uint32 type, ...);
	APTR APICALL (*USBAllocObject)(struct USBSysIFace *Self, uint32 type, struct TagItem * taglist);
	void APICALL (*USBFreeObject)(struct USBSysIFace *Self, uint32 type, APTR object);
	void APICALL (*USBLogPrintf)(struct USBSysIFace *Self, LONG err, CONST_STRPTR context, CONST_STRPTR msg, ...);
	APTR Private1;
	APTR Private2;
};

/**********************************************************************************************/

struct UserInfo
{
    TEXT  ui_UserName[32];
    UWORD ui_UserID;
    UWORD ui_PrimaryGroupID;
    ULONG ui_Flags;
};

/**********************************************************************************************/

struct UtilityIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct UtilityIFace *Self);
	ULONG APICALL (*Release)(struct UtilityIFace *Self);
	void APICALL (*Expunge)(struct UtilityIFace *Self);
	struct Interface * APICALL (*Clone)(struct UtilityIFace *Self);
	struct TagItem * APICALL (*AllocateTagItems)(struct UtilityIFace *Self, ULONG numTags);
	VOID APICALL (*ApplyTagChanges)(struct UtilityIFace *Self, struct TagItem * list, const struct TagItem * changeList);
	struct TagItem * APICALL (*CloneTagItems)(struct UtilityIFace *Self, const struct TagItem * original);
	VOID APICALL (*FilterTagChanges)(struct UtilityIFace *Self, struct TagItem * changeList, struct TagItem * originalList, ULONG apply);
	ULONG APICALL (*FilterTagItems)(struct UtilityIFace *Self, struct TagItem * taglist, const Tag * filterArray, ULONG logic);
	struct TagItem * APICALL (*FindTagItem)(struct UtilityIFace *Self, Tag tagValue, const struct TagItem * tagList);
	VOID APICALL (*FreeTagItems)(struct UtilityIFace *Self, struct TagItem * tagList);
	ULONG APICALL (*GetTagData)(struct UtilityIFace *Self, Tag tagValue, ULONG defaultVal, const struct TagItem * tagList);
	VOID APICALL (*MapTags)(struct UtilityIFace *Self, struct TagItem * tagList, const struct TagItem * mapList, ULONG mapType);
	struct TagItem * APICALL (*NextTagItem)(struct UtilityIFace *Self, struct TagItem ** tags);
	ULONG APICALL (*PackBoolTags)(struct UtilityIFace *Self, ULONG initialFlags, const struct TagItem * tagList, const struct TagItem * boolMap);
	VOID APICALL (*RefreshTagItemClones)(struct UtilityIFace *Self, struct TagItem * clone, const struct TagItem * original);
	BOOL APICALL (*TagInArray)(struct UtilityIFace *Self, Tag tagValue, const Tag * tagArray);
	ULONG APICALL (*CallHookPkt)(struct UtilityIFace *Self, struct Hook * hook, APTR object, APTR message);
	ULONG APICALL (*CallHook)(struct UtilityIFace *Self, struct Hook * hook, APTR object, ...);
	BOOL APICALL (*AddNamedObject)(struct UtilityIFace *Self, struct NamedObject * nameSpace, struct NamedObject * object);
	struct NamedObject * APICALL (*AllocNamedObjectA)(struct UtilityIFace *Self, CONST_STRPTR name, const struct TagItem * tags);
	struct NamedObject * APICALL (*AllocNamedObject)(struct UtilityIFace *Self, CONST_STRPTR name, ...);
	LONG APICALL (*AttemptRemNamedObject)(struct UtilityIFace *Self, struct NamedObject * object);
	struct NamedObject * APICALL (*FindNamedObject)(struct UtilityIFace *Self, struct NamedObject * name_space, CONST_STRPTR name, struct NamedObject * previous_object);
	struct NamedObject * APICALL (*FreeNamedObject)(struct UtilityIFace *Self, struct NamedObject * obj);
	STRPTR APICALL (*NamedObjectName)(struct UtilityIFace *Self, struct NamedObject * obj);
	void APICALL (*ReleaseNamedObject)(struct UtilityIFace *Self, struct NamedObject * obj);
	void APICALL (*RemNamedObject)(struct UtilityIFace *Self, struct NamedObject * obj, struct Message * message);
	void APICALL (*Amiga2Date)(struct UtilityIFace *Self, ULONG date_amiga, struct ClockData * cd);
	ULONG APICALL (*CheckDate)(struct UtilityIFace *Self, const struct ClockData * date);
	ULONG APICALL (*Date2Amiga)(struct UtilityIFace *Self, const struct ClockData * date);
	struct SkipList * APICALL (*CreateSkipList)(struct UtilityIFace *Self, struct Hook * hook, LONG max_levels);
	void APICALL (*DeleteSkipList)(struct UtilityIFace *Self, struct SkipList * skipList);
	struct SkipNode * APICALL (*FindSkipNode)(struct UtilityIFace *Self, const struct SkipList * skipList, APTR key);
	struct SkipNode * APICALL (*GetFirstSkipNode)(struct UtilityIFace *Self, const struct SkipList * skipList);
	struct SkipNode * APICALL (*GetNextSkipNode)(struct UtilityIFace *Self, const struct SkipList * skipList, const struct SkipNode * node);
	struct SkipNode * APICALL (*InsertSkipNode)(struct UtilityIFace *Self, struct SkipList * skipList, APTR key, ULONG dataSize);
	BOOL APICALL (*RemoveSkipNode)(struct UtilityIFace *Self, struct SkipList * skipList, APTR key);
	struct SplayTree * APICALL (*CreateSplayTree)(struct UtilityIFace *Self, struct Hook * compareHook);
	void APICALL (*DeleteSplayTree)(struct UtilityIFace *Self, struct SplayTree * splayTree);
	struct SplayNode * APICALL (*FindSplayNode)(struct UtilityIFace *Self, const struct SplayTree * splayTree, APTR key);
	struct SplayNode * APICALL (*InsertSplayNode)(struct UtilityIFace *Self, struct SplayTree * splayTree, APTR key, ULONG date_size);
	struct SplayNode * APICALL (*RemoveSplayNode)(struct UtilityIFace *Self, struct SplayTree * splayTree, APTR key);
	struct Node * APICALL (*FindNameNC)(struct UtilityIFace *Self, struct List * list, CONST_STRPTR name);
	ULONG APICALL (*GetUniqueID)(struct UtilityIFace *Self);
	void APICALL (*MessageDigest_SHA_Final)(struct UtilityIFace *Self, struct MessageDigest_SHA * shas);
	void APICALL (*MessageDigest_SHA_Init)(struct UtilityIFace *Self, struct MessageDigest_SHA * shas);
	void APICALL (*MessageDigest_SHA_Update)(struct UtilityIFace *Self, struct MessageDigest_SHA * shas, APTR data, LONG num_bytes);
	ULONG APICALL (*PackStructureTags)(struct UtilityIFace *Self, APTR pack, const ULONG * pack_table, const struct TagItem * tagList);
	ULONG APICALL (*UnpackStructureTags)(struct UtilityIFace *Self, CONST_APTR pack, const ULONG * pack_table, struct TagItem * tagList);
	ULONG APICALL (*Random)(struct UtilityIFace *Self, struct RandomState * state);
	APTR APICALL (*SetMem)(struct UtilityIFace *Self, APTR destination, UBYTE fillChar, LONG length);
	LONG APICALL (*Stricmp)(struct UtilityIFace *Self, CONST_STRPTR s1, CONST_STRPTR s2);
	LONG APICALL (*Strlcpy)(struct UtilityIFace *Self, STRPTR dst, CONST_STRPTR src, LONG size);
	LONG APICALL (*Strlcat)(struct UtilityIFace *Self, STRPTR dst, CONST_STRPTR src, LONG size);
	LONG APICALL (*Strnicmp)(struct UtilityIFace *Self, CONST_STRPTR s1, CONST_STRPTR s2, LONG n);
	ULONG APICALL (*ToLower)(struct UtilityIFace *Self, TEXT c);
	ULONG APICALL (*ToUpper)(struct UtilityIFace *Self, TEXT c);
	STRPTR APICALL (*VASPrintf)(struct UtilityIFace *Self, CONST_STRPTR fmt, APTR args);
	STRPTR APICALL (*ASPrintf)(struct UtilityIFace *Self, CONST_STRPTR fmt, ...);
	LONG APICALL (*VSNPrintf)(struct UtilityIFace *Self, STRPTR buffer, LONG bufferSize, CONST_STRPTR fmt, APTR args);
	LONG APICALL (*SNPrintf)(struct UtilityIFace *Self, STRPTR buffer, LONG bufferSize, CONST_STRPTR fmt, ...);
	VOID APICALL (*ClearMem)(struct UtilityIFace *Self, APTR destination, uint32 size);
	VOID APICALL (*MoveMem)(struct UtilityIFace *Self, APTR source, APTR destination, uint32 size);
	uint32 APICALL (*Strlen)(struct UtilityIFace *Self, CONST_STRPTR string);
};

/**********************************************************************************************/

struct Vector
{
   UBYTE  Operation; /* Type of rendering operation */
   UBYTE  Type;      /* Type of environment (monochrome/color) */
   UWORD  DRIPen;    /* DrawInfo pen for this rendering */
   ULONG  States;    /* States this rendering applies to */
   WORD   X, Y;      /* Offsets for rendering */
   UWORD *Data;      /* Rendering specifications */
};

/**********************************************************************************************/

struct VectorInfo
{
   ULONG          VectorID;     /* To identify the image, if needed */
   struct Vector *Vectors;      /* VO_END-terminated array of vectors */
   UWORD          DesignWidth;  /* Reference width for scaling */
   UWORD          DesignHeight; /* Reference height for scaling */
   ULONG          Flags;        /* Additional information */
   ULONG          States;       /* Supported states */
};

/**********************************************************************************************/

struct VirtualIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct VirtualIFace *Self);
	ULONG APICALL (*Release)(struct VirtualIFace *Self);
	void APICALL (*Expunge)(struct VirtualIFace *Self);
	struct Interface * APICALL (*Clone)(struct VirtualIFace *Self);
	Class * APICALL (*VIRTUAL_GetClass)(struct VirtualIFace *Self);
	VOID APICALL (*RefreshVirtualGadget)(struct VirtualIFace *Self, struct Gadget * gadget, Object * obj, struct Window * window, struct Requester * requester);
	BOOL APICALL (*RethinkVirtualSize)(struct VirtualIFace *Self, Object * virt_obj, Object * rootlayout, struct TextFont * font, struct Screen * screen, struct LayoutLimits * layoutlimits);
};

/**********************************************************************************************/

struct VolumeNode    /* VOLUME structure; vn_Type==DLT_VOLUME */
{
    BPTR             vn_Next;        /* bptr to next doslist entry          */
    int32            vn_Type;        /* always DLT_VOLUME for dos "volumes" */
    struct MsgPort * vn_Port;        /* msg port for the handler process    */
    int32            vn_Reserved1;   /* reserved for use by DOS             */
    struct DateStamp vn_VolumeDate;  /* creation date                       */
    BPTR             vn_LockList;    /* unused, leave as 0                  */
    int32            vn_DiskType;    /* 'DOS\0', etc                        */
    int32            vn_FSPrivate;   /* private filesystem use              */
    BSTR             vn_Name;        /* bstr name                           */
    int32            vn_StructSize;  /* FULL size of this structure         */
    int32            vn_Reserved[4]; /* DOS expansion                       */
};

/**********************************************************************************************/

struct Warp3DIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct Warp3DIFace *Self);
	ULONG APICALL (*Release)(struct Warp3DIFace *Self);
	void APICALL (*Expunge)(struct Warp3DIFace *Self);
	struct Interface * APICALL (*Clone)(struct Warp3DIFace *Self);
	W3D_Context * APICALL (*W3D_CreateContext)(struct Warp3DIFace *Self, ULONG * error, struct TagItem * CCTags);
	W3D_Context * APICALL (*W3D_CreateContextTags)(struct Warp3DIFace *Self, ULONG * error, ...);
	void APICALL (*W3D_DestroyContext)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_GetState)(struct Warp3DIFace *Self, W3D_Context * context, ULONG state);
	ULONG APICALL (*W3D_SetState)(struct Warp3DIFace *Self, W3D_Context * context, ULONG state, ULONG action);
	ULONG APICALL (*W3D_CheckDriver)(struct Warp3DIFace *Self);
	ULONG APICALL (*W3D_LockHardware)(struct Warp3DIFace *Self, W3D_Context * context);
	void APICALL (*W3D_UnLockHardware)(struct Warp3DIFace *Self, W3D_Context * context);
	void APICALL (*W3D_WaitIdle)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_CheckIdle)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_Query)(struct Warp3DIFace *Self, W3D_Context * context, ULONG query, ULONG destfmt);
	ULONG APICALL (*W3D_GetTexFmtInfo)(struct Warp3DIFace *Self, W3D_Context * context, ULONG format, ULONG destfmt);
	W3D_Texture * APICALL (*W3D_AllocTexObj)(struct Warp3DIFace *Self, W3D_Context * context, ULONG * error, struct TagItem * ATOTags);
	W3D_Texture * APICALL (*W3D_AllocTexObjTags)(struct Warp3DIFace *Self, W3D_Context * context, ULONG * error, ...);
	void APICALL (*W3D_FreeTexObj)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Texture * texture);
	void APICALL (*W3D_ReleaseTexture)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Texture * texture);
	void APICALL (*W3D_FlushTextures)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_SetFilter)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Texture * texture, ULONG min, ULONG mag);
	ULONG APICALL (*W3D_SetTexEnv)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Texture * texture, ULONG envparam, W3D_Color * envcolor);
	ULONG APICALL (*W3D_SetWrapMode)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Texture * texture, ULONG mode_s, ULONG mode_t, W3D_Color * bordercolor);
	ULONG APICALL (*W3D_UpdateTexImage)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Texture * texture, void * teximage, int level, ULONG * palette);
	ULONG APICALL (*W3D_UploadTexture)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Texture * texture);
	ULONG APICALL (*W3D_DrawLine)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Line * line);
	ULONG APICALL (*W3D_DrawPoint)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Point * point);
	ULONG APICALL (*W3D_DrawTriangle)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Triangle * triangle);
	ULONG APICALL (*W3D_DrawTriFan)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Triangles * triangles);
	ULONG APICALL (*W3D_DrawTriStrip)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Triangles * triangles);
	ULONG APICALL (*W3D_SetAlphaMode)(struct Warp3DIFace *Self, W3D_Context * context, ULONG mode, W3D_Float * refval);
	ULONG APICALL (*W3D_SetBlendMode)(struct Warp3DIFace *Self, W3D_Context * context, ULONG srcfunc, ULONG dstfunc);
	ULONG APICALL (*W3D_SetDrawRegion)(struct Warp3DIFace *Self, W3D_Context * context, struct BitMap * bm, int yoffset, W3D_Scissor * scissor);
	ULONG APICALL (*W3D_SetFogParams)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Fog * fogparams, ULONG fogmode);
	ULONG APICALL (*W3D_SetColorMask)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Bool red, W3D_Bool green, W3D_Bool blue, W3D_Bool alpha);
	ULONG APICALL (*W3D_SetStencilFunc)(struct Warp3DIFace *Self, W3D_Context * context, ULONG func, ULONG refvalue, ULONG mask);
	ULONG APICALL (*W3D_AllocZBuffer)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_FreeZBuffer)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_ClearZBuffer)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Double * clearvalue);
	ULONG APICALL (*W3D_ReadZPixel)(struct Warp3DIFace *Self, W3D_Context * context, ULONG x, ULONG y, W3D_Double * z);
	ULONG APICALL (*W3D_ReadZSpan)(struct Warp3DIFace *Self, W3D_Context * context, ULONG x, ULONG y, ULONG n, W3D_Double * z);
	ULONG APICALL (*W3D_SetZCompareMode)(struct Warp3DIFace *Self, W3D_Context * context, ULONG mode);
	ULONG APICALL (*W3D_AllocStencilBuffer)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_ClearStencilBuffer)(struct Warp3DIFace *Self, W3D_Context * context, ULONG * clearval);
	ULONG APICALL (*W3D_FillStencilBuffer)(struct Warp3DIFace *Self, W3D_Context * context, ULONG x, ULONG y, ULONG width, ULONG height, ULONG depth, void * data);
	ULONG APICALL (*W3D_FreeStencilBuffer)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_ReadStencilPixel)(struct Warp3DIFace *Self, W3D_Context * context, ULONG x, ULONG y, ULONG * st);
	ULONG APICALL (*W3D_ReadStencilSpan)(struct Warp3DIFace *Self, W3D_Context * context, ULONG x, ULONG y, ULONG n, ULONG * st);
	ULONG APICALL (*W3D_SetLogicOp)(struct Warp3DIFace *Self, W3D_Context * context, ULONG operation);
	ULONG APICALL (*W3D_Hint)(struct Warp3DIFace *Self, W3D_Context * context, ULONG mode, ULONG quality);
	ULONG APICALL (*W3D_SetDrawRegionWBM)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Bitmap * bitmap, W3D_Scissor * scissor);
	ULONG APICALL (*W3D_GetDriverState)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_Flush)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_SetPenMask)(struct Warp3DIFace *Self, W3D_Context * context, ULONG pen);
	ULONG APICALL (*W3D_SetStencilOp)(struct Warp3DIFace *Self, W3D_Context * context, ULONG sfail, ULONG dpfail, ULONG dppass);
	ULONG APICALL (*W3D_SetWriteMask)(struct Warp3DIFace *Self, W3D_Context * context, ULONG mask);
	ULONG APICALL (*W3D_WriteStencilPixel)(struct Warp3DIFace *Self, W3D_Context * context, ULONG x, ULONG y, ULONG st);
	ULONG APICALL (*W3D_WriteStencilSpan)(struct Warp3DIFace *Self, W3D_Context * context, ULONG x, ULONG y, ULONG n, ULONG * st, UBYTE * mask);
	void APICALL (*W3D_WriteZPixel)(struct Warp3DIFace *Self, W3D_Context * context, ULONG x, ULONG y, W3D_Double * z);
	void APICALL (*W3D_WriteZSpan)(struct Warp3DIFace *Self, W3D_Context * context, ULONG x, ULONG y, ULONG n, W3D_Double * z, UBYTE * maks);
	ULONG APICALL (*W3D_SetCurrentColor)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Color * color);
	ULONG APICALL (*W3D_SetCurrentPen)(struct Warp3DIFace *Self, W3D_Context * context, ULONG pen);
	ULONG APICALL (*W3D_UpdateTexSubImage)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Texture * texture, void * teximage, ULONG lev, ULONG * palette, W3D_Scissor * scissor, ULONG srcbpr);
	ULONG APICALL (*W3D_FreeAllTexObj)(struct Warp3DIFace *Self, W3D_Context * context);
	ULONG APICALL (*W3D_GetDestFmt)(struct Warp3DIFace *Self);
	ULONG APICALL (*W3D_DrawLineStrip)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Lines * lines);
	ULONG APICALL (*W3D_DrawLineLoop)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Lines * lines);
	W3D_Driver ** APICALL (*W3D_GetDrivers)(struct Warp3DIFace *Self);
	ULONG APICALL (*W3D_QueryDriver)(struct Warp3DIFace *Self, W3D_Driver * driver, ULONG query, ULONG destfmt);
	ULONG APICALL (*W3D_GetDriverTexFmtInfo)(struct Warp3DIFace *Self, W3D_Driver * driver, ULONG format, ULONG destfmt);
	ULONG APICALL (*W3D_RequestMode)(struct Warp3DIFace *Self, struct TagItem * taglist);
	ULONG APICALL (*W3D_RequestModeTags)(struct Warp3DIFace *Self, ...);
	void APICALL (*W3D_SetScissor)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Scissor * scissor);
	void APICALL (*W3D_FlushFrame)(struct Warp3DIFace *Self, W3D_Context * context);
	W3D_Driver * APICALL (*W3D_TestMode)(struct Warp3DIFace *Self, ULONG ModeID);
	ULONG APICALL (*W3D_SetChromaTestBounds)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Texture * texture, ULONG rgba_lower, ULONG rgba_upper, ULONG mode);
	ULONG APICALL (*W3D_ClearDrawRegion)(struct Warp3DIFace *Self, W3D_Context * context, ULONG color);
	ULONG APICALL (*W3D_DrawTriangleV)(struct Warp3DIFace *Self, W3D_Context * context, W3D_TriangleV * triangle);
	ULONG APICALL (*W3D_DrawTriFanV)(struct Warp3DIFace *Self, W3D_Context * context, W3D_TrianglesV * triangles);
	ULONG APICALL (*W3D_DrawTriStripV)(struct Warp3DIFace *Self, W3D_Context * context, W3D_TrianglesV * triangles);
	W3D_ScreenMode * APICALL (*W3D_GetScreenmodeList)(struct Warp3DIFace *Self);
	void APICALL (*W3D_FreeScreenmodeList)(struct Warp3DIFace *Self, W3D_ScreenMode * list);
	ULONG APICALL (*W3D_BestModeID)(struct Warp3DIFace *Self, struct TagItem * tags);
	ULONG APICALL (*W3D_BestModeIDTags)(struct Warp3DIFace *Self, ...);
	ULONG APICALL (*W3D_VertexPointer)(struct Warp3DIFace *Self, W3D_Context * context, void * pointer, int stride, ULONG mode, ULONG flags);
	ULONG APICALL (*W3D_TexCoordPointer)(struct Warp3DIFace *Self, W3D_Context * context, void * pointer, int stride, int unit, int off_v, int off_w, ULONG flags);
	ULONG APICALL (*W3D_ColorPointer)(struct Warp3DIFace *Self, W3D_Context * context, void * pointer, int stride, ULONG format, ULONG mode, ULONG flags);
	ULONG APICALL (*W3D_BindTexture)(struct Warp3DIFace *Self, W3D_Context * context, ULONG tmu, W3D_Texture * texture);
	ULONG APICALL (*W3D_DrawArray)(struct Warp3DIFace *Self, W3D_Context * context, ULONG primitive, ULONG base, ULONG count);
	ULONG APICALL (*W3D_DrawElements)(struct Warp3DIFace *Self, W3D_Context * context, ULONG primitive, ULONG type, ULONG count, void * indices);
	void APICALL (*W3D_SetFrontFace)(struct Warp3DIFace *Self, W3D_Context * context, ULONG direction);
	uint32 APICALL (*W3D_SetTextureBlend)(struct Warp3DIFace *Self, W3D_Context * context, struct TagItem * tagList);
	uint32 APICALL (*W3D_SetTextureBlendTags)(struct Warp3DIFace *Self, W3D_Context * context, ...);
	ULONG APICALL (*W3D_SecondaryColorPointer)(struct Warp3DIFace *Self, W3D_Context * context, void * pointer, int stride, ULONG format, ULONG mode, ULONG flags);
	ULONG APICALL (*W3D_FogCoordPointer)(struct Warp3DIFace *Self, W3D_Context * context, void * pointer, int stride, ULONG mode, ULONG flags);
	ULONG APICALL (*W3D_InterleavedArray)(struct Warp3DIFace *Self, W3D_Context * context, void * pointer, int stride, ULONG format, ULONG flags);
	ULONG APICALL (*W3D_ClearBuffers)(struct Warp3DIFace *Self, W3D_Context * context, W3D_Color * color, W3D_Double * depth, uint32 * stencil);
	uint32 APICALL (*W3D_SetParameter)(struct Warp3DIFace *Self, W3D_Context * context, uint32 target, void * pattern);
};

/**********************************************************************************************/

struct WindowIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct WindowIFace *Self);
	ULONG APICALL (*Release)(struct WindowIFace *Self);
	void APICALL (*Expunge)(struct WindowIFace *Self);
	struct Interface * APICALL (*Clone)(struct WindowIFace *Self);
	Class * APICALL (*WINDOW_GetClass)(struct WindowIFace *Self);
	void APICALL (*NewWindowPrefs)(struct WindowIFace *Self);
	ULONG APICALL (*WindowPrivate1)(struct WindowIFace *Self);
	void APICALL (*UpdateWindowPrefs)(struct WindowIFace *Self, struct Screen * screen);
};

/**********************************************************************************************/

struct wmActivateGadget
{
    uint32         MethodID;
    struct Gadget *wma_Object;
};

/**********************************************************************************************/

struct wmSnapshot
{
    uint32         MethodID; /* always WM_SNAPSHOT */
    enum SnapHow   How;
};

/**********************************************************************************************/

struct WordColorEntry
{
    WORD ColorWord[4]; /* 1 entry for each of YMCB */
};

/**********************************************************************************************/

struct WorkbenchIFace
{
	struct InterfaceData Data;

	ULONG APICALL (*Obtain)(struct WorkbenchIFace *Self);
	ULONG APICALL (*Release)(struct WorkbenchIFace *Self);
	void APICALL (*Expunge)(struct WorkbenchIFace *Self);
	struct Interface * APICALL (*Clone)(struct WorkbenchIFace *Self);
	VOID APICALL (*UpdateWorkbench)(struct WorkbenchIFace *Self, CONST_STRPTR name, ULONG lock, LONG action);
	APTR Private1;
	APTR Private2;
	struct AppWindow * APICALL (*AddAppWindowA)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, struct Window * window, struct MsgPort * msgport, const struct TagItem * taglist);
	struct AppWindow * APICALL (*AddAppWindow)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, struct Window * window, struct MsgPort * msgport, ...);
	BOOL APICALL (*RemoveAppWindow)(struct WorkbenchIFace *Self, struct AppWindow * appWindow);
	struct AppIcon * APICALL (*AddAppIconA)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort * msgport, BPTR lock, struct DiskObject * diskobj, const struct TagItem * taglist);
	struct AppIcon * APICALL (*AddAppIcon)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort * msgport, BPTR lock, struct DiskObject * diskobj, ...);
	BOOL APICALL (*RemoveAppIcon)(struct WorkbenchIFace *Self, struct AppIcon * appIcon);
	struct AppMenuItem * APICALL (*AddAppMenuItemA)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort * msgport, const struct TagItem * taglist);
	struct AppMenuItem * APICALL (*AddAppMenuItem)(struct WorkbenchIFace *Self, ULONG id, ULONG userdata, CONST_STRPTR text, struct MsgPort * msgport, ...);
	BOOL APICALL (*RemoveAppMenuItem)(struct WorkbenchIFace *Self, struct AppMenuItem * appMenuItem);
	APTR Private3;
	ULONG APICALL (*WBInfo)(struct WorkbenchIFace *Self, BPTR lock, CONST_STRPTR name, struct Screen * screen);
	BOOL APICALL (*OpenWorkbenchObjectA)(struct WorkbenchIFace *Self, CONST_STRPTR name, const struct TagItem * tags);
	BOOL APICALL (*OpenWorkbenchObject)(struct WorkbenchIFace *Self, CONST_STRPTR name, ...);
	BOOL APICALL (*CloseWorkbenchObjectA)(struct WorkbenchIFace *Self, CONST_STRPTR name, const struct TagItem * tags);
	BOOL APICALL (*CloseWorkbenchObject)(struct WorkbenchIFace *Self, CONST_STRPTR name, ...);
	BOOL APICALL (*WorkbenchControlA)(struct WorkbenchIFace *Self, CONST_STRPTR name, const struct TagItem * tags);
	BOOL APICALL (*WorkbenchControl)(struct WorkbenchIFace *Self, CONST_STRPTR name, ...);
	struct AppWindowDropZone * APICALL (*AddAppWindowDropZoneA)(struct WorkbenchIFace *Self, struct AppWindow * aw, ULONG id, ULONG userdata, const struct TagItem * tags);
	struct AppWindowDropZone * APICALL (*AddAppWindowDropZone)(struct WorkbenchIFace *Self, struct AppWindow * aw, ULONG id, ULONG userdata, ...);
	BOOL APICALL (*RemoveAppWindowDropZone)(struct WorkbenchIFace *Self, struct AppWindow * aw, struct AppWindowDropZone * dropZone);
	BOOL APICALL (*ChangeWorkbenchSelectionA)(struct WorkbenchIFace *Self, CONST_STRPTR name, struct Hook * hook, const struct TagItem * tags);
	BOOL APICALL (*ChangeWorkbenchSelection)(struct WorkbenchIFace *Self, CONST_STRPTR name, struct Hook * hook, ...);
	BOOL APICALL (*MakeWorkbenchObjectVisibleA)(struct WorkbenchIFace *Self, CONST_STRPTR name, const struct TagItem * tags);
	BOOL APICALL (*MakeWorkbenchObjectVisible)(struct WorkbenchIFace *Self, CONST_STRPTR name, ...);
	ULONG APICALL (*WhichWorkbenchObjectA)(struct WorkbenchIFace *Self, struct Window * window, LONG x, LONG y, const struct TagItem * tags);
	ULONG APICALL (*WhichWorkbenchObject)(struct WorkbenchIFace *Self, struct Window * window, LONG x, LONG y, ...);
	APTR Private4;
};

/**********************************************************************************************/

struct WorkbenchPreviewCachePrefs
{
    TEXT wtpc_Path[0];
};

/**********************************************************************************************/

struct WorkbenchTitleFormatPrefs
{
    TEXT wtfp_Format[0];
};

/**********************************************************************************************/

struct XenaIFace
{
	struct InterfaceData Data;

	uint32 APICALL (*Obtain)(struct XenaIFace *Self);
	uint32 APICALL (*Release)(struct XenaIFace *Self);
	void APICALL (*Expunge)(struct XenaIFace *Self);
	struct Interface * APICALL (*Clone)(struct XenaIFace *Self);
	CONST_STRPTR APICALL (*AllocResource)(struct XenaIFace *Self, uint32 unitNum, CONST_STRPTR name);
	void APICALL (*FreeResource)(struct XenaIFace *Self, uint32 unitNum);
};

/**********************************************************************************************/

struct YUVRenderInfo
{
	struct RenderInfo RI;
	APTR              Planes[3];
	WORD              BytesPerRow[3];
	WORD              padWord;
};
