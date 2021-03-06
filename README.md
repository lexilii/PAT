---
# PAT
  
2019.1.21 lexi_lii   
    
    记录PAT刷题过程中的心得体会，以及涉及到的陌生知识点。

---

# Table Of Contents

## 入门

### 简单模拟
    
    简单按题目说的作，考察代码能力
    
* [1042 Shuffling Machine](#1042)    
* [1046 Shortest Distance ](#1046)  
* [1065 A+B and C ](#1065)  
* [1002 A+B for Polynomials](#1002)
* [1009 Product of Polynomials](#1009)


### 查找元素
 
	给定一些元素，然后查找某个满足条件的元素。

	* 如果需要在一个比较小范围的数据集里进行查找，那么直接遍历即可
	* 如果需要查找的范围较大，那么可以用 `二分查找` 等算法来进行更快速的查找
	* 考虑在读入数据的时候就进行处理！！    
    	
* [1011 World Cup Betting](#1011)    
* [1006 Sign In and Sign Out](#1006)    
* [1036 Boys vs Girls](#1036) 


### 图形输出
  
	题目给定一些规则，需要根据规则进行画图。所谓图形，其实是由若干字符组成的，只要弄清规则就可以编写代码。一般有两种做法：
	
	* 按照规律，直接进行输出
	* 定义一个二维字符数组，通过规律填充，然后输出整个二维数组
	 
* [1031 Hello World for U](#1031)

### 日期处理
  
	比如日期差值（求两个日期之间的天数）
    	
	* 思路：不妨假设第一个日期早于第二个日期，令第一个日期不断加`1天`，直到第一个日期等于第二个日期为止即可得出答案
	 
### 进制转换
  
	对一个 P 进制数，转换为 Q 进制，需要分为两步：
    	
	* 将 P 进制数 x 转换为 十 进制数 y
	* 将 十 进制数 y 转换为 Q 进制数 z

* [1019 General Palindromic Number](#1019)
* [1027 Colors in Mars](#1027)
* [1058  A+B in Hogwarts](#1058)

### 字符串处理

	 一般需要仔细分析清楚题目中的输入和输出格式，有些题目可能实现逻辑非常麻烦，会有许多细节和边界情况

* [1061 Dating](#1061)
* [1073 Scientific Notation](#1073)
* [1001 A+B Format](#1001)
* [1005 Spell It Right](#1005)
* [1035 Password](#1035)
* [1077 Kuchiguse](#1077)
* [1082 Read Number in Chinese](#1082)


## 算法初步

### 排序

	 排序是基础算法之一，属于常见题型（冒泡排序、选择排序、插入排序）
	 
	 由于考试中的排序题大部分只需要得到排序的最终结果，而不需要写完整的过程，推荐直接使用 C++ 中的 sort函数 进行排序

* [1012 The Best Rank](#1012)
* [1016 Phone Bills](#1016)
* [1025  PAT Ranking](#1025)
* [1028 List Sorting](#1028)
* [1055 The World's Richest](#1055)
* [1075 PAT Judge](#1075)
* [1083 List Grades](#1083)
* [1080 Graduate Admission](#1080)
* [1095 Cars on Campus](#1095)


### 散列

	 散列（Hash）是最常用的算法之一
	 
	 定义：将元素通过一个函数转换为整数，使得该整数可以尽量唯一地代表这个元素
	 
	 通常可以使用标准库模板中的 map 来直接使用 hash 的功能


* [1084 Broken Keyboard](#1084)
* [1092 To Buy or Not to Buy](#1092)
* [1041 Be Unique](#1041)
* [1050 String Subtraction](#1050)
* [1048 Find Coins](#1048)


### 递归

	分治法 :
	   
	   将原问题划分为若干个规模较小而结构与原问题相同或相似的子问题，然后分别解决这些子问题，最后合并子问题的解，即可得到原问题的解。
	
	 * 减治：子问题的个数为1 （n的阶乘）
	 * 分治：子问题的个数大于1 （Fibonacci数列的求解过程）
	 
	 既可以使用 `递归` 的手段实现，也可以使用 `非递归` 的手段去实现。
	 
	 递归很适合用来实现分治思想
	 * 递归边界 ：返回最简单底层的结果
	 * 递归式 ：用来减少数据规模并向下一层递归
	 

### 贪心

	 是求解一类 `最优化问题` 的方法，总是考虑在当前状态下局部最优（或较优）的策略，来使全局的结果达到最优（或较优）


* [1070 Mooncake](#1070)	
* [1033 To Fill or Not to Fill](#1033)
* [1037 Magic Coupon](#1037)
* [1067 Sort with Swap(0, i)](#1067)
* [1038 Recover the Smallest Number](#1038)



### 二分

	 在一个严格递增序列中找出给定的数
	 
* [1085  Perfect Sequence](#1085)
* [1010  Radix](#1010)
* [1044  Shopping in Mars](#1044)
* [1048  Find Coins](#1048)



### two pointers

	  通常基于递增数组，快排算法、归并算法就用到了two pointers的思想
	  
* [1085  Perfect Sequence](#1085)
* [1089 Insert or Merge ](#1089)
* [1029 Median ](#1029)



### 其他高效技巧与算法

    打表、活用递推、随机选择算法
    
* [1093 Count PAT's ](#1093)
* [1101 Quick Sort ](#1101)


## 数学问题

### 简单数学

* [1069 The Black Hole of Numbers](#1069)
* [1104 Sum of Number Segments](#1104)
* [1008 Elevator](#1008)

### 分数的四则运算

 ```cpp
  struct Fraction  // 分数
  {
  	int up;    // 分子 
  	int down;  // 分母（非负）
  }
 
 ```
	 由于分数的乘法和除法过程中可能使分子或分母超过 int 型表示范围，因此一般情况下，分子分母应当使用 long long 型来存储。
	 
	 
	 
* [1081 Rational Sum](#1081)
* [1088 Rational Arithmetic](#1088)
---

* [1003 Emergency](#1003)
* [1007 Maximum Subsequence Sum](#1007)

* [1013 Battle Over Cities](#1013)
* [1015](#1015)
* [1017 Queueing at Bank](#1017)
* [1020 Tree Traversals](#1020)
* [1021 Deepest Root](#1021)
* [1022 Digital Library](#1022)
* [1023 Have Fun with Numbers](#1023)
* [1032 Sharing](#1032)




---
## 1001

### `思路1`  
 
   起先决定用1000对求和结果取余，再将余数转化为字符串，用字符串相加的方式添加 `,` 分隔符进去，最终输出字符串，核心代码如下：  
   ```cpp    
   cin>>a>>b;  
   sum = a + b;  
   tempSum = abs(sum);  
   do {  
        quotient = tempSum/1000; //商  
        remainder = tempSum%1000; //余数  
        if(quotient != 0)  
          result = "," + to_string(remainder) + result;  
        else  
          result = to_string(remainder) + result;  
        tempSum = quotient;  
      } while(tempSum != 0);  
      
   if (sum<0)  
       result = "-" + result;  
   ```
  * `漏洞`  
     
     如果系数是 `00x` 或 `000` 或 `0xx` ，就会拼接出错。比如 `sum = 100 009` ，输出就会变成 `100,9` 。

### `思路2`  

   直接用 `to_string(int)`将 `sum` 转化为字符串，然后用字符串的位数判断需要添加的 `,` 的个数以及位置。  
   ```cpp
   string.szie(); //返回大小
   ```
   ```cpp
   string.insert(int po, int n, int c); //在 po 处插入 n 个 e, 1 3 4 5 6 若 po = 2，则在 3 之后插入
   ```
    
   * `经验证，上述思路正确`

### `小技巧`
  
   * `to_string(int)` 可以将 int 转化为 string
                                                                                         

---
## 1002 

### `思路1(参考）`  

   建立 `result` 数组，按下标对应指数将两组数累加进去，合为 `0` 或 本身为 `0`  的项不输出，且统计 `k` 的时候要删掉。 

### `思路2(mine）`  

  * `易错点`  
  
    * 小数输出精确到小数点后 1 位  
    * 系数和为 0 后，该项不统计也不输出
 
  * `构建结构体`
    ```cpp
    struct Polynomials
    {
      int exponents;
      double coefficients;
    
      //构造函数
      Polynomials( int e=0, double c=0):exponents(e),coefficients(c) {}  
    }
     ```
  * `建立循环`  
  
    只要两个vector都没到尽头，循环就一直继续
    
  * `循环内分类讨论`
  
    * vector1 到头，vector2 直接循环叠加到 result 后
    * vector2 到头，vector1 直接循环叠加到 result 后
    * vector1 vector2 都没结束
      1. vector1 的系数 > vector2 的系数
      2. vector1 的系数 < vector2 的系数
      3. vector1 的系数 = vector2 的系数:系数相加，`涉及系数和为 0  的特殊情况`
      
### `小技巧`
  
   * `double 类型对象不可直接和 0 作比较，来判断其是否为0`
   
     ```cpp
     if(abs(a) > 1e-08)
     {
        //do something;
     }
     ```
   
---
## 1003  
     
### `思路`
      
   用 `迪杰斯特拉算法` 实现
     
   * `算法用途` 
     
        通常用来求解 `起点` 到 `目标点` 的 `最短路径`。
        
   * `算法特点`
     
        从离起点最近的点一层层向外扩展搜索，对每个节点进行遍历。
      
   * `算法思路`
     
       ```cpp
        Dijkstra()
        {
            //初始化；
            for( 循环n次 )
            {
                u = 使 dis[u] 最小的还未被访问的顶点的编号;
                记 u 为确定值;
                for(从 u 出发能到达的所有顶点 v )
                {
                    if(v 未被访问 && 以 u 为中介点使 s 到顶点 v 的最短距离更优）
                        优化dis[v];
                }
            }
        }
        
        
        //邻接矩阵
        int n, e[maxv][maxv];
        int dis[maxv], pre[maxv]; //pre用来标注当前节点的前一个节点
        bool vis[maxv] = {false};
        
        void Dijkstra(int s) //s是源点
        {
            fill(dis ,dis + maxv ,inf); //距离初始化为无穷远
            dis[s] = 0;
            for(int i=0; i<n; i++)
                pre[i] = i;//初始状态设每个点的前驱为自身
            for(int i=0; i<n; i++)
            {
                int u = -1;
                int minn = inf;
                for(int j=0; j<n; j++）
                {
                    if(visit[j] == flase && dis[j] < minn)
                    {
                        u = j;
                        minn = dis[j];
                    }
                }
                if(u == -1)
                    return;
                visit[u] = true;
                for(int v=0; v<n; v++)
                {
                    if(visit[v] == false && e[u][v] != inf && dis[u] + e[u][v] < dis[v])
                    {
                        dis[v] = dis[u] + e[u][v];
                        pre[v] = u; //pre 来标注当前节点的前一个节点 
                    }
                }
            }
        }
       ```
   * `三种考法`（第一标尺是距离，如果距离相等，新增第二标尺）
   
     * 新增边权：在最短路径有多条时要求路径上的花费之和最小
     ```cpp
      for(visit[v] == false && e[u][v] != inf)
      {
          if(dis[u] + e[u][v] < dis[v])
          {
              dis[v] = dis[u] + e[u][v];
              c[v] = c[u] + cost[u][v];
          }
          else if(dis[u]+e[u][v] == dis[v] && c[u] + cost[u][v] < c[v])
          {
              c[v] = c[u] + cost[u][v];
          }
      }
      ```
   * 新增点权：在最短路径有多条时要求路径上的点权之和最大
     ```cpp
      for(int v=0; v<n; v++)
      {
          if(visit[v] == false && e[u][v] != inf)
          {
              if(dis[u] + e[u][v] < dis[v])
              {
                  dis[v] = dis[u] + e[u][v];
                  w[v] = w[u] + weight[v];
              }
              else if(dis[u] + e[u][v] == dis[v] && w[u] + weight[v] > w[v])
              {
                  w[v] = w[u] + weight[v];
              }
          }
      }
     ```
  *  直接问有多少条最短路径  
   num[s] = 1，其余num[u]=0表示从起点s到达顶点u的最短路径的条数为num[u]。
     ```cpp
      for(int v=0; v<n; v++)
      {
          if(visit[v] == false && e[u][v] != inf)
          {
              if(dis[u] + e[u][v] < dis[v])
              {
                  dis[v] = dis[u]+e[u][v];
                  num[u] = num[v];
              }
              else if(dis[i] + e[u][v] == dis[v])
              {
                  num[v] = num[u] + num[v];
              }
          }
      }
     ```
 
### `小技巧`   

   * 迪杰斯特拉算法！！

---      
## 1005    
      
### `思路`

   * 由于`10^1000`远大于 int 和 double 的表达范围，应该采用字符串方式读入。   
   *  用`查表法`，下表搜索对应英文会快很多

### `小技巧`

   * ` '5'-'0' `就是 5（int）
   
---
## 1006 

### `思路1(mine)`
      
  * 构建结构体
      ```cpp
      struct Register
      {
        string ID;
        int signIn[3];
        int signOut[3];
      }
      
      vector<Register> list;
      ```
  * 读入数据，计算 `时、分、秒` ,存入 signIn 和 signOut
  * 比较时间（先h、再m、最后s）  
  * 判断 signIn 最小和 signOut 最大的ID分别输出

### `思路2(更优！！)`
      
   只需要所有人中 Sign_In_Time 最小和 Sign_Out_Time 最大的，所以初始化所有人中 unlock_time = "23:59:59" , lock_time = "00:00:00"
  * 每输入一个 ID_number Sign_in_time Sign_out_time  
    ```cpp
    if (Sign_in_time <= unlock_time)
    {
        unlock_time = Sign_in_time;
        In_ID = ID_number
    }
    
    if(Sign_out_time >= lock_time)
    {
       lock_time = Sign_out_time;
       Out_ID = ID_number;
    }
    
    string minT = "23:59:59";
    string maxT = "00:00:00";
    string tmp_in, tmp_out;
    string strID;
    ...
    for(int i=0; i<num; i++)
    {
       cin>> strID >> tmp_in >> tmp_out;
       if(tmp_in <= minT) //string 类型可以直接大小比较 “23:59:58 > 23:59:57”
       {
          mins= strID;
          minT = tmp_in;
       }
       if(tmp_out >= maxT)
       {
          maxs= strID;
          maxT = tmp_out;
       }
    }
    cout<< mins << " " << maxs << endl;
    ```

### `小技巧`
      
   C++ 字符串比较！！！ 通过比较字符串来比较时间先后 
      
      
      
      
      
---
## 1007 

### `思路1(mine)`      
      
   * 穷举法改进，复杂度O(n^2)，这题数据较小可通过
   * 用连续子序列 `[i,j]` 的和求 `[i,j+1]` 的和  
    
   ```cpp
     for(int i=0; i<size; i++)
     {
        tempSum = 0;
        for(int j=i; j<size; j++)
        {
            tempSum += data[j];
            if(tempSum > findSum) // findSum 初始化为 -1 或 -INF，因为最大和可能为0
            {
                finalSum = tempSum;
                start = i;
                end = j;
            }
        }
     }
   ```
   * 需要考虑的几种特殊情况：  
   
     * 输入 3 -1 -2 -3   输出 0 -1 -3 （全为负）  
     * 输入 3 0 1 0 输出 1 0 1（当前后有0时，取前不取后）  
     * 输入 1 0  输出 0 0 0
    
### `思路2(参考)`        
      
   * `联机算法`
     
     在任意时刻对要操作的数据只读入（扫描）一次，一旦被读入并处理，就无需再记忆。而在此处理过程中算法能对它已经读入的数据，立即给出相应子序列问题的正确答案。
     
   * `容易相通`
   
     最大子序列的首位不可能是负数——因为负数只能拉低总和，不如舍弃。
     
   * `推广` 
   
     任何 `负` 的子序列不可能是最优子序列的前缀
     
   * `方法` 
   
     假设已知以位置 `i-1` 为结尾的最大子序列和 `b[i-1]`，对于以位置 `i` 为结尾的最大连续子序列和 `b[i]`
     
     ```cpp
        b[i] = max{ b[i-1] + a[i] , a[i]};
     ```
     然后只需要令 `b[0]=a[0], maxSum = a[0]`, 然后从一开始按上述规则遍历求和 b[i] ,并用maxSum记录下最大的b[i]即可。
          
     ```cpp
        int* maxSubSum ( const vector<int> &a)
        {
            int thisSum = a[0], left = 0;
            int *maxSum = new int[3];
            maxSum[0] = a[0];
            maxSum[1] = maxSum[2] =0;
            for(int i=1; i<a.zie(), i++)
            {
                if(thisSum < 0)
                {
                    thisSum = a[i];
                    left = i;
                }
                else //thisSum>=0
                    thisSum += a[i];
                
                if(thisSum > maxSum[0])
                {
                    maxSum[0] = thisSum;
                    maxSum[1] = left;
                    maxSum[2] = i;
                }
            }
            
            return maxSum;
        }
     ```
### `小技巧`      
      
   * 联机算法！！
      
      
---
## 1008 

### `思路` 

* 可能会出现目的楼to就是当前层now的情况，这时候也需要停留5s



---
## 1009 

### `思路1(mine)`      
            
   用数组存储多项式，下标对应指数 exp
   
   * `注意`  
   
      * 数组最大长度是有限制的
      
        * 函数中的`char`（1字节）数组最大开到 4x518028 
        * 函数中的`int`（4字节）数组最大开到 518028
        * static/全局中int 最大开到10^7x10^7(static和全局开的是同一块空间）
      
      * A和B的最大项指数均可为1000，则乘积 result 的最高项指数可达 2000，因此数组大小要开成 `double result[2001]={0};`
      
### `小技巧`  

   * `IO 输出精度设置`
   
      ```cpp
        #include <iomanip>
        cout<<setprecision(n); //n代表保留几位
      ```
   * `注意`
   
     观察发现，若设置精度前设置了  
      ```cpp
      cout.setf(ios::fixed); //不足位补0
      ```
      保留的位数才从小数点后开始计，否则从小数点前开始计。
   
   
---
## 1010
  
### `思路`      
            
 * N1,N2 都是十位数，每一位的范围是【0-z】，即【0-35】。虽然每一位的范围是【0-z】,但不代表radix最大是36，radix可以非常大，需要设置long long 型。
 * 将给出进制的数 N1 转化为10进制数，然后循环找到满足要求的 N2 的进制数
 * radix 简单的从2开始枚举会超时，需要确定 radix 的范围进行二分查找，设 N2 为未知进制数
 	
	* 下界：N2 中最大一位数 +1
	* 上界：max(N1的十进制值，下界）+1（也可以不加1）
		 * 若上界 > N1,那么 N2 肯定会 > N1, 另外 N1 有可能 < 下界
 
 * 二分查找时，计算某进制下的数值可能会long long 溢出，可以用 `sum<0` 判断是否溢出
 
 	 * 往左继续二分：high = mid-1；
	 * 往右继续二分：low = mid+1；
	 * 若相等，则保存，并继续向左找出最小的符合进制（当某数只有一位时，在所有进制下都是相等的）
   
   
---
## 1012 

### `思路1(mine)`      
            
* `分析`
  
  * 排名并列应该为 1，1，3，4，5 而非1，1，2，3，4 ！！
  * 平均分四舍五入，按照 +0.5后取整（不四舍五入也可通过）
  * 存储科目成绩时按 A C M E 存储可以简化程序逻辑（因为要求排名相同时，按照 A C M E 的优先级输出）
  
* `建立结构体，存储学生成绩及排名情况`

   ```cpp
    struct Student{
        string ID;
        int best; //最好的成绩对应的下标（rank中）
        double grade[4] = {0}; //A C M E 顺序存储
        int rank[4] = {1,1,1,1};
        void calculateA(); //计算平均值A grade[0]
        void bestGrade(); //选四门成绩中排序最好的标号赋给best
    }
   ```
   
### `思路2(mine)`     

 * 对同类成绩分别进行排序
 * 每排序一次，对应更新每个学生该成绩的排名
 * 最后对应输入 id 的学生查询其各项排名，选择最优排名输出

### `小技巧`  

  * 初始化问题
  ```cpp
    int a[5] = {0}; //全部初始化为0
    int a[5] = {1}; //仅仅a[0]=1, 其余均为0
  ```  
  
  * 建立table存储对应成绩的名称，用下标索引
  ```cpp
    char table[4] = {'A','C','M','E'}; //可用 student.best 来索引table
  ```
   * 对 vector<自定义结构体> 定义 `sort算法`
   ```cpp
   #include <algorithm>
   
    struct Test{
      int memb1;
      int memb2;
    }
    
    bool SortByM1(const Test &v1, const Test &v2)
    {
        return v1.memb1 < v2.memb1; //升序排列
    }
   ```




---
## 1013 

### `思路`      
        
  * `本质`：一个图中，去掉某一个点，那么这张图至少需要添加多少条边来保持连通性
  
      * 一个 N 顶点的连通图，至少需要 N-1 条边
      * `深度优先搜索（DFS）`访问整张图的顶点，计算连通分量的个数，连通分量可以视为一个点
      * 利用`邻接矩阵v`存储整张图，用visit数组表示城市是否被遍历过
      * 对于每个被占领的城市，将其表示为遍历过的状态true即可
      
  * `深度优先搜索`
  
    * 思想
    
      * 从一个顶点 v0 开始，沿着一条路一直走到底。
      * 如果发现不能到达目标解，就返回上一个节点，然后从另一条路开始走到底
      * 这种尽量往深处走的概念就是`深度优先`
    
      ```cpp
        DFS(dep,...) //dep 代表目前DFS的深度
        {
            if(找到解 || 走不下去了）
            {
                //...
                return;
            }
            
            //枚举下一种情况，DFS(dep+1,...）
        }
      ```
    * 核心代码

    ```cpp
      /**
       * 前置条件是 visit 数组全部设置成 false
       * @param n 当前开始搜索的节点
       * @param d 当前到达的深度
       * @return 是否有解
      */
      
      bool DFS(Node n, int d)
      {
          if(isEnd(n,d))
          {
              return true; //一旦搜索深度到达一个结束状态，就返回true
          }
          
          for(Node nextNode in n) //遍历n相邻的nextNode
          {
              if(!visit[nextNode]]
              {
                  visit[nextNode] == true; //在下一步搜索中，nextNode不能再次出现
                  if(DFS（nextNode，d+1) //如果搜索出有解
                  {
                      //做些其他事情，例如记录结果深度等
                      return true;
                  }
                  //重新设置成false，因为它有可能出现在下一次搜索的别的路径中
                  visit[nextNode] = false;
              }
          }
          return false; //本次搜索无解
      }
    ```


### `小技巧`  

 * `printf 和 scanf 效率要远高于 std::cout 和 std::cin`
 
   cout和cin从实际测试的结果，速度比printf和scanf慢一个数量级以上。
   
   影响cout和cin的性能的有两个方面：同步性和缓冲区。  
   
   `同步性`可以通过ios_base::sync_with_stdio(false)禁用；  
   操作系统会对缓冲区进行管理和优化，但十分有限，使用了endl之后，会对缓冲区执行清空操作，这个过程会先执行’\n’，再执行flush操作，非常漫长，所以尽量使用‘\n’而不是endl执行换行。
   
   然后，还有一个cout和cin的绑定效果，两者同时使用的话，cin与cout交替操作，会有一个flush过程，所以还是会很漫长，可以通过cin.tie(0)禁用绑定。 
   
   但是需要注意的是，禁用同步之后，printf和scanf就不能用了，所以绕了一圈，还是用printf和scanf吧……


   ---
## 1016 

### `思路`      
        
一个用户要是没有任何有效的通话记录的话，就什么都不输出
* 通话时长可以将start和end的时间都转化为minute单位，然后相减计算
* 录入所有bill后需要按照人名和通话时间进行排序，自定义的比较函数很关键！！
  ```cpp
    bool mySort(const Record& r1, const Record& r2)
    {
	    if (r1.name != r2.name) //如果两条记录不是一个人的，则按照姓名拼音排列
    	{
	    	return r1.name < r2.name; //升序排列
    	}
    	else //是同一个人的通话记录
    	{
    		int total1 = r1.day * 24 * 60 + r1.hour * 60 + r1.minute;
    		int total2 = r2.day * 24 * 60 + r2.hour * 60 + r2.minute;
	    	return total1 < total2;
	    }
    }
  ```
* 设置一个标识量记录是否上一条是否录入on-line信息，对所有bill进行筛选，删除不具备对应关系的无效信息，复制到新的vector变量中
* 按要求计算通话时长和费用，输出

### `小技巧`  

* `字符串长度 & 字符串大小`

  * 字符串长度指字符串所含的字符个数，不包括最后的 '\0'  
  * 字符串大小指内存空间的大小，串长度加1才是所需空间
  ```cpp
    char str[MAX_SIZE];
    char str[MAX_LEN+1];
  ```
  
  ---
## 1017 

### `思路` 

设置每个窗口的availableTime，初始值设置为8：00：00，随着处理客户，按照每个客户的处理时长实时更新availableTime.
* 将所有的时间转化为 `s` 为单位
* 窗口的availableTime - 客户的arrivalTime = 客户的 waitingTime
* 如果客户到达之前就已经有窗口空闲，则窗口的 availableTime = 客户的 arrivalTime + processingTime
* 如果客户到达时还没哟窗口空闲，则窗口的  availableTime += 客户的 processingTime

### `小技巧`

* `注意`

  * 对所有用户按照到达时间先后进行排序
  * 哪个窗口优先空闲，就取哪个窗口办理业务

---
## 1019

### `思路` 

没什么特别注意的，考的是十进制转化任意进制。
   
   
---
## 1020

### `思路` 

* `两种思路`

  * 先构造二叉树，然后按层输出（需要用到链表和双向队列deque）
  * 不需要构建二叉树，直接将后序中序转换为前序，同时添加变量index指示当前根节点在二叉树中对应的下标（从0开始），按照index排序的结果就是层序遍历的顺序

* `二叉树遍历`
   
   二叉树本身不具有天然的全局次序，为实现遍历，需通过在各节点与其孩子之间约定某种局部次序，间接地定义某种全局次序。
   按惯例，左兄弟优先于右兄弟,若记作节点`v`,及其左右孩子`L`和`R`，则局部访问的次序可有`V L R`、`L V R`、`L R V`三种选择，根据节点`V`在其中的访问次序，三种策略相应称为 先序遍历（preorder）、中序遍历（inorder) 和 后序遍历(postorder)。
                   
     ![举例](https://github.com/lexilii/PAT/blob/master/pic/%E4%BA%8C%E5%8F%89%E6%A0%91.PNG)
   * `先序遍历`
      
      遍历顺序规则为【根左右】，先遍历根，再遍历左孩子，最后遍历右孩子
 
      ![先序遍历](https://github.com/lexilii/PAT/blob/master/pic/%E5%85%88%E5%BA%8F%E9%81%8D%E5%8E%86.png)
     
   * `中序遍历`
   
      遍历顺序规则为【左根右】
      
      ![中序遍历](https://github.com/lexilii/PAT/blob/master/pic/%E4%B8%AD%E5%BA%8F%E9%81%8D%E5%8E%86.png)
   
   * `后序遍历`
   
      遍历顺序规则为【左右根】
   
      ![后序遍历](https://github.com/lexilii/PAT/blob/master/pic/%E5%90%8E%E5%BA%8F%E9%81%8D%E5%8E%86.png)
      
  
* `二叉树重构` 

  二叉树的重构就是根据已知的二叉树 `前序` 、 `中序` 、 `后续` 遍历的数组重新构造出原二叉树。
  对于普通二叉树，可以由 `前序遍历 + 中序遍历` 或者 `后续遍历 + 中序遍历` 重构。（注意：二叉树各节点不能有相同值）
  
  ```cpp
                     1
                  /     \  
                 2       3
               /   \   /    \
             4      5 6      7
                   / \        \
                  8   9        10
  
  ```
  前序遍历：1 2 4 5 8 9 3 6 7 10  
  中序遍历：4 2 8 5 9 1 6 3 7 10  
  后续遍历：4 8 9 5 2 6 10 7 3 1  
  
  * 前序遍历+中序遍历重构二叉树
  
    * 前序遍历的顺序是：根->左子树->右子树   
    * 中序遍历的顺序是：左子树->根->右子树  

     前序遍历的第一个元素1就是整个二叉树的根节点，在中序遍历中找到该元素，则该元素把中序遍历数组分成左右两部分，分别为左子树（4 2 8 5 9）和右子树（6 3 7 10）；  
     前序遍历的第二个元素2为左子树的根节点，同理在中序遍历中找到该元素，左子树又被一分为二（4）和（8 5 9）；   
     ......  
     如此递归下去直到最后一个元素
     
     ```cpp
      Node* RebuildTree_Pre_In(int preorder[], int inorder[], int inorder_left, int inorder_right, int &pre_index)
      {
           if(inorder_left > inorder_right) //如果开始位置大于结束位置，说明已经处理到叶节点了
	 	  return NULL;
	       int key = preorder[pre_index++];
	       Node* node = new Node(key);
	 
	       if(inorder_left == inorder_right)
	           return node;
	  
	       int i;
	       for(i = inorder_left; inorder[i] != key; ++i)；//找到的i为根节点在中序遍历中的索引
	 
	       node->left = RebuildTree_Pre_In(preorder, inorder, inorder_left, i-1, pre_index);
	       node->right = RebuildTree_Pre_In(preorder, inorder, i+1, inorder_right, pre_index);
        
	     return node;
      }
     ```

   * 后序遍历+中序遍历重构二叉树

     * 后序遍历的顺序是：左子树->右子树->根  
     * 中序遍历的顺序是：左子树->根->右子树  
     
     后续遍历数组的最后一个元素 1 就是整个数组的根节点，在中序遍历数组中查找到该元素同样把整个数组分成两部分，左子树（4 2 8 5 9）和右子树（6 3 7 10）；    
     后续遍历数组的倒数第二个元素 3 就是右子树的根节点，同样又把上述右子树分成左右两部分（6）和（7 10）；    
     ......    
     如此地递归至最后一个元素。 
     `注意`: 我们在后序遍历数组是从根节点到右子树的顺序取值的，所以在递归的时候也要先从右节点开始。 
 
     ```cpp
      Node* RebuildTree_In_Post(int inorder[], int postorder[], int inorder_left, int inorder_right, int &post_index)
      {
          if(inorder_left > inorder_right) //如果开始位置大于结束位置，说明已经处理到叶节点了
	        return NULL;
	      int key = postorder[post_index--];
	      Node* node = new Node(key);
	  
	      if(inorder_left == inorder_right)
	          return node;
	  
	      int i;
	      for(i = inorder_left; inorder[i] != key; ++i)；//找到的i为根节点在中序遍历中的索引
	 
	      node->right = RebuildTree_In_Post(inorder, postorder, i+1, inorder_right, post_index);
	      node->left = RebuildTree_In_Post(inorder, postorder, inorder_left, i-1, post_index);

          return node;
       }
      ```
      
      
---
## 1021

### `思路` 

 * 第一个思路
     
     * 使用二维数组保存图的结构会有一个测试点超时！使用邻接矩阵；
     * 使用visit标记访问过的节点，对每个没有访问过的点DFS，获得连通分量的个数；
     * 如果只有一个连通分量，就先从一个节点dfs后获得此时的最深节点；
     * 取这些最深节点中的任意一个，继续DFS，获得所有的最深节点，将两次dfs的结果取并集。

 * 第二个思路
  
     * 使用 `并查集` 判断图是否为连通的。
     * 任意选取一点（此处取1，如不取1在n=1的情况下错误），做dfs搜索，选取其中最远距离的点集合A
     * 再从点集合A取一点做一次dfs，找到的所有距离最远的点以及集合A都是deepest root。
  
     * `并查集`
     
        并查集由一个整数型的数组和两个函数组成：
     
         * 数组 `pre[]` 记录了每个点的前导节点是什么 ，从1或者0开始编号（依据题意而定）
         * 函数 `find` 是查找
         * 函数 `join` 是合并
      
       并查集常见的应用：  
          
       * 求无向图的联通分量个数
       * 最近公共祖先（LCA）
       * 带限制的作业排序 
       * 实现Kruskar算法求最小生成树等
	  
 ```cpp
   int pre[1000];
   int find(int x)  // 查找 x 的根节点
   {
      int r = x;
      while(pre[r] != r)  // 返回根节点r  如果上一级是他本身，则他就是根节点
          r = pre[r];
      int i = x;
      int j;
      while(i != r)  // 路径压缩
      {
           j = pre[i];  // 在改变上级之前用临时变量 j 记录下他的值
	   pre[i] = r;  // 把上级改为根节点
	   i = j;
      }
      return r;
    }
       
    void join(int x, int y) // 让两个节点所在连通分支合并为一个
    {
       int fx = find(x);
       int fy = find(y);
       if(fx != fy)  // 如果不连通，就把他们所在的连通分支合并起来
           pre[fx] = fy;
    }       
 ```
       
### `小技巧`

  * 如果图中边的数目远远小于`n^2`称作稀疏图，这是用`邻接表`表示比用`邻接矩阵`表示节省空间;
  * 如果图中边的数目接近于`n^2`,对于无向图接近于n*(n-1)称作稠密图,考虑到邻接表中要附加链域，采用邻接矩阵表示法为宜。




---
## 1022

### `思路` 

  简单的数据读取并按要求输出相应目录的问题，题目本身并不难，但是在数据读入上出了问题，半天读不对，结果是对cin>>,scanf,getline(),cin.get()特性没掌握清楚。
  
  * cin>>
  
    回车符会留在缓冲区中，只不过cin流有一个默认状态是为输入操作符（“>>”）跳过空白，所以默认情况下，用输出操作读取时会跳过回车符等空白字符，实际上它是在缓冲区中的，可以通过noskipws操作符让输入操作符不跳过空白字符，这样就可以读取'\n'等空白字符了
 
 ```cpp
    #include <iostream>
    
    int main()
    {
       char m,n;
       std::cin>>m;
       std::cin>>std::noskipws>>n; // 不忽略空白字符
       return 0;
    }
    
```
   * cin.get()
   
      cin.get()是获取一个字符，回车也是字符，所以它会将回车（'\n'）当做字符读入，而cin>>则会跳过空格或回车
      
   * getline()
   
      getline()会读取缓存区的换行符导致直接换行  
      	  
	  * getline()函数之前的换行符，要用cin.get()吸收掉
	  * getline()函数之后的换行符会被读取，并换行，不需要考虑
	 
   * scanf
   
     C语言在读取键盘数据时，一般是带缓存的数据输入，需要按回车键才能完成该“行”数据的输入确认。   
     scanf()函数对这个回车确认符并不进行处理，回车符会留在缓冲区中，因此：  
     	
	  * 在下一个读 `字符` 操作函数（cin.get(),scanf("%c"),gets()等）运行时,会读到这个字符
	  * 而在读 `数值型数据` 或 `字符串` 时，scanf()会从第一个非空白字符（空白字符指：回车、空格、TAB键）开始读取，自动忽略前面的空白字符，而遇到空白字符结束该类型数据的输入。
      
### `小技巧`

  * 关于 string 的读入
  	* cin 在读到空格时就停止读取，所以输入 `asdf fghj`，输出 `asdf`
      
        ```cpp
         string s;
         cin >> s;
         cout << a << endl;
        ```
	* 若要保留空格，则需要用到 `getline`,此时在enter前的空格都能读到
  
        ```cpp
         string s;
         getline(cin,s);
        ```
	
  * C++ 中 cin、 cin.get()、cin.getline()、getline()、gets()等函数的用法
  	* `cin>>`  
       	  接受一个字符串，遇到`空格`、`TAB`、`回车`都结束  
     
        ```cpp
          #include<iostream> 
          using namespace std;
      
          void main()
          {
             //输入: jkljkl jkljkl 
             //输出：jkljkl
             char a[20];
             cin >> a;
             cout << a << endl;
          }
        ```
	* `cin.get()`
		* 用法1：cin.get(字符变量名) 可以用来接收字符
	
		```cpp
		  #include<iostream>
		  using namespace std;
		  void main()
		  {
	 	    //输入：jljlk
	  	    //输出：j
	  	    char ch;
	  	    ch  = cin.get(); //或者 cin.get(ch);
	  	    cout <<ch << endl;
	 	 }
		```
		* 用法2：cin.get(字符数组名，接收字符数目）用来接收一行字符串，可以接收空格
		
		```cpp
		  #include<iostream>
		  using namespace std;
		  void main()
		  {
	 	    //输入：jkl jkl jkl
	  	    //输出：jkl jkl jkl
		    
		    //输入: abcdeabcdeabcdeabcdeabcde(25个字符)
		    //输出：abcdeabcdeabcdeabcd (接收19个字符+1个'/0'）
	  	    char a[20];
	  	    cin.get(a,20);
	  	    cout <<a << endl;
	 	 } 
		```
	
	* `cin.getline()`  
	 
	 	* 此函数一次读取多个字符（包括空白字符），直到读满 N-1 个，或遇到指定的结束符位置（默认以'\n'结束）
	 	* 语法为：`cin.getline(字符指针(char*), 字符个数N(int), 结束符(char));`	  
		* `注意`：cin.getline()函数缺省的第三个参数为'\n'	
		* 当用在多维数组中的时候，也可以用`cin.getline(m[i],20)` 之类的用法
	```cpp
	    #include<iostream>
	    using namespace std;
	
	    int main()
	    {
	       //输入：jkljkljkl
	       //输出：jklj 
	       char m[20];
	       cin.getline(m,5); //接受5个字符到m中，最后一个为'/0'，所以只看到4个字符输出
	       cout<< m<< endl;
	    }
	  ```
	  
	  
	  
	* `getline()`
	  	
		* 需要包含 `#include<string>`  
	  	* 和cin.getline()类似，但是cin.getline()属于istream流，而getline()属于string流，是不一样的函数
		* getline()接受的字符串长度不受限制,回车结束读取
	  
	```cpp
	   #include<iostream>
	   #include<string>
	   using namespace std;
	
	   void main()
	   {
	      //输入：jkljkljkl
	      //输出：jkljkiljkl
	      
	      //输入：jkl jfkdld jklsfl
	      //输出：jkl jfkdld jklsfl
	      string str;
	      getline(cin,str);
	      cout<< str<< endl;
	   }
	
	```
	* `gets()`
	  
		* C 中的函数，可以无限读取，不会判断上限，以回车结束读取，所以程序员应保证buffer空间足够大，以便执行操作时不会发生溢出
		 * 与 cin.getline() 功能类似，但是不能自定义结束符，只能换行符结束
		* 需包含`#include<stdio.h>`  
		* gets()同样可以用在多维数组里面：`gets(m[i])`
	```cpp
	   #include<stdio.h>
	   #include<iostream>
	   using namespace std;
	
	   void main()
	   {
	      //输入：jkljkljkl
	      //输出：jkljkiljkl
	      
	      //输入：jkl jkl jkl
	      //输出：jkl jkl jkl
	      char m[20];
	      gets(m);      // 不能写成m=gets();
	      cout<< m<< endl;
	   }
	```
	   
  
  
  
---
## 1023
  
### `思路` 
  
 * 本质上就是 `大数加法`,需要用string存储
 * 注意最高位如果有进位也要保留！！！ 开始没有AC就是把最高位进位的情况忽略了。
  
  
---
## 1025
  
### `思路` 
  
 题目比较简单，主要考察自己定义 vector<结构体> 的排序函数，但是犯了两个低级错误：
 * 成绩排序应该是从大到小的降序排列，不是升序
 * 记录相同成绩的count变量应该在计算完排名再清除
 
 ```cpp
    for (int i = 0; i < totalTestee.size(); i++)
    {
		if (totalTestee[i].score != lastScore) // 和上一个人成绩不同
		{
			rank = rank + count + 1;
			totalTestee[i].final_rank = rank;
			lastScore = totalTestee[i].score;

			count = 0; //累计数清零
		}
		else // 和上一个人成绩相同
		{
			count++;
			totalTestee[i].final_rank = rank;
		}
    }
 ```
  

  
---
## 1028
  
### `思路` 
  
  题目很简单，考察自定义的vector排序函数。
  
  `注意:` 采用 cin cout 输入输出数据会有一个测试点不通过，改为 scanf printf 即可AC
  
### `小技巧`  

* 输入输出

  s运行时间上 cin > scanf , cout > printf ，所以数据量比较大的时候，尽量采用 scanf 和 printf
  
* scanf 获取 string
    
  ```cpp
     string s;
     char c[10];
     scanf("%s",c);
     s = c;
  ```
  
* printf 输出 string

  printf 输出字符串是针对 `char*` 的，printf 只能输出C语言中的内置数据，string不是C语言内置数据。  
  s 这个string类型的对象并非只有字符串，其中还有许多用于操作的函数，于是&s并非字符串的首地址，而是s这个对象的首地址。
  
  ```cpp
     string s;
     printf("%s",s.c_str()); // string 中c_string() 成员方法返回当前字符串的首字符地址
  ```

  
---
## 1029
  
### `思路` 
  
  其实就是`序列合并`的问题，只不过本题不要求把整个合并后的序列输出，只需要输出中位数即可。
  
### `注意`

* 如果两个序列都读入再合并则会发生`内存超限`，应该先读入第一个序列，然后边读第二个序列边执行合并
* long int 不是 long long
  
---
## 1031
  
### `思路` 
  
  简单，格式化输出
  
  `注意：` 循环之后需要重新计算 n2 的值
  
  
---
## 1032
  
### `思路` 

   * 利用链表的方式索引到下一个node，但是循环太多，导致最后一个测试点超时
   * 采用数组下标来索引相应的 node 地址
   
### `小技巧`

   * 开大数组发生堆栈溢出的问题
   
     C语言的内存分配如下： 
     
		* `代码区（Text Segment）`：就是用于放置编译过后的二进制机器码
		* `堆区（Heap）`: 用于动态内存分配，一般由程序员分配和释放，若程序员不释放，结束程序时有可能由操作系统回收。（其实就是malloc()函数能够掌控的内存区域）
		* `栈区（Stack）`：由编译器自动分配和释放，一般用来存放局部变量、函数参数
		* `全局初始化数据区/静态数据区（Data Segment）`：就是存放 全局变量 和 静态变量 的地方，这个区域被整个进程共享
		* `未初始化数据区（BBS）`:在运行时改变值，改变值（初始化）的时候，会根据它是全局变量还是局部变量，进到他们该去的区域。
  
     在Windows下：
		* `Data Segemnt` 所允许的空间大小取决于剩余内存的大小，也就是说，电脑剩余8G内存，int类型的二维数组甚至可以开到46340`*`46340的大小
		* `Stack` 的空间只有 2M ！！也就是2`*`1024`*`1024=2097152字节，局部变量顶多放得下524288个int类型
		 
     因此通常见到的定义如下：
    
```cpp
        #include <iostream>
     
        using namespace std;
     
        int dis[8000][8000]
        int main()
        {
           \\代码
        }
```
     
   想要在局部中开一个大数组怎么办？ 将它归到 Data Segment 中即可：
   
```cpp
        #include <iostream>
     
        using namespace std;
    
        int main()
        {
	   static int dis[8000][8000]
           \\代码
        }
```


---
## 1033
  
### `思路` 

* 将终点视为单位油价为0、离起点距离为D的加油站，然后对所有加油站按照距离起点`由近及远`排序
	
	* 如果起点处没有加油站，则直接输出 `The maximum travel distance = 0.00`
	* 如果起点处有加油站，假设当前所处加油站编号为now，接下来选取下一个前往的加油站
		
		 * 优先前往更低价格的加油站（加恰好能够到达加油站next的油）
		 * 没有更低油价的加油站时，前往油价尽可能低的加油站（加满油，前往next）
		 * 没有加油站可以到达时结束算法
---
## 1037
  
### `思路` 
  
  将两个序列排序，然后负数和负数相乘，正数和正数相乘，最后求和。
  
 * `贪心算法` 
 
    总是做出在当前看来是最好的选择
  
	* 贪心算法没有固定的算法框架，算法设计的关键是贪心策略的选择。
	* 选择的贪心策略必须具备无后效性，即某个状态以后的过程不会影响以前的状态，只与当前状态有关。
   
 * `思路误区` ：
  
	* 误认为应该找大小接近的数相乘，最后的和才最大，这是错的！！！
  	* 应该是尽量挑选大数相乘，这样才能获得最优结果。
  
  
---
## 1038
  
### `思路`    
   
   * 对字符串 str1 和 str2，如果 `str1+str2 < str2+str1` ，则将 str1 排在前面
   * 结果为零的时候，要输出0
   
   
   
---
## 1041
  
### `思路`  
  	
* `参考`
  	* 设置两个数组：
		 * int a[100001] 表示输入数字
		 * int HashTable[10001] = 0 为散列数组，用来记录 数字x 出现的次数
	
```cpp
	scanf("%d",&n); // n 个数
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);  // 当前输入的数为a[i]
		HashTable[a[i]]++;  // 数字a[i]出现的次数+1
	}
	
	int ans = -1; // 存放第一次出现的在序列中只有一个的数字
	for(int i = 0; i < n; i++)
	{
		if(HashTable[a[i]] == 1)
		{
			ans = a[i];
			break;
		}
	}

```
  
  
  
  
---
## 1042
  
### `思路`  

 * `mine`
	* 将cards存为table1
	* 每次置换存放到新的table2中
	* 结束一次shuffling，就将暂存的table2内容对table1的内容进行刷新
	
* `参考`
	 * 不是直接存储'S1'等来表示牌的花色，而是用数字对应相应的花色
	 * 对数字表示的花色进行 shuffling ，最后将数字按照13个为一轮转化为相应的花色输出
	
  
  
---
## 1044
  
### `思路`    
  
* 数据录入时，进行求和
	 
	 * `[x,...,y]`的和可由 `sum[y]-sum[x-1]` 求出，其中`sum[i]`表示`[1,...,i]`的和
	 
* 因为求和后的数列是递增数列（原序列都是正值），采用二分法，查找最接近目标 m 的区间 end 端点

    
---
## 1046
  
### `思路` 

 * `mine`
 	* 因为路径是一个环，算一边的路径，然后和剩下另一边的路径比较，选最短的输出
	 * 将全部路径相加，减去一边的就是另一边的路径长度
* `参考`
	 * 可以记录一个 ndis[] 数组，存储 1 号节点顺时针到达 i 号节点的距离，以节省查询时间！！！
	 * 于是对于每一个查询 left->right ，其结果就是 dis(left,right) 与 另一半的距离中的较小值
 
### `小技巧`

  可以读一组，输出一组结果！！！
  


---
## 1048
  
### `散列` 

用散列标记每个数出现的次数

* `注意`
	 * 虽然数列中的数 <= 500，但是 m 的范围为10^3以内，因此 HashTable 要开到 HashTable[1001], 否则 `m - v1` 可能超过500，发生段错误
	 * `v1 = m-v1` 的情况要特别对待
  
### `二分法`

* 定义int型数组a[]存放所有数，并进行从小到大的排序
* 对每个a[i]，用二分法查找是否存在 m-a[i]

* `注意`
	* 需要判断找到的 m-a[i] 是不是就是a[i]，即下标是否相同。如果下标相同，则说明找到的是同一个位置的数字
  


---
## 1050
  
### `思路`  
  	
* `参考`
  	* 设置两个数组：
		 * int a[10001] 表示输入字符
		 * int HashTable[128] = 0 为散列数组，用来记录 字符c 出现的次数


  
---
## 1055
  
### `思路`   
  
  需要注意的是，题目中最大输出个数 M <= 100，因此对于每个年龄而言，该年龄中财富排名在100以外的人永远不会被输出，所以可以将每个年龄中财富在100以内的人全部存储到另一个数组中，以降低后续查询的复杂度。
  
  

  
   
---
## 1061
  
### `思路`    
  
  仔细读题，理解题意
  
  * DAY: 前两个字符串的第一对相同位置的 A~G 的大写字母
  * HH: 寻找信息DAY的位置之后的第一对相同位置的 0~9 或 A~N 的英文字母
  * MM: 后两个字符串的第一对相同位置的 A~Z 或 a~z 的英文字母
  
### `注意`    
  
  * 需要对条件进行完整限定 A~G 或者 A~N，而不是 A~Z 即可
  
---
## 1065
  
### `思路` 
  
* long long 的表示范围是 `[-2^63,2^63)` 
* 考虑大数相加溢出
	 * a>0 , b>0 , a+b`<`0 则为正溢出
	* a<0 , b<0, a+b`>=`0 则为负溢出

  
  
  
  
  
---
## 1067
  
### `思路` 
  
  * 如果 `0` 当前在 `i` 号位，则找到数字 `i` 所处的位置，然后将二者交换
  * 一旦交换过程中数字 `0`  回到了 `0` 号位置，则上述策略就不能继续执行，这时需要将一个不在本位的数字与之交换
  
### `小技巧` 
  
  algorithm 头文件中的 swap(a,b) 很好用！
  
  
  
---
## 1069

### `思路`

两个函数：

 * 一个将int数组转换成int整数
 * 一个将int整数转换成int数组
  
### `注意`  

* 用vector存储序列，有一个测试点会超时
* 数据录入和输出时都要限定格式，因为录入的数可能不够四位，需要前面用零补齐


---
## 1070
  
### `注意` 

* 月饼库存和总售价可以是浮点数（题目之说是正数，并没说是正整数）


---
## 1073
  
### `思路`

* `mine`

	* 判断实数的正负，根据正负输出相应符号
	 * 判断指数正负
	 	 * 指数为正，再判断 指数位数 和 实数位数 的大小分开讨论
		 * 指数为负，再判断 指数位数 和 实数位数 的大小分开讨论


---
## 1075
  
### `思路`

* `注意`

	 * 所有题目都无有效提交（可以通过编译的提交）或 从未提交过任何题目的解答，则该学生不输出
	 	* 某问题从未提交过，输出‘-’
		 * 某问题提交过，但未通过编译，记为0分




---
## 1077
  
### `思路`

  我自己的思路不好，下面描述一种较优思路：
  
  * 考虑到 `公共后缀` 需要从后往前枚举字符串，因此不妨先将所有字符串反转，这样就把问题转换为求N个字符串的 `公共前缀`
  * 其次确保对字符串访问不越界，事先求出所有字符串的最小长度minLen，这个数据可以在读入字符串的过程中获得
  * 枚举所有字符串在 `[0,minLen)` 内的字符串，判断相同位置的字符是否相同
  	 * 相同，则累计公共前缀长度
	 * 不同，则停止枚举

  
### `注意`

   * 读入n之后要用getchar接收后面的换行符，否则会使循环内的getline读取这个换行符，导致第一个字符串读取错误
   * string 没有反转函数，需要自己编写
   
```cpp
	// 反转字符串 string str
	int len = str.length();
	for(int i = 0; i < len/2; i++)
	{
		char temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
 ```
 
  
---
## 1080
    
### `思路`
 
 * 需要设置 `Student` 和 `School` 两个结构体
 * 按照每个学生的成绩排名，按顺序选学校
 

---
## 1081
    
### `思路`

常规的分数四则运算题目，只需要令结构体Fraction存放分数的分子和分母，然后按照要求进行计算即可。

### `注意`

* 数据范围为 int ，因此两个分母相乘时，最大可达到long long，所以使用int会溢出，得到 “答案错误”
* 必须在每一步加法之后进行约分，如果全部加完再约分，会溢出
* 计算公约数时，算的是分子分母【绝对值】的公约数
---
## 1082
    
### `思路`

* 按照字符串方式处理
* 设置下标 `left` 和 `right` 来处理数字的每个节（个节、万节、亿节）的输出，即 left 指向当前需要输出的位，而 right 指向与 left 同节的个位
* 设置 flag 标记 是否存在累积的零，输出 flag 指向的位之前，先判断该位是否为 0：
	 * 为0 ： 令 `flag = true` ，表示存在累积的零
	 * 非0 ： 根据 flag 值判断是否需要输出额外的零，之后就可以输出该位本身以及该位对应的位号（十百千）
* 一整节输出之后，再输出 万 或 亿

### `注意`

* 只有当前位不是首位，且为 0 时才令flag = true （当输入为 0 时）
* 如果万节所有位都是0，那么要注意不能输出多余的万



---
## 1084
    
### `思路`

* `我的`

	* 构建一个名为 hashTable ，大小为 128 的结构体数组，其中分别存储 代表的 字符，读入顺序，读入的个数
	* 按照读入的字符作为数组下标，进行索引
	 * 存储字符，是为了在按照读入顺序排序后，数组下标失去与字符的对应关系时，用来标识该元素对应的字符
	 
* `参考`

	 * 枚举第一个字符串中的字符
	 	 * 对当前枚举字符c1，枚举第二个字符串中的字符（c2）， 如果 c1 或 c2 是小写字母，则变换为大写字母，然后判断是否相等
			 * 如果 c1 == c2，说明 c1 在第二个字符串中出现
			 * 如果 c1 != c2，则继续枚举下一个字符，如果对于 c1 ，无法在第二个字符串中找到与之相等的字符，则需要将 c1 输出
			 
	 * 设置 bool 型数组 HashTable[128] 表示该字符是否已经输出，如果 HashTable[c] == true，说明该字符已经输出


---
## 1085
    
### `二分法`

* p 与序列中的元素均可能达到 `10^9`，因此 `a[i]*p` 可能达到 `10^18`，必须使用 `long long` 进行强制类型转换
* 所有数列不能采用 `值传递` 的方式进行传参，这样一个测试例会运行超时

### `two pointers`

* 首先需要对数组进行`递增`排序
* while循环的结束条件需要包含`j<n`
* `int` 型相乘结果赋值给`long long`，需要强制类型转换，否则会发生截断
	```cpp
	res = (long long) a*p;
	```


---
## 1089

* 数据范围较小，归并排序可以不写合并函数，直接调用sort代替
* 因为要计算出下一步的序列后输出，因此归并排序采用非递归形式比较方便



---
## 1093

### `思路`

  对字符串中的每个A，计算它左边 P 的个数与它右边 T 的个数的乘积，然后把所有 A 的这个乘积相加就是答案
 
### `小技巧` 

* 通过设立 leftP 和 rightT 数组来递推统计每一位左右的 P 和 T 的个数
	```cpp
	if(str[i] == 'P')
	  	leftP[i] = leftP[i-1]+1;
	else
		leftP[i] = leftP[i-1];
  	```

---
## 1095
    
### `注意`

* 时间以 s 为单位可以简化操作
* 查询的时刻是按照从小到大排序的，如果对每个查询都从头到尾遍历，会运行超时
* 采用 map 数据结构存储 每辆车的停留时间，map具有按照key值从小到大自动排序的特性

### `小技巧`

* `查询当前车辆数`

	* 将 valid 数组按照时间从小到大排序，考虑到查询的时刻是按照时间顺序 `递增的`, 可以设置一个变量 now ，作为下标用以指向 valid 数组中的记录，使得 now 指向的记录的时刻不超过本次欲查询的时刻
	* 设置变量 numCar，记录当前校园里的车辆数
		 * 当 valid[now[] == "in" , numCar+1
		 * 当 valid[now[] == "out" , numCar-1

```cpp
	int numCar = 0;
	int now = 0; // 处理至当前查询时间
	for (int i = 0; i < k; i++)
	{
		int h, m, s;
		scanf("%d:%d:%d", &h, &m, &s);
		int qTime = h * 60 * 60 + m * 60 + s;

		while (now < valid.size() && valid[now].time <= qTime)
		{
			if (valid[now].status == "in")
				numCar++; // 车辆进入
			else
				numCar--; // 车辆离开
			now++;
		}

		printf("%d\n", numCar);
	}

```


---
## 1101

### `思路`

* 数组 leftMax 记录序列 A 的每一位左边的最大数（不含本位）
* 数组 rightMin 记录序列 A 的每一位右边的最小数
* `leftMax[i]<= A[i] <= rightMin[i]` 则说明 A[i] 是主元


---
## 1104

### `思路`

* 单纯靠双层循环计算sum会导致超时
* 列举 n = 4\5\6 等情况，观察各位数字出现的次数，得到规律，即第 i 个数字（从1开始编号）出现的次数为 `i*(n+1-i)`

### `注意`

* 整数溢出问题！！
```cpp
	// double sum, v;
	// int i,n;
	sum += v * i*(n + 1 - i);  // 正确
	sum += i*(n + 1 - i) * v;  // 错误 因为n的最大值为100,000，因此语句整数部分乘积最大为50,000*50,000>2^31-1，从而会造成溢出！
```
   
   
   
   
   
   
   
   
   
   
