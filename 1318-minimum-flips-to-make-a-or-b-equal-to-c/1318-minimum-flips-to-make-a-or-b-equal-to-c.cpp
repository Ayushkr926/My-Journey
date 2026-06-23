class Solution {
public:
    int minFlips(int a, int b, int c) {
    return popcount(0ul + (c ^= a | b) << 32 | a & b & c);
}
};