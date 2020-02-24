#include "salary_manage.h"
#include "add_pay_pthread.h"
#include "sub_pay_pthread.h"

int main(void)
{
	salary_manage lihf(3711);
	add_pay add_manage;
	sub_pay sub_manage;

	add_manage.add_pay_pthread_create(&lihf);
	sub_manage.sub_pay_pthread_create(&lihf);

	bool always_true = true;
	while(always_true)
	{
		lihf.salary_dispay_info();

		usleep(500*1000);
	}
	return 0;	
}
