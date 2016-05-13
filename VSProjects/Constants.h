//#ifndef INC_CONSTANTS_H
//#define INC_CONSTANTS_H

#pragma region "GENERAL"
#define TOTAL_SITES										4
#define QUADRANTA										0
#define QUADRANTB										1
#define QUADRANTC										2
#define QUADRANTD										3
#define TOTAL_DM_IN_SETTING_FILE						8
#define IS_DM_MODULE									0
#define IS_AM_MODULE									1

#define TEST_QS_BLKDGN_PROBE							1
#define TEST_QS_BLKDGN_DUT								2
#define TEST_QS_BLKDGN_PROBE_IF2						3
#define TEST_QS_BLKDGN_DUT_IF2							4

#define TOTAL_GLOBAL_VARIABLE							1024

#define SPI_CLK_FREQ									8e6 //2e6

#define TIMING_RESET_COUNT								5

#define PXITRIGGER0										0
#define PXITRIGGER1										1

#define INVALID_RESULT									-999

#define AM430E_SUPPLY_CONT								true
#pragma endregion "GENERAL"	

#pragma region "DA"
#define TOTAL_MUX_GROUP_PER_SITE						2
#define DA_IDEAL_GAIN									3
#define DA_IDEAL_GAIN_X1								1
#define DA_GAIN_ERROR_TOL_PERCENT						5	
#define DA_OFFSET_ERR_TOL								0.1	
#define CBIT_RLY_GRP1_IA_SEL							8
#define CBIT_RLY_GRP2_IA_SEL							10
#define CBIT_D_Sx_MTX_IN0_OUT0							36
#define CBIT_D_Sx_MTX_IN0_OUT2							38
#define CBIT_D_Sx_MTX_IN0_OUT3							39
#define CBIT_D_Sx_MTX_IN0_OUT5							41
#define CBIT_D_Sx_MTX_IN1_OUT1							45
#define CBIT_D_Sx_MTX_IN1_OUT4							48
#define CBIT_D_Sx_MTX_IN1_OUT2							46
#define CBIT_D_Sx_MTX_IN1_OUT5							49
#pragma endregion "DA"

#pragma region "DSP"
#define PI												3.141592653589793238460
#define NONE											0
#define PARZEN											1
#define WELCH											2
#define HANNING											3
#define HAMMING											4
#define BLACKMAN										5
#define BLACKMANHARRIS									6
#define FFT_SETTING_SIZE								15
#pragma endregion "DSP"	

#pragma region "DIGITIZER"
#define POWER_BINS										10
//#define DIGITIZER_795									true
//#ifdef DIGITIZER_795
	#define REG_DATAPORT									0
	#define REG_BUFFER_START_ADDRESS						1
	#define REG_BUFFER_IDENTIFIER							2
	#define DAT_CH1_BUFFER_IDENTIFIER						0x4
	#define DAT_CH2_BUFFER_IDENTIFIER						0x5
	#define REG_CH1_CONTROL									640 //To start or Stop FFT or digitizer
																//To start Offset calibration
																//To change the full-scale range
	#define REG_CH1_CONFIGURATION1							641 //To set FFT length, Decimation and Accumulation
	#define REG_CH1_CONFIGURATION2							642 //To set the channel Offset
	#define REG_CH1_STATUS									643 //Status register to check:
																// End of measure, FFT or independent digitizer
																// Readiness of full scale range setting / offset calibration
																// Trigger Grant Status bit
	#define REG_CH1_BRAMREAD								644 //To read spectrum
	#define REG_CH1_BRAMADDR								645 //To set start address to read spectrum
	#define REG_CH2_CONTROL									646
	#define REG_CH2_CONFIGURATION1							647
	#define REG_CH2_CONFIGURATION2							648
	#define REG_CH2_STATUS									649
	#define REG_CH2_BRAMREAD								650
	#define REG_CH2_BRAMADDR								651
	#define REG_RESERVED									652
	#define DAT_RESERVED									0x3FFF0000

	#define MAX_DIG_SAMPLE									32768//32768 //500000
	#define NORM_DIG_SAMPLE									1024
	#define BIG_DIG_SAMPLE									2048  // sidi for itr timing
	#define DIG_DATAARR_INDEX								10
