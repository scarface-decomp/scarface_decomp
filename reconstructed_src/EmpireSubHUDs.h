/*
 * ============================================================================
 * EmpireSubHUDs.h — 100% Byte-Verified Decompilation (PC v1.00.2 Official US Patch)
 * ============================================================================
 * Decompiled directly from `02_Business_DrugWars_Exotics_WorkPack.txt`
 * (Retail Xbox 1:1 Donor `default.xbe` -> Official PC US Patch `Scarface.exe` v1.00.2).
 *
 * Complete Coverage of All 13 Classes & Engine Helpers in Pack 02:
 *   1. BusinessHUD                          (sizeof == 0x84 = 132B | PC VFTable 0x007531C4)
 *   2. BusinessHUD::BusinessHUDMenuItem     (sizeof == 0x3C =  60B | PC VFTable 0x007502B8)
 *   3. BusinessHUD::BusinessHUDMenuItemData (sizeof == 0x14 =  20B | PC VFTable 0x00750300)
 *   4. BusinessHUD::HenchmenMenuItem        (sizeof == 0x50 =  80B | PC VFTable 0x007502D4)
 *   5. BusinessHUD::HenchmenItemData        (sizeof == 0x28 =  40B | PC VFTable 0x00750308)
 *   6. BusinessDetailHUD                    (sizeof == 0x6C = 108B | Xbox VFTable 0x003BA41C)
 *   7. DrugWarsHUD                          (sizeof == 0xC0 = 192B | PC VFTable 0x00753494)
 *   8. DrugWarsHUD::DrugWarsHUDFrontMenuItem(sizeof == 0x3C =  60B | PC VFTable 0x0074FF44)
 *   9. DrugWarsHUD::DrugWarsHUDTurfMenuItem (sizeof == 0x68 = 104B | PC VFTable 0x0074FF28)
 *  10. DrugWarsHUD::DrugWarsHUDMenuItemData (sizeof == 0x10 =  16B | PC VFTable 0x0074FF98)
 *  11. ExoticsHUD2                          (sizeof == 0xC4 = 196B | PC VFTable 0x0074CC14)
 *  12. ExoticsHUD2::ExoticsHUDMenuItem      (sizeof == 0x44 =  68B | PC VFTable 0x0074CD44)
 *  13. ExoticsHUD2::ExoticsHUDMenuItemData  (sizeof == 0x14 =  20B | PC VFTable 0x0074CD64)
 *
 * Architectural Discovery Proven by Machine Code (`0x0018AFF0` vs `0x001909F0`):
 *   - `EmpireHUD`, `BusinessHUD`, and `DrugWarsHUD` inherit from THREE bases:
 *       `HUDElement2` (+0x00) + `SubscriberInterface` (+0x64) + `GenericScrollerInterface` (+0x68).
 *   - `ExoticsHUD2` OMITS `SubscriberInterface` (`vfunc_35` @ 0x001911B0 is 22B with zero
 *     `EventManager` calls!), shifting `GenericScrollerInterface` UP by 4 bytes to `+0x64`!
 * ============================================================================
 */

#ifndef SCARFACE_PC_V1002_EMPIRE_SUB_HUDS_H
#define SCARFACE_PC_V1002_EMPIRE_SUB_HUDS_H

#include "EmpireHUD.h"

#if defined(_MSC_VER) && defined(_M_IX86)
    #pragma pack(push, 4)
#endif

/*
 * ============================================================================
 * 1. Additional Engine Helpers & UI Widgets Decoded From Pack 02 PrivateHelpers
 * ============================================================================
 */
namespace RadicalEngine {
    /* Xbox 0x0006FB50: Formatted CScript evaluator (`Con::executef` style) */
    const char* SCARFACE_CDECL ConEvaluateFmt1(const char* fmtScript, int32_t a1);
    const char* SCARFACE_CDECL ConEvaluateFmt2(const char* fmtScript, int32_t a1, int32_t a2);
    const char* SCARFACE_CDECL ConEvaluateFmt2Str(const char* fmtScript, int32_t a1, int32_t a2, const char* s3);

    /* Xbox 0x00099E50 / 0x002FC43E: CScript string-to-float (`atof`) & string-to-int (`atoi`) */
    float   SCARFACE_CDECL StringToFloat(const char* strVal);
    int32_t SCARFACE_CDECL StringToInt(const char* strVal);

    /* Xbox 0x00078800 + 0x000788D0 / 0x000782B0: Sound mixer ducking ("duck_satphone", "duck_menu") */
    uint32_t SCARFACE_CDECL GetAudioDuckHandle(const char* duckPresetName);
    void     SCARFACE_CDECL ActivateAudioDuck(uint32_t duckHandle, uint32_t fadeMs, int32_t a3, int32_t priority, int32_t a5);
    void     SCARFACE_CDECL ReleaseAudioDuck(uint32_t duckHandle, uint32_t fadeMs, int32_t a3, int32_t a4);

    /* Queries global gameplay state int (e.g. 0x95 = Henchman unlock count in BusinessHUD::vfunc_44) */
    int32_t SCARFACE_CDECL QueryGameplayInt(uint32_t queryId, int32_t subIndex);

    /*
     * Xbox 0x00022BB0 (385 bytes): Localized Cash / Integer Formatter!
     *   - Splits `amount` into millions (`0x431BDE83 >> 18`), thousands (`0x10624DD3 >> 6`), and units.
     *   - Reads global language code `g_LanguageCode` (`0x004585B8`):
     *       'F' (0x46 French), 'G' (0x47 German), 'S' (0x53 Spanish), 'I' (0x49 Italian)
     *       -> uses '.' separator (`0x0039E664`); otherwise ',' (`0x0039E668`)!
     *   - Zero-pads `< 100` and `< 10` subgroups into `prefix + formatted + suffix` (32-char buffer).
     */
    extern int32_t g_LanguageCode; /* Xbox 0x004585B8 ('E'=0x45, 'F'=0x46, 'G'=0x47, 'S'=0x53, 'I'=0x49) */

    SCARFACE_MATCHED_FN(0x00000000, 0x00022BB0, 385)
    const char* SCARFACE_CDECL FormatLocalizedCash(
        int32_t amount,
        const char* prefixStr,
        const char* suffixStr);
}

/* Pure3D Scrooby 2D UI Widget (`SetVisible` @ vslot +0x44, `SetAlpha` @ +0x74, `SetColour` @ +0x7C, `SetText` @ +0x9C) */
class Pure3DWidget {
public:
    Pure3DWidget();
    virtual ~Pure3DWidget() {}

