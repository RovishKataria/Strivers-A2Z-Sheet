// https://www.naukri.com/code360/problems/set-the-rightmost-unset-bit_8160456
// https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1

int setBits(int N){
    if ((N & (N+1)) == 0) return N;
    return (N | (N+1));
}