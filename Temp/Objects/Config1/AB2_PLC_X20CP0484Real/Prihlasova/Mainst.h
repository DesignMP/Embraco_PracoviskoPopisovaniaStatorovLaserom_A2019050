#ifndef __AS__TYPE_
#define __AS__TYPE_
static signed long __AS__STRING_CMP(char* pstr1, char* pstr2);
typedef struct {
	unsigned char bit0  : 1;
	unsigned char bit1  : 1;
	unsigned char bit2  : 1;
	unsigned char bit3  : 1;
	unsigned char bit4  : 1;
	unsigned char bit5  : 1;
	unsigned char bit6  : 1;
	unsigned char bit7  : 1;
} _1byte_bit_field_;

typedef struct {
	unsigned short bit0  : 1;
	unsigned short bit1  : 1;
	unsigned short bit2  : 1;
	unsigned short bit3  : 1;
	unsigned short bit4  : 1;
	unsigned short bit5  : 1;
	unsigned short bit6  : 1;
	unsigned short bit7  : 1;
	unsigned short bit8  : 1;
	unsigned short bit9  : 1;
	unsigned short bit10 : 1;
	unsigned short bit11 : 1;
	unsigned short bit12 : 1;
	unsigned short bit13 : 1;
	unsigned short bit14 : 1;
	unsigned short bit15 : 1;
} _2byte_bit_field_;

typedef struct {
	unsigned long bit0  : 1;
	unsigned long bit1  : 1;
	unsigned long bit2  : 1;
	unsigned long bit3  : 1;
	unsigned long bit4  : 1;
	unsigned long bit5  : 1;
	unsigned long bit6  : 1;
	unsigned long bit7  : 1;
	unsigned long bit8  : 1;
	unsigned long bit9  : 1;
	unsigned long bit10 : 1;
	unsigned long bit11 : 1;
	unsigned long bit12 : 1;
	unsigned long bit13 : 1;
	unsigned long bit14 : 1;
	unsigned long bit15 : 1;
	unsigned long bit16 : 1;
	unsigned long bit17 : 1;
	unsigned long bit18 : 1;
	unsigned long bit19 : 1;
	unsigned long bit20 : 1;
	unsigned long bit21 : 1;
	unsigned long bit22 : 1;
	unsigned long bit23 : 1;
	unsigned long bit24 : 1;
	unsigned long bit25 : 1;
	unsigned long bit26 : 1;
	unsigned long bit27 : 1;
	unsigned long bit28 : 1;
	unsigned long bit29 : 1;
	unsigned long bit30 : 1;
	unsigned long bit31 : 1;
} _4byte_bit_field_;
#endif

#ifndef __AS__TYPE_ParametreUzivatelovTyp
#define __AS__TYPE_ParametreUzivatelovTyp
typedef struct ParametreUzivatelovTyp
{	plcstring Meno[51];
	plcstring Heslo[51];
	unsigned short UrovenUzivatela;
} ParametreUzivatelovTyp;
#endif

struct TON
{	plctime PT;
	plctime ET;
	plctime StartTime;
	unsigned long Restart;
	plcbit IN;
	plcbit Q;
	plcbit M;
};
_BUR_PUBLIC void TON(struct TON* inst);
#ifndef __AS__TYPE_SequenceControlTyp
#define __AS__TYPE_SequenceControlTyp
typedef struct SequenceControlTyp
{	plcstring StepName[81];
	unsigned short Step;
	plcbit Switch1;
	plcbit Switch2;
	plcbit Switch3;
	plcbit ResetStep;
	plcbit LastStep;
	struct TON IdleTime;
	struct TON AlarmTime;
} SequenceControlTyp;
#endif