    virtual void SetVisible(bool bVisible);
    virtual void SetAlpha(uint8_t alpha);
    virtual void SetColour(uint8_t r, uint8_t g, uint8_t b);
    virtual void SetPosition(int32_t x, int32_t y);
    virtual void GetPosition(int32_t* outX, int32_t* outY) const;
    virtual void SetStringOrTextBible(const char* textKey, int32_t a2 = 0, int32_t a3 = 0);

    /* Xbox 0x00023290 (39B): Selects active image index in a Pure3D MultiSprite */
    void SetMultiSpriteIndex(int32_t spriteIndex);

    static Pure3DWidget* ResolveByUid(FEProject* pProject, uint32_t uid);

    uint32_t m_Uid;
    bool     m_bVisible;
    uint8_t  m_Alpha;
    uint8_t  m_R;
    uint8_t  m_G;
    uint8_t  m_B;
    int32_t  m_PosX;
    int32_t  m_PosY;
    int32_t  m_SpriteIndex;
    int32_t  m_SpriteCount;
    char     m_Text[64];
};

/*
 * ImageStreamInventory (`sizeof == 0x270` = 624 bytes, constructed @ Xbox 0x00026500 [417B]!)
 * Stored at `HUDElement2::m_pImageStreamer` (`this + 0x5C` in DrugWarsHUD & ExoticsHUD2).
 */
class ImageStreamInventory {
public:
    SCARFACE_MATCHED_FN(0x00000000, 0x00026500, 417)
    ImageStreamInventory(
        FEProject* pProject,
        uint32_t streamLayerUid,
        int32_t poolId,
        bool bModeA,
        uint32_t slotCount,
        bool bModeB);

    ~ImageStreamInventory(); /* Xbox 0x000266B0 */

    bool IsStreamReady() const { return m_bReady != 0; }         /* Xbox 0x00025760 */
    void CommitStreamedTexture(int32_t slotIdx);                 /* Xbox 0x00026010 */
    void PumpStreamer(bool bAllowLoad);                          /* Xbox 0x000260C0 */

    struct StreamSlotEntry {
        uint32_t m_Field00;
        uint32_t m_Field04;
        uint8_t  m_Byte08;
        uint8_t  m_Pad09;
        uint8_t  m_Byte0A;
        uint8_t  m_Pad0B;
        uint32_t m_Field0C;
        uint16_t m_Word10;
        uint8_t  m_Byte12;
        uint8_t  m_Pad13[2];
        uint8_t  m_Byte15;
        uint8_t  m_Pad16[2];
    }; /* 0x18 (24) bytes per slot x 2 slots (+0x21C..+0x24B) -> exact 0x270B! */

    uint32_t        m_Ptr00;               /* +0x000 */
    uint32_t        m_Ptr04;               /* +0x004 */
    uint32_t        m_Ptr08;               /* +0x008 */
    uint32_t        m_Unk0C;               /* +0x00C */
    uint8_t         m_bModeA;              /* +0x010 */
    uint8_t         m_bModeB;              /* +0x011 */
    uint8_t         m_bReady;              /* +0x012 */
    uint8_t         m_Pad13;               /* +0x013 */
    uint32_t        m_SlotCount;           /* +0x014 */
    uint8_t         m_InventoryBuf[0x200]; /* +0x018..+0x217 ("ImageStreamInventory") */
    uint32_t        m_State218;            /* +0x218 (= 6 in 0x00026500!) */
    StreamSlotEntry m_Slots[2];            /* +0x21C..+0x24B */
    uint8_t         m_Tail24C[0x24];       /* +0x24C..+0x26F -> exact sizeof == 0x270 (624 bytes)! */
};

/*
 * GenericBarMeter (`sizeof == 0x2C` = 44 bytes, allocated @ DrugWarsHUD::vfunc_44 & embedded at
 * `DrugWarsHUDTurfMenuItem + 0x38` -> `0x38 + 0x2C + 0x04 == 0x68`!).
 */
class GenericBarMeter {
public:
    GenericBarMeter(uint32_t backUid = 0, uint32_t topUid = 0, float scaleFactor = 1.0f);
    virtual ~GenericBarMeter(); /* Xbox 0x0018F600 */

    virtual void SetProgress(float normalizedProgress); /* Slot 01 (+0x04), tail-jumped @ 0x001AE611! */
    virtual void Update(uint32_t deltaMs);              /* Called via [vtable+0x18] in DrugWarsHUD::vfunc_54 */
    virtual void SetTopColour(uint8_t r, uint8_t g, uint8_t b); /* [vtable+0x2C] */

    void SetBackColour(uint8_t r, uint8_t g, uint8_t b); /* Xbox 0x0018F0B0 */
    void SetBorderAlpha(float alphaVal);                 /* Xbox 0x0018F5D0 */

    uint32_t m_BackUid;      /* +0x04 */
    uint32_t m_TopUid;       /* +0x08 */
    float    m_Progress;     /* +0x0C */
    float    m_TargetProg;   /* +0x10 */
    float    m_ScaleFactor;  /* +0x14 (1.5f = 0x3FC00000 or 1.4f = 0x3FB33333 in DrugWarsHUD!) */
    uint8_t  m_TopRGB[4];    /* +0x18 */
    uint8_t  m_BackRGB[4];   /* +0x1C */
    float    m_BorderAlpha;  /* +0x20 */
    uint32_t m_Unk24;        /* +0x24 */
    uint32_t m_Unk28;        /* +0x28 -> exact sizeof == 0x2C (44 bytes)! */
};

/*
 * GenericScrollbar (`sizeof == 0x28` = 40 bytes, allocated @ ExoticsHUD2::vfunc_44
 * bound to "ECScrollBack" & "ECScrollFront", destroyed via 0x002A9290!).
 */
class GenericScrollbar {
public:
    GenericScrollbar(uint32_t scrollBackUid, uint32_t scrollFrontUid);
    ~GenericScrollbar(); /* Xbox 0x002A9290 */

    uint32_t m_ScrollBackUid;  /* +0x00 */
    uint32_t m_ScrollFrontUid; /* +0x04 */
    float    m_ScrollPos;      /* +0x08 */
    uint8_t  m_Pad0C[0x1C];    /* +0x0C..+0x27 -> exact sizeof == 0x28 (40 bytes)! */
};

/*
 * AnimatedNumberCounter (`sizeof == 0x60` = 96 bytes, allocated x2 @ ExoticsHUD2::vfunc_44
 * for "ECCashAmount" [+0xB4] and "ECRepAmount" [+0xB8], helper 0x00196E60!).
 */
