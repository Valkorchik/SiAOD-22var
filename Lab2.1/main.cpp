#include <cmath>
#include <iostream>
using namespace std;
const int Rows=10;
const int Cols=10;
void MatrixCreate(double matrix[][Cols], int order)
{
	cout<<"Enter "<<order*order<<" numbers;\n";
	for(int i=0;i<order;i++)
	{
		for(int j=0;j<order;j++)
		{
			cin>>matrix[i][j];
		}
	}
}
void RandomMatrixFiller(double matrix[][Cols], int order)
{
	srand(time(NULL));
	for(int i=0;i<order;i++)
	{
		for(int j=0;j<order;j++)
		{
			matrix[i][j]=rand() % 100 + 1;
		}
	}
}
void MatrixShower(double matrix[][Cols],int order)
{
	cout<<"=== Matrix ===\n";
	for(int i=0;i<order;i++)
	{
		for(int j=0;j<order;j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void InverseMatrixShower(double ematrix[][Cols],int order)
{
	cout<<"=== Inverse Matrix ===\n";
	for(int i=0;i<order;i++)
	{
		for(int j=0;j<order;j++)
		{
			cout<<ematrix[i][j]<<"\t";
		}
		cout<<endl;
	}
}
void EdinCreate(double ematrix[][Cols], int order)
{
	for (int i=0; i<order; i++)
	{
		for (int j=0; j<order; j++)
		{
			if (i!=j)
			{
				ematrix[i][j]=0;
			}
			else
			{
				ematrix[i][j]=1;
			}
		}
	}
}
void TransformMatrix(double matrix[][Cols], double ematrix[][Cols],int order)
{
	int j=0, m, n;
	do
	{ // Выбор ведущего элемента ниже элемента [j,j-1]:
		m = j;
		for (n=j+1; n<order; n++)
		{
			if (fabs(matrix[m][j])<fabs(matrix[n][j]))
			{
				m = n;
			}
		}
		double prm;
		//Переобразования над матрицой А:
		for (n=0; n<order; n++)
		{
			prm = matrix[m][n];
			matrix[m][n] = matrix[j][n];
			matrix[j][n] = prm;
			prm = matrix[m][n];
			matrix[m][n] = matrix[j][n];
			matrix[j][n] = prm;
		}
		prm = matrix[j][j];
		for (n=0; n<order; n++)
		{
			matrix[j][n] = double (matrix[j][n]/prm);
			ematrix[j][n] = double (ematrix[j][n]/prm);
		}
		for (int i=0; i<order; i++)
			if (i!=j)
			{
				prm=matrix[i][j];
				for (n=j; n<order; n++)
				{
					matrix[i][n] = matrix[i][n]- double (prm*matrix[j][n]);
				}
				for (n=0; n<order; n++)
				{
					ematrix[i][n] = ematrix[i][n]- double (prm*ematrix[j][n]);
				}
			}
		j++;
	}
	while (j<order);
	InverseMatrixShower(ematrix,order);
}
int main()
{
	int order,choice;
	cout<<"Enter order of matrix. Maximum 10\n";
	cin>>order;
	if(order<1 || order>10)
	{
		cout<<"Order must be 1=<order=<10 ";
		return 0;
	}
	double matrix[Rows][Cols];
	double ematrix[Rows][Cols];
	cout<<"Choose method of containing: 1 - from keyboard, 2 - random numbers."<<endl;
	cin>>choice;
	if(choice==1) {MatrixCreate(matrix, order);}
	if(choice==2){RandomMatrixFiller(matrix, order);}
	MatrixShower(matrix,order);
	EdinCreate(ematrix,order);
	TransformMatrix(matrix,ematrix,order);
	return 0;
}