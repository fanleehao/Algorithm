## .Leetcode Top.100

> Some already done before





### 1. 两数相加 #2

- https://leetcode-cn.com/problems/add-two-numbers/

- code

  ```c++
  /**
   * Definition for singly-linked list.
   * struct ListNode {
   *     int val;
   *     ListNode *next;
   *     ListNode(int x) : val(x), next(NULL) {}
   * };
   */
  class Solution {
  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode *ret = new ListNode(0);
          ListNode *tmp = ret;
          int bt = 0; // 进位
          while(l1 != NULL || l2 != NULL){
              int n = (l1 ? l1->val:0) + (l2 ? l2->val:0) + bt;
              if(n >= 10){
                  bt = 1;
                  n = n - 10;
              }
              else{
                  bt = 0;
              }
              ListNode *node = new ListNode(n);
              tmp->next=node;
              tmp=tmp->next;
              if(l1) l1=l1->next;
              if(l2) l2=l2->next;
          }
          if(bt != 0)
              tmp->next = new ListNode(bt);
          return ret->next;
      }
  };
  ```

  

### 2. 合并二叉树  #617

- https://leetcode-cn.com/problems/merge-two-binary-trees/

- 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

  你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

- 思路1：二叉树的先序遍历 + DFS，递归

  ```c++
  /**
   * Definition for a binary tree node.
   * struct TreeNode {
   *     int val;
   *     TreeNode *left;
   *     TreeNode *right;
   *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   * };
   */
  class Solution {
  public:
      void DFS(TreeNode* t1, TreeNode* t2, TreeNode* &root){
          if(t1 == NULL && t2 ==NULL)
              return;
          else if(t1 != NULL && t2 ==NULL){
              root = new TreeNode(t1->val);
              DFS(t1->left, NULL, root->left);
              DFS(t1->right, NULL, root->right);
          }
          else if(t1 == NULL && t2 !=NULL){
              root = new TreeNode(t2->val);
              DFS(NULL, t2->left, root->left);
              DFS(NULL, t2->right, root->right);
          }
          else {
              root = new TreeNode(t1->val+t2->val);
  			      DFS(t1->left, t2->left, root->left);
  						DFS(t1->right, t2->right, root->right); 
          }
      }
      
      TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
          TreeNode *root = NULL;
          DFS(t1, t2, root);
          return root;
      }
  };
  ```

- 更简洁

  ```c++
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return NULL;
        }
        // 先合并根节点
        int val = (t1 == NULL ? 0 : t1->val) + (t2 == NULL ? 0 : t2->val);
        TreeNode* root = new TreeNode(val);
        // 再递归合并左右子树
        root->left = mergeTrees(t1 == NULL ? NULL : t1->left, t2 == NULL ? NULL : t2->left);
        root->right = mergeTrees(t1 == NULL ? NULL : t1->right, t2 == NULL ? NULL : t2->right);
        return root;
    }
  ```



### 3. 合并二叉树 #226

- https://leetcode-cn.com/problems/invert-binary-tree/

- 递归思路

  ```c++
  TreeNode* invertTree(TreeNode* root) {
          //递归
          if(root == NULL || (root->left == NULL && root->right == NULL))
              return root;
          TreeNode *p = root->left;
          //左右交换
          root->left = invertTree(root->right);
          root->right = invertTree(p);
          return root;        
      }
  ```





### 4. 明汉距离 #461

- https://leetcode-cn.com/problems/hamming-distance/

- 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目

- 思路：先做异或运算，得出的值进行数1的个数

  ```c++
  int hammingDistance(int x, int y) {
      int count = 0;        
      y = x ^ y;
      while(y != 0){
          y &= y - 1;
          count++;
      }    
      return count;  
  }
  ```



### 5. 二叉树的最大深度 #104

- https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

- 给定一个二叉树，找出其最大深度。二叉树的深度为根节点到最远叶子节点的最长路径上的节点数

- 思路1：递归

  ```c++
  int maxDepth(TreeNode* root) {
      if(root == NULL) 
          return 0;
      return max(maxDepth(root->left), maxDepth(root->right))+1;
  }
  ```

- 思路2：非递归，层序便利访问节点，最大的层数就是树的高度

  ```c++
  int maxDepth(TreeNode* root) {
      queue<TreeNode *> q;
      if(root == NULL) 
          return 0;
      q.push(root);
      int size = 1;
      int height = 0;
      while(!q.empty()) {
  
        TreeNode* node = q.front();
              q.pop();
        size--;
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
  
        if (size==0) {
          height++;
          size = q.size();
        }
      }
      return height;
  }
  ```

  

  

### 6. 反转链表 #206

- https://leetcode-cn.com/problems/reverse-linked-list/

- 递归

  ```c++
  ListNode* reverseList(ListNode* head) {
      if (head == NULL || head->next == NULL) 
          return head;
      ListNode* p = reverseList(head->next);
     	//让我的后一个节点指向我
      head->next->next = head;
      head->next = NULL;
      return p;
  }
  ```

- 非递归，头插法

  ```c++
  ListNode* reverseList(ListNode* head){
     if(head == NULL) return head;
     ListNode *p, *r;
     p = head->next;
     head->next = NULL;
     while(p != NULL){
        r = p->next;
        p->next = head;
        head = p;
        p = r;
     }
  }
  ```

  

### 7. 只出现一次的数字 #136

- https://leetcode-cn.com/problems/single-number/

- 给定一个非空数组，找到仅出现一次的数字

- 思路1：暴力，O(n^2^)

- 思路2：哈希，额外空间O(n)，O(n)；c++中可以使用set来完成。

  ```c++
  int singleNumber(vector<int>& nums) {
        set<int> S;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            if (S.find(*iter) != S.end())
            {
                S.erase(*iter);
            } else {
                S.insert(*iter);
            }
        }
        return *S.begin();
    }
  --------------------------map类似------------------
  ```
  
  
  
