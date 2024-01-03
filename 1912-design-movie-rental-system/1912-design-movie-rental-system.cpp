class MovieRentingSystem {
public:
    map<int, set<pair<int, int>>> mp; // movie-{rent, shop}
    map<int, map<int, int>> ma; // {movie, shop - val}
    map<int, set<pair<int, int>>> rentedMovies;
    
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto& e : entries) {
            int shop = e[0];
            int movie = e[1];
            int price = e[2];
            
            mp[movie].insert({price, shop});
            ma[movie][shop] = price;
        }    
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        for(auto& it : mp[movie]) {
            ans.push_back(it.second);
            
            if(ans.size() == 5) {
                break;
            }
        }
        
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = ma[movie][shop];
        mp[movie].erase({price, shop});
        
        rentedMovies[price].insert({shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = ma[movie][shop];
        mp[movie].insert({price, shop});
        
        rentedMovies[price].erase({shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        
        for(auto& it : rentedMovies) {
            for(auto& [shop, movie] : it.second) {
                ans.push_back({shop, movie});
                
                if(ans.size() == 5) {
                    return ans;
                }
            }
        }
        
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */