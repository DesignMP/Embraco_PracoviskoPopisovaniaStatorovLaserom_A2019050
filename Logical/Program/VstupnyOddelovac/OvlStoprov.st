
ACTION OvlStoprov: 

	
	//Pozice stoprov//
	VstupnyOddelovac.STAV.Stopre_PoziciaNAVAZANIE:= VstupnyOddelovac.IN.Stoper1_ZASUNUTY AND VstupnyOddelovac.IN.Stoper2_VYSUNUTY;
	VstupnyOddelovac.STAV.Stopre_PoziciaVYVAZANIE:= VstupnyOddelovac.IN.Stoper1_VYSUNUTY AND VstupnyOddelovac.IN.Stoper2_ZASUNUTY;
	
	
	
	//Volanie funkcie SequenceControl//
	SequenceControl(SC:= SC_OvlStoprov);
	
	
	
	CASE SC_OvlStoprov.Step OF
		
		0:
			SC_OvlStoprov.StepName:= '0 - Nulovanie';
			Stopre_pozNAVAZANIE:= FALSE;
			Stopre_pozVYVAZANIE:= FALSE;
			VstupnyOddelovac.OUT.Stoper1_VYSUN:= FALSE;
			VstupnyOddelovac.OUT.Stoper1_ZASUN:= FALSE;
			VstupnyOddelovac.OUT.Stoper2_VYSUN:= FALSE;
			VstupnyOddelovac.OUT.Stoper2_ZASUN:= FALSE;
			IF SC_VstupnyOddelovac.Step <> 0 THEN
				SC_OvlStoprov.ResetStep:= TRUE;
				SC_OvlStoprov.Step:= 1;
			END_IF
		
		1:
			SC_OvlStoprov.StepName:= '1 - Rozhodnutie o cinnosti';
			IF Stopre_pozNAVAZANIE THEN
				SC_OvlStoprov.Step:= 10;
			ELSIF Stopre_pozVYVAZANIE THEN
				SC_OvlStoprov.Step:= 20;
			END_IF
	
		10:
			SC_OvlStoprov.StepName:= '10 - Prepnutie oddelovaca do pozicie navazania';
			SC_OvlStoprov.IdleTime.PT:= T#3s;
			SC_OvlStoprov.AlarmTime.PT:= T#3s;
			
			IF VstupnyOddelovac.Automat THEN
				SC_OvlStoprov.AlarmTime.IN:= TRUE;
			ELSE	
				SC_OvlStoprov.IdleTime.IN:= TRUE;
			END_IF
		
			IF NOT SC_OvlStoprov.Switch1 THEN
				VstupnyOddelovac.OUT.Stoper1_ZASUN:= TRUE;
				VstupnyOddelovac.OUT.Stoper2_VYSUN:= TRUE;
				SC_OvlStoprov.Switch1:= TRUE;
			END_IF
		
			IF SC_OvlStoprov.AlarmTime.Q THEN
				IF NOT VstupnyOddelovac.IN.Stoper1_ZASUNUTY THEN
					Alarmy[11]:= TRUE;
				ELSIF NOT VstupnyOddelovac.IN.Stoper2_VYSUNUTY THEN
					Alarmy[14]:= TRUE;
				END_IF	
				PoruchaVstupnehoOddelovaca:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF
		
			IF VstupnyOddelovac.STAV.Stopre_PoziciaNAVAZANIE OR SC_OvlStoprov.IdleTime.Q THEN
				SC_OvlStoprov.ResetStep:= TRUE;
				SC_OvlStoprov.Step:= 0;
			END_IF
		
		
		20:
			SC_OvlStoprov.StepName:= '20 - Prepnutie oddelovaca do pozicie vyvazania';
			SC_OvlStoprov.IdleTime.PT:= T#3s;
			SC_OvlStoprov.AlarmTime.PT:= T#3s;
			
			IF VstupnyOddelovac.Automat THEN
				SC_OvlStoprov.AlarmTime.IN:= TRUE;
			ELSE	
				SC_OvlStoprov.IdleTime.IN:= TRUE;
			END_IF
		
			IF NOT SC_OvlStoprov.Switch1 THEN
				VstupnyOddelovac.OUT.Stoper1_VYSUN:= TRUE;
				VstupnyOddelovac.OUT.Stoper2_ZASUN:= TRUE;
				SC_OvlStoprov.Switch1:= TRUE;
			END_IF
		
			IF SC_OvlStoprov.AlarmTime.Q THEN
				IF NOT VstupnyOddelovac.IN.Stoper1_VYSUNUTY THEN
					Alarmy[13]:= TRUE;
				ELSIF NOT VstupnyOddelovac.IN.Stoper2_ZASUNUTY THEN
					Alarmy[12]:= TRUE;
				END_IF	
				PoruchaVstupnehoOddelovaca:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF
		
			IF VstupnyOddelovac.STAV.Stopre_PoziciaVYVAZANIE OR SC_OvlStoprov.IdleTime.Q THEN
				SC_OvlStoprov.ResetStep:= TRUE;
				SC_OvlStoprov.Step:= 0;
			END_IF
	
	
	
	END_CASE
	
	
END_ACTION