//#else
//	#define REG_CH1_CONTROL									320 //To start or Stop FFT or digitizer
//																//To start Offset calibration
//																//To change the full-scale range
//	#define REG_CH1_CONFIGURATION1							321 //To set FFT length, Decimation and Accumulation
//	#define REG_CH1_STATUS									322 //Status register to check:
//																// End of measure, FFT or independent digitizer
//																// Readiness of full scale range setting / offset calibration
//																// Trigger Grant Status bit
//	#define REG_CH1_BRAMREAD								323 //To read spectrum
//	#define REG_CH1_BRAMADDR								324 //To set start address to read spectrum
//	#define REG_CH2_CONTROL									325
//	#define REG_CH2_CONFIGURATION1							326
//	#define REG_CH2_STATUS									327
//	#define REG_CH2_BRAMREAD								328
//	#define REG_CH2_BRAMADDR								329
//#endif
#pragma endregion "DIGITIZER"	

#pragma region "DUT"
#define HDSS											2 /* 2 CHANNELS DUT */
#define CONST_Rdr_Av_div								23.6	//2935 is 44.63 
#define CONST_R4										1000.00	/* Reader input divider */		//ML - no R4 in 2945
#define CONST_R1										52.3000	/* Transmission line divider shunt */
#define CONST_R2										150		/* Reader primary head load /2 */    //ML - 2935 is 137
#define CONST_Rr1										352.3	//CONST_R1+2*CONST_R2	//ML 2935 is 326.3
#define CONST_R21										10		/* Transmission line divider shunt */
#define CONST_R20										45.3	/* Fly height head load /2 */
#define CONST_Rw										3
#define CONST_Rw_Tol									20 //%
#define CONST_Rwo										1000	//ML - is RW1=887 in Cat 2935, RW1=1000 in 2945
#define CONST_Rwo_Tol									1 //%
#define CONST_Rh										100	   //ML 2935 is 5.1
#define CONST_Rh1										392	   //ML 2935 is 73.2
#define CONST_RhNom										100    //ML 2935 is 78.3 //Rh+Rh1 //2945 is 100 or 492
#define CONST_RhAlt										392	   //ML 2935 is RH=5.1, to double check the value
#define CONST_Rf										0.005  //R21/(2*R22)=10/2k
#define CONST_Rfhs										79.91	//R31+ 2*R30 in 2945 R30=37.4, R31=5.11
#define CONST_FSAv_div									217.5
#define CONST_SERIAL_BIT_WIDTH							16
#define CONST_SERIAL_DATA_WIDTH							8
#pragma endregion "DUT"	

#pragma region "IFBOARD"
#define IFBRD_CONST_TOTAL_MUX_IO						8*16+2*8
#define GROUP1_FH										0
#define GROUP1_SH										1
#define GROUP1_SL										2
#define GROUP1_FL										3
#define GROUP2_FH										4
#define GROUP2_SH										5
#define GROUP2_SL										6
#define GROUP2_FL										7
#define MUX_ON											1
#define SWITCH_S1										1
#define SWITCH_S2										2
#define SWITCH_S3										3
#define SWITCH_S4										4
#define SWITCH_S5										5
#define SWITCH_S6										6
#define SWITCH_S7										7
#define SWITCH_S8										8
#define SWITCH_S9										9
#define SWITCH_S10										10
#define SWITCH_S11										11
#define SWITCH_S12										12
#define SWITCH_S13										13
#define SWITCH_S14										14
#define SWITCH_S15										15
#define SWITCH_S16										16
#define CBIT_VCC_FORWARD								53
#define CBIT_VEE_FORWARD								54
#pragma endregion "IFBOARD"

#pragma region "ERROR CODE"
#define ER_FILE_NOT_FOUND								-999
#define ER_READ_FILE_ERROR								-998
#define ER_INVALID_SETTING								-997
#define ER_HARDWARE_PROFILE_NOT_SPECIFIED				-1
#define ER_POWER_LINE_FREQ_NOT_SPECIFIED				-2
#define ER_OFFLINE_NOT_SPECIFIED						-3
#define ER_GENERAL										-4
#define ER_GNS_MUX_OPEN									-5
#define AEMPXIE_E_BAD_ARGUMENTS							-1375141728 //0xAE0900A0
#define ER_TIMEOUT										-6
#pragma endregion "ERROR CODE"

