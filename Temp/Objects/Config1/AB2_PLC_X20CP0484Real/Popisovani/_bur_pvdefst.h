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

_BUR_LOCAL SequenceControlTyp SC_OvlStopra;
_BUR_LOCAL plcbit StoperZdvizky_VYSUN;
_BUR_LOCAL plcbit StoperZdvizky_ZASUN;
_BUR_LOCAL SequenceControlTyp SC_OvlZdvizky;
_BUR_LOCAL plcbit Zdvizku_VYSUN;
_BUR_LOCAL plcbit Zdvizku_ZASUN;
_BUR_LOCAL unsigned char PoleUSINT[20];
_BUR_LOCAL unsigned long length;
_BUR_LOCAL plcstring PosledneZnaky[5];
_BUR_LOCAL unsigned char i;
