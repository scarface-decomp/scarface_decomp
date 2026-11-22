// bin: proto
// va: 0x0009AE40
// what: 
// tool: the portal's starter code (no AI)

// sub_0009AE40 (Proto 0x0009AE40, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_00393980;

class Class_0009AE40
{
public:
    float sub_0009AE40(int a1, int a2);
};

float Class_0009AE40::sub_0009AE40(int a1, int a2)
{
    unsigned char t1;

    t1 = *(unsigned char*)((a1 << 4) + a2 + a1 + (int)this + 360);
    a1 = *(unsigned char*)((a1 << 4) + a2 + a1 + (int)this + 360);
    return ((float)a1) * DAT_00393980;
}
