AHI structs from "http://aminet.net/driver/audio/m68k-amigaos-ahidev.lha"

List of AHI structs:
struct AHIAudioCtrl
struct AHIAudioCtrlDrv
struct AHIAudioModeRequester
struct AHIDSPEcho            //USE AHIEffDSPEcho instead!
struct AHIEffChannelInfo
struct AHIEffDSPEcho
struct AHIEffDSPMask
struct AHIEffMasterVolume
struct AHIEffOutputBuffer
struct AHIGlobalPrefs
struct AHIIFace
struct AHIInterfaceData
struct AHIRecordMessage
struct AHIRequest
struct AHISampleInfo
struct AHISoundMessage
struct AHIsubIFace
struct AHIsubInterfaceData
struct AHIUnitPrefs

/**********************************************/

/* AHIAudioCtrl */
struct AHIAudioCtrl
{
 APTR ahiac_UserData;
 /* Lots of private data follows! */
};

/* AHISoundMessage */
struct AHISoundMessage
{
  UWORD  ahism_Channel;
};

/* AHIRecordMessage */
struct AHIRecordMessage
{
 ULONG ahirm_Type;        /* Format of buffer (object) */
 APTR  ahirm_Buffer;      /* Pointer to the sample array */
 ULONG ahirm_Length;      /* Number of sample frames in buffer */
};

/* AHISampleInfo */
struct AHISampleInfo
{
 ULONG ahisi_Type;        /* Format of samples */
 APTR  ahisi_Address;    /* Address to array of samples */
 ULONG ahisi_Length;      /* Number of samples in array */
};

/* AHIAudioModeRequester */
struct AHIAudioModeRequester
{
 ULONG ahiam_AudioID;      /* Selected audio mode */
 ULONG ahiam_MixFreq;      /* Selected mixing/sampling frequency */

 WORD  ahiam_LeftEdge;      /* Coordinates of requester on exit */
 WORD  ahiam_TopEdge;
 WORD  ahiam_Width;
 WORD  ahiam_Height;

 BOOL  ahiam_InfoOpened;    /* Info window opened on exit? */
 WORD  ahiam_InfoLeftEdge;  /* Last coordinates of Info window */
 WORD  ahiam_InfoTopEdge;
 WORD  ahiam_InfoWidth;
 WORD  ahiam_InfoHeight;

 UWORD ahiam_ObsoleteUserData[2];
 UWORD ahiam_Pad;
 APTR  ahiam_UserData;      /* You can store your own data here (V6) */
 /* Lots of private data follows! */
};

/* AHIEffMasterVolume */
struct AHIEffMasterVolume
{
 ULONG ahie_Effect;        /* Set to AHIET_MASTERVOLUME */
 Fixed ahiemv_Volume;      /* See autodocs for range! */
};

/* AHIEffOutputBuffer */
struct AHIEffOutputBuffer
{
 ULONG    ahie_Effect;      /* Set to AHIET_OUTPUTBUFFER */
 struct Hook  *ahieob_Func;
 /* These fields are filled by AHI */
 ULONG    ahieob_Type;      /* Format of buffer */
 APTR     ahieob_Buffer;    /* Pointer to the sample array */
 ULONG    ahieob_Length;    /* Number of sample frames in buffer */
};

/* AHIEffDSPMask (V4) */
struct AHIEffDSPMask
{
 ULONG ahie_Effect;        /* Set to AHIET_DSPMASK */
 UWORD ahiedm_Channels;    /* Number of elements in array */
 UBYTE ahiedm_Mask[0];      /* Here follows the array */
};

/* AHIEffDSPEcho (V4) */
struct AHIEffDSPEcho
{
 ULONG ahie_Effect;        /* Set to AHIET_DSPECHO */
 ULONG ahiede_Delay;        /* In samples */
 Fixed ahiede_Feedback;
 Fixed ahiede_Mix;
 Fixed ahiede_Cross;
};

/* AHIEffChannelInfo (V4) */
struct AHIEffChannelInfo
{
 ULONG        ahie_Effect;        /* Set to AHIET_CHANNELINFO */
 struct Hook *ahieci_Func;
 UWORD        ahieci_Channels;
 UWORD        ahieci_Pad;
 /* The rest is filled by AHI */
 ULONG        ahieci_Offset[0];  /* The array follows */
};

/* AHIUnitPrefs */
struct AHIUnitPrefs
{
 UBYTE  ahiup_Unit;
 UBYTE   ahiup_Obsolete;        /* Was ahiup_ScaleMode */
       UWORD  ahiup_Channels;
       ULONG  ahiup_AudioMode;
       ULONG  ahiup_Frequency;
       Fixed  ahiup_MonitorVolume;
       Fixed  ahiup_InputGain;
       Fixed  ahiup_OutputVolume;
       ULONG  ahiup_Input;
       ULONG  ahiup_Output;
};

