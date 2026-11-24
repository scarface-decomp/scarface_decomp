// bin: xb
// va: 0x001EAEB0
// what: Sets the script field pathGroup of VehicleSpawnObject (the accessor its field table registers).
// how: shape
// tool: the portal's starter code (no AI)

// sub_001EAEB0 (0x001EAEB0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001EAD60(int);
};

int __cdecl sub_001EAEB0(int a1, int a2)
{
    int r_eax;

    r_eax = a2;
    if (a2) {
        if (!*(unsigned char*)r_eax) goto L_17;
        r_eax = ((Object*)a1)->sub_001EAD60(a2);
    }
L_17:
    return r_eax;
}
