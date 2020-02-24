#ifndef __SCOPED_RWROCK_H__
#define __SCOPED_RWROCK_H__

namespace mod_scoped_rwlock
{
	class scoped_rdlock
	{
		public:
			inline scoped_rdlock(rwlock& lock):m_lock(lock)
			{
				m_lock.rdlock();
			}

			inline ~scoped_rdlock()
			{
				m_lock.unlock();
			}

		private:
			//禁止对象拷贝
			scoped_rdlock(scoped_rdlock&);
			scoped_rdlock& operator=(scoped_rdlock&);
			
			rwlock& m_lock;  //引用的一个读锁变量
			
	};

	class scoped_wrlock
	{
		public:
			inline scoped_wrlock(rwlock& lock):m_lock(lock)
			{
				m_lock.wrlock();
			}

			inline ~scoped_wrlock()
			{
				m_lock.unlock();
			}

		private:
			//禁止拷贝
			scoped_wrlock(scoped_wrlock &);
			scoped_wrlock & operator= (scoped_wrlock &);
				
			rwlock& m_lock;
	};
}
#endif