- 思路3：利用异或运算——其他数字都出现两次

  ```c++
  int singleNumber(vector<int>& nums) {
          int ans = nums[0];
          if (nums.size() > 1) {
             for (int i = 1; i < nums.size(); i++) {
                 //相同两个数异或等于0；0和任何数异或是本身
                ans = ans ^ nums[i];
             }
          }
          return ans;
      }
  ```

- 思路4：排序，找出单个的值。Refer

  ```java
  public int singleNumber(int[] nums) {      
      Arrays.sort(nums);
      for( int i = 0; i < nums.length - 1; i++ ){
          if( nums[i] == nums[i+1] ){
              i = i + 1;                
          }else{                
              return nums[i];
          }            
      }        
      return nums[nums.length - 1];
  }
  ```

  


### 8. 合并两个有序链表 #21

- https://leetcode-cn.com/problems/merge-two-sorted-lists/

- 合并两个有序链表返回

- 思路：递归

  ```c++
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if(l1 == nullptr) return l2;
      if(l2 == nullptr) return l1;
      if(l1->val < l2->val){
          l1->next = mergeTwoLists(l1->next, l2);
          return l1;
      }else{
          l2->next = mergeTwoLists(l1, l2->next);
          return l2;
      }
  }
  ```




### 9. 二叉搜索树转换为累加树 #538

- https://leetcode-cn.com/problems/convert-bst-to-greater-tree/

- 给定一个二叉搜索树BST，把他转换为累加树Greater Tree，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

- ```properties
  输入: 二叉搜索树:
                5
              /   \
             2     13
  
  输出: 转换为累加树:
               18
              /   \
            20     13
  ```

- 思路：先遍历又分支，然后根，最后左分支；可以以此累加。—逆中序遍历，**递归**

  ```c++
  class Solution {
  public:
      TreeNode* convertBST(TreeNode* root) {
          int i = 0;
          InOrderTraver(root, i);
          return root;            
      }
      void InOrderTraver(TreeNode *root, int &sum){
          if(!root) 
              return;
          InOrderTraver(root->right, sum);
          root->val = root->val + sum;
          sum = root->val;
          InOrderTraver(root->left, sum);
      }
  };
  ```

  

### 10. 路径总和III #437

- https://leetcode-cn.com/problems/path-sum-iii/

- 给定一个二叉树，结点存放整数值。找出路径等于给定数值的路径总数。路径可以是中间的，但只能从上往下

- ```properties
  root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
  
        10
       /  \
      5   -3
     / \    \
    3   2   11
   / \   \
  3  -2   1
  
  返回 3。和等于 8 的路径有:
  
  1.  5 -> 3
  2.  5 -> 2 -> 1
  3.  -3 -> 11
  ```

- 思路1：暴力？ 双重递归，遍历所有结点为起点的路径。

  ```c++
  class Solution {
  public:
      int pathSum(TreeNode* root, int sum) {
          if(!root)
              return 0;
          int ret = countPath(root, sum);
          return pathSum(root->left, sum) + pathSum(root->right, sum) + ret;
      }
      int countPath(TreeNode *root, int sum){
          if(!root) return 0;
          int cnt = 0;
          if(root->val == sum) cnt++;
          cnt += countPath(root->left, sum - root->val) + countPath(root->right, sum - root->val);
          return cnt;
      }
  };
  ```



### 11. 最小栈 #155

- https://leetcode-cn.com/problems/min-stack/
- 设计一个支持push,pop,top操作，并能在O(1)时间内检索到最小元素的栈。
- 思路，维护栈顶的位置是最小值，辅助栈；
  - 入栈：先入元素再入最小值
  - 出栈：先出元素再出最小值

```c++
class MinStack {
private:
    stack<int> mm;
    vector<int> vec;
public:
    /** initialize your data structure here. */
    MinStack() { }
    
    void push(int x) {
        if(mm.empty() || x <= mm.top())
            mm.push(x);
        vec.push_back(x);
    }
    
    void pop() {
        if(vec.back() == mm.top())
            mm.pop();
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return mm.top();
    }
};
```



### 12. 镜像二叉树 #101

- https://leetcode-cn.com/problems/symmetric-tree/

- 思路1：递归，两个子树互为镜像。也就是说，两个🌲为镜像的规则为：

  - 根节点相同
  - 每个树的右子树和另一个树的左子树镜像对称

  - 时间O(N)，空间最差O(N)

  ```c++
  class Solution {
  public:
      bool isSymmetric(TreeNode* root) {
          if(root == NULL) return true;
          return isMirror(root->left, root->right);
      }
      bool isMirror(TreeNode *r1, TreeNode *r2){
          if(r1 == NULL && r2 == NULL)
              return true;
          if(r1 == NULL || r2 == NULL)
              return false;
          return (r1->val == r2->val) && isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
      }
  };
  ```

- 思路2：迭代。BFS，使用队列来进行遍历节点后存储，每次应该能拿到一对相等的值。

  ```c++
  class Solution {
  public:
      bool isSymmetric(TreeNode* root) {
          if(root == NULL) return true;
          queue<TreeNode *> q;
          q.push(root->left);
          q.push(root->right);
          while(!q.empty()){
              TreeNode *t1 = q.front(); q.pop();
              TreeNode *t2 = q.front(); q.pop();
              if(t1 == NULL && t2 == NULL) continue;
              if(t1 == NULL || t2 == NULL) return false;
              if (t1->val != t2->val) return false;
              q.push(t1->left);
              q.push(t2->right);
              q.push(t1->right);
              q.push(t2->left);
          }
          return true;
      }
  };
  ```

