#include <iostream>

using namespace std;

#define MAXARRAYLEN		3
#define MAXCANDIDATES	10
bool finished = false;

bool is_a_solution(int a[], int k, int n)
{
	return (k==n)?true:false;
}

void construct_candidates(int a[], int k, int n, int c[], int* ncandidates)
{
	c[0]=true;
	c[1]=false;
	*ncandidates=2;
}

void process_solution(int a[], int k)
{
	int i;
	printf("{");
	for(i=1; i<=k; ++i)
	{
		if(a[i] == true)
			printf(" %d",i);
	}
	printf(" }\n");
}

void backtrack(int a[], int k, int input)
{
	int c[MAXCANDIDATES];
	int ncandidates;
	int i;
	
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
			if(finished)
				return;
		}
	}
}

int main(void)
{
	int a[MAXARRAYLEN] = {1,2,3};
	int k;
	int n;	/* need resolved size */
	
	k = 0;
	n = 3;
	
	backtrack(a, k, n);

	return 0;
}