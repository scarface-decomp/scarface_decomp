// bin: pc
// va: 0x006E82D0
// tool: the portal's starter code (no AI)
// core::DriveThread::vfunc_02 (0x006E82D0, 8 bytes)
// An adjustor thunk. Nobody wrote this function: the compiler adds it for a class with two base
// classes that both declare the same virtual function. Called through the second base's table, it
// moves `this` back 12 bytes to the start of the object and jumps to the real function at
// 0x006E8610. So it is matched by declaring the class that way, not by writing a body.
// The two bases and their names are guesses; the first base is the part of the object in front
// of the second base (12 bytes).

namespace core {
class DriveThread_Base0 { public: virtual void sub_006E8610(); char m_pad04[0x8]; };
class DriveThread_Base1 { public: virtual void sub_006E8610(); };

class DriveThread : public DriveThread_Base0, public DriveThread_Base1
{
public:
    DriveThread();
    virtual void sub_006E8610();          // the real function; the thunk jumps here
};

DriveThread::DriveThread() {}                  // building one is what makes the compiler write its tables and the thunk
}
