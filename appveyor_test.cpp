#include <iostream>
#include <windows.h>

int main(int argc, char * argv[])
{
	BOOL bIsWow64;
	if (!IsWow64Process(GetCurrentProcess(), &bIsWow64))
	{
		std::cerr << "IsWow64Process() failed." << std::endl;
		exit(1);
	}

#ifdef _WIN64
	std::cout << "Compiled for WIN64." << std::endl;
	std::cout << "Running on 64bit windows." << std::endl;
#else
	std::cout << "Compiled for WIN32." << std::endl;
	if (bIsWow64)
		std::cout << "Running on 64bit windows." << std::endl;
	else
		std::cout << "Running on 32bit windows." << std::endl;
#endif



	exit(0);
}
