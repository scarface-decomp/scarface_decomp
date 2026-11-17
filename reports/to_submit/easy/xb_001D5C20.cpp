// bin: xb
// va: 0x001D5C20
// tool: the portal's starter code (no AI)
// sub_001D5C20 (0x001D5C20, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00098BB0(int);
    bool sub_00164880();
};

extern "C" int DAT_0048A9D8;
extern "C" Object DAT_0048F188;
extern "C" int DAT_0048F18C;

void __cdecl sub_001D5C20(void)
{
    int r_esi;

    r_esi = DAT_0048F188.sub_00098BB0(DAT_0048F18C);
    if (!r_esi) goto L_4E;
    if (DAT_0048A9D8) {
        if (!((Object*)DAT_0048A9D8)->sub_00164880()) goto L_3D;
        if (*(bool*)(r_esi + 132)) goto L_4E;
        *(bool*)(r_esi + 132) = true;
        return;
    }
L_3D:
    if (*(bool*)(r_esi + 132)) {
        *(bool*)(r_esi + 132) = false;
    }
L_4E:
    ;
}
