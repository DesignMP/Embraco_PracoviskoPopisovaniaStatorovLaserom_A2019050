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
_BUR_LOCAL signed short i;
_BUR_LOCAL struct TON CasPotvrdeniaAlarmu;
_BUR_LOCAL plcbit ZapniHukacku;
_BUR_LOCAL struct TON CasMeraniaTlakuVzduchu;
_BUR_LOCAL struct TON CasMeraniaModuluXV1;