- 思路3：迭代+DFS。先按序入栈，然后出栈比较。

  ```java
  public boolean isSymmetric(TreeNode root) { 
      if (root == null) {
          return true;
      }
      Stack<TreeNode> stackLeft = new Stack<>();
      Stack<TreeNode> stackRight = new Stack<>();
      TreeNode curLeft = root.left;
      TreeNode curRight = root.right;
      while (curLeft != null || !stackLeft.isEmpty() || curRight!=null || !stackRight.isEmpty()) {
          // 节点不为空一直压栈
          while (curLeft != null) {
              stackLeft.push(curLeft);
              curLeft = curLeft.left; // 考虑左子树
          }
          while (curRight != null) {
              stackRight.push(curRight);
              curRight = curRight.right; // 考虑右子树
          }
          //长度不同就返回 false
          if (stackLeft.size() != stackRight.size()) {
              return false;
          }
          // 节点为空，就出栈
          curLeft = stackLeft.pop();
          curRight = stackRight.pop();
  
          // 当前值判断
          if (curLeft.val != curRight.val) {
              return false;
          }
          // 考虑右子树
          curLeft = curLeft.right;
          curRight = curRight.left;
      }
      return true;
  }
  ```

  

### 13. 相交链表

- https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
- 找出两个链表的相交点。
  - 如果两个链表没有交点，返回 null
  - 在返回结果后，两个链表仍须保持原有的结构。可假定整个链表结构中没有循环。
  - 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存

- 思路1：暴力，O(MN)

- 思路2：哈希法，先存储M链的地址，然后遍历N链，第一个找到的地址就是相交点。不过需要O(n)的空间复杂度。

  ```java
  public class Solution {
      public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
          Set<ListNode> set = new HashSet<>();
          
          ListNode p = headA;
          while(p != null) {
              set.add(p);
              p = p.next;
          }
          
          ListNode q = headB;
          while(q != null) {
              if(set.contains(q)) break;
              q = q.next;
          }
          
          return q;
      }
  }
  ```

  

- 思路3：双指针。指针分别指向A，B，长度不一时，先到末尾的指针指向另一个链表的头，这样就消除了长度差。再遍历至相交或者都到末尾(不相交)。

  ```c++
  class Solution {
  public:
      ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          if (headA == NULL || headB == NULL) return NULL;
          ListNode *pA = headA, *pB = headB;
          while (pA != pB) {
              pA = pA == NULL ? headB : pA->next;
              pB = pB == NULL ? headA : pB->next;
          }
          return pA;
      }
  };
  ```



### 14. 二叉树的直径 #543

- https://leetcode-cn.com/problems/diameter-of-binary-tree/

- 一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。两结点之间的路径长度是以它们之间边的数目表示。

- 思路：左右子树的高度和，最大值。

  ```c++
  class Solution {
  public:
      int diameterOfBinaryTree(TreeNode* root){
          int distance = 0;
          dfs(root, distance);
          return distance;
      }
      
      /**
       * distance 记录以root为根的子树的最大直径，返回树的高度
      */
      int dfs(TreeNode *root, int &distance){
          if (root == nullptr)
              return 0;
          int left = dfs(root->left, distance);
          int right = dfs(root->right, distance);
          distance = max(left + right, distance);
          return max(left, right) + 1;
      }
  };
  ```



### 15. 环形链表 #141

- https://leetcode-cn.com/problems/linked-list-cycle/

- 给定一个链表，判断其中是否有环

- 思路1：快慢指针。

  ```c++
  class Solution {
  public:
      bool hasCycle(ListNode *head) {
          if(head == nullptr || head->next == nullptr)
              return false;
          ListNode *slow = head, *fast = head->next;
          while(slow != fast){
              if(fast == nullptr || fast->next == nullptr)
                  return false;
              slow = slow->next;
              fast = fast->next->next;
          }
          return true;
      }
  };
  ```

- 思路2：哈希法，第二次出现时则说明有环。

  ```c++
  class Solution {
  public:
      bool hasCycle(ListNode *head) {
          map<ListNode *, int> m;
          while(head != NULL){
              if(m[head] == 0) //这个地方默认值不一定为0；
                  m[head] = 1;
              else
                  return true;
              head = head->next;
          }
          return false;
      }
  };
  ```



### 16. 环形链表2 #142

- https://leetcode-cn.com/problems/linked-list-cycle-ii/submissions/

- 有环则找出其入口

  ```c++
  class Solution {
  public:
      ListNode *detectCycle(ListNode *head) {
          ListNode *slow = head, *fast = head;
          while(fast != nullptr && fast->next != nullptr){
              slow = slow->next;
              fast = fast->next->next;
              if(slow == fast)
                  break;
          }
          if(fast == nullptr ||fast->next == nullptr)
              return NULL;
          ListNode *p1 = head, *p2 = slow;
          while(p1 != p2){
              p1 = p1->next;
              p2 = p2->next;
          }
          return p1;
      }
  };
  ```

- 拓展：求环的长度

  ```c++
  int cycLen(ListNode *cycIn){
      //入口结点
      ListNode *p = cycIn;
      int len = 1;
      while(p->next != cycIn){
          ++len;
          p = p->next;
      }
  }
  //或者快慢指针相遇后，再次相遇即是一圈的长度
  int cycLen(ListNode *head){
      ListNode *slow = head, *fast = head;
      while(fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;
          if(slow == fast)break;
      }
      if(!fast || !fast->next) return NULL; //无环
      int len = 0;
      while(fast && fast->next){
          len++; 
          slow = slow->next;
          fast = fast->next->next;
          if(slow == fast)break;
      }
      return len;
  }
  ```

  

### 17. 打家劫舍 #198

- https://leetcode-cn.com/problems/house-robber/

- 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

  给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

- 思路1：奇偶数的异型最优解。分别求奇偶数序列的和，优化：当累加的和不如另一个的数时，直接选择该数为当前最优解。

  ```c++
  int rob(vector<int>& nums) 
  {
  	int sumOdd = 0;
  	int sumEven = 0;
  
  	for (int i = 0; i < nums.size(); i++)
  	{
  		if (i % 2 == 0)
  		{
  			sumEven += nums[i];
  			sumEven = max(sumOdd, sumEven);
  		}
  		else
  		{
  			sumOdd += nums[i];
  			sumOdd = max(sumOdd, sumEven);
  		}
  	}
  	return max(sumOdd, sumEven);
  }
  ```

