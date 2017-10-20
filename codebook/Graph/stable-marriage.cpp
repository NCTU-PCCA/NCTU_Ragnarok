稳定婚姻是组合数学里面的一个问题。
问题大概是这样：有一个社团里有n个女生和n个男生，每位女生按照她的偏爱程度将男生排序，同时每位男生也按照自己的偏爱程度将女生排序。然后将这n个女生和n个男生配成完备婚姻。
如果存在两位女生A和B，两位男生a和b，使得A和a结婚，B和b结婚，但是A更偏爱b而不是a，b更偏爱A而不是B，则这个婚姻就是不稳定的，A和b可能背着别人相伴而走，因为他俩都认为，与当前配偶比起来他们更偏爱各自的新伴侣。
如果完备婚姻不是不稳定的，则称其是稳定的。通过证明，可以得到每一个n女n男的社团，都存在稳定婚姻的结论。但是这种情况只在异性的社团中存在。也就是说在同性的社团里面，稳定婚姻的存在性将不再被保证。
Gale - Shapley 算法
while 存在男人m是自由的且还没对每个女人都求过婚
选择这个男人m
令w是m的优先表中还没求过婚的最高排名的女人
if w是自由的
    （m，w）变成约会状态
    else w当前与m1约会
        if w更偏爱m1而不爱m
            m保持自由
            else w更偏爱m而不爱m1
                （m，w）变成约会状态
                m1变成自由
                endif
                endif
                endwhile
#include <iostream>
#include <queue>
#include <algorithm>
#include  <cstdio>
#include <string.h>
using namespace std;
int gg[30][30], mm[30][30];
int a[30], n, ggpre[30], mmpre[30];
queue<int>my;
void stable_marriage()
{
    int i;
    memset(ggpre, 0, sizeof(ggpre)); //gg优先选择.
    memset(mmpre, -1, sizeof(mmpre)); //mm优先选择.
    int pm, pf;
    while (!my.empty())
    {
        pm = my.front();
        my.pop();
        pf = gg[pm][ggpre[pm]];
        ggpre[pm]++;
        if (mmpre[pf] < 0) mmpre[pf] = pm; //pf是自由的（pm，pf）变成约会状态
        else if (mm[pf][mmpre[pf]] < mm[pf][pm]) //pf更喜欢pm1,pm保持自由.
        {
            my.push(pm);
        }
        else                           //pf更喜欢pm,而不是pm1,(pm,pf)变成约会状态.
        {
            my.push(mmpre[pf]);
            mmpre[pf] = pm;
        }
    }
    for (i = 0; i < 26; i++)
        if (mmpre[i] > -1) ggpre[mmpre[i]] = i;
    for (i = 0; i < n; i++)
        printf("%c %c\n", a[i] + 'a', ggpre[a[i]] + 'A');
    puts("");
}
int main()
{
    int i, j, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        char temp, str[30];
        while (!my.empty())
            my.pop();
        for (i = 0; i < n; i++)
        {
            scanf(" %c", &temp);
            a[i] = temp - 'a';
            my.push(temp - 'a');
        }
        sort(a, a + n);
        for (i = 0; i < n; i++)
            scanf(" %c", &temp);
        for (i = 0; i < n; i++)
        {
            scanf("%s", str);
            for (j = 0; j < n; j++)
                gg[str[0] - 'a'][j] = str[j + 2] - 'A';
        }
        for (i = 0; i < n; i++)
        {
            scanf("%s", str);
            for (j = 0; j < n; j++)
                mm[str[0] - 'A'][str[j + 2] - 'a'] = j;
        }
        stable_marriage();
    }
    return 0;
}
