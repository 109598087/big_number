#include <stdio.h>
#include <stdlib.h>
#define LEN 100
void testOper(char input1[], char input2[], char op)
{
    char c[LEN];
    if(op == '+'){
        Add(input1, input2, c);
        re_Print(c);
    }
    if(op == '-'){
        Sub(input1, input2, c);
        re_Print(c);
    }
    if(op == '*'){
        Mul(input1, input2, c);
        re_Print(c);
    }
}
void Mul(char input1[], char input2[], char c[])
{
 char re_input1[LEN], re_input2[LEN];
 int i, j, len1 = strlen(input1), len2 = strlen(input2);
 for(i = 0;i<LEN;i++)
 {
     re_input1[i] = '0';
     re_input2[i] = '0';
     c[i] = '0';

 }
  for(i=0;i<len1;i++)
 {
     re_input1[i] = input1[len1-i-1];
 }

 for(i=0;i<len2;i++)
 {
     re_input2[i] = input2[len2-i-1];
 }

 //前置作業end
 int temp[LEN] = {0}, re_input1_int[LEN] = {0}, re_input2_int[LEN] = {0};
 int m_count; //計算幾個負數
 for(i=0;i<len1;i++){
    if(re_input1[i] == '-'){
        m_count += 1;
        break;
    }
    re_input1_int[i] = re_input1[i] - '0';
 }
 for(i=0;i<len2;i++){
    if(re_input2[i] == '-'){
        m_count += 1;
        break;
    }
    re_input2_int[i] = re_input2[i] - '0';
 }
 for(i=0;i<LEN;i++){
    for(j=0;j<LEN;j++){
        temp[i+j] += re_input1_int[j] * re_input2_int[i];
        if(temp[i+j]>=10){
            temp[i+j+1] += temp[i+j]/10; //進位
            temp[i+j] = temp[i+j]%10;     //取個位數
        }
    }
 }

 for(i=0;i<LEN;i++){
    c[i] = temp[i] +'0';
 }
 for(i=0;i<LEN;i++){
    if(c[LEN-i-1] != '0' && m_count == 1){
        c[LEN-i] = '-';
        break;
    }
 }

}
void Sub(char input1[], char input2[], char c[])
{
 char re_input1[LEN], re_input2[LEN];
 int i,len1 = strlen(input1), len2 = strlen(input2);

for(i = 0;i<LEN;i++)
 {
     re_input1[i] = '0';
     re_input2[i] = '0';
     c[i] = '0';

 }
  for(i=0;i<len1;i++)
 {
     re_input1[i] = input1[len1-i-1];
 }

 for(i=0;i<len2;i++)
 {
     re_input2[i] = input2[len2-i-1];
 }

 // 判斷正負號
 int input1_m = 0, input2_m = 0;
 for(i=0;i<LEN;i++)
 {
     if(re_input1[i] == '-')
        input1_m += 1;
     if(re_input2[i] == '-')
        input2_m += 1;
 }

if(input1_m == input2_m) //同號
{
 for(i=0;i<LEN;i++)
 {
     if(re_input1[i] == '-' )
     {
         if(len1>len2)
            c[i] = re_input1[i];
         else
            c[i] = re_input2[i];
     }
     else if(re_input2[i] == '-')
     {
         if(len2>len1)
            c[i] = re_input2[i];
         else
            c[i] = re_input1[i];
     }
     else
        if(len1>len2)
            c[i] = re_input1[i] - re_input2[i]+'0';
        else
            c[i] = re_input2[i] - re_input1[i]+'0';
     if(re_input1[i] == '0'&& re_input2[i] == '0') //有問題
        if(len1>len2)
            break;
        else
        {
            c[i] = '-';
            break;
        }
 }
 for(i=0;i<LEN;i++)
 {
        if(c[i] == '-' && c[i] == c[i+1])
        {
            c[i] = '0';
            c[i+1] = '0';
        }
 }
 int temp[LEN] = {0};
 for(i=0;i<LEN;i++)
 {
     if(c[i] == '-')
     {
         temp[i] = 100;
         break;
     }

     temp[i] = c[i] - '0';

 }

 for(i=0;i<LEN-1;i++)
 {
     if(temp[i]<0)
     {
         temp[i+1] -= 1;
         temp[i] = 10+temp[i];
     }

 }
 for(i=0;i<LEN;i++)
 {
     if(temp[i] == 100)
     {
         c[i] = '-'; //maybe problem
         break;
     }
     c[i] = temp[i] + '0';
 }
} //同號end
else
{
     int input1_rm = 0, input2_rm = 0;
     for(i=0;i<LEN;i++)
     {
         if(re_input1[i] == '-')
            re_input1[i] = '0';
            input1_rm = 1;
            break;
     }
     for(i=0;i<LEN;i++)
     {
         if(re_input2[i] == '-')
            re_input2[i] = '0';
            input2_rm = 1;
            break;
     }
     for(i=0;i<LEN;i++)
    {
     if(re_input1[i] == '-' )
     {
          if(len1>len2)
            c[i] = re_input1[i];
          else
            c[i] = re_input2[i];
     }
     else if(re_input2[i] == '-')
     {
         if(len2>len1)
            c[i] = re_input2[i];
         else
            c[i] = re_input1[i];
     }
     else
        c[i] = re_input1[i] + re_input2[i]-'0';
     if(re_input1[i] == '0' && re_input2[i] == '0') // 這裡有問題
        break;

    }
    if(len2>len1)
    {

        if(input2_rm == 1)
        {
            for(i=0;i<LEN;i++)
            {
                if(c[i] == '0' && c[i+1] == '0') //有問題
                {
                    c[i] = '-';
                    break;
                }
            }
        }


    }

     int temp[LEN];
     for(i=0;i<LEN;i++)
     {
         temp[i] = c[i] - '0';
     }
     for(i=0; i<LEN-1; i++)
     {

       if(temp[i]>=10) {

         temp[i+1]+=temp[i]/10;

         temp[i]=temp[i]%10;

       }
     }
     for(i=0;i<LEN;i++)
     {
         c[i] = temp[i] + '0';
         if(c[i] == '.')
         {
             c[i] = '1';
             c[i+1] = '-';
             break;
         }
     }
     for(i=0;i<LEN;i++)
     {
         if(c[i]=='-' && c[i+1] == c[i])
         {
             c[i] = '0';
             c[i+1] = '0';
             break;
         }
     }

 } //sub 異號 end
} //sub end
void Add(char input1[], char input2[], char c[])
{
 char re_input1[LEN], re_input2[LEN];
 int i, len1 = strlen(input1), len2 = strlen(input2);

 for(i = 0;i<LEN;i++)
 {
     re_input1[i] = '0';
     re_input2[i] = '0';
     c[i] = '0';

 }
 for(i=0;i<len1;i++)
 {
     re_input1[i] = input1[len1-i-1];
 }

 for(i=0;i<len2;i++)
 {
     re_input2[i] = input2[len2-i-1];
 }
 // 判斷是否有負號
 int input1_m = 0, input2_m = 0;
 for(i=0;i<LEN;i++)
 {
     if(re_input1[i] == '-')
        input1_m += 1;
     if(re_input2[i] == '-')
        input2_m += 1;
 }
 if(input1_m ==  input2_m) //同號
{
    for(i=0;i<LEN;i++)
    {
     if(re_input1[i] == '-' )
     {
          if(len1>len2)
            c[i] = re_input1[i];
          else
            c[i] = re_input2[i];
     }
     else if(re_input2[i] == '-')
     {
         if(len2>len1)
            c[i] = re_input2[i];
         else
            c[i] = re_input1[i];
     }
     else
        c[i] = re_input1[i] + re_input2[i]-'0';
     if(re_input1[i] == '0' && re_input2[i] == '0') // 這裡有問題
        break;

    }
 int temp[LEN];
 for(i=0;i<LEN;i++)
 {
     temp[i] = c[i] - '0';
 }
 for(i=0; i<LEN-1; i++)
 {

   if(temp[i]>=10) {

     temp[i+1]+=temp[i]/10;

     temp[i]=temp[i]%10;

   }
 }
 for(i=0;i<LEN;i++)
 {
     c[i] = temp[i] + '0';
     if(c[i] == '.')
     {
         c[i] = '1';
         c[i+1] = '-';
         break;
     }
 }

 } // add 同號 end
 else
 {
     printf("異號\n");
     for(i=0;i<LEN;i++)
     {
         if(re_input1[i] == '-')
            re_input1[i] = '0';
            break;
     }
     for(i=0;i<LEN;i++)
     {
         if(re_input2[i] == '-')
            re_input2[i] = '0';
            break;
     }
     for(i=0;i<LEN;i++)
     {
         if(re_input1[i] == '-' )
         {
             if(len1>len2)
                c[i] = re_input1[i];
             else
                c[i] = re_input2[i];
         }
         else if(re_input2[i] == '-')
         {
             if(len2>len1)
                c[i] = re_input2[i];
             else
                c[i] = re_input1[i];
         }
         else
            if(len1>len2)
                c[i] = re_input1[i] - re_input2[i]+'0';
            else
                c[i] = re_input2[i] - re_input1[i]+'0';
         if(re_input1[i] == '0'&& re_input2[i] == '0') //有問題
                break;
     }
     for(i=0;i<LEN;i++)
     {
            if(c[i] == '-' && c[i] == c[i+1])
            {
                c[i] = '0';
                c[i+1] = '0';
            }
     }
     int temp[LEN] = {0};
     for(i=0;i<LEN;i++)
     {
         if(c[i] == '-')
         {
             temp[i] = 100;
             break;
         }

         temp[i] = c[i] - '0';

     }

     for(i=0;i<LEN-1;i++)
     {
         if(temp[i]<0)
         {
             temp[i+1] -= 1;
             temp[i] = 10+temp[i];
         }

     }
     for(i=0;i<LEN;i++)
     {
         if(temp[i] == 100)
         {
             c[i] = '-'; //maybe problem
             break;
         }
         c[i] = temp[i] + '0';
     }



 }


}//add end
void re_Print(char n[]){
 int i;
 for(i=LEN-1; i>0; i--)
 {
   int x = n[i] -'0';
   if(x == 0)
   {
       continue;
 }
 for(;i>=0;i--)
 {
     printf("%c", n[i]);
 }
 printf("\n");
}
}


void main()
{
 char input1[] = "-99999", input2[] = "-999", output[LEN];

 testOper("-99999", "-999", '*');



}