- 思路2：DP，假设h(i)为**前i个房子**能抢到的最大值,

  - h(1)=n1, h(2)=max(n1, n2);
  - n=3时，抢则h(3)=n1+n3，不抢则h(3)=h(2).
  - DP：h(i) = max{h(i-2) + ni, h(i-1)}

  ```c++
  class Solution {
  public:
      int rob(vector<int>& nums) {
          int prevMax = 0;
          int currMax = 0;
          for (int x : nums) {
              int temp = currMax;
              currMax = max(prevMax + x, currMax);
              prevMax = temp;
          }
          return currMax;
      }
    // 这样看可能更明白一点，空间复杂度大一些
      int rob(vector<int>& nums) {
          if(nums.size()==0) return 0;
          if(nums.size()==1) return nums[0];
          if(nums.size()==2) return max(nums[0],nums[1]);
          int h[nums.size()];
          h[0] = nums[0],h[1]=max(nums[0], nums[1]);
          for(int i= 2; i < nums.size(); i++){
              h[i] = max(h[i-2] + nums[i], h[i-1]);
          }
          return h[nums.size()-1];
      }
  };
  ```



### 18. 最小覆盖子串 #76

- https://leetcode-cn.com/problems/minimum-window-substring/submissions/

- 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

- 思路：经典的双指针+窗口问题，可以使用两个map分别存储查询时窗口中的字符表，和条件要求表。

  - 先向右拓展窗口直到满足基本要求
  - 然后更新最短的长度
  - 此时，移动左边指针来缩小窗口，直到不匹配；如此循环。

  ```c++
  class Solution {
  public:
      string minWindow(string s, string t) {
          //结果标准，起始点和长度
          int start, len = INT_MAX;
          //窗口大小
          int left=0, right=0;
          
          //存储变量的map
          unordered_map<char, int> need, window;
          for(char c: t)
              need[c]++;
          
          int match = 0;
          while(right < s.size()){
              char c1 = s[right];
              if(need.count(c1)){
                  window[c1]++;
                  if(window[c1] == need[c1])
                      match++; //符合要求的个数
              }
              
              right++;
              //左侧
              while(match == need.size()){
                  //更新
                  if(len > right - left){
                      len = right - left;
                      start = left;
                  }
                  char c2 = s[left];
                  if(need.count(c2)){
                      window[c2]--;
                      if(window[c2] < need[c2])
                          match--;
                  }
                  left++;
              }
          }
          return len == INT_MAX ? "" : s.substr(start, len);
      }
  };
  ```



### 19. 找到字符串中所有字母异位词 #438

- https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/

- 同上

  ```c++
  class Solution {
  public:
      vector<int> findAnagrams(string s, string p) {
          // 用数组记录答案
          vector<int> res;
          int left = 0, right = 0;
          unordered_map<char, int> needs;
          unordered_map<char, int> window;
          for (char c : p) needs[c]++;
          int match = 0;
  
          while (right < s.size()) {
              char c1 = s[right];
              if (needs.count(c1)) {
                  window[c1]++;
                  if (window[c1] == needs[c1])
                      match++;
              }
              right++;
  
              while (match == needs.size()) {
                  // 如果 window 的大小合适
                  // 就把起始索引 left 加入结果
                  if (right - left == p.size()) {
                      res.push_back(left);
                  }
                  char c2 = s[left];
                  if (needs.count(c2)) {
                      window[c2]--;
                      if (window[c2] < needs[c2])
                          match--;
                  }
                  left++;
              }
          }
          return res;
      }
  };
  ```

  

### 20. 无重复字符的最长子串 #3

- https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

- 给定一个字符串，请你找出其中不含有重复字符的 **最长子串** 的长度

- 同上

  ```c++
  class Solution {
  public:
      int lengthOfLongestSubstring(string s) {
          int res = 0;
          int left = 0, right = 0;
          
          unordered_map<char,int> sub;
          
          while(right < s.size()){
              char c1 = s[right];
              sub[c1]++;
              right++;
              // 如果 sub 中出现重复字符
              // 开始移动 left 缩小窗口,截断到上一个出现c1的位置开始为left
              while (sub[c1] > 1) {
                  char c2 = s[left];
                  sub[c2]--;
                  left++;
              }
              res = max(res, right - left);
          }
          return res;
      }
  };
  ```



### 21. 回文链表 #234

- https://leetcode-cn.com/problems/palindrome-linked-list/

- 请判断一个链表是否为回文链表

- 思路1：暴力，利用栈输出，然后依次比较。时间为O(N)，空间O(N)

  ```c++
  bool isPalindrome(ListNode* head) {
        stack<int> b;
        ListNode *p = head;
        while(p){
            b.push(p->val);
            p = p->next;
        }
        while(head){
            if(head->val == b.top()){
                b.pop();
                head = head->next;
                continue;
            }
            else return false;
        }
        return true;
    }
  ```

- 思路2：链表转置，然后和原链表比较，复杂度同上。三个指针，分别指向前驱、当前和后继结点，遍历至链表尾部，然后依次修改当前指针指向。

  ```c++
  bool isPalindrome(ListNode* head) {
          vector<int> f;
          ListNode* tmp = head;
          while(tmp){
              f.push_back(tmp->val);
              tmp = tmp->next;
          }
          ListNode* rev = revert(head);  //此处会修改指针
          for(int i:f){
              if(i == rev->val){
                  rev = rev->next;
              }
              else return false;
          }
          return true;
      }
      ListNode* revert(ListNode *head){
          ListNode* reverted = NULL;
          ListNode* cur = head;
          ListNode* pre = NULL;
          while(cur != NULL){
              ListNode* next = cur->next;
              if(next == NULL)
                  reverted = cur;
              cur->next = pre;
              pre = cur;
              cur = next;
          }
          return reverted;
      }
  ```

