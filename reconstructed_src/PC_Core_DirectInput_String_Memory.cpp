extern "C" {
    __declspec(dllimport) void* __cdecl malloc(unsigned int size);
    __declspec(dllimport) void  __cdecl free(void* ptr);
    __declspec(dllimport) char* __cdecl _strupr(char* str);
    __declspec(dllimport) char* __cdecl _strlwr(char* str);
    __declspec(dllimport) int   __stdcall IsDebuggerPresent(void);
    __declspec(dllimport) void  __stdcall DebugBreak(void);
}

namespace core {

extern void* g_pCoreMemoryPool; // 0x007F5A70
void __cdecl FreeToCorePool(void* pool, void* ptr);

// 1. core::ControllerInputPointDirectInput::vfunc_01 (PC VA 0x006DDC60, 23 B)
class RefCountedSub04 {
public:
    virtual ~RefCountedSub04();
    int m_Pad04;
    int m_RefCount08;
};

class ControllerInputPointDirectInput {
public:
    virtual void vfunc_00();
    RefCountedSub04 m_Sub04;
    virtual void vfunc_01(); // PC VA 0x006DDC60 (23 B)
};

void ControllerInputPointDirectInput::vfunc_01() {
    RefCountedSub04* p = &m_Sub04;
    if (--p->m_RefCount08 == 0) {
        p->m_RefCount08 = 1500;
        delete p;
    }
}

// 2. core::ControllerSystemDirectInput (PC-Exclusive DirectInput System)
struct ControllerDeviceNode {
    virtual void vfunc_00(); virtual void vfunc_01(); virtual void vfunc_02(); virtual void vfunc_03();
    virtual void vfunc_04(); virtual void vfunc_05(); virtual void vfunc_06(); virtual void vfunc_07();
    virtual void vfunc_08(); virtual void vfunc_09(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
    virtual void OnSystemNotify(int a, int b); // slot 19 (+0x4C)
    char                  pad[0x27C];
    ControllerDeviceNode* m_pNext280;          // +0x280
};

class ControllerSystemDirectInput {
public:
    char                  pad04[0x14];
    int                   m_SystemContext18; // +0x18
    int                   m_Field1C;         // +0x1C
    void*                 m_pActiveDevice20; // +0x20
    int                   m_Field24;         // +0x24
    ControllerDeviceNode* m_pDeviceList28;   // +0x28

    static void operator delete(void* ptr) {
        FreeToCorePool(g_pCoreMemoryPool, ptr);
    }

