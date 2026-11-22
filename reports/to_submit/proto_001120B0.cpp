// bin: proto
// va: 0x001120B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001120B0 (Proto 0x001120B0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045C1E8;
extern "C" int DAT_0045C1F0;
extern "C" float DAT_0045C1F4;

int __stdcall sub_001120B0(float a1)
{
    int t1;

    t1 = DAT_0045C1E8;
    *(int*)(((int)&DAT_0045C1F0) + (DAT_0045C1E8 * 8)) = 2;
    *(float*)(((int)&DAT_0045C1F4) + (t1 * 8)) = a1;
    DAT_0045C1E8 = t1 + 1;
    return t1 + 1;
}
