#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>
using namespace std;

void func1()
{
    json js;
    js["msg_type"] = 2;
    // 添加key-value
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};
    cout << js << endl;
}

string func2()
{
    json js;
    // 直接序列化一个vector容器
vector<int> vec;
vec.push_back(1);
vec.push_back(2);
vec.push_back(5);
js["list"] = vec;
// 直接序列化一个map容器
map<int, string> m;
m.insert({1, "黄山"});
m.insert({2, "华山"});
m.insert({3, "泰山"});
js["path"] = m;
string sendBuf = js.dump();
return sendBuf;
}


int main()
{
    string rebuf = func2();
    json js = json::parse(rebuf);
    vector<int> v = js["list"];
    for(int val : v)
{
cout << val << " ";
}
cout << endl;


    return 0;
}