class AnimatedNumberCounter {
public:
    explicit AnimatedNumberCounter(uint32_t textWidgetUid);
    virtual ~AnimatedNumberCounter() {}
    virtual void Update(uint32_t deltaMs); /* Slot 01 (+0x04) called in ExoticsHUD2::vfunc_54 */

    /* Xbox 0x00196E60 (50B): Sets or smoothly animates target value */
    SCARFACE_MATCHED_FN(0x00000000, 0x00196E60, 50)
    void SetTargetValue(int32_t newValue);

    uint32_t m_TextWidgetUid; /* +0x04 */
    uint8_t  m_AnimPad[0x40]; /* +0x08..+0x47 */
    int32_t  m_CurrentValue;  /* +0x48 (-1 on init -> snaps immediately in 0x00196E60!) */
    int32_t  m_TargetValue;   /* +0x4C */
    uint8_t  m_Pad50[8];      /* +0x50..+0x57 */
    int8_t   m_AnimFlags;     /* +0x58 (sign bit tested via `test al, al; js` @ 0x00196E84!) */
    uint8_t  m_Pad59[7];      /* +0x59..+0x5F -> exact sizeof == 0x60 (96 bytes)! */
};

/*
 * ============================================================================
 * 2. BusinessHUD & Nested Classes (`sizeof(BusinessHUD) == 0x84` = 132 bytes)
 * ============================================================================
 *   Primary VFTable            : PC 0x007531C4 <== Xbox 0x003BA54C (59 slots)
 *   BusinessHUDMenuItem VFTable: PC 0x007502B8 <== Xbox 0x003BFA18 ( 6 slots, 0x3CB)
 *   HenchmenMenuItem VFTable   : PC 0x007502D4 <== Xbox 0x003BFA34 ( 6 slots, 0x50B)
 */
