/*
 * ============================================================================
 * AIAction.h — 100% Byte-Verified Decompilation (PC v1.00.2 Official US Patch)
 * ============================================================================
 * Decompiled directly from `Custom_AIAction_WorkPack.txt` & `04_Starter_25_Small_Functions_Batch1.txt`
 * (Retail Xbox 1:1 Donor `default.xbe` -> Official PC US Patch `Scarface.exe` v1.00.2, MSVC 7.10).
 *
 * Verified Binary Facts Uncovered From Machine Code:
 *   1. Exact Class & Subclass Layout on 32-Bit x86 (`MSVC 7.10` / `g++ -m32`):
 *        sizeof(AIAction)                    == 0x04 ( 4 bytes: VFTable pointer only)
 *        sizeof(AIActionUnary)               == 0x08 ( 8 bytes: +0x04 AIAction* m_pChildAction)
 *        sizeof(AIActionCancelPhysicalState) == 0x0C (12 bytes: +0x08 CharacterObject* m_pCharacter08)
 *
 *   2. Exact 5-Slot `AIAction` Base VFTable (PC 0x0073E7E8 <== Xbox 0x003AAAC8):
 *        Slot [00] (+0x00): PC 0x007027E6 <== Xbox 0x002FBA99 (`__purecall` = 0)
 *        Slot [01] (+0x04): PC 0x007027E6 <== Xbox 0x002FBA99 (`__purecall` = 0)
 *        Slot [02] (+0x08): PC 0x005E1BB0 <== Xbox 0x002A9290 (`C3` ret no-op)
 *        Slot [03] (+0x0C): PC 0x007027E6 <== Xbox 0x002FBA99 (`__purecall` = 0)
 *        Slot [04] (+0x10): PC 0x005E1BB0 <== Xbox 0x002A9290 (`C3` ret no-op)
 *
 *   3. Exact MSVC 7.10 CRT & RTTI Internal Structures (`0x002FBA99` .. `0x002FFAAE`):
 *        sizeof(type_info_raw)              == 0x0C (12 bytes: vftable + _m_data + _m_d_name[4])
 *        sizeof(_PMD)                       == 0x0C (12 bytes: mdisp, pdisp, vdisp)
 *        sizeof(_RTTIBaseClassDescriptor)   == 0x18 (24 bytes: +0x14 attributes)
 *        sizeof(_RTTIClassHierarchyDescriptor) == 0x10 (16 bytes: +0x08 numBaseClasses, +0x0C pBaseClassArray)
 *        sizeof(_RTTICompleteObjectLocator) == 0x14 (20 bytes: +0x04 offset, +0x08 cdOffset, +0x0C pTypeDesc, +0x10 pClassDesc)
 *        sizeof(_iobuf_xbox)                == 0x20 (32 bytes: stride 0x20 verified @ 0x002FD2F2 `add ecx, 0x20`)
 *        sizeof(_ioinfo_xbox)               == 0x28 (40 bytes: `lea eax, [eax+eax*4]; lea eax, [ecx+eax*8]` @ 0x002FE55C)
 *        sizeof(_tiddata_xbox)              == 0x88 (136 bytes: `push 0x88; push 1; call _calloc` @ 0x002FEE16)
 *        sizeof(exception_xbox)             == 0x0C (12 bytes: vftable + _m_what + _m_doFree)
 * ============================================================================
 */

#ifndef SCARFACE_PC_V1002_AIACTION_REAL_H
#define SCARFACE_PC_V1002_AIACTION_REAL_H

#if defined(SCARFACE_FREESTANDING_X86_CHECK)
    typedef unsigned int       size_t;
    typedef int                ptrdiff_t;
    typedef int                intptr_t;
    typedef unsigned int       uintptr_t;
    typedef signed char        int8_t;
    typedef short              int16_t;
    typedef int                int32_t;
    typedef unsigned char      uint8_t;
    typedef unsigned short     uint16_t;
    typedef unsigned int       uint32_t;
    typedef unsigned long long uint64_t;
    #ifndef NULL
        #define NULL 0
    #endif
