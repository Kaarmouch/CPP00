#include <iostream>
#include <cctype> // std::toupper

int main(int argc, char** argv) 
{
	int	i;
	size_t	j;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			std::string str = argv[i];
			j = 0;
			while (j < str.size())
			{
				std::cout << static_cast<char>(std::toupper(str[j]));
				j++;
			}
			if (i < argc - 1) {
				std::cout << " ";
			}
			i++;
		}
		std::cout << std::endl;
	}
	else 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}

