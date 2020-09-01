#include <stdio.h>
#include <stdlib.h>
#define LEN 300

void Add(char a[], char b[], char c[])
{
    int temp[LEN];
    int i, strlen_a=0, strlen_b=0;
    for(i=0;i<LEN;i++)
    {
        if(a[i]!='0')
            strlen_a += 1;
        if(b[i]!='0')
            strlen_b += 1;
    }
    for(i=0;i<LEN;i++)
     {
         if(a[i] == '-' )
         {
              if(strlen_a>strlen_b)
                c[i] = a[i];
              else
                c[i] = b[i];
         }
         else if(b[i] == '-')
         {
             if(strlen_b>strlen_a)
                c[i] = b[i];
             else
                c[i] = a[i];
         }
         else
            c[i] = a[i] + b[i]-'0';
         printf("c[i]:%c\n", c[i]);

     }
     for(i=0;i<LEN;i++)
     {
         temp[i] = c[i] - '0';
     }
     for(i=0; i<LEN-1; i++) {

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
 char input1[] = "9999999", input2[] = "999", output[LEN];
 char re_input1[LEN], re_input2[LEN];
 int i, len1 = strlen(input1), len2 = strlen(input2);


 for(i = 0;i<LEN;i++)
 {
     re_input1[i] = '0';
     re_input2[i] = '0';
     output[i] = '0';

 }
 for(i=0;i<len1;i++)
 {
     re_input1[i] = input1[len1-i-1];
 }

 for(i=0;i<len2;i++)
 {
     re_input2[i] = input2[len2-i-1];
 }

 Add(re_input1, re_input2, output);

 re_Print(output);


}
