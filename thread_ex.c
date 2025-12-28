#include<stdlib.h>
#include<pthread.h>
#include<stdio.h>
  void* calculate_sum(void* data){
    int* numbers=(int*)data;
    int* result=malloc(sizeof(int));
    *result=numbers[0]+numbers[1];
    return result;
  }

     int main(){

        pthread_t thread;
        int nums[]={10,20};
        pthread_create(&thread,NULL,calculate_sum,nums);

        void* ret_val;
        pthread_join(thread,&ret_val);
        int* sum=(int*)ret_val;
        printf("sum: %d\n",*sum);
        free(sum);
        return 0 ;

     }
