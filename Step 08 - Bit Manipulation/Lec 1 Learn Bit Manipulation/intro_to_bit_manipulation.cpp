// https://www.naukri.com/code360/problems/bit-manipulation_8142533
// https://www.geeksforgeeks.org/problems/bit-manipulation-1666686020/1
// https://www.youtube.com/watch?v=qQd-ViW7bfk

vector<int> bitManipulation(int num, int i){
    vector<int> res(3);
    // if indexing is 1-based -> i-1
    res[0] = ((num & (1 << i-1)) == 0) ? 0 : 1;
    res[1] = num | (1 << i-1);
    res[2] = num & ~(1 << i-1);
    return res;
}