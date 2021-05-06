http://oliveryang.net/2015/09/pitfalls-of-TSC-usage/

tsc是intel从pentium开始引入的一个64位寄存器，tsc寄存器在gdb中是看不到的。用法如下：
```
#include <unistd.h>
#include <iostream>
using namespace std;

uint64_t tsc_cycles() {
  uint32_t low, high;
  asm volatile("rdtsc": "=a"(low), "=d"(high));
  return (uint64_t(low) | uint64_t(high) << 32);
}

int  main() {
  uint64_t start, end;
  start = tsc_cycles();
  sleep(10);
  end = tsc_cycles();
  cout << "duration "  << end - start << endl;
  return 0;
}
```
跑一下，时钟周期是：`16，960，812，513`,看来CPU的频率并不高？用`lscpu`看到
```
Architecture:          x86_64
CPU op-mode(s):        32-bit, 64-bit
Byte Order:            Little Endian
CPU(s):                12
On-line CPU(s) list:   0-11
Thread(s) per core:    1
Core(s) per socket:    6
Socket(s):             2
NUMA node(s):          2
Vendor ID:             GenuineIntel
CPU family:            6
Model:                 79
Model name:            Intel(R) Xeon(R) CPU E5-2603 v4 @ 1.70GHz
Stepping:              1
CPU MHz:               1696.142
CPU max MHz:           1700.0000
CPU min MHz:           1200.0000
BogoMIPS:              3392.28
Virtualization:        VT-x
L1d cache:             32K
L1i cache:             32K
L2 cache:              256K
L3 cache:              15360K
NUMA node0 CPU(s):     0-5
NUMA node1 CPU(s):     6-11
```
看来确实基本对的上。
