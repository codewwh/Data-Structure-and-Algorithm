#include <stdio.h>

int K;

int main()
{
    //ÊäÈëÊý¾Ý
    scanf("%d", &K);
    if(K>0 && K<=100000)
    {
    int num[K];
    for(int i = 0; i < K; i++)
     {
        scanf("%d", &num[i]);
      }
      int max = 0;
      int cur = 0;
      for(int i = 0;i < K;i++)
      {
        cur += num[i];
        if(cur>max)
        {
          max = cur;
        }
        cur=cur < 0 ? 0 : cur;
      }
    printf("%d",max);  
    }
    return 0;
}