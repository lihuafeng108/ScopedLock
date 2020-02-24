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
	    //��������Ĭ��Ϊ�ഴ����copy���캯�����ع�"="�����������������Ϊprivate(ֻ����������)��
	    //��ֹ���󿽱����Ӷ����⻥������������
	    rwlock(rwlock &);
	    rwlock & operator= (rwlock &);

		pthread_rwlock_t m_rw;  //��д������
	};
}
#endif // !__RWROCK_H__
