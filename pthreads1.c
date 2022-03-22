//program to create thread.my_thread prints 0-4 and main process prints 20-24

#include<stdio.h>
#include<unistd.h>//header file for sleep()
#include<pthread.h>//header file for pthread_create and pthread_join functions
int i,j;

void *my_thread(void *arg)//function definition
{
  printf("inside thread:\n");
  for(i=0;i<5;i++)
  {
      printf("%d\n",i);
      sleep(2);//after prinitng each value waits for 2seconds and printd next value
  }
}
  
int main()
{
  pthread_t thread1;//thread declaration
  pthread_create(&thread1,NULL,my_thread,NULL);//function to create thread and compiler moves to line 8
  pthread_join(thread1,NULL);//main function waits for my_thread to complete first and then executes main()function
  printf("inside main method:\n");
  for(j=20;j<25;j++)//this main method is executed only after my_thread completes execution
  {
      printf("%d\n",j);
      sleep(2);//after prinitng each value waits for 2seconds and printd next value
  }
  return 0;
}
