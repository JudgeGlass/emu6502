/**
 * @file CPU.h
 * 
 * @author Hunter Wilcox (hunter.wilcox@judgeglass.net)
 * @brief The 6502 CPU
 * @version 0.1
 * @date 2022-08-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __CPU_H__
#define __CPU_H__

#include "types.h"

typedef struct CPU
{
    uint8_t A;
    uint8_t X;
    uint8_t Y;
    uint8_t SP;
    uint16_t PC;

} cpu_t;

typedef struct Flags{
    uint8_t NEGATIVE;
    uint8_t OVERFLOW;
    uint8_t BREAK;
    uint8_t DECIMAL_MODE;
    uint8_t IRQ_DISABLED;
    uint8_t ZERO;
    uint8_t CARRY;
};

const uint8_t
    ADC_IMM         = 0X69, //ADC
    ADC_ZP          = 0X65,
    ADC_ZPX         = 0X75,
    ADC_ABS         = 0X6D,
    ADC_ABSX        = 0X7D,
    ADC_ABSY        = 0X79,
    ADC_INDX        = 0X61,
    ADC_INDY        = 0X71,
    AND_IMM         = 0X29, //AND
    AND_ZP          = 0X25,
    AND_ZPX         = 0X35,
    AND_ABS         = 0X2D,
    AND_ABSX        = 0X3D,
    AND_ABSY        = 0X39,
    AND_INDX        = 0X21,
    AND_INDY        = 0X31,
    ASL_ACC         = 0X0A, //ASL
    ASL_ZP          = 0X06,
    ASL_ZPX         = 0X16,
    ASL_ABS         = 0X0E,
    ASL_ABSX        = 0X1E, //BIT
    BIT_ZP          = 0X24,
    BIT_ABS         = 0X2C, //BRANCH INSTRUCTIONS
    BPL             = 0X10,
    BMI             = 0X30,
    BVC             = 0X50,
    BVS             = 0X70,
    BCC             = 0X90,
    BCS             = 0XB0,
    BNE             = 0XD0,
    BEQ             = 0XF0, //FLAGS
    CLC             = 0X18,
    SEC             = 0X38,
    CLI             = 0X58,
    SEI             = 0X78,
    CLV             = 0XB8,
    CLD             = 0XD8,
    SED             = 0XF8, //REGISTER INSTRUCTIONS
    TAX             = 0XAA,
    TXA             = 0X8A,
    DEX             = 0XCA,
    INX             = 0XE8,
    TAY             = 0XA8,
    TYA             = 0X98,
    DEY             = 0X88,
    INY             = 0XC8, //STACK INSTRUCTIONS
    TXS             = 0X94,
    TSX             = 0XBA,
    PHA             = 0X48,
    PLA             = 0X68,
    PHP             = 0X08,
    PLP             = 0X28, //GENERAL
    BRK_IMP         = 0X00,
    RTI_IMP         = 0X40,
    RTS_IMP         = 0X60,
    NOP             = 0XEA, //CMP
    CMP_IMM         = 0XC9,
    CMP_ZP          = 0XC5,
    CMP_ZPX         = 0XD5,
    CMP_ABS         = 0XCD,
    CMP_ABSX        = 0XDD,
    CMP_ABSY        = 0XD9,
    CMP_INDX        = 0XC1,
    CMP_INDY        = 0XD1, //CPX
    CPX_IMM         = 0XE0,
    CPX_ZP          = 0XE4,
    CPX_ABS         = 0XEC, //CPY
    CPY_IMM         = 0XC0,
    CPY_ZP          = 0XC4,
    CPY_ABS         = 0XCC, //DEC
    DEC_ZP          = 0XC6,
    DEC_ZPX         = 0XD6,
    DEC_ABS         = 0XCE,
    DEC_ABSX        = 0XDE, //EOR
    EOR_IMM         = 0X49,
    EOR_ZP          = 0X45,
    EOR_ZPX         = 0X55,
    EOR_ABS         = 0X4D,
    EOR_ABSX        = 0X5D,
    EOR_ABSY        = 0X59,
    EOR_INDX        = 0X41,
    EOR_INDY        = 0X51, //INC
    INC_ZP          = 0XE6,
    INC_ZPX         = 0XF6,
    INC_ABS         = 0XEE,
    INC_ABSX        = 0XFE, //JMP
    JMP_ABS         = 0X4C,
    JMP_IND         = 0X6C, //JSR
    JSR_ABS         = 0X20, //LDA
    LDA_IMM         = 0XA9,
    LDA_ZP          = 0XA5,
    LDA_ZPX         = 0XB5,
    LDA_ABS         = 0XAD,
    LDA_ABSX        = 0XBD,
    LDA_ABSY        = 0XB9,
    LDA_INDX        = 0XA1,
    LDA_INDY        = 0XB1, //LDX
    LDX_IMM         = 0XA2,
    LDX_ZP          = 0XA6,
    LDX_ZPY         = 0XB6,
    LDX_ABS         = 0XAE,
    LDX_ABY         = 0XBE, //LDY
    LDY_IMM         = 0XA0,
    LDY_ZP          = 0XA4,
    LDY_ZPX         = 0XB4,
    LDY_ABS         = 0XAC,
    LDY_ABSX        = 0XBC, //LSR
    LSR_ACC         = 0X4A,
    LSR_ZP          = 0X46,
    LSR_ZPX         = 0X56,
    LSR_ABS         = 0X4E,
    LSR_ABSX        = 0X5E, //ORA
    ORA_IMM         = 0X09,
    ORA_ZP          = 0X05,
    ORA_ZPX         = 0X15,
    ORA_ABS         = 0X0D,
    ORA_ABSX        = 0X1D,
    ORA_ABSY        = 0X19,
    ORA_INDX        = 0X01,
    ORA_INDY        = 0X11, //ROL
    ROL_ACC         = 0X2A,
    ROL_ZP          = 0X26,
    ROL_ZPX         = 0X36,
    ROL_ABS         = 0X2E,
    ROL_ABSX        = 0X3E, //ROR
    ROR_ACC         = 0X6A,
    ROR_ZP          = 0X66,
    ROR_ZPX         = 0X76,
    ROR_ABS         = 0X6E,
    ROR_ABSX        = 0X7E, //SBC
    SBC_IMM         = 0XE9,
    SBC_ZP          = 0XE5,
    SBC_ZPX         = 0XF5,
    SBC_ABS         = 0XED,
    SBC_ABSX        = 0XFD,
    SBC_ABSY        = 0XF9,
    SBC_INDX        = 0XE1,
    SBC_INDY        = 0XF1, //STA
    STA_ZP          = 0X85,
    STA_ZPX         = 0X95,
    STA_ABS         = 0X8D,
    STA_ABSX        = 0X9D,
    STA_ABSY        = 0X99,
    STA_INDX        = 0X81,
    STA_INDY        = 0X91, //STX
    STX_ZP          = 0X86,
    STX_ZPY         = 0X96,
    STX_ABS         = 0X8E, //STY
    STY_ZP          = 0X84,
    STY_ZPX         = 0X94,
    STY_ABS         = 0X8C
    ;

    


#endif
