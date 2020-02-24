#ifndef __SALARY_MANAGE_H__
#define __SALARY_MANAGE_H__

#include <iostream>
using namespace std;   //不加这个cout用不了哦

#include "mod_scoped_rwlock.h"

struct pay_t
{
	int id;      //工号
	int add_cnt; //加工资次数
	int sub_cnt; //减工资次数
	int tal_pay; //工资总额
};

class salary_manage
{
public:
	salary_manage(int id)
	{
		memset(&m_pay, 0, sizeof(m_pay));
		m_pay.id = id;
	}

	void salary_add_pay(void)
	{
		mod_scoped_rwlock::scoped_wrlock wrlock(m_rwlock);  //上锁解锁就一句话

		m_pay.add_cnt++;
		m_pay.tal_pay++;
	}

	void salary_sub_pay(void)
	{
		mod_scoped_rwlock::scoped_wrlock wrlock(m_rwlock); 

		m_pay.sub_cnt--;
		m_pay.tal_pay--;
	}

	pay_t salary_get_payinfo(void)
	{
		mod_scoped_rwlock::scoped_rdlock rdlock(m_rwlock);

		return m_pay;
	}

	void salary_dispay_info(void)
	{
		mod_scoped_rwlock::scoped_rdlock rdlock(m_rwlock);

		cout<<"ID:"<<m_pay.id<<endl;
		cout<<"Add_cnt:"<<m_pay.add_cnt<<endl;
		cout<<"Sub_cnt:"<<m_pay.sub_cnt<<endl;
		cout<<"Tal_pay:"<<m_pay.tal_pay<<endl;
	}

private:
	pay_t m_pay;
	mod_scoped_rwlock::rwlock m_rwlock;  //类资源管理所
};
#endif