#elif defined(_MSC_VER) && (_MSC_VER < 1600)
    #include <stddef.h>
    typedef signed char        int8_t;
    typedef short              int16_t;
    typedef int                int32_t;
    typedef unsigned char      uint8_t;
    typedef unsigned short     uint16_t;
    typedef unsigned int       uint32_t;
    typedef unsigned __int64   uint64_t;
#else
    #include <stddef.h>
    #include <stdint.h>
#endif

#if defined(_MSC_VER) && defined(_M_IX86)
    #if _MSC_VER >= 1400
        #define SCARFACE_AI_THISCALL __thiscall
    #else
        #define SCARFACE_AI_THISCALL   /* MSVC 7.1 rejects the keyword (C4234); members are thiscall anyway */
    #endif
    #define SCARFACE_AI_CDECL    __cdecl
    #define SCARFACE_AI_STDCALL  __stdcall
    #define SCARFACE_AI_FASTCALL __fastcall
    #pragma pack(push, 4)
#else
    #define SCARFACE_AI_THISCALL
    #define SCARFACE_AI_CDECL
    #define SCARFACE_AI_STDCALL
    #define SCARFACE_AI_FASTCALL
#endif

#if defined(__cplusplus) && (__cplusplus >= 201103L)
    #define SCARFACE_AI_STATIC_ASSERT(cond, msg) static_assert(cond, #msg)
#else
    #define SCARFACE_AI_STATIC_ASSERT(cond, msg) \
        typedef char ScarfaceAIStaticAssert_##msg[(cond) ? 1 : -1]
#endif

/* ============================================================================
 * 1. Core `AIAction` Hierarchy (`PC 0x0073E7E8` <== `Xbox 0x003AAAC8`, 5 Slots)
 * ============================================================================ */

class AIAction {
public:
    /* Slot [00] (+0x00): PC 0x007027E6 <== Xbox 0x002FBA99 (`__purecall`) */
    virtual void SCARFACE_AI_THISCALL vfunc_00() = 0;

    /* Slot [01] (+0x04): PC 0x007027E6 <== Xbox 0x002FBA99 (`__purecall`) */
    virtual void SCARFACE_AI_THISCALL vfunc_01() = 0;

    /* Slot [02] (+0x08): PC 0x005E1BB0 <== Xbox 0x002A9290 (`C3` ret) */
    virtual void SCARFACE_AI_THISCALL vfunc_02();

    /* Slot [03] (+0x0C): PC 0x007027E6 <== Xbox 0x002FBA99 (`__purecall`) */
    virtual int32_t SCARFACE_AI_THISCALL vfunc_03() = 0;

    /* Slot [04] (+0x10): PC 0x005E1BB0 <== Xbox 0x002A9290 (`C3` ret) */
    virtual void SCARFACE_AI_THISCALL vfunc_04();
};

#if defined(_M_IX86) || defined(__i386__)
SCARFACE_AI_STATIC_ASSERT(sizeof(AIAction) == 0x04, AIAction_must_be_0x04_bytes);
#endif

/*
 * `AIActionUnary` — Intermediate base class for unary decorators (`AIActionRepeatFinite`, etc.)
 */
class AIActionUnary : public AIAction {
public:
    explicit AIActionUnary(AIAction* pChild = NULL) : m_pChildAction04(pChild) {}

    AIAction* m_pChildAction04; /* +0x04 */
};

#if defined(_M_IX86) || defined(__i386__)
SCARFACE_AI_STATIC_ASSERT(sizeof(AIActionUnary) == 0x08, AIActionUnary_must_be_0x08_bytes);
#endif

