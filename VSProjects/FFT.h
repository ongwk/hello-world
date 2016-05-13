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
	public ref class FFT
	{
	public:
		typedef std::complex<double> Complex;
		typedef std::valarray<Complex> CArray;
		
		void apply_fft(CArray& x);

		double GetVpp(array<double>^ dataIn, double sample_interval, int flag_window, bool print_fft);

		void Windowing(array<double>^ dataIn, array<double>^ dataOut, int size, int flag_window);
		double Parzen(int i, int nn);
		double Welch(int i, int nn);
		double Hanning(int i, int nn);
		double Hamming(int i, int nn);
		double Blackman(int i, int nn);
		double BlackmanHarris(int i, int nn);
	};
}