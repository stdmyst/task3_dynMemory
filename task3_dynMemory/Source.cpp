// ������
//
// 1. ������������ ������ � ���������� ������������������ ����� �����.
// 2. ������ ����� ������������������ ������� ����������.
// 3. ������ ������������������ ������� �� 10-15 ���������, �� ����� �������� � 25 ���������.
// 4. ������ ����� ������������������ �������� ���� ����� 0.
// 5. ���������� ��������� ��� ������������������ ����� �� ���� � ��������� ��� ��� ��� ��������.
// 6.1 ������� ������� �������������� ������������������ �����.
// 6.2 ������� ������ �������� ����� �� ������������������.
// 6.3 ������� ������������������ � �������� �������.
// 7. ������������������ ������ ��������� � ������������ ������
// � �������� ����� �� ���������� ������, ������� ��������� ��� ��, 
// �� ����������� �������� ����� �������������.
// 8. ����� ���� ��������� ������������������ �� ������ ����� �������.

#include <iostream>

using namespace std;

void Average(float, int*, int);//����� ���������� �������� ��������������� ������������������ ����� (�. 6.1)

void Odd(int*, int);           //����� �����������, ������ �������� ����� � �������� ������������������ (�. 6.2)

void Inverse(int*, int);       //����� ������ �������� ������������������ � �������� ������� (�. 6.3)

void dynArray()
{
	float fSum = 0;
	int iflag = 0;
	int iLength = 25;

	int* piArray;
	int* piArray1;
	piArray = new int[iLength];

	cout << "Enter array elements: ";
	for (size_t i = 0; i < iLength; i++)//���������� ������� ������������ ����� iLength;
	{								    //���������� ������� ������������ ����� iLength;
		cin >> *(piArray + i);		    //���������� ������� ������������ ����� iLength;
		if (piArray[i] == 0)
		{
			iLength = iflag + 1;
			piArray1 = new int[iLength];		 //iflag = i
			for (size_t i = 0; i <= iflag; i++)  //���������� �������, ����������� iflag ���������
			{								     //���������� �������, ����������� iflag ���������
				*(piArray1 + i) = *(piArray + i);//���������� �������, ����������� iflag ���������
			}								     //���������� �������, ����������� iflag ���������
			delete[] piArray;

			Average(fSum, piArray1, iflag);
			Odd(piArray1, iflag);
			Inverse(piArray1, iflag);

			delete[] piArray1;

			break;
		}
		iflag = i;//�������� ���������� ��������� �������, ��������� �������������

		if (i + 1 == iLength)
		{
			iLength *= 2;
			piArray1 = new int[iLength];
			for (size_t i = 0; i <= iflag; i++)
			{
				*(piArray1 + i) = *(piArray + i);
			}
			delete[] piArray;

			piArray = new int[iLength];
			for (size_t i = 0; i <= iflag; i++)
			{
				*(piArray + i) = *(piArray1 + i);
			}
			delete[] piArray1;
		}
	}
}

int main()
{
	dynArray();
	return 0;
}

void Average(float sum, int* arr, int length)//����� ���������� �������� ��������������� ������������������ ����� (�. 6.1)
{
	cout << "AVERAGE: ";
	for (size_t i = 0; i <= length; i++)
	{
		sum += arr[i];
	}
	sum /= length + 1;//length + 1 - ���������� ��������� �������
	cout << sum << "\n";
}

void Odd(int* arr, int length)//����� �����������, ������ �������� ����� � �������� ������������������ (�. 6.2)
{
	cout << "ODD: ";
	for (size_t i = 0; i <= length; i++)
	{
		if (arr[i] % 2 != 0)
		{
			cout << arr[i] << " ";
		}
	}
	cout << "\n";
}

void Inverse(int* arr, int length)//����� ������ �������� ������������������ � �������� ������� (�. 6.3)
{
	cout << "INVERSE: ";
	for (int i = length; i >= 0; i--)//int ������ size_t, ����� �������� ������������
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}