#ifndef __AS__TYPE_MpRecipeErrorEnum
#define __AS__TYPE_MpRecipeErrorEnum
typedef enum MpRecipeErrorEnum
{	mpRECIPE_NO_ERROR = 0,
	mpRECIPE_ERR_ACTIVATION = -1064239103,
	mpRECIPE_ERR_MPLINK_NULL = -1064239102,
	mpRECIPE_ERR_MPLINK_INVALID = -1064239101,
	mpRECIPE_ERR_MPLINK_CHANGED = -1064239100,
	mpRECIPE_ERR_MPLINK_CORRUPT = -1064239099,
	mpRECIPE_ERR_MPLINK_IN_USE = -1064239098,
	mpRECIPE_ERR_CONFIG_INVALID = -1064239091,
	mpRECIPE_ERR_SAVE_DATA = -1064140799,
	mpRECIPE_ERR_LOAD_DATA = -1064140798,
	mpRECIPE_ERR_INVALID_FILE_DEV = -1064140797,
	mpRECIPE_ERR_INVALID_FILE_NAME = -1064140796,
	mpRECIPE_ERR_CMD_IN_PROGRESS = -1064140795,
	mpRECIPE_WRN_SAVE_WITH_WARN = -2137882618,
	mpRECIPE_WRN_LOAD_WITH_WARN = -2137882617,
	mpRECIPE_ERR_SAVE_WITH_ERRORS = -1064140792,
	mpRECIPE_ERR_LOAD_WITH_ERRORS = -1064140791,
	mpRECIPE_ERR_MISSING_RECIPE = -1064140790,
	mpRECIPE_ERR_MISSING_MPFILE = -1064140789,
	mpRECIPE_ERR_INVALID_SORT_ORDER = -1064140788,
	mpRECIPE_WRN_MISSING_UICONNECT = -2137882611,
	mpRECIPE_ERR_INVALID_PV_NAME = -1064140786,
	mpRECIPE_ERR_INVALID_LOAD_TYPE = -1064140785,
	mpRECIPE_ERR_LISTING_FILES = -1064140784,
	mpRECIPE_ERR_PV_NAME_NULL = -1064140783,
	mpRECIPE_WRN_NO_PV_REGISTERED = -2137882606,
	mpRECIPE_ERR_SYNC_SAVE_ACTIVE = -1064140781,
	mpRECIPE_ERR_DELETING_FILE = -1064140780,
	mpRECIPE_WRN_EMPTY_RECIPE = -2137882603,
	mpRECIPE_INF_WAIT_RECIPE_FB = 1083342870,
	mpRECIPE_ERR_RENAMING_FILE = -1064140777,
	mpRECIPE_WRN_NO_PV_FOUND = -2137882600,
	mpRECIPE_WRN_LIST_SIZE = -2137882599,
} MpRecipeErrorEnum;
#endif

#ifndef __AS__TYPE_MpComSeveritiesEnum
#define __AS__TYPE_MpComSeveritiesEnum
typedef enum MpComSeveritiesEnum
{	mpCOM_SEV_SUCCESS = 0,
	mpCOM_SEV_INFORMATIONAL = 1,
	mpCOM_SEV_WARNING = 2,
	mpCOM_SEV_ERROR = 3,
} MpComSeveritiesEnum;
#endif

#ifndef __AS__TYPE_MpRecipeStatusIDType
#define __AS__TYPE_MpRecipeStatusIDType
typedef struct MpRecipeStatusIDType
{	MpRecipeErrorEnum ID;
	MpComSeveritiesEnum Severity;
	unsigned short Code;
} MpRecipeStatusIDType;
#endif

#ifndef __AS__TYPE_MpRecipeDiagType
#define __AS__TYPE_MpRecipeDiagType
typedef struct MpRecipeDiagType
{	MpRecipeStatusIDType StatusID;
} MpRecipeDiagType;
#endif

#ifndef __AS__TYPE_MpRecipeInfoType
#define __AS__TYPE_MpRecipeInfoType
typedef struct MpRecipeInfoType
{	MpRecipeDiagType Diag;
} MpRecipeInfoType;
#endif

#ifndef __AS__TYPE_MpRecipeXmlInfoType
#define __AS__TYPE_MpRecipeXmlInfoType
typedef struct MpRecipeXmlInfoType
{	unsigned long FileSize;
	unsigned long PendingSync;
	MpRecipeDiagType Diag;
	plcstring LastLoadedRecipe[256];
} MpRecipeXmlInfoType;
#endif

