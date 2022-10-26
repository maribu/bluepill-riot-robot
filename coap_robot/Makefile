APPLICATION := coap_robot
BOARD := robodongle
RIOTBASE := $(CURDIR)/../RIOT
EXTERNAL_BOARD_DIRS := $(CURDIR)/../EXT_BOARDS
DEVELHELP ?= 1
QUIET ?= 1

USEMODULE += auto_init_gnrc_netif
USEMODULE += fmt
USEMODULE += gcoap
USEMODULE += gnrc
USEMODULE += gnrc_icmpv6_echo
USEMODULE += gnrc_ipv6
USEMODULE += gnrc_ipv6_default
USEMODULE += gnrc_netif_single
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