#pragma region "SMU"	
#define AM_CONST_MEASURECURRENT							0
#define AM_CONST_MEASUREVOLTAGE							1
#define AM_CONST_50_HERTZ 								50
#define AM_CONST_60_HERTZ 								60
#define AM_CONST_DVCI 									0
#define AM_CONST_DICV 									1
#define AM_CONST_LOCAL 									0
#define AM_CONST_REMOTE 								1
#define AM_CONST_SECONDS 								0
#define AM_CONST_PLC 									1
#define AM_CONST_OFF 									0
#define AM_CONST_ON 									1
#define AM_CONST_ON_WITH_SERIES_RES						2
#define AM_CONST_TRANSIENT_SLOW							0
#define AM_CONST_TRANSIENT_NORMAL 						1
#define AM_CONST_TRANSIENT_FAST 						2
#define AM_CONST_TRANSIENT_CUSTOM0						3
#define AM_CONST_TRANSIENT_CUSTOM1						4
#define AM_CONST_TRANSIENT_CUSTOM2						5
#define AM_CONST_TRANSIENT_CUSTOM3						6
#define AM_CONST_TRANSIENT_CUSTOM4						7
#define AM_CONST_AUTOMATICALLY_AFTER_SOURCE_COMPLETE	0
#define AM_CONST_ON_MEASURE_TRIGGER 					1
#define AM_CONST_ON_DEMAND								2
#define AM_CONST_ON_ACQUIRE_ARRAY						3
#define AM_CONST_SMU_OUTPUT_TRIGGER_IDLE				0
#define AM_CONST_SMU_OUTPUT_TRIGGER_SOURCE_COMPLETE		1
#define AM_CONST_SMU_OUTPUT_TRIGGER_MEASURE_COMPLETE	2
#define AM_CONST_SMU_OUTPUT_TRIGGER_ENTER_CLAMP			3
#define AM_CONST_SMU_OUTPUT_TRIGGER_EXIT_CLAMP			4
#define AM_CONST_SMU_OUTPUT_TRIGGER_DURING_SOURCE		5	
#define AM_CONST_TRIGGER_TRISTATE						0
#define AM_CONST_TRIGGER_PXI_TRIG0						1
#define AM_CONST_TRIGGER_PXI_TRIG1						2
#define AM_CONST_TRIGGER_PXI_TRIG2						3
#define AM_CONST_TRIGGER_PXI_TRIG3						4
#define AM_CONST_TRIGGER_PXI_TRIG4						5
#define AM_CONST_TRIGGER_PXI_TRIG5						6
#define AM_CONST_TRIGGER_PXI_TRIG6						7
#define AM_CONST_TRIGGER_PXI_TRIG7						8
#define AM_CONST_TRIGGER_PXI_LBL6						9
#define AM_CONST_TRIGGER_PXI_LBR6						10
#define AM_CONST_TRIGGER_PXI_STAR						11
#define AM_CONST_TRIGGER_PXIE_DSTARA					12
#define AM_CONST_TRIGGER_PXIE_DSTARB					13
#define AM_CONST_TRIGGER_PXIE_DSTARC					14
#define AM_CONST_TRIGGER_SOFT_TRIG0						19
#define AM_CONST_TRIGGER_SOFT_TRIG1						20
#define AM_CONST_TRIGGER_SOFT_TRIG2						21
#define AM_CONST_TRIGGER_SOFT_TRIG3						22
#define AM_CONST_TRIGGER_EXT_TRIG						23
#define AM_CONST_SINGLE_SITE							0
#define AM_CONST_MULTI_SITE								1
#define AM_CONST_1V_RANGE								1
#define AM_CONST_2V_RANGE								2
#define AM_CONST_5V_RANGE								5	
#define AM_CONST_10V_RANGE								10					
#define AM_CONST_1UA_RANGE								1E-6
#define AM_CONST_10UA_RANGE								10E-6
#define AM_CONST_100UA_RANGE							100E-6
#define AM_CONST_1MA_RANGE								1E-3
#define AM_CONST_10MA_RANGE								10E-3	
#define AM_CONST_100MA_RANGE							100E-3
#define AM_CONST_1A_RANGE								1
#define AM_CONST_3A_RANGE								3
#pragma endregion "SMU"