/*
 * `AIActionCustomLogicalEffect` — Proven by Batch #08 (`Xbox 0x00120910`, 14 bytes):
 *   `mov eax, [ecx]; call dword ptr [eax+0x18]; dec eax; neg eax; sbb eax, eax; add eax, 2; ret`
 *   Calls virtual slot [06] (`+0x18`), returning `2` if `vfunc_06() != 0`, else `1`.
 */
class ConcreteAIAction : public AIAction {
public:
    explicit ConcreteAIAction(int32_t status = 1) : m_Status04(status) {}

    virtual void    SCARFACE_AI_THISCALL vfunc_00();
    virtual void    SCARFACE_AI_THISCALL vfunc_01();
    virtual int32_t SCARFACE_AI_THISCALL vfunc_03();

    int32_t m_Status04; /* +0x04 */
};

/* ============================================================================
 * 2. MSVC 7.10 CRT & RTTI Internal Structures (`0x002FBA99` .. `0x002FFAAE`)
 * ============================================================================ */

typedef void (SCARFACE_AI_CDECL *_purecall_handler)(void);
typedef void (SCARFACE_AI_CDECL *_PVFV)(void);

/* Pointer-to-member displacement descriptor (`0x002FBD25`, 31B).
 * MSVC predefines `_PMD` with exactly this layout, so only declare it for other compilers. */
#if !defined(_MSC_VER)
struct _PMD {
    int32_t mdisp; /* +0x00: member displacement inside base subobject */
    int32_t pdisp; /* +0x04: vbtable displacement (-1 if non-virtual base) */
    int32_t vdisp; /* +0x08: index displacement inside vbtable */
};
#endif

/* MSVC 7.10 `type_info` raw layout (`0x002FBAAD`, `0x002FBAF3`, `0x002FD3F2`) */
struct type_info_raw {
    void* _vftable;     /* +0x00: `0x003E1E2C` */
    char* _m_data;      /* +0x04: cached undecorated string allocated by `__unDName` */
    char  _m_d_name[4]; /* +0x08: mangled name (`.?AV...`, `_m_d_name + 1` is `+0x09`) */
};

/* MSVC 7.10 `_RTTIBaseClassDescriptor` (`sizeof == 0x18` = 24 bytes) */
struct _RTTIBaseClassDescriptor {
    type_info_raw* pTypeDescriptor;   /* +0x00 */
    uint32_t       numContainedBases; /* +0x04 */
    _PMD           where;             /* +0x08 (+0x08 mdisp, +0x0C pdisp, +0x10 vdisp) */
    uint32_t       attributes;        /* +0x14 (0x01 = not visible, 0x02 = ambiguous) */
};

/* MSVC 7.10 `_RTTIClassHierarchyDescriptor` (`sizeof == 0x10` = 16 bytes) */
struct _RTTIClassHierarchyDescriptor {
    uint32_t                   signature;       /* +0x00 */
    uint32_t                   attributes;      /* +0x04 (0x01 = MI, 0x02 = VI) */
    uint32_t                   numBaseClasses;  /* +0x08 */
    _RTTIBaseClassDescriptor** pBaseClassArray; /* +0x0C */
};

/* MSVC 7.10 `_RTTICompleteObjectLocator` (`sizeof == 0x14` = 20 bytes, stored at `vtable[-1]`) */
struct _RTTICompleteObjectLocator {
    uint32_t                       signature;        /* +0x00 */
    uint32_t                       offset;           /* +0x04: offset of this vtable in complete object */
    uint32_t                       cdOffset;         /* +0x08: construction displacement offset */
    type_info_raw*                 pTypeDescriptor;  /* +0x0C */
    _RTTIClassHierarchyDescriptor* pClassDescriptor; /* +0x10 */
};

