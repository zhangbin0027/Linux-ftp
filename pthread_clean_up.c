#include "func.h"

void clean_up(void *p)
{
	printf("clean_up func %d\n",(int)p);
}
void *thread(void *p)
{
	pthread_clean_up_push(clean_up,(void*)1);
	sleep(3);
	printf("I am wake up\n");
	pthread_exit(NULL);
	pthread_clean_up_pop(1);
}

int main()
{
	pthread_t pthid;
	int ret;
	ret=pthread_creat(&pthid,NULL,thread,NULL);
	if(ret!=0)
	{
		printf("pthread_create ret=%d\n",ret);
		return -1;
	}
	pthread_join(pthid,NULL);
	return 0;
}