#pragma region "DM"
#define DM_CONST_FORCE_STATE_VECTOR				0
#define DM_CONST_FORCE_STATE_PMU				1
#define DM_CONST_FORCE_STATE_DIO				2
#define DM_CONST_FORCE_STATE_CLOCK				5
#define DM_CONST_FORCE_STATE_INVERTED_CLOCK		6
#define DM_CONST_DIR_OUTPUT						1
#define DM_CONST_DIR_INPUT						0
#define DM_CONST_DVCI							0
#define DM_CONST_DICV							1
#define DM_CONST_LOCAL							0
#define DM_CONST_REMOTE							1
#define DM_CONST_MEASURECURRENT					0
#define DM_CONST_MEASUREVOLTAGE					1
#define DM_CONST_50_HERTZ						50
#define DM_CONST_60_HERTZ						60
#define DM_CONST_SECONDS						0
#define DM_CONST_PLC							1
#define DM_CONST_TRIGGER_WHEN_RISING_EDGE 		0
#define DM_CONST_TRIGGER_WHEN_FALLING_EDGE 		1
#define DM_CONST_TRIGGER_WHEN_LOW 				2
#define DM_CONST_TRIGGER_WHEN_HIGH 				3
#define DM_CONST_TRIGGER_NO_CONNECT				0
#define DM_CONST_TRIGGER_PXI_TRIG0				1
#define DM_CONST_TRIGGER_PXI_TRIG1				2	
#define DM_CONST_TRIGGER_PXI_TRIG2				3
#define DM_CONST_TRIGGER_PXI_TRIG3				4
#define DM_CONST_TRIGGER_PXI_TRIG4				5
#define DM_CONST_TRIGGER_PXI_TRIG5				6
#define DM_CONST_TRIGGER_PXI_TRIG6				7
#define DM_CONST_TRIGGER_PXI_TRIG7				8
#define DM_CONST_TRIGGER_PXI_STAR 				11
#define DM_CONST_TRIGGER_PXIE_DSTARA 			12
#define DM_CONST_TRIGGER_PXIE_DSTARB 			13
#define DM_CONST_TRIGGER_SOFTWARE 				19
#define DM_CONST_TRIGGER_SOFTWARE2				20
#define DM_CONST_TRIGGER_EXT_TRIGIN0 			23
#define DM_CONST_TRIGGER_EXT_TRIGIN1 			24
#define DM_CONST_TRIGGER_EXT_TRIGOUT0 			25
#define DM_CONST_TRIGGER_EXT_TRIGOUT1 			26
#define DM_CONST_TRIGGER_MIPI_TRIGOUT0			27
#define DM_CONST_TRIGGER_MIPI_TRIGOUT1			28
#define DM_CONST_SINGLE_SITE					0
#define DM_CONST_MULTI_SITE						1
#define DM_CONST_2UA_RANGE						2E-6
#define DM_CONST_20UA_RANGE						20E-6
#define DM_CONST_200UA_RANGE					200E-6
#define DM_CONST_2MA_RANGE						2E-3
#define DM_CONST_25MA_RANGE						25E-3
#define DM_CONST_SPI_NCS_ACTIVE_LOW				0
#define DM_CONST_SPI_NCS_ACTIVE_HIGH			1
#define DM_CONST_VECTOR_PERIOD_1MHZ				0.5e-6
#define DM_CONST_VECTOR_PERIOD_2MHZ				0.25e-6
#define DM_CONST_VECTOR_PERIOD_10MHZ			50e-9
#define DM_CONST_VECTOR_PERIOD_20MHZ			25e-9
#define DM_CONST_VECTOR_PERIOD_25MHZ			20e-9
#define DM_CONST_VECTOR_PERIOD_40MHZ			12.5e-9
#define DM_CONST_VECTOR_PERIOD_50MHZ			10e-9
#define DM_CONST_VECTOR_PERIOD_100MHZ			5e-9
#define DM_CONST_VECTOR_PERIOD_60MHZ			8.33e-9
#define DM_CONST_VECTOR_PERIOD_70MHZ			7.14e-9
#define DM_CONST_VECTOR_PERIOD_80MHZ			6.25e-9
#define DM_CONST_VECTOR_PERIOD_90MHZ			5.55e-9
#define DM_CONST_VECTOR_PERIOD_100NS			100e-9
#define DM_CONST_BIDIRECTIONAL_IO				0
#define DM_CONST_DEDICATED_IO					1
#define DM_CONST_TOTAL_CHANNEL_PER_CARD			12
#define DM_CONST_MAX_VECTOR_SET					1024		
#define DM_CONST_MODULE_TYPE					0xA10D483e
#define DM_CONST_VMAX							6
#define DM_CONST_VMIN							-2
#define DM_CONST_SET_VIH						0
#define DM_CONST_SET_VIL						1
#define DM_CONST_SET_VTERM						2
#define DM_CONST_SET_VOL						3
#define DM_CONST_SET_VOH						4
#define DM_CONST_SET_VCH						5
#define DM_CONST_SET_VCL						6
#define DM_CONST_SET_IOH						7
#define DM_CONST_SET_IOL						8
#pragma endregion "DM"

