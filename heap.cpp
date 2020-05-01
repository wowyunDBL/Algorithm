#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Queue{
  private:
	int *A;
	int length;
	int heap_size;
  public:
	Queue();
	void max_heapify(int i);
	void build_max_heap();
	void heap_sort();

	int LEFT(int i){return 2*i;}
	int RIGHT(int i){return 2*i+1;}
	void swap(int &a,int &b);
};

void Queue::max_heapify(int i)
{
	int l,r,largest;
	l = LEFT(i);
	r = RIGHT(i);
	if(l<=heap_size)
	{
		if(A[l]>A[i])
			largest = l;
	}
	else
		largest = i;
	if(r<=heap_size)
	{
		if(A[r]>A[largest])
			largest = r;
	}
	if(largest != i){
		//exchange A[i] with A[largest]
		swap(A[i],A[largest]);
		//cout<<A[i]<<" "<<A[largest]<<endl;
		max_heapify(largest);
	}
}
void Queue::build_max_heap()
{
	heap_size = length;
	for(int i=(heap_size/2); i>0; i--)
		max_heapify(i);
	
}
void Queue::heap_sort()
{
	cout<<"here";	
	build_max_heap();
	
	for(int i=length; i>1; i--)
	{
		swap(A[1],A[heap_size]);
		heap_size--;
		max_heapify(1);			
	}
	for(int i=1; i<=length; i++)
		cout<<A[i]<<" "; 
	
}
void Queue::swap(int &a,int &b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
Queue::Queue()
{
	A = new int [17];  // I don't use A[0]
	length = 16;
	srand(5);
	A[0] = 0;
	for(int i=1; i<=length; i++)
	{
		A[i] = rand()%50;
		cout<<A[i]<<" "; 
	}
	cout<<endl;
}
int main(int argc, char **argv)
{
	Queue 	q;
	cout<<"here";
	q.heap_sort();

	return 0;
}