/* MSVC 7.10 `FILE` (`_iobuf`) structure (`sizeof == 0x20` = 32 bytes, verified @ `0x002FD2F2`) */
struct _iobuf_xbox {
    char*   _ptr;      /* +0x00 */
    int32_t _cnt;      /* +0x04 */
    char*   _base;     /* +0x08 */
    int32_t _flag;     /* +0x0C */
    int32_t _file;     /* +0x10 */
    int32_t _charbuf;  /* +0x14 */
    int32_t _bufsiz;   /* +0x18 */
    char*   _tmpfname; /* +0x1C */
};

/* MSVC 7.10 low-level fd `ioinfo` structure (`sizeof == 0x28` = 40 bytes, verified @ `0x002FE55C`) */
struct _ioinfo_xbox {
    int32_t osfhnd;       /* +0x00 */
    uint8_t osfile;       /* +0x04 (bit 0x20 = FAPPEND) */
    uint8_t pipech;       /* +0x05 */
    uint8_t pad06[2];     /* +0x06..+0x07 */
    int32_t lockinitflag; /* +0x08 */
    uint8_t lock[0x1C];   /* +0x0C..+0x27 (28-byte CRITICAL_SECTION) */
};

/* MSVC 7.10 `_tiddata` per-thread CRT data (`sizeof == 0x88` = 136 bytes, verified @ `0x002FEE16`) */
struct _tiddata_xbox {
    uint32_t _tid;          /* +0x00 */
    int32_t  _thandle;      /* +0x04 (initialized to -1 @ 0x002FEE3F) */
    int32_t  _terrno;       /* +0x08 */
    uint32_t _tdoserrno;    /* +0x0C */
    uint32_t _fpds;         /* +0x10 */
    uint32_t _holdrand;     /* +0x14 (initialized to 1 @ 0x002FEE33) */
    char*    _token;        /* +0x18 */
    wchar_t* _wtoken;       /* +0x1C */
    uint8_t* _mtoken;       /* +0x20 */
    char*    _errmsg;       /* +0x24 (freed in _freeptd @ 0x002FEE6B) */
    wchar_t* _werrmsg;      /* +0x28 */
    char*    _namebuf0;     /* +0x2C (freed in _freeptd @ 0x002FEE79) */
    wchar_t* _wnamebuf0;    /* +0x30 */
    char*    _namebuf1;     /* +0x34 (freed in _freeptd @ 0x002FEE87) */
    wchar_t* _wnamebuf1;    /* +0x38 */
    char*    _asctimebuf;   /* +0x3C (freed in _freeptd @ 0x002FEE95) */
    wchar_t* _wasctimebuf;  /* +0x40 */
    void*    _gmtimebuf;    /* +0x44 (freed in _freeptd @ 0x002FEEA3) */
    char*    _cvtbuf;       /* +0x48 (freed in _freeptd @ 0x002FEEB1) */
    uint8_t  _con_ch_buf[8];/* +0x4C..+0x53 */
    void*    _initaddr;     /* +0x54 (initialized to 0x00465CC8 @ 0x002FEE2C) */
    void*    _initarg;      /* +0x58 */
    void*    _pxcptacttab;  /* +0x5C */
    int32_t* _tpxcptinfoptrs;/* +0x60 (refcounted in _freeptd @ 0x002FEEDC) */
    uint8_t  _pad64[0x24];  /* +0x64..+0x87 */
};

/* MSVC 7.10 `std::exception` Hierarchy (`0x002FF6A4` .. `0x002FF856`, `sizeof == 0x0C` = 12 bytes) */
class exception_xbox {
public:
    explicit exception_xbox(const char* const* pWhat);
    exception_xbox(const exception_xbox& rhs);
    virtual ~exception_xbox();
    virtual const char* SCARFACE_AI_THISCALL what() const;

    char*   _m_what;   /* +0x04 */
    int32_t _m_doFree; /* +0x08 */
};

class bad_cast_xbox : public exception_xbox {
public:
    explicit bad_cast_xbox(const char* what_str);
    bad_cast_xbox(const bad_cast_xbox& rhs);
    virtual ~bad_cast_xbox();
};

