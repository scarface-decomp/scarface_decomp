// bin: xb
// va: 0x001B68C0
// what: Steps back to the object this one is part of and calls one of its functions with 0.
// tool: Claude Fable 5.2 (look-alike of 0x001B2250, names and addresses swapped)
// PimpYourMansionHUD::vfunc_00 (0x001B68C0, 11 bytes)
struct Object
{
    void sub_001B6010(int);
};

class PimpYourMansionHUD
{
public:
    virtual void vfunc_00();
};

void PimpYourMansionHUD::vfunc_00()
{
    ((Object*)(int)this + -104)->sub_001B6010(0);
}
