#include <stdio.h>
#include <stdint.h>
#include <climits>

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    register uint32_t ans = 0, i = 0, j = 31;
    do {
      ans |= ((n & (1 << i)) >> i) << j; ++i; --j;
    } while (i < 32);
    return ans;
  }
};

int main(void)
{
  Solution solution;

  solution.reverseBits(0x2941e9c);

  return 0;
}
