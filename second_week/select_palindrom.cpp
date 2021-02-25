bool IsPalindrom(string str) {
	for(int i = 0; i < str.size() / 2; ++i) {
		if(str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}
	return true;
}
vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> palindrom;

	for(auto w : words) {
		if(w.size() >= minLength && IsPalindrom(w)) {
			palindrom.push_back(w);
			}
		}
	return palindrom;
}