
ACTION SpravaPreLaser: 

	
	
  //*********************************Položky ktoré obsahuje QR kód*********************************************************//
  	//*******BOM materiálu***********//
	QR_Kod.BOM_Statora:= ZvolenyBOM_kod_Statora;  //7 znakov
	
	//*******Dátum výroby************//
	//Deò//
	IF System_Cas_Datum.day < 10 THEN
		brsstrcpy(ADR(Systemovy_Datum_STR.Den),ADR('0'));
		Den_String:= USINT_TO_STRING(System_Cas_Datum.day);
		brsstrcat(ADR(Systemovy_Datum_STR.Den),ADR(Den_String));
	ELSE	
		Systemovy_Datum_STR.Den:= USINT_TO_STRING(System_Cas_Datum.day);
	END_IF	
	//Mesiac//
	IF System_Cas_Datum.month < 10 THEN
		brsstrcpy(ADR(Systemovy_Datum_STR.Mesiac),ADR('0'));
		Mesiac_String:= USINT_TO_STRING(System_Cas_Datum.month);
		brsstrcat(ADR(Systemovy_Datum_STR.Mesiac),ADR(Mesiac_String));
	ELSE
		Systemovy_Datum_STR.Mesiac:= USINT_TO_STRING(System_Cas_Datum.month);
	END_IF	
	//Rok//
	Systemovy_Datum_STR.Rok:= UINT_TO_STRING(System_Cas_Datum.year);
	
	TextPole_Datum:='';
	brsstrcat(ADR(TextPole_Datum),ADR(Systemovy_Datum_STR.Den));
	(*brsstrcat(ADR(TextPole_Datum),ADR(SeparatorDatumu));*)
	brsstrcat(ADR(TextPole_Datum),ADR(Systemovy_Datum_STR.Mesiac));
	(*brsstrcat(ADR(TextPole_Datum),ADR(SeparatorDatumu));*)
	brsstrcat(ADR(TextPole_Datum),ADR(Systemovy_Datum_STR.Rok));
	
	QR_Kod.DatumVyroby:= TextPole_Datum;  //8 znakov
	
	
	
	//*********Èas výroby*************//
	//Hodina//
	IF System_Cas_Datum.hour < 10 THEN
		brsstrcpy(ADR(Systemovy_Cas_STR.Hodina),ADR('0'));
		Hodina_String:= USINT_TO_STRING(System_Cas_Datum.hour);
		brsstrcat(ADR(Systemovy_Cas_STR.Hodina),ADR(Hodina_String));
	ELSE	
		Systemovy_Cas_STR.Hodina:= USINT_TO_STRING(System_Cas_Datum.hour);
	END_IF	
	
	
	//Minúta//
	IF System_Cas_Datum.minute < 10 THEN
		brsstrcpy(ADR(Systemovy_Cas_STR.Minuta),ADR('0'));
		Minuta_String:= USINT_TO_STRING(System_Cas_Datum.minute);
		brsstrcat(ADR(Systemovy_Cas_STR.Minuta),ADR(Minuta_String));
	ELSE
		Systemovy_Cas_STR.Minuta:= USINT_TO_STRING(System_Cas_Datum.minute);
	END_IF	
	
	TextPole_Cas:='';
	brsstrcat(ADR(TextPole_Cas),ADR(Systemovy_Cas_STR.Hodina));
	(*brsstrcat(ADR(TextPole_Cas),ADR(SeparatorCasu));*)
	brsstrcat(ADR(TextPole_Cas),ADR(Systemovy_Cas_STR.Minuta));
	
	QR_Kod.CasVyroby:= TextPole_Cas;  //4 znaky
	
	
	
	
	//*************Èíslo výrobnej linky***************//
	QR_Kod.NazovVyrobnejLinky:= 'StatorEM';   //8 znakov
	
	
	
		
	//**************Vyèítavanie posledných štyroch znakov z BOM materiálu**************//
	
	length := brsstrlen(ADR(ZvolenyBOM_kod_Statora)); //Zistí poèet znakov//
	IF length >= 4 THEN
		brsmemcpy(ADR(PoleUSINT),ADR(ZvolenyBOM_kod_Statora),SIZEOF(ZvolenyBOM_kod_Statora));
		i := PoleUSINT[length-4];
		brsstrcpy(ADR(PosledneZnaky),ADR(i));
		i := PoleUSINT[length-3];
		brsstrcat(ADR(PosledneZnaky),ADR(i));
		i := PoleUSINT[length-2];
		brsstrcat(ADR(PosledneZnaky),ADR(i));
		i := PoleUSINT[length-1];
		brsstrcat(ADR(PosledneZnaky),ADR(i));
	END_IF
	
	QR_Kod.BOM_PosledneZnaky:= PosledneZnaky;  //4 znaky
	
	
	//***************************************Vytvorenie správy pre laser*******************************************
	
	brsmemcpy(ADR(Laser_DataSpravy[8]),ADR(QR_Kod.BOM_Statora),7);  			//Pole è.0
	brsmemcpy(ADR(Laser_DataSpravy[17]),ADR(QR_Kod.DatumVyroby),8);				//Pole è.1
	brsmemcpy(ADR(Laser_DataSpravy[27]),ADR(QR_Kod.CasVyroby),4);				//Pole è.2
	brsmemcpy(ADR(Laser_DataSpravy[33]),ADR(QR_Kod.NazovVyrobnejLinky),8);  	//Pole è.3
	brsmemcpy(ADR(Laser_DataSpravy[43]),ADR(QR_Kod.BOM_PosledneZnaky),4);       //Pole è.4
	

	
	
	
	
	
	
	
	
END_ACTION
