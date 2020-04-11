#include<iostream>
#include <pthread.h>
using namespace std;
int n,i;
int fib[500]; 
void *fibon(void *value) 
{ 
    if (n<0)
       pthread_exit(0);
	fib[0] = 0; 
    if (n>1){
	  fib[1]=1;
      for (i=2;i<n;i++)
          fib[i]=fib[i-1]+ fib[i-2];
    }
    pthread_exit(0);
}
int main(int arg,char *argv[])
{
	pthread_t id;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	printf("Enter the no. of values: ");
	cin>>n;
	if(n<=500)
	{
	   pthread_create(&id, &attr,fibon, argv[1]);
	   pthread_join(id,NULL);
	   if (n>=0)
	      cout<<fib[0]<<endl;
	   for (i=1;i<n;i++)
	      cout<<fib[i]<<endl;
    }
    else
       cout<<"Exceeds the limit.";
	cout<<endl;
	return 0;

}
    

