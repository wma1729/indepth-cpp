#include <iostream>
#include <iomanip>
#include <limits>

int
main()
{
	std::cout
		<< std::setw(12) << "Type"
		<< std::setw(6) << "Size"
		<< std::setw(16) << "Min -ve"
		<< std::setw(16) << "Min +ve"
		<< std::setw(16) << "Max +ve"
		<< std::setw(8) << "Radix"
		<< std::setw(8) << "Digits"
		<< std::setw(10) << "Min-Exp"
		<< std::setw(10) << "Max-Exp"
		<< std::setw(10) << "IEEE 754"
		<< std::setw(10) << "Infinity"
		<< std::setw(10) << "QuietNaN"
		<< std::setw(14) << "SignalingNaN"
		<< std::endl;
	std::cout
		<< std::setw(12) << "float"
		<< std::setw(6) << sizeof(float)
		<< std::setw(16) << std::numeric_limits<float>::lowest()
		<< std::setw(16) << std::numeric_limits<float>::min()
		<< std::setw(16) << std::numeric_limits<float>::max()
		<< std::setw(8) << std::numeric_limits<float>::radix
		<< std::setw(8) << std::numeric_limits<float>::digits
		<< std::setw(10) << std::numeric_limits<float>::min_exponent
		<< std::setw(10) << std::numeric_limits<float>::max_exponent
		<< std::setw(10) << std::boolalpha << std::numeric_limits<float>::is_iec559
		<< std::setw(10) << std::boolalpha << std::numeric_limits<float>::has_infinity
		<< std::setw(10) << std::boolalpha << std::numeric_limits<float>::has_quiet_NaN
		<< std::setw(14) << std::boolalpha << std::numeric_limits<float>::has_signaling_NaN
		<< std::endl;
	std::cout
		<< std::setw(12) << "double"
		<< std::setw(6) << sizeof(double)
		<< std::setw(16) << std::numeric_limits<double>::lowest()
		<< std::setw(16) << std::numeric_limits<double>::min()
		<< std::setw(16) << std::numeric_limits<double>::max()
		<< std::setw(8) << std::numeric_limits<double>::radix
		<< std::setw(8) << std::numeric_limits<double>::digits
		<< std::setw(10) << std::numeric_limits<double>::min_exponent
		<< std::setw(10) << std::numeric_limits<double>::max_exponent
		<< std::setw(10) << std::boolalpha << std::numeric_limits<double>::is_iec559
		<< std::setw(10) << std::boolalpha << std::numeric_limits<double>::has_infinity
		<< std::setw(10) << std::boolalpha << std::numeric_limits<double>::has_quiet_NaN
		<< std::setw(14) << std::boolalpha << std::numeric_limits<double>::has_signaling_NaN
		<< std::endl;
	std::cout
		<< std::setw(12) << "long double"
		<< std::setw(6) << sizeof(long double)
		<< std::setw(16) << std::numeric_limits<long double>::lowest()
		<< std::setw(16) << std::numeric_limits<long double>::min()
		<< std::setw(16) << std::numeric_limits<long double>::max()
		<< std::setw(8) << std::numeric_limits<long double>::radix
		<< std::setw(8) << std::numeric_limits<long double>::digits
		<< std::setw(10) << std::numeric_limits<long double>::min_exponent
		<< std::setw(10) << std::numeric_limits<long double>::max_exponent
		<< std::setw(10) << std::boolalpha << std::numeric_limits<long double>::is_iec559
		<< std::setw(10) << std::boolalpha << std::numeric_limits<long double>::has_infinity
		<< std::setw(10) << std::boolalpha << std::numeric_limits<long double>::has_quiet_NaN
		<< std::setw(14) << std::boolalpha << std::numeric_limits<long double>::has_signaling_NaN
		<< std::endl;
	return 0;
}
