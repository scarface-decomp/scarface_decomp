// bin: pc
// va: 0x006E77C0
// tool: the portal's starter code (no AI)
// core::Win32Drive::vfunc_02 (0x006E77C0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 12 bytes to the start of the object and jumps to the real function at
// 0x006E78B0. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (12 bytes).

namespace core {
class Win32Drive_Base0 { public: virtual void sub_006E78B0(); char m_pad04[0x8]; };
class Win32Drive_Base1 { public: virtual void sub_006E78B0(); };

class Win32Drive : public Win32Drive_Base0, public Win32Drive_Base1
{
public:
    Win32Drive();
    virtual void sub_006E78B0();          // the real function; the thunk jumps here
};

Win32Drive::Win32Drive() {}                  // building one is what makes the compiler write its tables and the thunk
}
