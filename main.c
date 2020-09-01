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
 Print(re_input1);
 printf("\n");
 Print(re_input2);





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
 int temp[LEN];
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
     if(re_input1[i] == '0' && re_input2[i] == '0')
        break;

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
 char input1[] = "-1234999", input2[] = "-66699", output[LEN];



 Add(input1, input2, output);
 //Sub(input1, input2, output);

 re_Print(output);


}
