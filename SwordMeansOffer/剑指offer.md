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


&nbsp;

#### 5. 重建二叉树

- 根据前序遍历和中序遍历，构建二叉树

- 从前序遍历中找打一个点，找到其在中序遍历的位置，前后分成两棵子树

  ```c++
  /**
   * Definition for binary tree
   * struct TreeNode {
   *     int val;
   *     TreeNode *left;
   *     TreeNode *right;
   *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   * };
   */
  class Solution {
  public:
      TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
          int len = pre.size() - 1;
          return buildTree(pre, 0, len, vin, 0, len);
      }
      TreeNode *buildTree(vector<int>& preorder, int preL, int preR, vector<int>& inorder, int inL, int inR){
          if(preL > preR) //遍历到头
              return NULL;
          int index = inL;
          while(preorder[preL] != inorder[index])
              index++;
          int numL = index - inL;
          TreeNode* root = new TreeNode(preorder[preL]);
          root->left = buildTree(preorder, preL+1, preL+numL, inorder, inL, index-1);
          root->right = buildTree(preorder, preL+numL+1, preR, inorder, index+1, inR);
          return root;
      }
  };
  ```

  ```java
  /**
   * Definition for binary tree
   * public class TreeNode {
   *     int val;
   *     TreeNode left;
   *     TreeNode right;
   *     TreeNode(int x) { val = x; }
   * }
   */
  public class Solution {
      public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
          int len = pre.length - 1;  //length 是数组的属性，length()是字符串的方法
          return buildTree(pre,0,len,in,0,len);
      }
      public TreeNode buildTree(int[] pre, int preL, int preR, int[] in, int inL, int inR){
          if(preL > preR)
              return null;
          int index = inL;
          while(pre[preL] != in[index])
              index++;
          int numL = index - inL;
          TreeNode root = new TreeNode(pre[preL]);
          root.left = buildTree(pre,preL+1,preL+numL,in,inL,index-1);
          root.right = buildTree(pre,preL+numL+1,preR,in,index+1,inR);
          return root;
      }
  }
  ```

&nbsp;

#### 6. 用两个栈实现队列

- 分析：如stack1和stack2；当压入栈时，直接放入stack1；弹出时，若stack2为空，则把stack1的元素依次弹出压入到stack2中，则stack2的栈顶元素就是队列应该出的元素。

- **引申**：两个队列模拟栈；每次入queue1，出队时，除queue1最后一个元素，其他都到queue2中，删除queue1的剩余元素。*始终维护一个空队列，一个有数据的队列*

  ```java
  import java.util.Stack;
  
  public class Solution {
      Stack<Integer> stack1 = new Stack<Integer>();
      Stack<Integer> stack2 = new Stack<Integer>();
      
      public void push(int node) {
          stack1.push(node);
      }
      
      public int pop() {
          if(stack2.empty()){
             while(!stack1.empty()){
                 int k = stack1.pop();
                 stack2.push(k);
             } 
          }
          return stack2.pop();
      }
  }
  ```

  ```c++
  class Solution
  {
  public:
      void push(int node) {
          stack1.push(node);
      }
      int pop() {
          int k;
          if(stack2.empty()){
              while(!stack1.empty()){
                  k = stack1.top();
                  stack2.push(k);                
                  stack1.pop();
              }
          }
          k = stack2.top();
          stack2.pop();
          return k;
      }
  
  private:
      stack<int> stack1;
      stack<int> stack2;
  };
  ```

&nbsp;

#### 7. 旋转数组的最小数字

- 旋转数组中，找到最小的那个数；

- 思路：最小值在前后分界点上，且是右边的第一个数。分析二分的时候，注意mid的值与前后left、right的值进行比较；若mid<=right的值，则剔除掉右半部分，反之剔除左半边部分，注意边界控制；

