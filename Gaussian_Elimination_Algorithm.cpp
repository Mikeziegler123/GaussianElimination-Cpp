/* Author:  Michael Ziegler
 *
 * Purpose: This program reads in a single value, (square) matrix dimension
 * from the user, and then reads in the corresponding values using stdin.
 * 	 ---> Note: [Matrix Dimensions may not exceed 10x10] <---
 * Using a modified Gaussian Elimination algorithm, this program calculates
 * and displays the inverse matrix respectively.
 *
 * Due date:February 6, 2018 before 11:59pm
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Declarations
	float matrixAr[10][20], tempY, tempX;
	int i, j, k, inputSize, valYou;

	//Assigns: from Standard-User-Input, into The Matrix's Size. 
	cout << "Input the inputSize of the matrix:" << "  ";
	cin >> inputSize;


	cout << endl << "Input the " << inputSize << "X" << inputSize << " matrix:"
		<< endl;

	//Assigns: elements, from Standard-User-Input, into The Matrix's Left Side.
	for (i = 0; i < inputSize; i++)
	{
		for (j = 0; j < inputSize; j++)
		{
			cin >> matrixAr[i][j];
		}
	}

	//Assigns: Standard-Identity-Matrix-elements into The Matrix's Right Side. 
	for (i = 0; i < inputSize; i++)
	{
		for (j = inputSize; j < 2 * inputSize; j++)
		{
			if (i == j % inputSize)
			{
				matrixAr[i][j] = 1;
			}
			else
			{
				matrixAr[i][j] = 0;
			}
		}
	}
	//BEGIN: modified Gaussian Elimination algorithm.
	for (j = 0; j < inputSize; j++)
	{
		valYou = j;
		//Finds: Largest-Values within each respective Column.
		for (i = j + 1; i < inputSize; i++)
		{
			if (matrixAr[i][j] > matrixAr[valYou][j])
			{
				valYou = i;
			}
		}
		//Organizes:  A Largest column, if needed. 
		if (valYou != j)
		{
			for (k = 0; k < 2 * inputSize; k++)
			{
				tempY = matrixAr[j][k];
				matrixAr[j][k] = matrixAr[valYou][k];
				matrixAr[valYou][k] = tempY;
			}
		}
		// Processes/Calculates: The Elimination, alongside the Inverse Matrix.  
		for (i = 0; i < inputSize; i++)
		{
			if (i != j)
			{
				tempX = matrixAr[i][j];
				for (k = 0; k < 2 * inputSize; k++)
				{
					matrixAr[i][k] -= matrixAr[j][k] * tempX /
						matrixAr[j][j];
				}
			}

			else
			{
				tempX = matrixAr[i][j];
				for (k = 0; k < 2 * inputSize; k++)
				{
					matrixAr[i][k] /= tempX;
				}
			}
		}
	}

	//Displays: The Inverse of the User's Matrix.
	cout << endl << "The inverse matrix is: " << endl;

	for (i = 0; i < inputSize; i++)
	{
		for (j = inputSize; j < 2 * inputSize; j++)
		{
			cout << setprecision(2) << setw(3) << matrixAr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}







