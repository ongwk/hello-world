#pragma once

#include "TF-Macro.h"
#include "Constants.h"
#include "FFT.h"
#include "Utilities.h"
#include "Global.h"

#include <string>
#include <windows.h>
#include <math.h>
#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <sstream>
#include <cmath>
#include <limits>
#include <complex>
#include <valarray>
#include <fstream>

#include <msclr/lock.h>
#include "CountdownEvent.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;
using namespace Aemulus::Tech::Flow;
using namespace Aemulus::Hardware;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System::Threading;
using namespace std; 
using namespace System::Text;
using namespace System::Collections::Generic;

//Barriers
using namespace Aemulus::Tech;
using namespace Aemulus::Tech::Flow::EquipmentDriver;

namespace SS294502E1_55
{
	public ref class TestProgram : ITestProgram
	{
	private:
		//Trimming offset mode
		int UUTCount;
		int TestOffset;

		int GloBcount;

		//Global Variables
		int _numOffset;

		array<int> ^ SPI_started;
		array<double> ^ GND_SENSE_VOLT;

		String ^ HardwareProfile;
		bool offline;
		double Power_Line_Freq; 
		int HDS;

		int Test;

		bool ForceSingleSite;
		int ForceSingleSiteNumber;
		bool SingleSiteTest;
		

		// Trimming
		int Blow_Fuse;

		float wafer_diameter;
		float high_x;
		float high_y;
		
		bool ForceBlowFuseSim;
		//
		int testHead;
		int testSite;
		
		bool TIByPassed;

		bool USE_SPI;	 //ML - shld bypass for 2945 temp?

		// Vector
		Dictionary <String ^ , int> ^ VectorSetNo;
		Dictionary <String ^ , int> ^ VectorLineCount;

		//SPI
		Dictionary <String ^ , int> ^ SPISetNo;
		Dictionary <String ^ , int> ^ SPISetIndex;

		String ^ SPIFileDirectory;
		String ^ VectorFileDirectory;
		String ^ SetupFileDirectory;
	
		bool Debug_Enable;
	
		// Objects
		array<CM ^>^ pxi_controller;
		array<SMU ^>^ smu;
		array<DIO ^>^ dio;
		array<DM ^>^ dm;
		array<TM ^>^ tm;
		array<ACM ^>^ acm;
		array<ACM ^>^ digitizer;
		array<ResourceManager ^>^ resourceManager;

		FFT^ _fft;
		Utilities ^ _util;
		Global ^ _glob;
		
		String ^ OffsetFile;
		Dictionary <String ^ , array<double> ^> ^ offset;

		String ^ TesterCalFile;
		Dictionary <String ^ , array<double> ^> ^ calfactor;

		String ^ DIOSettingFile;
		Dictionary <String ^, array<String ^> ^> ^ DIOSetting; 

		String ^ DMSettingFile;
		Dictionary <String ^, array<String ^> ^> ^ DMSetting; 

		String ^ CBitSettingFile;
		Dictionary <String ^, array<String ^> ^> ^ CBitSetting; 

		String ^ MuxSettingFile;
		Dictionary <String ^, array<String ^> ^> ^ MuxSetting; 

		Dictionary <String ^, double> ^ Vswg_calibrated;
		Dictionary <String ^, double> ^ Vswg_at_dut;

		Dictionary <String ^, double> ^ Vswg_calibrated_gainhds;
		Dictionary <String ^, double> ^ Vswg_at_dut_gainhds;
		Dictionary <String ^, double> ^ Vswg_calibrated_gainhds_virvor;
		
		Dictionary <String ^, double> ^ Vswg_calibrated_gainsup;
		Dictionary <String ^, double> ^ Vswg_at_dut_gainsup;

		Dictionary <String ^, double> ^ Vswg_timing_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_timing_at_dut;

		Dictionary <String ^, double> ^ Vswg_fhsgain_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_fhsgain_at_dut;

		Dictionary <String ^, double> ^ Vswg_fhsgain_spd_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_fhsgain_spd_at_dut;

		Dictionary <String ^, double> ^ Vswg_fhsgain_spd_0_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_fhsgain_spd_0_at_dut;

		Dictionary <String ^, double> ^ Vswg_fhsgain_spd_8_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_fhsgain_spd_8_dut;

		Dictionary <String ^, double> ^ Vswg_fhsgain_spd_4_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_fhsgain_spd_4_dut;

		Dictionary <String ^, double> ^ Vswg_fhsgain_spd_2_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_fhsgain_spd_2_dut;

		Dictionary <String ^, double> ^ Vswg_proxdetect_20k_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_proxdetect_20k_dut;

		Dictionary <String ^, double> ^ Vswg_proxdetect_120k_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_proxdetect_120k_dut;

		Dictionary <String ^, double> ^ Vswg_proxdetect_600k_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_proxdetect_600k_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_50k_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_50k_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_140k_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_140k_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_35k_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_35k_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_100k_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_100k_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_1M_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_1M_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_110k_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_110k_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_180k_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_180k_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_250k_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_250k_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_2M_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_2M_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_3M_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_3M_dut;

		Dictionary <String ^, double> ^ Vswg_hsm_20M_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hsm_20M_dut;

		Dictionary <String ^, double> ^ Vswg_filter_calibrated; //key is Fswg
		Dictionary <String ^, double> ^ Vswg_filter_at_dut;

		Dictionary <String ^, double> ^ Vswg_hth_timing_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_hth_timing_at_dut;

		Dictionary <String ^, double> ^ Vswg_bias_timing_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_bias_timing_at_dut;

		Dictionary <String ^, double> ^ Vswg_itr_timing_calibrated; // key is TIDispName name
		Dictionary <String ^, double> ^ Vswg_itr_timing_at_dut;

		Dictionary <String^, double> ^ Vswg_lpd_spd_calibrated; // key is Fswg
		Dictionary <String^, double> ^ Vswg_lpd_spd_at_dut;

		Dictionary <String ^, int> ^ wr_timing_siggen_del_index; // key is TIDispName name
		Dictionary <String ^, int> ^ wr_timing_vset; // key is TIDispName name
		Dictionary <String ^, int> ^ wr_timing_dig_del_index; // key is TIDispName name
		
		Dictionary <String ^, int> ^ bias_timing_siggen_del_index; // key is TIDispName name
		Dictionary <String ^, int> ^ bias_timing_vset; // key is TIDispName name
		Dictionary <String ^, int> ^ bias_timing_dig_del_index; // key is TIDispName name

		Dictionary <String ^, int> ^ itr_timing_siggen_del_index; // key is TIDispName name
		Dictionary <String ^, int> ^ itr_timing_vset; // key is TIDispName name
		Dictionary <String ^, int> ^ itr_timing_dig_del_index; // key is TIDispName name

		Dictionary <String ^, int> ^ hth_timing_siggen_del_index; // key is TIDispName name
		Dictionary <String ^, int> ^ hth_timing_vset; // key is TIDispName name
		Dictionary <String ^, int> ^ hth_timing_dig_del_index; // key is TIDispName name

		Dictionary <String ^, int> ^ rw_timing_vset; // key is TIDispName name
		Dictionary <String ^, int> ^ rw_timing_dig_del_index; // key is TIDispName name

		Dictionary <String ^, int> ^ CBitHist;

		Stopwatch gwatch;

		//Memory Usage Optimzation
		//SPI 
		array<int> ^ spi_data ;
		array<int> ^ spi_data_dir ;
		array<double> ^ delay_s_after_byte;


		//DGT
		array<int> ^ readdata;
		array<int> ^ readdata_big;

		//  =statistical contact monitoring
		int SampleCount;
		array<double, 2> ^ Cont_Data ; 
		array<int> ^ Cont_Data_idx   ;
		array<double> ^ Cont_Data_mean ;
		array<double> ^ Cont_Data_max;
		array<double> ^ Cont_Data_min; 
		array<double> ^ Cont_Data_sum;
		array<double> ^ Cont_Data_stdev;
		array<int> ^ Cont_Data_meas;
		
		int CD_idx ;

		bool EnableContStat	;

		///////////////////////////////////////////////////////////////////////////////////////
		// Barriers

		StringBuilder ^ sb_sync;
		StreamWriter ^ sw_sync;

		bool Barrier_Debug_Enable;

		static Object^ __barrierLoadLock = gcnew Object();
		static bool __barrierLoaded = false;
		static bool __barrierActive = false;
		static IUutEDDataCollection^ __barrierEdUuts;

		static Object^ __barrierLock = gcnew Object();
		static bool __barrierSetup = false;

		static int __barrierIndex;
		static int __barrierCount;
		static array<CountdownEvent^>^ __barriers;
		static array<bool>^ __barrierFlags;
		void Barrier(int barrier_idx, int site_idx);
		bool IsRunningProduction(Site^ site);
		void SetupBarrier();
		void ResetBarrier(CountdownEvent^ barrier);
		void RunEnded(Site^ site, Phase^ phase, RunResult^ runResult);
		void RunStopped(Site^ site);
		void RunConclude(Site^ site, RunResult^ runResult);

		void Check_Barrier_Flow(Site^ site);

		///////////////////////////////////////////////////////////////////////////////////////

		ref class TestProgramData
		{
		public:
			int UutOffsetIndex;
			Thread^ Thread;
			Exception^ Exception;
			int ErrorCode;
			Site^ t_site;
		};

		///////////////////////////////////////////////////////////////////////////////////////

		//
		void InitializeGlobalVariables();
		int LoadVectorFileList(Site ^ site);
		int LoadVectorFiles(Site ^ site, int UutOffsetIndex);
		int GetDataByteFromHistoryRam(String^ VectorFileName, array<int>^ HistoryRam, int % data_one_byte, int data_channel);
		int LoadOffsetFile(Site ^ site);
		double GetOffset(int UutOffsetIndex, String ^ TestParamDisplayName);
		int LoadDMSettingFile(Site ^ site);
		int SetupDigital(int UutOffsetIndex);
		int DriveDMPin(int UutOffsetIndex, String ^ TestParamDisplayName);
		int ResetDMPin(int UutOffsetIndex, String ^ TestParamDisplayName);
		int Digital_Init_State(int UutOffsetIndex);
		int LoadCBitSettingFile(int UutOffsetIndex);
		int LoadMuxSettingFile(int UutOffsetIndex);
		int SetupDIO(int UutOffsetIndex);
		int DriveCBit(int UutOffsetIndex, String ^ TestParamDisplayName);
		int ResetCBit_TTR(int UutOffsetIndex);									// modified to save TT - only change those "1" to "0"
		int ResetCBit(int UutOffsetIndex);										// ORIGINAL CBIT RESET will only be run by WTR_timing test
		int UltimateResetCBit(int UutOffsetIndex);								// original CBit Reset
		int OnOffCbit(int UutOffsetIndex, int Cbit, int value);
		int DriveMuxIO(int UutOffsetIndex, String ^ TestParamDisplayName);
		int ResetMuxIO(int UutOffsetIndex);
		int OnMux(int UutOffsetIndex, int mux_grp, int mux_pin);
		int OnOffFETGnd(int UutOffsetIndex, int On_h_Off_l);
		int Configure_GND_FET(int UutOffsetIndex);
		int InitCBitHist();
		int ResetCBitHist(int UutOffsetIndex);
		int LoadTesterCalFile();
		int TestProgram::smuReadVoltage(int UutOffsetIndex, double % volt);
		int Measure_GNDS_Voltage(int UutOffsetIndex, double nplc, double meas_delay, double % volt);
		int Configure_GNDS(int UutOffsetIndex);
		int Configure_GNDS_Mux(int UutOffsetIndex, double nplc);
		int DriveMuxIO(int UutOffsetIndex, String ^ TestParamDisplayName, int index);
		int DriveDMPin(int UutOffsetIndex, String ^ TestParamDisplayName, int index);
		int DriveDMPin2(int UutOffsetIndex, String ^ TestParamDisplayName);
		int ResetDMPin(int UutOffsetIndex, String ^ TestParamDisplayName, int index);
		int DriveCBit(int UutOffsetIndex, String ^ TestParamDisplayName, int index);
		int ReadFaultStatusBits(int UutOffsetIndex);
		void CheckError(int UutOffsetIndex, int return_code, int line_number);
		int InitPowerSupplies(int UutOffsetIndex);
		int Probe_Card_FET_Control(int UutOffsetIndex, int hw_fet, int fhcr_fet, int fhcw_fet);
		void LoadPolarity(void);

		//Digitizer
		int Digitizer_Configure(int UutOffsetIndex, array<double> ^ data);
		//int Digitizer_CaptureVpp(int UutOffsetIndex, array<double> ^ data, double % vpp);
		int TestProgram::Digitizer_CaptureVpp(int UutOffsetIndex, array<double> ^ data, double diff2se_digitizer_factor, double % vpp, array<double> ^ dataArray_vpp);
		int TestProgram::Digitizer_CaptureVppNoFFT(int UutOffsetIndex, array<double> ^ data, double diff2se_digitizer_factor, double % vpp, array<double> ^ dataArray_vpp);
		int DigitizerFFT_Configure(int UutOffsetIndex, array<double> ^ data);
		int DigitizerFFT_CaptureVpp(int UutOffsetIndex, array<double> ^ data, double diff2se_digitizer_factor, double % vpp);
		int DigitizerFFT_CaptureVpp(int UutOffsetIndex, int ch, array<double> ^ data, double diff2se_digitizer_factor, double % vpp);
		int Digitizer_GetData(int UutOffsetIndex,int channel, int nbrSamples, int index );
        int Digitizer_ClearData(int UutOffsetIndex, int index );
		int Digitizer_GetBigData(int UutOffsetIndex,int channel, int nbrSamples );
        int Digitizer_ClearBigData(int UutOffsetIndex );
		int SWG_Configure(int UutOffsetIndex, double amplitude, double freq, double phase);
		int FindAmplitude(int UutOffsetIndex, array<double> ^ dat, double thres_v, double % amp);
		void Digitizer_GetVpp(int UutOffsetIndex, array<double> ^ config, double diff2se_digitizer_factor, array<double> ^ rawData, double % vpp); //294502
//		void TestProgram::Digitizer_GetVppOld(int UutOffsetIndex, array<double> ^ config, double diff2se_digitizer_factor, array<double> ^ rawData, double % vpp);
		void TestProgram::MyFLTMUXScopeStop(int UutOffsetIndex);	//FLTMUX Scope
		void TestProgram::MyFLTMUXScopeStart(int UutOffsetIndex);	//FLTMUX Scope

		// Trimming
		void CheckTestItemByPassed(Site ^ site);
		void InitDieID();
		void UpdateXY(Site ^ site, int UutOffsetIndex);
		array<int>^ make_vector(int rw, int page, int reg, int data);
		int RunVectorFile(int UutOffsetIndex, String ^ Vector_str);
		int RunVectorArray(int UutOffsetIndex, int Vector_set_no);
		int ReadVector(int UutOffsetIndex, String ^ Vector_str, int % data);
		int CorrectDac(int % dac, int fuse_count);
		int find_target(int UutOffsetIndex, int target_range_dac, double lsb, int % target_dac, double % target_result, double Measure_Delay_s, int dac, int paramter, int mode);
		void ProcessReading(int UutOffsetIndex, int parameter, double % reading); 
		void LoadTrimReg(void);
		int blow_fuse(int UutOffsetIndex, int parameter, int fuse_bit);
		int blow_fuse_WHD(int UutOffsetIndex, int HD, int fuse_bit);
		int blow_fuse_RHD(int UutOffsetIndex, int HD, int fuse_bit);
		int readlockbit(int UutOffsetIndex);
		int blow_testlockfuse(int UutOffsetIndex);
		int ReadReg(int UutOffsetIndex, int page, int reg, int % data);
		int ReadAllReg(int UutOffsetIndex, string filename);

		//SPI method
		int VectorToSPI(String ^ vec);
		int RunSPI(int UutOffsetIndex, String ^ spi_str);
		int ReadSPI(int UutOffsetIndex, String ^ spi_str, int % data);
		int LoadSPI(String ^ vec, int SPISetNumber);
		int LoadSPIFiles(Site ^ site);
		int OnOffSPI(int UutOffsetIndex, int OnOff);
		int WriteSPI(int UutOffsetIndex, int page, int reg, int data);
		int SPI_Configure(int UutOffsetIndex, int spiGroup, double clk_freq, String ^ clk, String ^ ncs, String ^ mosi, String ^ miso, double input_delay);
		int SPI(int UutOffsetIndex, int spiGroup, array<int> ^ spi_data_array, int spi_array_length, array<double> ^ delay_s_after_byte, int bit_width, array<int> ^ spi_data_direction, int % spiStatus);

		//Diff amp
		int CalibrateDiffAmp_X3(int UutOffsetIndex);
		int CalibrateDiffAmp_X1(int UutOffsetIndex);
		
			//Pin Initialize
		int reader_init(int UutOffsetIndex, String^ Test_Pin_PN, double NPLC, double Input_Channel_Delay_s);
		int writer_init(int UutOffsetIndex, String^ Test_Pin_PN, double NPLC, double Input_Channel_Delay_s);
		int heater_init(int UutOffsetIndex, String^ Test_Pin_PN, double NPLC, double Input_Channel_Delay_s);
		int fhs_init(int UutOffsetIndex, String^ Test_Pin_PN, double NPLC, double Input_Channel_Delay_s);

		// Methods (API)
		void IsRunTest(Site^ site, array<bool>^ run_test);
		void IsRunTest_NoJoF(Site^ site, array<bool>^ run_test);
		int DoThread(ParameterizedThreadStart^ func, Site^ site);
		int DoThreadWithoutVee(ParameterizedThreadStart^ func, Site^ site);
		int DoThreadWithoutVccVee(ParameterizedThreadStart^ func, Site^ site);
		int DoThreadWithoutVee_AWG(ParameterizedThreadStart^ func, Site^ site);

		void gnds_cont(Object ^ object);
		void depmos_test(Object ^ object);
		void vendor(Object ^ object);
		void vcc_cont(Object ^ object);
		void hsd_cont(Object ^ object);
		void analog_rd_cont(Object ^ object);
		void mux_cont_diff(Object^ object);
		void mux_cont_se_kelvin(Object^ object);
		void analog_fhs_cont(Object^ object);

		void input_leakage(Object^ object);
		void vcc_leakage(Object^ object);

		void serial_pwrup(Object^ object);
		void serial_ck_brd(Object^ object);
		void por(Object^ object);
		void serial_ck_brd_level(Object^ object);
		void dig_vol_voh(Object^ object);
		void input_current(Object^ object);
		void mux_offset(Object^ object);
		void pre_vref_trim(Object^ object);
		void sim_vref_trim(Object^ object);
		void sim_vref_trim_sweep(Object^ object);
		void pre_iabs_trim(Object^ object);
		void sim_iabs_trim(Object^ object);
		void sim_iabs_trim_sweep(Object^ object);
		void pre_atemp_trim(Object^ object);
		void sim_atemp_trim_sweep(Object^ object);
		void sim_atemp_trim(Object^ object);
		void htslope(Object^ object);
		void htr(Object^ object);
		void sim_htr(Object^ object);
		void testPass_trim(Object^ object);
		void drheat(Object^ object);
		void writer_in2(Object^ object);
		void vit_vhys_func(Object^ object);
		void digfunc(Object^ object);  
		void dietemp_i(Object^ object);
		void src_curr_meas_volt(Object^ object);
		void amux_current1(Object^ object);
		void power(Object^ object);
		void power_vee_cal(Object^ object);
		void power_pd(Object^ object);
		void rd2wr_bias(Object^ object);
		void dmux(Object^ object);
		void dgf(Object^ object);
		void dgt(Object^ object);
		void adc_ramp(Object^ object);
		void ir_sup3_ttr(Object^ object);
		void ir_hds4_ttr(Object^ object);
		void mrhv3_ttr(Object^ object);
		void reader_cpp(Object^ object);
		void autocal(Object^ object);
		void reader_vos_spd(Object^ object);
		void reader_vocm(Object^ object);
		void rout(Object^ object);
		void gain_sup3(Object^ object);
		void gain_hds2(Object^ object);
		void gain_hds_zdin2(Object^ object);
		void gain_hds_vir_vor2(Object^ object);
		void lfp_ibias_vbias(Object^ object);
		void iw_step3_ttr(Object^ object);
		void iw_supply3_ttr(Object^ object);
		void iw_unsel_ttr(Object^ object);
		void osd_spd(Object^ object);
		void osa_step3_ttr(Object^ object);
		void servo(Object^ object);
		void heater_sup_ttr(Object^ object);
		void heater_rng_ttr(Object^ object);
		void heater_hds(Object^ object);
		void heater_slew2(Object^ object);
		void heater_power(Object^ object);
		void heater_blank(Object^ object);
		void ifhs_bias_hds(Object^ object);
		void vfhs_bias_hds4_ttr(Object^ object);
		void vfhsv4_ttr(Object^ object);
		void ifhs_bias_sup_ttr(Object^ object);
		void vfhs_bias_sup_ttr(Object^ object);
		void fhs_func(Object^ object);
		void prox_diffmux(Object^ object);
		void prox_detect(Object^ object);
		void prox_dacs(Object^ object);
		void fhs_dmux(Object^ object);
		void fhsgain_sup2(Object^ object);
		void fhsgain_spd(Object^ object);
		void hi_spd_mux(Object^ object);
		void rbhv4_ttr(Object^ object);
		void rbhi3_ttr(Object^ object);
		void rdbhv3_ttr(Object^ object);
		void rdbhvc_ttr(Object^ object);
		void rdbhi_ttr(Object^ object);
		void wbhv3_ttr(Object^ object);
		void wdbhv_ttr(Object^ object);
		void fhcr_ttr(Object^ object);
		void sbhv(Object^ object);
		void sbhi3_ttr(Object^ object);
		void hbhi_ttr(Object^ object);
		void flt_wr(Object^ object);
		void flt_ht_ttr(Object^ object);
		void fhs_flt_spd(Object^ object);
		void fhs_vtrip_ttr(Object^ object);
		void flt_fhs_vopen_short2_ttr(Object^ object);
		void flt_ireader_open(Object^ object); 
		void IDCcancelDAC(Object^ object);
		void sply_flt(Object^ object); //2945
		void flt_fhs_iopen(Object^ object);
		void temp_flt(Object^ object);
		void dig_faults(Object^ object);   //2945
		void flt_reader_open(Object^ object);	//new 2945
		void vlo_vee_sply_flt(Object^ object);	//new 2945
		void iwth(Object^ object);
		void por_flt(Object^ object);	  //2945
		void fhs_ishort(Object^ object);  //2945
		void fhs_dcdet_flt(Object^ object);  //2945
		void heater_servo(Object^ object);

		////2945 func
		double supply_thr_ppmu(int idx, String ^ pin, double pass_th, double fail_th,int flt_lvl);
		
	public:
		// TestProgram Constructor
		//ADC
		static int ADC_cal_status = 0;
		//static double ramp_cal = 0;
		//static double offset_cal = 0;
		TestProgram(void);

		// Public Methods
		int Load(Site ^ site);
		int Unload(Site ^ site);
		
		// Public Methods 
		int seq_force_next(Site ^ site);
		int seq_math(Site ^ site);
		int Pre_Test(Site ^ site);
		int Post_Test(Site ^ site);
		int Probe_Card_FET_Control(Site ^ site);
		int Test_Fuse_Branch(Site ^ site);

		int seq_gnds_cont(Site ^ site);
		int seq_depmos_test(Site ^ site);
		int seq_vendor(Site ^ site);
		int seq_vcc_cont(Site ^ site);
		int seq_vee_cont(Site ^ site);
		int seq_hsd_cont(Site ^ site);
		int seq_analog_rd_cont(Site ^ site);
		int seq_mux_cont_diff(Site ^ site);
		int seq_mux_cont_se_kelvin(Site ^ site);
		int seq_analog_fhs_cont(Site ^ site);
		int seq_open_short(Site ^ site);

		int seq_input_leakage(Site ^ site);
		int seq_vcc_leakage(Site ^ site);
		int seq_vee_leakage(Site ^ site);

		int seq_serial_pwrup(Site ^ site);
		int seq_serial_ck_brd(Site ^ site);
		int seq_por(Site ^ site);	//new in 2945
		int seq_serial_ck_brd_level(Site ^ site);
		int seq_dig_vol_voh(Site ^ site);
		int seq_input_current(Site ^ site);

		int seq_power(Site ^ site);
		int seq_power_vee_cal(Site ^ site);
		int seq_power_vee(Site ^ site);
		int seq_power_pd(Site ^ site);

		int seq_mux_offset(Site ^ site);
		int seq_pre_vref_trim(Site ^ site);
		int seq_sim_vref_trim(Site ^ site);
		int seq_sim_vref_trim_sweep(Site ^ site);
		int seq_pre_iabs_trim(Site ^ site);
		int seq_sim_iabs_trim(Site ^ site);
		int seq_sim_iabs_trim_sweep(Site ^ site);
		int seq_pre_atemp_trim(Site ^ site);
		int seq_sim_atemp_trim_sweep(Site ^ site);
		int seq_sim_atemp_trim(Site ^ site);
		int seq_htslope(Site ^ site);	//
		int seq_htr(Site ^ site);	//
		int seq_sim_htr(Site ^ site);	//new in 2945
		int seq_drheat(Site ^ site);	//
		int seq_testPass_trim(Site ^ site);
		int seq_writer_in2(Site ^ site);
		int seq_vit_vhys_func(Site ^ site);
		int seq_digfunc(Site ^ site); 
		int seq_dietemp_i(Site ^ site);
		int seq_src_curr_meas_volt(Site ^ site);
		int seq_amux_current1(Site ^ site);	//
		int seq_rd2wr_bias(Site ^ site); //2945
		int seq_dmux(Site ^ site);	//2945
		int seq_dgf(Site ^ site);
		int seq_dgt(Site ^ site);
		int seq_adc_ramp(Site ^ site);
		int seq_ir_sup3_ttr(Site ^ site);
		int seq_ir_hds4_ttr(Site ^ site);
		int seq_mrhv3_ttr(Site ^ site);
		int seq_reader_cpp(Site ^ site);	//2945 new
		int seq_autocal(Site ^ site);
		int seq_reader_vos_spd(Site ^ site);
		int seq_reader_vocm(Site ^ site);
		int seq_rout(Site ^ site);
		int seq_awg_input_meas(Site ^ site);
		int seq_gain_sup3(Site ^ site);
		int seq_gain_hds2(Site ^ site);
		int seq_gain_hds_zdin2(Site ^ site);
		int seq_gain_hds_vir_vor2(Site ^ site);
		int seq_lfp_ibias_vbias(Site ^ site);
		int seq_iw_step3_ttr(Site ^ site);
		int seq_iw_supply3_ttr(Site ^ site);
		int seq_ro_ttr(Site ^ site);		//int seq_ro(Site ^ site);
		int seq_iw_unsel_ttr(Site ^ site);
		int seq_osd_spd(Site ^ site);
		int seq_osa_step3_ttr(Site ^ site);
		int seq_servo(Site ^ site); //new in 2945
		int seq_acerase_mux(Site ^ site); //new in 2945
		int seq_heater_sup_ttr(Site ^ site);
		int seq_heater_servo(Site ^ site);
		int seq_heater_rng_ttr(Site ^ site);
		int seq_heater_hds(Site ^ site);
		int seq_heater_slew2(Site ^ site);
		int seq_heater_power(Site ^ site);	//new 2945
		int seq_heater_blank(Site ^ site);
		int seq_ifhs_bias_hds(Site ^ site);
		int seq_vfhs_bias_hds4_ttr(Site ^ site);
		int seq_vfhsv4_ttr(Site ^ site);
		int seq_ifhs_bias_sup_ttr(Site ^ site);
		int seq_vfhs_bias_sup_ttr(Site ^ site);
		int seq_fhs_func(Site ^ site);
		int seq_prox_diffmux(Site ^ site);
		int seq_prox_detect(Site ^ site);
		int seq_prox_dacs(Site ^ site);
		int seq_fhs_dmux(Site ^ site);
		int seq_fhsgain_sup2(Site ^ site);
		int seq_fhsgain_spd(Site ^ site);
		int seq_hi_spd_mux(Site ^ site); //
		int seq_rbhv4_ttr(Site ^ site);
		int seq_rbhi3_ttr(Site ^ site);
		int seq_rdbhv3_ttr(Site ^ site);
		int seq_rdbhvc_ttr(Site ^ site);
		int seq_rdbhi_ttr(Site ^ site);
		int seq_wbhv3_ttr(Site ^ site);
		int seq_wdbhv_ttr(Site ^ site);
		int seq_fhcr_ttr(Site ^ site);
		int seq_sbhi3_ttr(Site ^ site);
		int seq_sbhv(Site ^ site);
		int seq_hbhi_ttr(Site ^ site);
		int seq_flt_wr(Site ^ site);
		int seq_flt_ht_ttr(Site ^ site);
		int seq_fhs_flt_spd(Site ^ site);
		int seq_fhs_vtrip_ttr(Site ^ site);
		int seq_flt_fhs_vopen_short2_ttr(Site ^ site);
		int seq_flt_ireader_open(Site ^ site);
		int seq_IDCcancelDAC(Site ^ site); //2945
		int seq_sply_flt(Site ^ site); //2945
		int seq_flt_fhs_iopen(Site ^ site);
		int seq_temp_flt(Site ^ site);
		int seq_dig_faults(Site ^ site);   //2945
		int seq_flt_reader_open(Site ^ site);	//new 2945
		int seq_iwth(Site ^ site);
		int seq_por_flt(Site ^ site);	  //2945
		int seq_fhs_ishort(Site ^ site);  //2945
		int seq_vlo_vee_sply_flt(Site ^ site);	//new 2945
		int seq_fhs_dcdet_flt(Site ^ site);	//new 2945

		int seq_dummy(Site ^ site);

		// AC_TTR
		int logstatus(int UutOffsetIndex, string sstr);
		int PrntWfrm(string sstr, array <double> ^ % data);
		int PrntWfrm(string sstr, array <int> ^ % data);
		//
		
		int seq_wr_timing3_combo(Site ^ site);
		int seq_rw_timing3(Site ^ site);
		int seq_wtr_slow_combo(Site ^ site);
		
		int seq_hth_timing_2hd_3(Site ^ site);
		int seq_bias_timing3(Site ^ site);
		int	seq_itr_timing3(Site ^ site);	
		int seq_wr_flt_timing (Site ^ site);
		int seq_flt_timing(Site ^ site);

		void wr_timing3_combo(Object^ object);
		void rw_timing3(Object^ object);
		void wtr_slow_combo(Object^ object);
			
		void hth_timing_2hd_3(Object^ object);
		void bias_timing3(Object^ object);
		void itr_timing3(Object^ object);
		void wr_flt_timing(Object^ object);
		void flt_timing(Object^ object);

		//
		int stopDigitizerFFTAcquire(int idx, int ch);
		int startDigitizerDGTAcquire(int UutOffsetIndex, int ch);
		int waitDigitizerDGTComplete(int UutOffsetIndex, int ch);
		int stopDigitizerDGTAcquire(int UutOffsetIndex, int ch);
		int RetrieveDigitizerDataArray(int UutOffsetIndex, int ch, array <double> ^ % data);
		int RetrieveDigitizerDataArray(int UutOffsetIndex, int ch, int SampleSize, int index);
		int RetrieveDigitizerDataArray(int UutOffsetIndex, int ch, int SampleSize);

		int InactiveSiteCheck(Site ^ site);

		// 11-1-2016
		//int Calibrate_fhsgain_av0(Site ^ site);

		void PrintContStat(void);
		void RecContData(double result, int C_idx)	;
			
	};
}
