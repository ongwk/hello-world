#include "Utilities.h"

namespace SS294502E1_55
{
	int Utilities::SwapBitSequence(int data, int bitwidth)
	{
		int dataout = 0;

		array<int> ^ datatmp = gcnew array<int>(bitwidth);
		for (int i=0; i<bitwidth; i++)
			datatmp[i] = 0;
	
		for (int i=0; i<bitwidth; i++)
		{
			datatmp[i] = (data >> ((bitwidth - 1) - i)) & 0x1;

			dataout = dataout | (datatmp[i] << i);
		}

		return dataout;
	}

	int Utilities::bin2dec(const char* binary)
	{
		int len,dec=0,i,exp;
		len = strlen(binary);
		exp = len-1;

		for(i=0;i<len;i++,exp--)
			dec += binary[i]=='1'?(1 << exp):0;

		return dec;
	}

	char *Utilities::dec2bin(int n, int bit)
	{	
		// 8 bit converter
		int c, d, count;
		char *pointer;
	 
		count = 0;
		pointer = (char*)malloc(bit +1);
	 
		if ( pointer == NULL )
			exit(EXIT_FAILURE);
	 
		for ( c = bit - 1 ; c >= 0 ; c-- )
		{
			d = n >> c;
	 
			if ( d & 1 )
				*(pointer+count) = 1 + '0';
			else
				*(pointer+count) = 0 + '0';
	 
			count++;
		}
		*(pointer+count) = '\0';
	 
		return  pointer;
	}

	void Utilities::line_fit(array<int>^ d_array, array<double>^ m_array, int size, double % slope, double % offset)
	{
		/* d_array - array of dac values */
		/* m_array - array of measurement values */
		/* size - number of d_array and m_array values */
		/* slope,offset - ideal line parameters */
		double sum_x, sum_y, exp_x, mult_xy;
		int i;

		sum_x = sum_y = exp_x = mult_xy = 0.0;

		slope = 0;
		offset = 0;

		for (i=0; i<size; i++)
		{
			sum_y   += m_array[i];
			sum_x   += (double)d_array[i];
			mult_xy += (double)d_array[i] * m_array[i];
			exp_x   += (double)d_array[i] * (double)d_array[i];
		}

		slope =  (size*mult_xy - sum_x*sum_y) / (size*exp_x - sum_x*sum_x);
		offset = ((sum_y / size) - (slope * (sum_x / size)));
	}

	void Utilities::line_fit_d(array<double>^ d_array, array<double>^ m_array, int size, double % slope, double % offset)
	{
		/* d_array - array of dac values */
		/* m_array - array of measurement values */
		/* size - number of d_array and m_array values */
		/* slope,offset - ideal line parameters */
		double sum_x, sum_y, exp_x, mult_xy;
		int i;

		sum_x = sum_y = exp_x = mult_xy = 0.0;

		slope = 0;
		offset = 0;

		for (i=0; i<size; i++)
		{
			sum_y   += m_array[i];
			sum_x   += (double)d_array[i];
			mult_xy += (double)d_array[i] * m_array[i];
			exp_x   += (double)d_array[i] * (double)d_array[i];
		}

		slope =  (size*mult_xy - sum_x*sum_y) / (size*exp_x - sum_x*sum_x);
		offset = ((sum_y / size) - (slope * (sum_x / size)));
	}	

	void Utilities::line_fit_d_hbhi(array<double>^ d_array, array<double>^ m_array, int size, double % slope, double % offset)
	{
		/* d_array - array of dac values */
		/* m_array - array of measurement values */
		/* size - number of d_array and m_array values */
		/* slope,offset - ideal line parameters */
		double sum_x, sum_y, exp_x, mult_xy;
		int i;
		int count = 0;

		sum_x = sum_y = exp_x = mult_xy = 0.0;

		slope = 0;
		offset = 0;

		for (i=0; i<size; i++)
		{
			sum_y   += m_array[i];
			sum_x   += (double)d_array[i];
			mult_xy += (double)d_array[i] * m_array[i];
			exp_x   += (double)d_array[i] * (double)d_array[i];
			count ++;
		}

		if(((count*exp_x) - (sum_x*sum_x)) < 0.00001)
			slope = 0;
		else
			slope =  (count*mult_xy - sum_x*sum_y) / (count*exp_x - sum_x*sum_x);

		offset = ((sum_y / count) - (slope * (sum_x / count)));
	}
	int Utilities::monotonicity(array<double>^ m_array, int size, int type, double % measResult)
	{
		/* monotonicity() returns the index of the minimum deviation between adjacent
		measurements.  For instance, if the minimum occurs between 7-8, it returns 8,
		the thought being that the 8 value is too low to meet monotonicity. 
		 The minimum deviation is passed back in measResult */

		/* measurement array, array size, 0 for pos ascending, measurement result */

		int x, stepResult;
		float stepDelta, smallestDelta;

		measResult = 0;

		if(type == 0)   /*ascending*/
		{
			for(x=1; x<size; x++)
			{
				stepDelta = (float)(m_array[x] - m_array[x-1]);
				if(x==1)
				{
					stepResult = x;
					smallestDelta = stepDelta;
				}
				if(x!=1 && (stepDelta < smallestDelta))
				{
					stepResult = x;
					smallestDelta = stepDelta;
				}
			}

			measResult = smallestDelta;
		}
		else  /*decending*/
		{        
			for(x=1; x<size; x++)
			{
				stepDelta = (float)(m_array[x] - m_array[x-1]);
				if(x==1)
				{
					stepResult = x;
					smallestDelta = stepDelta;
				}
			  
				if(x!=1 && (stepDelta > smallestDelta))
				{
					stepResult = x;
					smallestDelta = stepDelta;
				}
			}
			
			measResult = smallestDelta;
		}

		return stepResult;
	}

