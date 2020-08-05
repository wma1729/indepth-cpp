#include <iostream>
#include <iomanip>
#include <limits>

int
main()
{
	std::cout << std::setw(20) << "Type"
		<< std::setw(8) << "Size"
		<< std::setw(24) << "Minimum"
		<< std::setw(24) << "Maximum"
		<< std::setw(12) << "Signed"
		<< std::endl;
	std::cout << std::setw(20) << "bool"
		<< std::setw(8) << sizeof(bool)
		<< std::setw(24) << +std::numeric_limits<bool>::min()
		<< std::setw(24) << +std::numeric_limits<bool>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<bool>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "char"
		<< std::setw(8) << sizeof(char)
		<< std::setw(24) << +std::numeric_limits<char>::min()
		<< std::setw(24) << +std::numeric_limits<char>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<char>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "signed char"
		<< std::setw(8) << sizeof(signed char)
		<< std::setw(24) << +std::numeric_limits<signed char>::min()
		<< std::setw(24) << +std::numeric_limits<signed char>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<signed char>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "unsigned char"
		<< std::setw(8) << sizeof(unsigned char)
		<< std::setw(24) << +std::numeric_limits<unsigned char>::min()
		<< std::setw(24) << +std::numeric_limits<unsigned char>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<unsigned char>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "short"
		<< std::setw(8) << sizeof(short)
		<< std::setw(24) << std::numeric_limits<short>::min()
		<< std::setw(24) << std::numeric_limits<short>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<short>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "unsigned short"
		<< std::setw(8) << sizeof(unsigned short)
		<< std::setw(24) << std::numeric_limits<unsigned short>::min()
		<< std::setw(24) << std::numeric_limits<unsigned short>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<unsigned short>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "int"
		<< std::setw(8) << sizeof(int)
		<< std::setw(24) << std::numeric_limits<int>::min()
		<< std::setw(24) << std::numeric_limits<int>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<int>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "unsigned int"
		<< std::setw(8) << sizeof(unsigned int)
		<< std::setw(24) << std::numeric_limits<unsigned int>::min()
		<< std::setw(24) << std::numeric_limits<unsigned int>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<unsigned int>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "unsigned"
		<< std::setw(8) << sizeof(unsigned)
		<< std::setw(24) << std::numeric_limits<unsigned>::min()
		<< std::setw(24) << std::numeric_limits<unsigned>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<unsigned>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "long"
		<< std::setw(8) << sizeof(long)
		<< std::setw(24) << std::numeric_limits<long>::min()
		<< std::setw(24) << std::numeric_limits<long>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<long>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "unsigned long"
		<< std::setw(8) << sizeof(unsigned long)
		<< std::setw(24) << std::numeric_limits<unsigned long>::min()
		<< std::setw(24) << std::numeric_limits<unsigned long>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<unsigned long>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "long long"
		<< std::setw(8) << sizeof(long long)
		<< std::setw(24) << std::numeric_limits<long long>::min()
		<< std::setw(24) << std::numeric_limits<long long>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<long long>::is_signed
		<< std::endl;
	std::cout << std::setw(20) << "unsigned long long"
		<< std::setw(8) << sizeof(unsigned long long)
		<< std::setw(24) << std::numeric_limits<unsigned long long>::min()
		<< std::setw(24) << std::numeric_limits<unsigned long long>::max()
		<< std::setw(12) << std::boolalpha << std::numeric_limits<unsigned long long>::is_signed
		<< std::endl;
	return 0;
}

