## What is 'alternate signal stack' in thread

#### How does thread be created in linux
pthreads是一套标准，或者说规范，那么linux下是怎么实现这套规范的？通过glibc。那么从系统调用层次来说，线程是如何被创建的？答案是clone系统调用。NTPL基于clone和内核模型提供过了1:1的线程模型，线程和其他任何进程没有太大区别，除了他们共享特性支援。

#### clone with CLONE_THREAD
用kill往clone(CLONE_THREAD)出来的thread发送信号，那么据说随意的一个没有block这个信号的线程会被执行，而且只会在一个线程上执行，但是据测试，一般是指定的那个线程执行。

#### 线程数量的限制两种可能
一般有两种，the RLIMIT_NPROC soft resource limit (set via setrlimit(2)),  which  limits  the  number  of  process  for  a  real  user  ID,  was  reached;
or the kernel's system-wide limit on the number of threads, /proc/sys/kernel/threads-max, was reached.

#### 线程创建默认的站大小
On Linux/x86-32, the default stack size for a new thread is 2 megabytes. 但是在当前的linux中的NPTL这种线程实现中，可以通过ulimit -s查看，一般是8192K。

#### pthread_create创建的线程的信号掩码
会继承调用线程的信号掩码，The new thread inherits a copy of the creating thread's signal mask。

#### pthread_create创建线程的pending信号集合
pending 信号集合为空。

#### pthread_create会继承调用线程的能力集
The new thread inherits copies of the calling thread's capability sets  (see  capabilities(7))

#### pthread_create会继承CPU亲和性
The new thread inherits copies of the calling thread's CPU  affinity  mask  (see sched_setaffinity(2)).

#### 线程的退出
pthread_create创建的线程退出有四种情况，可以参见man下pthread_create。

#### 只让某一个线程退出的方法
其实就是发信号，另外进程要先注册指定的信号处理函数，不然大部分的信号回让整个进程退出。
```
pthread_kill(h->thread_id, SIGABRT);
```

#### 线程的等待为什么叫join
join本意是加入，对应的detach叫分离。glibc中的thread_join调用lll_wait_tid 实现。

#### 线程有父线程么？
有父进程，进程的父进程可以通过ppid查看， ```cat /proc/<pid>/status``` 中的PPid字段查看到，所以我们也用同样的方法查看发现，所有的线程的ppid和主线程的ppid相同，也就是进程的ppid相同。
所以，线程没有父线程的概念，看不出由哪个线程创建。

#### linux clone 和 fork的区别是什么？
clone 有两种，一种是glibc的封装，一种是系统调用。clone 的man 说明是create一个child process，好像和fork没啥区别。
但是man明确说明，clone允许子进程共享父进程的部分 execution context，注意这里的执行上下文不是代码段，而是比较宽泛的概念，比如内存空间，文件描述符表，以及信号处理函数表。
所以clone很重要的一个应用就是实现线程。glibc的clone的很重要的一个区别是clone会指定入口函数，而不是fork一样子进程也往后执行同样的代码。
其实系统调用的clone和fork是差不多的，也是从父进程clone调用点开始往下执行。

#### linux中线程之间的同步系统调用是什么？
futex，系统调用是了解实现机制的分界线，系统提供的功能可以都从这里入手。
比如pthread中提供的pthread_mutex_lock,pthread_cond_t师傅不是都是基于fetux来实现的呢？
