[LIT]
4
0	110	40	123	40
1	123	40	176	40
2	123	53	138	53
3	123	40	123	53

[TET]
6
5	59	35	67	37	4	5	TRUE
6	33	39	67	41	4	5	siVyblokovanieZamkov_KanalA
7	33	43	67	45	4	5	siVyblokovanieZamkov_KanalB
8	52	47	67	49	4	5	TIME#20ms
9	176	39	206	41	4	3	Status_ZamkyVyblokovane
10	165	52	198	54	4	3	VyblokovanieZamkov_Aktivne

[FBS]
2
21	69	32	108	52	0	SF_Equivalent_V1_00	ServisnyKluc
22	140	49	163	57	1	SAFEBOOL_TO_BOOL	

[FPT]
10
11	69	35	80	37	Activate	0	128	0	BOOL
12	69	39	84	41	S_ChannelA	0	128	0	SAFEBOOL
13	69	43	84	45	S_ChannelB	0	128	0	SAFEBOOL
14	69	47	89	49	DiscrepancyTime	0	128	0	TIME
15	100	35	108	37	Ready	1	0	128	BOOL
16	89	39	108	41	S_EquivalentOut	1	0	128	SAFEBOOL
17	101	43	108	45	Error	1	0	128	BOOL
18	96	47	108	49	DiagCode	1	0	128	WORD
19	140	52	142	54		0	640	0	SAFEBOOL
20	162	52	163	54		1	0	640	BOOL

[KOT]
0

[VER]
0