- 备注：当数组中有重复元素时，要考虑特殊情况；

  ```c++
  int minNumberInRotateArray(vector<int> rotateArray) {
          int left = 0;
          int right = rotateArray.size()-1;
          if(rotateArray.empty())  return 0;
          int mid = left;
          while(rotateArray[left] >= rotateArray[right]){
              if(right-left==1){
                  mid = right;
                  break;
              }
              mid = (left + right) / 2;
              if(rotateArray[left]==rotateArray[right] && rotateArray[mid]==rotateArray[left])
                  return MinInOrder(rotateArray, left, right);
              if(rotateArray[mid] <= rotateArray[right]){
                  //右边递增序列中
                  right = mid;
              }
              else if(rotateArray[mid] >= rotateArray[left]){
                  left = mid;
              }
          }
          return rotateArray[mid];
      }
      int MinInOrder(vector<int> rotateArray, int left, int right){
          int res = rotateArray[left];
          for(int i = left+1;i<=right;i++){
              if(rotateArray[i] < res)
                  res = rotateArray[i];
          }
          return res;
      }
  ```

&nbsp;

#### 8. 菲波那切数列

- 递归与非递归

  ```c++
  int Fibonacci(int n) {
          if(n<2)
              return n;
          //return Fibonacci(n-1)+Fibonacci(n-2);
          int f0 = 0, f1 = 1;
          int res;
          while(n>=2){
              res = f0 + f1;
              f0 = f1;
              f1 = res;
              n--;
          }
          return res;
      }
  ```

  ```c++
  //青蛙跳台阶
  int jumpFloor(int number) {
          if(number<=2)
              return number;
          int res;
          int f0 = 1, f1 = 2;
          while(number>2){
              res = f0 + f1;
              f0 = f1;
              f1 = res;
              number--;
          }
          return res;
      }
  //青蛙跳台阶2
  int jumpFloorII(int number) {
          if(number<=2)
              return number;
          int f1 = 1,f2 = 1;
          int res = 0, f3 = 2;
          for(int i = 2; i <= number; i++){
              res += f3;  //累加
              f3 = res;
          }
          //return res;
          return pow(2,number-1);
      }
  ```

  ```c++
  //矩形覆盖
  int rectCover(int number) {
          if(number<=2)
              return number;
          int f1 = 1,f2 = 2;
          int res;
          for(int i = 2; i < number; i++){
              res = f1 + f2;
              f1 = f2;
              f2 = res;
          }
          return res;
      }
  ```

&nbsp;

#### 9. 二进制中1的个数

- 判断一个数的二进制中1的个数

- > 数字左移操作无区别；右移操作对无符号整数高位补0，有符号整数高位补符号数

- 思路1：使用位移操作，每次比较最右边的是不是1（和1与操作），然后右移一位；这样容易出现负数的死循环问题。改用一个flag，从1开始，每次左移一位，进行与操作。这样将会循环很多次（int型循环32）。

  ```c++
  int  NumberOf1(int n) {
       //避免右移操作，造成负数（有符号数）的死循环
       int cnt = 0;
       unsigned int flag = 1;
       while(flag){
           if(n & flag)
               cnt++;
           flag = flag << 1; //左移一位，直到32位次循环结束
       }
       return cnt;
   }
  ```

- 思路2：“一个数减一操作后再和该数进行与操作，可以把该数最右边的1变为0”

  ```c++
  int  NumberOf1(int n) {
       int cnt = 0;
       while(n){
           cnt++;
           n = (n - 1) & n;
       }
       return cnt;
   }
  ```

&nbsp;

### 高质量的代码

#### 10. 数值的整数次方

- 求一个数的整数次方，实现库函数的Pow操作。

- 注意点：一是长度问题，如果用double类型，一定注意判断相等的方式。要考虑异常边界

  ```c++
  class Solution {
  public:
      double Power(double base, int exponent) {
          if(equal(base, 0.0) && exponent < 0)   //注意精度问题
              return 0.0;
          unsigned int absEx = (unsigned int) exponent;
          if(exponent < 0)
              absEx = (unsigned int) -exponent;
          double ret = PowerWithUnsignedEx(base, absEx);
          if(exponent < 0)
              return 1.0 / ret;
          return ret;        
      }
      bool equal(double x, double y){
          if((x - y > -0.0000001) && (x - y < 0.0000001))
              return true;
          return false;
      }
      double PowerWithUnsignedEx(double base, unsigned int exponent){
          double ret = 1.0;
          for(unsigned int i = 1; i <= exponent; i++){ //此处容易类型不匹配出错
              ret *= base;
          }
          return ret;
      }
  };
  ```

