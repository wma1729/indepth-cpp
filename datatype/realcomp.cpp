#include <iostream>
#include <limits>
#include <string>
#include <bitset>
#include <cstring>

// Components of real number

inline bool
is_signed(unsigned int n)
{
	return ((n & 0x80000000) == 0x80000000);
}

// The exponent returned in biased
inline int
get_exponent(unsigned int n)
{
	return static_cast<int>((n >> 23) & 0x000000FF);
}

inline int
get_mantissa(unsigned int n)
{
	return static_cast<int>(n & 0x007FFFFF);
}

int
usage(const char *prog)
{
	std::cerr << prog << " <number>" << std::endl;
	return 1;
}

void
print(float f)
{
	unsigned int *iptr = reinterpret_cast<unsigned int *>(&f);
	unsigned int ival = *iptr;

	int e = get_exponent(ival);
	int m = get_mantissa(ival);

	std::cout << "Negative: " << std::boolalpha << is_signed(ival) << std::endl;
	std::cout << "Exponent: " << std::bitset<8>(e).to_string()
		<< " (" << e << ", unbiased = " << e - 127 << ")" <<  std::endl;
	std::cout << "Mantissa: " << std::bitset<23>(m).to_string() << std::endl;
	std::cout << "Number  : " << std::bitset<32>(ival).to_string() << std::endl;
}

int
main(int argc, const char **argv)
{
	float f;

	if (argc < 2)
		return usage(argv[0]);

	if (strcmp(argv[1], "-inf") == 0) {
		f = -1.0f / 0.0f;
	} else if (strcmp(argv[1], "inf") == 0) {
		f = std::numeric_limits<float>::infinity();
	} else if (strcmp(argv[1], "nan") == 0) {
		f = std::numeric_limits<float>::quiet_NaN();
		std::cout << "Quiet NaN" << std::endl;
		print(f);
		f = std::numeric_limits<float>::signaling_NaN();
		std::cout << "Signaling NaN" << std::endl;
	} else {
		f = std::stof(argv[1]);
	}

	print(f);

	return 0;
}