class BusinessHUD
    : public HUDElement2               /* +0x00..+0x63 */
    , public SubscriberInterface       /* +0x64..+0x67 */
    , public GenericScrollerInterface  /* +0x68..+0x6B */
{
public:
    enum {
        kEventId_BusinessUpdateA   = 0xC8, /* 200 — subscribed in vfunc_35 (0x001906C0) */
        kEventId_BusinessUpdateB   = 0xCA, /* 202 — subscribed in vfunc_35 (0x001906C0) */
        kEventId_EmpireOpened      = 0x9A, /* 154 — triggered at end of vfunc_44        */
        kQueryId_UnlockedHenchmen  = 0x95, /* 149 — queried in vfunc_44 (0x001B26A2)    */
        kBusinessMissionRowCount   = 3,    /* Rows 1..3: BM_MenuItem1..3                */
        kHenchmanPortraitSlotCount = 3,    /* 3 Henchman icons (Enforcer/Driver/Assassin)*/
        kActivePortraitAlpha       = 0xFF, /* 255 — full brightness                     */
        kDimmedPortraitAlpha       = 0x4B, /*  75 — inactive henchman portrait alpha!   */
        kAudioDuckFadeMs           = 500   /* 0x1F4 ms for "duck_satphone"              */
    };

    /* PC VFTable 0x00750300 <== Xbox 0x003BFA60 (`sizeof == 0x14` = 20 bytes) */
    class BusinessHUDMenuItemData : public GenericMenuItemData {
    public:
        BusinessHUDMenuItemData(int32_t rowIndex, int32_t missionSlotIdx, bool bGenerated)
            : GenericMenuItemData()
            , m_RowIndex(rowIndex)
            , m_MissionSlotIndex(missionSlotIdx)
            , m_bMissionListGenerated(bGenerated ? 1 : 0)
        {
            m_Pad11[0] = 0;
            m_Pad11[1] = 0;
            m_Pad11[2] = 0;
        }

        int32_t m_RowIndex;               /* +0x08 */
        int32_t m_MissionSlotIndex;       /* +0x0C (read @ 0x001B176B!) */
        uint8_t m_bMissionListGenerated;  /* +0x10 (read @ 0x001B1765: 0 -> "[BUSINESS_DIALING]"!) */
        uint8_t m_Pad11[3];               /* +0x11..+0x13 -> exact sizeof == 0x14 (20 bytes)! */
    };

    /* PC VFTable 0x00750308 <== Xbox 0x003BFA68 (`sizeof == 0x28` = 40 bytes) */
    class HenchmenItemData : public GenericMenuItemData {
    public:
        explicit HenchmenItemData(int32_t unlockedHenchmenCount);

        bool HasCustomAvailabilityMask() const { return m_bUseMask != 0; } /* 0x0011E190 */

        uint8_t m_HenchPad08[0x17];       /* +0x08..+0x1E */
        uint8_t m_bUseMask;               /* +0x1F */
        uint8_t m_AvailableMask[4];       /* +0x20..+0x23 (read @ 0x001AF349!) */
        int32_t m_SelectedHenchmanIndex;  /* +0x24 (read @ 0x001AF326!) -> exact sizeof == 0x28 (40B)! */
    };

    /* PC VFTable 0x007502B8 <== Xbox 0x003BFA18 (`sizeof == 0x3C` = 60 bytes) */
    class BusinessHUDMenuItem : public GenericMenuItem {
    public:
        BusinessHUDMenuItem(
            FEProject* pProject,
            uint32_t itemUid,
            uint32_t backUid,
            uint32_t spriteUid);

        /* Slot 00 (+0x00) — PC 0x005B43A0 <== Xbox 0x001B1710 (70 bytes) */
        SCARFACE_MATCHED_FN(0x005B43A0, 0x001B1710, 70)
        virtual ~BusinessHUDMenuItem();

        /* Slot 01 (+0x04) — PC 0x005D0910 <== Xbox 0x001CB900 (44 bytes) */
        SCARFACE_MATCHED_FN(0x005D0910, 0x001CB900, 44)
        virtual void OnHighlight();

        /* Slot 02 (+0x08) — PC 0x005D0940 <== Xbox 0x001A5530 (44 bytes) */
        SCARFACE_MATCHED_FN(0x005D0940, 0x001A5530, 44)
        virtual void OnUnhighlight();

        /* Slot 05 (+0x14) — PC 0x005B43C0 <== Xbox 0x001B1760 (165 bytes) */
        SCARFACE_MATCHED_FN(0x005B43C0, 0x001B1760, 165)
        virtual void BindItemData(GenericMenuItemData* pData);

    private:
        Pure3DWidget* m_pMissionSprite; /* +0x38 ("BM_MenuSprite%i") -> exact sizeof == 0x3C (60B)! */
    };

    /* PC VFTable 0x007502D4 <== Xbox 0x003BFA34 (`sizeof == 0x50` = 80 bytes) */
    class HenchmenMenuItem : public GenericMenuItem {
    public:
        HenchmenMenuItem(
            FEProject* pProject,
            uint32_t titleUid,
            uint32_t back4Uid,
            uint32_t henchGroupUid,
            uint32_t henchBackUid);

        /* Slot 00 (+0x00) — PC 0x005B4470 <== Xbox 0x001B1810 (70 bytes) */
        SCARFACE_MATCHED_FN(0x005B4470, 0x001B1810, 70)
        virtual ~HenchmenMenuItem();

        /* Slot 01 (+0x04) — PC 0x005B2200 <== Xbox 0x001AF380 (73 bytes) */
        SCARFACE_MATCHED_FN(0x005B2200, 0x001AF380, 73)
        virtual void OnHighlight();

        /* Slot 02 (+0x08) — PC 0x005B2250 <== Xbox 0x001AF3D0 (82 bytes) */
        SCARFACE_MATCHED_FN(0x005B2250, 0x001AF3D0, 82)
        virtual void OnUnhighlight();

        /* Slot 05 (+0x14) — PC 0x005B21A0 <== Xbox 0x001AF320 (89 bytes) */
        SCARFACE_MATCHED_FN(0x005B21A0, 0x001AF320, 89)
        virtual void BindItemData(GenericMenuItemData* pData);

        Pure3DWidget* GetPortraitSlot(int32_t idx) const {
            if (idx == 0) { return m_pTextWidget; }
            if (idx == 1) { return m_pExtraPortraits[0]; }
            if (idx == 2) { return m_pExtraPortraits[1]; }
            return NULL;
        }

    private:
        /* 3 contiguous portrait pointers at [+0x34, +0x38, +0x3C] (`lea esi, [ebx+0x34]` @ 0x001AF3D5!) */
        Pure3DWidget* m_pExtraPortraits[2];    /* +0x38, +0x3C (with m_pTextWidget @ +0x34 = 3 slots!) */
        Pure3DWidget* m_pHenchTitleWidget;     /* +0x40 */
        Pure3DWidget* m_pHenchBackWidget;      /* +0x44 */
        uint32_t      m_HenchGroupUid;         /* +0x48 */
        int32_t       m_SelectedHenchmanIdx;   /* +0x4C (read @ 0x001AF383!) -> exact sizeof == 0x50 (80B)! */
    };

public:
    static ConcreteClassRep<BusinessHUD> sm_ConcreteClassRep; /* Xbox 0x0043636C */

    /* Constructor — Xbox 0x001909F0 (83 bytes) */
    SCARFACE_MATCHED_FN(0x00000000, 0x001909F0, 83)
    BusinessHUD(const char* pName = NULL, int32_t allocatorPoolId = 0);

    /* Slot 00 (+0x00) — PC 0x005C2E40 <== Xbox 0x00190A50 (6 bytes) */
    SCARFACE_MATCHED_FN(0x005C2E40, 0x00190A50, 6)
    virtual AbstractClassRep* GetClassRep() const;

    /* Slot 01 (+0x04) — PC 0x005C3800 <== Xbox 0x00192AB0 (30 bytes) */
    SCARFACE_MATCHED_FN(0x005C3800, 0x00192AB0, 30)
    virtual ~BusinessHUD();

    /* Slot 29 (+0x74) — PC 0x005E1BC0 <== Xbox 0x00193FD0 (5-byte thunk) */
    SCARFACE_MATCHED_FN(0x005E1BC0, 0x00193FD0, 5)
    virtual void OnResetHUD();

    /* Slot 35 (+0x8C) — PC 0x005C2B20 <== Xbox 0x001906C0 (167 bytes: subscribes 0xC8 & 0xCA!) */
    SCARFACE_MATCHED_FN(0x005C2B20, 0x001906C0, 167)
    virtual bool SetActiveState(bool bActive, int32_t a2, int32_t a3);

    /* Slot 36 (+0x90) — PC 0x005C3590 <== Xbox 0x001907C0 (49 bytes) */
    SCARFACE_MATCHED_FN(0x005C3590, 0x001907C0, 49)
    virtual bool OnPageInit(void* pArg1, void* pArg2);

    /* Slot 38 (+0x98) & Slot 40 (+0xA0) — PC 0x005A4810 <== Xbox 0x0006F990 (3 bytes) */
    SCARFACE_MATCHED_FN(0x005A4810, 0x0006F990, 3)
    virtual bool IsModalHUD() const;
    virtual bool BlocksWorldInput() const;

    /* Slot 44 (+0xB0) — PC 0x005B5220 <== Xbox 0x001B2660 (769 bytes) */
    SCARFACE_MATCHED_FN(0x005B5220, 0x001B2660, 769)
    virtual bool OnOpenModal(FEProject* pProject);

    /* Slot 45 (+0xB4) — PC 0x005B1DF0 <== Xbox 0x001AF0B0 (218 bytes) */
    SCARFACE_MATCHED_FN(0x005B1DF0, 0x001AF0B0, 218)
    virtual bool OnCloseModal(int32_t closeReason);

    /* Slot 50 (+0xC8) — PC 0x005D0480 <== Xbox 0x00190800 (34 bytes: ducks "duck_satphone") */
    SCARFACE_MATCHED_FN(0x005D0480, 0x00190800, 34)
    virtual void vfunc_50();

    /* Slot 51 (+0xCC) — PC 0x005C2C20 <== Xbox 0x00190830 (32 bytes: unducks "duck_satphone") */
    SCARFACE_MATCHED_FN(0x005C2C20, 0x00190830, 32)
    virtual void vfunc_51();

    /* Slot 54 (+0xD8) — PC 0x005C2AE0 <== Xbox 0x00190680 (57 bytes) */
    SCARFACE_MATCHED_FN(0x005C2AE0, 0x00190680, 57)
    virtual void UpdateFrame(uint32_t deltaMs);

    int32_t GetMissionOffset() const   { return m_MissionOffset; }
    int32_t GetHenchmanCount() const   { return m_HenchmanCount; }
    GenericCursorMenu* GetMenu() const { return m_pMenu; }

private:
    GenericCursorMenu* m_pMenu;           /* +0x6C (x86) */
    GenericScroller*   m_pScroller;       /* +0x70 (x86) */
    int32_t            m_MissionOffset;   /* +0x74 (x86): `bGenerated ? 6 : 0` via `neg; sbb; and 6`! */
    uint8_t            m_bDialingActive;  /* +0x78 (x86) */
    uint8_t            m_bHasWaypoint;    /* +0x79 (x86) */
    uint8_t            m_Pad7A[2];        /* +0x7A..+0x7B */
    int32_t            m_HenchmanCount;   /* +0x7C (x86): `QueryGameplayInt(0x95, 0)` */
    HenchmenItemData*  m_pHenchmanData;   /* +0x80 (x86): cleared to NULL in vfunc_45 -> exact 0x84B! */
};

