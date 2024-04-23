/*************************************************************************
        > File Name: test1.cc
        > Author: amoscykl
        > Mail: amoscykl@163.com
        > Created Time: 2023年11月14日 星期二 16时51分51秒
 ************************************************************************/

#include <iostream>
using namespace std;
// class A {
// public:
//   void get() { std::cout << "a" << std::endl; }
//   int a;
// };

#include <algorithm>
#include <iostream>
#include <random>
class Soultion {
public:
  void maoPao(int (&a)[100]) {
    for (int i = 0; i < 100; i++) {
      int temp;
      for (int i = 0; i != 100; ++i) {
        for (int j = 0; j != 100; ++j) {
          if (a[i] > a[j]) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
          }
        }
      }
    }
  }

  void XuanZhe(int (&a)[100]) {
    int min = 0;
    int temp;
    int min_locate;
    for (int i = 0; i < 100; i++) {
      min_locate = i;
      for (int j = i + 1; j < 100; j++) {
        if (a[j] < a[min_locate]) {
          min_locate = j;
        }
      }
      if (min_locate != i) {
        temp = a[i]; // 交换元素
        a[i] = a[min_locate];
        a[min_locate] = temp;
      }
    }
  }
  void ChaRU(int (&a)[100]) {
    int temp = 0;
    for (int i = 0; i < 100; i++) {
      if (i == 0) {
        continue;
      }
      temp = a[i];
      if (a[i] < a[i - 1]) {
        for (int j = i - 1; j >= 0; j--) {
          if (a[j] > temp) {
            swap(a[j + 1], a[j]);
          }
        }
      }
    }
  }
  void quicksort(int a[], int first, int last) {
    if (first > last)
      return;
    int i = first, j = last, x = a[first];
    while (i < j) {
      // while (i < j && a[j] > x)
      //   j--;
      // if (i < j)
      //   a[i++] = a[j];
      // while (i < j && a[i] <= x)
      //   i++;
      // if (i < j)
      //   a[j--] = a[i];
      while (i < j && a[j] > x) {
        j--;
      }
      if (j > i) {
        swap(a[j], a[i]);
      }
      while (i < j && a[i] < x) {
        i++;
      }
      if (j > i) {
        swap(a[j], a[i]);
      }
    }
    a[i] = x;
    // a[i] = x;
    quicksort(a, first, i - 1);
    quicksort(a, i + 1, last);
  }

  void adjust(int arr[], int len, int index) {
    int left = 2*index + 1;
    int right = 2*index + 2;
    int maxIdx = index;
    if(left<len && arr[left] > arr[maxIdx]) maxIdx = left;
    if(right<len && arr[right] > arr[maxIdx]) maxIdx = right; 
    if(maxIdx != index)                 
    {
        swap(arr[maxIdx], arr[index]);
        adjust(arr, len, maxIdx);       
    }

  }
  void heap(int arr[], int size) {
   for(int i=size/2 - 1; i >= 0; i--)  
    {
        adjust(arr, size, i);
    }
    for(int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);          
        adjust(arr, i, 0);             
    }


  }
};
int main() {
  void *a;
  cout << sizeof a << endl;
  // 创建包含1到100的数组
  int arr[100];
  for (int i = 0; i < 100; ++i) {
    arr[i] = i + 1;
  }

  // 使用随机数引擎和洗牌算法打乱数组
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(arr, arr + 100, g);

  // 打印打乱后的数组
  std::cout << "打乱后的数组：" << std::endl;
  for (int i = 0; i < 100; ++i) {
    std::cout << arr[i] << " ";
    if ((i + 1) % 10 == 0) { // 每行打印10个数字
      std::cout << std::endl;
    }
  }
  cout << "-------------------" << endl;
  Soultion solu;
  // solu.quicksort(arr, 0, 99);
  solu.heap(arr, 100);
  std::cout << "排序后的数组：" << std::endl;
  for (int i = 0; i < 100; ++i) {
    std::cout << arr[i] << " ";
    if ((i + 1) % 10 == 0) { // 每行打印10个数字
      std::cout << std::endl;
    }
  }

  return 0;
}