	bool Utilities::IsInf(double value)
	{
		double max_value = std::numeric_limits<double>::infinity();
		//double min_value = - max_value;
		//return ! ( min_value <= value && value <= max_value );
		//return ! ( Math::Abs(value) <= max_value );
		
		value = Math::Abs(value);

		if (value < max_value)
			return false;
		else
			return true;
	}

	int Utilities::StrToInt(String ^ str)
	{
		int value = 0;

		try 
		{
			value = int::Parse(str);
		}
		catch (Exception ^)
		{
			value = 0;
		}

		return value;
	}

	double Utilities::StrToDouble(String ^ str)
	{
		double value = 0.0;

		try 
		{
			value = double::Parse(str);
		}
		catch (Exception ^)
		{
			value = 0.0;
		}

		return value;
	}

	int Utilities::Wait_Sec(double sec)
	{
		LARGE_INTEGER startTime;
		LARGE_INTEGER stopTime;
		LARGE_INTEGER sysFreq;

		if (QueryPerformanceFrequency(&sysFreq) == false)
		{
			return -99;
		}

		else
		{
			QueryPerformanceCounter(&startTime);

			do
			{
				QueryPerformanceCounter(&stopTime);
			}
			while (((double)(stopTime.QuadPart - startTime.QuadPart) / (double)sysFreq.QuadPart) < sec);
		}

		return 0;
	}

	int Utilities::SampleRes(string filename, double dresult)
	{
		int ret = 0;
		string filepath = "C:/Aemulus/Debug/" + filename + ".txt";

		ofstream myfile;
		myfile.open(filepath.c_str(), ofstream::out | ofstream::app);
		

		{	
				std::cout.precision(6);
				std::cout.setf( std::ios::fixed, std:: ios::floatfield );
				myfile << dresult << "\t" ;
			}
		


		myfile.close();

		return ret;
	}

	int Utilities::SampleRes(string filename, string sresult)
	{
		int ret = 0;
		string filepath = "C:/Aemulus/Debug/" + filename + ".txt";

		ofstream myfile;

		if (sresult == "n/f")
		{
			myfile.open(filepath.c_str(), ofstream::out);
			myfile.close();
		}else{
			myfile.open(filepath.c_str(), ofstream::out | ofstream::app);
			
			if (sresult == "\n")
				myfile << sresult;
			else
				myfile << sresult << "\t" ;

			myfile.close();
		}
		
		return ret;
	}

	int Utilities::round(double r) 
	{	
		// roundoff to neareast int
		int result = 0;
		result = (int)((r > 0.0) ? (r + 0.5) : (r - 0.5)); 
		return result;
	}

	int Utilities::find_closest(array<double>^ result_arr, double target)
	{
		// sweep all reading and find closest fuse combination to target, return the fuse dac // foolproof method
		int arr_size = 0;
		int target_dac = 0;
		double dev = 0.0;
		double dev_min = 0.0;

		arr_size = result_arr->Length;	
		
		dev_min = abs(result_arr[0] - target) ;
		
		for (int i = 1; i < arr_size; i++)
		{
			dev = abs(result_arr[i] - target);
			
			if (dev < dev_min)
			{
				dev_min = dev;
				target_dac = i;
			}
		}

		return target_dac ;
	}

	int Utilities::find_est_range(double min, double max, double target, int dac, double % lsb, int mode)
	{	
		// bisection method to est target range from range  // valid for 2's comp dac	
			
		int target_dac	= 0;
		double range	= 0.0;
		double pos_dev	= 0.0;
		double neg_dev	= 0.0;
		double target_dac_offset	= 0.0;
		int pos_dac		= (dac / 2) - 1;
		int neg_dac		= pos_dac + 1;

		range =  max - min; ;
		lsb = range / (dac - 1) ; 
		
		pos_dev = abs(max - target) ;
		neg_dev = abs(min - target);

		if (pos_dev < neg_dev)
		{
			target_dac_offset = pos_dev/ lsb;
			target_dac = pos_dac - round(target_dac_offset); 
		}
		else
		{
			target_dac_offset = neg_dev/ lsb;
			target_dac = neg_dac + round(target_dac_offset);
		}
		
		if (mode==INV)
		{
			target_dac = abs(dac - target_dac);
		}
		
		return target_dac;
	}
}