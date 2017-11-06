#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

class pork
{
    public:
    char number[54];
    char flower[52];
    
    pork();
    void wash();  
};

pork::pork(void)  //构造函数
{
    number[0] = 'A';
    number[1] = '2';
    number[2] = '3';
    number[3] = '4';
    number[4] = '5';
    number[5] = '6';
    number[6] = '7';
    number[7] = '8';
    number[8] = '9';
    number[9] = '0';
    number[10] = 'J';
    number[11] = 'Q';
    number[12] = 'K';
    for(int i = 13; i <= 52; i++)  //剩下A到k的构造
    {
        number[i] = number[i - 13]; 
    }
    number[53] = 'x';
    number[54] = 'd';

    // for(int i = 0; i < 13; i++)
    // {
    //     flower[i] = '♠';
    // }
    // for(int i = 13; i < 26; i++)
    // {
    //     flower[i] = '♠';
    // }
    // for(int i = 26; i < 39; i++)
    // {
    //     flower[i] = '♣';
    // }
    // for(int i = 39; i < 52; i++)
    // {
    //     flower[i] = '♦';
    // }

}

void pork :: wash(void)   //洗牌
{
    int n;
    srand((unsigned)time(0));
    for(int i = 0; i <= 52; i++)  //缺少大小王
    {
        int tmp ;  //下标
        int j;    //用来交换扑克牌上点的容器
        tmp = rand() % 52;
        j = number[i];
        number[i] = number[tmp];
        number[tmp] = j;
        
        if(i <= 52 && tmp <= 52)
        {
            int k;  //用来交换花色的容器
            k = flower[i];
            flower[i] = flower[tmp];
            flower[tmp] = k;
        }  
    }
}

class player:public pork   //玩家的类
{
    public:
    //
    char card[52];
    char cardNumber[52];  //每个人52张牌的点数
    char cardFlower[52];   
    player();
    void showPlayerCard(void);
};

    player::player() //人的构造
    {
        for(int i = 0 ; i < 52 ; i++)
        {
            cardNumber[i] = number[i];
            cardFlower[i] = flower[i];
        }
    }


    //玩家的手牌显示
    void player::showPlayerCard(void)
    {
        cout << "paly1:" <<endl;
        for(int i = 0 ; i < 13; i++)
        {
            cout << ' ' << cardNumber[i] ;
            //cout << cardFlower[i] ;
        }
        cout << endl;

        cout << "play2:" << endl;
        for(int i = 13 ; i < 26; i++)
        {
            cout << ' ' << cardNumber[i] ;
            //cout << cardFlower[i] ;
        }
        cout << endl;

        cout << "play3:" << endl;
        for(int i = 26; i < 39; i++)
        {
            cout << ' ' << cardNumber[i] ;
            //cout << cardFlower[i] ;
        }
        cout << endl;

        cout << "play4:" << endl;
        for(int i = 39; i < 52; i++)
        {
            cout << ' ' <<cardNumber[i];
            //cout << cardFlower[i] ;
        }
    }



int main()
{
    player p;
    
    pork k;
    k.wash();
    p.showPlayerCard();
}