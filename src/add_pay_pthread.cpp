#include <pthread.h>
#include "add_pay_pthread.h"

int add_pay::add_pay_pthread_create(salary_manage *sa_manages)
{
	pthread_t pthread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	
    return pthread_create(&pthread, &attr, add_pay_manage, (void *)sa_manages);
}

void *add_pay::add_pay_manage(void *arg)
{
	salary_manage *p_sa = (salary_manage *)arg;
	bool alway_true = true;

	while(alway_true)
	{
		p_sa->salary_add_pay();
		usleep(1000*2);
	}	
}


