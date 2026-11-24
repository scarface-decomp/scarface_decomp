// bin: xb
// va: 0x0020C270
// what: Gets the script field coverProperties of WheeledVehicleTemplate (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_0020C270 (0x0020C270, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000CE360();
    int sub_00211990();
};

extern "C" char DAT_0039D520[];
extern "C" int __cdecl sub_0009A220(int);

int __cdecl sub_0020C270(int a1)
{
    int r_eax, r_esi;

    r_eax = ((Object*)a1)->sub_00211990();
    r_esi = r_eax;
    if (r_esi) {
        r_eax = ((Object*)r_esi)->sub_000CE360();
        if (r_eax) {
            if (*(unsigned char*)r_eax) goto L_33;
        }
        r_esi = *(int*)(r_esi + 16);
        r_eax = sub_0009A220(r_esi);
        return r_eax;
    }
    r_eax = (int)DAT_0039D520;
L_33:
    return r_eax;
}
