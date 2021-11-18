MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control
NKRO_ENABLE		= yes # Enables N-key rollover

SRC += brooks.c # keymap

# select alternative base layer alphas
ifneq ($(strip $(ALPHAS)),)
  OPT_DEFS += -DALPHAS_$(ALPHAS)
endif

# select alternative subset mappings
ifneq ($(strip $(MAPPING)),)
  OPT_DEFS += -DMAPPING_$(MAPPING)
endif
