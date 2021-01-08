# MCU name
MCU = atmega32a

# Processor frequency
F_CPU = 16000000

# Bootloader selection
BOOTLOADER = USBasp

# build options
BOOTMAGIC_ENABLE = no
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = yes
KEY_LOCK_ENABLE = no
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
AUDIO_ENABLE = no

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

OPT_DEFS = -DDEBUG_LEVEL=0

# custom matrix setup
CUSTOM_MATRIX = yes
SRC = matrix.c

# programming options
PROGRAM_CMD = ./util/atmega32a_program.py $(TARGET).hex

LAYOUTS = ortho_4x12 planck_mit

ENCODER_ENABLE = yes