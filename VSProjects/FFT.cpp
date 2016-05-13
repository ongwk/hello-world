#include "FFT.h"

namespace SS294502E1_55
{
	void FFT::apply_fft(CArray& x)
	{
		const size_t N = x.size();
		if (N <= 1) return;
	 
		// divide
		CArray even = x[slice(0, N/2, 2)];
		CArray  odd = x[slice(1, N/2, 2)];
	 
		// conquer
		apply_fft(even);
		apply_fft(odd);
	 
		// combine
		for (size_t k = 0; k < N/2; ++k)
		{
			Complex t = polar(1.0, -2 * PI * k / N) * odd[k];
			x[k    ] = even[k] + t;
			x[k+N/2] = even[k] - t;
		}
	}	
	double FFT::Parzen(int i, int nn)
	{
		return (1.0 - Math::Abs(((double)i-0.5*(double)(nn-1)) /(0.5*(double)(nn+1))));
	}
	double FFT::Welch(int i, int nn)
	{
		return (1.0-(((double)i-0.5*(double)(nn-1))/(0.5*(double)(nn+1)))*(((double)i-0.5*(double)(nn-1))/(0.5*(double)(nn+1))));
	}
	double FFT::Hanning(int i, int nn)
	{
		return (0.5 * (1.0 - Math::Cos(2.0*PI*(double)i/(double)(nn-1))));
	}
	double FFT::Hamming(int i, int nn)
	{
		return (0.54 - 0.46 * Math::Cos(2.0*PI*(double)i/(double)(nn-1)) );
	}
	double FFT::Blackman(int i, int nn)
	{
		return (0.42 - 0.5 * Math::Cos(2.0*PI*(double)i/(double)(nn-1)) + 0.08 * Math::Cos(4.0*PI*(double)i/(double)(nn-1)));
	}
	double FFT::BlackmanHarris(int i, int nn)
	{
		return (0.35875 - (0.48829 *  Math::Cos(1.0 * (double)i/(double)(nn-1))) + (0.14128 *  Math::Cos(2.0 * (double)i/(double)(nn-1))) - (0.01168 *  Math::Cos(3.0 * (double)i/(double)(nn-1))));
	}
	void FFT::Windowing(array<double>^ dataIn, array<double>^ dataOut, int size, int flag_window)
	{
		for (int i = 0; i < size; i++) 
		{
			switch (flag_window)
			{
				case 1: 
					dataOut[i] = dataIn[i] * Parzen(i, size);
					break;

				case 2: 
					dataOut[i] = dataIn[i] * Welch(i, size);
					break;

				case 3:
					dataOut[i] = dataIn[i] * Hanning(i, size);
					break;

				case 4:
					dataOut[i] = dataIn[i] * Hamming(i, size);
					break;

				case 5:
					dataOut[i] = dataIn[i] * Blackman(i, size);
					break;

				case 6:
					dataOut[i] = dataIn[i] * BlackmanHarris(i, size);
					break;

				case 0: // square (no window)
					dataOut[i] = dataIn[i];
			}
		}
	}
	double FFT::GetVpp(array<double>^ dataIn, double sample_interval, int flag_window, bool print_fft)
	{
		int ret = 0;

		int nbrSamples = dataIn->Length;

		array<double> ^ dataArray = gcnew array<double>(nbrSamples);

		double dataTemp = 0;
		complex<double> * dataArrayComplex = new complex<double>[nbrSamples];
		array<double> ^ magn = gcnew array<double>(nbrSamples);
		double vout_pp = 0.0;
		double fftBIN = 0;

		Windowing(dataIn, dataArray, nbrSamples, flag_window);

		for (int j=0; j<nbrSamples; j++)
		{
			dataTemp = dataArray[j];
			dataArrayComplex[j] = complex<double>(dataTemp);
		}
		 
		CArray data(dataArrayComplex, nbrSamples);
		
		apply_fft(data);

		if (print_fft == true)
		{
			ofstream outFile("C:\\Aemulus\\Debug\\fftdata.txt");
			for (int i = 0; i < nbrSamples; i++) 
			{
				outFile << data[i].real() << "," << data[i].imag() << endl;
			}
			outFile.close();
		}

		fftBIN = 1 / (sample_interval * nbrSamples);

		double max = 0;
		for (int m=0; m<nbrSamples; m++)
		{
			magn[m] = Math::Sqrt(data[m].real()*data[m].real() + data[m].imag()*data[m].imag());

			if (magn[m] > max)
			{
				max = magn[m];
			}
		}
		
		vout_pp = 2.0 * 2.0 * max / nbrSamples;

		delete [] dataArrayComplex; // WK fix for memory leak
		return vout_pp;
	}
}
