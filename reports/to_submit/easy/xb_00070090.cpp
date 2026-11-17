// bin: xb
// va: 0x00070090
// tool: the portal's starter code (no AI)
// sub_00070090 (0x00070090, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0006FF50(int);
extern "C" bool __cdecl sub_00099BC0(int);

bool __cdecl sub_00070090(int a1, bool a2)
{
    int t1;

    t1 = sub_0006FF50(a1);
    if (*(bool*)t1) {
        return sub_00099BC0(t1);
    }
    return a2;
}
