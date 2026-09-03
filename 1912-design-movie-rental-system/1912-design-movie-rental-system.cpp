class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> availableMovies;
    unordered_map<int, unordered_map<int, int>> priceMap;
    set<array<int, 3>> rentedMovies;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];

            availableMovies[movie].insert({price, shop});
            priceMap[shop][movie] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> res;

        for (auto& [price, shop] : availableMovies[movie]) {
            if (res.size() == 5)
                break;

            res.push_back(shop);
        }

        return res;
    }

    void rent(int shop, int movie) {
        int price = priceMap[shop][movie];

        //delete from available movies
        availableMovies[movie].erase({price, shop});

        //insert into rented movies
        rentedMovies.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[shop][movie];

        //insert back to available movies
        availableMovies[movie].insert({price, shop});

        //remove rented movies
        rentedMovies.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;

        for (auto& [price, shop, movie] : rentedMovies) {
            if (res.size() == 5)
                break;

            res.push_back({shop, movie});
        }

        return res;
    }
};