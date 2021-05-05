#ifndef __AS__TYPE_
#define __AS__TYPE_
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

#ifndef __AS__TYPE_CheckerIN_typ
#define __AS__TYPE_CheckerIN_typ
typedef struct CheckerIN_typ
{	plcbit TlacitkoBANNER;
	plcbit Checker_OUT0;
	plcbit Checker_OUT1;
	plcbit Checker_OUT2;
	plcbit Checker_OUT3;
	plcbit Stoper1_ZASUNUTY;
	plcbit Stoper1_VYSUNUTY;
	plcbit Stoper2_ZASUNUTY;
	plcbit Stoper2_VYSUNUTY;
	plcbit ZasobaPredStoprom1;
	plcbit Stoper1_PritomnostPaletky;
	plcbit Stoper2_PritomnostPaletky;
	plcbit Stoper2_PritomnostStatora;
	plcbit ZaplnenieVystupnejTrate;
} CheckerIN_typ;
#endif

#ifndef __AS__TYPE_CheckerOUT_typ
#define __AS__TYPE_CheckerOUT_typ
typedef struct CheckerOUT_typ
{	plcbit BANNER_ZelenaLED;
	plcbit BANNER_CervenaLED;
	plcbit Checker_IN0;
	plcbit Checker_IN1;
	plcbit Stoper1_VYSUN;
	plcbit Stoper1_ZASUN;
	plcbit Stoper2_VYSUN;
	plcbit Stoper2_ZASUN;
} CheckerOUT_typ;
#endif

#ifndef __AS__TYPE_CheckerCOM_typ
#define __AS__TYPE_CheckerCOM_typ
typedef struct CheckerCOM_typ
{	unsigned char ControlWord;
	unsigned char StatusWord;
	unsigned char ResultStatus;
	unsigned char ResultControl;
	unsigned short ResultData;
} CheckerCOM_typ;
#endif

#ifndef __AS__TYPE_CheckerPAR_typ
#define __AS__TYPE_CheckerPAR_typ
typedef struct CheckerPAR_typ
{	unsigned long PAR_0;
} CheckerPAR_typ;
#endif

#ifndef __AS__TYPE_CheckerSTAV_typ
#define __AS__TYPE_CheckerSTAV_typ
typedef struct CheckerSTAV_typ
{	plcbit PoINIT;
	plcbit Stopre_PoziciaNAVAZANIE;
	plcbit Stopre_PoziciaVYVAZANIE;
	plcbit TRIGER_Ready;
	plcbit BUSY;
	plcbit Vysledok_READY;
	plcbit Vysledok_OK;
	plcbit Vysledok_NG;
} CheckerSTAV_typ;
#endif

#ifndef __AS__TYPE_Checker_typ
#define __AS__TYPE_Checker_typ
typedef struct Checker_typ
{	plcbit Automat;
	plcbit Manual;
	plcbit Reset;
	plcbit KoniecCyklu;
	CheckerIN_typ IN;
	CheckerOUT_typ OUT;
	CheckerCOM_typ COM;
	CheckerPAR_typ PAR;
	CheckerSTAV_typ STAV;
	plcbit TRIGER_Enable;
	plcbit TRIGER;
	plcbit Vysledok_POTVRDENIE;
	plcbit KAMERA_OFF;
} Checker_typ;
#endif

_GLOBAL Checker_typ Checker;
