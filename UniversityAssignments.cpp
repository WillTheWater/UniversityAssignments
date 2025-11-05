// UniversityAssignments

#include <cstdio>
#include <cmath>

void PrintASCIITablesInRange(int MinRange, int MaxRange)
{
	for (int i = MinRange; i <= MaxRange; i++)
		printf("%3d | %c\n", i, i);
}

int main()
{
	PrintASCIITablesInRange(32, 126);
	return 0;
}