/*
 * Bonus Class Uncovered Adjacent to BusinessHUD::vfunc_51 (`0x00190850`..`0x00190886`):
 * BusinessDetailHUD (`sizeof == 0x6C` = 108 bytes, Xbox VFTable 0x003BA41C, SubVFTable 0x003BA410)
 */
class BusinessDetailHUD
    : public HUDElement2         /* +0x00..+0x63 */
    , public SubscriberInterface /* +0x64..+0x67 */
{
public:
    SCARFACE_MATCHED_FN(0x00000000, 0x00190850, 55)
    BusinessDetailHUD(const char* pName = NULL, int32_t allocatorPoolId = 0);
    virtual AbstractClassRep* GetClassRep() const;

private:
    uint8_t m_bFlag68;  /* +0x68 */
    uint8_t m_bFlag69;  /* +0x69 */
    uint8_t m_bFlag6A;  /* +0x6A */
    uint8_t m_Pad6B;    /* +0x6B -> exact sizeof == 0x6C (108 bytes)! */
};

/*
 * ============================================================================
 * 3. DrugWarsHUD & Nested Classes (`sizeof(DrugWarsHUD) == 0xC0` = 192 bytes)
 * ============================================================================
 *   Primary VFTable                 : PC 0x00753494 <== Xbox 0x003BAACC (59 slots)
 *   DrugWarsHUDFrontMenuItem VFTable: PC 0x0074FF44 <== Xbox 0x003BF6FC ( 6 slots, 0x3CB)
 *   DrugWarsHUDTurfMenuItem VFTable : PC 0x0074FF28 <== Xbox 0x003BF6E0 ( 6 slots, 0x68B)
 */
