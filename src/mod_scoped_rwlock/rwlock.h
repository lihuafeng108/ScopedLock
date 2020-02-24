#ifndef __RWROCK_H__
#define __RWROCK_H__

#include <pthread.h>

namespace mod_scoped_rwlock
{
	class rwlock
	{
	public:
		inline rwlock()
		{
			::pthread_rwlock_init(&m_rw, 0);
		}

		inline ~rwlock()
		{
			::pthread_rwlock_destroy(&m_rw);
		}

		inline void rdlock()
		{
			::pthread_rwlock_rdlock(&m_rw);
		}

		inline void wrlock()
		{
			::pthread_rwlock_wrlock(&m_rw);
		}

		inline void unlock()
		{
			::pthread_rwlock_unlock(&m_rw);
		}

		inline void lock()
		{
			wrlock();
		}

	private:
	    //将编译器默认为类创建的copy构造函数，重构"="运算符这两个，声明为private(只声明不定义)。
	    //阻止对象拷贝，从而避免互斥量被拷贝。
	    rwlock(rwlock &);
	    rwlock & operator= (rwlock &);

		pthread_rwlock_t m_rw;  //读写锁变量
	};
}
#endif // !__RWROCK_H__
