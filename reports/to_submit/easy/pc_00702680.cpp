// bin: pc
// va: 0x00702680
// tool: the portal's starter code (no AI)
// movie::BinkCallback::vfunc_03 (0x00702680, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 8 bytes to the start of the object and jumps to the real function at
// 0x00702690. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (8 bytes).

namespace movie {
class BinkCallback_Base0 { public: virtual void sub_00702690(); char m_pad04[0x4]; };
class BinkCallback_Base1 { public: virtual void sub_00702690(); };

class BinkCallback : public BinkCallback_Base0, public BinkCallback_Base1
{
public:
    BinkCallback();
    virtual void sub_00702690();          // the real function; the thunk jumps here
};

BinkCallback::BinkCallback() {}                  // building one is what makes the compiler write its tables and the thunk
}
