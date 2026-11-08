extern "C" {
    __declspec(dllimport) int __stdcall CloseHandle(void* hObject);
}
void __cdecl operator delete(void* ptr);

namespace core {

extern void* g_pCoreMemoryPool; // 0x007F5A70
void  __cdecl FreeToCorePool(void* pool, void* ptr);
void* __cdecl ResolveDescA(void* p);
void* __cdecl ResolveDescB(void* p);

struct ILockObject {
    virtual void Lock();   // +0x00
    virtual void Unlock(); // +0x04
    int m_RefCount04;      // +0x04
    // Inlined into Drive::vfunc_00 and CementLibrary::AddRefLocked10. Working through the
    // lock's own `this` keeps it in esi; /G7 turns ++ into add [esi+4],1 as in the game.
    void AddRefLocked() { Lock(); ++m_RefCount04; Unlock(); }
};

struct IDriveParent0C {
    virtual void vfunc_00(); virtual void vfunc_01(); virtual void vfunc_02(); virtual void vfunc_03();
    virtual void vfunc_04(); virtual void vfunc_05(); virtual void vfunc_06(); virtual void vfunc_07();
    virtual unsigned char GetDriveFlags08(); // +0x20
};

// 1. Fix File::vfunc_25 (PC VA 0x006E5160, 24 B) -> positive `flags & 0x80` check emits `79 04` (`jns`)!
class FileFix {
public:
    char            pad[0x08];
    IDriveParent0C* m_pDrive0C;          // +0x0C
    char            pad10[0x0E];         // +0x10..0x1D
    char            m_InlineName1E[258]; // +0x1E
    virtual char* vfunc_25();            // PC VA 0x006E5160 (24 B)
};

char* FileFix::vfunc_25() {
    // test al,al / jns: the name is returned when bit 7 is CLEAR.
    if (m_pDrive0C->GetDriveFlags08() & 0x80) {
        return 0;
    }
    return m_InlineName1E;
}

// 2. InstanceDrive additions (vfunc_18, vfunc_22, vfunc_46)
struct ICompletionArg {
    void OnExecute();
};

class InstanceDriveExt {
public:
    ILockObject m_Lock04;         // +0x04 (size 8: vftable +0x04, refcount +0x08)
    int         m_Field0C;        // +0x0C
    int         m_Field10;        // +0x10
    int         m_PendingCount14; // +0x14

    virtual void vfunc_00(); virtual void vfunc_01(); virtual void vfunc_02(); virtual void vfunc_03();
    virtual void vfunc_04(); virtual void vfunc_05(); virtual void vfunc_06(); virtual void vfunc_07();
    virtual void vfunc_08(); virtual void vfunc_09(); virtual void vfunc_10();
    virtual void vfunc_11(int a);                // +0x2C
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17();
    virtual void vfunc_18(int a);                // PC VA 0x006E5960 (26 B)
    virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21();
    virtual bool vfunc_22();                     // PC VA 0x006E5A70 (35 B)
    virtual void vfunc_23();                     // +0x5C (WaitForDriveCompletion)
    virtual void vfunc_46(ICompletionArg* pArg); // PC VA 0x006E5E50 (12 B)
};

void InstanceDriveExt::vfunc_18(int a) {
    vfunc_11(a);
    vfunc_23();
}

bool InstanceDriveExt::vfunc_22() {
    m_Lock04.Lock();
    bool bEmpty = (m_PendingCount14 == 0);
    m_Lock04.Unlock();
    return bEmpty;
}

void InstanceDriveExt::vfunc_46(ICompletionArg* pArg) {
    pArg->OnExecute();
}

// 3. core::Drive::AddRefLocked (PC VA 0x006E6070, 23 B)
class Drive {
public:
    char        pad[0x08];
    ILockObject m_Lock0C; // +0x0C
    virtual void vfunc_00(); // PC VA 0x006E6070 (23 B)
};

void Drive::vfunc_00() {
    m_Lock0C.AddRefLocked();
}

// 4. core::CementLibrary (PC VAs 0x006E6710..0x006E6B50)
struct ICementSub04 {
    virtual void* vfunc_00(); // +0x00
    virtual void* vfunc_01(); // +0x04
};

struct CementOwner0C {
    int          m_Pad00;
    ICementSub04 m_Sub04; // +0x04
};

struct ICementCallback {
    virtual void OnCementCallback(); // +0x00
};

void __cdecl YieldCementThread(int ms);
void __cdecl PollCementState(); // a free function: the game calls it without setting ecx

class CementLibrary {
public:
    char             pad04[0x08];
    CementOwner0C*   m_pOwner0C;    // +0x0C
    ILockObject      m_Lock10;      // +0x10 (vftable +0x10, m_RefCount +0x14)
    int              m_Field18;     // +0x18
    int              m_Field1C;     // +0x1C
    int              m_State20;     // +0x20
    char             pad24[0x48];   // +0x24..0x6B
    ICementCallback* m_pCallback6C; // +0x6C
    int              m_Context70;   // +0x70


