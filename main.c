#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
int digit_count(long num)
{
    int count = 0;
    while(num>0)
    {
    count++;
    num=num/10;
    }
    return count;
}
int main(void)
{
    int otherSum=0, anotherSum=0, valid=0, x;
    long cardNum=get_long("Enter your credit card number:\n");
    long cardNum2 = cardNum;
    while(cardNum2>0)
    {
        cardNum2= cardNum2/10;
        x = 2*(cardNum2%10);
        if(x >= 10)
        {
            otherSum += (x%10) + (x/10);
        }
        else otherSum += x;
        cardNum2= cardNum2/10;
    }
    cardNum2 = cardNum; //reset the vlaue of cardNum2
    while(cardNum2>0)
    {
        anotherSum += cardNum2%10;
        cardNum2= cardNum2/100;
    }
    int totalSum = otherSum+ anotherSum;

    if(totalSum % 10 == 0)
        valid = 1;
    else
        valid = 0;
    cardNum2 = cardNum; //reset the vlaue of cardNum2
    if(!valid)
    { printf("INVALID\n"); exit(0);  }
    else if (valid==1)
    {
        while(cardNum2>0)
          {
            cardNum2=cardNum2/10;
            if( ( cardNum2==34 || cardNum2==37 ) && digit_count(cardNum)==15)
            {   printf("AMEX\n"); exit(0); }

            else if( (cardNum2==51 || cardNum2==52 || cardNum2==53 || cardNum2==54 || cardNum2==55 ) && digit_count(cardNum)==16)
            { printf("MASTERCARD\n"); exit(0); }

            else if(cardNum2==4 && ( digit_count(cardNum)==13 || digit_count(cardNum)==16 ) )
            {  printf("VISA\n");  exit(0); }
          }
            printf("INVALID\n");  exit(0);
     }
}
