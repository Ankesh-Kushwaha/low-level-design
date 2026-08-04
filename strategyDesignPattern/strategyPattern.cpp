#include<bits/stdc++.h>
using namespace std;
//the primary goal of a strategy pattern is to define a set of algorithms, encapsulate them in their classes and make them   interchangeable within the context objects.through this encapsulation the statrategy pattern promotes the open/close principle.

//create a common interface 
class SortingStrategy{
  public:
   virtual void sort(vector<int> &arr) = 0;
};

//implement the concrete strategies 
class bubble_sort:public SortingStrategy{
  public:
  void sort(vector<int> &arr) override{
    int n = arr.size();
    // complexity is O(n^2);
    for (int i = 0; i < n;i++){
      for (int j = 0; j < n - i - 1;j++){
           if(arr[j]>arr[j+1]){
             swap(arr[j], arr[j + 1]);
           }
      }
    }
  }
};

class selection_sort:public SortingStrategy{
  public:
  void sort(vector<int> &arr) override{
    // complexity = O(n^2);
    int n = arr.size();
    for (int i = 0; i < n-1;i++){
      int idx = i;

      for (int j = i + 1; j < n;j++){
           if(arr[idx]>arr[j]){
             idx = j;
           }
      }
      swap(arr[i], arr[idx]);
    }
  }
};

class insertion_sort:public SortingStrategy{
  public:
    // cmplexity:-> Best case O(n), worst case O(n^2) , average case O(n^2);
    void sort(vector<int> &arr) override
    {
      int n = arr.size();
      for (int i = 0; i < n;i++){
        int key = arr[i];
        int j = i - 1;

        while(j>=0 && arr[j]>key){
          arr[j + 1] = arr[j];
          j = j - 1;
        }

        arr[j + 1] = key;
      }
    }
};

class quick_sort:public SortingStrategy{
  public:
    int partition_helper(vector<int> &arr, int low, int high)
    {
      int pivot = arr[high];

      int i = low - 1;

      for (int j = low; j < high; j++)
      {
        if (arr[j] < pivot)
        {
          i++;
          swap(arr[i], arr[j]);
        }
      }

      swap(arr[i + 1], arr[high]);

      return i + 1;
    }

  void sortHelper(vector<int> &arr,int start,int end){
     if(start<end){
       int pIdx = partition_helper(arr, start, end);
       sortHelper(arr,0,pIdx-1);
       sortHelper(arr,pIdx+1,end);
     }
  }

  void sort(vector<int> &arr) override{
    sortHelper(arr, 0, arr.size() - 1);
  }
};

class merge_sort:public SortingStrategy{
  public:
  void sort(vector<int> &arr) override{
     
  }
};

class heap_sort:public SortingStrategy{
  public:
  void sort(vector<int> &arr) override{
     
  }
};

class counting_sort:public SortingStrategy{
  public:
  void sort(vector<int> &arr)override{
    
  }
};

//creating the context class 
class Sorter{
  SortingStrategy *strategy;
  public:
  Sorter(SortingStrategy* strategy){
    this->strategy = strategy;
  }

  void sort(vector<int> &arr){
    this->strategy->sort(arr);
  }
};

void print(vector<int> &nums){
   for(auto n:nums)
     cout << n << " ";
   cout << endl;
}

int main(){
  //client interaction
  vector<int> nums;
  for (int i = 100; i >= 0;i--){
    nums.push_back(i);
  }
    Sorter *st1 = new Sorter(new quick_sort());
  st1->sort(nums);
  print(nums);

  return 0;
}