    ~ControllerSystemDirectInput();
    virtual void                  vfunc_00();
    virtual void                  vfunc_01();
    virtual void                  vfunc_02();
    virtual void*                 vfunc_03(unsigned int flags);     // PC VA 0x006DE690 (36 B)
    virtual void                  vfunc_04();
    virtual ControllerDeviceNode* vfunc_05(unsigned int index);     // PC VA 0x006DE650 (38 B)
    virtual void                  vfunc_09(int arg);                // PC VA 0x006DE620 (44 B)
    virtual void                  vfunc_12(void* pDev);             // PC VA 0x006DE590 (19 B)
};

void* ControllerSystemDirectInput::vfunc_03(unsigned int flags) {
    this->~ControllerSystemDirectInput();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

ControllerDeviceNode* ControllerSystemDirectInput::vfunc_05(unsigned int index) {
    unsigned int i = 0;
    ControllerDeviceNode* cur = m_pDeviceList28;
    if (cur != 0) {
        do {
            if (i == index) {
                return cur;
            }
            cur = cur->m_pNext280;
            ++i;
        } while (cur != 0);
    }
    return 0;
}

void ControllerSystemDirectInput::vfunc_09(int arg) {
    ControllerDeviceNode* cur = m_pDeviceList28;
    if (cur != 0) {
        do {
            cur->OnSystemNotify(arg, m_SystemContext18);
            cur = cur->m_pNext280;
        } while (cur != 0);
    }
}

void ControllerSystemDirectInput::vfunc_12(void* pDev) {
    if (m_pActiveDevice20 == pDev) {
        m_pActiveDevice20 = 0;
    }
}

// 3. core::ControllerDirectInput (PC-Exclusive DirectInput Gamepad/Device)
struct InputPointNode174 {
    char               pad[0x174];
    InputPointNode174* m_pNext174; // +0x174
};

struct OutputPointNode19C {
    char                pad[0x19C];
    OutputPointNode19C* m_pNext19C; // +0x19C
};

struct IDirectInputDevice8A {
    virtual void __stdcall QueryInterface();
    virtual void __stdcall AddRef();
    virtual void __stdcall Release();
    virtual void __stdcall GetCapabilities();
    virtual void __stdcall EnumObjects();
    virtual int  __stdcall GetProperty(void* pProp); // +0x14
};

struct IControllerSubObj27C {
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual const char* GetDeviceName(); // +0x20
};

extern const char g_EmptyControllerName[];

class ControllerDirectInput {
public:
    char                  pad[0x258];
    IDirectInputDevice8A* m_pDIDevice25C;  // +0x25C
    int                   m_Field260;      // +0x260
    InputPointNode174*    m_pInputList264; // +0x264
    int                   m_Field268;      // +0x268
    int                   m_Field26C;      // +0x26C
    OutputPointNode19C*   m_pOutputList270;// +0x270
    int                   m_Field274;      // +0x274
    int                   m_Field278;      // +0x278
    IControllerSubObj27C* m_pSubObj27C;    // +0x27C

    ~ControllerDirectInput();
    virtual void*               vfunc_03(unsigned int flags); // PC VA 0x006DE1D0 (36 B)
    virtual const char*         vfunc_07();                   // PC VA 0x006DE000 (21 B)
    virtual InputPointNode174*  vfunc_12(unsigned int index); // PC VA 0x006DDF60 (38 B)
    virtual OutputPointNode19C* vfunc_17(unsigned int index); // PC VA 0x006DDFA0 (38 B)
};

void* ControllerDirectInput::vfunc_03(unsigned int flags) {
    this->~ControllerDirectInput();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

const char* ControllerDirectInput::vfunc_07() {
    IControllerSubObj27C* pSub = m_pSubObj27C;
    if (pSub != 0) {
        return pSub->GetDeviceName();
    }
    return g_EmptyControllerName;
}

InputPointNode174* ControllerDirectInput::vfunc_12(unsigned int index) {
    unsigned int i = 0;
    InputPointNode174* cur = m_pInputList264;
    if (cur != 0) {
        do {
            if (i == index) {
                return cur;
            }
            cur = cur->m_pNext174;
            ++i;
        } while (cur != 0);
    }
    return 0;
}

OutputPointNode19C* ControllerDirectInput::vfunc_17(unsigned int index) {
    unsigned int i = 0;
    OutputPointNode19C* cur = m_pOutputList270;
    if (cur != 0) {
        do {
            if (i == index) {
                return cur;
            }
            cur = cur->m_pNext19C;
            ++i;
        } while (cur != 0);
    }
    return 0;
}

// 4. core::Platform::vfunc_04 (PC VA 0x006DF4C0, 24 B)
class Platform {
public:
    int m_Field04; // +0x04
    virtual void vfunc_04(); // PC VA 0x006DF4C0 (24 B)
};

void Platform::vfunc_04() {
    if (m_Field04 == 0 && IsDebuggerPresent() == 0) {
        DebugBreak();
    }
}

// 5. core::MemoryAllocatorMalloc
void* __cdecl AlignedAllocHelper(unsigned int a, unsigned int b);

class MemoryAllocatorMalloc {
public:
    virtual void* vfunc_04(unsigned int size);                // PC VA 0x006DF730 (26 B)
    virtual void  vfunc_05(void* ptr);                        // PC VA 0x006DF750 (15 B)
    virtual void* vfunc_07(unsigned int a, unsigned int b);   // PC VA 0x006DF760 (21 B)
    virtual void  vfunc_08(void* ptr);                        // PC VA 0x006DF7C0 (22 B)
};

void* MemoryAllocatorMalloc::vfunc_04(unsigned int size) {
    if (size == 0) {
        size = 1;
    }
    return malloc(size);
}

void MemoryAllocatorMalloc::vfunc_05(void* ptr) {
    free(ptr);
}

void* MemoryAllocatorMalloc::vfunc_07(unsigned int a, unsigned int b) {
    return AlignedAllocHelper(a, b);
}

void MemoryAllocatorMalloc::vfunc_08(void* ptr) {
    if (ptr) {
        free(*((void**)ptr - 1));
    }
}

// 6. core::MemoryDlAllocator & core::MemorySmallDlAllocator
class MemoryDlAllocator {
public:
    char          pad[0x0C];
    unsigned int  m_StartAddr10; // +0x10
    unsigned int  m_EndAddr14;   // +0x14
    ~MemoryDlAllocator();
    virtual void* vfunc_03(unsigned int flags);      // PC VA 0x006E0A60 (36 B)
    virtual bool  vfunc_06(unsigned int ptr);        // PC VA 0x006E09E0 (28 B)
};

void* MemoryDlAllocator::vfunc_03(unsigned int flags) {
    this->~MemoryDlAllocator();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

bool MemoryDlAllocator::vfunc_06(unsigned int ptr) {
    if ((ptr >= m_StartAddr10 && ptr < m_EndAddr14) || ptr == 0) {
        return true;
    }
    return false;
}

class MemorySmallDlAllocator {
public:
    ~MemorySmallDlAllocator();
    virtual void* vfunc_03(unsigned int flags);      // PC VA 0x006E1D40 (36 B)
};

void* MemorySmallDlAllocator::vfunc_03(unsigned int flags) {
    this->~MemorySmallDlAllocator();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

// 7. core::String
int __cdecl StringCompareHelper(char* buf, const char* other);
extern const char g_TrueStringLiteral[];  // 0x0073BB10
extern const char g_FalseStringLiteral[]; // 0x007352C0

class String {
public:
    char          pad[0x0C];
    char*         m_pBuffer10; // +0x10
    unsigned int  m_Flags14;   // +0x14

    unsigned char GetHighBit() const { return (unsigned char)(m_Flags14 >> 31); }

    ~String();
    virtual void  vfunc_00(); virtual void vfunc_01(); virtual void vfunc_02();
    virtual void* vfunc_03(unsigned int flags);      // PC VA 0x006E0540 (36 B)
    virtual bool  vfunc_04(String* other);           // PC VA 0x006E0090 (36 B)
    virtual bool  vfunc_05(const char* str);         // slot 5 (+0x14)
    virtual void  vfunc_06(String* other);           // PC VA 0x006E01E0 (34 B)
    virtual void  vfunc_07(const char* str);         // slot 7 (+0x1C)
    virtual const char* vfunc_08();                  // PC VA 0x006E0250 (17 B)
    virtual void  vfunc_09(); virtual void vfunc_10();
    virtual void  vfunc_11(bool bVal);               // PC VA 0x006E0490 (26 B)
    virtual void  vfunc_12(); virtual void vfunc_13();
    virtual void  vfunc_14(char ch);                 // PC VA 0x006E0430 (26 B)
    virtual void  vfunc_15(); virtual void vfunc_16();
    virtual void  vfunc_17(const char* str);         // slot 17 (+0x44)
    virtual void  vfunc_18();
    virtual void  vfunc_19();                        // PC VA 0x006E04B0 (22 B)
    virtual void  vfunc_20();                        // PC VA 0x006E04D0 (22 B)
    virtual bool  vfunc_21(String* other);           // PC VA 0x006E0510 (36 B)
    virtual int   vfunc_22(const char* other);       // PC VA 0x006E04F0 (20 B)
};

void* String::vfunc_03(unsigned int flags) {
    this->~String();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

bool String::vfunc_04(String* other) {
    if (other != 0) {
        return vfunc_05(other->vfunc_08());
    }
    return false;
}

void String::vfunc_06(String* other) {
    if (other != 0 && other != this) {
        vfunc_07(other->vfunc_08());
    }
}

const char* String::vfunc_08() {
    if (GetHighBit() & 1) {
        return 0;
    }
    return m_pBuffer10;
}

void String::vfunc_11(bool bVal) {
    vfunc_17(bVal ? g_TrueStringLiteral : g_FalseStringLiteral);
}

void String::vfunc_14(char ch) {
    char buf[2];
    buf[0] = ch;
    buf[1] = 0;
    vfunc_17(buf);
}

void String::vfunc_19() {
    if (!(GetHighBit() & 1)) {
        _strlwr(m_pBuffer10);
    }
}

void String::vfunc_20() {
    if (!(GetHighBit() & 1)) {
        _strupr(m_pBuffer10);
    }
}

bool String::vfunc_21(String* other) {
    if (other != 0) {
        return vfunc_22(other->vfunc_08());
    }
    return false;
}

int String::vfunc_22(const char* other) {
    return StringCompareHelper(m_pBuffer10, other);   // the game returns the helper's result as is
}

// 8. core::CompletionEventRequest & core::FileCompletionRequest
void __cdecl SetCompletionEvent(void* hEvent);

class CompletionEventRequest {
public:
    char  pad[0x04];
    void* m_hEvent08; // +0x08
    virtual int vfunc_01(); // PC VA 0x006E36A0 (18 B)
};

int CompletionEventRequest::vfunc_01() {
    SetCompletionEvent(m_hEvent08);
    return 1;
}

struct FileSubObj0C {
    void OnRequestCompleted(void* req);
};

class FileCompletionRequest {
public:
    char  pad[0x08];
    struct Holder0C {
        char pad[0x0C];
        FileSubObj0C* m_pSub0C;
    }* m_pHolder0C;
    virtual int vfunc_01(); // PC VA 0x006E3700 (18 B)
};

int FileCompletionRequest::vfunc_01() {
    m_pHolder0C->m_pSub0C->OnRequestCompleted(this);
    return 3;
}

} // namespace core
