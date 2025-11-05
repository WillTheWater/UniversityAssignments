// UniversityAssignments

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

// Print ASCII Table within a range
void PrintASCIITablesInRange(int MinRange, int MaxRange)
{
    int count = 0;

    for (int i = MinRange; i <= MaxRange; i++)
    {
        std::cout << std::setw(6) << i << ": " << (char)(i) << "  ";
        count++;

        if (count % 8 == 0)
            std::cout << "\n";
    }

    std::cout << "\n\n\n";
}


// Check if an integer is prime
bool IsPrime(long long NumberToTest)
{
    if (NumberToTest <= 1) { return false; }

    long long Limit = sqrt(NumberToTest);
    for (long long i = 2; i <= Limit; ++i)
    {
        if (NumberToTest % i == 0) { return false; }
    }
    return true;
}

// Check if an integer is prime, print its factors if not

void FactorizeNumber(long long NumberToFactorize)
{
    std::vector<long long> Factors;
    for (long long i = 2; i < NumberToFactorize; i++)
    {
        while (NumberToFactorize % i == 0)
        {
            Factors.push_back(i);
            NumberToFactorize /= i;
        }
    }
    if (NumberToFactorize > 1)
    {
        Factors.push_back(NumberToFactorize);
    }
    std::cout << "And its factors are: ";
    for (auto Factor : Factors)
    {
        std::cout << Factor << " ";
    }
    std::cout << "\n";
}

int main()
{
    // Printing ASCII Table within a range 32 - 126
	PrintASCIITablesInRange(32, 126);

    // Checking if an integer is prime
    {
        long long UserInputNumberToTest = 0;

        std::cout << "Is it Prime?\nEnter an integer to test: ";
        std::cin >> UserInputNumberToTest;

        if (IsPrime(UserInputNumberToTest))
        {
            std::cout << UserInputNumberToTest << " is a prime number.\n";
        }
        else
        {
            std::cout << UserInputNumberToTest << " is not a prime number.\n";
            FactorizeNumber(UserInputNumberToTest);
        }
        std::cout << "\n\n\n";
    }

	return 0;
}