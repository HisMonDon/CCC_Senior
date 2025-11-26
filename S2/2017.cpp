#include <iostream>
#include <algorithm>
#include <string>
#include <array>
#include <vector>
#include <climits>
#include <map>
#include <sstream>
#include <cmath>
#include <unordered_map>
using namespace std;

int main() {
  int numOfWaves;
  cin>>numOfWaves;
  cin.ignore();
  string waves;
  vector<int> waveList;
  int wave;
  getline(cin, waves);
  stringstream ss(waves);
  while(ss >> wave){
    waveList.push_back(wave);
  }
  sort(waveList.begin(), waveList.end());
  vector<int> l(waveList.begin(), waveList.begin() + ceil(numOfWaves/2.0));
  vector<int> h(waveList.begin() + ceil(numOfWaves/2.0), waveList.end());
  reverse(l.begin(),l.end());
  for(int x = 0; x < h.size(); x++){
    cout<<l[x]<<" "<<h[x]<<" ";
  }
  if(l.size() > h.size()){
    cout<<l.back();
  }
}
