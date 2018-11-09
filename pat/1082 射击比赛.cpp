/*
1082 射击比赛 （20 分）
本题目给出的射击比赛的规则非常简单，谁打的弹洞距离靶心最近，谁就是冠军；谁差得最远，谁就是菜鸟。本题给出一系列弹洞的平面坐标(x,y)，请你编写程序找出冠军和菜鸟。我们假设靶心在原点(0,0)。

输入格式：
输入在第一行中给出一个正整数 N（≤ 10 000）。随后 N 行，每行按下列格式给出：

ID x y
其中 ID 是运动员的编号（由 4 位数字组成）；x 和 y 是其打出的弹洞的平面坐标(x,y)，均为整数，且 0 ≤ |x|, |y| ≤ 100。题目保证每个运动员的编号不重复，且每人只打 1 枪。

输出格式：
输出冠军和菜鸟的编号，中间空 1 格。题目保证他们是唯一的。

输入样例：
3
0001 5 7
1020 -1 3
0233 0 -1
输出样例：
0233 0001
*/
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    string win, lose;
    int maxscore = 10000, minscore = 0;
    while (n--) {
        string s;
        int a, b;
        cin >> s >> a >> b;
        int score = a * a + b * b;
        if (score < maxscore) {
            maxscore = score;
            win = s;
        }
        if (score > minscore) {
            minscore = score;
            lose = s;
        }
    }
    cout << win << " " << lose;
    return 0;
}