- 思路2：可以使用递归的方式。每次取平方根进行平方操作。考虑奇偶变化。使用位移操作是亮点。

  ```c++
  double PowerWithUnsignedEx2(double base, unsigned int exponent){
      if(exponent == 0)
          return 1;
      if(exponent == 1)
          return base;
      double ret = PowerWithUnsignedEx2(base, exponent >> 1);
      ret *= ret;
      if(exponent & 0x1 == 1) //奇数
          ret *= base;
      return ret;
  }
  ```

&nbsp;

#### 11. 打印1到最大的n位数

- 思路，使用字符串来模拟大数，将进位与打印拆分

  ```c++
  void PrintN(char *num){
      int len = strlen(num);
      int index = 0;
      for(;index<len;index++){
          if(num[index] != '0')
              break;
      }
      for(;index<len;index++){
          printf("%c", num[index]);
      }
      printf("\n");
  }
  //打印最大的1到n
  bool IncrementN(char *num){
      //cout<<num<<endl;
      bool isOverflow = false;
      int carry = 0;
      int len = strlen(num);
      for(int i = len - 1; i >= 0; i--){
          int tmp = num[i] - '0' + carry;
          if(i == len - 1)
              tmp++;  //最后一位才加1
          if(tmp >= 10){
              if(i==0)  isOverflow = true;  //标记为爆战了
              else{
                  tmp -= 10;
                  carry = 1;
                  num[i] = tmp + '0';
              }
          }
          else{        //没有进位
              num[i] = '0' + tmp;
              break;
          }
      }
      return isOverflow;
  }
  void PrintMaxNDigits(int n){
      if(n<=0)
          return;
      char *num = new char[n+1];
      memset(num, '0', n);
      num[n] = '\0'; //注意点
      cout<<num<<endl;
      while(!IncrementN(num)){
          PrintN(num);
      }
      delete []num;
  }
  ```

- 思路2：采用全排列的思路，1-最大的n位数，就是打印全排列。递归执行

  ```c++
  void Print1ToMaxNDigitsRecursively(char *num, int len, int index){
      if(index == len - 1){
          PrintN(num);
          return;
      }
      for(int i = 0; i < 10; i++){
          num[index+1] = i + '0';
          Print1ToMaxNDigitsRecursively(num, len, index+1);
      }
  }
  
  void PrintMaxNDigits2(int n){
      if(n<=0)
          return;
      char *num = new char[n+1];
      memset(num,'0',n);
      num[n] = '\0';
      for(int i = 0; i < 10; i++){
          num[0] = i + '0';   //第一位
          Print1ToMaxNDigitsRecursively(num, n, 0);
      }
      delete []num;
  }
  ```

&nbsp;

#### 12. O(1) 时间删除链表结点

- 思路，只要当待删除的结点i不是头结点或尾结点时，可以找到i的下一个节点j，将j的内容复制到i，修改指针再删除j即可。 否则，还是需要从头结点开始遍历，注意若是删除头结点则需另外将头结点置为null.

  ```c++
  typedef struct LinkNode{
      int value;
      LinkNode * next;
  }LinkNode;
  //两个**表示指向指针的指针。*pListHead代表头结点
  void DeleteNode(LinkNode** plistHead, ListNode * pToBeDeleted){
      if(!pListHead || !pToBeDeleted)
          return;
      //非尾节点
      if(pToBeDeleted->next != NULL){
          ListNode* p = pToBeDeleted->next;
          pToBeDeleted->value = p->value;
          pToBeDeleted->next = p->next;
          delete p;    //delete是释放指针所指的内存，此时p为野指针
          p = NULL;
      }
      //头结点，且尾节点
      else if(*pListHead == pToBeDeleted){
          delete pToBeDeleted;
          pToBeDeleted = NULL;
          *pListHead = NULL;
      }
      else{//多个结点的尾节点
          ListNode *p = *pListHead;
          while(p->next != pToBeDeleted)
              p = p->next;
          p-next = NULL;
          delete pToBeDeleted;
          pToBeDeleted = NULL;
      }
  }
  ```

- 限制：需要保证链表中确实存在该结点。

&nbsp;

#### 13. 调整数组顺序使奇数在偶数前面

- 思路1：暴力O(n^2^)，遍历遇到是偶数，则将后面的数向前一位，然后将该数插入末尾。或者反过来。

