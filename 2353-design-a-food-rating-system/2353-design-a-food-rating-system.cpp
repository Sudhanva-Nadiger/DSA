struct cmp {
  bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
      if(a.first == b.first) {
            return a.second > b.second;
        }    
        
      return a.first < b.first;
  }
};

class FoodRatings {
public:
    
    map<string, set<pair<int, string>, cmp> > mp; // cusine to rating
    map<string, int> mapp;
    map<string, string> ma;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        
        for(int i = 0; i < n; i++) {
            mp[cuisines[i]].insert({ratings[i], foods[i]});
            mapp[foods[i]] = ratings[i];
            ma[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int prevRating = mapp[food];
        string cuisine = ma[food];
        
        mapp[food] = newRating;

        mp[cuisine].erase({prevRating, food});
        mp[cuisine].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].rbegin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */