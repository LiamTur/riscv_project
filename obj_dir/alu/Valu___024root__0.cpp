// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Valu.h for the primary calling header

#include "Valu__pch.h"

bool Valu___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

void Valu___024root___ico_comb__TOP__0(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___ico_comb__TOP__0\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.out = ((8U & (IData)(vlSelfRef.op_code))
                      ? ((- (IData)((1U & (~ ((IData)(vlSelfRef.op_code) 
                                              >> 1U))))) 
                         & (((1U & (IData)(vlSelfRef.op_code))
                              ? (vlSelfRef.rs1 & vlSelfRef.rs2)
                              : (vlSelfRef.rs1 | vlSelfRef.rs2)) 
                            & (- (IData)((1U & (~ ((IData)(vlSelfRef.op_code) 
                                                   >> 2U)))))))
                      : ((4U & (IData)(vlSelfRef.op_code))
                          ? ((2U & (IData)(vlSelfRef.op_code))
                              ? ((1U & (IData)(vlSelfRef.op_code))
                                  ? VL_SHIFTRS_III(32,32,5, vlSelfRef.rs1, 
                                                   (0x0000001fU 
                                                    & vlSelfRef.rs2))
                                  : (vlSelfRef.rs1 
                                     >> (0x0000001fU 
                                         & vlSelfRef.rs2)))
                              : ((1U & (IData)(vlSelfRef.op_code))
                                  ? (vlSelfRef.rs1 
                                     ^ vlSelfRef.rs2)
                                  : (1U & (- (IData)(
                                                     (vlSelfRef.rs1 
                                                      < vlSelfRef.rs2))))))
                          : ((2U & (IData)(vlSelfRef.op_code))
                              ? ((1U & (IData)(vlSelfRef.op_code))
                                  ? (1U & (- (IData)(
                                                     (((vlSelfRef.rs1 
                                                        >> 0x0000001fU) 
                                                       < 
                                                       (vlSelfRef.rs2 
                                                        >> 0x0000001fU)) 
                                                      | ((0x7fffffffU 
                                                          & vlSelfRef.rs1) 
                                                         < 
                                                         (0x7fffffffU 
                                                          & vlSelfRef.rs2))))))
                                  : (vlSelfRef.rs1 
                                     << (0x0000001fU 
                                         & vlSelfRef.rs2)))
                              : ((1U & (IData)(vlSelfRef.op_code))
                                  ? (vlSelfRef.rs1 
                                     - vlSelfRef.rs2)
                                  : (vlSelfRef.rs1 
                                     + vlSelfRef.rs2)))));
    vlSelfRef.z = (0U == vlSelfRef.out);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Valu___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Valu___024root___eval_phase__ico(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_phase__ico\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                        (((vlSelfRef.rs2 
                                                           != vlSelfRef.__Vtrigprevexpr___TOP__rs2__0) 
                                                          << 2U) 
                                                         | (((vlSelfRef.rs1 
                                                              != vlSelfRef.__Vtrigprevexpr___TOP__rs1__0) 
                                                             << 1U) 
                                                            | ((IData)(vlSelfRef.op_code) 
                                                               != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__op_code__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__op_code__0 
            = vlSelfRef.op_code;
        vlSelfRef.__Vtrigprevexpr___TOP__rs1__0 = vlSelfRef.rs1;
        vlSelfRef.__Vtrigprevexpr___TOP__rs2__0 = vlSelfRef.rs2;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (4ULL | vlSelfRef.__VicoTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Valu___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Valu___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_ico
            if ((7ULL & vlSelfRef.__VicoTriggered[0U])) {
                Valu___024root___ico_comb__TOP__0(vlSelf);
            }
        }
    }
    return (__VicoExecute);
}

void Valu___024root___eval(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    // Body
    __VicoIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Valu___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("rtl/alu.sv", 4, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Valu___024root___eval_phase__ico(vlSelf);
    } while (vlSelfRef.__VicoPhaseResult);
}

#ifdef VL_DEBUG
void Valu___024root___eval_debug_assertions(Valu___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Valu___024root___eval_debug_assertions\n"); );
    Valu__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.op_code & 0xf0U)))) {
        Verilated::overWidthError("op_code");
    }
}
#endif  // VL_DEBUG
