
PROGRAM _INIT
	(* Insert code here *)
	 
END_PROGRAM

PROGRAM _CYCLIC
	
	Laser_Sprava;
	
	
	CASE Client.sStep OF
 	
		0://Èakanie na spustenie komunikácie z laserom//
			IF Laser.Commands.VyberSpravuLasera THEN
				Laser.Status.PoruchaOtvoreniaKomunikacie:= FALSE;
				Laser.Status.PoruchaSpojenia_s_Laserom:= FALSE;
				Laser.Status.PoruchaOdoslaniaDat:= FALSE;
				Laser.Status.PoruchaZatvoreniaKomunikacie:= FALSE;
				Laser.Status.PoruchaPrijatiaDat:= FALSE;
				Laser.Status.VyberSpravy_NG:= FALSE;
				Laser.Status.VyberSpravy_OK:= FALSE;
				Laser.Status.StrataKomunikacie:= FALSE;
				brsmemset(ADR(Laser_Sprava),0,SIZEOF(Laser_Sprava));
				brsmemset(ADR(Laser_Odpoved),0,SIZEOF(Laser_Odpoved));
				brsmemcpy(ADR(Laser_Sprava[0]),ADR(Laser_NazovSpravy),SIZEOF(Laser_NazovSpravy));
				Client.sStep := 1;
			ELSIF Laser.Commands.OdosliDataSpravy THEN
				Laser.Status.PoruchaOtvoreniaKomunikacie:= FALSE;
				Laser.Status.PoruchaSpojenia_s_Laserom:= FALSE;
				Laser.Status.PoruchaOdoslaniaDat:= FALSE;
				Laser.Status.PoruchaZatvoreniaKomunikacie:= FALSE;
				Laser.Status.PoruchaPrijatiaDat:= FALSE;
				Laser.Status.OdoslanieDatSpravy_OK:= FALSE;
				Laser.Status.OdoslanieDatSpravy_NG:= FALSE;
				Laser.Status.StrataKomunikacie:= FALSE;
				brsmemset(ADR(Laser_Sprava),0,SIZEOF(Laser_Sprava));
				brsmemset(ADR(Laser_Odpoved),0,SIZEOF(Laser_Odpoved));
				brsmemcpy(ADR(Laser_Sprava[0]),ADR(Laser_DataSpravy),SIZEOF(Laser_DataSpravy));
				Client.sStep := 1;
			END_IF
		
		
		
		1: //Otvorenie ethernetovej komunikácie//
			Client.TcpOpen_0.enable := 1;	
			Client.TcpOpen_0.pIfAddr := 0;  (* Which Interface to open *)
			Client.TcpOpen_0.port := 3490;  (* Port komunikácie s laserom *)
			Client.TcpOpen_0.options := 0;	
			Client.TcpOpen_0;  (* Call the Function *)
			
						
			IF Client.TcpOpen_0.status = 0 THEN  (* TCP port je otvorený *)
				Client.TcpOpen_timeout := 0;
				Client.sStep := 5;											
			ELSIF Client.TcpOpen_0.status = ERR_FUB_BUSY THEN  (* TCP port sa otvára *)				
				Client.TcpOpen_timeout := Client.TcpOpen_timeout + 1;
				IF Client.TcpOpen_timeout > 50 THEN
					Laser.Status.PoruchaOtvoreniaKomunikacie:= TRUE;
					Client.TcpOpen_timeout := 0;
					Client.sStep := 100;
				END_IF
				(* Busy *)
			ELSE  (* Goto Error Step *)
				Laser.Status.PoruchaOtvoreniaKomunikacie:= TRUE;
				Client.TcpOpen_timeout := 0;
				Client.sStep := 100;
			END_IF
		
		5: 		 
			Client.linger_opt.lLinger := 0; (* linger Time = 0 *)
			Client.linger_opt.lOnOff := 1; (* linger Option ON *)
			Client.TcpIoctl_0.enable := 1;
			Client.TcpIoctl_0.ident := Client.TcpOpen_0.ident; (* Connection Ident from AsTP.TCP_Open *)
			Client.TcpIoctl_0.ioctl := tcpSO_LINGER_SET; (* Set Linger Options *)
			Client.TcpIoctl_0.pData := ADR(Client.linger_opt);
			Client.TcpIoctl_0.datalen := SIZEOF(Client.linger_opt);
			Client.TcpIoctl_0;	    
		
			IF Client.TcpIoctl_0.status = 0 THEN  (* TcpIoctl successfull *)
				Client.sStep := 10;											
			ELSIF Client.TcpIoctl_0.status = ERR_FUB_BUSY THEN  (* TcpIoctl not finished -> redo *)				
				(* Busy *)
			ELSE  (* Goto Error Step *)
				Client.sStep := 100;
			END_IF
		
		
		10: //Spojenie s laserom//					
			Client.TcpClient_0.enable := 1;
			Client.TcpClient_0.ident := Client.TcpOpen_0.ident;  (* Connection Ident from AsTCP.TCP_Open *)
			Client.TcpClient_0.portserv := 3490;  (* Port komunikácie s laserom *)
			Client.TcpClient_0.pServer := ADR('192.168.1.4');  (* Adresa lasera *)
			Client.TcpClient_0;  (* Call the Function*)
			
			
			IF Client.TcpClient_0.status = 0 THEN  (* Open ok -> Send Data *)
				Client.TcpClient_timeout := 0;
				Client.sStep := 20;	
			ELSIF Client.TcpClient_0.status = ERR_FUB_BUSY THEN  (* TcpClient not finished -> redo *)	
				Client.TcpClient_timeout := Client.TcpClient_timeout + 1;
				IF Client.TcpClient_timeout > 50 THEN
					Laser.Status.StrataKomunikacie:= TRUE;
					Client.TcpClient_timeout := 0;
					Client.sStep := 40;
				END_IF
				
				(* Busy *)
			ELSIF Client.TcpClient_0.status = tcpERR_INVALID THEN  (* Port error -> Close actual connection, and reopen a new one *)
				Client.TcpClient_timeout := 0;
				Client.sStep := 40;
			ELSE  (* Goto Error Step *)
				Laser.Status.PoruchaSpojenia_s_Laserom:= TRUE;
				Client.TcpClient_timeout := 0;
				Client.sStep := 100;
			END_IF
		
		
		20: //Poslanie dát do lasera//
			Client.TcpSend_0.enable := 1;				
			Client.TcpSend_0.ident := Client.TcpOpen_0.ident;  (* Connection Ident from AsTCP.TCP_Open *)
			Client.TcpSend_0.pData := ADR(Laser_Sprava);  (* Dáta poslané do lasera *)
			Client.TcpSend_0.datalen := SIZEOF(Laser_Sprava);  (* Lenght of data to send *)
			Client.TcpSend_0.flags := 0;
			Client.TcpSend_0;  (* Call the Function*)
			
			
			IF Client.TcpSend_0.status = 0 THEN  (* Data was sent sucessfully -> receive data *)
				Client.sStep := 30;
			ELSIF Client.TcpSend_0.status = ERR_FUB_BUSY THEN  (* TcpSend not finished -> redo *)	
				(* Busy *)
			ELSIF (Client.TcpSend_0.status = tcpERR_SENTLEN) OR (Client.TcpSend_0.status = tcpERR_NOT_CONNECTED) THEN (* Connection Lost *)
				Laser.Status.StrataKomunikacie:= TRUE;
				Client.sStep := 40;
			ELSE  (* Goto Error Step *)
				Laser.Status.PoruchaOdoslaniaDat:= TRUE;
				Client.sStep := 100;
			END_IF				
		
			
		30: //Prijatie odpovede s lasera//
			Client.TcpRecv_0.enable := 1;
			Client.TcpRecv_0.ident := Client.TcpOpen_0.ident;  (* Connection Ident from AsTCP.TCP_Open *)
			Client.TcpRecv_0.pData	:= ADR(Laser_Odpoved);  (* Dáta poslané z lasera *)
			Client.TcpRecv_0.datamax := SIZEOF(Laser_Odpoved);  (* Lenght of data buffer *)
			Client.TcpRecv_0.flags := 0;
			Client.TcpRecv_0;  (* Call the Function*)
		
			IF Client.TcpRecv_0.status = 0 THEN  (* Data was received sucessfully -> Send next packet *)
				Client.recv_timeout := 0;
				Client.sStep := 40;
			ELSIF Client.TcpRecv_0.status = tcpERR_NO_DATA THEN  (* No data received - wait *)
				Client.recv_timeout := Client.recv_timeout + 1;
				IF Client.recv_timeout > 50 THEN
					Client.recv_timeout := 0;
					Laser.Status.PoruchaPrijatiaDat:= TRUE;
					Client.sStep := 40;
				END_IF
				(* No Data received *)
			ELSIF Client.TcpRecv_0.status = ERR_FUB_BUSY THEN  (* TcpRecv not finished -> redo *)		
				(* Busy *)
			ELSIF Client.TcpRecv_0.status = tcpERR_NOT_CONNECTED THEN (* Connection Lost *)			
				Client.recv_timeout := 0;
				Laser.Status.StrataKomunikacie:= TRUE;
				Client.sStep := 40;
			ELSE  (* Goto Error Step *)
				Laser.Status.PoruchaPrijatiaDat:= TRUE;
				Client.recv_timeout := 0;
				Client.sStep := 100;
			END_IF	
			
			
		40: //Zatvorenie ethernetovej komunikácie//
			Client.TcpClose_0.enable := 1;
			Client.TcpClose_0.ident := Client.TcpOpen_0.ident;  (* Connection Ident from AsTCP.TCP_Open *)
			Client.TcpClose_0.how := 0;
			Client.TcpClose_0;  (* Call the Function*)
	
			IF Client.TcpClose_0.status = 0 THEN  (* Close sucessfull -> Reopen the interface *)
				Client.sStep := 50;
			ELSIF Client.TcpClose_0.status = ERR_FUB_BUSY THEN  (* TcpClose not finished -> redo *)	
				(* Busy *)
			ELSE  (* Goto Error Step *)
				Laser.Status.PoruchaZatvoreniaKomunikacie:= TRUE;
				Client.sStep := 100;
			END_IF
		
		50: //Kontrola odpovede z lasera//	
			//Ak je status 0 tak je odpoved lasera OK//
			IF Laser.Commands.VyberSpravuLasera THEN
				Laser.Status.VysledokPorovnaniaOdpovede:= brsmemcmp(ADR(Laser_Odpoved),ADR(OK_OdpovedNaVyberSpravy),SIZEOF(OK_OdpovedNaVyberSpravy));
				IF Laser.Status.VysledokPorovnaniaOdpovede = 0 THEN
					Laser.Status.VyberSpravy_OK:= TRUE;
					Laser.Commands.VyberSpravuLasera:= FALSE;
					Client.sStep := 0;
				ELSE
					Laser.Status.VyberSpravy_NG:= TRUE;
					Laser.Commands.VyberSpravuLasera:= FALSE;
					Client.sStep := 0;
				END_IF
			ELSIF Laser.Commands.OdosliDataSpravy THEN	
				Laser.Status.VysledokPorovnaniaOdpovede:= brsmemcmp(ADR(Laser_Odpoved),ADR(OK_OdpovedNaDataSpravy),SIZEOF(OK_OdpovedNaDataSpravy));
				IF Laser.Status.VysledokPorovnaniaOdpovede = 0 THEN
					Laser.Status.OdoslanieDatSpravy_OK:= TRUE;
					Laser.Commands.OdosliDataSpravy:= FALSE;
					Client.sStep := 0;
				ELSE
					Laser.Status.OdoslanieDatSpravy_NG:= TRUE;
					Laser.Commands.OdosliDataSpravy:= FALSE;
					Client.sStep := 0;
				END_IF
			END_IF
	
		
			
			
		100: //Ukonèenie komunikácie s laserom//
			Laser.Commands.VyberSpravuLasera:= FALSE;
			Laser.Commands.OdosliDataSpravy:= FALSE;
			Client.sStep := 0;
		
		
	END_CASE	
	
	
	
	
END_PROGRAM

PROGRAM _EXIT
	(* Insert code here *)
	 
END_PROGRAM

