#ifndef __SUB_PAY_PTHREAD_H__
#define __SUB_PAY_PTHREAD_H__

#include "pthread.h"

class sub_pay
{
	public:
		int sub_pay_pthread_create(salary_manage *sa_manage)
		{
			pthread_t pthread;
		    pthread_attr_t attr;
		    pthread_attr_init(&attr);
		    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
			
		    return pthread_create(&pthread, &attr, sub_pay_manage, (void *)sa_manage);
		}

	private:
		static void *sub_pay_manage(void *arg)
		{
			salary_manage *p_sa = (salary_manage *)arg;
			bool always_ture = true;


			while (always_ture)
			{
				p_sa->salary_sub_pay();

				usleep(10*1000);
			}
		}
	
};

#endif
