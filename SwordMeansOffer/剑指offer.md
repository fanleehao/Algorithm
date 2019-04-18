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

#### ==17. 树的子结构==

- 输入两颗二叉树A、B，判断B是不是A的子树

- 思路：递归的遍历树，匹配一个结点，如果匹配，继续匹配左、右子树；否则，去找当前树的子树继续匹配，不行再继续匹配右子树。

- 代码中的flag，可以使用||短路进行省略

  ```c++
  bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){//递归遍历二叉树1,从根节点开始遍历
      bool ret = false;
      if(pRoot1!=NULL && pRoot2!=NULL){
          if(pRoot1->val==pRoot2->val)
              //以当前结点为起点，遍历是否包含子树
              ret = DoesTree1HaveTree2(pRoot1,pRoot2);
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

- 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：

  > 1  2  3  4
  >  5  6  7  8
  >  9  10 11 12
  >  13 14 15 16 

- 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

  ```
  vector<int> printMatrix(vector<vector<int> > matrix) {
      if (matrix.empty() || matrix[0].empty()) return {};
      int m = matrix.size(), n = matrix[0].size();
      vector<int> res;
      int up = 0, down = m - 1, left = 0, right = n - 1;
      while (true) {
          for (int j = left; j <= right; ++j) res.push_back(matrix[up][j]);
          if (++up > down) break;
          for (int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
          if (--right < left) break;
          for (int j = right; j >= left; --j) res.push_back(matrix[down][j]);
          if (--down < up) break;
          for (int i = down; i >= up; --i) res.push_back(matrix[i][left]);
          if (++left > right) break;
      }
      return res;
  }
  ```

&nbsp;

#### 20. 包含min函数的栈

- 设计栈的结构，使得栈的pop/push/min操作，都是O(1)的复杂度需求

- 使用辅助的栈，来保存每次入栈操作的最小元素。这样，在出栈时就能保证次小元素依然能够获取。每次获取辅助栈顶元素，即为最小值。

  ```c++
  void push(int value) {
          m_data.push(value);
          if(m_min.size() == 0 || value < m_min.top())
              m_min.push(value);
          else
              m_min.push(m_min.top());
      }
      void pop() {
          m_data.pop();    //这里可以需要判断栈是否为空
          m_min.pop();
      }
      int top() {
          return m_data.top();   //同上
      }
      int min() {
          return m_min.top();   //同上
      }
   private:
      stack<int> m_data;
      stack<int> m_min;
  ```

  &nbsp;

#### 21. 栈的压入与弹出

- 给定压栈序列，判断出栈序列是否合法

- 规律：如果下一个弹出序列的数字是栈顶数字，则直接弹出；否则，将入栈中直至待弹出的所有数字都压入栈，如果都压入了还没找到下一个弹出的数字，则不合法。

  ```c++
  bool IsPopOrder(vector<int> pushV,vector<int> popV) {
          bool ret = false;
          vector<int> stack;
          for(int i =0, j = 0; i < pushV.size();){
              stack.push_back(pushV[i++]);
              while(j < popV.size() && popV[j] == stack.back()){
                  stack.pop_back();
                  j++;
              }
          }
          return stack.empty();
      }
  ```

&nbsp;

#### 22. 从上往下打印二叉树

- 层序遍历

- 其实也是广度优先，BFS

  ```c++
  vector<int> PrintFromTopToBottom(TreeNode* root) {
          vector<int> ret;
          if(root == NULL)
              return {};
          deque<TreeNode *> dequeTreeNode;
          dequeTreeNode.push_back(root);
          while(dequeTreeNode.size()){
              TreeNode *pNode = dequeTreeNode.front();
              dequeTreeNode.pop_front();
              ret.push_back(pNode->val);
              if(pNode->left)
                  dequeTreeNode.push_back(pNode->left);
              if(pNode->right)
                  dequeTreeNode.push_back(pNode->right);
          }
          return ret;
      }
  ```

&nbsp;

#### 23. 二叉搜索树的后续遍历

- 判断一个数组是不是某二叉搜索树的后序遍历结果

  ```c++
  bool VerifySquenceOfBST(int sequence[], int length) {
      if(sequence = NULL || length <= 0) 
          return false;
      int root = sequence[len-1];
      int i = 0;
      for(;i < len-1; ++i){
          if(sequence[i]>root) 
              break; // 找到第一个大于根结点的位置，则左边为左子树，右边为右子树
      }
      int j = i;
      for(;j < len-1; ++j){ // 循环时去除root，因此为len-1
          if(sequence[j]<root) 
              return false; // 有一个小于root，则返回false
      }    
      bool left = true,right = true; // 看左右子树是否是二叉搜索树
      if(i > 0) 
          left = VerifySquenceOfBST(sequence, i);
      if(i < length - 1) 
          right = VerifySquenceOfBST(sequence + i, length - i - 1);
      return (left && right);
  }
  -------------------------------------------------------------------------------
  public:
      bool VerifySquenceOfBST(vector<int> a) {
          if(!a.size()) 
              return false;
          return judge(a, 0, a.size() - 1);
      }
  	bool judge(vector<int>& a, int l, int r){
          if(l >= r) return true;
          int i = r;
          while(i > l && a[i - 1] > a[r]) 
              --i;
          for(int j = i - 1; j >= l; --j) 
              if(a[j] > a[r]) 
                  return false;
          return judge(a, l, i - 1) && (judge(a, i, r - 1));
      }
  ------------------------------------------------------------------------------
  //非递归
  bool VerifySquenceOfBST(vector<int> sequence) {
          int size = sequence.size();
          if(0==size)return false;
   
          int i = 0;
          while(--size)
          {
              while(sequence[i++]<sequence[size]);
              while(sequence[i++]>sequence[size]); 
              if(i<size)
                  return false;
              i=0;
          }
          return true;
      }
  ```

&nbsp;

#### 24. 二叉树中和为某一值的路径

- 输入一颗二叉树和一个整数，打印出二叉树中结点值的和为目标数的所有路径。（根结点到叶结点）

- 回溯+递归

  ```c++
  vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
          if(root == NULL)
              return {};
          vector<vector<int>> res;
          vector<int> path;
          int curSum = 0;
          FindPath(root, res, path, curSum, expectNumber);
          return res;
      }
      void FindPath(TreeNode *root, vector<vector<int>> &res, vector<int> &path,int curSum,int expectNumber){
          curSum += root->val;
          path.push_back(root->val);
          //叶子结点
          bool isLeaf = root->left == NULL && root->right == NULL;
          if(curSum == expectNumber && isLeaf){
              res.push_back(path);
          }
          if(root->left != NULL)
              FindPath(root->left, res, path, curSum, expectNumber);
          if(root->right != NULL)
              FindPath(root->right, res, path, curSum, expectNumber);
          //回溯
          curSum -= root->val;
          path.pop_back();
      }
  ```

&nbsp;

#### 25. 复杂链表的复制

- 链表中的结点，除了有一个指向下一个结点的指针，还有一个指向任意结点或者为NULL的指针。

  > struct ComplexListNode{
  > ​	int value;
  > ​	ComplexListNode * pNext;
  > ​	ComplexListNode * pSibling;
  >
  > };

- 思路1：复制所有的结点，及其next指针，连成链；再去找每一个的sibling链对象；O(n^2^)

- 思路2：使用哈希表，存储<N,N’>的对应关系；空间换时间

- 思路3：将复制的结点插入在当前结点的next位置，再修改sibiling的指针；最后拆分两个链表——奇偶分离；

  ```c++
  RandomListNode* Clone(RandomListNode* pHead){
      //复制
      CloneNodes(pHead);
      ConnectRandomNodes(pHead);  //连接
      return ReconnectNodes(pHead);  //分离
  }
  void CloneNodes(RandomListNode* pHead){
      RandomListNode* pNode = pHead;
      while(pNode != NULL){
          RandomListNode* pCloned = new RandomListNode(pNode->label);
          pCloned->label = pNode->label;
          pCloned->next = pNode->next;
          pCloned->random = NULL;
  
          pNode->next = pCloned;
          pNode = pNode->next;
      }
  }
  void ConnectRandomNodes(RandomListNode * pHead){
      RandomListNode* pNode = pHead;
      while(pNode != NULL){
          RandomListNode * pCloned = pNode->next;
          if(pNode->random != NULL)
              pCloned->random = pNode->random->next;
          pNode = pCloned->next;
      }
  }
  RandomListNode * ReconnectNodes(RandomListNode *pHead){
      RandomListNode * pNode = pHead;
      RandomListNode * pClonedHead = NULL;
      RandomListNode * pClonedNode = NULL;
      if(pNode != NULL){
          pClonedHead = pClonedNode = pNode->next;
          pNode->next = pClonedNode->next;
          pNode = pNode->next;
      }
      while(pNode != NULL){
          pClonedNode->next = pNode->next;
          pClonedNode = pClonedNode->next;
          pNode->next = pClonedNode->next;
          pNode = pNode->next;
      }
      return pClonedHead;
  }
  ```

  ```c++
  RandomListNode* Clone(RandomListNode* pHead){
      if(!pHead) return NULL;
      RandomListNode *currNode = pHead;
      while(currNode){
          RandomListNode *node = new RandomListNode(currNode->label);
          node->next = currNode->next;
          currNode->next = node;
          currNode = node->next;
      }
      currNode = pHead;
      while(currNode){
          RandomListNode *node = currNode->next;
          if(currNode->random){               
              node->random = currNode->random->next;
          }
          currNode = node->next;
      }
      //拆分
      RandomListNode *pCloneHead = pHead->next;
      RandomListNode *tmp;
      currNode = pHead;
      while(currNode->next){
          tmp = currNode->next;
          currNode->next =tmp->next;
          currNode = tmp;
      }
      return pCloneHead;
  }
  ```

&nbsp;

#### ==26. 二叉搜索树与双向链表==

- 输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。不能创建新的结点，只能调整原结点的指针。

- 思路：原结点的左指针指向前驱，右指针指向后继

  ```c++
  //递归
  TreeNode* Convert(TreeNode* pRootOfTree){
      if(pRootOfTree == NULL)
          return NULL;
      TreeNode* list1 = Convert(pRootOfTree->left);    // 将左子树变为排序链表
      TreeNode* list2 = Convert(pRootOfTree->right);   // 将右子树变为排序链表
      TreeNode* tmp = list1;
      if(tmp != NULL){
          while(tmp->right)
              tmp = tmp->right;    //找到最右边的链表结点
          tmp->right = pRootOfTree;
      }
      pRootOfTree->left  = tmp;
      pRootOfTree->right = list2;
      if(list2 != NULL)
          list2->left = pRootOfTree;
      return list1 == NULL ? pRootOfTree : list1;
  }
  //非递归
  public TreeNode ConvertBSTToBiList(TreeNode root) {
      if(root==null)
          return null;
      Stack<TreeNode> stack = new Stack<TreeNode>();
      TreeNode p = root;
      TreeNode pre = null;// 用于保存中序遍历序列的上一节点
      boolean isFirst = true;
      while(p!=null||!stack.isEmpty()){
          while(p!=null){
              stack.push(p);
              p = p.left;
          }
          p = stack.pop();
          if(isFirst){
              root = p;// 将中序遍历序列中的第一个节点记为root
              pre = root;
              isFirst = false;
          }else{
              pre.right = p;
              p.left = pre;
              pre = p;
          }      
          p = p.right;
      }
      return root;
  }
  ————————————————————————————————————————————————————————————————
  //另一种解题思路
  vector<TreeNode*> nodes;
  void tranverse(TreeNode* pRoot) {
      if (nullptr == pRoot)
          return;
      tranverse(pRoot->left);
      nodes.push_back(pRoot);
      tranverse(pRoot->right);
  }
  TreeNode* adjustTree() {
      for (int i = 0; i < nodes.size() - 1; ++i)
          nodes[i]->right = nodes[i+1];
      nodes[nodes.size()-1]->right = nullptr;
      for (int i = nodes.size() - 1; i > 0; --i)
          nodes[i]->left = nodes[i-1];
      nodes[0]->left = nullptr;
      return nodes[0];
  }
  TreeNode* Convert(TreeNode* pRoot)
  {
      if (nullptr == pRoot)
          return nullptr;
      tranverse(pRoot);
      return adjustTree();
  }
  ```

&nbsp;

#### 27. 字符串的排列

- 输入一个字符串，打印该字符串中字符的所有排列

- 递归：求一个字符，和后面所有的字符排列；再将这个字符和后面的字符逐个交换

  ```c++
  vector<string> Permutation(string str) {
      set<string> ret;
      Permutation(str, ret, 0);
      return vector<string>(ret.begin(), ret.end());
  }
  void Permutation(string &str, set<string> &ret, int index){
      if(index==str.length()-1)
          ret.insert(str);
      else{
          for(int i = index; i < str.length(); i++){
              swap(str[i], str[index]);
              Permutation(str, ret, index+1);
              swap(str[i], str[index]);
          }
      }
  }
  ```

&nbsp;

### 优化时间和空间效率

#### 28. 数组中出现次数超过一半的数字

- 数组中有一个数字出现的次数超过数组长度的一半，找出。

- 思考1：排序数组中出现次数超过一半的数字，一定是中位数；也就是第n/2大的数。

  ```c++
  int MoreThanHalfNum_Solution(vector<int> numbers){
      // 因为用到了sort，时间复杂度O(NlogN)，并非最优
      if(numbers.empty()) return 0;
  
      sort(numbers.begin(),numbers.end()); // 排序，取数组中间那个数
      int middle = numbers[numbers.size()/2];
  
      int count=0; // 出现次数
      for(int i=0;i<numbers.size();++i){
          if(numbers[i]==middle) ++count;
      }
      return (count>numbers.size()/2) ? middle :  0;
  }
  -------------------------------------------------------------------------------
  //拆分快速排序
  int MoreThanHalfNum_Solution(vector<int> numbers) {
      int low = 0, high = numbers.size() - 1;
      int k = Partition(numbers, low, high);
      int mid = numbers.size() / 2;
      while(k != mid){
          if(k > mid){
              high = k - 1;
              k = Partition(numbers, low, high);
          }
          else {
              low = k + 1;
              k = Partition(numbers, low, high);
          }
      }
      int cnt = 0;
      for(int x: numbers){
          if(x==numbers[mid])
              cnt++;
      }
      return cnt * 2 > numbers.size() ? numbers[mid]:0;
  }
  int Partition(vector<int> numbers, int low, int high){
      int key = numbers[low];
      while(low<high){
          while(low < high && numbers[high] >= key)
              high--;
          swap(numbers[high], numbers[low]);
          while(low < high && numbers[low] <= key)
              low++;
          swap(numbers[high], numbers[low]);
      }
      return low;
  }
  ```

- 思路2：计数。每次遇到保存的数字，就次数加1；否则次数减1。次数为0后，则保存下一个数字，并设定次数为1.

  原因是：目标数字出现的次数比所有数字出现的次数和还要多。

  ```c++
  int MoreThanHalfNum_Solution(vector<int> numbers) {
      int ret = numbers[0];
      int times = 1, cnt = 0;
      for(auto x: numbers){
          if(times == 0){
              ret = x;
              times = 1;
          }
          else if(x == ret)
              times++;
          else times--;
      }
      for(auto x: numbers){
          if(x == ret)
              cnt++;
      }
      return cnt * 2 > numbers.size() ? ret : 0;
  }
  ---------------------------------------------------------------
  //哈希法
  int MoreThanHalfNum_Solution(vector<int> numbers) {
      int n = numbers.size();
      //map 记录出现次数
      map<int, int> m;
      int count;
      for (int i = 0; i < n; i++) {
          count = ++m[numbers[i]];
          if (count > n/2) return numbers[i];
      }
      return 0;
  }
  ```

&nbsp;

#### 29. 最小的K个数

- 输入n个数，找出其中最小的k个数

- 思路1：快排

- 思路2：Parttition思路。每次根据k进行Partition操作，使得比第K个数字小的位于左边，大的位于右边，调整后左边的k个值就是结果（但不一定有序，且这种方法需要交换数组元素）；

  ```c++
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
          int low = 0, high = input.size()-1;
          int index = Partition(input, low, high);
          if(high<=0||k<=0||k>high+1) return vector<int>();
          if(k==high+1)
              return input;
          while(index != (k-1)){
              if(index > (k-1)){
                  high = index - 1;
                  index = Partition(input, low, high);
              }
              else {
                  low = index + 1;
                  index = Partition(input, low, high);
              }
          }
          vector<int> ret;
          for(int i = 0; i < k; i++)
              ret.push_back(input[i]);
          return ret;
      }
      int Partition(vector<int> &numbers, int low, int high){
          int key = numbers[low];
          while(low<high){
              while(low < high && numbers[high] >= key)
                  high--;
              swap(numbers[high], numbers[low]);
              while(low < high && numbers[low] <= key)
                  low++;
              swap(numbers[high], numbers[low]);
          }
          return low;
      }
  ```

- 思路2：使用大小为K的数据容器进行存储。大顶堆或者红黑树。更新容器中的最大值。当容器满了之后，使用2步操作：

  > 1. 找出k个数中最大的值
  > 2. 比较下一个数，可能删除最大的值，替换成一个较小的数

  总的时间复杂度为O(nlogK)，可以使用STL的容器，如SET进行辅助。这种解法能够适用于海量数据的分析，也就是N很大、k很小的情况。

  ```c++
  vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
      int low = 0, high = input.size()-1;
      if(high<=0||k<=0||k>high+1) return vector<int>();
      if(k==high) return input;
      multiset<int, greater<int>> ret;
      multiset<int, greater<int> >::iterator ite; // 定义迭代器
      for(auto x: input){
          if(ret.size() < k)
              ret.insert(x);
          else{
              ite = ret.begin();
              if(*ret.begin() > x){
                  ret.erase(ite);
                  ret.insert(x);
              }
          }
      }
      return vector<int>(ret.begin(), ret.end());
  }
  ```

&nbsp;

#### 30. 连续子数组的最大和（连续）

- 输入一个整型数据，有正数和负数。求最大的连续子数组的和。要求时间复杂度O(n)；

- 思路1：暴力，n*(n+1)/2个**连续**子数组。可以使用DFS，或者格雷码反射码求子集。

- 思路2：规律分析法。尝试找到如下规律：当前最大和，如果当前最大和为负、且下一个数为正，则放弃当前值。如果当前最大和为正、且下一个数为负，继续更新。

  ```c++
  private: bool g_InvalidInput = false;//标识非法输入
  int FindGreatestSumOfSubArray(vector<int> array) {
      int len = array.size();
      if(len <= 0){
          g_InvalidInput = true;
          return 0;
      }
      g_InvalidInput = false;
      int curSum = 0, maxSum = INT_MIN;
      for(int i = 0; i < len; i++){
          if(curSum <= 0)
              curSum = array[i];
          else curSum += array[i];
          if(curSum > maxSum)
              maxSum = curSum;
      }
      return maxSum;
  }
  ```

- 思路3：动态规划。h[i]表示以第i个数字结尾的最大子数组和。分析类同上：第一个数就是自己。对于第i个数结尾的子数组，如果第i-1个数的最大和非正，则舍弃。否则，加上当前的数。

  ```c++
  int FindGreatestSumOfSubArray(vector<int> array) {
      int len = array.size();
      if(len <= 0)
          return 0;
      int *h = new int[len], ret = INT_MIN;
      h[0] = array[0];
      for(int i = 1; i < len; i++){
          if(h[i-1] <= 0)
              h[i] = array[i];
          else h[i] = h[i-1] + array[i];
          ret = max(ret, h[i]);
      }
      return ret;
  }
  ```

&nbsp;

#### 31. 1-n中1出现的次数

- 1-n的自然数，1出现的次数？如1-13，有1、10/11/12/13，共6次1。

- 思路1：暴力，遍历+取模。O(nlogn)

  ```c++
  int NumberOf1Between1AndN_Solution(int n){
      int ret = 0;
      for(int i = 1; i <= n; i++){
          ret += NumberOf1(i);
      }
      return ret;
  }
  int NumberOf1(int num){
      int cnt = 0;
      while(num){
          if(num % 10 == 1)
              cnt++;
          num /= 10;
      }
      return cnt;
  }
  ```

- 思路2：数字规律分析+递归



&nbsp;

#### 32. 把数组排成最小的数

- 给定一个正整数数组，将所有数拼接成一个数，输出最小的那个。如{3,32,321}，输出321323

- 思路1：暴力，求全排列+比较

- 思路2：利用隐含大数思路，将数组组合成字符串，进行自定义排序规则的比较。

  ```c++
  string PrintMinNumber(vector<int> numbers) {
      int len = numbers.size();
      if(len <= 0) return "";
      sort(numbers.begin(), numbers.end(), cmp);
      string ret = "";
      for(int i = 0; i < len; i++){
          ret += to_string(numbers[i]);
      }
      return ret;
  }
  static bool cmp(int a, int b){
      string A="";
      string B="";   //如果ab < ba,则a排在b之前
      A += to_string(a);
      A += to_string(b);
      B += to_string(b);
      B += to_string(a);
      return A < B;
  }
  ```

&nbsp;

#### 33. 丑数

- 只包含因子2/3/5的数称作丑数。求按从小到大排列的第1500个丑数。习惯上把1当成第一个丑数

- 思路1：暴力。按序判断每一个数是否是丑数。

  ```c++
  int GetUglyNumber_Solution(int index) {
      int cnt = 0, num = 0;
      if(index <= 0)
          return 0;
      while(cnt < index){
          ++num;
          if(IsUgly(num))
              ++cnt;
      }
      return num;
  }
  bool IsUgly(int num){
      while(num % 2 == 0)
          num /= 2;
      while(num % 3 == 0)
          num /= 3;
      while(num % 5 == 0)
          num /= 5;
      return (num == 1) ? true : false;
  }
  ```

- 思路2：只考虑丑数的来源，维护一个数组，每次新增都是其中的数乘以2/3/5的值。关键在于维护该数组中丑数的有序性。

- 找到乘以2/3/5的数，中第一个大于当前最大丑数的值，再取其中最小的一个。

  ```c++
  int GetUglyNumber_Solution(int index) {
      if (index < 7)return index;
      vector<int> res(index);
      res[0] = 1;
      int t2 = 0, t3 = 0, t5 = 0;
      for (int i = 1; i < index; ++i){
          res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
          if (res[i] == res[t2] * 2)t2++;
          if (res[i] == res[t3] * 3)t3++;
          if (res[i] == res[t5] * 5)t5++;
      }
      return res[index - 1];
  }
  ```

&nbsp;

#### 34. 第一次只出现一次的字符

- 在字符串中找出第一个只出现一次的字符。

- 思路：哈希法。

  ```c++
  int FirstNotRepeatingChar(string str) {
      int len = str.length();
      if(len <= 0) return -1;
      map<char, int> mm;
      for(char c: str)
          mm[c]++;
      for(int i = 0; i < len; i++){
          if(mm[str[i]] == 1)
              return i;
      }
      return -1;
  }
  ```

&nbsp;

#### 35. 数组中的逆序对

- 给定数组，求逆序对的个数

- 思路1：暴力，O(n^2^)

- 思路2：分治（二分）法+归并统计。分治到单个，归并比较相邻两个数，统计。逐层向上。

- 先用两个指针指向两个子数组的末尾，比较指向数字。第一个子数组数字大于第二个子数组数字，则有逆序对且个数是第二个数组中剩余个数。否则不构成逆序对。每一次比较，将较大数字从后往前复制到新的辅助序列中，确保其实递增排列的。然后将对应指针前移，继续下一轮比较。

  ```c++
  int InversePairs(vector<int> data) {
      if(data.size() <= 1) return 0;//如果少于等于1个元素，直接返回0
      int* copy = new int[data.size()];
      //初始化该数组，该数组作为存放临时排序的结果，最后要将排序的结果复制到原数组中
      for(unsigned int i=0; i<data.size(); i++)
          copy[i] = 0;
      //调用递归函数求解结果
      int count=InversePairCore(data, copy, 0, data.size()-1);
      delete[] copy;//删除临时数组
      return count;
  }
   //程序的主体函数
  int InversePairCore(vector<int>& data,int*& copy,int start,int end)
  {
      if(start == end) {
          copy[start] = data[start];
          return 0;
      }
      //将数组拆分成两部分
      int length = (end - start) / 2;//这里使用的下标法，下面要用来计算逆序个数；也可以直接使用mid=（start+end）/2
      //分别计算左边部分和右边部分
      int left = InversePairCore(data, copy, start, start+length) % 1000000007;
      int right = InversePairCore(data, copy, start+length+1, end) % 1000000007;
      //进行逆序计算
      int i = start + length;//前一个数组的最后一个下标
      int j = end;//后一个数组的下标
      int index = end;//辅助数组下标，从最后一个算起
      int count = 0;
      while(i >= start && j >= start + length + 1) {
          if(data[i] > data[j]) {
              copy[index--] = data[i--];
              //统计长度
              count += j - start - length;
              if(count >= 1000000007)//数值过大求余
                  count %= 1000000007;
          }
          else copy[index--] = data[j--];
      }
      for(; i >= start; --i) 
          copy[index--] = data[i];
      for(; j >= start + length + 1; --j) 
          copy[index--] = data[j];
      //排序
      for(int i = start; i <= end; i++)
          data[i] = copy[i];
      //返回最终的结果
      return (count + left + right) % 1000000007;
  }
  ```

&nbsp;

#### 36. 两个链表的第一个公共结点

- 输入两个链表，找出其第一个公共结点。

- 思路1：暴力，O(m*n)

- 思路2：从后往前遍历，使用栈辅助；找到最后一个不相等的结点；O(m+n)，辅助O(m+n)

- 思路3：计算两个链表的长度，每次在较长的链表先走几步（两个链表长度之差）；找到第一个相同的结点；

  ```c++
  ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
      int len1 = GetListLen(pHead1);
      int len2 = GetListLen(pHead2);
  
      int dif = len1 - len2;
      ListNode* shortList = pHead2;
      ListNode* longList = pHead1;
      if(dif < 0){
          shortList = pHead1;
          longList = pHead2;
          dif = len2- len1;
      }
      //先在长链表走dif步长
      for(int i = 0; i < dif; i++)
          longList = longList->next;
      while(longList != NULL && shortList != NULL && longList != shortList){
          longList = longList->next;
          shortList = shortList->next;
      }
      return longList;        
  }
  int GetListLen(ListNode* pHead){
      int len = 0;
      ListNode* node = pHead;
      while(node != NULL){
          len++;
          node = node->next;
      }
      return len;
  }
  ```

&nbsp;

### 面试中的各项能力

#### 37. 数字在排序数组中出现的次数

- 统计一个数字在排序数组中出现的次数。

- 思路1：暴力

- 思路2：二分的变形；分别使用二分找到某个数字闭区间的上界和下界，都存在则是其差+1；O(logn)

  ```c++
  int GetNumberOfK(vector<int> data ,int k) {
      int num = 0;
      if(!data.empty()){
          int st = Get1stK(data, k, 0, data.size()-1);
          int ed = GetEndK(data, k, 0, data.size()-1);
          if(st > -1 && ed > -1)
              num = ed - st + 1;
      }
      return num;
  }
  int Get1stK(vector<int> data, int k, int left, int right){        
      while(left <= right){
          int mid = (left + right) / 2;
          if(data[mid] >= k)
              right = mid - 1;
          else 
              left = mid + 1;
          if(left < data.size() && data[left]==k)
              return left;
      }
      return -1;
  }
  int GetEndK(vector<int> data, int k, int left, int right){
      while(left <= right){
          int mid = (left + right) / 2;
          if(data[mid] <= k)
              left = mid + 1;
          else right = mid - 1;
          if(right >= 0 && data[right] == k)
              return right;
      }
      return -1;
  }
  ```

&nbsp;

#### 38. 二叉树的深度

- 从根结点到叶子结点形成树的一条路径，深度为最长路径长度。

- 思路：树的深度等于左右子树较大值+1；递归

  ```c++
  int TreeDepth(TreeNode* pRoot){
      if(pRoot == NULL)
          return 0;
      int left = TreeDepth(pRoot->left);
      int right = TreeDepth(pRoot->right);
      return (right > left) ? right+1:left+1;
  }
  ```

- 给定一颗二叉查找树的根结点，判断其是不是平衡二叉树——也即左右子树高度差不大于1.

- 思路1：如上，增加判断即可

  ```c++
  bool IsBalanced_Solution(TreeNode* pRoot) {
      if(pRoot == NULL)
          return true;
      int left = TreeDepth(pRoot->left);
      int right = TreeDepth(pRoot->right);
      int diff = left - right;
      if(diff < -1 || diff > 1)
          return false;
      return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
  }
  ```

- 思路2：使用后续遍历思路，每次只需比较一次结点即可；遍历时保存每个子树的深度；

  ```c++
  bool IsBalanced_Solution(TreeNode* pRoot) {
      int depth = 0;
      return IsBalanced(pRoot, &depth);
  }
  bool IsBalanced(TreeNode* pRoot, int* depth){
      if(pRoot == NULL){
          *depth = 0;
          return true;
      }
      int left, right;
      if(IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)){
          int diff = left - right;
          if(diff <=1 && diff >= -1){
              *depth = (left > right ? left:right) + 1;
              return true;
          }
      }
      return false;
  }
  ```

&nbsp;

#### 39. 数组中只出现一次的数字

- 一个整型数组除两个数字外，其他数字都出现了两次；要求O(n)+O(1)找出这两个数字。

- 思路：**异或操作**。每个数字异或本身都等于0；将所有数分为两组，每组只包含一个出现一次的数字。拆分过程：使用所有数异或结果，找到第一位为1的下标n，以数字得二进制中第n位是不是1分成两组；

  ```c++
  void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
      if(data.size()<2)
          return;
      int resOR = 0;
      for(int i = 0; i < data.size(); i++)
          resOR ^= data[i];
      int index = Find1stBit1(resOR);
      *num1 = *num2 = 0;
      for(int j = 0; j < data.size(); j++){
          if(IsBit1(data[j], index))
              *num1 ^= data[j];
          else *num2 ^= data[j];
      }
  }
  int Find1stBit1(int num){
      int index = 0;
      while(((num & 1) == 0) && (index < 8*sizeof(int))){
          num = num >> 1;
          ++index;
      }
      return index;
  }
  bool IsBit1(int num, int index){
      num = num >> index;
      return (num & 1);
  }
  ```

&nbsp;

#### 40. 和为s的两个数字VS和为s的连续正数序列

- 输入一个递增数组和一个数字s，在数组中查找两个数，使得其和正好是s；多对则输出任意一对

- 思路1：暴力，O(n^2^);

- 思路2：双指针。前后指向，每次判断指针指向值之和，根据与目标值大小进行前后移动；

  ```c++
  vector<int> FindNumbersWithSum(vector<int> array,int sum) {
      int left = 0, right = array.size() - 1;
      if(left >= right) return {};
      vector<int> res(2,0);
      int mul = INT_MAX;
      while(left < right){
          int temp = array[left] + array[right];
          if(temp == sum && array[left] * array[right] < mul){
              res[0] = array[left]; res[1] = array[right];
              mul = res[0] * res[1];
          }
          else if(temp > sum)
              right--;
          else left++;
      }
      if(res[0] != 0 && res[1] != 0)
          return res;
      else return {};
  }
  ```

- 输入一个正整数s，打印出所有和为s的连续正数序列（至少含有两个）。

- 思路：同上，双指针；

  ```c++
  vector<vector<int> > FindContinuousSequence(int sum) {
      int left = 1, right = 2;
      int mid = (1+sum) / 2;
      int temp = left + right;
      vector<vector<int> > ret;
      while(left < mid){
          if(temp == sum){                            
              vector<int> t;
              for(int i = left; i <= right; i++)
                  t.push_back(i);
              ret.push_back(t);
          }
          while(temp > sum && left < mid){
              temp -= left;
              left++;
              if(temp == sum){
                  vector<int> t;
                  for(int i = left; i <= right; i++)
                      t.push_back(i);
                  ret.push_back(t);
              }
          }
          right++;
          temp += right;
      }
      return ret;
  }
  ```

&nbsp;

#### 41. 翻转单词顺序 VS 左旋转字符串

- 一：输入一个英文句子，翻转句子中单词的顺序，但单词内字符顺序不变

- 思路1：先将整个字符串翻转，然后逐个翻转每个单词；

  ```c++
  void ReverseWord(string &str, int s, int e){
      while(s < e)
          swap(str[s++], str[e--]);
   } 
  string ReverseSentence(string str) {
      ReverseWord(str, 0, str.size() - 1); //先整体翻转
      int s = 0, e = 0;
      int i = 0;
      while(i < str.size()){
          while(i < str.size() && str[i] == ' ') //空格跳过
              i++;
          e = s = i; //记录单词的第一个字符的位置
          while(i < str.size() && str[i] != ' '){ //不是空格 找单词最后一个字符的位置
              i++;
              e++;
          }
          ReverseWord(str, s, e - 1); //局部翻转
      }
      return str;
  }
  ```

- 思路2：栈；或者直接反向拼接，然后输出即可

  ```c++
  string ReverseSentence(string str) {
      string res = "", tmp = "";
      for(unsigned int i = 0; i < str.size(); ++i){
          if(str[i] == ' ') res = " " + tmp + res, tmp = "";
          else tmp += str[i];
      }
      if(tmp.size()) res = tmp + res;
      return res;
  }
  ```



- 题2：字符串的左旋操作是把字符串前面的若干个字符转移到字符串的末尾。

- 思路：类上，先翻转前n位，再翻转后N-n位，最后旋转整个字符串

  ```c++
  string LeftRotateString(string str, int n) {
      if(str.empty() || n > str.length())
          return str;
      reverse(str, 0, n-1);
      reverse(str, n, str.length()-1);
      reverse(str, 0, str.length()-1);
      return str;
  }
  void reverse(string &str, int left, int right){
      while(left<right){
          swap(str[left++], str[right--]);
      }
  }
  ```

&nbsp;

#### 42. n个骰子的点数

- 把n个骰子投掷，所有骰子朝上一面点数和为s；输入n，输出s的所有可能值出现的概率

- 每个骰子6面，出现点数的概率总数为6^n^；求出每个点数的频次/6^n^，即为概率；

- 思路1：基于递归求解；1个骰子可能有6中情况，分别约剩下的n-1个组合；

  ```c++
  int G = 6;  //一个常数
  void Probability(int n, int * p){
      for(int i = 1; i <= G; i++)
          Probability2(n, n, i, p);
  }
  void Probability2(int origianl, int current, int sum, int *p){
      if(current == 1) p[sum - original]++;
      else{
          for(int i = 1; i <= G; i++)
              Probability2(original, current - 1, sum + i, p);
      }
  }
  void PrintProbability(int n){
      if(n < 1) return;
      int maxSum = n * G;   //出现的最大的数为n*G
      int *p = new int[maxSum - n + 1];   //定义n-n*G的数组范围表示
      for(int i = n; i <= maxSum; i++){
          p[i] = 0;  //概率都是0；
      }
      Probability(n, p);
  }
  ```

- 思路2：基于循环求骰子点数；



&nbsp;

#### 43. 扑克牌的顺子

- 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的；大小王可为任意数字；

- 思路：看做一个5位数字组成的数组，观察是否有序？若无，0代表的大小王是否可以填充？

  1. 数组排序
  2. 统计0的个数、排序后相邻数字间空格总数
  3. 若空缺总数小于或等于0的个数，则有序——顺子
  4. 不能包含有对子——数字重复出现

  ```c++
  bool IsContinuous( vector<int> numbers ) {
      if(numbers.empty()) return false;
      int len = numbers.size();
      sort(numbers.begin(), numbers.end());
      int nOf0 = 0, nOfGap = 0;
      for(int i = 0 ; i < len && numbers[i] == 0; i++)
          nOf0++;
      int small = nOf0;
      int big = small + 1;
      while(big < len){
          if(numbers[small] == numbers[big])
              return false; //对子出现
          nOfGap += numbers[big] - numbers[small] - 1;
          small = big;
          big++;
      }
      return (nOfGap > nOf0) ? false:true;
  }
  ```

&nbsp;

#### 44. 圆圈中最后剩下的数字

- 0,1，…，n-1；n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字。求出这个圆圈中剩下的最后一个数字

- 思路1：环形链表模拟圆圈；注意，每当链表遍历到尾时，则转回到链表头；O(mn)，空间O(n)

  ```c++
  int LastRemaining_Solution(int n, int m){
      if(n < 1 || m < 1)
          return -1;
      list<int> numbers;
      for(int i = 0; i < n; i++)
          numbers.push_back(i);
      list<int>::iterator ite = numbers.begin();
      while(numbers.size() > 1){
          for(int i = 1; i < m; i++){
              ite++;
              if(ite == numbers.end())
                  ite = numbers.begin();
          }
          list<int>::iterator next = ++ite;
          if(next == numbers.end())
              next = numbers.begin();
          --ite;
          numbers.erase(ite);
          ite = next;
      }
      return *ite;
  }
  ```

- 思路2：约瑟夫环；找出递归公式；

  ​	$f(n,m)=0 ,n=1;$
  ​	$f(n,m)=[f(n-1,m) + m] \%n,  n>1$

  ```c++
  int LastRemaining_Solution(int n, int m){
      if(n < 1||m<1) return -1;
      int ret = 0;
      for(int i = 2; i <= n; i++)
          ret = (ret + m) % i;
      return ret;
  }
  ```

&nbsp;








