#pragma once

#include "Constants.h"

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
	public ref class Utilities
	{
	public:
		int SwapBitSequence(int data, int bitwidth);
		int bin2dec(const char* binary);
		char * dec2bin(int n, int bit);
		void line_fit_d(array<double>^ d_array, array<double>^ m_array, int size, double % slope, double % offset);
		void line_fit_d_hbhi(array<double>^ d_array, array<double>^ m_array, int size, double % slope, double % offset);
		void line_fit(array<int>^ d_array, array<double>^ m_array, int size, double % slope, double % offset);
		int monotonicity(array<double>^ m_array, int size, int type, double % measResult);
		bool IsInf(double value);
		int StrToInt(String ^ str);
		double StrToDouble(String ^ str);
		int Wait_Sec(double sec);
		int SampleRes(string filename, double dresult);
		int SampleRes(string filename, string sresult);
		int round( double r ); 
		int find_closest(array<double>^ result_arr, double target);
		int find_est_range(double min, double max, double target, int dac, double % lsb, int mode);

	};
}