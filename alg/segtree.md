
#### 用处

线段树，主要是用来高效地在一个数组上进行连续范围查询，同时也能有足够灵活性来对数组的元素进行修改。
比如常用的两个场景：（1）查询一段连续范围内元素的和。（2）在O(logn)的时间内找到一个连续范围内的最小值。

#### 缺点

可以改变数组中某个位置的值，或者改变一个子线段的值，但是好像不能添加元素。

#### 要求

只需要线性数量的内存，标准的线段树需要4n空间，要安全访问，4倍的空间是必要的。

#### 基础实现的问题

如果n不是2的幂，那么4n的属组中有不少位置是浪费掉的。因为实际用的元位置只有2n-1，所以是可以优化的。任何n总数量都是2n—1，所以其实可以改变遍历顺序。

#### 为什么值只需要2n-1个节点

这个只需用数学归纳法，当n=1时，只需要1个节点，当n=2时，需要2个节点，所以当任何n拆分成两部分，两个子部分满足2n-1，所以整个满足2n-1。

#### 数组大小

所以对于N只需要2N个数组就可以，而且第一个可以不用，所以写代码的时候可以简化为2N的数组即可。

#### 高效内存实现版
只用2N大小的数组，如果二叉树是中序遍历，

#### Euler tour traversal
pre-order traversal

#### 线段树的中序版本
中序版本的线段树，数组中的每一个元素都是被使用的。

## Advanced versions of Segment Trees
### More complex queries
#### Finding the maximum
change the function build and update.
#### Finding the maximum and the number of times it appears
##### Compute the greatest common divisor / least common multiple
```
p[i] = GCD(p[2*i], p[2*i+1])
p[i] = LCM(p[2*i], p[2*i+1])
```
#### Counting the number of zeros, searching for the k-th zero
```
find_kth(v) = k < v[2*p]? find_kth(2v) : find_k-nth(2v+1)
```
#### Searching for an array prefix with a given amount
#### Searching for the first element greater than a given amount
#### Finding subsegments with the maximal sum

## Practice Problems

zoj2859，hdu1166，hdu1754
