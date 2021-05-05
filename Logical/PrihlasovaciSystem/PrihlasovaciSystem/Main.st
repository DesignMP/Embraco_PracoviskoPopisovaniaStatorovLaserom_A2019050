
PROGRAM _INIT
	MpRecipeXml_1.Load:= TRUE;
	ZvolenyUzivatel:= '';
	ZvolenaUroven:= 0;
	TP_ZobrazPopUpPrihlasenie:=1;
	
END_PROGRAM

PROGRAM _CYCLIC
	
	//Volanie funkcie SequenceControl//
	SequenceControl(SC:= SC_Uzivatelia);
	
	
	//Naèítanie receptur z pamäte//
	IF MpRecipeXml_1.Load AND (MpRecipeXml_1.CommandDone OR MpRecipeXml_1.Error) THEN
		MpRecipeXml_1.Load:= FALSE;
		old_a:= 1;
		i:= 0; 
		IndexZoznam:= 0;
	END_IF	
	
	
	//Konfigurácia receptur//
	MpRecipeXml_1.MpLink:= ADR(gUzivatelXmlLink);  //takto sa menuje mapp komponenta v configurating view//
	MpRecipeXml_1.Enable:= TRUE;
	MpRecipeXml_1.Category:= ADR('UZIVATELIA');
	MpRecipeXml_1.Category:= ADR(strCategory);
	MpRecipeXml_1.DeviceName:= ADR('HDD');  //Názov media, kde sa budú receptury ukladat//
	MpRecipeXml_1.FileName:= ADR('UlozenyUzivatel'); //Názov súboru do ktorého sa receptúry uložia//
	MpRecipeXml_1();
	
	MpRecipeRegPar_1.MpLink:= ADR(gUzivatelXmlLink);
	MpRecipeRegPar_1.Enable:= TRUE;
	MpRecipeRegPar_1.Category:= ADR('UZIVATELIA');
	MpRecipeRegPar_1.PVName:= ADR('Uzivatel'); //Názov premenné, kde je vytvorená štruktura dat pre receptury//
	MpRecipeRegPar_1();	
	
	
	//Zobrazenie názvou receptúr//
	FOR IndexZoznam:=0 TO 50 BY 1 DO
		ZoznamUzivatelov[IndexZoznam]:= Uzivatel[IndexZoznam].Meno;
	END_FOR
	
	//Posun indexu//
	IF MoveUP THEN
		IF i< 50 THEN
			i:= i+1;
		END_IF
		MoveUP:= FALSE;
	END_IF
	
	IF MoveDown THEN
		IF i>0 THEN
			i:= i-1;
		END_IF
		MoveDown:= FALSE;
	END_IF
	
	//Listovanie v uložených uživateloch//
	IF old_a <> i AND i >= 0 AND i <= 50 THEN
		MenoUzivatela:= Uzivatel[i].Meno;
		HesloUzivatela:= Uzivatel[i].Heslo;
		UrovenUzivatela:= Uzivatel[i].UrovenUzivatela;
		old_a:= i;
	END_IF	
	
	
	
	//Prihlasovanie//
	CASE SC_Uzivatelia.Step OF
		
		0://Vynulovanie uživatela//
			SC_Uzivatelia.StepName:= '0 - Nulovanie';
			UlozUzivatelov:= FALSE;
			PrihlasUzivatela:= FALSE;
			VymazUzivatela:= FALSE;
			OdhlasUzivatela:= FALSE;
			MpRecipeXml_1.Save:= FALSE;
			b:= 0;
			SC_Uzivatelia.ResetStep:= TRUE;
			SC_Uzivatelia.Step:= 1;
			
		1://Rozhodnutie o èinnosti//
			SC_Uzivatelia.StepName:= '1 - Rozhodnutie o cinnosti';
			IF UlozUzivatelov THEN
				SC_Uzivatelia.Step:= 10;
			ELSIF PrihlasUzivatela THEN
				SC_Uzivatelia.Step:= 20;
			ELSIF OdhlasUzivatela THEN
				SC_Uzivatelia.Step:= 30;
			ELSIF VymazUzivatela THEN
				SC_Uzivatelia.Step:= 40;
			END_IF
		
		10://Ulozenie uzivatela//
			SC_Uzivatelia.StepName:= '10 - Ulozenie uzivatela';
			Uzivatel[i].Meno:= MenoUzivatela;
			Uzivatel[i].Heslo:= HesloUzivatela;
			Uzivatel[i].UrovenUzivatela:= UrovenUzivatela;
			MpRecipeXml_1.Save:= TRUE;
			IF MpRecipeXml_1.CommandDone THEN
				SC_Uzivatelia.ResetStep:= TRUE;
				SC_Uzivatelia.Step:= 0;
			END_IF
				
		
		20://Èakanie na prihlásenie uživatela//
			SC_Uzivatelia.StepName:= '20 - Kontrola prazdneho uzivatela';
			IF ZadaneMenoUzivatela <> '' AND ZadaneHesloUzivatela <> '' THEN
				SC_Uzivatelia.ResetStep:= TRUE;
				SC_Uzivatelia.Step:= 21;
			ELSE
				ZadaneHesloUzivatela:= ''; 
				SC_Uzivatelia.ResetStep:= TRUE;
				SC_Uzivatelia.Step:= 0;
			END_IF	
				
		21://Kontrola prihláseného uživatela//		
			SC_Uzivatelia.StepName:= '21 - Kontrola prihláseného uzivatela';	
			IF Uzivatel[b].Meno = ZadaneMenoUzivatela AND Uzivatel[b].Heslo = ZadaneHesloUzivatela THEN
				ZvolenyUzivatel:= Uzivatel[b].Meno;
				ZvolenaUroven:= Uzivatel[b].UrovenUzivatela;
				ZadaneHesloUzivatela:= ''; 
				TP_ZobrazPopUpPrihlasenie:= 1;
				SC_Uzivatelia.ResetStep:= TRUE;
				SC_Uzivatelia.Step:= 0;
			ELSE
				b:= b + 1;
				IF b = 51 OR b < 0 OR b > 51 THEN 
					ZadaneMenoUzivatela:= '';
					ZadaneHesloUzivatela:= ''; 
					SC_Uzivatelia.ResetStep:= TRUE;
					SC_Uzivatelia.Step:= 0;
				END_IF
			END_IF	
		
		30://Odhlásenie uživatela//
			SC_Uzivatelia.StepName:= '30 - Odhlasenie uzivatela';
			ZvolenyUzivatel:= '';
			ZvolenaUroven:= 0;
			SC_Uzivatelia.ResetStep:= TRUE;
			SC_Uzivatelia.Step:= 0;
		
		
		40://Vymazanie uživatela//
			SC_Uzivatelia.StepName:= '40 - Vymazanie uzivatela';	
			Uzivatel[i].Meno:= '';
			Uzivatel[i].Heslo:= '';
			Uzivatel[i].UrovenUzivatela:= 0;
			MpRecipeXml_1.Save:= TRUE;
			IF MpRecipeXml_1.CommandDone THEN
				SC_Uzivatelia.ResetStep:= TRUE;
				SC_Uzivatelia.Step:= 0;
			END_IF
		
	END_CASE	
	
	
	
	
	
	 
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

