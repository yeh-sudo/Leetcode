#define vt vector
#define sz(a) a.size()
#define mp make_pair

class Solution {
public:
    
    void countSort(vt<pair<int, int>>& v, int exp){
	    vt<pair<int, int>> output(128);
	    int tmp[10];
	    memset(tmp, 0, sizeof(tmp));
	    for (int i = 0; i < sz(v); i++){
		    tmp[(v[i].first / exp) % 10]++;
	    }
	    for (int i = 1; i < 10; i++){
		    tmp[i] += tmp[i-1];
	    }
	    for (int i = sz(v)-1; i >= 0; i--){
		    output[tmp[(v[i].first / exp) % 10] - 1] = v[i];
		    tmp[(v[i].first / exp) % 10]--;
	    }
	    copy(output.begin(), output.end(), v.begin());
    }
    
    string frequencySort(string s) {
        string ret = "";
	    vt<pair<int, int>> ans(128);
	    for (int i = 0; i < sz(ans); i++){
		    ans[i] = mp(0, 127 - i);
	    }
	    for (int i = 0; i < s.length(); i++){
		    ans[127 - s[i]].first++;
	    }
	    for (int i = 1; i <= 100000; i *= 10){
		    countSort(ans, i);
	    }
	    for (int i = sz(ans)-1; i >= 0; i--){
		    while (ans[i].first--){
			    ret += (char)ans[i].second;
		    }
	    }
        return ret;
    }
};