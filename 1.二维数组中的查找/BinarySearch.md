# 二分查找

## 二分查找的两种写法

```
这里假定给定了一个排序好array,有两种方法来实现二分查找。这里用l和h来指代查找的范围的上下限。h对应于array的最后一个元素和array对应于array最后一个元素下一个位置，分别对应于两种写法。
```

1.**h指代array最后一个元素的位置写法**

​	在学习数据结构的时候以及看网上的一些博客的时候看到的都是这种写法。查找的过程是，比较正在查找区间中间位置的元素值与带查找元素进行比较。这里的中间位置通常是，上下标和的平均值取整。如果中间值等于查找的元素，返回找到元素。如果中间值大于待查找值，说明当前查找区间包含中间值的后半部分的元素肯定都大于带查找元素，于是更新查找区间为不包含中间元素的前半部分区间。如果查找的元素值大于中间值，说明当前查找区间包含中间值的前半部分的元素都是小于带查找值的，于是更新查找区间为此时查找区间的后半部分。通过，这种查找区间减半的方法，如果原区间中有等于带查找值的元素，则必然可以找到。如果没有则上限的更新值会小于下限，退出查找。

​	具体的代码实现如下

```cpp
bool BinarySearch(int target, int array[], int length){
    int l = 0;
    int h = length-1;
    while(l <= h){
        int mid = (l + h) / 2;
        if(array[mid] == target)
            return true;
        else if(array[mid] > target)
            l = mid + 1;
        else h = mid - 1;
    }
    return false;
}
```

​		

2.**使用左开右闭区的间写法**

[l,h)

```cpp
bool BinarySearch(int target, int array[], int length){
    int l = 0;
    int h = length;
    while(l < h){
        int mid = l + (h-l) / 2;
        if(array[mid] == target)
            return true;
        else if(array[mid] > target)
            l = mid + 1;
        else h = mid;
    }
    return false;
}
```



---

第一种写法非常的直观。通过分别对l和h分别加一和减一的操作，有着很明确的缩短区间的意思，写的时候不容易出错。在循环判断的时候，需要理解的是，由于上下限都指的是区间中的元素，所以，当l==h的时候，搜索的范围任然在区间中。只有当l > h的时候，区间才失效。

第二种写法，符合写for循环时候的习惯。即对于一个n个元素的数组，[0,n)的遍历过程对应着n此循环，而且指明了区间的长度是n-0 = 0。对于把这种方法用到二分搜索中，就可以提现这样的优点：1.[l,h) 中h-l就是区间的长度 2.当数组元素为空的时候，l == h，没有负数出现。 3.如果需要查找数组中第一个不小于待查元素的位置，对比使用第一种的写法返回h+1,l和h都可以作为返回结果。4.这种写法正好对应于STL中函数传入区间的写法。

注意

```cpp
int mid = (l + h)/2;
//等价于
int mid = l + (h - l)/2;
//因为
mid = (l + h)/2 = (h - l + 2*l)/2 = l + (h-l)/2
```



第二种写法更为符合C++算法库Algorithm中函数的传参特点，有点更为明显。



引用：

* https://www.zhihu.com/question/36132386?sort=created 



## 查找第一个不小于待查元素的位置

```cpp
int BinarySearch(int target, int array[], int length){
    int l = 0;
    int h = length-1;
    while(l <= h){
        int mid = (l + h) / 2;
        if(array[mid] >= target)
            h = mid - 1;
        else l = mid + 1;
    }
    return h+1;
}
```



如果使用开区间来写的话，其实实现的就是C++中

* std::lower_bound https://en.cppreference.com/w/cpp/algorithm/lower_bound

```cpp
int BinarySearch(int target, int array[], int length){
    int l = 0;
    int h = length;
    while(l < h){
        int mid = l + (h - l)/2;
        if(array[mid] >= target)
            h = mid;
        else l = mid + 1;
    }
    return l；
}
```



类似的，如果是查找不大于待查元素的最后一个位置，将array[mid] == target并入到 if(array[mid] < target)中就可以了。也就是std::upper_bound
