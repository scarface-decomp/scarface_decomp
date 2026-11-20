// bin: xb
// va: 0x0029C290
// what: Stores two numbers in a pair of global settings.
// tool: Claude Opus 5.5 (symcov hint: RpTieSetFreeListCreateParams, link-order)
// sub_0029C290 (0x0029C290, 22 bytes)
// The unit keeps frame pointers (push ebp; mov ebp, esp).
#pragma optimize("y", off)

extern "C" int DAT_0045EAB4;
extern "C" int DAT_0045EAB8;

// Sets both globals.
void __cdecl sub_0029C290(int a1, int a2)
{
    DAT_0045EAB4 = a1;
    DAT_0045EAB8 = a2;
}