- 思路3：O(N)+O(1)。快慢指针找中点，然后反转后半部分。

  ```c++
  bool isPalindrome(ListNode* head) {
          if(head == nullptr || head->next == nullptr)
              return true;
          ListNode *slow = head, *fast = head;
          while(fast && fast->next){
              slow = slow->next;
              fast = fast->next->next;
          }
          ListNode *back = revert(slow);
          ListNode *front = head;
          
          while(front && back){
              if(front->val == back->val){
                  front =front->next;
                  back = back->next;
              }
              else return false;
          }
          return true;
          
          return true;
      }
      ListNode* revert(ListNode *head){
          ListNode* cur = head;
          ListNode* pre = NULL;
          while(cur != NULL){
              ListNode* next = cur->next;
              
              cur->next = pre;
              pre = cur;
              cur = next;
          }
          return pre;
      }
  ```

  

### 22. 最短无序连续子数组 #581

- https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/

- 给定一个整数数组，你需要寻找一个**连续的子数组**，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

  你找到的子数组应是**最短**的，请输出它的长度。

- 思路：找到原顺序的两侧拐点。

  ```c++
  int findUnsortedSubarray(vector<int>& nums) {
        vector<int> ss = nums;
        sort(ss.begin(), ss.end());
  
        int begin = 0, end = nums.size() - 1;
        //如果之前的数据就在正确的位置上，就移动指针位置
        while(nums[begin] == ss[begin] && begin < end)
            begin++;
        while(nums[end] == ss[end] && begin < end)
            end--;
        //相等时，代表之前就是有序的
        if(begin == end)
            return 0;
        else
            return end - begin + 1;
    }
  ```



### 23. 比特位计数 #338

- https://leetcode-cn.com/problems/counting-bits/

- 给定一个非负整数 **num**。对于 **0 ≤ i ≤ num** 范围中的每个数字 **i** ，计算其二进制数中的 1 的数目并将它们作为数组返回。

- 思路1：位运算。一个数减1与其自身按位与，则二进制中的最右位会变成0，然后依次右移操作。

  ```c++
  vector<int> countBits(int num) {
        vector<int> ret;
        for(int i = 0; i <= num; i++)
            ret.push_back(count1(i));
        return ret;
    }
    int count1(int num){
        int cnt = 0;
        while(num){
            cnt++;
            num = (num - 1) & num;
        }
        return cnt;
    }
  ```

- 思路2：DP。最低有效位

  - x = (1001011101) 2  = (605) 10
  - x' = (100101110) 2 = (302) 10

  可以看做一个递推关系式:*P*(*x*)=*P*(*x*/2)+(*x* mod 2)

  ```c++
  vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for(int i = 1; i <= num; i++){
            ret[i] = ret[i >> 1] + (i & 1);
        }
        return ret;
    }
  ```



### 24. 全排列 #46

- https://leetcode-cn.com/problems/permutations/submissions/

- 思路：回溯法+递归

  ```c++
  vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        findPremute(res, nums, 0);
        return res;
    }
    void findPremute(vector<vector<int>> &res, vector<int> &nums, int index){
        if(index == nums.size()){
            res.push_back(nums);
        }
        for(int i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            findPremute(res, nums, index+1);
            swap(nums[i], nums[index]);
        }
  
    }
  ```



### 25. 二叉树中序遍历 #94

- https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

- 思路1：递归

  - 时间复杂度：O(n)。递归函数 T(n) = 2 T(n/2)+1。
  - 空间复杂度：最坏情况下需要空间O(n)，平均情况为O(log n)

  ```c++
  vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      inorder(root, res);
      return res;
  }
  void inorder(TreeNode *root, vector<int> &res){
      if(root == nullptr)
          return;
      inorder(root->left, res);
      res.push_back(root->val);
      inorder(root->right, res);
  }
  ```

- 思路2：迭代。利用栈。

  ```c++
  vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      stack<TreeNode *> ss;
      TreeNode *cur = root;
      while(cur || !ss.empty()){
          while (cur != NULL) {
              ss.push(cur);
              cur = cur->left;
          }
          cur = ss.top(); ss.pop();
          res.push_back(cur->val);
          cur = cur->right;
      }
      return res;
  }
  ```



### 26. 根据身高重建队列 #406

- https://leetcode-cn.com/problems/queue-reconstruction-by-height/

- 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

- 思路：按身高排序后插入。假设候选队列为 A，已经站好队的队列为 B.

  从 A 里挑身高最高的人 x 出来，插入到 B. 因为 B 中每个人的身高都比 x 要高，因此 x 插入的位置，就是看 x 前面应该有多少人就行了。比如 x 前面有 5 个人，那 x 就插入到队列 B 的第 5 个位置

  ```c++
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      sort(people.begin(), people.end(), cmp);
      vector<vector<int>> res;
      for(vector<int> tmp: people){
          res.insert(res.begin() + tmp[1], tmp);
      }
      return res;
  }
  static bool cmp(vector<int> a, vector<int> b){
      if(a[0] > b[0])
          return true;
      if(a[0] == b[0] && a[1] < b[1])
          return true;
      return false;
  }
  ```



### 27.  二叉树展开为链表 #114

- https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

- 给定一个二叉树，原地将它展开为链表(按先序遍历)

- 思路：每次移动将右子树挂在左子树的最右结点上，然后左子树变右子树，左子树置空

  ```c++
  void flatten(TreeNode* root) {
      while (root != nullptr) {
          if (root->left != nullptr) {
              auto most_right = root->left; // 如果左子树不为空, 那么就先找到左子树的最右节点
              while (most_right->right != nullptr) 
                most_right = most_right->right; // 找最右节点
              most_right->right = root->right; // 然后将跟的右孩子放到最右节点的右子树上
              root->right = root->left; // 这时候跟的右孩子可以释放, 因此我令左孩子放到右孩子上
              root->left = nullptr; // 将左孩子置为空
          }
          root = root->right; // 继续下一个节点
      }
      return;
  }
  ```

  ```java
  / 增加全局last节点
  TreeNode last = null;
  private void recursion(TreeNode root) {
      if (root == null) return;
      // 前序：注意更新last节点，包括更新左右子树
      if (last != null) {
          last.left = null;
          last.right = root;
      }
      last = root;
      // 前序：注意备份右子节点，规避下一节点篡改
      TreeNode copyRight = root.right;
      recursion(root.left);
      recursion(copyRight);
  }
  ```

