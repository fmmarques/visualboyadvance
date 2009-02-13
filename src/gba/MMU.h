#ifndef MMU_H
#define MMU_H

#include "../common/Port.h"

u32 CPUReadMemory(u32 address);
u32 CPUReadHalfWord(u32 address);
u16 CPUReadHalfWordSigned(u32 address);
u8 CPUReadByte(u32 address);

void CPUWriteMemory(u32 address, u32 value);
void CPUWriteHalfWord(u32 address, u16 value);
void CPUWriteByte(u32 address, u8 b);

#endif // MMU_H