#include <iostream>
#include <set>
#include <utility>

// 自定义比较器类
struct compare_{
    int a;
    compare_(int val):a(val){

    }
};

class MyComparator
{
public:
    bool operator() (const compare_& a, const compare_& b) const {
        // 按照绝对值大小比较
        return a.a > b.a;
    }
};

int main() {
    // 创建 map 对象，并指定自定义的比较器类 MyComparator
    std::set<compare_, MyComparator> myMap;
    std::move()
    // 插入一些键值对
    compare_ A(231);
    compare_ A1(223);
    compare_ A2(33);
    compare_ A3(134);
    myMap.insert(A);
    myMap.insert(A1);
    myMap.insert(A2);
    myMap.insert(A3);


    // 遍历 map，输出键和值
    for (const auto& pair : myMap) {
        std::cout << pair.a << std::endl;
    }

    return 0;
}
