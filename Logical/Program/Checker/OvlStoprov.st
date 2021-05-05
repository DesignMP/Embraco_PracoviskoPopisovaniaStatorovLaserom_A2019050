
ACTION OvlStoprov: 

	//Pozície stoprov//
	Checker.STAV.Stopre_PoziciaNAVAZANIE:= Checker.IN.Stoper1_ZASUNUTY AND Checker.IN.Stoper2_VYSUNUTY;
	Checker.STAV.Stopre_PoziciaVYVAZANIE:= Checker.IN.Stoper1_VYSUNUTY AND Checker.IN.Stoper2_ZASUNUTY;
	
	
	
	//Volanie funkcie SequenceControl//
	SequenceControl(SC:= SC_OvlStoprov);
	
	
	
	CASE SC_OvlStoprov.Step OF
		
		0:
			SC_OvlStoprov.StepName:= '0 - Nulovanie';
			Stopre_pozNAVAZANIE:= FALSE;
			Stopre_pozVYVAZANIE:= FALSE;
			Stoper1_VYSUN:= FALSE;
			Stoper1_ZASUN:= FALSE;
			Checker.OUT.Stoper1_VYSUN:= FALSE;
			Checker.OUT.Stoper1_ZASUN:= FALSE;
			Checker.OUT.Stoper2_VYSUN:= FALSE;
			Checker.OUT.Stoper2_ZASUN:= FALSE;
			IF SC_Checker.Step <> 0 THEN
				SC_OvlStoprov.ResetStep:= TRUE;
				SC_OvlStoprov.Step:= 1;
			END_IF
		
		1:
			SC_OvlStoprov.StepName:= '1 - Rozhodnutie o cinnosti';
			IF Stopre_pozNAVAZANIE THEN
				SC_OvlStoprov.Step:= 10;
			ELSIF Stopre_pozVYVAZANIE THEN
				SC_OvlStoprov.Step:= 20;
			ELSIF Stoper1_VYSUN THEN
				SC_OvlStoprov.Step:= 30;
			ELSIF Stoper1_ZASUN THEN
				SC_OvlStoprov.Step:= 40;
			END_IF
	
		10:
			SC_OvlStoprov.StepName:= '10 - Prepnutie oddelovaca do pozicie navazania';
			SC_OvlStoprov.IdleTime.PT:= T#3s;
			SC_OvlStoprov.AlarmTime.PT:= T#3s;
			
			IF Checker.Automat THEN
				SC_OvlStoprov.AlarmTime.IN:= TRUE;
			ELSE	
				SC_OvlStoprov.IdleTime.IN:= TRUE;
			END_IF
		
			IF NOT SC_OvlStoprov.Switch1 THEN
				Checker.OUT.Stoper1_ZASUN:= TRUE;
				Checker.OUT.Stoper2_VYSUN:= TRUE;
				SC_OvlStoprov.Switch1:= TRUE;
			END_IF
		
			IF SC_OvlStoprov.AlarmTime.Q THEN
				IF NOT Checker.IN.Stoper1_ZASUNUTY THEN
					Alarmy[19]:= TRUE;
				ELSIF NOT Checker.IN.Stoper2_VYSUNUTY THEN
					Alarmy[22]:= TRUE;
				END_IF	
				PoruchaCheckera:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF
		
			IF Checker.STAV.Stopre_PoziciaNAVAZANIE OR SC_OvlStoprov.IdleTime.Q THEN
				SC_OvlStoprov.ResetStep:= TRUE;
				SC_OvlStoprov.Step:= 0;
			END_IF
		
		
		20:
			SC_OvlStoprov.StepName:= '20 - Prepnutie oddelovaca do pozicie vyvazania';
			SC_OvlStoprov.IdleTime.PT:= T#3s;
			SC_OvlStoprov.AlarmTime.PT:= T#3s;
			
			IF Checker.Automat THEN
				SC_OvlStoprov.AlarmTime.IN:= TRUE;
			ELSE	
				SC_OvlStoprov.IdleTime.IN:= TRUE;
			END_IF
		
			IF NOT SC_OvlStoprov.Switch1 THEN
				Checker.OUT.Stoper1_VYSUN:= TRUE;
				Checker.OUT.Stoper2_ZASUN:= TRUE;
				SC_OvlStoprov.Switch1:= TRUE;
			END_IF
		
			IF SC_OvlStoprov.AlarmTime.Q THEN
				IF NOT Checker.IN.Stoper1_VYSUNUTY THEN
					Alarmy[21]:= TRUE;
				ELSIF NOT Checker.IN.Stoper2_ZASUNUTY THEN
					Alarmy[20]:= TRUE;
				END_IF	
				PoruchaCheckera:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF
		
			IF Checker.STAV.Stopre_PoziciaVYVAZANIE OR SC_OvlStoprov.IdleTime.Q THEN
				SC_OvlStoprov.ResetStep:= TRUE;
				SC_OvlStoprov.Step:= 0;
			END_IF
	
	
		30:
			SC_OvlStoprov.StepName:= '30 - Vysunutie stopra 1';
			SC_OvlStoprov.IdleTime.PT:= T#3s;
			SC_OvlStoprov.AlarmTime.PT:= T#3s;
		
			IF Checker.Automat THEN
				SC_OvlStoprov.AlarmTime.IN:= TRUE;
			ELSE	
				SC_OvlStoprov.IdleTime.IN:= TRUE;
			END_IF
		
			IF NOT SC_OvlStoprov.Switch1 THEN
				Checker.OUT.Stoper1_VYSUN:= TRUE;
				SC_OvlStoprov.Switch1:= TRUE;
			END_IF
		
			IF SC_OvlStoprov.AlarmTime.Q THEN
				Alarmy[21]:= TRUE;
				PoruchaCheckera:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF
		
			IF Checker.IN.Stoper1_VYSUNUTY OR SC_OvlStoprov.IdleTime.Q THEN
				SC_OvlStoprov.ResetStep:= TRUE;
				SC_OvlStoprov.Step:= 0;
			END_IF
			
		40:
			SC_OvlStoprov.StepName:= '40 - Zasunutie stopra 1';
			SC_OvlStoprov.IdleTime.PT:= T#3s;
			SC_OvlStoprov.AlarmTime.PT:= T#3s;
		
			IF Checker.Automat THEN
				SC_OvlStoprov.AlarmTime.IN:= TRUE;
			ELSE	
				SC_OvlStoprov.IdleTime.IN:= TRUE;
			END_IF
		
			IF NOT SC_OvlStoprov.Switch1 THEN
				Checker.OUT.Stoper1_ZASUN:= TRUE;
				SC_OvlStoprov.Switch1:= TRUE;
			END_IF
		
			IF SC_OvlStoprov.AlarmTime.Q THEN
				Alarmy[19]:= TRUE;
				PoruchaCheckera:= TRUE;
				Zariadenie.KoniecCyklu:= TRUE;
			END_IF
		
			IF Checker.IN.Stoper1_ZASUNUTY OR SC_OvlStoprov.IdleTime.Q THEN
				SC_OvlStoprov.ResetStep:= TRUE;
				SC_OvlStoprov.Step:= 0;
			END_IF
		
		
	
	END_CASE
	
	
END_ACTION
