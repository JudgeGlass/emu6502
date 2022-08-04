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

#include "bus.h"

typedef struct CPU
{
    uint8_t A;
    uint8_t X;
    uint8_t Y;
    uint8_t SP;
    uint16_t PC;
    uint8_t active;

} cpu_t;

typedef struct Flags{
    uint8_t NEGATIVE;           // N
    uint8_t OVERFLOW;           // V
    uint8_t BREAK;
    uint8_t DECIMAL_MODE;       // D
    uint8_t IRQ_DISABLED;       // I
    uint8_t ZERO;               // Z
    uint8_t CARRY;              // C
} flags_t;

void cpuInit();
void clock();
void execInstruction(uint8_t op);


cpu_t cpu;
flags_t flags;


#define   ADC_IMM           0X69//ADC
#define   ADC_ZP            0X65
#define   ADC_ZPX           0X75
#define    ADC_ABS          0X6D
#define    ADC_ABSX         0X7D
#define    ADC_ABSY         0X79
#define    ADC_INDX         0X61
#define    ADC_INDY         0X71
#define    AND_IMM          0X29 //AND
#define    AND_ZP           0X25
#define    AND_ZPX          0X35
#define    AND_ABS          0X2D
#define    AND_ABSX         0X3D
#define    AND_ABSY         0X39
#define    AND_INDX         0X21
#define    AND_INDY         0X31
#define    ASL_ACC          0X0A //ASL
#define    ASL_ZP           0X06
#define    ASL_ZPX          0X16
#define    ASL_ABS          0X0E
#define    ASL_ABSX         0X1E //BIT
#define    BIT_ZP           0X24
#define    BIT_ABS          0X2C //BRANCH INSTRUCTIONS
#define    BPL              0X10
#define    BMI              0X30
#define    BVC              0X50
#define    BVS              0X70
#define    BCC              0X90
#define    BCS              0XB0
#define    BNE              0XD0
#define    BEQ              0XF0 //FLAGS
#define    CLC              0X18
#define    SEC              0X38
#define    CLI              0X58
#define    SEI              0X78
#define    CLV              0XB8
#define    CLD              0XD8
#define    SED              0XF8 //REGISTER INSTRUCTIONS
#define    TAX              0XAA
#define    TXA              0X8A
#define    DEX              0XCA
#define    INX              0XE8
#define    TAY              0XA8
#define    TYA              0X98
#define    DEY              0X88
#define    INY              0XC8 //STACK INSTRUCTIONS
#define    TXS              0X94
#define    TSX              0XBA
#define    PHA              0X48
#define    PLA              0X68
#define    PHP              0X08
#define    PLP              0X28 //GENERAL
#define    BRK_IMP          0X00
#define    RTI_IMP          0X40
#define    RTS_IMP          0X60
#define    NOP              0XEA //CMP
#define    CMP_IMM          0XC9
#define    CMP_ZP           0XC5
#define    CMP_ZPX          0XD5
#define    CMP_ABS          0XCD
#define    CMP_ABSX         0XDD
#define    CMP_ABSY         0XD9
#define    CMP_INDX         0XC1
#define    CMP_INDY         0XD1 //CPX
#define    CPX_IMM          0XE0
#define    CPX_ZP           0XE4
#define    CPX_ABS          0XEC //CPY
#define    CPY_IMM          0XC0
#define    CPY_ZP           0XC4
#define    CPY_ABS          0XCC //DEC
#define    DEC_ZP           0XC6
#define    DEC_ZPX          0XD6
#define    DEC_ABS          0XCE
#define    DEC_ABSX         0XDE //EOR
#define    EOR_IMM          0X49
#define    EOR_ZP           0X45
#define    EOR_ZPX          0X55
#define    EOR_ABS          0X4D
#define    EOR_ABSX         0X5D
#define    EOR_ABSY         0X59
#define    EOR_INDX         0X41
#define    EOR_INDY         0X51 //INC
#define    INC_ZP           0XE6
#define    INC_ZPX          0XF6
#define    INC_ABS          0XEE
#define    INC_ABSX         0XFE //JMP
#define    JMP_ABS          0X4C
#define    JMP_IND          0X6C //JSR
#define    JSR_ABS          0X20 //LDA
#define    LDA_IMM          0XA9
#define    LDA_ZP           0XA5
#define    LDA_ZPX          0XB5
#define    LDA_ABS          0XAD
#define    LDA_ABSX         0XBD
#define    LDA_ABSY         0XB9
#define    LDA_INDX         0XA1
#define    LDA_INDY         0XB1 //LDX
#define    LDX_IMM          0XA2
#define    LDX_ZP           0XA6
#define    LDX_ZPY          0XB6
#define    LDX_ABS          0XAE
#define    LDX_ABSY         0XBE //LDY
#define    LDY_IMM          0XA0
#define    LDY_ZP           0XA4
#define    LDY_ZPX          0XB4
#define    LDY_ABS          0XAC
#define    LDY_ABSX         0XBC //LSR
#define    LSR_ACC          0X4A
#define    LSR_ZP           0X46
#define    LSR_ZPX          0X56
#define    LSR_ABS          0X4E
#define    LSR_ABSX         0X5E //ORA
#define    ORA_IMM          0X09
#define    ORA_ZP           0X05
#define    ORA_ZPX          0X15
#define    ORA_ABS          0X0D
#define    ORA_ABSX         0X1D
#define    ORA_ABSY         0X19
#define    ORA_INDX         0X01
#define    ORA_INDY         0X11 //ROL
#define    ROL_ACC          0X2A
#define    ROL_ZP           0X26
#define    ROL_ZPX          0X36
#define    ROL_ABS          0X2E
#define    ROL_ABSX         0X3E //ROR
#define    ROR_ACC          0X6A
#define    ROR_ZP           0X66
#define    ROR_ZPX          0X76
#define    ROR_ABS          0X6E
#define    ROR_ABSX         0X7E //SBC
#define    SBC_IMM          0XE9
#define    SBC_ZP           0XE5
#define    SBC_ZPX          0XF5
#define    SBC_ABS          0XED
#define    SBC_ABSX         0XFD
#define    SBC_ABSY         0XF9
#define    SBC_INDX         0XE1
#define    SBC_INDY         0XF1 //STA
#define    STA_ZP           0X85
#define    STA_ZPX          0X95
#define    STA_ABS          0X8D
#define    STA_ABSX         0X9D
#define    STA_ABSY         0X99
#define    STA_INDX         0X81
#define    STA_INDY         0X91 //STX
#define    STX_ZP           0X86
#define    STX_ZPY          0X96
#define    STX_ABS          0X8E //STY
#define    STY_ZP           0X84
#define    STY_ZPX          0X94
#define    STY_ABS          0X8C

