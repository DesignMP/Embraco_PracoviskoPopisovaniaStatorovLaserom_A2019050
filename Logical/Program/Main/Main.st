
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	//Volanie podprogramov//
	OvlSafety;
	
	//Zariadenie stav Automat//
	IF VstupnyOddelovac.Automat OR Popisovanie.Automat OR Checker.Automat THEN
		Zariadenie.STAV.Automat:= TRUE;
	ELSE	
		Zariadenie.STAV.Automat:= FALSE;
		Zariadenie.STAV.UkoncenieCyklu:= FALSE;
	END_IF	
	
	//Zariadenie stav Manual//
	IF VstupnyOddelovac.Manual OR Popisovanie.Manual OR Checker.Manual THEN
		Zariadenie.STAV.Manual:= TRUE;
	ELSE	
		Zariadenie.STAV.Manual:= FALSE;
	END_IF
	
	//Zariadenie stav po inicializacii//
	IF VstupnyOddelovac.STAV.PoINIT AND Popisovanie.STAV.PoINIT AND Checker.STAV.PoINIT THEN
		Zariadenie.STAV.PoINIT:= TRUE;
	ELSE
		Zariadenie.STAV.PoINIT:= FALSE;
	END_IF
	
	//Spustenie režimu automat//
	IF EDGEPOS(Zariadenie.IN.TlacitkoSTART)THEN
		IF Safety.STAV.ZonaCS_Aktivna AND NOT NastalaPorucha AND Safety.STAV.ZonaVnutroBunky_Aktivna AND NOT Zariadenie.STAV.UkoncenieCyklu AND Zariadenie.IN.TlakVzduchu_OK AND NOT Zariadenie.STAV.Manual AND Zariadenie.STAV.Moduly_OK AND Vizu.CisloAktualnejObrazovky = 2 AND NOT Zariadenie.STAV.NezvolenaReceptura AND NOT Zariadenie.KoniecModelu THEN
			VstupnyOddelovac.Automat:= TRUE;
			Popisovanie.Automat:= TRUE;
			Checker.Automat:= TRUE;
		END_IF	
	END_IF	
	
	
	//Spustenie režimu manual//
	IF Zariadenie.Manual THEN
		IF Safety.STAV.ZonaCS_Aktivna AND NOT NastalaPorucha AND NOT Zariadenie.STAV.Automat THEN
			VstupnyOddelovac.Manual:= TRUE;
			Popisovanie.Manual:= TRUE;
			Checker.Manual:= TRUE;
		END_IF	
		Zariadenie.Manual:= FALSE;
	END_IF	
	
	
	//Resetovanie zariadenia pri stlaèení tlaèítka režim automat//
	IF Vizu.TlacitkoRezimAutomat THEN
		IF NOT Zariadenie.STAV.Automat THEN
			Zariadenie.Reset:= TRUE;
		END_IF
		Vizu.TlacitkoRezimAutomat:= FALSE;
	END_IF	
	
	
	
	
	//Reset zariadenia//
	IF Zariadenie.Reset THEN
		VstupnyOddelovac.Reset:= TRUE;
		Popisovanie.Reset:= TRUE;
		Checker.Reset:= TRUE;
		Zariadenie.Reset:= FALSE;
	END_IF	
	
	//Resetovanie zariadenia pri stlaèení tlaèítka režim automat//
	IF Vizu.TlacitkoRezimAutomat THEN
		IF NOT Zariadenie.STAV.Automat THEN
			Zariadenie.Reset:= TRUE;
		END_IF
		Vizu.TlacitkoRezimAutomat:= FALSE;
	END_IF	
	
	
	//Ukonèenie cyklu zariadenia//
	IF EDGEPOS(Zariadenie.IN.TlacitkoSTOP) OR Zariadenie.KoniecCyklu THEN
		IF Zariadenie.STAV.PoINIT AND NOT Zariadenie.STAV.UkoncenieCyklu THEN
			VstupnyOddelovac.KoniecCyklu:= TRUE;
			Popisovanie.KoniecCyklu:= TRUE;
			Checker.KoniecCyklu:= TRUE;
			Zariadenie.STAV.UkoncenieCyklu:= TRUE;
		END_IF
		Zariadenie.KoniecCyklu:= FALSE;
	END_IF	
	
	//Stav externé moduly OK//
	Zariadenie.STAV.Moduly_OK:= Zariadenie.STAV.KOM_Modul_BC1_OK AND Zariadenie.STAV.KOM_Modul_DI1_OK AND Zariadenie.STAV.KOM_Modul_SI1_OK AND Zariadenie.STAV.KOM_Modul_XV_OK (*AND Zariadenie.STAV.KOM_Checker_OK*);
	

	//Príznak nezvolená receptura//
	IF ZvolenyNazovStatora = '' AND NOT Zariadenie.PriechodnyRezim THEN
		Zariadenie.STAV.NezvolenaReceptura:= TRUE;
		Vizu.Zobraz_HlasenieNezvolenaRecept:= 0;
	ELSE	
		Zariadenie.STAV.NezvolenaReceptura:= FALSE;
		Vizu.Zobraz_HlasenieNezvolenaRecept:= 1;
	END_IF	
	
	
	
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

