#ifndef __ADD_PAY_PTHEAD_H__
#define __ADD_PAY_PTHEAD_H__

#include <pthread.h>   //多线程
#include "salary_manage.h"
          
class add_pay
{
	public:
		int add_pay_pthread_create(salary_manage *sa_manage);

	private:
		static void *add_pay_manage(void *arg);
};

#endif