static uint8_t getCycles(uint8_t op){
    switch (op)
    {
    
    
    case ADC_IMM:
    case AND_IMM:
    case ASL_ACC:
    case BPL:
    case BMI:
    case BVC:
    case BVS:
    case BCC:
    case BCS:
    case BNE:
    case BEQ:
    case CLC:
    case SEC:
    case CLI:
    case SEI:
    case CLV:
    case CLD:
    case SED:
    case CMP_IMM:
    case CPX_IMM:
    case CPY_IMM:
    case EOR_IMM:
    case LDA_IMM:
    case LDX_IMM:
    case LDY_IMM:
    case LSR_ACC:
    case NOP:
    case ORA_IMM:
    case TAX:
    case TXA:
    case DEX:
    case INX:
    case TAY:
    case TYA:
    case DEY:
    case INY:
    case ROL_ACC:
    case ROR_ACC:
    case SBC_IMM:
    case TXS:
    case TSX:
        return 2;

    case ADC_ZP:
    case AND_ZP:
    case BIT_ZP:
    case CMP_ZP:
    case CPX_ZP:
    case CPY_ZP:
    case EOR_ZP:
    case JMP_ABS:
    case LDA_ZP:
    case LDX_ZP:
    case LDY_ZP:
    case ORA_ZP:
    case SBC_ZP:
    case STA_ZP:
    case PHA:
    case PHP:
    case STX_ZP:
    case STY_ZP:
        return 3;

    case ADC_ABS:
    case ADC_ZPX:
    case ADC_ABSX:
    case ADC_ABSY:
    case AND_ZPX:
    case AND_ABS:
    case AND_ABSX:
    case AND_ABSY:
    case BIT_ABS:
    case CMP_ZPX:
    case CMP_ABS:
    case CMP_ABSX:
    case CMP_ABSY:
    case CPX_ABS:
    case CPY_ABS:
    case EOR_ZPX:
    case EOR_ABS:
    case EOR_ABSX:
    case EOR_ABSY:
    case LDA_ZPX:
    case LDA_ABS:
    case LDA_ABSX:
    case LDA_ABSY:
    case LDX_ZPY:
    case LDX_ABS:
    case LDX_ABSY:
    case LDY_ZPX:
    case LDY_ABS:
    case LDY_ABSX:
    case ORA_ZPX:
    case ORA_ABS:
    case ORA_ABSX:
    case ORA_ABSY:
    case SBC_ZPX:
    case SBC_ABS:
    case SBC_ABSX:
    case SBC_ABSY:
    case STA_ZPX:
    case STA_ABS:
    case PLA:
    case PLP:
    case STX_ZPY:
    case STX_ABS:
    //case STY_ZPX:
    case STY_ABS:
        return 4;

    case ADC_INDY:
    case AND_INDY:
    case ASL_ZP:
    case CMP_INDY:
    case DEC_ZP:
    case EOR_INDY:
    case INC_ZP:
    case JMP_IND:
    case LDA_INDY:
    case LSR_ZP:
    case ORA_INDY:
    case ROL_ZP:
    case ROR_ZP:
    case SBC_INDY:
    case STA_ABSX:
    case STA_ABSY:
        return 5;

    case ADC_INDX:
    case AND_INDX:
    case ASL_ZPX:
    case ASL_ABS:
    case CMP_INDX:
    case DEC_ZPX:
    case DEC_ABS:
    case EOR_INDX:
    case INC_ZPX:
    case INC_ABS:
    case JSR_ABS:
    case LDA_INDX:
    case LSR_ABS:
    case LSR_ZPX:
    case ORA_INDX:
    case ROL_ZPX:
    case ROL_ABS:
    case ROR_ZPX:
    case ROR_ABS:
    case RTI_IMP:
    case RTS_IMP:
    case SBC_INDX:
    case STA_INDX:
    case STA_INDY:
        return 6;

    case ASL_ABSX:
    case BRK_IMP:
    case DEC_ABSX:
    case INC_ABSX:
    case LSR_ABSX:
    case ROL_ABSX:
    case ROR_ABSX:
        return 7;
    
    default:
        return 0;
    }
}
    


#endif
