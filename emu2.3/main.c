#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* memory 1MB */
#define MEMORY_SIZE (1024 * 1024)

enum Register
{
	EAX,
	ECX,
	EDX,
	EBX,
	ESP,
	EBP, 
	ESI,
	EDI,
	REGISTERS_COUNT
};

char* registers_name[] = {
	"EAX", "ECX", "EDX", "EBX", "ESP", "EBP", "ESI", "EDI"
};

typedef struct {
	/* 汎用レジスタ */
	uint32_t registers[REGISTERS_COUNT];

	/* EFAGSレジスタ */
	uint32_t eflags;

	/* メモリ(バイト列) */
	uint8_t* memory;

	/* プログラムカウンタ */
	uint32_t eip;
} Emulator;

/* エミュレータを作成する */
static Emulator* create_emu(size_t size, uint32_t eip, uint32_t esp)
{
	Emulator* emu = malloc(sizeof(Emulator));
	emu->memory = malloc(size);

	/* 汎用レジスタの初期値を全て0にする */
	memset(emu->registers, 0, sizeof(emu->registers));

	/* レジスタの初期値を指定されたものにする */
	emu->eip = eip;
	emu->registers[ESP] = esp;

	return emu;
}

/* エミュレータを破棄する */
static void destory_emu(Emulator* emu)
{
	free(emu->memory);
	free(emu);
}
