#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int n;
void *average(void* args){
	int *arr=(int*)args;
	int sum=0;
	float *f=(float*)malloc(sizeof(float));
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	*f=sum/n;
	pthread_exit(f);
}
void *minimum(void* args){
	int *arr=(int*)args;
	int *min=(int*)malloc(sizeof(int));
	*min=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]<*min){
			*min=arr[i];
		}
	}
	pthread_exit(min);
}
void *maximum(void* args){
	int *arr=(int*)args;
	int *max=(int*)malloc(sizeof(int));
	*max=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>*max){
			*max=arr[i];
		}
	}
	pthread_exit(max);
}
int main(){
	pthread_t thAvg,thMax,thMin;
	n=3;
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	float *avg=(float*)malloc(sizeof(float));
	pthread_create(&thAvg,NULL,average,(void*)&arr);
	pthread_join(thAvg,(void**)&avg);
	pthread_create(&thMin,NULL,minimum,(void*)&arr);
	int *min=(int*)malloc(sizeof(int));
	pthread_join(thMin,(void**)&min);
	int *max=(int*)malloc(sizeof(int));
	pthread_create(&thMax,NULL,maximum,(void*)&arr);
	pthread_join(thMax,(void**)&max);
	printf("Average: %f\nMinimum: %d\nMaximum: %d\n",*avg,*min,*max);
	return 0;
}
