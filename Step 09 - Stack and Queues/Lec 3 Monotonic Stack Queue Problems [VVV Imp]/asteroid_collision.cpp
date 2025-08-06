// https://www.naukri.com/code360/problems/asteroid-collision_10870970
// https://www.geeksforgeeks.org/problems/asteroid-collision/1
// https://leetcode.com/problems/asteroid-collision/description/
// https://www.youtube.com/watch?v=_eYGqw_VDR4

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    vector<int> ans;
    for (int i=0; i<n; i++) {
        if (asteroids[i] > 0) ans.push_back(asteroids[i]);
        else {
            while (!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i]))
                ans.pop_back();
            if (!ans.empty() && ans.back() == abs(asteroids[i]))
                ans.pop_back();
            else if (ans.empty() || ans.back() < 0)
                ans.push_back(asteroids[i]);
        }
    }
    return ans;
}
// Above fails when arr[i] == 0

vector<int> collidingAsteroids(vector<int> &asteroids) {
    int n = asteroids.size();
    vector<int> ans;
    
    for (int i = 0; i < n; i++) {
        int curr = asteroids[i];
        bool destroyed = false;
        
        while (!ans.empty() && curr < 0 && ans.back() > 0) {
            if (abs(curr) > ans.back()) {
                ans.pop_back();
                continue;
            } else if (abs(curr) == ans.back()) {
                ans.pop_back();
            }
            destroyed = true;
            break;
        }

        // Only push if not destroyed
        if (!destroyed) {
            // Only push massless (0) if not destroyed
            if (curr != 0 || (ans.empty() || ans.back() <= 0))
                ans.push_back(curr);
        }
    }
    return ans;
}
