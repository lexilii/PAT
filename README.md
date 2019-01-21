# PAT
  
2019.1.21 lexi_lii   
    
    记录PAT刷题过程中的心得体会，以及涉及到的陌生知识点。

## 1001 A+B Format

* `思路1`  
 
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
     
     如果系数是`00x`或`000`或`0xx`，就会拼接出错。  
     比如`sum = 100 009`，输出就会变成`100,9`
