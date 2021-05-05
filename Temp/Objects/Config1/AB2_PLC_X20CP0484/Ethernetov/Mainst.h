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

struct TcpOpen
{	unsigned long pIfAddr;
	unsigned short port;
	unsigned long options;
	unsigned short status;
	unsigned long ident;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void TcpOpen(struct TcpOpen* inst);
struct TcpClient
{	unsigned long ident;
	unsigned long pServer;
	unsigned short portserv;
	unsigned short status;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void TcpClient(struct TcpClient* inst);
struct TcpRecv
{	unsigned long ident;
	unsigned long pData;
	unsigned long datamax;
	unsigned long flags;
	unsigned short status;
	unsigned long recvlen;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void TcpRecv(struct TcpRecv* inst);
struct TcpSend
{	unsigned long ident;
	unsigned long pData;
	unsigned long datalen;
	unsigned long flags;
	unsigned short status;
	unsigned long sentlen;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void TcpSend(struct TcpSend* inst);
struct TcpIoctl
{	unsigned long ident;
	unsigned long ioctl;
	unsigned long pData;
	unsigned long datalen;
	unsigned short status;
	unsigned long outlen;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void TcpIoctl(struct TcpIoctl* inst);
struct TcpClose
{	unsigned long ident;
	unsigned long how;
	unsigned short status;
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	plcbit enable;
};
_BUR_PUBLIC void TcpClose(struct TcpClose* inst);
#ifndef __AS__TYPE_tcpLINGER_typ
#define __AS__TYPE_tcpLINGER_typ
typedef struct tcpLINGER_typ
{	unsigned long lOnOff;
	unsigned long lLinger;
} tcpLINGER_typ;
#endif

#ifndef __AS__TYPE_Client_typ
#define __AS__TYPE_Client_typ
typedef struct Client_typ
{	unsigned short sStep;
	struct TcpOpen TcpOpen_0;
	struct TcpClient TcpClient_0;
	struct TcpRecv TcpRecv_0;
	struct TcpSend TcpSend_0;
	struct TcpIoctl TcpIoctl_0;
	struct TcpClose TcpClose_0;
	tcpLINGER_typ linger_opt;
	unsigned long recv_timeout;
	unsigned long TcpOpen_timeout;
	unsigned long TcpClient_timeout;
} Client_typ;
#endif

#ifndef __AS__TYPE_LaserCommands_typ
#define __AS__TYPE_LaserCommands_typ
typedef struct LaserCommands_typ
{	plcbit OdosliDataSpravy;
	plcbit ResetPoruchy;
	plcbit VyberSpravuLasera;
} LaserCommands_typ;
#endif

#ifndef __AS__TYPE_LaserStatus_typ
#define __AS__TYPE_LaserStatus_typ
typedef struct LaserStatus_typ
{	plcbit PoruchaOtvoreniaKomunikacie;
	plcbit PoruchaOdoslaniaDat;
	plcbit PoruchaZatvoreniaKomunikacie;
	plcbit PoruchaSpojenia_s_Laserom;
	plcbit PoruchaPrijatiaDat;
	plcbit OdoslanieDatSpravy_OK;
	plcbit OdoslanieDatSpravy_NG;
	plcbit VyberSpravy_OK;
	plcbit VyberSpravy_NG;
	plcbit StrataKomunikacie;
	signed long VysledokPorovnaniaOdpovede;
} LaserStatus_typ;
#endif

#ifndef __AS__TYPE_LaserData_typ
#define __AS__TYPE_LaserData_typ
typedef struct LaserData_typ
{	unsigned char Data;
} LaserData_typ;
#endif

#ifndef __AS__TYPE_Laser_typ
#define __AS__TYPE_Laser_typ
typedef struct Laser_typ
{	LaserCommands_typ Commands;
	LaserStatus_typ Status;
	LaserData_typ Data;
} Laser_typ;
#endif

_BUR_PUBLIC unsigned long brsmemset(unsigned long pDest, unsigned char value, unsigned long length);
_BUR_PUBLIC unsigned long brsmemcpy(unsigned long pDest, unsigned long pSrc, unsigned long length);
_BUR_PUBLIC signed long brsmemcmp(unsigned long pMem1, unsigned long pMem2, unsigned long length);
_BUR_PUBLIC signed long CheckBounds(signed long index, signed long lower, signed long upper);
_GLOBAL Client_typ Client;
_GLOBAL Laser_typ Laser;
_GLOBAL unsigned char Laser_DataSpravy[48];
_GLOBAL unsigned char Laser_NazovSpravy[13];
_GLOBAL unsigned char Laser_Sprava[51];
_GLOBAL unsigned char Laser_Odpoved[51];
_GLOBAL unsigned char OK_OdpovedNaDataSpravy[51];
_GLOBAL unsigned char OK_OdpovedNaVyberSpravy[51];
_GLOBAL unsigned short ERR_FUB_BUSY;
_GLOBAL unsigned short tcpERR_NO_DATA;
_GLOBAL unsigned short tcpERR_SENTLEN;
_GLOBAL unsigned short tcpERR_INVALID;
_GLOBAL unsigned short tcpERR_NOT_CONNECTED;
_GLOBAL unsigned long tcpSO_LINGER_SET;
