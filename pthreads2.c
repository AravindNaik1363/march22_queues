//program to create thread.my_thread1 prints 0,my_thread2 prints 0-10 and main process prints 20-24

#include<stdio.h>
#include<unistd.h>//header file for sleep()
#include<pthread.h>//header file for pthread_create and pthread_join functions
int i,j,val=10;

void *my_thread1(void *arg)//function definition
{
  printf("thread1 is running and values in thread 1:\n");
  for(i=0;i<=val;i++)
  {
      printf("%d\n",i);
      sleep(2);//after prinitng each value waits for 2seconds and printd next value
  }
}
  
  void *my_thread2(void *arg)//function definition
{
  printf("thread2 is running and values in thread 2:\n");
  for(i=0;i<=val;i++)
  {
      printf("%d\n",i);
      sleep(2);//after prinitng each value waits for 2seconds and printd next value
  }
}
  
int main()
{
  pthread_t thread[2];//thread declaration
  char *msg1="Aravind";//input to my_thread1 function
  char *msg2="Naik";//input to my_thread1 function
  pthread_create(&thread[0],NULL,my_thread1,(void *)msg1);//function to create thread1 and compiler moves to line 8
  pthread_create(&thread[1],NULL,my_thread2,(void *)msg2);//function to create thread2 and compiler moves to line 18
  pthread_join(thread[0],NULL);//main function waits for my_thread1 to complete first and then executes main()function
  pthread_join(thread[1],NULL);//main function waits for my_thread2 to complete first and then executes main()function
  
  printf("inside main method:\n");
  for(j=20;j<25;j++)//this main method is executed only after my_thread1 amd my_thread2 completes execution
  {
      printf("%d\n",j);
      sleep(2);//after prinitng each value waits for 2seconds and printd next value
  }

  return 0;
}