- 思路2：暴力

  ```c++
  class Solution {
  private:
      vector<TreeNode*> t;
  public:
      void modify(TreeNode *p) {
          t.push_back(p);
          if (p->left) modify(p->left);
          if (p->right) modify(p->right);
          return;
      }
      void flatten(TreeNode* root) {
          if (root) modify(root);
          for (int i = 0; i < t.size(); ++i) {
              t[i]->left = nullptr;
              t[i]->right = i + 1 < t.size() ? t[i + 1] : nullptr;
          }
          return;
      }
  };
  ```



### 28. 不同的二叉搜索树 #96

- https://leetcode-cn.com/problems/unique-binary-search-trees/submissions/

- 给定一个整数 *n*，求以 1 ... *n* 为节点组成的二叉搜索树有多少种？

- 思路：DP。

  稍后我们将看到，G(n)可以从 F(i, n)得到，而 F(i, n)又会递归的依赖于 G(n)。

  首先，根据上一节中的思路，不同的二叉搜索树的总数 G(n)，是对遍历所有 i (1 <= i <= n) 的 F(i, n)之和。换而言之：

  ![image-20190722204625873](assets/image-20190722204625873.png)

  给定一个有序序列 1 ... n，为了根据序列构建一棵二叉搜索树。我们可以遍历每个数字 i，将该数字作为树根，1 ... (i-1) 序列将成为左子树，(i+1) ... n 序列将成为右子树。于是，我们可以递归地从子序列构建子树。 在上述方法中，由于根各自不同，每棵二叉树都保证是独特的。

  ![Screen Shot 2019-07-21 at 6.26.15 PM](assets/Screen Shot 2019-07-21 at 6.26.15 PM.png)

  ```c++
  int numTrees(int n) {
          int G[n+1] = {0};
          G[0] = 1;
          G[1] = 1;
  
          for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
              G[i] += G[j - 1] * G[i - j];
            }
          }
          return G[n];
      }
  ```

  

- ```c++
  int numTrees(int n) {
      int G[n+1] = {0};
      G[0] = 1;
      G[1] = 1;
  
      for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
          G[i] += G[j - 1] * G[i - j];
        }
      }
      return G[n];
  }
  ```

- 思路2：卡特兰数。

  ```c++
  class Solution {
    public int numTrees(int n) {
      // Note: we should use long here instead of int, otherwise overflow
      long C = 1;
      for (int i = 0; i < n; ++i) {
        C = C * 2 * (2 * i + 1) / (i + 2);  //卡特兰数的计算公式
      }
      return (int) C;
    }
  }
  ```



### 29. 排序链表 #148

- https://leetcode-cn.com/problems/sort-list/

- 给定O(nlogn)+O(1)的条件完成对链表的排序

- 思路：归并排序。使用快慢指针找到中间节点，断开链表，分别递归。最后合并

  ```c++
  ListNode* sortList(ListNode* head) {
      if (head == nullptr || head->next == nullptr)
          return head;
      ListNode *fast = head->next, *slow = head;
      //找到中点，奇数时左边多一个
      while (fast != nullptr && fast->next != nullptr) {
          slow = slow->next;
          fast = fast->next->next;
      }
      ListNode *tmp = slow->next;
      slow->next = nullptr;
      //递归分割
      ListNode *left = sortList(head);
      ListNode *right = sortList(tmp);
  
      ListNode *cur = new ListNode(0);
      ListNode *res = cur;
      while (left != nullptr && right != nullptr) {
          if (left->val < right->val) {
              cur->next = left;
              left = left->next;
          } else {
              cur->next = right;
              right = right->next;
          }
          cur = cur->next;
      }
      cur->next = left != nullptr ? left : right;
      return res->next;
  }
  ```

- 思路2：直接自底向上归并。

  ```c++
  ListNode* sortList(ListNode* head) {
      ListNode dummyHead(0);
      dummyHead.next = head;
      auto p = head;
      int length = 0;
      while (p) {
          ++length;
          p = p->next;
      }
  
      for (int size = 1; size < length; size <<= 1) {  //长度每次x2
          auto cur = dummyHead.next;
          auto tail = &dummyHead;
        
          while (cur) {
              auto left = cur;  //左半部分
              auto right = cut(left, size);  //右半部分
              cur = cut(right, size); //剩余部分
  
              tail->next = merge(left, right);
              while (tail->next) {
                  tail = tail->next;
              }
          }
      }
      return dummyHead.next;
  }
  
  ListNode* cut(ListNode* head, int n) { //将链表 l 切掉前 n 个节点，并返回后半部分的链表头
      auto p = head;
      while (--n && p) {
          p = p->next;
      }
  
      if (!p) return nullptr;
  
      auto next = p->next;
      p->next = nullptr;
      return next;
  }
  
  ListNode* merge(ListNode* l1, ListNode* l2) { //二路归并
      ListNode dummyHead(0);
      auto p = &dummyHead;
      while (l1 && l2) {
          if (l1->val < l2->val) {
              p->next = l1;
              p = l1;
              l1 = l1->next;       
          } else {
              p->next = l2;
              p = l2;
              l2 = l2->next;
          }
      }
      p->next = l1 ? l1 : l2;
      return dummyHead.next;
  }
  ```



### 30. 实现前缀树 #208

- https://leetcode-cn.com/problems/implement-trie-prefix-tree/

- 实现一个 Trie (前缀树)，包含 `insert`, `search`, 和 `startsWith` 这三个操作

- **备注**：Trie的核心思想是空间换时间。利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。 
  它有3个基本性质：https://www.cnblogs.com/luosongchao/p/3239521.html

  1. 根节点不包含字符，除根节点外每一个节点都只包含一个字符。
  2. 从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
  3. 每个节点的所有子节点包含的字符都不相同。

- 搭建Trie的基本算法也很简单，无非是逐一把每则单词的每个字母插入Trie。插入前先看前缀是否存在。如果存在，就共享，否则创建对应的节点和边。查询和存储同时开始。

