#include "Point.hpp"
#include <string>

int	main(void)
{
	float x = 0;
	float y = 0;
	int	count = 0;
	std::string line;
	Point array[4];
	while (count < 4)
	{
		if (count == 0)
			std::cout << "Crete A point" << std::endl;
		if (count == 1)
			std::cout << "Crete B point" << std::endl;
		if (count == 2)
			std::cout << "Crete C point" << std::endl;
		if (count == 3)
			std::cout << "Crete P point" << std::endl;
		std::cout << "enter x: " << std::flush;
		for (std::cin >> x; !std::cin; std::cin >> x)
		{
			if (std::cin.eof())
				std::exit(1);
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid input, please try again!" << std::endl;
			std::cout << "enter x: " << std::flush;
		}
		std::cout << "enter y: " << std::flush;
		for (std::cin >> y; !std::cin; std::cin >> y)
		{
			if (std::cin.eof())
				std::exit(1);
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid input, please try again!" << std::endl;
			std::cout << "enter y: " << std::flush;
		}
		array[count] = Point(x, y);
		count++;
	}
	std::cout << "Point A: " << array[0] << std::endl;
	std::cout << "Point B: " << array[1] << std::endl;
	std::cout << "Point C: " << array[2] << std::endl;
	std::cout << "Point P: " << array[3] << std::endl;
	if (bsp(array[0], array[1], array[2], array[3]))
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle" << std::endl;
	return (0);
}