#pragma region "DIO"
#define IOM_CONST_OUTPUT_VIO_OFF				-1
#define IOM_CONST_OUTPUT_VIO_3_3V				0
#define IOM_CONST_OUTPUT_VIO_5_0V				1
#define IOM_CONST_OUTPUT_VIO_EXT				2
#define IOM_CONST_OUTPUT_VCCOUT5_ON				1
#define IOM_CONST_OUTPUT_VCCOUT5_OFF			0
#define IOM_CONST_OUTPUT_VCCOUT12_ON			1
#define IOM_CONST_OUTPUT_VCCOUT12_OFF			0
#define IOM_CONST_DIR_OUTPUT					1
#define IOM_CONST_DIR_INPUT						0
#define IOM_CONST_TOTAL_IO						40
#define IOM_CONST_TOTAL_CBITS					64
#define IOM_CONST_TOTAL_PORTS					5
#pragma endregion "DIO"

#pragma region "ACM"
#define ACM_CONST_MODE_FUNCTION_GENERATOR		0
#define ACM_CONST_MODE_AWG						1
#define ACM_CONST_SWITCH_OFF					0
#define ACM_CONST_SWITCH_ON						1
#define ACM_CONST_IMPEDANCE_HIGHZ				0
#define ACM_CONST_IMPEDANCE_50OHM				1
#define ACM_CONST_IMPEDANCE_75OHM				2
#define ACM_CONST_SINE							1
#define ACM_CONST_AUTOTRIG						0
#define ACM_CONST_EXTTRIG						2
#define ACM_CONST_EXTTRIG_CYCLE					6 //new in 54. what is this?
#define ACM_CONST_TRIG_HIGH						1
#define ACM_CONST_TRIG_LOW						2
#define ACM_CONST_TRIG_RISE						3
#define ACM_CONST_TRIG_FALL						4
#pragma endregion "ACM"

#pragma region "TM"
#define TM_CONST_SLOPE_POSITIVE					0
#define TM_CONST_SLOPE_NEGATIVE					1
#define TM_CONST_RANGE_0_50OHM					0
#define TM_CONST_RANGE_1_1MOHM					1
#define TM_CONST_RANGE_2_1MOHM					2
#define TM_CONST_START_CHANNEL					0
#define TM_CONST_STOP_CHANNEL					1
#define TM_CONST_OFF_ARM						0
#define TM_CONST_SOFTWARE_ARM					1
#define TM_CONST_HARDWARE_ARM					2
#define TM_CONST_TRIGGER_ARM					3
#pragma endregion "TM"

#pragma region "Trim"
//#define BLOW_FUSE								0		//ML need to unmask later for burn fuse
#define TRIM_COMP								0.0	 //in 47s was 0.1
//#define SIM										1
#define INV										-1
#define NORM									1
// TrimReg
#define VREF									0
#define IABS									1
#define ATEMP									2
//#define WFRID									3
//#define QUADID								4
//#define RADID									5
//#define WHTRCORE								6
//#define RHTRCORE								7
#define TRIMHEAD								3
#define TRIMCURRENT								4
#define HTR										4
#define TRIMHTSLOPE								5
#define TESTPASS								8
#define TRIMLOCK								9
//#define WHTR_HD									0
//#define RHTR_HD									1
#define	PG										0
#define	REG										1
#define	BIT										2
#define	FUSE									3
#define	FUSEDAC									4
#pragma endregion "Trim"

//SPI
#pragma region "SPI"
#define MAX_SPI_SET								1024
#define MAX_SPI_SET_INDEX						1024
#pragma endregion "SPI"						

//#endif /* INC_CONSTANTS_H */