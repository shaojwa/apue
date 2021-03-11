今天注意到命令 last reboot 返回的时间段有重叠，重启操作导致的reboot时间段理论上不应该重叠。

last命令中，用户的登入和登出都会写入wtmp文件，last会往回搜索这个文件，得到用户的登入登出信息。
而reboot是一个特殊的用户，pseudo user，这个用户的信息在系统每次重启时记录，其实只是记录启动事件，通过last的-x选项我们可以发现这点。

同时-x会显示系统shutdown和run level改变的时间。从shutdown往前搜索，搜到一个reboot就确定一个时间段。
last reboot 时间的重叠常常伴随last -x中shutdown用户的system down事件和reboot 用户的system boot事件的不一致。

正常情况下，这两个事件是交替进行的。在不一致的场景下，通常会有某个用户下的crash事件。
其实时间段重叠的直接原因是很多shutdown事件没有被记录导致reboot用户的终止时间没有正确记录，最终用的一个更晚的shutdown时间。

没有正确记录的原因有意外断电，也有reboot带-d参数这样人为特意不写入shutdown事件。
所以其实时间重叠也是正常的现象，last只是去读取wtmp文件，要是文件本身数据就有偏差，那结果也就不可靠。
所以last得数据只是一种系统在没出异常时的参考。


* last -x  | grep reboot 等价于 last reboot
* reboot    用户的开始时间就是系统的启动时间
* shutdown  用户的时间段是关机时间但并不是所有的关机都有shutdown日志
* shutdown  命令不会产生shutdown日志???
