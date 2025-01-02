
#include <iostream>
#include <random>
#include <array>
#include <string>
#include <fstream>

int GenerateRandomNumber(int min, int max) 
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distr(min, max);

    return distr(gen);
}

bool IsStringInFile(const std::string& filePath, const std::string& targetString) 
{
    std::ifstream file(filePath);
    if (!file.is_open()) 
    {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        if (line == targetString) 
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}


int main()
{
    std::string numbers;
    std::array<std::string, 10> listOfNumbers;

    std::ofstream givenNumbers;
    std::ofstream archiveNumbers;

    givenNumbers.open("Given/Given");
    archiveNumbers.open("Archive/Archive",std::ios::app);
    
    for (auto n = 0; n < listOfNumbers.size(); n++)
    {
        for (auto i = 0; i < 5; i++)
        {
            const auto random = GenerateRandomNumber(1, 59);
            numbers += std::to_string(random) + " ";
        }
        listOfNumbers[n] = numbers;
        if (!IsStringInFile("Archive/Archive", numbers))
        {
            givenNumbers << listOfNumbers[n] << std::endl;
            archiveNumbers << listOfNumbers[n] << std::endl;
        }
        numbers = "";
    }
    
    givenNumbers.close();
    archiveNumbers.close();

    

    

    
}