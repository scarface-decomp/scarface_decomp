// bin: xb
// va: 0x00073550
// what: Calls virtual slot 0 on this object and passes its return value along with the argument to sub_00073500.
// tool: Gemini 4 Neon

extern "C" int __cdecl sub_00073500(int value, int arg);

class Class_00073550
{
public:
    virtual int vfunc_00();
    int sub_00073550(int arg);
};

int Class_00073550::sub_00073550(int arg)
{
    return sub_00073500(vfunc_00(), arg);
}
