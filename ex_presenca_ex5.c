#include <stdio.h>

int ways(int s, int n2, int n5, int n10, int n20, int n50, int n100)
{
    int dp[s + 1];
    int notes[6] = {2, 5, 10, 20, 50, 100};
    dp[0] = 1;
    for (int i = 0; i < 6; i++)
    {
        for (int j = notes[i]; j <= s; j++)
        {
            dp[j] = 0;
            for (int k = 0; k <= i; k++)
            {
                int note = notes[k];
                int max_count = j / note;
                for (int l = 1; l <= max_count && l <= (k == 5 ? n100 : (k == 4 ? n50 : (k == 3 ? n20 : (k == 2 ? n10 : (k == 1 ? n5 : n2))))); l++)
                {
                    dp[j] += dp[j - l * note];
                }
            }
        }
    }
    return dp[s];
}

int main()
{
    int s, n2, n5, n10, n20, n50, n100;
    scanf("%d %d %d %d %d %d %d", &s, &n2, &n5, &n10, &n20, &n50, &n100);
    printf("%d\n", ways(s, n2, n5, n10, n20, n50, n100));
    return 0;
}
