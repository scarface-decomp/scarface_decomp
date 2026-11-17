// bin: proto
// va: 0x0019DD40
// tool: the portal's starter code (no AI)
// sub_0019DD40 (0x0019DD40, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0008D4E0(int);
    bool sub_00148450();
};

extern "C" Object DAT_00460668;
extern "C" int DAT_0046066C;
extern "C" Object DAT_00462DD4;
extern "C" int DAT_00462DD8;

void __cdecl sub_0019DD40(void)
{
    int r_esi, t3;

    r_esi = DAT_00460668.sub_0008D4E0(DAT_0046066C);
    if (!r_esi) goto L_5B;
    t3 = DAT_00462DD4.sub_0008D4E0(DAT_00462DD8);
    if (t3) {
        if (!((Object*)t3)->sub_00148450()) goto L_4A;
        if (*(bool*)(r_esi + 136)) goto L_5B;
        *(bool*)(r_esi + 136) = true;
        return;
    }
L_4A:
    if (*(bool*)(r_esi + 136)) {
        *(bool*)(r_esi + 136) = false;
    }
L_5B:
    ;
}