class DrugWarsHUD
    : public HUDElement2               /* +0x00..+0x63 (uses m_pImageStreamer @ +0x5C!) */
    , public SubscriberInterface       /* +0x64..+0x67 */
    , public GenericScrollerInterface  /* +0x68..+0x6B */
{
public:
    enum {
        kEventId_DrugWarsUpdate = 0xCD, /* 205 — subscribed in vfunc_35 (0x00192EF0) */
        kEventId_EmpireOpened   = 0x9A, /* 154 — triggered at end of vfunc_44        */
        kTurfRegionCount        = 4,    /* Little Havana, Downtown, South Beach, North Beach */
        kStatBarCount           = 2     /* DrugWarsStatBarTop & DrugWarsStatBarBottom */
    };

    /* PC VFTable 0x0074FF98 <== Xbox 0x003BF74C (`sizeof == 0x10` = 16 bytes) */
    class DrugWarsHUDMenuItemData : public GenericMenuItemData {
    public:
        DrugWarsHUDMenuItemData(int32_t turfIndex, int32_t frontIndex = 0)
            : GenericMenuItemData()
            , m_TurfIndex(turfIndex)
            , m_FrontIndex(frontIndex)
        {
        }

        int32_t m_TurfIndex;  /* +0x08 (read @ 0x001AE5E4 & 0x001AE71A!) */
        int32_t m_FrontIndex; /* +0x0C (read @ 0x001AE715!) -> exact sizeof == 0x10 (16 bytes)! */
    };

    /* PC VFTable 0x0074FF44 <== Xbox 0x003BF6FC (`sizeof == 0x3C` = 60 bytes) */
    class DrugWarsHUDFrontMenuItem : public GenericMenuItem {
    public:
        DrugWarsHUDFrontMenuItem(FEProject* pProject, uint32_t itemUid, uint32_t backUid, uint32_t iconUid);

        /* Slot 00 (+0x00) — PC 0x005B3510 <== Xbox 0x001B06F0 (30B) + 0x001AE6C0 (77B) */
        SCARFACE_MATCHED_FN(0x005B3510, 0x001B06F0, 30)
        virtual ~DrugWarsHUDFrontMenuItem();

        /* Slot 01 (+0x04) — PC 0x005B3530 <== Xbox 0x001B0710 (102 bytes) */
        SCARFACE_MATCHED_FN(0x005B3530, 0x001B0710, 102)
        virtual void OnHighlight();

        /* Slot 02 (+0x08) — PC 0x005B35A0 <== Xbox 0x001B0780 (102 bytes) */
        SCARFACE_MATCHED_FN(0x005B35A0, 0x001B0780, 102)
        virtual void OnUnhighlight();

        /* Slot 03 (+0x0C) — PC 0x005B11D0 <== Xbox 0x001B7D40 (55 bytes) */
        SCARFACE_MATCHED_FN(0x005B11D0, 0x001B7D40, 55)
        virtual void SetVisible(bool bVis);

        /* Slot 05 (+0x14) — PC 0x005B1140 <== Xbox 0x001AE710 (133 bytes) */
        SCARFACE_MATCHED_FN(0x005B1140, 0x001AE710, 133)
        virtual void BindItemData(GenericMenuItemData* pData);

    private:
        Pure3DWidget* m_pFrontIcon; /* +0x38 -> exact sizeof == 0x3C (60 bytes)! */
    };

    /* PC VFTable 0x0074FF28 <== Xbox 0x003BF6E0 (`sizeof == 0x68` = 104 bytes) */
    class DrugWarsHUDTurfMenuItem : public GenericMenuItem {
    public:
        DrugWarsHUDTurfMenuItem(
            FEProject* pProject,
            uint32_t itemUid,
            uint32_t meterTopUid,
            uint32_t meterBackUid,
            uint32_t turfIconUid);

        /* Slot 00 (+0x00) — PC 0x005B3320 <== Xbox 0x001B0520 (40 bytes) */
        SCARFACE_MATCHED_FN(0x005B3320, 0x001B0520, 40)
        virtual ~DrugWarsHUDTurfMenuItem();

        /* Slot 01 (+0x04) — PC 0x005B3390 <== Xbox 0x001B0550 (196 bytes) */
        SCARFACE_MATCHED_FN(0x005B3390, 0x001B0550, 196)
        virtual void OnHighlight();

        /* Slot 02 (+0x08) — PC 0x005B3450 <== Xbox 0x001B0620 (196 bytes) */
        SCARFACE_MATCHED_FN(0x005B3450, 0x001B0620, 196)
        virtual void OnUnhighlight();

        /* Slot 05 (+0x14) — PC 0x005B0FA0 <== Xbox 0x001AE5E0 (52 bytes) */
        SCARFACE_MATCHED_FN(0x005B0FA0, 0x001AE5E0, 52)
        virtual void BindItemData(GenericMenuItemData* pData);

        const GenericBarMeter& GetTurfMeter() const { return m_TurfMeter; }

    private:
        GenericBarMeter m_TurfMeter; /* +0x38..+0x63 (`lea ecx, [esi+0x38]` @ 0x001B0523 & 0x001AE606!) */
        Pure3DWidget*   m_pTurfIcon; /* +0x64 -> exact sizeof == 0x68 (104 bytes)! */
    };

public:
    static ConcreteClassRep<DrugWarsHUD> sm_ConcreteClassRep; /* Xbox 0x00436524 */

    /* Constructor — Xbox 0x00192F90 (173 bytes) */
    SCARFACE_MATCHED_FN(0x00000000, 0x00192F90, 173)
    DrugWarsHUD(const char* pName = NULL, int32_t allocatorPoolId = 0);

    /* Slot 00 (+0x00) — PC 0x005C33D0 <== Xbox 0x00192DA0 (6 bytes) */
    SCARFACE_MATCHED_FN(0x005C33D0, 0x00192DA0, 6)
    virtual AbstractClassRep* GetClassRep() const;

    /* Slot 01 (+0x04) — PC 0x005C36B0 <== Xbox 0x00193040 (30B) + 0x00192D40 (86B body) */
    SCARFACE_MATCHED_FN(0x005C36B0, 0x00193040, 30)
    virtual ~DrugWarsHUD();

    /* Slot 29 (+0x74) — PC 0x005C33E0 <== Xbox 0x00192DB0 (183 bytes) */
    SCARFACE_MATCHED_FN(0x005C33E0, 0x00192DB0, 183)
    virtual void OnResetHUD();

    /* Slot 35 (+0x8C) — PC 0x005C3520 <== Xbox 0x00192EF0 (107 bytes: Event 0xCD!) */
    SCARFACE_MATCHED_FN(0x005C3520, 0x00192EF0, 107)
    virtual bool SetActiveState(bool bActive, int32_t a2, int32_t a3);

    /* Slot 36 (+0x90) — PC 0x005C3590 <== Xbox 0x001907C0 (49 bytes) */
    SCARFACE_MATCHED_FN(0x005C3590, 0x001907C0, 49)
    virtual bool OnPageInit(void* pArg1, void* pArg2);

    /* Slot 38 (+0x98) & Slot 40 (+0xA0) — PC 0x005A4810 <== Xbox 0x0006F990 (3 bytes) */
    SCARFACE_MATCHED_FN(0x005A4810, 0x0006F990, 3)
    virtual bool IsModalHUD() const;
    virtual bool BlocksWorldInput() const;

    /* Slot 44 (+0xB0) — PC 0x005B4500 <== Xbox 0x001B18E0 (732 bytes) */
    SCARFACE_MATCHED_FN(0x005B4500, 0x001B18E0, 732)
    virtual bool OnOpenModal(FEProject* pProject);

    /* Slot 45 (+0xB4) — PC 0x005B09A0 <== Xbox 0x001AE000 (232 bytes) */
    SCARFACE_MATCHED_FN(0x005B09A0, 0x001AE000, 232)
    virtual bool OnCloseModal(int32_t closeReason);

    /* Slot 54 (+0xD8) — PC 0x005C34A0 <== Xbox 0x00192E70 (235 bytes) */
    SCARFACE_MATCHED_FN(0x005C34A0, 0x00192E70, 235)
    virtual void UpdateFrame(uint32_t deltaMs);

    GenericCursorMenu* GetTurfMenu() const     { return m_pTurfMenu; }
    GenericBarMeter*   GetStatBar(int i) const { return m_pStatBars[i]; }

private:
    GenericCursorMenu* m_pTurfMenu;             /* +0x6C (x86) */
    GenericCursorMenu* m_pFrontMenu;            /* +0x70 (x86) */
    GenericCursorMenu* m_pActiveMenu;           /* +0x74 (x86): points to TurfMenu or FrontMenu! */
    GenericScroller*   m_pScroller;             /* +0x78 (x86) */
    Pure3DWidget*      m_pFrontLayer;           /* +0x7C (x86): "drugwarsfrontlayer" */
    Pure3DWidget*      m_pFrontStatLayer;       /* +0x80 (x86): "drugwarsfrontstatlayer" */
    Pure3DWidget*      m_pFrontAttackLayer;     /* +0x84 (x86): "drugwarsfrontattacklayer" */
    Pure3DWidget*      m_pFrontStatusLayer;     /* +0x88 (x86): "drugwarsfrontstatuslayer" */
    Pure3DWidget*      m_pConfirmLabel;         /* +0x8C (x86): "DrugWarsConfirmLabel" */
    Pure3DWidget*      m_pCancelLabel;          /* +0x90 (x86): "DrugWarsCancelLabel" */
    Pure3DWidget*      m_pFrontStatusText;      /* +0x94 (x86): "DrugWarsFrontStatusText" */
    GenericBarMeter*   m_pStatBars[2];          /* +0x98, +0x9C: Top (scale 1.5f) & Bottom (scale 1.4f) */
    uint32_t           m_SelectedTurfIdx;       /* +0xA0 (x86) */
    uint32_t           m_SelectedFrontIdx;      /* +0xA4 (x86) */
    Pure3DWidget*      m_pTurfOverlaysLayer;    /* +0xA8 (x86): "TurfOverlays" */
    Pure3DWidget*      m_pTurfOverlayItems[4];  /* +0xAC..+0xB8: "MP_turfOverlay1..4" */
    uint8_t            m_bStreamPending;        /* +0xBC (x86): polled in vfunc_54 @ 0x00192EC0! */
    uint8_t            m_PadBD[3];              /* +0xBD..+0xBF -> exact sizeof == 0xC0 (192 bytes)! */
};