/* AHIGlobalPrefs */
struct AHIGlobalPrefs
{
 UWORD ahigp_DebugLevel;        /* Range: 0-3 (for None, Low, High and All) */
 BOOL  ahigp_DisableSurround;
 BOOL  ahigp_DisableEcho;
 BOOL  ahigp_FastEcho;
 Fixed ahigp_MaxCPU;
 BOOL  ahigp_ClipMasterVolume;
 UWORD ahigp_Pad;
 Fixed ahigp_AntiClickTime;    /* In seconds (V6) */
 UWORD ahigp_ScaleMode;        /* See below (V6) */
};

/* AHIRequest */
struct AHIRequest
{
 struct IOStdReq ahir_Std;      /* Standard IO request */
 UWORD           ahir_Version;  /* Needed version */
 /* --- New for V4, they will be ignored by V2 and earlier --- */
 UWORD       ahir_Pad1;
 ULONG       ahir_Private[2];    /* Hands off! */
 ULONG       ahir_Type;          /* Sample format */
 ULONG       ahir_Frequency;    /* Sample/Record frequency */
 Fixed       ahir_Volume;        /* Sample volume */
 Fixed       ahir_Position;      /* Stereo position */
 struct AHIRequest *ahir_Link; /* For double buffering */
};

/* AHIAudioCtrlDrv */
struct AHIAudioCtrlDrv
{
 struct AHIAudioCtrl ahiac_AudioCtrl;
 ULONG               ahiac_Flags;          /* See below for definition  */
 struct Hook        *ahiac_SoundFunc;      /* AHIA_SoundFunc    */
 struct Hook        *ahiac_PlayerFunc;      /* AHIA_PlayerFunc    */
 Fixed               ahiac_PlayerFreq;      /* AHIA_PlayerFreq    */
 Fixed               ahiac_MinPlayerFreq;  /* AHIA_MinPlayerFreq    */
 Fixed               ahiac_MaxPlayerFreq;  /* AHIA_MaxPlayerFreq    */
 ULONG               ahiac_MixFreq;        /* AHIA_MixFreq      */
 UWORD               ahiac_Channels;        /* AHIA_Channels    */
 UWORD               ahiac_Sounds;          /* AHIA_Sounds      */

 APTR                ahiac_DriverData;      /* Unused. Store whatever you want here. */

 struct Hook *ahiac_MixerFunc;         /* Mixing routine Hook    */
 struct Hook *ahiac_SamplerFunc;       /* Sampler routine Hook    */
 ULONG        ahiac_Obsolete;
 ULONG        ahiac_BuffSamples;       /* Samples to mix this pass.  */
 ULONG        ahiac_MinBuffSamples;   /* Min. samples to mix each pass. */
 ULONG        ahiac_MaxBuffSamples;   /* Max. samples to mix each pass. */
 ULONG        ahiac_BuffSize;         /* Buffer size ahiac_MixerFunc needs. */
 ULONG        ahiac_BuffType;         /* Buffer format (V2)    */
 BOOL       (*ahiac_PreTimer)(void);   /* Call before mixing (V4)  */
 void       (*ahiac_PostTimer)(void); /* Call after mixing (V4)  */
 ULONG        ahiac_AntiClickSamples; /* AntiClick samples (V6)  */
 struct Hook *ahiac_PreTimerFunc;     /* A Hook wrapper for ahiac_PreTimer (V6) */
 struct Hook *ahiac_PostTimerFunc;    /* A Hook wrapper for ahiac_PostTimer (V6) */

 /* The rest is PRIVATE! Hands off! They may change any time.
 [lots of private stuff] */
};

/* AHIInterfaceData */
struct AHIInterfaceData {
 struct Library *LibBase;
};

