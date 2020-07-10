#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int H, W;
int image[200][400];
bool visited[200][400];

char conv[6] = { 'W', 'A', 'K', 'J', 'S', 'D' };
int dir[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

void setimage(int h, int w, char c)
{
	int n;
	if (c >= '0' && c <= '9') n = c - '0';
	if (c >= 'a' && c <= 'f') n = 10 + c - 'a';
	for (int i = 0; i < 4; i++) image[h][w*4+i] = (n >> (3 - i)) & 1;
}

int dfsw(int r, int c)
{
	if (r < 0 || c < 0 || r == H || c == W || visited[r][c] || image[r][c] == 1) return 0;
	visited[r][c] = true;
	for (int i = 0; i < 4; i++)
		dfsw(r+dir[i][0], c+dir[i][1]);
	return 1;
}

int dfsb(int r, int c)
{
	if (r < 0 || c < 0 || r == H || c == W || visited[r][c] || image[r][c] == 0) return 0;
	visited[r][c] = true;	
	int count = 0;
	for (int i = 0; i < 4; i++)
		count += dfsw(r+dir[i][0], c+dir[i][1]);
	for (int i = 0; i < 4; i++)
		count += dfsb(r+dir[i][0], c+dir[i][1]);
	return count;
}

int main()
{
	int T = 0;
	while (cin >> H >> W)
	{
		if (H == 0 && W == 0) break;
		string in;
		for (int h = 0; h < H; h++) for (int w = 0; w < W*4; w++) visited[h][w] = false; 
		for (int h = H-1; h >= 0; h--) 
		{
			cin >> in; 
			for (int w = 0; w < W; w++)
				setimage(h, w, in[w]);
		}
		W *= 4;

		/*
		for (int h = H-1; h >= 0; h--)
		{
			for (int w = 0; w < W; w++) cout << image[h][w];
			cout << endl;
		}
		*/

		vector<char> hiero;
		for (int r = 0; r < H; r++) dfsw(r, 0), dfsw(r, W-1);
		for (int c = 0; c < W; c++) dfsw(0, c), dfsw(H-1, c);
		for (int r = H-1; r >= 0; r--) for (int c = 0; c < W; c++)
		{
			if (image[r][c] == 1 && !visited[r][c])
			{
				int h = dfsb(r, c);	
				// printf("%d %d %c\n", r, c, conv[h]);
				hiero.push_back(conv[h]);
			}
		}
		sort(hiero.begin(), hiero.end());

		printf("Case %d: ", ++T);
		for (int i = 0; i < hiero.size(); i++)
			printf("%c", hiero[i]); printf("\n");
	}
}
