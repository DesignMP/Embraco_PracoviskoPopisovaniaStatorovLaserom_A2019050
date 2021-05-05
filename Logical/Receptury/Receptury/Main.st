
PROGRAM _INIT

	
END_PROGRAM

PROGRAM _CYCLIC

	//Naèítanie receptur pri prvom spustení//
	IF EDGEPOS(Safety.STAV.SafetyPLC_Nabehlo = TRUE) THEN
		MpRecipeXml_0.Load:= TRUE;
	END_IF
	
	//Naèítanie receptur z pamäte//
	IF MpRecipeXml_0.Load AND (MpRecipeXml_0.CommandDone OR MpRecipeXml_0.Error) THEN
		MpRecipeXml_0.Load:= FALSE;
		old_i:= 1;
		i:= 0;
		IndexZoznam:= 0;
	END_IF	
	
	//Konfigurácia receptur//
	MpRecipeXml_0.MpLink:= ADR(gRecipeXmlLink);  //takto sa menuje mapp komponenta v configurating view//
	MpRecipeXml_0.Enable:= TRUE;
	MpRecipeXml_0.Category:= ADR('RECEPTURY');
	MpRecipeXml_0.DeviceName:= ADR('HDD');  //Názov media, kde sa budú receptury ukladat//
	MpRecipeXml_0.FileName:= ADR('UlozeneReceptury'); //Názov súboru do ktorého sa receptúry uložia//
	MpRecipeXml_0();
	
	MpRecipeRegPar_0.MpLink:= ADR(gRecipeXmlLink);
	MpRecipeRegPar_0.Enable:= TRUE;
	MpRecipeRegPar_0.Category:= ADR('RECEPTURY');
	MpRecipeRegPar_0.PVName:= ADR('Receptura'); //Názov premenné, kde je vytvorená štruktura dat pre receptury//
	MpRecipeRegPar_0();

	//Zobrazenie názvou receptúr//
	FOR IndexZoznam:=0 TO 150 BY 1 DO
		ZoznamReceptur[IndexZoznam]:= Receptura[IndexZoznam].NazovStatora;
	END_FOR
	
	//Posun indexu//
	IF MoveUP THEN
		IF i< 150 THEN
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
	
	//Posun indexu po stranách//
	IF MoveUP_Page THEN
		IF i< (150 - 7) THEN
			i:= i+7;
		END_IF
		MoveUP_Page:= FALSE;
	END_IF
	
	IF MoveDown_Page THEN
		IF i>(0+7) THEN
			i:= i-7;
		END_IF
		MoveDown_Page:= FALSE;
	END_IF
	
	
	//Listovanie v uložených recepturach//
	IF old_i <> i THEN
		NazovStatora:= Receptura[i].NazovStatora;
		BOM_kod_Statora:= Receptura[i].BOM_kod_Statora;
		old_i:= i;
	END_IF
	
	
	
	//Uloženie receptury//
	IF UlozRecepturu THEN
		Receptura[i].NazovStatora:= NazovStatora;
		Receptura[i].BOM_kod_Statora:= BOM_kod_Statora;
		MpRecipeXml_0.Save:= TRUE;
		IF MpRecipeXml_0.CommandDone THEN
			MpRecipeXml_0.Save:= FALSE;
			UlozRecepturu:= FALSE;
		END_IF
	END_IF	
	
	//Naèitanie receptur do premenných//
	IF NacitajRecepturu THEN
		ZvolenyNazovStatora:= NazovStatora;
		ZvolenyBOM_kod_Statora:= BOM_kod_Statora;
		NacitajRecepturu:= FALSE;
	END_IF
	
	
	
	
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