/*
 * ============================================================================
 * 4. ExoticsHUD2 & Nested Classes (`sizeof(ExoticsHUD2) == 0xC4` = 196 bytes)
 * ============================================================================
 *   Primary VFTable               : PC 0x0074CC14 <== Xbox 0x003B90D4 (59 slots)
 *   GenericScrollerInterface (+64): Xbox 0x003B90BC (NO SubscriberInterface!)
 *   ExoticsHUDMenuItem VFTable    : PC 0x0074CD44 <== Xbox 0x003B93D4 ( 6 slots, 0x44B)
 */
class ExoticsHUD2
    : public HUDElement2               /* +0x00..+0x63 (uses m_pImageStreamer @ +0x5C!) */
    , public GenericScrollerInterface  /* +0x64..+0x67 (shifted UP 4 bytes vs EmpireHUD!) */
{
public:
    enum {
        kEventId_EmpireOpened      = 0x9A, /* 154 — triggered at end of vfunc_44 */
        kVisibleExoticRowSlots     = 8,    /* Loop `0..7` ("ECMenuItem0..7") @ 0x0018C4A0 */
        kCategoryHeaderIndentPx    = 85,   /* 0x55 — `itemIdx <= -1` @ 0x0018B6B9 */
        kChildExoticItemIndentPx   = 100,  /* 0x64 — `0x55 + 0x0F` when `itemIdx >= 0`! */
        kHighlightedArrowAlpha     = 0xC8, /* 200 — set in ExoticsHUDMenuItem::OnHighlight */
        kMenuAudioDuckFadeMs       = 500   /* 0x1F4 ms for "duck_menu" */
    };

    /* PC VFTable 0x0074CD64 <== Xbox 0x003B9408 (`sizeof == 0x14` = 20 bytes) */
    class ExoticsHUDMenuItemData : public GenericMenuItemData {
    public:
        ExoticsHUDMenuItemData(int32_t categoryIdx, int32_t itemIdx, bool bOwnedOrPlaced)
            : GenericMenuItemData()
            , m_CategoryIndex(categoryIdx)
            , m_ItemIndex(itemIdx)
            , m_bOwnedOrPlaced(bOwnedOrPlaced ? 1 : 0)
        {
            m_Pad11[0] = 0;
            m_Pad11[1] = 0;
            m_Pad11[2] = 0;
        }

        int32_t m_CategoryIndex;  /* +0x08 (read @ 0x0018B64A!) */
        int32_t m_ItemIndex;      /* +0x0C (-1 for category header, >=0 for item @ 0x0018B64E!) */
        uint8_t m_bOwnedOrPlaced; /* +0x10 (read @ 0x0018B651 -> arrow sprite idx!) */
        uint8_t m_Pad11[3];       /* +0x11..+0x13 -> exact sizeof == 0x14 (20 bytes)! */
    };

    /* PC VFTable 0x0074CD44 <== Xbox 0x003B93D4 (`sizeof == 0x44` = 68 bytes) */
    class ExoticsHUDMenuItem : public GenericMenuItem {
    public:
        ExoticsHUDMenuItem(
            FEProject* pProject,
            uint32_t itemUid,
            uint32_t backUid,
            uint32_t arrowUid);

        /* Slot 00 (+0x00) — PC 0x0059F740 <== Xbox 0x0018C280 (70 bytes) */
        SCARFACE_MATCHED_FN(0x0059F740, 0x0018C280, 70)
        virtual ~ExoticsHUDMenuItem();

        /* Slot 01 (+0x04) — PC 0x0059EA90 <== Xbox 0x0018B6F0 (67 bytes) */
        SCARFACE_MATCHED_FN(0x0059EA90, 0x0018B6F0, 67)
        virtual void OnHighlight();

        /* Slot 02 (+0x08) — PC 0x0059F190 <== Xbox 0x0018BD20 (142 bytes) */
        SCARFACE_MATCHED_FN(0x0059F190, 0x0018BD20, 142)
        virtual void OnUnhighlight();

        /* Slot 03 (+0x0C) — PC 0x0059EAE0 <== Xbox 0x0018B740 (55 bytes) */
        SCARFACE_MATCHED_FN(0x0059EAE0, 0x0018B740, 55)
        virtual void SetVisible(bool bVis);

        /* Slot 05 (+0x14) — PC 0x0059E9E0 <== Xbox 0x0018B640 (163 bytes) */
        SCARFACE_MATCHED_FN(0x0059E9E0, 0x0018B640, 163)
        virtual void BindItemData(GenericMenuItemData* pData);

        Pure3DWidget* GetTextWidget() const  { return m_pTextWidget; }
        Pure3DWidget* GetArrowWidget() const { return m_pArrowWidget; }

    private:
        uint32_t      m_Reserved38;  /* +0x38 */
        Pure3DWidget* m_pArrowWidget;/* +0x3C ("ECArrow%i", alpha 0xC8 on highlight @ 0x0018B71D!) */
        uint32_t      m_Reserved40;  /* +0x40 -> exact sizeof == 0x44 (68 bytes)! */
    };

public:
    static ConcreteClassRep<ExoticsHUD2> sm_ConcreteClassRep; /* Xbox 0x00435F50 */

    /* Constructor — Xbox 0x0018AFF0 (156 bytes) */
    SCARFACE_MATCHED_FN(0x00000000, 0x0018AFF0, 156)
    ExoticsHUD2(const char* pName = NULL, int32_t allocatorPoolId = 0);

    /* Slot 00 (+0x00) — PC 0x0059E380 <== Xbox 0x0018B0A0 (6 bytes) */
    SCARFACE_MATCHED_FN(0x0059E380, 0x0018B0A0, 6)
    virtual AbstractClassRep* GetClassRep() const;

    /* Slot 01 (+0x04) — PC 0x0059F220 <== Xbox 0x0018BD90 (30B) + 0x0018B780 (132B body) */
    SCARFACE_MATCHED_FN(0x0059F220, 0x0018BD90, 30)
    virtual ~ExoticsHUD2();

    /* Slot 04 (+0x10) — PC 0x0059E4C0 <== Xbox 0x0018B1E0 (43 bytes) */
    SCARFACE_MATCHED_FN(0x0059E4C0, 0x0018B1E0, 43)
    virtual bool OnAddToSim(bool bRegister);

    /* Slot 29 (+0x74) — PC 0x0059E390 <== Xbox 0x0018B0B0 (293 bytes) */
    SCARFACE_MATCHED_FN(0x0059E390, 0x0018B0B0, 293)
    virtual void OnResetHUD();

    /* Slot 35 (+0x8C) — PC 0x005D9EB0 <== Xbox 0x001911B0 (22 bytes: NO EventManager calls!) */
    SCARFACE_MATCHED_FN(0x005D9EB0, 0x001911B0, 22)
    virtual bool SetActiveState(bool bActive, int32_t a2, int32_t a3);

    /* Slot 38 (+0x98) & Slot 40 (+0xA0) — PC 0x005A4810 <== Xbox 0x0006F990 (3 bytes) */
    virtual bool IsModalHUD() const;
    virtual bool BlocksWorldInput() const;

    /* Slot 44 (+0xB0) — PC 0x0059F760 <== Xbox 0x0018C2D0 (892 bytes) */
    SCARFACE_MATCHED_FN(0x0059F760, 0x0018C2D0, 892)
    virtual bool OnOpenModal(FEProject* pProject);

    /* Slot 45 (+0xB4) — PC 0x0059ED40 <== Xbox 0x0018B960 (234 bytes) */
    SCARFACE_MATCHED_FN(0x0059ED40, 0x0018B960, 234)
    virtual bool OnCloseModal(int32_t closeReason);

    /* Slot 54 (+0xD8) — PC 0x0059E4F0 <== Xbox 0x0018B210 (121 bytes) */
    SCARFACE_MATCHED_FN(0x0059E4F0, 0x0018B210, 121)
    virtual void UpdateFrame(uint32_t deltaMs);

    GenericCursorMenu*     GetMenu() const        { return m_pMenu; }
    AnimatedNumberCounter* GetCashCounter() const { return m_pCashCounter; }
    AnimatedNumberCounter* GetRepCounter() const  { return m_pRepCounter; }

private:
    GenericCursorMenu*     m_pMenu;               /* +0x68 (x86) */
    GenericScrollbar*      m_pScrollbar;          /* +0x6C (x86): "ECScrollBack" / "ECScrollFront" */
    GenericScroller*       m_pScroller;           /* +0x70 (x86) */
    int32_t                m_ExpandedCategory;    /* +0x74 (x86): -1 on init */
    Pure3DWidget*          m_pDetailIconImage;    /* +0x78 (x86): "ECDetailIconImage" */
    uint32_t               m_Unk7C;               /* +0x7C (x86) */
    Pure3DWidget*          m_pImageStreamerLayer; /* +0x80 (x86): "ECImageStreamerLayer" */
    Pure3DWidget*          m_pStreamImages[3];    /* +0x84, +0x88, +0x8C: "ECDetailStreamImage0..2" */
    uint32_t               m_DetailTitleUid;      /* +0x90 (x86): "ECDetailTitle" */
    uint32_t               m_DetailPriceUid;      /* +0x94 (x86): "ECDetailPrice" */
    uint32_t               m_BuyLabelUid;         /* +0x98 (x86): "ECBuyLabel" */
    uint32_t               m_ThemeLabelUid;       /* +0x9C (x86): "ECThemeLabel" */
    uint32_t               m_InfoLabelUid;        /* +0xA0 (x86): "ECInfoLabel" */
    uint32_t               m_InfoTextUid;         /* +0xA4 (x86): "DL_ECInfoText" */
    uint32_t               m_InfoLayerUid;        /* +0xA8 (x86): "ECInfoLayer" */
    uint32_t               m_RepGainLayerUid;     /* +0xAC (x86): "ECRepGainLayer" */
    uint32_t               m_RepGainedTextUid;    /* +0xB0 (x86): "DL_ECRepGained" */
    AnimatedNumberCounter* m_pCashCounter;        /* +0xB4 (x86): "ECCashAmount" (0x60B) */
    AnimatedNumberCounter* m_pRepCounter;         /* +0xB8 (x86): "ECRepAmount"  (0x60B) */
    int32_t                m_PendingStreamSlot;   /* +0xBC (x86): -1 on init */
    uint8_t                m_bStreamPaused;       /* +0xC0 (x86): inverted arg to PumpStreamer! */
    uint8_t                m_bSelectionDirty;     /* +0xC1 (x86) */
    uint8_t                m_PadC2[2];            /* +0xC2..+0xC3 -> exact sizeof == 0xC4 (196 bytes)! */
};

