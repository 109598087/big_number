#include <stdio.h>
#include <stdlib.h>
#define LEN 100
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

if(input1_m == input2_m)
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
}
else
{
 printf("異號");
}
 }



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

 }
 else
 {
     int input1_rm=0, input2_rm=0;
     printf("異號\n");
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



 } // 同號結束


}

void re_Print(char n[])
{
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
void Print(char n[])
{
    int i;
    for(i=0;i<strlen(n);i++)
    {
        printf("%c", n[i]);
    }
}

void main()
{
 char input1[] = "-5", input2[] = "-12345", output[LEN];
 int i;

 Add(input1, input2, output);
 //Sub(input1, input2, output);

 re_Print(output);


}
