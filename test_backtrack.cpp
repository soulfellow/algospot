#include <iostream>

using namespace std;

//#define USE_SUBSETS_FUNC
#define NMAX			4
#define MAXCANDIDATES	10
bool finished = false;		// 모든 풀이를 찾았는지 여부

// 간단하게 말하자면 재귀에서 마지막 노드에 왔는가를 검사. 일종의 종료 조건.
bool is_a_solution(int a[], int k, int n)
{
	return (k==n);//?true:false;
}

//결과의 순서에 가장 영향을 끼치는 부분. 이 부분을 수정하여 다른 문제로 응용이 가능
//분기를 나누는데 결정되는 c배열의 값을 이 함수에서 구함.
//아래 code는 부분집합을 구하는 경우라 후보군의 갯수가 있고(true), 없고(false) 두가지 뿐임
void construct_candidates(int a[], int k, int n, int c[], int* ncandidates)
{
	#if 0			//모든 부분 집합을 구하기위한 construct_candidates
	c[0]=true;
	c[1]=false;
	*ncandidates=2;
	#else			//모든 순열을 구하기위한 construct_candidates
	int i;
	bool in_perm[NMAX] = {false,};
	
	for(i=0; i<k; ++i)
		in_perm[a[i]]=true;
	
	*ncandidates =0;
	for(i=1; i<=n; ++i)
	{
		if(in_perm[i] == false)
		{
			c[*ncandidates] = i;
			(*ncandidates)++;
		}
	}
	#endif
}

//마지막 노드까지 와서 출력하는 부분.(출력 이외의 output이 필요하면 이부분을 수정)
//is_a_solution에서 k(현재 재귀호출된 count)와 입력한 n 값을 비교한 후 끝까지 오면 호출 됨
void process_solution(int a[], int k)
{
	#if 0			//부분집합
	int i;
	printf("{");
	for(i=1; i<=k; ++i)
	{
		if(a[i] == true)
			printf(" %d",i);
	}
	printf(" }\n");
	#else			//순열
	int i;
	for(i=1; i<=k; ++i)
		printf(" %d", a[i]);
	printf("\n");
	#endif
}

void backtrack(int a[], int k, int input)
{
	int c[MAXCANDIDATES] = {0,};	//다음 위치가 될 수 있는 후보군 배열, c[x]에는 후보군의 값이 들어 있음
	int ncandidates;				//다음 위치가 될 수 있는 후보군 개수, construct_candidates에서 정해짐
	int i;							//카운터
	
	if(is_a_solution(a,k,input))
		process_solution(a,k);
		//process_solution(a,k,input);
	else
	{
		k=k+1;
		construct_candidates(a,k,input,c,&ncandidates);
		for(i=0; i<ncandidates; ++i)
		{
			a[k]=c[i];
			backtrack(a,k,input);
			if(finished)		//일찍 종료할 조건이 있다면 backtrack 호출되기전에 값을 바꾸어서 응용 가능
				return;
		}
	}
}

void generate_subsets(int n)
{
	int a[NMAX] = {false,};
	backtrack(a,0,n);
}


int main(void)
{
#if defined (USE_SUBSETS_FUNC)
	generate_subsets(3);
#else
	int a[NMAX] = {0,};
	int k;
	int n;	/* need resolved size */
	
	k = 0;
	n = 3;
	
	backtrack(a, k, n);
#endif

	return 0;
}