- 思路2：类似插入排序或者冒泡排序，当是奇数是不停地向前交换

  ```c++
  void reOrderArray(vector<int> &array) {
      int len = array.size();
      for(int i = 1; i < len; i++){
          int temp = array[i];
          if((temp & 1) != 1)
              continue;
          for(int j = i; j>0; j--){
              if(array[j-1] % 2 == 0)
                  swap(array[j], array[j-1]);
              else break;
          }
      }
  }
  ```

- 思路3：暴力O(n)+O(N)，遍历，拷贝到另一个数组中。

- 思路4：双指针，前后指针法，前奇后偶，遇到不是的就交换两个数，直到两个指针相错。

  ```c++
  void reOrderArray(vector<int> &array) {
      int left=0;
      int right = array.size() - 1;
      if(right<1) return;
      while(left<right){  //小于等于无所谓
          while(left < right && (array[left] & 0x1) != 0)
              left++;
          while(left < right && (array[right] & 0x1) == 0)
              right--;
          if(left<right)
              swap(array[left], array[right]);
      }
  }
  ```

- 拓展：条件可以是负数在前，3的倍数在前…………解耦抽离

  ```c++
  bool isEven(int n){
      return (n & 1) == 0;
  }
  void Reorder(int *num, int len, bool (*func)(int)){
      if(num == NULL || len == 0)
      	return;
      int *left = num;
      int *right = num + len - 1;
      while(left<right){
          while(left<right && !func(*left))
          	left++;
          while(left<right) && func(*right)
          	right--;
          if(left<right){
              int temp = *left;
              *left = *right;
              *right = temp;
          }
      }
  }
  void ReorderWithEven(int num, int len){
      Reorder(num, len, isEven);
  }
  ```

&nbsp;

#### 14. 链表中倒数第K个结点

- 遍历一次找到倒数第K个结点；单链表，假设长度为n，结点为1-n，则倒数第K个是n-k+1.

- 通常可以两次遍历获取，但是使用双指针一次遍历即可。

- 思路：前指针先走K-1步，然后两个指针一起走，直到前指针到链表尾部

- 鲁棒性：

  - 链表为空，返回null
  - k不在链表范围内，NULL

  ```c++
  struct ListNode {
  	int val;
  	struct ListNode *next;
  	ListNode(int x) :val(x), next(NULL) {}
  }
  
  ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
      if(pListHead == NULL || k==0)
          return NULL;
      ListNode *pAhead = pListHead;
      ListNode *pBehind = pListHead;
      for(int i = 0; i < k-1; i++){		//防止溢出
          if(pAhead->next != NULL)
              pAhead = pAhead->next;
          else
              return NULL;                
      }
      while(pAhead->next != NULL){
          pAhead = pAhead->next;
          pBehind = pBehind->next;
      }
      return pBehind;
  }
  ```

&nbsp;

#### 15. 反转链表

- 输入一个链表的头结点，反转该链表，然后输出链表头结点

- 使用三个指针，分别指向当前结点，前驱结点和后继结点。处理时，将当前结点的指针指向前驱，然后下一个；直到链表结尾。

  ```c++
  ListNode* ReverseList(ListNode* pHead) {
      ListNode *pReversedHead = NULL;  //前部分已经反转好的头
      ListNode *pCur = pHead;
      ListNode *pPre = NULL;
      while(pCur != NULL){  //没有到链表尾
          ListNode *pNext = pCur->next;
          if(pNext==NULL)
              pReversedHead = pCur;   //已经到尾了
          pCur->next = pPre;   //割断，指向前
          pPre = pCur;         //遍历右移
          pCur = pNext;
      }
      return pReversedHead;
  }
  ```

  ```c++
  //递归
  ListNode* ReverseList(ListNode* pHead) {
      //如果链表为空或者链表中只有一个元素
      if(pHead==NULL||pHead->next==NULL) return pHead;
  
      //先反转后面的链表，走到链表的末端结点
      ListNode* pReverseNode=ReverseList(pHead->next);
  
      //再将当前节点设置为后面节点的后续节点，也就是说让我的后一个指向我
      pHead->next->next=pHead;
      pHead->next=NULL;
  
      return pReverseNode;
  
  }
  ```

&nbsp;

#### 16. 合并两个排序的链表

- 两个递增的链表，合并后仍然递增

