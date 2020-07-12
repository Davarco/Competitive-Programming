#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<vector<char>> vvc;

char F; 
int R, C, index;
string input, output;
vvc grid;

string convert_B_to_D(int r0, int r1, int c0, int c1)
{
	if (abs(r0-r1) == 1 && abs(c0-c1) == 1)
		return string(1, grid[r0][c0]);
	else if (abs(r0-r1) == 1)
	{
		int cm = (c0+c1) % 2 == 0 ? (c0+c1) / 2 : (c0+c1)/2 + 1;	
		string L = convert_B_to_D(r0, r1, c0, cm);
		string R = convert_B_to_D(r0, r1, cm, c1);
		if (L[0] == '1' && R[0] == '1')
			return "1";
		else if (L[0] == '0' && R[0] == '0')
			return "0";
		else
			return "D" + L + R;
	}
	else if (abs(c0-c1) == 1)
	{
		int rm = (r0+r1) % 2 == 0 ? (r0+r1) / 2 : (r0+r1)/2 + 1;
		string T = convert_B_to_D(r0, rm, c0, c1);
		string B = convert_B_to_D(rm, r1, c0, c1);
		if (T[0] == '1' && B[0] == '1')
			return "1";
		else if (T[0] == '0' && B[0] == '0')
			return "0";
		else
			return "D" + T + B;
	}
	else
	{
		int rm = (r0+r1) % 2 == 0 ? (r0+r1) / 2 : (r0+r1)/2 + 1;
		int cm = (c0+c1) % 2 == 0 ? (c0+c1) / 2 : (c0+c1)/2 + 1;	
		string TL = convert_B_to_D(r0, rm, c0, cm);
		string TR = convert_B_to_D(r0, rm, cm, c1);
		string BL = convert_B_to_D(rm, r1, c0, cm);
		string BR = convert_B_to_D(rm, r1, cm, c1);
		if (TL[0] == '1' && TR[0] == '1' && BL[0] == '1' && BR[0] == '1')
			return "1";
		else if (TL[0] == '0' && TR[0] == '0' && BL[0] == '0' && BR[0] == '0')
			return "0";
		else
			return 'D' + TL + TR + BL + BR;
	}
}

void convert_D_to_B(int r0, int r1, int c0, int c1)
{
	char c = input[index++];
	if (c == '1')
	{
		for (int r = r0; r < r1; r++)
			for (int c = c0; c < c1; c++)
				output[r*C+c] = '1';
	}
	else if (c == '0')
	{
		for (int r = r0; r < r1; r++)
			for (int c = c0; c < c1; c++)
				output[r*C+c] = '0';
	}
	else if (abs(r0-r1) == 1)
	{
		int cm = (c0+c1) % 2 == 0 ? (c0+c1) / 2 : (c0+c1)/2 + 1;	
		convert_D_to_B(r0, r1, c0, cm);
		convert_D_to_B(r0, r1, cm, c1);
	}
	else if (abs(c0-c1) == 1)
	{
		int rm = (r0+r1) % 2 == 0 ? (r0+r1) / 2 : (r0+r1)/2 + 1;
		convert_D_to_B(r0, rm, c0, c1);
		convert_D_to_B(rm, r1, c0, c1);
	}
	else
	{
		int rm = (r0+r1) % 2 == 0 ? (r0+r1) / 2 : (r0+r1)/2 + 1;
		int cm = (c0+c1) % 2 == 0 ? (c0+c1) / 2 : (c0+c1)/2 + 1;	
		convert_D_to_B(r0, rm, c0, cm);
		convert_D_to_B(r0, rm, cm, c1);
		convert_D_to_B(rm, r1, c0, cm);
		convert_D_to_B(rm, r1, cm, c1);
	}
}

int main()
{
	while (cin >> F)
	{
		if (F == '#') 
			break;
		else if (F == 'B')
		{
			cin >> R >> C; grid.assign(R, vector<char>(C));
			int n = 0;
			while (n < R*C)
			{
				string L; cin >> L;
				for (int i = 0; i < L.size(); i++)
				{
					grid[n/C][n%C] = L[i];
					n += 1;
				}
			}
			string converted = convert_B_to_D(0, R, 0, C);
			printf("D%4d%4d\n", R, C);
			for (int i = 0; i < converted.size(); i+=50)
				cout << converted.substr(i, min(50, (int)(converted.size())-i)) << endl;
		}
		else if (F == 'D')
		{
			cin >> R >> C >> input; 
			index = 0;
			output.resize(R*C);
			convert_D_to_B(0, R, 0, C);
			printf("B%4d%4d\n", R, C);
			for (int i = 0; i < output.size(); i+=50)
				cout << output.substr(i, min(50, (int)(output.size())-i)) << endl;
		}
	}
}
