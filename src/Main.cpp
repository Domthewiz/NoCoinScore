#include <actor/ActorState.h>
#include <graphics/AnimModel.h>
#include <state/FStateID.h>

void main() {} // don't care :)

class ActorCoinDemoJump : public ActorMultiState
{
    public:
        // Address: 0x026C44A0
        ActorCoinDemoJump(const ActorCreateParam& param);
        // Address: 0x026C4C00
        ~ActorCoinDemoJump() override { }

    protected:
        // Address: 0x026C450C
        Result create() override;
        // Address: 0x026C4034
        bool execute() override;

    public:
        // StateID_Alive            Address: 0x1021F1B4
        // initializeState_Alive    Address: 0x026C4BF8
        // executeState_Alive       Address: 0x026C4738
        // finalizeState_Alive      Address: 0x026C4BFC
        DECLARE_STATE_ID(ActorCoinDemoJump, Alive);

    protected:
        AnimModel*  mModel; // These are part of a different struct, unknown name however.
        u32         _17cc;  // These are part of a different struct, unknown name however.
        u32         _17d0;  // These are part of a different struct, unknown name however.
        u32         _17d4;  // These are part of a different struct, unknown name however.
        u32         _17d8;
        u8          _17dc[4];
};
static_assert(sizeof(ActorCoinDemoJump) == 0x17E0, "ActorCoinDemoJump size mismatch");

void ActorCoinDemoJump_ScoreSetPositionOverride(ActorCoinDemoJump *_this) {
    // Sets the position to zero before the score can get displayed
    _this->getPos() = sead::Vector3f::zero;
    return;
}

#define TELKIN_REGISTERS
#include <telkin/Telkin.h>

void ScoreSetPositionOverride() tAssembly(
    tSaveVolatileRegisters;
    
    mr r3, r31;
    bl _Z42ActorCoinDemoJump_ScoreSetPositionOverrideP17ActorCoinDemoJump;
    
    tRestoreVolatileRegisters;

    // replaced instruction
    li r5, 0;
    blr;
)
tBranch(0x026C47E8, ScoreSetPositionOverride, tk::BranchType::bl); // ActorCoinDemoJump::executeState_Alive()