- 可以应用在和串有关的top-k问题上

  ```c++
  class Trie {
  public:
      
      bool is_str; // 标识当前结点是否为一个完整的字符串
      Trie *next[26]; // 下一个结点的指针数组
      
      /** Initialize your data structure here. */
      Trie() {
          is_str = NULL;
          memset(next,0,sizeof(next));
      }
      
      /** Inserts a word into the trie. */
      void insert(string word) {
          Trie *cur = this; // cur初始化为根结点指针
          for(char w : word){ // 遍历word中的每一个字符
              if(cur->next[w-'a']==NULL){ // 下一个结点不存在，新增一个结点
                  Trie *new_node = new Trie();
                  cur->next[w-'a'] = new_node;
              }
              cur = cur->next[w-'a'];
          }
          cur->is_str = true; // 当前结点已经是一个完整的字符串了
      }
      
      /** Returns if the word is in the trie. */
      bool search(string word) {
          Trie *cur = this;
          for(char w : word){
              if(cur!=NULL)
                  cur = cur->next[w-'a']; // 更新cur指针的指向，使其指向下一个结点
          }
          return (cur!=NULL && cur->is_str); // cur指针不为空且cur指针指向的结点为一个完整的字符串，则成功找到字符串
      }
      
      /** Returns if there is any word in the trie that starts with the given prefix. */
      bool startsWith(string prefix) {
          Trie *cur = this;
          for(char w : prefix){
              if(cur != NULL)
                  cur = cur->next[w-'a'];
          }
          return (cur != NULL);
      }
  };
  
  /**
   * Your Trie object will be instantiated and called as such:
   * Trie* obj = new Trie();
   * obj->insert(word);
   * bool param_2 = obj->search(word);
   * bool param_3 = obj->startsWith(prefix);
   */
  ```

  

### 31. 每日温度 #739

- https://leetcode-cn.com/problems/daily-temperatures/

- 根据每日 `气温` 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 `0` 来代替。

- 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]

- 思路1：暴力，超时。

  ```c++
  vector<int> dailyTemperatures(vector<int>& T) {
      vector<int> res;
      int len  = T.size();
      int curMax = 0;
      for(int i = 0; i < len; i++){
          int cur = T[i];
          int j = i;
          for(; j < len; j++){
              if(cur < T[j]){
                  res.push_back(j-i);
                  break;
              }
          }
          if(j==len) res.push_back(0);
      }
      return res;
  }
  ```

- 思路2：利用栈，逆序遍历。找到当前温度的第一个大于的值。

  ```c++
  vector<int> dailyTemperatures(vector<int>& T) {
      vector<int> res(T.size(), 0);
      stack<int> ss;
      for(int i = T.size()-1; i >=0; i--){
          // 当前元素比栈顶元素大 出栈 重新调整栈直至满足要求
          while(!ss.empty() && T[i] >= T[ss.top()]){
              ss.pop();
          }
          // 栈为空 即后面没有比当前天温度高的
          // 不为空 栈顶元素对应的下标减去当前下标即为经过几天后温度比当前天温度高
          res[i] = ss.empty()? 0 : ss.top() - i;
          // 当前元素进栈
          ss.push(i);
      }
      return res;
  }
  ```




### 32. 数组中第K大个元素 #215

- https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

- 在未排序的数组中找到第 **k** 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

- 思路1：暴力排序，然后输出；O(nlogn)最快

- 思路2：快排变形。依次折半直到找到目标，时间复杂度 : 平均情况 {O}(N)*O*(*N*)，最坏情况 {O}(N^2)*O*(*N*2)

  ```c++
  int findKthLargest(vector<int>& nums, int k) {
          //第size-k小的数
          return quickselect(nums, 0, nums.size()-1,  nums.size()-k);
      }
      int quickselect(vector<int>&  nums, int left, int right, int k){
          if (left == right) // If the list contains only one element,
              return nums[left];  // return that element
  
          int pivot_index = Partition(nums, left, right);
          //ut<<pivot_index<<" ";
          if(k == pivot_index)
              return nums[k];
          else if(k < pivot_index)
              return quickselect(nums, left, pivot_index - 1, k);
          else 
              return quickselect(nums, pivot_index + 1, right, k);
      }
      int Partition(vector<int>& num, int low, int high){
          int key = num[low];
          while(low<high){
              while(low < high && num[high] >= key)
                  high--;
              swap(num[low], num[high]);
              while(low < high && num[low] <= key)
                  low++;
              swap(num[low], num[high]);
          }
          return low;
      }
  ```

- 思路3：top-k问题，堆排序；维护一个k个数的小顶堆，保留前K个元素。依次入堆，若大于堆顶则入堆，最终保留的堆中最大的K个元素，堆顶为解答。O(nlogK)

  ```java
  class Solution {
      public int findKthLargest(int[] nums, int k) {
          Queue<Integer> heap = new PriorityQueue<>();
          for (int i = 0; i < k; i++)
              heap.add(nums[i]);
          for (int i = k; i < nums.length; i++) {
              if (nums[i] > heap.peek()) {
                  heap.remove();
                  heap.add(nums[i]);
              }
          }
          return heap.peek();
      }
  }
  ```



### 33. 二叉树层序遍历 #215

- https://leetcode-cn.com/problemset/hot-100/

- 思路：使用队列。

  ```c++
  vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;
      if(!root) return res;
      queue<TreeNode *> q;
      q.push(root);
      int size = 1;
      while(!q.empty()){
          vector<int> tmp;
          size = q.size();
          while(size--){
              TreeNode *node = q.front();
              q.pop();
              tmp.push_back(node->val);
              if(node->left)
                  q.push(node->left);
              if(node->right)
                  q.push(node->right);
          }
          res.push_back(tmp);                
      }
      return res;
  }
  ```

