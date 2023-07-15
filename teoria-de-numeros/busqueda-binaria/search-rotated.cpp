// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int searchRotated(vector<int> &nums, int target){
  int left=0;
  int right=nums.size()-1;
  int mitad;
  while (left<=right){
    mitad=left+(right-left)/2;
    if (nums[mitad]==target){
      return mitad;
    }
    if (nums[mitad]>= nums[left]){
      if (target>=nums[left] && target<nums[mitad]){
        right=mitad-1;
      }else{
        left=mitad+1;
      }
    }else{
      if (target<=nums[right] && target<nums[mitad]){
        left=mitad+1;
      }else{
        right=mitad-1;
      }
    }
  }
  return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<int> nums(n, 0);
    int target;
    for (int i=0;i<n;i++){
      cin>>nums[i];
    }
    cin>>target;
    cout<<searchRotated(nums, target);
    return 0;
}