/*
 * ============================================================================
 * 5. Compile-Time 32-Bit x86 ABI Size & Layout Assertions (Pack 02 Complete)
 * ============================================================================
 */
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(ImageStreamInventory) == 0x270,
    image_stream_inventory_must_be_0x270_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(GenericBarMeter) == 0x2C,
    generic_bar_meter_must_be_0x2C_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(GenericScrollbar) == 0x28,
    generic_scrollbar_must_be_0x28_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(AnimatedNumberCounter) == 0x60,
    animated_number_counter_must_be_0x60_bytes_on_x86);

SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(BusinessHUD) == 0x84,
    business_hud_must_be_exact_0x84_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(BusinessHUD::BusinessHUDMenuItem) == 0x3C,
    business_menu_item_must_be_0x3C_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(BusinessHUD::BusinessHUDMenuItemData) == 0x14,
    business_menu_item_data_must_be_0x14_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(BusinessHUD::HenchmenMenuItem) == 0x50,
    henchmen_menu_item_must_be_0x50_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(BusinessHUD::HenchmenItemData) == 0x28,
    henchmen_item_data_must_be_0x28_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(BusinessDetailHUD) == 0x6C,
    business_detail_hud_must_be_0x6C_bytes_on_x86);

SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(DrugWarsHUD) == 0xC0,
    drug_wars_hud_must_be_exact_0xC0_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(DrugWarsHUD::DrugWarsHUDFrontMenuItem) == 0x3C,
    drug_wars_front_menu_item_must_be_0x3C_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(DrugWarsHUD::DrugWarsHUDTurfMenuItem) == 0x68,
    drug_wars_turf_menu_item_must_be_0x68_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(DrugWarsHUD::DrugWarsHUDMenuItemData) == 0x10,
    drug_wars_menu_item_data_must_be_0x10_bytes_on_x86);

SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(ExoticsHUD2) == 0xC4,
    exotics_hud2_must_be_exact_0xC4_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(ExoticsHUD2::ExoticsHUDMenuItem) == 0x44,
    exotics_menu_item_must_be_0x44_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(ExoticsHUD2::ExoticsHUDMenuItemData) == 0x14,
    exotics_menu_item_data_must_be_0x14_bytes_on_x86);

#if defined(_MSC_VER) && defined(_M_IX86)
    #pragma pack(pop)
#endif

#endif /* SCARFACE_PC_V1002_EMPIRE_SUB_HUDS_H */
