// bin: proto
// va: 0x001493B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001493B0 (Proto 0x001493B0, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_001BB0E0();
};

extern "C" int DAT_00462DD4;
extern "C" int __cdecl sub_001BB7D0(void);

class Class_001493B0
{
public:
    bool sub_001493B0();
};

bool Class_001493B0::sub_001493B0()
{
    int r_ecx;

    r_ecx = (int)this;
    if (*(int*)(r_ecx + 16) == DAT_00462DD4) {
        r_ecx = sub_001BB7D0();
        return ((Object*)r_ecx)->sub_001BB0E0();
    }
    return *(bool*)(r_ecx + 364);
}
