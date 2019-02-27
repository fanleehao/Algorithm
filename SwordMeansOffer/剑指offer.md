## 笔记

> 面试问题的引入

### 引言

#### 1. 斐波那契

斐波那契数列的递归和非递归分析：

**递归方法**：每一个数都需要按照两个子分支去计算下一节的数，存在着大量的重复计算；最坏的情况下，可以将计算次数统计为一个满二叉树，其复杂度为O(2^n^)

![1551097176311](assets/1551097176311.png)

```c++
long long fib2(size_t N) {
    if (N < 2) 
        return 1;
    return fib2(N - 1) + fib2(N - 2);
}
int main()
{
    printf("%lld", fib2(10));
    getchar();
}
```

**非递归方法**：

非递归方法，每一个数只计算一次；时间复杂度为O(N);

```c++
long long fib1(size_t N) {
    long long a = 0, b = 1, c = 0;
    if (N < 2) {
        return 1;
    }
    else {
        for (long long i = 2; i <= N; ++i) {
            c = a + b;
            a = b;  b = c;
        }
    }
    return c;
}
int main()
{
    printf("%lld", fib1(10));
    return 0;
}  //此算法最大的优点是不存在重复计算，故效率比递归算法快的多得多。
```

&nbsp;

### 基础知识

#### 2. 二维数组中的查找

- 二维数组从左到右、从上到下都是递增的，查找一个数是否存在；

- 思路1：暴力：

  ```java
  public boolean Find(int target, int [][] array) {
     for(int i=0;i<array.length;i++){
          int low=0;
          int high=array[i].length-1;
          while(low<=high){
              int mid=(low+high)/2;
              if(target>array[i][mid])
                  low=mid+1;
              else if(target<array[i][mid])
                  high=mid-1;
              else
                  return true;
          }
      }
      return false;        
  }
  ```

- 思路2：**技巧-**从左上角或者右上角，每次判断一下；小于target则可以剔除一行，大于则可以剔除一列；

  ```java
  public boolean Find(int target, int [][] array) {
      //右上角开始
      int j = array[0].length - 1; //列
      int i = 0;
      while(i <= array.length - 1 && j >= 0){
          if(array[i][j] > target)
              j--;
          else if(array[i][j] < target)
              i++;
          else
              return true;
      }
      return false;
  }
  ```

  ```c++
  bool Find(int target, vector<vector<int> > array) {        
      if(!array.empty()){
          int j = array[0].size() - 1;
          int i = 0;
          while(i <= array.size() - 1 && j >= 0){
              if(array[i][j] > target)
                  j--;
              else if(array[i][j] < target)
                  i++;
              else 
                  return true;
          }
      }        
      return false;
  }
  ```

  &nbsp;

#### 3. 空格替换

- 替换字符串中空格为其他字符串

  ```c++
  void replaceSpace(char *str,int length) {
          //按题意，length是以开辟的内存长度
          int oldLen = 0;
          int newLen = 0;
          int blank = 0;
          int i = 0;
          while(str[i] != '\0'){
              oldLen++;
              if(str[i]==' ')
                  blank++;
              i++;
          }
          newLen = oldLen + 2*blank;
          if(newLen> length)
              return;//超过就插入不了
          while(oldLen>=0){       //条件oldLen>newLen 非必须把？
              if(str[oldLen] == ' '){
                  str[newLen--] = '0';
                  str[newLen--] = '2';
                  str[newLen--] = '%';
              }
              else 
                  str[newLen--] = str[oldLen];
              oldLen--;
          }
  	}
  ```

- java

  ```java
  public String replaceSpace(StringBuffer str) {
      	//return str.toString().replaceAll("\\s", "%20");
          int oldLen = str.length();
          int blank = 0;
          for(int i = 0; i < oldLen; i++){
              if(str.charAt(i) == ' ')
                  blank++;
          }
          int newLen = oldLen + 2 * blank;
          str.setLength(newLen);
          int Oindex = oldLen - 1, Nindex = newLen - 1;
          for(;Oindex>=0 && Oindex < Nindex;Oindex--){
              if(str.charAt(Oindex)==' '){
                  str.setCharAt(Nindex--, '0');
                  str.setCharAt(Nindex--, '2');
                  str.setCharAt(Nindex--, '%');
              }
              else
                  str.setCharAt(Nindex--, str.charAt(Oindex));
          }
          return str.toString();
      }
  ```

&nbsp;

#### 4. 链表反转

- 倒序输出链表的值

- 思路1：使用栈来完成；先进后出

  ```java
  public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {        
      /*while(listNode != null){
          list.add(listNode.val);
          listNode = listNode.next;
      }         
      Collections.reverse(list);    //使用Collections的reverse方法，直接将list反转
      return list;*/
      Stack<Integer> s = new Stack<>();
      while(listNode != null){
          s.push(listNode.val);
          listNode = listNode.next;
      }
      ArrayList<Integer> arrayList = new ArrayList<Integer>();
      while(!s.empty()){
          arrayList.add(s.pop());
      }
      return arrayList;
  }
  ```

- 思路2：使用栈就可以使用递归，每当输出一个节点的值前，先递归输出他的上一个值。

  ```java
  public void solveRecursively(ListNode listNode){
      //ArrayList<Integer> list = new ArrayList<>();
      if (listNode != null) {
          if(listNode.next != null){
              solveRecursively(listNode.next);
          }
          System.out.println(listNode.val);
      }
      return;
  }
  ```

- 