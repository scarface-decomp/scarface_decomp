// bin: xb
// va: 0x00263EE0
// what: Stores a value in the global at 0x0045C328.
// tool: Claude Opus 5.5 (generated from the shape 'set int global (framed)', checked on decomp.me preset 266 by example)
#pragma optimize("y", off)

extern "C" int DAT_0045C328;

void __stdcall sub_00263EE0(int value)
{
    DAT_0045C328 = value;
}
