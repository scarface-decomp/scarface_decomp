// bin: proto
// va: 0x00013420
// what: 
// tool: the portal's starter code (no AI)

// sub_00013420 (Proto 0x00013420, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00441458[];
extern "C" int __cdecl sub_00013330(int);
extern "C" int __cdecl sub_00028120(int);

void __cdecl sub_00013420(int a1)
{
    int t1;

    t1 = sub_00013330(a1);
    if (t1 >= 0) {
        *(bool*)(sub_00028120(DAT_00441458[t1]) + 132) = true;
    }
}
