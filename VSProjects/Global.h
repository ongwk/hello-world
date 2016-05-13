#pragma once

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
#include <ctime>

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

namespace SS294502E1_55
{
	public ref class Global
	{
	public:

		bool jump_on_fail;

		bool DieID_Query_Flag;

		String ^ VectorListFile;

		array<double, 2>^ Global_Result; 

		array<double, 2>^ global_who_i; 
		array<double, 2>^ global_who_v; 

		array<double, 2>^ w_slope; 
		array<double, 2>^ r_slope; 

		int SPD_Channel_Number;

		double global_fsav0;		//for prox_detect test

		int VectorArrSetNo;

		// Contact
		array<int>^ contact_open_l_short_h;
		array<int>^ contact_fail;

		// SPI global variable
		array<int,3>^ SPI_Data_Arr;
		array<int,1>^ SPI_Data_Index;
		double spi_clk_freq;
		
		// Trimming test global variable //use array for 54
		array<int>^ trimlock;
		array<int>^ testpass;
		array<int>^ FuseBlown;

		array<int>^ GoodDIE;
		
		array<double>^ vref_pre;
		array<double>^ iabs_pre;
		array<double>^ atemp_pre;
		array<double>^ htr_pre;
		
		double ramp_cal;
		double offset_cal;

		double Vref_Target;
		double Iabs_Target;
		double Atemp_Target;
		double Htr_Target;
		double Htslope_Target;
		double Htslope_Tolerance; //Added by CB

		array<double>^ mux_offset;

		array<int>^ vref_blown_fuse;
		array<int>^ atemp_blown_fuse;
		array<int>^ iabs_blown_fuse;
		array<int>^ waferid_blown_fuse;
		array<int>^ quadrantid_blown_fuse;
		array<int>^ radiusid_blown_fuse;
		array<int>^ htr_blown_fuse;
		array<int>^ trimhead_blown_fuse;
		array<int>^ trimcurrent_blown_fuse;
		array<int>^ trimhtslope_blown_fuse;

		array<int>^ vref_fuse_toblow;
		array<int>^ atemp_fuse_toblow;
		array<int>^ iabs_fuse_toblow;
		array<int>^ waferid_fuse_toblow;
		array<int>^ quadrantid_fuse_toblow;
		array<int>^ radiusid_fuse_toblow;
		array<int>^ htr_fuse_toblow;
		array<int>^ trimhead_fuse_toblow;
		array<int>^ trimcurrent_fuse_toblow;
		array<int>^ trimhtslope_fuse_toblow;

		// DieID info
		array<int>^ Xcoord;
		array<int>^ Ycoord;

		//waferID Info
		//int WaferScribeString;
		//int WaferDiameter;
		float Die_Size_X;
		float Die_Size_Y;
		float Center_X;
		float Center_Y;

		array<int,2>^ TrimReg; 
		array<int,2>^ TrimRegWHD; 
		array<int,2>^ TrimRegRHD; 

		// Diff Amp Self-Calibration
		array<double, 2> ^ DA_OffsetError;
		array<double, 2> ^ DA_GainError;
		array<double, 1> ^ DA_m;
		array<double, 1> ^ DA_c;
			
		array<double, 2> ^ DA_OffsetError_X1;
		array<double, 2> ^ DA_GainError_X1;
		array<double, 1> ^ DA_m_X1;
		array<double, 1> ^ DA_c_X1;

		//Digitizer Samples Array   (Norm Size)
		array<double, 3>^ DIG_Data_Arr;		//2D array for Digitizer of all sites
		array<double, 1>^ DIG_temp_Arr_S0;  //1D temporary array to retrieve array from digitizer of S0
		array<double, 1>^ DIG_temp_Arr_S1;  //1D temporary array to retrieve array from digitizer of S1
		array<double, 1>^ DIG_temp_Arr_S2;  //1D temporary array to retrieve array from digitizer of S2
		array<double, 1>^ DIG_temp_Arr_S3;  //1D temporary array to retrieve array from digitizer of S3
		array<double, 1>^ DIG_temp_Arr2_S0;  //1D temporary array to retrieve array from digitizer of S0
		array<double, 1>^ DIG_temp_Arr2_S1;  //1D temporary array to retrieve array from digitizer of S1
		array<double, 1>^ DIG_temp_Arr2_S2;  //1D temporary array to retrieve array from digitizer of S2
		array<double, 1>^ DIG_temp_Arr2_S3;  //1D temporary array to retrieve array from digitizer of S3
		array<double, 1>^ DIG_temp_Arr3_S0;  //1D temporary array to retrieve array from digitizer of S0
		array<double, 1>^ DIG_temp_Arr3_S1;  //1D temporary array to retrieve array from digitizer of S1
		array<double, 1>^ DIG_temp_Arr3_S2;  //1D temporary array to retrieve array from digitizer of S2
		array<double, 1>^ DIG_temp_Arr3_S3;  //1D temporary array to retrieve array from digitizer of S3
		array<double, 1>^ DIG_temp_Arr4_S0;  //1D temporary array to retrieve array from digitizer of S0
		array<double, 1>^ DIG_temp_Arr4_S1;  //1D temporary array to retrieve array from digitizer of S1
		array<double, 1>^ DIG_temp_Arr4_S2;  //1D temporary array to retrieve array from digitizer of S2
		array<double, 1>^ DIG_temp_Arr4_S3;  //1D temporary array to retrieve array from digitizer of S3
		
		//Digitizer Samples Array   (UpSize)
		array<double, 2>^ DIG_Big_Data_Arr;		//2D array for Digitizer of all sites
		array<double, 1>^ DIG_Big_temp_Arr_S0;  //1D temporary array to retrieve array from digitizer of S0
		array<double, 1>^ DIG_Big_temp_Arr_S1;  //1D temporary array to retrieve array from digitizer of S1
		array<double, 1>^ DIG_Big_temp_Arr_S2;  //1D temporary array to retrieve array from digitizer of S2
		array<double, 1>^ DIG_Big_temp_Arr_S3;  //1D temporary array to retrieve array from digitizer of S3

		array<double> ^ digitizer_setting;
		array<double> ^ waveAmplitude;
		array<double> ^ dataArray_vpp;
		//DUT counter
		array<int, 1>^ DUT_Counter;

		//Polarity
		array<int,2>^ PolWR_PROBE; 
		array<int,2>^ PolRD_PROBE; 
		array<int,2>^ PolTA_PROBE; 
		array<int,2>^ PolWR_DUT; 
		array<int,2>^ PolRD_DUT; 
		array<int,2>^ PolTA_DUT; 

		//ew: 04232016 -- CBIT control
		array<int>^ cbit_setting;
		int CBIT_TTR;	// master bypass global for CBIT DRIVE
		int CBIT_RESET_TTR; // master bypass global for CBIT RESET
		int GND_SENSE_VOLT_TTR; // master bypass global for GND_SENSE_VOLT TTR
	};
}