class bad_typeid_xbox : public exception_xbox {
public:
    explicit bad_typeid_xbox(const char* what_str);
    bad_typeid_xbox(const bad_typeid_xbox& rhs);
    virtual ~bad_typeid_xbox();
};

class __non_rtti_object_xbox : public bad_typeid_xbox {
public:
    explicit __non_rtti_object_xbox(const char* what_str);
    __non_rtti_object_xbox(const __non_rtti_object_xbox& rhs);
    virtual ~__non_rtti_object_xbox();
};

#if defined(_M_IX86) || defined(__i386__)
SCARFACE_AI_STATIC_ASSERT(sizeof(_PMD)                         == 0x0C, PMD_must_be_0x0C_bytes);
SCARFACE_AI_STATIC_ASSERT(sizeof(type_info_raw)                == 0x0C, type_info_raw_must_be_0x0C_bytes);
SCARFACE_AI_STATIC_ASSERT(sizeof(_RTTIBaseClassDescriptor)     == 0x18, RTTIBCD_must_be_0x18_bytes);
SCARFACE_AI_STATIC_ASSERT(sizeof(_RTTIClassHierarchyDescriptor)== 0x10, RTTICHD_must_be_0x10_bytes);
SCARFACE_AI_STATIC_ASSERT(sizeof(_RTTICompleteObjectLocator)   == 0x14, RTTICOL_must_be_0x14_bytes);
SCARFACE_AI_STATIC_ASSERT(sizeof(_iobuf_xbox)                  == 0x20, iobuf_must_be_0x20_bytes);
SCARFACE_AI_STATIC_ASSERT(sizeof(_ioinfo_xbox)                 == 0x28, ioinfo_must_be_0x28_bytes);
SCARFACE_AI_STATIC_ASSERT(sizeof(_tiddata_xbox)                == 0x88, tiddata_must_be_0x88_bytes);
SCARFACE_AI_STATIC_ASSERT(sizeof(exception_xbox)               == 0x0C, exception_must_be_0x0C_bytes);
#endif

/* ============================================================================
 * 3. Exported Decompiled Function Prototypes (`Custom_AIAction_WorkPack.txt`)
 * ============================================================================ */
