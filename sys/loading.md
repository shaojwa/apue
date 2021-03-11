## 加载问题解决步骤

#### 先用ldd看 可执行文件加载的共享库版本对不对
```
ldd cephfs.so
```
或者可执行文件：
```
[wsh@node 23:34:58 /usr/local/lib ]$ ldd /usr/bin/testparm | grep ldb
    libldbsamba-samba4.so => /usr/lib64/samba/libldbsamba-samba4.so (0x00007f63af890000)
    libldb.so.1 => /lib64/libldb.so.1 (0x00007f63acde7000)
```

2. 再看库依赖库查找路径RPATH是否没有包含
```
readelf -d cephfs.so
```

3. 看`LD_LIBRARY_PATH`中的路径是否正确
```
echo $LD_LIBRARY_PATH
```

#### elf 中的符号查看

3. 如果需要查看`ELF`中的符号问题用`nm`
```
nm cephfs.so  | grep openv
```

## 共享库的加载路径
这个可以通过`ldconfig`命令查看，这个是系统默认的库加载路径，优先级非常低，按照顺序，应该是：
1. `ELF`文件中的`rpath`。
1. `LD_LIBRARY_PATH`路径。
1. `/etc/ld.so.conf`中指定的路径。
1. 可信路径`/lib` 和 `/lib64`。