- 思路2：使用递归的DFS，增加一个高度(也就是层数来判断)。

  ```java
  class Solution {
  public:
      vector<vector<int>> levelOrder(TreeNode* root) {
          vector<vector<int>> res;
          pre(root,0,res);
          return res;
      }
      void pre(TreeNode *root,int depth,vector<vector<int>> &res)
      {
          if(!root) return;
          if(depth>=res.size())   //说明需要增加一层
              res.push_back(vector<int>{});
          res[depth].push_back(root->val);
          pre(root->left,depth+1,res);
          pre(root->right,depth+1,res);
      }
  };
  ```



### 34. 前K个高频元素 #347

- https://leetcode-cn.com/problems/top-k-frequent-elements/

- 给定一个非空的整数数组，返回其中出现频率前 **k** 高的元素。

- 思路1：哈希法。排序后暴力遍历

  ```c++
  class Solution {
  public:
      vector<int> topKFrequent(vector<int>& nums, int k) {
          vector<int> ret;
          unordered_map<int, int> mm;
          vector<vector<int>> top;
          for(int n: nums)
              mm[n]++;
          
          for(auto it = mm.begin(); it != mm.end(); ++it ){
              vector<int> tmp;
              tmp.push_back(it->first);
              tmp.push_back(it->second);
              cout<<it->first<<":"<<it->second<<endl;
              top.push_back(tmp);
          }
          cout<<"-------\n";
          sort(top.begin(),top.end(),[](vector<int> a, vector<int> b){return a[1] > b[1];});
          for(auto v:top){
              cout<<v[0]<<":"<<v[1]<<endl;
          }
          for(int i = 0 ; i < k; i++){
              ret.push_back(top[i][0]);
          }
          return ret;
      }
  };
  ```

  

- 思路2：哈希+桶排序。先使用哈希表存储频次；使用另一个桶，将哈希表中的数插入到索引为他的频次的桶里，也就是将频次作为键，数为值。然后倒序遍历k个即可。

- 思路3：topk，小顶堆，每次比较堆顶，大于堆顶则入堆.

  ```c++
  class Solution {
  public:
      struct compartor{
          bool operator()(pair<int,int> &left, pair<int,int> &right) {
              return left.second > right.second;
          }
      };
      vector<int> topKFrequent(vector<int>& nums, int k) {
          priority_queue<pair<int,int>, vector<pair<int,int> >, compartor> q;
          unordered_map<int, int> mp;
          for (auto i : nums) {
              mp[i]++;
          }
          for(auto item: mp){
              //pair<int,int> p(item->first, item->second);
              if(q.size() < k){
                  q.push(item);
              }
              else if (item.second > q.top().second) {
                  q.pop();
                  q.push(item);
              }
          }
          vector<int> ret(q.size(), 0);
      
          while (!q.empty()) {
              ret[q.size()-1] = q.top().first;
              q.pop();
          }
  
          return ret;
      }
  };
  ```
  
  

### 35. 回文子串 #647

- https://leetcode-cn.com/problems/palindromic-substrings/

- 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

- 思路1：暴力拓展法。

  ```c++
  class Solution {
  public:
      int countSubstrings(string s) {
          int ret = 0;
          int len = s.length();
          //奇数
          for(int i = 0 ; i < len; i++){
              int left = i-1;
              int right = i+1;
              while(left >= 0 && right < len ){
                  if(s[left] == s[right]){
                      ret++;
                      left--;
                      right++;
                  }
                  else break;
              }
          }
          ret += len;
          //偶数
          for(int i = 0 ; i < len-1; i++){
              if(s[i]==s[i+1]){
                  ret++;
                  int left = i-1;
                  int right = i+2;
                  while(left >= 0 && right < len ){
                      if(s[left] == s[right]){
                          ret++;
                          left--;
                          right++;
                      }
                      else break;
                  }
              }
          }
          return ret;
      }
  };
  ```

- 思路2：DP.

  ```c++
  int countSubstrings(string s) {
      int ret = 0;
      int len = s.length();
      //dp
      vector<vector<bool>> dp(len, vector<bool>(len, false));
      //1个和2个字符的串
      for(int i = 0 ; i < len; i++){
          dp[i][i] = true;
          ret++;
          if(i < len-1 && s[i] == s[i+1]){
              dp[i][i+1] = true;
              ret++;
          }
      }
      //3个长度到n个长度的串
      for(int size = 3; size <= len; size++){
          for(int start = 0; start < len - size + 1; start++){
              int end = start + size - 1;
              if(s[start] == s[end] && dp[start+1][end-1]){
                  ret++;
                  dp[start][end] = true;
              }
          }
      }
      return ret;
  }
  ```



### 36. 二叉树的最近公共祖先 #236

- https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

- 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。

- 思路1：哈希法，类似于#相交链表。这里先使用栈将p,q节点的路径存入栈，然后再比较。

  ```c++
  bool getPath(TreeNode *root, TreeNode *node, stack<TreeNode *> &path){
      if(root == nullptr)
          return false;
      path.push(root);
      if(root == node)
          return true;
      if(getPath(root->left, node, path))
          return true;
      if(getPath(root->right, node, path))
          return true;
      path.pop();
      return false;
  }
  
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      stack<TreeNode *> ppath, qpath;
      getPath(root, p, ppath);
      getPath(root, q, qpath);
      while(ppath.size() != qpath.size()){
          if(ppath.size() > qpath.size())
              ppath.pop();
          else
              qpath.pop();
      }
      while(ppath.top() != qpath.top()){
          ppath.pop();
          qpath.pop();
      }
      return ppath.top();
  }
  ```

  

- 思路2：递归。

  - 在左、右子树中分别查找是否包含p或q，如果（两种情况：左子树包含p，右子树包含q/左子树包含q，右子树包含p），那么此时的根节点就是最近公共祖先
  - 如果左子树包含p和q，那么到root->left中查找，最近公共祖先在左子树里面
  - 如果右子树包含p和q，那么到root->right中查找，最近公共祖先在右子树里面

  ```c++
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
          if(root == nullptr || root == p || root == q)
              return root;
          TreeNode *left = lowestCommonAncestor(root->left, p, q);
          TreeNode *right = lowestCommonAncestor(root->right, p, q);
          return left == nullptr ? right : (right == nullptr ? left : root);
      }
  ```

  