// bin: xb
// va: 0x002BE6A0
// what: Stores two numbers in a pair of global settings.
// tool: Claude Opus 5.5 (symcov hint: RpSkinSetFreeListCreateParams, link-order)
// sub_002BE6A0 (0x002BE6A0, 22 bytes)
// The unit keeps frame pointers (push ebp; mov ebp, esp).
#pragma optimize("y", off)

extern "C" int DAT_00461A58;
extern "C" int DAT_00461A5C;

// Sets both globals.
void __cdecl sub_002BE6A0(int a1, int a2)
{
    DAT_00461A58 = a1;
    DAT_00461A5C = a2;
}
