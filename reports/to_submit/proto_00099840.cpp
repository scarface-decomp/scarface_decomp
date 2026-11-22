// bin: proto
// va: 0x00099840
// what: 
// tool: the portal's starter code (no AI)

// sub_00099840 (Proto 0x00099840, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;
extern "C" float DAT_0037CE50;
extern "C" float DAT_0037D4D0;

float __cdecl sub_00099840(float a1)
{
    if (a1 > DAT_0037D4D0) {
        return DAT_0037CE50;
    }
    return DAT_0037CD94;
}
