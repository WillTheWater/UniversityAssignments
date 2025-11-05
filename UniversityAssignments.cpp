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

// Approximate PI using Machin's Formula using only integers
const long long Scaler = 10000000000000000LL;

double ApproximateIntPI(int NumberOfTerms)
{
    long long Output = 0;

    for (int k = 0; k < NumberOfTerms; k++)
    {
        int Denominator = 2 * k + 1;

        long long Term1 = 16 * Scaler;
        for (int i = 0; i < Denominator; i++) Term1 /= 5;

        long long Term2 = 4 * Scaler;
        for (int i = 0; i < Denominator; i++) Term2 /= 239;

        long long Term = (Term1 - Term2) / Denominator;

        Output += ((k % 2 == 0) ? 1 : -1) * Term;
    }

    return Output;
}

// Create Multiplication Table
int TableSize;

void PrintMultiplicationTable(int TableSIze)
{
    std::cout << "Multiplication Table\n\n";

    for (int i = 0; i <= TableSize; i++)
    {
        std::cout << std::setw(3) << i << " |";
        for (int j = 0; j <= TableSize; j++)
        {
            std::cout << std::setw(4) << i * j;
        }
        std::cout << "\n";
    }
}

int TakeInput()
{
    std::cout << " Enter the size of the table you want\n";
    std::cin >> TableSize;
    return TableSize;
}

// Print integers in binary
int UserInput()
{
    int InputNumber;
    std::cout << "Enter an integer: ";
    std::cin >> InputNumber;
    return InputNumber;
}

void PrintBinary(int Number)
{
    unsigned int Mask = 1u << 31;

    for (int i = 0; i < 32; ++i)
    {
        std::cout << ((Number & Mask) ? '1' : '0');
        if (i % 4 == 3) { std::cout << ' '; }
        Mask >>= 1;
    }
    std::cout << std::endl;
}

// Find the root for x^x = 10
double FindRootForXXEquals10(double LowerBound, double UpperBound)
{
    double Midpoint = (LowerBound + UpperBound) / 2.0;
    double ValueAtMid = std::pow(Midpoint, Midpoint);
    const double Tolerance = 1e-10;

    if (std::abs(ValueAtMid - 10.0) < Tolerance) { return Midpoint; }

    return ValueAtMid < 10.0 ? FindRootForXXEquals10(Midpoint, UpperBound) : FindRootForXXEquals10(LowerBound, Midpoint);

}

void PrintRootForXX(double xValue)
{
    const int IndentWidth = 10;
    std::cout << std::fixed << std::setprecision(15);

    std::cout << std::setw(IndentWidth) << "x = " << std::setw(IndentWidth) << xValue << std::endl;

    std::cout << std::setw(IndentWidth) << "x^x = " << std::setw(IndentWidth) << std::pow(xValue, xValue) << std::endl;
}

// Create an Array from user input and print the highest value
#define N 5

int Numbers[N];

void CreateArrayOfIntFromUserInput()
{
    std::cout << "Enter " << N << " Integers\n";
    for (int i = 0; i < N; i++)
    {
        std::cin >> Numbers[i];
    }
    for (int i = N - 1; i >= 0; i--)
    {
        std::cout << Numbers[i] << " ";
    }
    std::cout << "\n\n";
}

void PrintMaxValueOfArray()
{
    int Max = Numbers[0];
    for (int i = 1; i < N; i++)
    {
        if (Numbers[i] > Max)
        {
            Max = Numbers[i];
        }
    }
    std::cout << "The Largest Number is: " << Max << "\n";
}

// Count individual letters of using input text
void CountLettersFromUserInput()
{
    int Count[26] = { 0 };
    char c;
    std::cout << "Enter Text (Ctrl+Z to Complete)\n\n";
    while (std::cin.get(c))
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            Count[(c >= 'a') ? (c - 'a') : (c - 'A')]++;
        }
    }
    std::cout << "Letter Count: \n";
    for (int i = 0; i < 26; i++)
    {
        if (i % 13 == 0) { std::cout << "\n"; }
        std::cout << (char)('a' + i) << ": " << "[" << Count[i] << "] ";
    }

}

// Find prime numbers within a range
#define Limit 200
bool bIsPrime[Limit + 1];

void PrintPrimesInRange(int Range)
{
    std::cout << "Prime Numbers from 2 to " << Range << ": \n";

    int PrintedNum = 0;
    bool bShouldSpace = false;
    for (int i = 2; i <= Range; i++)
    {
        if (bIsPrime[i])
        {
            std::cout << i << " ";
            PrintedNum++;
            bShouldSpace = true;
        }
        if (PrintedNum % 5 == 0 && bShouldSpace)
        {
            std::cout << "\n";
            bShouldSpace = false;
        }
    }
}

void FindAndPrintPrimesInRange(int Range)
{
    for (int i = 2; i <= Range; i++)
    {
        bIsPrime[i] = true;
    }
    for (int i = 2; i * i <= Range; i++)
    {
        if (bIsPrime[i])
        {
            for (int j = i * 2; j <= Range; j += i)
            {
                bIsPrime[j] = false;
            }
        }
    }
    PrintPrimesInRange(Range);
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

    // Approximate PI for a set number of terms using only integers
    {
        int Terms;
        std::cout << "Enter number of terms to use in Machin's Formula\n";
        std::cin >> Terms;

        long long ApproxPi = ApproximateIntPI(Terms);

        long long integerPart = ApproxPi / Scaler;
        long long decimalPart = ApproxPi % Scaler;

        std::cout << integerPart << "." << decimalPart << "\n";
        std::cout << "\n\n\n";
    }

    // Creates a multiplication table
    {
        PrintMultiplicationTable(TakeInput());
        std::cout << "\n\n\n";
    }

    // Printing integers in binary
    {
        PrintBinary(UserInput());
        std::cout << "\n\n\n";
    }

    // Finding and printing the root of x^x = 10
    {
        PrintRootForXX(FindRootForXXEquals10(2.0, 3.0));
        std::cout << "\n\n\n";
    }

    //Creating an Array of intergers from user input
    {
        CreateArrayOfIntFromUserInput();
        PrintMaxValueOfArray();
        std::cout << "\n\n\n";
    }

    // Counting each letter from user input 
    {
        CountLettersFromUserInput();
        std::cout << "\n\n\n";
    }

    // Printing all prime numbers within a limited range
    {
        FindAndPrintPrimesInRange(Limit);
        std::cout << "\n\n\n";
    }

	return 0;
}