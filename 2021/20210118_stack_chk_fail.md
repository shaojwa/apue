stacks
```
1: (()+0x2b5f30) [0x560a6183ff30]
2: (()+0xf6d0) [0x7f8583a3e6d0]
3: (gsignal()+0x37) [0x7f8581fb5277]
4: (abort()+0x148) [0x7f8581fb6968]
5: (()+0x2f096) [0x7f8581fae096]
6: (()+0x2f142) [0x7f8581fae142]
7: (RCache::_enqueue_warm(rcache_object_t&)+0x304) [0x7f85859b7954]
8: (RCache::rcache_write(object_t const&, snapid_t, unsigned long long, unsigned long long, ...)+0xee) [0x7f85859c0dde]
9: (DCacheOPProc::do_sparse_read(DCacheOPProc::OpContext*, OSDOp&)+0x5a5) [0x7f85858f9925]
10: (DCacheOPProc::do_dse_ops(DCacheOPProc::OpContext*, std::vector<OSDOp, std::allocator<OSDOp> >&)+0x546) [0x7f8585917f56]
11: (DCacheOPProc::dcache_do_op_proc(DCacheOPProc::OpContext*, std::vector<OSDOp, std::allocator<OSDOp> >&)+0x1fe) [0x7f858591881e]
12: (()+0x65498d) [0x7f858591b98d]
13: (()+0x658544) [0x7f858591f544]
14: (()+0x113f39) [0x7f8586924f39]
15: (co::Task::Run()+0xba) [0x7f8586925086]
16: (co::Task::StaticRun(long)+0x20) [0x7f858692582e]
17: (make_fcontext()+0x21) [0x7f85869bc251]
```
asm:
```
RCache::_enqueue_warm(rcache_object_t&)():
  6f0650:       41 57                   push   %r15
  6f0652:       41 56                   push   %r14
  6f0654:       41 55                   push   %r13
  6f0656:       41 54                   push   %r12
  6f0658:       55                      push   %rbp
  6f0659:       48 89 f5                mov    %rsi,%rbp
  6f065c:       53                      push   %rbx
  6f065d:       48 89 fb                mov    %rdi,%rbx
  6f0660:       48 81 ec 38 01 00 00    sub    $0x138,%rsp
  6f0667:       48 83 05 31 2f cd 00    addq   $0x1,0xcd2f31(%rip)        # 13c35a0 <__gcov0._ZN6RCache13_enqueue_warmER15rcache_object_t>
  6f066e:       01
  6f066f:       64 48 8b 04 25 28 00    mov    %fs:0x28,%rax
  6f0676:       00 00
  6f0678:       48 89 84 24 28 01 00    mov    %rax,0x128(%rsp)
  6f067f:       00
  6f0680:       31 c0                   xor    %eax,%eax
  6f0682:       48 8b 07                mov    (%rdi),%rax
  6f0685:       48 8b 78 08             mov    0x8(%rax),%rdi
  6f0689:       80 bf 48 06 00 00 00    cmpb   $0x0,0x648(%rdi)
  6f0690:       0f 85 aa 00 00 00       jne    6f0740 <RCache::_enqueue_warm(rcache_object_t&)+0xf0>
  6f0696:       48 83 bd c8 00 00 00    cmpq   $0x0,0xc8(%rbp)
  6f069d:       00
  6f069e:       c6 85 90 00 00 00 01    movb   $0x1,0x90(%rbp)
  6f06a5:       48 8d 85 c8 00 00 00    lea    0xc8(%rbp),%rax
  6f06ac:       0f 85 7b 02 00 00       jne    6f092d <RCache::_enqueue_warm(rcache_object_t&)+0x2dd>
  6f06b2:       48 8b 93 08 01 c0 01    mov    0x1c00108(%rbx),%rdx
  6f06b9:       48 8d 8b 00 01 c0 01    lea    0x1c00100(%rbx),%rcx
  6f06c0:       48 83 05 d8 90 cd 00    addq   $0x1,0xcd90d8(%rip)
  6f06c7:       01
  6f06c8:       48 89 8d c8 00 00 00    mov    %rcx,0xc8(%rbp)
  6f06cf:       48 89 95 d0 00 00 00    mov    %rdx,0xd0(%rbp)
  6f06d6:       48 89 83 08 01 c0 01    mov    %rax,0x1c00108(%rbx)
  6f06dd:       48 89 02                mov    %rax,(%rdx)
  6f06e0:       48 83 83 f8 00 c0 01    addq   $0x1,0x1c000f8(%rbx)
  6f06e7:       01
  6f06e8:       48 83 05 80 2f cd 00    addq   $0x1,0xcd2f80(%rip)        # 13c3670 <__gcov0._ZN6RCache13_enqueue_warmER15rcache_object_t+0xd0>
  6f06ef:       01
  6f06f0:       48 8b 85 88 00 00 00    mov    0x88(%rbp),%rax
  6f06f7:       f0 48 01 83 98 00 c0    lock add %rax,0x1c00098(%rbx)
  6f06fe:       01
  6f06ff:       48 89 df                mov    %rbx,%rdi
  6f0702:       e8 69 97 dc ff          callq  4b9e70 <RCache::_lru_warm()@plt>
  6f0707:       48 83 05 69 2f cd 00    addq   $0x1,0xcd2f69(%rip)        # 13c3678 <__gcov0._ZN6RCache13_enqueue_warmER15rcache_object_t+0xd8>
  6f070e:       01
  6f070f:       48 8b 84 24 28 01 00    mov    0x128(%rsp),%rax
  6f0716:       00
  6f0717:       64 48 33 04 25 28 00    xor    %fs:0x28,%rax
  6f071e:       00 00
  6f0720:       0f 85 2e 02 00 00       jne    6f0954 <RCache::_enqueue_warm(rcache_object_t&)+0x304>
 ```
 ```
  6f0954:       e8 b7 86 dc ff          callq  4b9010 <__stack_chk_fail@plt>
 ```
 (0x7f85859b7954 - 0x304)- (6f0650-4b9010) = 0x7F8585780010
  
  