- 两个指针，分别遍历，注意空指针的**鲁棒性**问题

  ```c++
  ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
      if(pHead1==NULL)
          return pHead2;
      else if(pHead2==NULL)
          return pHead1;
      ListNode *mergedHead = NULL;
      if(pHead1->val < pHead2->val){
          mergedHead = pHead1;
          mergedHead->next = Merge(pHead1->next, pHead2);
      }
      else{
          mergedHead = pHead2;
          mergedHead->next = Merge(pHead1, pHead2->next);
      }
      return mergedHead;
  }
  ```

  ```c++
  //非递归
  ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
          if(pHead1==NULL)
              return pHead2;
          else if(pHead2==NULL)
              return pHead1;
          ListNode *mergedHead = NULL;
          ListNode *current = NULL;
          /*if(pHead1->val < pHead2->val){
              mergedHead=pHead1;
              pHead1=pHead1->next;
          }            
          else{
              mergedHead=pHead2;
              pHead2=pHead2->next;
          }*/
          //current = mergedHead;
          while(pHead1!=NULL && pHead2!=NULL){
              if(pHead1->val < pHead2->val){
                  if(mergedHead==NULL)
                      mergedHead=current=pHead1;
                  else{
                      current->next = pHead1;
                      current = current->next;
                  }                
                  pHead1=pHead1->next;
              }
              else{
                  if(mergedHead==NULL)
                      mergedHead=current=pHead2;
                  else{
                      current->next = pHead2;
                      current=current->next;
                  }                
                  pHead2=pHead2->next;
              }
          }
          if(pHead1==NULL)
              current->next = pHead2;
          else
              current->next = pHead1;
          return mergedHead;
      }
  ```

  &nbsp;

#### 17. 树的子结构

- 输入两颗二叉树A、B，判断B是不是A的子树

- 思路：递归的遍历树，匹配一个结点，如果匹配，继续匹配左、右子树；否则，去找当前树的子树继续匹配，不行再继续匹配右子树。

- 代码中的flag，可以使用||短路进行省略

  ```c++
  bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){  //递归遍历二叉树1,从根节点开始遍历
          bool ret = false;
          if(pRoot1!=NULL && pRoot2!=NULL){
              if(pRoot1->val==pRoot2->val)
                  ret = DoesTree1HaveTree2(pRoot1,pRoot2); //以当前结点为起点，遍历是否包含子树
              if(!ret)
                  ret = HasSubtree(pRoot1->left, pRoot2);
              if(!ret)
                  ret = HasSubtree(pRoot1->right, pRoot2);
          }
          return ret;
      }
      bool DoesTree1HaveTree2(TreeNode* pRoot1, TreeNode* pRoot2){
          if(pRoot2==NULL)
              return true;
          if(pRoot1==NULL)
              return false;
          if(pRoot1->val != pRoot2->val)
              return false;
          return DoesTree1HaveTree2(pRoot1->left,pRoot2->left) && 	
              	DoesTree1HaveTree2(pRoot1->right,pRoot2->right);
      }
  ```

&nbsp;

### 解决面试题的思路

#### 18. 二叉树的镜像

- 树的镜像，就是交互树的所有非叶子结点的左右子结点。

- 思路：先序遍历树，某个结点有子结点，就交换其左右顺序。直到所有的非叶子结点全都遍历。

  ```c++
  void Mirror(TreeNode *pRoot) {
          if(pRoot==NULL || (pRoot->left == NULL && pRoot->right==NULL))
              return;
          TreeNode *pTemp = pRoot->left;  //交换左右子树
          pRoot->left = pRoot->right;
          pRoot->right = pTemp;
          if(pRoot->left)
              Mirror(pRoot->left);
          if(pRoot->right)
              Mirror(pRoot->right);
      }
  ```

  ```c++
  //非递归
  void Mirror(TreeNode *pRoot) {
          if(pRoot==NULL)
              return;
          stack<TreeNode*> stackNode;
          stackNode.push(pRoot);
          while(stackNode.size()){
              TreeNode* tree=stackNode.top();
              stackNode.pop();
              if(tree->left!=NULL || tree->right!=NULL){
                  TreeNode *ptemp=tree->left;
                  tree->left=tree->right;
                  tree->right=ptemp;
              }
              if(tree->left)
                  stackNode.push(tree->left);
              if(tree->right)
                  stackNode.push(tree->right);
          }
      }
  ```

  &nbsp;

#### 19. 顺时针打印矩阵

