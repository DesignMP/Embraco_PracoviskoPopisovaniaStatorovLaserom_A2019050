
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	//Volanie podprogramov//
	OvlStoprov;
	
	
	//Volanie funkcie SequenceControl//
	SequenceControl(SC:= SC_VstupnyOddelovac);
	
	 
	
	//Reset sekcie //
	IF VstupnyOddelovac.Reset OR PoruchaVstupnehoOddelovaca THEN
		SC_VstupnyOddelovac.Step:= 0;
	END_IF
	
	
	CASE SC_VstupnyOddelovac.Step OF 
	
		0:
			SC_VstupnyOddelovac.StepName:='0 - Nulovanie';
			SC_OvlStoprov.Step:= 0;
			VstupnyOddelovac.Automat:= FALSE;
			VstupnyOddelovac.KoniecCyklu:= FALSE;
			VstupnyOddelovac.Manual:= FALSE;
			VstupnyOddelovac.Reset:= FALSE;
			VstupnyOddelovac.STAV.PoINIT:= FALSE;
						
			IF Safety.STAV.ZonaCS_Aktivna AND NOT PoruchaVstupnehoOddelovaca AND Zariadenie.IN.TlakVzduchu_OK THEN
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 1;
			END_IF
	
		1:
			SC_VstupnyOddelovac.StepName:='1 - Cakam na spustenie vyroby';
			IF VstupnyOddelovac.Automat THEN
				SC_VstupnyOddelovac.Step:= 2;
			ELSIF VstupnyOddelovac.Manual THEN
				SC_VstupnyOddelovac.Step:= 700;
			END_IF
			
		
		//********************************************************Inicializácia****************************************************************************//
	
		2:
			SC_VstupnyOddelovac.StepName:='2 - Inicializacia - cakam na spustenie inicializacie';
			SC_VstupnyOddelovac.IdleTime.PT:= T#500ms;
			SC_VstupnyOddelovac.AlarmTime.PT:= T#5s;
			
			SC_VstupnyOddelovac.IdleTime.IN:= TRUE;
						
			IF SC_VstupnyOddelovac.IdleTime.Q THEN
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 3;
			END_IF
		
		
		3:
			SC_VstupnyOddelovac.StepName:='3 - Inicializacia - rozhodnutie o inicializacii';
			SC_VstupnyOddelovac.IdleTime.PT:= T#500ms;
			SC_VstupnyOddelovac.AlarmTime.PT:= T#5s;
		
			IF VstupnyOddelovac.STAV.Stopre_PoziciaNAVAZANIE THEN
				VstupnyOddelovac.STAV.PoINIT:= TRUE;
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 100;
			ELSIF VstupnyOddelovac.STAV.Stopre_PoziciaVYVAZANIE THEN
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 5;
			ELSE
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 5;
			END_IF	
		
		5:
			SC_VstupnyOddelovac.StepName:='5 - Inicializacia - cakam na odchod paletky z 2 stopra';
			SC_VstupnyOddelovac.IdleTime.PT:= T#1s;
			SC_VstupnyOddelovac.AlarmTime.PT:= T#5s;
		
			SC_VstupnyOddelovac.IdleTime.IN:= NOT VstupnyOddelovac.IN.Stoper2_PritomnostPaletky;
			
			IF SC_VstupnyOddelovac.IdleTime.Q THEN
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 7;
			END_IF
			
		7:
			SC_VstupnyOddelovac.StepName:='7 - Inicializacia - preklopenie stoprov do pozicie navazania';
			SC_VstupnyOddelovac.IdleTime.PT:= T#500ms;
			SC_VstupnyOddelovac.AlarmTime.PT:= T#5s;
			
			IF NOT SC_VstupnyOddelovac.Switch1 THEN
				Stopre_pozNAVAZANIE:= TRUE;
				SC_VstupnyOddelovac.Switch1:= TRUE;
			END_IF
			
			IF VstupnyOddelovac.STAV.Stopre_PoziciaNAVAZANIE THEN
				VstupnyOddelovac.STAV.PoINIT:= TRUE;
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 100;
			END_IF	
			
			
			
		
		
		//********************************************************Automatický režim****************************************************************************//
				
		100:
			SC_VstupnyOddelovac.StepName:='100 - Automaticky Rezim - cakam na pritomnost paletky na 2 stopri a vyvezenie na stoper zdvizky';
			SC_VstupnyOddelovac.IdleTime.PT:= T#100ms;
			SC_VstupnyOddelovac.AlarmTime.PT:= T#5s;
		
			SC_VstupnyOddelovac.IdleTime.IN:= NOT Popisovanie.IN.StoperZdvizky_PritomnostPaletky;	
		
			IF VstupnyOddelovac.KoniecCyklu THEN
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 0;
			ELSIF Zariadenie.KoniecModelu THEN
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 0;
			ELSIF Popisovanie.STAV.PoINIT THEN
				IF VstupnyOddelovac.IN.Stoper2_PritomnostPaletky AND Popisovanie.IN.Zdvizka_ZASUNUTA AND Popisovanie.IN.StoperZdvizky_VYSUNUTY AND NOT Popisovanie.IN.StoperZdvizky_PritomnostPaletky THEN
					SC_VstupnyOddelovac.ResetStep:= TRUE;
					SC_VstupnyOddelovac.Step:= 101;
				ELSIF VstupnyOddelovac.IN.Stoper2_PritomnostPaletky AND Popisovanie.IN.Zdvizka_ZASUNUTA AND SC_VstupnyOddelovac.IdleTime.Q THEN
					SC_VstupnyOddelovac.ResetStep:= TRUE;
					SC_VstupnyOddelovac.Step:= 101;
				END_IF
			END_IF
		
		
		101:
			SC_VstupnyOddelovac.StepName:='101 - Automaticky Rezim - preklopenie stoprov do pozicie vyvazania';
			SC_VstupnyOddelovac.IdleTime.PT:= T#500ms;
			SC_VstupnyOddelovac.AlarmTime.PT:= T#5s;
		
		
			IF NOT SC_VstupnyOddelovac.Switch1 THEN
				Stopre_pozVYVAZANIE:= TRUE;
				SC_VstupnyOddelovac.Switch1:= TRUE;
			END_IF
			
			IF VstupnyOddelovac.STAV.Stopre_PoziciaVYVAZANIE THEN
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 105;
			END_IF
		
		
		105:
			SC_VstupnyOddelovac.StepName:='105 - Automaticky Rezim - cakam na odchod paletky z 2 stopra';
			SC_VstupnyOddelovac.IdleTime.PT:= T#500ms;
			SC_VstupnyOddelovac.AlarmTime.PT:= T#5s;
		
		
			SC_VstupnyOddelovac.IdleTime.IN:= NOT VstupnyOddelovac.IN.Stoper2_PritomnostPaletky;
			
			IF SC_VstupnyOddelovac.IdleTime.Q THEN
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 108;
			END_IF
		
		
			
		
		108:
			SC_VstupnyOddelovac.StepName:='108 - Automaticky Rezim - preklopenie stoprov do pozicie navazania';
			SC_VstupnyOddelovac.IdleTime.PT:= T#500ms;
			SC_VstupnyOddelovac.AlarmTime.PT:= T#5s;
			
			IF NOT SC_VstupnyOddelovac.Switch1 THEN
				Stopre_pozNAVAZANIE:= TRUE;
				SC_VstupnyOddelovac.Switch1:= TRUE;
			END_IF
			
			IF VstupnyOddelovac.STAV.Stopre_PoziciaNAVAZANIE THEN
				SC_VstupnyOddelovac.ResetStep:= TRUE;
				SC_VstupnyOddelovac.Step:= 100;
			END_IF	
		
		
	
			//*******************************************************Manuálny režim*******************************************************************************//
		700:
			SC_VstupnyOddelovac.StepName:='700 - Manualny Rezim';
			SC_VstupnyOddelovac.IdleTime.PT:= T#8s;
			SC_VstupnyOddelovac.AlarmTime.PT:= T#5s;
		
		
		
	
	END_CASE
	
	
	
	
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

