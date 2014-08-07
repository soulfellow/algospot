#include <iostream>
#include <math.h>

using namespace std;

#define NMAX			9
#define MAXCANDIDATES	81
//bool finished = false;		// 모든 풀이를 찾았는지 여부
int solution_count =0;

bool is_a_solution(int a[], int k, int n,int b_cnt)
{
	return (k==b_cnt);//?true:false;
}

void construct_candidates(int a[], int k, int n, int b_cnt, int c[], int* ncandidates)
{
	int i, j, l, m;            // 카운터 //
	bool legal_move;   // 이동 가능 여부 //

	*ncandidates = 0;
	
	for(i=1; i <=n; ++i)
	{
		for(j=1; j<=n; ++j)
		{
			legal_move = true;
			int temp = n*(i-1)+j;	//현재 B를 넣으려는 index
			cout << "k : " << k << " B index : " << temp << "   ";
			for(l=1; l<k; ++l)
			{
				int temp_i = ((a[l]-1)/n)+1;	//이전 후보 B의 행
				int temp_j = a[l]%n;			//이전 후보 B의 열
				if(temp_j == 0)				//나머지가 0이면 마지막 열
					temp_j = n;
				
				if(abs(i-temp_i) == abs(j-temp_j) || temp == a[l])	//대각선 check, 같은위치
				{
					legal_move = false;
					break;
				}				
				
				#if 0
				//a[l]은 이전에 B를 넣었던 index
				if(temp %n == 1)	//첫 열은 왼쪽 위 대각선 check하면 안됨
				{
					for(m=1; m<=k;++m){
						if(temp-((n-1)*m) == a[l])		//오른쪽 위 대각선						
						{
							legal_move = false;
							break;
						}
					}
					if(!legal_move)	break;
				}
				else if(temp%n == 0)	//마지막 열은 오른쪽 위 대각선 check하면 안됨
				{
					for(m=1; m<=k;++m){
						if(temp-((n+1)*m) == a[l])		//왼쪽 위 대각선
						{
							legal_move = false;
							break;
						}
					}
					if(!legal_move)	break;
				}
				else
				{
					for(m=1; m<=k;++m){
						if(temp-((n+1)*m) == a[l]		//왼쪽 위 대각선
						|| temp-((n-1)*m) == a[l])		//오른쪽 위 대각선
						{
							legal_move = false;
							break;
						}
					}
					if(!legal_move)	break;
				}
				#endif				
			}
			
			if(legal_move == true)
			{
				cout << *ncandidates << " candidates : " << temp;
				c[*ncandidates] = n*(i-1)+j;	//temp
				(*ncandidates)++;
			}
			cout << endl;
		}
	}
	#if 0
	for(i=1; i<=n; i++)		// 열을 조사
	{
		legal_move = true;
		
		for(j=1; j<k; j++)	// 행을 조사
		{
				// 대각선 방향 or 같은 열
				//k : Q을 놓을 행, j : 첫번부터 k 이전까지 행(Q가 놓인 행)
				//i : 탐색중인 열, a[j] : 이전에 Q가 놓인 열
				if( abs( (k) -j ) == abs( i - a[j] )) 
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
	#endif
}

void process_solution(int a[], int k, int n, int b_cnt)
{
	int l=1;
	solution_count++;

	printf("\n");
	
	for( int i=1 ; i<=n ; i++ )
	{
		for( int j=1 ; j<=n ; j++ )
		{
				if( a[l] == n*(i-1)+j)
				{
					printf("B");
					l++;
				}
				else
					printf(".");
		}
		printf("\n");
	}
	printf("\n");
	
	#if 0
	for( int i=1 ; i<=n ; i++ )
	{
		for( int j=1 ; j<=n ; j++ )
		{
				if( a[l] == i)
						printf("B");
				else
						printf(".");
		}
		printf("\n");
	}
	printf("\n");
	#endif
}

void backtrack(int a[], int k, int n, int b_cnt)
{
	int c[MAXCANDIDATES] = {0,};	//다음 위치가 될 수 있는 후보군 배열, c[x]에는 후보군의 값이 들어 있음
	int ncandidates;				//다음 위치가 될 수 있는 후보군 개수, construct_candidates에서 정해짐
	int i;							//카운터
	
	if(is_a_solution(a,k,n,b_cnt))
		process_solution(a,k,n,b_cnt);
	else
	{
		k=k+1;
		construct_candidates(a,k,n,b_cnt,c,&ncandidates);
		cout << "ncandidates : " << ncandidates<< endl;
		for(i=0; i<ncandidates; ++i)
			cout << "c[" << i<<"] : " << c[i] << endl;
			
		for(i=0; i<ncandidates; ++i)
		{
			a[k]=c[i];
			backtrack(a,k,n,b_cnt);
			//if(finished)	return;
		}
	}
}

void generate_subsets(int n, int b_cnt)
{
	int a[NMAX] = {false,};
	solution_count = 0;
	backtrack(a,0,n, b_cnt);
	for(int i=0; i < NMAX; ++i)
		cout << "a[" << i<<"] : " << a[i] << endl;
	printf("n = %d, b_cnt = %d, solution_count = %d\n", n, b_cnt, solution_count);
}

int main(void)
{
	int n = 4;
	int b_cnt = 4;
	generate_subsets(n,b_cnt);

	return 0;
}