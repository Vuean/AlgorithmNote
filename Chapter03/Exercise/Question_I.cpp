// 问题 I: 锤子剪刀布 (20)
/*
现给出两人的交锋记录，请统计双方的胜、平、负次数，
并且给出双方分别出什么手势的胜算最大。
*/

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
//     int N;
//     cin >> N;
//     int win = 0, draw = 0, lose = 0;
//     int C_win = 0, J_win = 0, B_win = 0;
//     int C_win_yi = 0, J_win_yi = 0, B_win_yi = 0;
//     for(int i = 0; i < N; i++)
//     {
//         string Jia, Yi;
//         cin >> Jia >> Yi;
//         if (Jia == Yi)
//         {
//             draw++;
//         }
//         else if(Jia == "B" && Yi == "C")
//         {
//             win++;
//             B_win++;
//         }
//         else if(Jia == "B" && Yi == "J")
//         {
//             lose++;
//             J_win_yi++;
//         }
//         else if(Jia == "C" && Yi == "J")
//         {
//             win++;
//             C_win++;
//         }
//         else if(Jia == "C" && Yi == "B")
//         {
//             lose++;
//             B_win_yi++;
//         }
//         else if(Jia == "J" && Yi == "B")
//         {
//             win++;
//             B_win++;
//         }
//         else if(Jia == "J" && Yi == "C")
//         {
//             lose++;
//             C_win_yi++;
//         }
//     }
//     cout << win << " " << draw << " " << lose << endl;
//     cout << lose << " " << draw << " " << win << endl;
// }

#include<stdio.h>  
int main()  
{  int n, i, draw = 0, j[3]={0}, y[3]={0};   
    char jia,yi;  
    scanf("%d",&n);  
    getchar();
    for(i=0;i<n;i++)
    {
        scanf("%c %c",&jia,&yi);
        getchar(); 
        if(jia==yi)draw++;  
        else if(jia=='C'&&yi=='J')j[0]++;  
        else if(jia=='J'&&yi=='B')j[1]++;  
        else if(jia=='B'&&yi=='C')j[2]++;  
        else if(yi=='C'&&jia=='J')y[0]++;  
        else if(yi=='J'&&jia=='B')y[1]++;       
        else if(yi=='B'&&jia=='C')y[2]++;  
    }  
    int jiaWinSum = j[0]+j[1]+j[2], yiWinSum = y[0]+y[1]+y[2];  
    printf("%d %d %d\n",jiaWinSum,draw,n-jiaWinSum-draw);
    printf("%d %d %d\n",yiWinSum,draw,n-yiWinSum-draw);    
    char cs[]={'C','J','B'};  
    int maxIndex1 = 0, maxIndex2 = 0;  
    for(i=0;i<=2;i++)  
    {  
        if(j[i]==j[maxIndex1]&&cs[i]<cs[maxIndex1])
            maxIndex1=i;  
        else if(j[i]>j[maxIndex1])  
            maxIndex1=i;  
    }  
    for(i=0;i<=2;i++)  
    {  
        if(y[i]==y[maxIndex2]&&cs[i]<cs[maxIndex2])
            maxIndex2=i;  
        else if(y[i]>y[maxIndex2])  
            maxIndex2=i;  
    }  
    printf("%c %c\n",cs[maxIndex1],cs[maxIndex2]);  
    return 0;  
} 