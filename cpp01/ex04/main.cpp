#include <iostream>
#include <fstream>
#include <string>

int	copyFileContent(std::string s1, std::string s2, std::ofstream &copy, std::ifstream &originalFile)
{
	std::string	line;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (std::getline(originalFile, line))
	{
		while (line[j])
		{
			if ((i = line.find(s1, i)) != -1)
			{
				line.erase(i, s1.size());
				line.insert(i, s2);
				i += s2.size();
				j += s2.size();
			}
			else
				j++;
		}
		copy << line;
	}
	return (0);
}

int	checkArg(int argc, char **argv, std::ifstream *originalFile)
{
	std::string	fileName;

	if (argc != 4 || argv[2][0] == '\0')
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (1);
	}
	fileName = argv[1];
	originalFile->open(fileName.c_str(), std::ifstream::in);
	if (!originalFile->is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	std::ifstream	originalFile;
	std::ofstream	copy;
	std::string		fileName;
	std::string		s1;
	std::string		s2;

	if (checkArg(argc, argv, &originalFile))
		return (1);
	fileName = argv[1];
	copy.open(fileName.append(".replace").c_str(), std::ofstream::app | std::ofstream::in | std::ofstream::out);
	if (!copy.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	s1 = argv[2];
	s2 = argv[3];
	copyFileContent(s1, s2, copy, originalFile);
	copy.close();
	originalFile.close();
	return (0);
}