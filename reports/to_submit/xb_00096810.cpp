// bin: xb
// va: 0x00096810
// what: Calls a function of the object held in a global pointer, passing it a global value.
// tool: Claude Opus 5.5 (symcov hint: $E13, link-order)
// sub_00096810 (0x00096810, 19 bytes)

class Class_00094E30
{
public:
    void sub_00094E30(int a1);
};

extern "C" int DAT_004236AC;
extern "C" Class_00094E30 *__cdecl sub_00094C80();

// Hands the global value to the global object's method.
void __cdecl sub_00096810()
{
    sub_00094C80()->sub_00094E30(DAT_004236AC);
}
