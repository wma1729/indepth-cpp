#include <iostream>

enum flags {
	none   = 0x00000000,
	rdonly = 0x00000001,
	wronly = 0x00000002,
	rdwr   = 0x00000004
};

enum flags_large {
	l_none   = 0x7fffffff00000000,
	l_rdonly = 0x7fffffff00000001,
	l_wronly = 0x7fffffff00000002,
	l_rdwr   = 0x7fffffff00000004
};

int
main()
{
	flags f = rdonly;
	std::cout << "sizeof(flags) = " << sizeof(flags) << std::endl;
	std::cout << "f = " << std::hex << f << std::endl;

	flags_large lf = l_rdonly;
	std::cout << "sizeof(flags_large) = " << sizeof(flags_large) << std::endl;
	std::cout << "lf = " << std::hex << lf << std::endl;

	return 0;
}
