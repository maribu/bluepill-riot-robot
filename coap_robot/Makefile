APPLICATION := coap_robot
BOARD := robopill
RIOTBASE := $(CURDIR)/../RIOT
EXTERNAL_BOARD_DIRS := $(CURDIR)/../EXT_BOARDS
DEVELHELP ?= 1
QUIET ?= 1

USEMODULE += fmt
USEMODULE += gcoap
USEMODULE += gnrc_ipv6_default
USEMODULE += gnrc_sock_udp
USEMODULE += netdev_default
USEMODULE += netutils
USEMODULE += od
USEMODULE += ps
USEMODULE += random
USEMODULE += servo
USEMODULE += shell
USEMODULE += shell_cmds_default

include $(RIOTBASE)/Makefile.include