    virtual void* vfunc_00();                                    // PC VA 0x006E6710 (11 B)
    virtual void* vfunc_01();                                    // PC VA 0x006E6720 (12 B)
    virtual void  vfunc_05();                                    // PC VA 0x006E6730 (39 B)
    virtual void  vfunc_06(ICementCallback* cb, int context);    // PC VA 0x006E6770 (23 B)
    virtual bool  vfunc_07();                                    // PC VA 0x006E6760 (10 B)
    void          AddRefLocked10();                              // PC VA 0x006E6B50 (23 B)
};

void* CementLibrary::vfunc_00() {
    return m_pOwner0C->m_Sub04.vfunc_00();
}

void* CementLibrary::vfunc_01() {
    return m_pOwner0C->m_Sub04.vfunc_01();
}

void CementLibrary::vfunc_05() {
    while (m_State20 == 0) {
        PollCementState();
        YieldCementThread(0);
    }
}

void CementLibrary::vfunc_06(ICementCallback* cb, int context) {
    m_pCallback6C = cb;
    m_Context70   = context;
    cb->OnCementCallback();
}

bool CementLibrary::vfunc_07() {
    return m_State20 == 1;
}

void CementLibrary::AddRefLocked10() {
    m_Lock10.AddRefLocked();
}

// 5. core::Win32Drive (PC-Only Win32 File System Drive — PC VAs 0x006E7480..0x006E78B0)
class Win32Drive {
public:
    char m_Pad04[0xDC];
    char m_DriveInfoE0[12]; // +0xE0
    int  m_DescEC;          // +0xEC

    ~Win32Drive();
    virtual void  vfunc_00();                     // PC VA 0x006E7480 (14 B)
    virtual void  vfunc_01();                     // PC VA 0x006E7490 (14 B)
    virtual char* vfunc_02();                     // PC VA 0x006E74A0 (7 B)
    virtual void* vfunc_03(unsigned int flags);   // PC VA 0x006E78B0 (36 B)
    virtual int   vfunc_22(void** pHandle);       // PC VA 0x006E74D0 (29 B)
};

void Win32Drive::vfunc_00() {
    ResolveDescA(&m_DescEC);
}

void Win32Drive::vfunc_01() {
    ResolveDescB(&m_DescEC);
}

char* Win32Drive::vfunc_02() {
    return m_DriveInfoE0;
}

void* Win32Drive::vfunc_03(unsigned int flags) {
    this->~Win32Drive();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

int Win32Drive::vfunc_22(void** pHandle) {
    CloseHandle(*pHandle);
    *pHandle = (void*)-1;
    return 1;
}

// 6. core::DriveThread (PC VAs 0x006E7EB0..0x006E8610)
class DriveThread {
public:
    int   m_Field04; // +0x04
    void* m_pDesc08; // +0x08

    ~DriveThread();
    virtual void  vfunc_00();                   // PC VA 0x006E7EB0 (11 B)
    virtual void  vfunc_01();                   // PC VA 0x006E7EC0 (11 B)
    virtual void* vfunc_03(unsigned int flags); // PC VA 0x006E8610 (36 B)
};

// These two return nothing: "return ResolveDescA(...)" makes cl clean the stack with
// add esp,4 (13 B), while a void function gets pop ecx (11 B), which is what the game has.
void DriveThread::vfunc_00() {
    ResolveDescA(m_pDesc08);
}

void DriveThread::vfunc_01() {
    ResolveDescB(m_pDesc08);
}

void* DriveThread::vfunc_03(unsigned int flags) {
    this->~DriveThread();
    if (flags & 1) {
        FreeToCorePool(g_pCoreMemoryPool, this);
    }
    return this;
}

} // namespace core

// 7. NISStreamDataLoader::vfunc_04 (PC VA 0x006E9E70, 27 B)
class NISStreamDataLoader {
public:
    char pad[0x0C];
    int  m_Field10; // +0x10
    virtual void vfunc_00(); virtual void vfunc_01(); virtual void vfunc_02(); virtual void vfunc_03();
    virtual void vfunc_04(int a, int b, int c, int d, int e); // PC VA 0x006E9E70 (27 B)
    virtual void vfunc_05();
    virtual void vfunc_06(int a, int b, int f10, int e);      // +0x18
};

void NISStreamDataLoader::vfunc_04(int a, int b, int c, int d, int e) {
    vfunc_06(a, b, m_Field10, e);
}

// 8. content::Stats::vfunc_00 (PC VA 0x006E9E90, 32 B)
namespace content {
class Stats {
public:
    virtual ~Stats(); // PC VA 0x006E9E90 (32 B)
};
Stats::~Stats() {
}
} // namespace content

// 9. audio::OmHalStream (PC VAs 0x006EBDF0..0x006EC020)
namespace audio {
int __cdecl InitAudioSub0C(void* pSub);

struct AudioSlot16 {
    int a, b, c, d;
};

class OmHalStream {
public:
    int         m_Field04;        // +0x04
    int         m_TotalBytes08;   // +0x08
    char        m_Sub0C[0xAC];    // +0x0C..0xB7
    AudioSlot16 m_SlotsB8[16];    // +0xB8..0x1B7
    int         m_PendingBytes1B8;// +0x1B8
    int         m_Field1BC;       // +0x1BC
    struct Sub1C0 {
        void ResetSub1C0();
    } m_Sub1C0;                   // +0x1C0

    virtual int         vfunc_03();               // PC VA 0x006EC020 (13 B)
    virtual bool        vfunc_08(int* pOutBytes); // PC VA 0x006EBFA0 (36 B)
    virtual AudioSlot16* vfunc_09(int index);     // PC VA 0x006EBFD0 (17 B)
    virtual void        vfunc_10();               // PC VA 0x006EBDF0 (11 B)
};

int OmHalStream::vfunc_03() {
    return InitAudioSub0C(m_Sub0C);   // add esp,4 (not pop ecx) because the result is returned
}

bool OmHalStream::vfunc_08(int* pOutBytes) {
    *pOutBytes = m_PendingBytes1B8;
    m_TotalBytes08 -= m_PendingBytes1B8;
    m_PendingBytes1B8 = 0;
    return true;
}

AudioSlot16* OmHalStream::vfunc_09(int index) {
    return &m_SlotsB8[index];
}

void OmHalStream::vfunc_10() {
    m_Sub1C0.ResetSub1C0();
}

} // namespace audio
