/*Minimum product subset of an array
              Using STL            
*/



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
	vector<int> v ,v2,v3;
	int n;
	ll mult1 = 1;
	cin >> n;
	int cnt = 0, c0=0;
	while (n--) {
		int t;
		cin >> t;
		if (t < 0) { // counting number of -ves
			cnt++;
			v2.push_back(t); // storing them for further use
		}
		else if (t>0) {
			v3.push_back(t); // storing positive numbers
			mult1 *= t; // and thier mult
		}
		if(t == 0) {
			c0++; // counting zeors
		}
		v.push_back(t); // storing the original array
	}


	/*Checking the posiblities in the 
	given array and evaluating
	by using those 
	conditions 
	:-)
	*/
	if (cnt % 2 != 0 and c0 == 0) {
		ll mult = 1;
		for (auto x : v) {
			mult *= x;
		}
		cout << mult;return 0;
	}
	else if (cnt % 2 != 0 and c0 != 0) {
		ll mult = 1;
		for (auto x : v) {
			if (x == 0) {
				continue;
			}
			else {
				mult *= x;
			}
			
		}
		cout << mult << endl;return 0;
	}
	else if (cnt == 0 ) {
		ll mult = *min_element(v.begin(), v.end());
		cout << mult << endl;
		return 0;
	}
	else if ((cnt % 2 == 0 and c0 == 0 ) or (cnt % 2 == 0 and c0 != 0)) {
		ll mult = 1;
		for (ll i = 1;i < cnt;i++) {
			ll val = *min_element(v2.begin(), v2.end());
			mult *= val;
			v2.erase(std::remove(v2.begin(), v2.end(), val), v2.end());
		}
		mult *= mult1;
		cout << mult;
		return 0;
	}
	
	return 0;
}