#ifndef __AS__TYPE_MpRecipeXmlHeaderType
#define __AS__TYPE_MpRecipeXmlHeaderType
typedef struct MpRecipeXmlHeaderType
{	plcstring Name[101];
	plcstring Description[256];
	plcstring Version[21];
	plcdt DateTime;
} MpRecipeXmlHeaderType;
#endif

#ifndef __AS__TYPE_MpRecipeXmlLoadEnum
#define __AS__TYPE_MpRecipeXmlLoadEnum
typedef enum MpRecipeXmlLoadEnum
{	mpRECIPE_XML_LOAD_ALL = 0,
	mpRECIPE_XML_LOAD_HEADER = 1,
} MpRecipeXmlLoadEnum;
#endif

#ifndef __AS__TYPE_MpComIdentType
#define __AS__TYPE_MpComIdentType
typedef struct MpComIdentType
{	unsigned long Internal[2];
} MpComIdentType;
#endif

#ifndef __AS__TYPE_MpComInternalDataType
#define __AS__TYPE_MpComInternalDataType
typedef struct MpComInternalDataType
{	unsigned long pObject;
	unsigned long State;
} MpComInternalDataType;
#endif

_BUR_PUBLIC signed long CheckBounds(signed long index, signed long lower, signed long upper);
_BUR_PUBLIC plcbit SequenceControl(struct SequenceControlTyp(* SC));
struct MpRecipeRegPar
{	struct MpComIdentType(* MpLink);
	plcstring(* PVName)[101];
	plcstring(* Category)[51];
	signed long StatusID;
	MpRecipeInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Active;
	plcbit Error;
	plcbit UpdateNotification;
};
_BUR_PUBLIC void MpRecipeRegPar(struct MpRecipeRegPar* inst);
struct MpRecipeXml
{	struct MpComIdentType(* MpLink);
	plcstring(* DeviceName)[51];
	plcstring(* FileName)[256];
	struct MpRecipeXmlHeaderType(* Header);
	plcstring(* Category)[51];
	MpRecipeXmlLoadEnum LoadType;
	signed long StatusID;
	MpRecipeXmlInfoType Info;
	MpComInternalDataType Internal;
	plcbit Enable;
	plcbit ErrorReset;
	plcbit Load;
	plcbit Save;
	plcbit UpdateNotification;
	plcbit Active;
	plcbit Error;
	plcbit CommandBusy;
	plcbit CommandDone;
};
_BUR_PUBLIC void MpRecipeXml(struct MpRecipeXml* inst);
_BUR_LOCAL plcstring strCategory[81];
_BUR_LOCAL signed short i;
_BUR_LOCAL signed short old_a;
_BUR_LOCAL plcbit MoveUP;
_BUR_LOCAL plcbit MoveDown;
_BUR_LOCAL signed short IndexZoznam;
_BUR_LOCAL signed short b;
_GLOBAL struct MpRecipeXml MpRecipeXml_1;
_GLOBAL struct MpRecipeRegPar MpRecipeRegPar_1;
_GLOBAL struct ParametreUzivatelovTyp Uzivatel[51];
_GLOBAL plcstring ZoznamUzivatelov[51][51];
_GLOBAL plcstring MenoUzivatela[51];
_GLOBAL plcstring HesloUzivatela[51];
_GLOBAL unsigned short UrovenUzivatela;
_GLOBAL plcstring ZadaneMenoUzivatela[51];
_GLOBAL plcstring ZadaneHesloUzivatela[51];
_GLOBAL plcstring ZvolenyUzivatel[51];
_GLOBAL unsigned short ZvolenaUroven;
_GLOBAL unsigned char TP_ZobrazPopUpPrihlasenie;
_GLOBAL plcbit UlozUzivatelov;
_GLOBAL plcbit PrihlasUzivatela;
_GLOBAL plcbit VymazUzivatela;
_GLOBAL plcbit OdhlasUzivatela;
_GLOBAL SequenceControlTyp SC_Uzivatelia;
_GLOBAL MpComIdentType gUzivatelXmlLink;
