APPLICATION := testing_app
BOARD := robodongle
RIOTBASE := $(CURDIR)/../RIOT
EXTERNAL_BOARD_DIRS := $(CURDIR)/../EXT_BOARDS
DEVELHELP ?= 1
QUIET ?= 1

USEMODULE += auto_init_gnrc_netif
USEMODULE += gnrc
USEMODULE += gnrc_icmpv6_echo
USEMODULE += gnrc_ipv6
USEMODULE += gnrc_netif_single
USEMODULE += netdev_default
USEMODULE += ps
USEMODULE += saul_default
USEMODULE += shell
USEMODULE += shell_cmds_default

include $(RIOTBASE)/Makefile.include
