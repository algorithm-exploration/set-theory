void GeneratePowerSet(vector<int> s) {
    int start=0;
    vector<int> subset;
    start=pow(2,s.size())-1; //gives s.size() length bitmask
    for(int i=start; i>0; i--) {
        for(int j=0; j<s.size(); j++) {
            if(i & (1<<j)) {
                cout << s[j] << ' ';
                subset.push_back(s[j]); // In the future, we could make this a class and
                // have a function that returns the next powerset incrementally much like the
                // next_permutation function in stl.
            }
        }
        cout << endl;
        subset.clear();
    } 
}
