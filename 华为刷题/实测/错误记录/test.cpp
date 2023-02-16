#include <iostream>
#include <string>
#include <deque>
#include <map>
using namespace std;
int main()
{
    string str;
    map<string, int> result;//map记录重复的次数
    deque<string> deq;//记录错误文件
    while (getline(cin, str))
    {
        //查找输入的最后一个斜杠“\”,后面的字符串付给str
        str = str.substr(str.find_last_of('\\') + 1);
        //查找后面字符串中空格的索引
        int pos = str.find_last_of(' ');
        if (pos > 16) {                          //文件名大于16
            str = str.substr(pos - 16);         //截取最后16个字符
        }
        if (result.find(str) == result.end())   //说明map里面还没有创建该文件名
            deq.push_back(str);                 //把文件名保存到dep双端容器中
        ++result[str];                          //map中存储次数；下标操作容器会同时创建key与deq不同的是，result保存全部输入数据
        if (deq.size() > 8)                      //只保存最新8个
            deq.pop_front();
    }
    for (auto x : deq) {
        cout << x << " " << result[x] << endl;
    }
    return 0;
}
