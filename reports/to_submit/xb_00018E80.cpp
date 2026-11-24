// bin: xb
// va: 0x00018E80
// what: Returns 1 if the global object pointer DAT_0048A9D8 is non-null and equals this object, otherwise 0.
// tool: Gemini 4 Neon

extern "C" void* DAT_0048A9D8;

class Class_00018E80
{
public:
    int sub_00018E80();
};

int Class_00018E80::sub_00018E80()
{
    if (DAT_0048A9D8 && this == DAT_0048A9D8)
        return 1;
    return 0;
}