/* AHIIFace */
struct AHIIFace
{
 struct AHIInterfaceData Data;
 static struct AHIIFace* CreateIFace(struct Library * _AHIBase);
 static void DestroyIFace(struct AHIIFace* _iface);
 struct AHIAudioCtrl* AHI_AllocAudioA(struct TagItem * tagList);
 struct AHIAudioCtrl* AHI_AllocAudio(Tag tag1, ...);
 void  AHI_FreeAudio(struct AHIAudioCtrl * AudioCtrl);
 void  AHI_KillAudio();
 ULONG AHI_ControlAudioA(struct AHIAudioCtrl * AudioCtrl, struct TagItem * tagList);
 ULONG AHI_ControlAudio(struct AHIAudioCtrl * AudioCtrl, Tag tag1, ...);
 void  AHI_SetVol(UWORD Channel, Fixed Volume, sposition Pan, struct AHIAudioCtrl * AudioCtrl, ULONG Flags);
 void  AHI_SetFreq(UWORD Channel, ULONG Freq, struct AHIAudioCtrl * AudioCtrl, ULONG Flags);
 void  AHI_SetSound(UWORD Channel, UWORD Sound, ULONG Offset, LONG Length, struct AHIAudioCtrl * AudioCtrl, ULONG Flags);
 ULONG AHI_SetEffect(APTR Effect, struct AHIAudioCtrl * AudioCtrl);
 ULONG AHI_LoadSound(UWORD Sound, ULONG Type, APTR Info, struct AHIAudioCtrl * AudioCtrl);
 void  AHI_UnloadSound(UWORD Sound, struct AHIAudioCtrl * Audioctrl);
 ULONG AHI_NextAudioID(ULONG Last_ID);
 BOOL  AHI_GetAudioAttrsA(ULONG ID, struct AHIAudioCtrl * Audioctrl, struct TagItem * tagList);
 BOOL  AHI_GetAudioAttrs(ULONG ID, struct AHIAudioCtrl * Audioctrl, Tag tag1, ...);
 ULONG AHI_BestAudioIDA(struct TagItem * tagList);
 ULONG AHI_BestAudioID(Tag tag1, ...);
 struct AHIAudioModeRequester* AHI_AllocAudioRequestA(struct TagItem * tagList);
 struct AHIAudioModeRequester* AHI_AllocAudioRequest(Tag tag1, ...);
 BOOL  AHI_AudioRequestA(struct AHIAudioModeRequester * Requester, struct TagItem * tagList);
 BOOL  AHI_AudioRequest(struct AHIAudioModeRequester * Requester, Tag tag1, ...);
 void  AHI_FreeAudioRequest(struct AHIAudioModeRequester * Requester);
 void  AHI_PlayA(struct AHIAudioCtrl * Audioctrl, struct TagItem * tagList);
 void  AHI_Play(struct AHIAudioCtrl * Audioctrl, Tag tag1, ...);
 ULONG AHI_SampleFrameSize(ULONG SampleType);
 ULONG AHI_AddAudioMode(struct TagItem * AHIPrivate);
 ULONG AHI_RemoveAudioMode(ULONG AHIPrivate);
 ULONG AHI_LoadModeFile(STRPTR AHIPrivate);
};

/* AHIsubInterfaceData */
struct AHIsubInterfaceData {
 struct Library *LibBase;
};

/* AHIsubIFace */
struct AHIsubIFace
{
 struct AHIsubInterfaceData Data;
 static struct AHIsubIFace* CreateIFace(struct Library * _AHIsubBase);
 static void DestroyIFace(struct AHIsubIFace* _iface);
 ULONG AHIsub_AllocAudio(struct TagItem * tagList, struct AHIAudioCtrlDrv * AudioCtrl);
 void  AHIsub_FreeAudio(struct AHIAudioCtrlDrv * AudioCtrl);
 void  AHIsub_Disable(struct AHIAudioCtrlDrv * AudioCtrl);
 void  AHIsub_Enable(struct AHIAudioCtrlDrv * AudioCtrl);
 ULONG AHIsub_Start(ULONG Flags, struct AHIAudioCtrlDrv * AudioCtrl);
 ULONG AHIsub_Update(ULONG Flags, struct AHIAudioCtrlDrv * AudioCtrl);
 ULONG AHIsub_Stop(ULONG Flags, struct AHIAudioCtrlDrv * AudioCtrl);
 ULONG AHIsub_SetVol(UWORD Channel, Fixed Volume, sposition Pan, struct AHIAudioCtrlDrv * AudioCtrl, ULONG Flags);
 ULONG AHIsub_SetFreq(UWORD Channel, ULONG Freq, struct AHIAudioCtrlDrv * AudioCtrl, ULONG Flags);
 ULONG AHIsub_SetSound(UWORD Channel, UWORD Sound, ULONG Offset, LONG Length, struct AHIAudioCtrlDrv * AudioCtrl, ULONG Flags);
 ULONG AHIsub_SetEffect(APTR Effect, struct AHIAudioCtrlDrv * AudioCtrl);
 ULONG AHIsub_LoadSound(UWORD Sound, ULONG Type, APTR Info, struct AHIAudioCtrlDrv * AudioCtrl);
 ULONG AHIsub_UnloadSound(UWORD Sound, struct AHIAudioCtrlDrv * Audioctrl);
 LONG  AHIsub_GetAttr(ULONG Attribute, LONG Argument, LONG DefValue, struct TagItem * tagList, struct AHIAudioCtrlDrv * AudioCtrl);
 LONG  AHIsub_HardwareControl(ULONG Attribute, LONG Argument, struct AHIAudioCtrlDrv * AudioCtrl);
};
