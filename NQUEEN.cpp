#include <iostream>
#include <math.h>

using namespace std;

#define NMAX			13
#define MAXCANDIDATES	16
//bool finished = false;		// 모든 풀이를 찾았는지 여부
int solution_count =0;

bool is_a_solution(int a[], int k, int n)
{
	return (k==n);//?true:false;
}

void construct_candidates(int a[], int k, int n, int c[], int* ncandidates)
{
	int i, j;            // 카운터 //
	bool legal_move;   // 이동 가능 여부 //

	*ncandidates = 0;
	
	for(i=1; i<=n; i++)		// 열을 조사
	{
		legal_move = true;
		
		for(j=1; j<k; j++)	// 행을 조사
		{
				// 대각선 방향 or 같은 열
				//k : Q을 놓을 행, j : 첫번부터 k 이전까지 행(Q가 놓인 행)
				//i : 탐색중인 열, a[j] : 이전에 Q가 놓인 열
				if( abs( (k) -j ) == abs( i - a[j] ) || i == a[j] ) 
				{
						legal_move = false;
						break;
				}
		}
		if( legal_move == true )
		{
				c[*ncandidates] = i;
				*ncandidates = *ncandidates + 1;
		}
	}
}

void process_solution(int a[], int k, int n)
{
	solution_count++;	
}

void backtrack(int a[], int k, int input)
{
	int c[MAXCANDIDATES] = {0,};	//다음 위치가 될 수 있는 후보군 배열, c[x]에는 후보군의 값이 들어 있음
	int ncandidates;				//다음 위치가 될 수 있는 후보군 개수, construct_candidates에서 정해짐
	int i;							//카운터
	
	if(is_a_solution(a,k,input))
		process_solution(a,k,input);
	else
	{
		k=k+1;
		construct_candidates(a,k,input,c,&ncandidates);
		for(i=0; i<ncandidates; ++i)
		{
			a[k]=c[i];
			backtrack(a,k,input);
			//if(finished)	return;
		}
	}
}

void generate_subsets(int n)
{
	int a[NMAX] = {false,};
	solution_count = 0;
	backtrack(a,0,n);
	printf("%d\n",solution_count);
}

int main(void)
{
	int loop, n;
	
	cin >> loop;

	while(loop--)
	{
		n =0;
		cin >> n;
		generate_subsets(n);
	}
	
	return 0;
}