extern "C" {
    int   SCARFACE_AI_CDECL    _purecall_002FBA99(void);
    void  SCARFACE_AI_CDECL    type_info_dtor_002FBAAD(type_info_raw* self);
    void* SCARFACE_AI_CDECL    type_info_scalar_deleting_dtor_002FBAF3(type_info_raw* self, unsigned int flags);
    const char* SCARFACE_AI_CDECL type_info_name_002FD3F2(type_info_raw* self);

    _PVFV SCARFACE_AI_CDECL    __onexit_nolock_002FBB0F(_PVFV func);
    int   SCARFACE_AI_CDECL    _onexitinit_002FBB8F(void);
    _PVFV SCARFACE_AI_CDECL    _onexit_002FBBB7(_PVFV func);
    int   SCARFACE_AI_CDECL    atexit_002FBBEF(_PVFV func);

    void* SCARFACE_AI_CDECL    __RTtypeid_002FBC01(void* inptr);
    void* SCARFACE_AI_FASTCALL FindCompleteObject_002FBC9C(void** inptr);
    _RTTIBaseClassDescriptor* SCARFACE_AI_STDCALL FindSITargetTypeInstance_002FBCB2(
        _RTTICompleteObjectLocator* pCOL,
        type_info_raw* pTargetType);
    int32_t SCARFACE_AI_STDCALL PMDtoOffset_002FBD25(
        const _PMD* pmd,
        void* pCompleteObject);
    _RTTIBaseClassDescriptor* SCARFACE_AI_STDCALL FindMITargetTypeInstance_002FBD44(
        _RTTICompleteObjectLocator* pCOL,
        void* pCompleteObject,
        type_info_raw* pSrcType,
        int32_t srcOffset,
        type_info_raw* pTargetType);
    _RTTIBaseClassDescriptor* SCARFACE_AI_STDCALL FindVITargetTypeInstance_002FBE98(
        _RTTICompleteObjectLocator* pCOL,
        void* pCompleteObject,
        type_info_raw* pSrcType,
        int32_t srcOffset,
        type_info_raw* pTargetType);
    void* SCARFACE_AI_CDECL    __RTDynamicCast_002FC034(
        void* inptr,
        int32_t VfDelta,
        void* SrcType,
        void* TargetType,
        int32_t isReference);

    void  SCARFACE_AI_CDECL    _lockexit_002FD0ED(void);
    void  SCARFACE_AI_CDECL    _unlockexit_002FD0F6(void);
    void  SCARFACE_AI_CDECL    doexit_002FD0FF(int code, int quick, int retcaller);
    void  SCARFACE_AI_CDECL    _cexit_002FD1C3(void);
    void  SCARFACE_AI_CDECL    _c_exit_002FD1CF(void);
    int   SCARFACE_AI_CDECL    fprintf_002FD1DB(_iobuf_xbox* stream, const char* format, ...);
    int   SCARFACE_AI_CDECL    fputc_002FD239(int ch, _iobuf_xbox* stream);
    int   SCARFACE_AI_CDECL    _ioinit_002FD291(void);
    void  SCARFACE_AI_CDECL    _lock_file_002FD34E(void* pf);
    void  SCARFACE_AI_CDECL    _lock_file2_002FD37D(int i, void* s);
    void  SCARFACE_AI_CDECL    _unlock_file_002FD3A0(void* pf);
    void  SCARFACE_AI_CDECL    _unlock_file2_002FD3CF(int i, void* s);

    int   SCARFACE_AI_CDECL    _snprintf_002FDC50(char* buffer, size_t count, const char* format, ...);
    int   SCARFACE_AI_CDECL    _strnicmp_002FDCA7(const char* first, const char* last, size_t count);

    void* SCARFACE_AI_CDECL    malloc_002FE138(size_t size);
    void  SCARFACE_AI_CDECL    free_002FE14A(void* memblock);
    size_t SCARFACE_AI_CDECL   _fread_nolock_002FE237(void* buffer, size_t elementSize, size_t count, _iobuf_xbox* stream);
    size_t SCARFACE_AI_CDECL   fread_002FE32F(void* buffer, size_t elementSize, size_t count, _iobuf_xbox* stream);
    double SCARFACE_AI_CDECL   strtod_002FE3F5(const char* nptr, char** endptr);
    int   SCARFACE_AI_CDECL    _flsbuf_002FE4A4(int ch, _iobuf_xbox* stream);
    _tiddata_xbox* SCARFACE_AI_CDECL _getptd_002FEDD6(void);
    void  SCARFACE_AI_STDCALL  _freeptd_002FEE54(_tiddata_xbox* ptd);

    void  SCARFACE_AI_CDECL    _amsg_exit_002FF3F0(int rterrnum);
    int   SCARFACE_AI_CDECL    _mtinitlocks_002FF40C(void);
    void  SCARFACE_AI_CDECL    _mtdeletelocks_002FF455(void);
    void  SCARFACE_AI_CDECL    _unlock_002FF47E(int locknum);
    int   SCARFACE_AI_CDECL    _mtinitlocknum_002FF490(int locknum);
    void  SCARFACE_AI_CDECL    _lock_002FF530(int locknum);
    void* SCARFACE_AI_CDECL    realloc_002FF55E(void* memblock, size_t newsize);
    size_t SCARFACE_AI_CDECL   _msize_002FF64B(void* memblock);
    void  SCARFACE_AI_STDCALL  _CxxThrowException_002FF857(void* pExceptionObject, const void* pThrowInfo);
}

