# PAT
  
2019.1.21 lexi_lii   
    
    记录PAT刷题过程中的心得体会，以及涉及到的陌生知识点。

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

   直接将sum用 `to_string(int)` 转化为字符串，然后用字符串的位数判断需要添加的 `,` 的个数以及位置。  
   ```cpp
   string.szie(); //返回大小
   ```
   ```cpp
   string.insert(int po, int n, int c); //在 po 处插入 n 个 e, 1 3 4 5 6 若 po = 2，则在 3 之后插入
   ```
    
   * `经验证，上述思路正确`

## 1002 A+B for Polynomials

### `思路1(别人的）`  

    建立 `result` 数组，按下标对应指数将两组数累加进去，合为 `0` 或 本身为 `0`  的项不输出，且统计 `k` 的时候要删掉。 

### `思路2(自己的）`  

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
      
   * `double 类型对象不可直接和 0 作比较，来判断其是否为0`
   
     ```cpp
     if(abs(a) > 1e-08)
     {
        //do something;
     }
     ```
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
