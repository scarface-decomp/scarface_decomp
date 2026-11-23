// bin: xb
// va: 0x00317740
// what: 
// tool: the portal's starter code (no AI)

// sub_00317740 (0x00317740, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048A160;
extern "C" int DAT_0048A164;
extern "C" int DAT_0048A168;
extern "C" int DAT_0048A178;
extern "C" int DAT_0048A17C;
extern "C" int DAT_0048A180;

int __cdecl sub_00317740(void)
{
    int t1, t2, t3;

    t1 = DAT_0048A168;
    t2 = DAT_0048A164;
    t3 = DAT_0048A160;
    DAT_0048A178 = DAT_0048A168;
    DAT_0048A17C = t2;
    DAT_0048A180 = t3;
    return t1;
}
