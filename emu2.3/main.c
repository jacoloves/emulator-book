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
	/* �ėp���W�X�^ */
	uint32_t registers[REGISTERS_COUNT];

	/* EFAGS���W�X�^ */
	uint32_t eflags;

	/* ������(�o�C�g��) */
	uint8_t* memory;

	/* �v���O�����J�E���^ */
	uint32_t eip;
} Emulator;

/* �G�~�����[�^���쐬���� */
static Emulator* create_emu(size_t size, uint32_t eip, uint32_t esp)
{
	Emulator* emu = malloc(sizeof(Emulator));
	emu->memory = malloc(size);

	/* �ėp���W�X�^�̏����l��S��0�ɂ��� */
	memset(emu->registers, 0, sizeof(emu->registers));

	/* ���W�X�^�̏����l���w�肳�ꂽ���̂ɂ��� */
	emu->eip = eip;
	emu->registers[ESP] = esp;

	return emu;
}

/* �G�~�����[�^��j������ */
static void destory_emu(Emulator* emu)
{
	free(emu->memory);
	free(emu);
}
