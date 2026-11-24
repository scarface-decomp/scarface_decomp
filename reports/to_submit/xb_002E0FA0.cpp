// bin: xb
// va: 0x002E0FA0
// what: Passes this object to sub_002D4B90 on the global object DAT_004C0518.
// tool: Gemini 4 Neon

struct GlobalObj_004C0518
{
    void sub_002D4B90(void* arg);
};

extern "C" GlobalObj_004C0518 DAT_004C0518;

class Class_002E0FA0
{
public:
    void sub_002E0FA0();
};

void Class_002E0FA0::sub_002E0FA0()
{
    DAT_004C0518.sub_002D4B90(this);
}
