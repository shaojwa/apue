Mutex中的Lock/Unlock是void类型，而ptherad_mutex_lock是有返回值的，怎么做这个一层屏蔽转换？

##### pthread_mutex_t 的安全使用
走读`void Mutex::lock(bool no_lockdep)`代码，pthread_mutex_lock当然会犯错，查看`man`我们知道：

If the mutex type is PTHREAD_MUTEX_NORMAL, deadlock detection shall not be provided.这种方式都是不安全的：
Attempting to relock the mutex causes deadlock. If a thread attempts to unlock a mutex that it has not locked or a mutex which is unlocked, undefined behavior results.
If the mutex type is PTHREAD_MUTEX_ERRORCHECK， 这是更好的方式。重复lock，或者unlock不是这个线程lock的mutex，或者这个mutex已经unlock，那么就会报错。

#### Mutex类进行的封装
