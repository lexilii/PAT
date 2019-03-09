---
# PAT
  
2019.1.21 lexi_lii   
    
    记录PAT刷题过程中的心得体会，以及涉及到的陌生知识点。

---

# Table Of Contents

* [1001 A+B Format](#1001)
* [1002 A+B for Polynomials](#1002)
* [1003 Emergency](#1003)
* [1005 Spell It Right](#1005)
* [1006 Sign In and Sign Out](#1006)
* [1007 Maximum Subsequence Sum](#1007)
* [1008 ](#1008)
* [1009 Product of Polynomials](#1009)
* [1011 ](#1011)
* [1012 The Best Rank](#1012)
* [1013 Battle Over Cities](#1013)
* [1015](#1015)
* [1016 Phone Bills](#1016)
* [1017 Queueing at Bank](#1017)
* [1019 General Palindromic Number](#1019)
* [1020 Tree Traversals](#1020)
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

* `二叉树遍历`
   
   二叉树本身不具有天然的全局次序，为实现遍历，需通过在各节点与其孩子之间约定某种局部次序，间接地定义某种全局次序。
   按惯例，左兄弟优先于右兄弟,若记作节点`v`,及其左右孩子`L`和`R`，则局部访问的次序可有`V L R`、`L V R`、`L R V`三种选择，根据节点`V`在其中的访问次序，三种策略相应称为 先序遍历（preorder）、中序遍历（inorder) 和 后序遍历(postorder)。
                      ![举例](https://github.com/lexilii/PAT/blob/master/pic/%E4%BA%8C%E5%8F%89%E6%A0%91.PNG)
   * `先序遍历`
      遍历顺序规则为【根左右】，先遍历根，再遍历左孩子，最后遍历右孩子
   ![先序遍历](https://github.com/lexilii/PAT/blob/master/pic/%E5%85%88%E5%BA%8F%E9%81%8D%E5%8E%86.png)
   
   * `中序遍历`：遍历顺序规则为【左根右】
   * `后序遍历`：遍历顺序规则为【左右根】
   
