#include <bits/stdc++.h>
using namespace std;

int parent(int i){
	return (i-1)/2;
}
int left(int i){
	return (i*2)+1;
}
int right(int i){
	return (i*2)+2;
}
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void heapify(int a[],int i,int n){
	int l = left(i);
	int r = right(i);
	int max = i;
	
	if(l<n and a[max] < a[l]){
		max = l;
	}
	if(r<n and a[max] < a[r]){
		max = r;
	}
	
	if(max != i){
		swap(a[max], a[i]);
		heapify(a,max,n);
	}
}
void heapSort(int a[], int n){
	for(int i=0;i<n;++i){
		int j = i;
		while(j !=0 and a[parent(j)]<a[j]){
			swap(a[parent(j)],a[j]);
			j = parent(j);
		}
	}
	int i = n-1;
	while(i!=0){
		swap(a[0],a[i]);
		heapify(a,0,i--);
	}
}

int main(int argc, char** argv) {
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	
	heapSort(a, n);
	
	for(int i=0;i<n;++i){
		cout<<a[i]<<" ";
	}
	return 0;
}
