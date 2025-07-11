#include "timer.h"
#include "vector2.h"

#include <Windows.h>
#include <iostream>

int main()
{
	int i = 0;

	while (true)
	{
		system("cls");
		long long start_time = GetTickCount64();


		std::cout << i++ << std::endl;

		long long end_time = GetTickCount64();
		long long delta_time = end_time - start_time;
		if (delta_time < 1000 / 60.0)
			Sleep(1000 / 60.0 - delta_time);
	}

	return 0;
}