
ACTION SpravaPreLaser: 

	
	
  //*********************************Polo�ky ktor� obsahuje QR k�d*********************************************************//
  	//*******BOM materi�lu***********//
	QR_Kod.BOM_Statora:= ZvolenyBOM_kod_Statora;  //8 znakov
	
	//*******D�tum v�roby************//
	//De�//
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
    Rok_STRING:= UINT_TO_STRING(System_Cas_Datum.year);
    brsmemcpy(ADR(Rok_PoleUSINT),ADR(Rok_STRING),SIZEOF(Rok_STRING));
	
    brsmemcpy(ADR(Rok_Cislica1),ADR(Rok_PoleUSINT[2]),SIZEOF(Rok_PoleUSINT[2]));
    brsmemcpy(ADR(Rok_Cislica2),ADR(Rok_PoleUSINT[3]),SIZEOF(Rok_PoleUSINT[3]));
              
    Systemovy_Datum_STR.Rok:= '';
    brsstrcat(ADR(Systemovy_Datum_STR.Rok),ADR(Rok_Cislica1));
    brsstrcat(ADR(Systemovy_Datum_STR.Rok),ADR(Rok_Cislica2));
	
	TextPole_Datum:='';
	brsstrcat(ADR(TextPole_Datum),ADR(Systemovy_Datum_STR.Rok));
    (*brsstrcat(ADR(TextPole_Datum),ADR(SeparatorDatumu));*)
    brsstrcat(ADR(TextPole_Datum),ADR(Systemovy_Datum_STR.Mesiac));
    (*brsstrcat(ADR(TextPole_Datum),ADR(SeparatorDatumu));*)
    brsstrcat(ADR(TextPole_Datum),ADR(Systemovy_Datum_STR.Den));
	
    QR_Kod.DatumVyroby:= TextPole_Datum;  //8 znakov
	
	
	
	//*********�as v�roby*************//
	//Hodina//
	IF System_Cas_Datum.hour < 10 THEN
		brsstrcpy(ADR(Systemovy_Cas_STR.Hodina),ADR('0'));
		Hodina_String:= USINT_TO_STRING(System_Cas_Datum.hour);
		brsstrcat(ADR(Systemovy_Cas_STR.Hodina),ADR(Hodina_String));
	ELSE	
		Systemovy_Cas_STR.Hodina:= USINT_TO_STRING(System_Cas_Datum.hour);
	END_IF	
	
	
	//Min�ta//
	IF System_Cas_Datum.minute < 10 THEN
		brsstrcpy(ADR(Systemovy_Cas_STR.Minuta),ADR('0'));
		Minuta_String:= USINT_TO_STRING(System_Cas_Datum.minute);
		brsstrcat(ADR(Systemovy_Cas_STR.Minuta),ADR(Minuta_String));
	ELSE
		Systemovy_Cas_STR.Minuta:= USINT_TO_STRING(System_Cas_Datum.minute);
	END_IF	
	
    //Sekunda//
    IF System_Cas_Datum.second < 10 THEN
        brsstrcpy(ADR(Systemovy_Cas_STR.Sekunda),ADR('0'));
        Sekunda_String:= USINT_TO_STRING(System_Cas_Datum.second);
        brsstrcat(ADR(Systemovy_Cas_STR.Sekunda),ADR(Sekunda_String));
    ELSE
        Systemovy_Cas_STR.Sekunda:= USINT_TO_STRING(System_Cas_Datum.second);
    END_IF
        
    
	TextPole_Cas:='';
	brsstrcat(ADR(TextPole_Cas),ADR(Systemovy_Cas_STR.Hodina));
	(*brsstrcat(ADR(TextPole_Cas),ADR(SeparatorCasu));*)
	brsstrcat(ADR(TextPole_Cas),ADR(Systemovy_Cas_STR.Minuta));
	brsstrcat(ADR(TextPole_Cas),ADR(Systemovy_Cas_STR.Sekunda));
    
	QR_Kod.CasVyroby:= TextPole_Cas;  //6 znakov
	
	
	
	
	//*************��slo v�robnej linky***************//
	QR_Kod.NazovVyrobnejLinky:= 'StatorEM';   //8 znakov
	
	
	
		
	//**************Vy��tavanie posledn�ch �tyroch znakov z BOM materi�lu**************//
	
	length := brsstrlen(ADR(ZvolenyBOM_kod_Statora)); //Zist� po�et znakov//
	IF length >= 4 THEN
		brsmemcpy(ADR(KodStatora_PoleUSINT),ADR(ZvolenyBOM_kod_Statora),SIZEOF(ZvolenyBOM_kod_Statora));
		i := KodStatora_PoleUSINT[length-4];
		brsstrcpy(ADR(PosledneZnaky),ADR(i));
		i := KodStatora_PoleUSINT[length-3];
		brsstrcat(ADR(PosledneZnaky),ADR(i));
		i := KodStatora_PoleUSINT[length-2];
		brsstrcat(ADR(PosledneZnaky),ADR(i));
		i := KodStatora_PoleUSINT[length-1];
		brsstrcat(ADR(PosledneZnaky),ADR(i));
	END_IF
	
	QR_Kod.BOM_PosledneZnaky:= PosledneZnaky;  //4 znaky
	
	
	//***************************************Vytvorenie spr�vy pre laser*******************************************
	
	brsmemcpy(ADR(Laser_DataSpravy[8]),ADR(QR_Kod.BOM_Statora),7);  			//Pole �.0
	brsmemcpy(ADR(Laser_DataSpravy[17]),ADR(QR_Kod.DatumVyroby),6);				//Pole �.1
	brsmemcpy(ADR(Laser_DataSpravy[25]),ADR(QR_Kod.CasVyroby),6);				//Pole �.2
	brsmemcpy(ADR(Laser_DataSpravy[33]),ADR(QR_Kod.NazovVyrobnejLinky),8);  	//Pole �.3
	brsmemcpy(ADR(Laser_DataSpravy[43]),ADR(QR_Kod.BOM_PosledneZnaky),4);       //Pole �.4
	

	
	
	
	
	
	
	
	
END_ACTION