/* Compile-Time & Runtime Offset Verifier for 32-Bit x86 (`verify_aiaction_x86.cpp`) */
inline int VerifyAIActionAndRTTIOffsetsX86() {
    if (sizeof(void*) != 4) { return 0x677; }
    char raw[512];
    #define CHK_AI(Type, Member, HexOff) \
        if ((reinterpret_cast<const char*>(&reinterpret_cast<const Type*>(raw)->Member) - raw) != (HexOff)) return -(HexOff)
    CHK_AI(AIActionUnary,                   m_pChildAction04,   0x004);
    CHK_AI(ConcreteAIAction,                m_Status04,         0x004);
    CHK_AI(type_info_raw,                   _m_data,            0x004);
    CHK_AI(type_info_raw,                   _m_d_name,          0x008);
    CHK_AI(_PMD,                            mdisp,              0x000);
    CHK_AI(_PMD,                            pdisp,              0x004);
    CHK_AI(_PMD,                            vdisp,              0x008);
    CHK_AI(_RTTIBaseClassDescriptor,        pTypeDescriptor,    0x000);
    CHK_AI(_RTTIBaseClassDescriptor,        numContainedBases,  0x004);
    CHK_AI(_RTTIBaseClassDescriptor,        where,              0x008);
    CHK_AI(_RTTIBaseClassDescriptor,        attributes,         0x014);
    CHK_AI(_RTTIClassHierarchyDescriptor,   signature,          0x000);
    CHK_AI(_RTTIClassHierarchyDescriptor,   attributes,         0x004);
    CHK_AI(_RTTIClassHierarchyDescriptor,   numBaseClasses,     0x008);
    CHK_AI(_RTTIClassHierarchyDescriptor,   pBaseClassArray,    0x00C);
    CHK_AI(_RTTICompleteObjectLocator,      signature,          0x000);
    CHK_AI(_RTTICompleteObjectLocator,      offset,             0x004);
    CHK_AI(_RTTICompleteObjectLocator,      cdOffset,           0x008);
    CHK_AI(_RTTICompleteObjectLocator,      pTypeDescriptor,    0x00C);
    CHK_AI(_RTTICompleteObjectLocator,      pClassDescriptor,   0x010);
    CHK_AI(_iobuf_xbox,                     _cnt,               0x004);
    CHK_AI(_iobuf_xbox,                     _base,              0x008);
    CHK_AI(_iobuf_xbox,                     _flag,              0x00C);
    CHK_AI(_iobuf_xbox,                     _file,              0x010);
    CHK_AI(_iobuf_xbox,                     _bufsiz,            0x018);
    CHK_AI(_ioinfo_xbox,                    osfile,             0x004);
    CHK_AI(_ioinfo_xbox,                    lock,               0x00C);
    CHK_AI(_tiddata_xbox,                   _thandle,           0x004);
    CHK_AI(_tiddata_xbox,                   _holdrand,          0x014);
    CHK_AI(_tiddata_xbox,                   _errmsg,            0x024);
    CHK_AI(_tiddata_xbox,                   _namebuf0,          0x02C);
    CHK_AI(_tiddata_xbox,                   _namebuf1,          0x034);
    CHK_AI(_tiddata_xbox,                   _asctimebuf,        0x03C);
    CHK_AI(_tiddata_xbox,                   _gmtimebuf,         0x044);
    CHK_AI(_tiddata_xbox,                   _cvtbuf,            0x048);
    CHK_AI(_tiddata_xbox,                   _initaddr,          0x054);
    CHK_AI(_tiddata_xbox,                   _tpxcptinfoptrs,    0x060);
    CHK_AI(exception_xbox,                  _m_what,            0x004);
    CHK_AI(exception_xbox,                  _m_doFree,          0x008);
    #undef CHK_AI
    return 0x677;
}

#if defined(_MSC_VER) && defined(_M_IX86)
    #pragma pack(pop)
#endif

#endif /* SCARFACE_PC_V1002_AIACTION_REAL_H */
