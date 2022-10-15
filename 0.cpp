#include<stdio.h>

int main()
{
    int s, v;
    scanf("%d %d", &s, &v);
    int h = 0, m = 0;
    int time = 0, sum = 8*60;
    if(s%v==0)
    {
        time = s+10;
    }
    else
    {
        time = s+11;
    }
    h = sum-time;
    while(h>=60)
    {
        h/=60;
        while(m>=60)
        {
            m/=60;
            h++;
        }
    }
    
    printf("%02d:%02d\n", h, m);
    return 0;
}
