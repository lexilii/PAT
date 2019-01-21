---
# PAT
  
2019.1.21 lexi_lii   
    
    记录PAT刷题过程中的心得体会，以及涉及到的陌生知识点。

---

## 1001 A+B Format

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
## 1002 A+B for Polynomials

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
## 1003 Emergency 
     
### `思路`
      
   用 `迪杰斯特拉算法` 实现
     
   * `算法用途` 
     
        通常用来求解 `起点` 到 `目标点` 的 `最短路径`。
        
   * `算法特点`
     
        从离起点最近的点一层层向外扩展搜索，对每个节点进行遍历。
      
   * `算法思路`
     
       * 对所有节点状态进行初始化 `visit` `dist = INF`
       * 对起点状态初始化
       * 用邻接矩阵描述各点间的连通关系
       * 搜索所有未访问节点，寻找距离起点最近的节点，更新其状态为 `visit = 1`（已访问）
       * 在所有未访问节点中进行搜索  
          
          若 `dist[nearst]+ map[nearst][j] < dist[j]` , 则更新节点 `j` 到 `起点` 的最近距离
      
      
---      
## 1005 Spell It Right    
      
### `思路`

   * 由于`10^1000`远大于 int 和 double 的表达范围，应该采用字符串方式读入。   
   *  用`查表法`，下表搜索对应英文会快很多

### `小技巧`

   * ` '5'-'0' `就是 5（int）
   
---
## 1006 Sign In and Sign Out

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
      
      
      
      
      
      
