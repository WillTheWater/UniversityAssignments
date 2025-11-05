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


// Compute the square root of a number
double SquareRoot(double InNumber)
{
    double x = InNumber;
    for (int i = 0; i < 20; i++)
    {
        x = 0.5f * (x + (InNumber / x));
    }
    return x;
}

// Testing the Collatz Conjecture
void CollatzConjecture(int InValue)
{
    int Current = InValue;
    std::cout << Current << ":";
    while (Current != 1)
    {
        if (Current % 2 == 0) { Current = Current / 2; }
        else { Current = (Current * 3) + 1; }

        std::cout << " -> " << Current;
    }
    std::cout << "\n\n";
}

// Approximate PI using Machin's Formula
double ApproximatePI(int NumberOfTerms)
{
    double Output = 0.0;

    for (int k = 0; k < NumberOfTerms; k++)
    {
        int Denominator = 2 * k + 1;

        double Term1 = 16.0 * pow(1.0 / 5, Denominator);
        double Term2 = 4.0 * pow(1.0 / 239, Denominator);
        double Term = (Term1 - Term2) / Denominator;

        Output += ((k % 2 == 0) ? 1 : -1) * Term;
    }

    return Output;
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

    // Computing the square root of a number
    {
        double UserInputNumberToSqRt = 0;

        std::cout << "Enter a number to find the square root: ";
        std::cin >> UserInputNumberToSqRt;
        std::cout << "The square root of: " << UserInputNumberToSqRt << " is ";
        std::cout << std::fixed << std::setprecision(4);
        std::cout << SquareRoot(UserInputNumberToSqRt) << "\n";
        std::cout << "\n\n\n";
    }

    // Using the Collatz Conjecture
    {
        for (int i = 1; i <= 100; i++)
        {
            CollatzConjecture(i);
        }
        std::cout << "\n\n\n";
    }

    // Approximate PI for a set number of terms
    {
        int NumberOfTerms;
        std::cout << "Enter number of terms to use in Machin's Formula\n";
        std::cin >> NumberOfTerms;

        std::cout << std::setprecision(15);
        std::cout << ApproximatePI(NumberOfTerms);
        std::cout << "\n\n\n";
    }

	return 0;
}