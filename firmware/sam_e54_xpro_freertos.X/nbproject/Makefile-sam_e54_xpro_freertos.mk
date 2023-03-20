#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-sam_e54_xpro_freertos.mk)" "nbproject/Makefile-local-sam_e54_xpro_freertos.mk"
include nbproject/Makefile-local-sam_e54_xpro_freertos.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=sam_e54_xpro_freertos
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/sam_e54_xpro_freertos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/sam_e54_xpro_freertos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_ethphy.c ../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_extphy_ksz8091.c ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac.c ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac_lib_samE5x.c ../src/config/sam_e54_xpro_freertos/driver/i2c/src/drv_i2c.c ../src/config/sam_e54_xpro_freertos/driver/miim/src/dynamic/drv_miim.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/helpers.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dns.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/icmp.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcp.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dhcp.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/arp.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/berkeley_api.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/ipv4.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_alloc.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_internal.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/hash_fnv.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/oahash.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_helpers.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_manager.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_notify.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_packet.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_announce.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/udp.c ../src/config/sam_e54_xpro_freertos/net_pres/pres/src/net_pres.c ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_enc_glue.c ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_cert_store.c ../src/config/sam_e54_xpro_freertos/peripheral/adc/plib_adc0.c ../src/config/sam_e54_xpro_freertos/peripheral/clock/plib_clock.c ../src/config/sam_e54_xpro_freertos/peripheral/cmcc/plib_cmcc.c ../src/config/sam_e54_xpro_freertos/peripheral/eic/plib_eic.c ../src/config/sam_e54_xpro_freertos/peripheral/evsys/plib_evsys.c ../src/config/sam_e54_xpro_freertos/peripheral/nvic/plib_nvic.c ../src/config/sam_e54_xpro_freertos/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/sam_e54_xpro_freertos/peripheral/pm/plib_pm.c ../src/config/sam_e54_xpro_freertos/peripheral/port/plib_port.c ../src/config/sam_e54_xpro_freertos/peripheral/rtc/plib_rtc_timer.c ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom3_i2c_master.c ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom7_i2c_master.c ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom2_usart.c ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom0_usart.c ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom5_usart.c ../src/config/sam_e54_xpro_freertos/peripheral/tc/plib_tc0.c ../src/config/sam_e54_xpro_freertos/peripheral/tcc/plib_tcc0.c ../src/config/sam_e54_xpro_freertos/stdio/xc32_monitor.c ../src/config/sam_e54_xpro_freertos/system/cache/sys_cache.c ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console_uart.c ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console.c ../src/config/sam_e54_xpro_freertos/system/debug/src/sys_debug.c ../src/config/sam_e54_xpro_freertos/system/int/src/sys_int.c ../src/config/sam_e54_xpro_freertos/system/time/src/sys_time.c ../src/config/sam_e54_xpro_freertos/system/sys_time_h2_adapter.c ../src/config/sam_e54_xpro_freertos/tasks.c ../src/config/sam_e54_xpro_freertos/initialization.c ../src/config/sam_e54_xpro_freertos/interrupts.c ../src/config/sam_e54_xpro_freertos/exceptions.c ../src/config/sam_e54_xpro_freertos/startup_xc32.c ../src/config/sam_e54_xpro_freertos/libc_syscalls.c ../src/config/sam_e54_xpro_freertos/freertos_hooks.c ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F/port.c ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_3.c ../src/third_party/rtos/FreeRTOS/Source/croutine.c ../src/third_party/rtos/FreeRTOS/Source/list.c ../src/third_party/rtos/FreeRTOS/Source/queue.c ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c ../src/third_party/rtos/FreeRTOS/Source/timers.c ../src/third_party/rtos/FreeRTOS/Source/event_groups.c ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c ../src/config/sam_e54_xpro_freertos/osal/osal_freertos.c ../src/cJSON.c ../src/com_lib.c ../src/netapp_lib.c ../src/shared_settings.c ../src/mcp9800.c ../src/OLED12864.c ../src/BH1750FVI.c ../src/lcw.c ../src/adc.c ../src/uart_command.c ../src/Judgeman.c ../src/eeprom.c ../src/app.c ../src/tcp_app.c ../src/uart_app.c ../src/rs232_app.c ../src/judgeman_app.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/234661171/drv_ethphy.o ${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o ${OBJECTDIR}/_ext/125405427/drv_gmac.o ${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o ${OBJECTDIR}/_ext/865364553/drv_i2c.o ${OBJECTDIR}/_ext/1233363243/drv_miim.o ${OBJECTDIR}/_ext/1925797400/helpers.o ${OBJECTDIR}/_ext/1925797400/dns.o ${OBJECTDIR}/_ext/1925797400/icmp.o ${OBJECTDIR}/_ext/1925797400/tcp.o ${OBJECTDIR}/_ext/1925797400/dhcp.o ${OBJECTDIR}/_ext/1925797400/arp.o ${OBJECTDIR}/_ext/1925797400/berkeley_api.o ${OBJECTDIR}/_ext/1925797400/ipv4.o ${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o ${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o ${OBJECTDIR}/_ext/1925797400/hash_fnv.o ${OBJECTDIR}/_ext/1925797400/oahash.o ${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o ${OBJECTDIR}/_ext/1925797400/tcpip_manager.o ${OBJECTDIR}/_ext/1925797400/tcpip_notify.o ${OBJECTDIR}/_ext/1925797400/tcpip_packet.o ${OBJECTDIR}/_ext/1925797400/tcpip_announce.o ${OBJECTDIR}/_ext/1925797400/udp.o ${OBJECTDIR}/_ext/615292289/net_pres.o ${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o ${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o ${OBJECTDIR}/_ext/767142862/plib_adc0.o ${OBJECTDIR}/_ext/1507984452/plib_clock.o ${OBJECTDIR}/_ext/1988306724/plib_cmcc.o ${OBJECTDIR}/_ext/767146861/plib_eic.o ${OBJECTDIR}/_ext/1505834966/plib_evsys.o ${OBJECTDIR}/_ext/1987970188/plib_nvic.o ${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o ${OBJECTDIR}/_ext/301841679/plib_pm.o ${OBJECTDIR}/_ext/1987917037/plib_port.o ${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o ${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o ${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o ${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o ${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o ${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o ${OBJECTDIR}/_ext/301841793/plib_tc0.o ${OBJECTDIR}/_ext/767161090/plib_tcc0.o ${OBJECTDIR}/_ext/1041620184/xc32_monitor.o ${OBJECTDIR}/_ext/1947381213/sys_cache.o ${OBJECTDIR}/_ext/557048589/sys_console_uart.o ${OBJECTDIR}/_ext/557048589/sys_console.o ${OBJECTDIR}/_ext/1747368521/sys_debug.o ${OBJECTDIR}/_ext/1706319323/sys_int.o ${OBJECTDIR}/_ext/339643745/sys_time.o ${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o ${OBJECTDIR}/_ext/651216402/tasks.o ${OBJECTDIR}/_ext/651216402/initialization.o ${OBJECTDIR}/_ext/651216402/interrupts.o ${OBJECTDIR}/_ext/651216402/exceptions.o ${OBJECTDIR}/_ext/651216402/startup_xc32.o ${OBJECTDIR}/_ext/651216402/libc_syscalls.o ${OBJECTDIR}/_ext/651216402/freertos_hooks.o ${OBJECTDIR}/_ext/246609638/port.o ${OBJECTDIR}/_ext/1665200909/heap_3.o ${OBJECTDIR}/_ext/404212886/croutine.o ${OBJECTDIR}/_ext/404212886/list.o ${OBJECTDIR}/_ext/404212886/queue.o ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o ${OBJECTDIR}/_ext/404212886/timers.o ${OBJECTDIR}/_ext/404212886/event_groups.o ${OBJECTDIR}/_ext/404212886/stream_buffer.o ${OBJECTDIR}/_ext/1767394448/osal_freertos.o ${OBJECTDIR}/_ext/1360937237/cJSON.o ${OBJECTDIR}/_ext/1360937237/com_lib.o ${OBJECTDIR}/_ext/1360937237/netapp_lib.o ${OBJECTDIR}/_ext/1360937237/shared_settings.o ${OBJECTDIR}/_ext/1360937237/mcp9800.o ${OBJECTDIR}/_ext/1360937237/OLED12864.o ${OBJECTDIR}/_ext/1360937237/BH1750FVI.o ${OBJECTDIR}/_ext/1360937237/lcw.o ${OBJECTDIR}/_ext/1360937237/adc.o ${OBJECTDIR}/_ext/1360937237/uart_command.o ${OBJECTDIR}/_ext/1360937237/Judgeman.o ${OBJECTDIR}/_ext/1360937237/eeprom.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/tcp_app.o ${OBJECTDIR}/_ext/1360937237/uart_app.o ${OBJECTDIR}/_ext/1360937237/rs232_app.o ${OBJECTDIR}/_ext/1360937237/judgeman_app.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/234661171/drv_ethphy.o.d ${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o.d ${OBJECTDIR}/_ext/125405427/drv_gmac.o.d ${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o.d ${OBJECTDIR}/_ext/865364553/drv_i2c.o.d ${OBJECTDIR}/_ext/1233363243/drv_miim.o.d ${OBJECTDIR}/_ext/1925797400/helpers.o.d ${OBJECTDIR}/_ext/1925797400/dns.o.d ${OBJECTDIR}/_ext/1925797400/icmp.o.d ${OBJECTDIR}/_ext/1925797400/tcp.o.d ${OBJECTDIR}/_ext/1925797400/dhcp.o.d ${OBJECTDIR}/_ext/1925797400/arp.o.d ${OBJECTDIR}/_ext/1925797400/berkeley_api.o.d ${OBJECTDIR}/_ext/1925797400/ipv4.o.d ${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o.d ${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o.d ${OBJECTDIR}/_ext/1925797400/hash_fnv.o.d ${OBJECTDIR}/_ext/1925797400/oahash.o.d ${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o.d ${OBJECTDIR}/_ext/1925797400/tcpip_manager.o.d ${OBJECTDIR}/_ext/1925797400/tcpip_notify.o.d ${OBJECTDIR}/_ext/1925797400/tcpip_packet.o.d ${OBJECTDIR}/_ext/1925797400/tcpip_announce.o.d ${OBJECTDIR}/_ext/1925797400/udp.o.d ${OBJECTDIR}/_ext/615292289/net_pres.o.d ${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o.d ${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o.d ${OBJECTDIR}/_ext/767142862/plib_adc0.o.d ${OBJECTDIR}/_ext/1507984452/plib_clock.o.d ${OBJECTDIR}/_ext/1988306724/plib_cmcc.o.d ${OBJECTDIR}/_ext/767146861/plib_eic.o.d ${OBJECTDIR}/_ext/1505834966/plib_evsys.o.d ${OBJECTDIR}/_ext/1987970188/plib_nvic.o.d ${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o.d ${OBJECTDIR}/_ext/301841679/plib_pm.o.d ${OBJECTDIR}/_ext/1987917037/plib_port.o.d ${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o.d ${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o.d ${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o.d ${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o.d ${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o.d ${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o.d ${OBJECTDIR}/_ext/301841793/plib_tc0.o.d ${OBJECTDIR}/_ext/767161090/plib_tcc0.o.d ${OBJECTDIR}/_ext/1041620184/xc32_monitor.o.d ${OBJECTDIR}/_ext/1947381213/sys_cache.o.d ${OBJECTDIR}/_ext/557048589/sys_console_uart.o.d ${OBJECTDIR}/_ext/557048589/sys_console.o.d ${OBJECTDIR}/_ext/1747368521/sys_debug.o.d ${OBJECTDIR}/_ext/1706319323/sys_int.o.d ${OBJECTDIR}/_ext/339643745/sys_time.o.d ${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o.d ${OBJECTDIR}/_ext/651216402/tasks.o.d ${OBJECTDIR}/_ext/651216402/initialization.o.d ${OBJECTDIR}/_ext/651216402/interrupts.o.d ${OBJECTDIR}/_ext/651216402/exceptions.o.d ${OBJECTDIR}/_ext/651216402/startup_xc32.o.d ${OBJECTDIR}/_ext/651216402/libc_syscalls.o.d ${OBJECTDIR}/_ext/651216402/freertos_hooks.o.d ${OBJECTDIR}/_ext/246609638/port.o.d ${OBJECTDIR}/_ext/1665200909/heap_3.o.d ${OBJECTDIR}/_ext/404212886/croutine.o.d ${OBJECTDIR}/_ext/404212886/list.o.d ${OBJECTDIR}/_ext/404212886/queue.o.d ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d ${OBJECTDIR}/_ext/404212886/timers.o.d ${OBJECTDIR}/_ext/404212886/event_groups.o.d ${OBJECTDIR}/_ext/404212886/stream_buffer.o.d ${OBJECTDIR}/_ext/1767394448/osal_freertos.o.d ${OBJECTDIR}/_ext/1360937237/cJSON.o.d ${OBJECTDIR}/_ext/1360937237/com_lib.o.d ${OBJECTDIR}/_ext/1360937237/netapp_lib.o.d ${OBJECTDIR}/_ext/1360937237/shared_settings.o.d ${OBJECTDIR}/_ext/1360937237/mcp9800.o.d ${OBJECTDIR}/_ext/1360937237/OLED12864.o.d ${OBJECTDIR}/_ext/1360937237/BH1750FVI.o.d ${OBJECTDIR}/_ext/1360937237/lcw.o.d ${OBJECTDIR}/_ext/1360937237/adc.o.d ${OBJECTDIR}/_ext/1360937237/uart_command.o.d ${OBJECTDIR}/_ext/1360937237/Judgeman.o.d ${OBJECTDIR}/_ext/1360937237/eeprom.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/tcp_app.o.d ${OBJECTDIR}/_ext/1360937237/uart_app.o.d ${OBJECTDIR}/_ext/1360937237/rs232_app.o.d ${OBJECTDIR}/_ext/1360937237/judgeman_app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/234661171/drv_ethphy.o ${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o ${OBJECTDIR}/_ext/125405427/drv_gmac.o ${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o ${OBJECTDIR}/_ext/865364553/drv_i2c.o ${OBJECTDIR}/_ext/1233363243/drv_miim.o ${OBJECTDIR}/_ext/1925797400/helpers.o ${OBJECTDIR}/_ext/1925797400/dns.o ${OBJECTDIR}/_ext/1925797400/icmp.o ${OBJECTDIR}/_ext/1925797400/tcp.o ${OBJECTDIR}/_ext/1925797400/dhcp.o ${OBJECTDIR}/_ext/1925797400/arp.o ${OBJECTDIR}/_ext/1925797400/berkeley_api.o ${OBJECTDIR}/_ext/1925797400/ipv4.o ${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o ${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o ${OBJECTDIR}/_ext/1925797400/hash_fnv.o ${OBJECTDIR}/_ext/1925797400/oahash.o ${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o ${OBJECTDIR}/_ext/1925797400/tcpip_manager.o ${OBJECTDIR}/_ext/1925797400/tcpip_notify.o ${OBJECTDIR}/_ext/1925797400/tcpip_packet.o ${OBJECTDIR}/_ext/1925797400/tcpip_announce.o ${OBJECTDIR}/_ext/1925797400/udp.o ${OBJECTDIR}/_ext/615292289/net_pres.o ${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o ${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o ${OBJECTDIR}/_ext/767142862/plib_adc0.o ${OBJECTDIR}/_ext/1507984452/plib_clock.o ${OBJECTDIR}/_ext/1988306724/plib_cmcc.o ${OBJECTDIR}/_ext/767146861/plib_eic.o ${OBJECTDIR}/_ext/1505834966/plib_evsys.o ${OBJECTDIR}/_ext/1987970188/plib_nvic.o ${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o ${OBJECTDIR}/_ext/301841679/plib_pm.o ${OBJECTDIR}/_ext/1987917037/plib_port.o ${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o ${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o ${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o ${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o ${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o ${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o ${OBJECTDIR}/_ext/301841793/plib_tc0.o ${OBJECTDIR}/_ext/767161090/plib_tcc0.o ${OBJECTDIR}/_ext/1041620184/xc32_monitor.o ${OBJECTDIR}/_ext/1947381213/sys_cache.o ${OBJECTDIR}/_ext/557048589/sys_console_uart.o ${OBJECTDIR}/_ext/557048589/sys_console.o ${OBJECTDIR}/_ext/1747368521/sys_debug.o ${OBJECTDIR}/_ext/1706319323/sys_int.o ${OBJECTDIR}/_ext/339643745/sys_time.o ${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o ${OBJECTDIR}/_ext/651216402/tasks.o ${OBJECTDIR}/_ext/651216402/initialization.o ${OBJECTDIR}/_ext/651216402/interrupts.o ${OBJECTDIR}/_ext/651216402/exceptions.o ${OBJECTDIR}/_ext/651216402/startup_xc32.o ${OBJECTDIR}/_ext/651216402/libc_syscalls.o ${OBJECTDIR}/_ext/651216402/freertos_hooks.o ${OBJECTDIR}/_ext/246609638/port.o ${OBJECTDIR}/_ext/1665200909/heap_3.o ${OBJECTDIR}/_ext/404212886/croutine.o ${OBJECTDIR}/_ext/404212886/list.o ${OBJECTDIR}/_ext/404212886/queue.o ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o ${OBJECTDIR}/_ext/404212886/timers.o ${OBJECTDIR}/_ext/404212886/event_groups.o ${OBJECTDIR}/_ext/404212886/stream_buffer.o ${OBJECTDIR}/_ext/1767394448/osal_freertos.o ${OBJECTDIR}/_ext/1360937237/cJSON.o ${OBJECTDIR}/_ext/1360937237/com_lib.o ${OBJECTDIR}/_ext/1360937237/netapp_lib.o ${OBJECTDIR}/_ext/1360937237/shared_settings.o ${OBJECTDIR}/_ext/1360937237/mcp9800.o ${OBJECTDIR}/_ext/1360937237/OLED12864.o ${OBJECTDIR}/_ext/1360937237/BH1750FVI.o ${OBJECTDIR}/_ext/1360937237/lcw.o ${OBJECTDIR}/_ext/1360937237/adc.o ${OBJECTDIR}/_ext/1360937237/uart_command.o ${OBJECTDIR}/_ext/1360937237/Judgeman.o ${OBJECTDIR}/_ext/1360937237/eeprom.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/tcp_app.o ${OBJECTDIR}/_ext/1360937237/uart_app.o ${OBJECTDIR}/_ext/1360937237/rs232_app.o ${OBJECTDIR}/_ext/1360937237/judgeman_app.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_ethphy.c ../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_extphy_ksz8091.c ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac.c ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac_lib_samE5x.c ../src/config/sam_e54_xpro_freertos/driver/i2c/src/drv_i2c.c ../src/config/sam_e54_xpro_freertos/driver/miim/src/dynamic/drv_miim.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/helpers.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dns.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/icmp.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcp.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dhcp.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/arp.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/berkeley_api.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/ipv4.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_alloc.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_internal.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/hash_fnv.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/oahash.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_helpers.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_manager.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_notify.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_packet.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_announce.c ../src/config/sam_e54_xpro_freertos/library/tcpip/src/udp.c ../src/config/sam_e54_xpro_freertos/net_pres/pres/src/net_pres.c ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_enc_glue.c ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_cert_store.c ../src/config/sam_e54_xpro_freertos/peripheral/adc/plib_adc0.c ../src/config/sam_e54_xpro_freertos/peripheral/clock/plib_clock.c ../src/config/sam_e54_xpro_freertos/peripheral/cmcc/plib_cmcc.c ../src/config/sam_e54_xpro_freertos/peripheral/eic/plib_eic.c ../src/config/sam_e54_xpro_freertos/peripheral/evsys/plib_evsys.c ../src/config/sam_e54_xpro_freertos/peripheral/nvic/plib_nvic.c ../src/config/sam_e54_xpro_freertos/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/sam_e54_xpro_freertos/peripheral/pm/plib_pm.c ../src/config/sam_e54_xpro_freertos/peripheral/port/plib_port.c ../src/config/sam_e54_xpro_freertos/peripheral/rtc/plib_rtc_timer.c ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom3_i2c_master.c ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom7_i2c_master.c ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom2_usart.c ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom0_usart.c ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom5_usart.c ../src/config/sam_e54_xpro_freertos/peripheral/tc/plib_tc0.c ../src/config/sam_e54_xpro_freertos/peripheral/tcc/plib_tcc0.c ../src/config/sam_e54_xpro_freertos/stdio/xc32_monitor.c ../src/config/sam_e54_xpro_freertos/system/cache/sys_cache.c ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console_uart.c ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console.c ../src/config/sam_e54_xpro_freertos/system/debug/src/sys_debug.c ../src/config/sam_e54_xpro_freertos/system/int/src/sys_int.c ../src/config/sam_e54_xpro_freertos/system/time/src/sys_time.c ../src/config/sam_e54_xpro_freertos/system/sys_time_h2_adapter.c ../src/config/sam_e54_xpro_freertos/tasks.c ../src/config/sam_e54_xpro_freertos/initialization.c ../src/config/sam_e54_xpro_freertos/interrupts.c ../src/config/sam_e54_xpro_freertos/exceptions.c ../src/config/sam_e54_xpro_freertos/startup_xc32.c ../src/config/sam_e54_xpro_freertos/libc_syscalls.c ../src/config/sam_e54_xpro_freertos/freertos_hooks.c ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F/port.c ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_3.c ../src/third_party/rtos/FreeRTOS/Source/croutine.c ../src/third_party/rtos/FreeRTOS/Source/list.c ../src/third_party/rtos/FreeRTOS/Source/queue.c ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c ../src/third_party/rtos/FreeRTOS/Source/timers.c ../src/third_party/rtos/FreeRTOS/Source/event_groups.c ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c ../src/config/sam_e54_xpro_freertos/osal/osal_freertos.c ../src/cJSON.c ../src/com_lib.c ../src/netapp_lib.c ../src/shared_settings.c ../src/mcp9800.c ../src/OLED12864.c ../src/BH1750FVI.c ../src/lcw.c ../src/adc.c ../src/uart_command.c ../src/Judgeman.c ../src/eeprom.c ../src/app.c ../src/tcp_app.c ../src/uart_app.c ../src/rs232_app.c ../src/judgeman_app.c ../src/main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-sam_e54_xpro_freertos.mk dist/${CND_CONF}/${IMAGE_TYPE}/sam_e54_xpro_freertos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATSAME54P20A
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/234661171/drv_ethphy.o: ../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_ethphy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/234661171" 
	@${RM} ${OBJECTDIR}/_ext/234661171/drv_ethphy.o.d 
	@${RM} ${OBJECTDIR}/_ext/234661171/drv_ethphy.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/234661171/drv_ethphy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/234661171/drv_ethphy.o.d" -o ${OBJECTDIR}/_ext/234661171/drv_ethphy.o ../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_ethphy.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o: ../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_extphy_ksz8091.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/234661171" 
	@${RM} ${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o.d 
	@${RM} ${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o.d" -o ${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o ../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_extphy_ksz8091.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/125405427/drv_gmac.o: ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/125405427" 
	@${RM} ${OBJECTDIR}/_ext/125405427/drv_gmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/125405427/drv_gmac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/125405427/drv_gmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/125405427/drv_gmac.o.d" -o ${OBJECTDIR}/_ext/125405427/drv_gmac.o ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o: ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac_lib_samE5x.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/125405427" 
	@${RM} ${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o.d 
	@${RM} ${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o.d" -o ${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac_lib_samE5x.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/865364553/drv_i2c.o: ../src/config/sam_e54_xpro_freertos/driver/i2c/src/drv_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/865364553" 
	@${RM} ${OBJECTDIR}/_ext/865364553/drv_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/865364553/drv_i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/865364553/drv_i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/865364553/drv_i2c.o.d" -o ${OBJECTDIR}/_ext/865364553/drv_i2c.o ../src/config/sam_e54_xpro_freertos/driver/i2c/src/drv_i2c.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1233363243/drv_miim.o: ../src/config/sam_e54_xpro_freertos/driver/miim/src/dynamic/drv_miim.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1233363243" 
	@${RM} ${OBJECTDIR}/_ext/1233363243/drv_miim.o.d 
	@${RM} ${OBJECTDIR}/_ext/1233363243/drv_miim.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1233363243/drv_miim.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1233363243/drv_miim.o.d" -o ${OBJECTDIR}/_ext/1233363243/drv_miim.o ../src/config/sam_e54_xpro_freertos/driver/miim/src/dynamic/drv_miim.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/helpers.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/helpers.o.d" -o ${OBJECTDIR}/_ext/1925797400/helpers.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/helpers.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/dns.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/dns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/dns.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/dns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/dns.o.d" -o ${OBJECTDIR}/_ext/1925797400/dns.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dns.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/icmp.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/icmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/icmp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/icmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/icmp.o.d" -o ${OBJECTDIR}/_ext/1925797400/icmp.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/icmp.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcp.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcp.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcp.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcp.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/dhcp.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dhcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/dhcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/dhcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/dhcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/dhcp.o.d" -o ${OBJECTDIR}/_ext/1925797400/dhcp.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dhcp.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/arp.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/arp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/arp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/arp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/arp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/arp.o.d" -o ${OBJECTDIR}/_ext/1925797400/arp.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/arp.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/berkeley_api.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/berkeley_api.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/berkeley_api.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/berkeley_api.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/berkeley_api.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/berkeley_api.o.d" -o ${OBJECTDIR}/_ext/1925797400/berkeley_api.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/berkeley_api.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/ipv4.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/ipv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/ipv4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/ipv4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/ipv4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/ipv4.o.d" -o ${OBJECTDIR}/_ext/1925797400/ipv4.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/ipv4.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_alloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_alloc.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_internal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_internal.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/hash_fnv.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/hash_fnv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/hash_fnv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/hash_fnv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/hash_fnv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/hash_fnv.o.d" -o ${OBJECTDIR}/_ext/1925797400/hash_fnv.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/hash_fnv.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/oahash.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/oahash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/oahash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/oahash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/oahash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/oahash.o.d" -o ${OBJECTDIR}/_ext/1925797400/oahash.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/oahash.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_helpers.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_manager.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_manager.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_manager.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_manager.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_notify.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_notify.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_notify.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_notify.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_notify.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_notify.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_notify.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_notify.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_packet.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_packet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_packet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_packet.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_packet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_packet.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_packet.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_packet.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_announce.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_announce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_announce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_announce.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_announce.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_announce.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/udp.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/udp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/udp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/udp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/udp.o.d" -o ${OBJECTDIR}/_ext/1925797400/udp.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/udp.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/615292289/net_pres.o: ../src/config/sam_e54_xpro_freertos/net_pres/pres/src/net_pres.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/615292289" 
	@${RM} ${OBJECTDIR}/_ext/615292289/net_pres.o.d 
	@${RM} ${OBJECTDIR}/_ext/615292289/net_pres.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/615292289/net_pres.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/615292289/net_pres.o.d" -o ${OBJECTDIR}/_ext/615292289/net_pres.o ../src/config/sam_e54_xpro_freertos/net_pres/pres/src/net_pres.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o: ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_enc_glue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/509249492" 
	@${RM} ${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o.d 
	@${RM} ${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o.d" -o ${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_enc_glue.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o: ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_cert_store.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/509249492" 
	@${RM} ${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o.d 
	@${RM} ${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o.d" -o ${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_cert_store.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/767142862/plib_adc0.o: ../src/config/sam_e54_xpro_freertos/peripheral/adc/plib_adc0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/767142862" 
	@${RM} ${OBJECTDIR}/_ext/767142862/plib_adc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/767142862/plib_adc0.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767142862/plib_adc0.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/767142862/plib_adc0.o.d" -o ${OBJECTDIR}/_ext/767142862/plib_adc0.o ../src/config/sam_e54_xpro_freertos/peripheral/adc/plib_adc0.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1507984452/plib_clock.o: ../src/config/sam_e54_xpro_freertos/peripheral/clock/plib_clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1507984452" 
	@${RM} ${OBJECTDIR}/_ext/1507984452/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1507984452/plib_clock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1507984452/plib_clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1507984452/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1507984452/plib_clock.o ../src/config/sam_e54_xpro_freertos/peripheral/clock/plib_clock.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1988306724/plib_cmcc.o: ../src/config/sam_e54_xpro_freertos/peripheral/cmcc/plib_cmcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1988306724" 
	@${RM} ${OBJECTDIR}/_ext/1988306724/plib_cmcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1988306724/plib_cmcc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1988306724/plib_cmcc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1988306724/plib_cmcc.o.d" -o ${OBJECTDIR}/_ext/1988306724/plib_cmcc.o ../src/config/sam_e54_xpro_freertos/peripheral/cmcc/plib_cmcc.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/767146861/plib_eic.o: ../src/config/sam_e54_xpro_freertos/peripheral/eic/plib_eic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/767146861" 
	@${RM} ${OBJECTDIR}/_ext/767146861/plib_eic.o.d 
	@${RM} ${OBJECTDIR}/_ext/767146861/plib_eic.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767146861/plib_eic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/767146861/plib_eic.o.d" -o ${OBJECTDIR}/_ext/767146861/plib_eic.o ../src/config/sam_e54_xpro_freertos/peripheral/eic/plib_eic.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1505834966/plib_evsys.o: ../src/config/sam_e54_xpro_freertos/peripheral/evsys/plib_evsys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1505834966" 
	@${RM} ${OBJECTDIR}/_ext/1505834966/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1505834966/plib_evsys.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1505834966/plib_evsys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1505834966/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1505834966/plib_evsys.o ../src/config/sam_e54_xpro_freertos/peripheral/evsys/plib_evsys.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1987970188/plib_nvic.o: ../src/config/sam_e54_xpro_freertos/peripheral/nvic/plib_nvic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1987970188" 
	@${RM} ${OBJECTDIR}/_ext/1987970188/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1987970188/plib_nvic.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1987970188/plib_nvic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1987970188/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1987970188/plib_nvic.o ../src/config/sam_e54_xpro_freertos/peripheral/nvic/plib_nvic.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o: ../src/config/sam_e54_xpro_freertos/peripheral/nvmctrl/plib_nvmctrl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/312016962" 
	@${RM} ${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o ../src/config/sam_e54_xpro_freertos/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/301841679/plib_pm.o: ../src/config/sam_e54_xpro_freertos/peripheral/pm/plib_pm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/301841679" 
	@${RM} ${OBJECTDIR}/_ext/301841679/plib_pm.o.d 
	@${RM} ${OBJECTDIR}/_ext/301841679/plib_pm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/301841679/plib_pm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/301841679/plib_pm.o.d" -o ${OBJECTDIR}/_ext/301841679/plib_pm.o ../src/config/sam_e54_xpro_freertos/peripheral/pm/plib_pm.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1987917037/plib_port.o: ../src/config/sam_e54_xpro_freertos/peripheral/port/plib_port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1987917037" 
	@${RM} ${OBJECTDIR}/_ext/1987917037/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1987917037/plib_port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1987917037/plib_port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1987917037/plib_port.o.d" -o ${OBJECTDIR}/_ext/1987917037/plib_port.o ../src/config/sam_e54_xpro_freertos/peripheral/port/plib_port.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o: ../src/config/sam_e54_xpro_freertos/peripheral/rtc/plib_rtc_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/767159695" 
	@${RM} ${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o.d" -o ${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o ../src/config/sam_e54_xpro_freertos/peripheral/rtc/plib_rtc_timer.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o: ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom3_i2c_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/89900541" 
	@${RM} ${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o.d" -o ${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom3_i2c_master.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o: ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom7_i2c_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/89900541" 
	@${RM} ${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o.d" -o ${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom7_i2c_master.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o: ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom2_usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2118479575" 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o.d" -o ${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom2_usart.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o: ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom0_usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2118479575" 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o.d" -o ${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom0_usart.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o: ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom5_usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2118479575" 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o.d" -o ${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom5_usart.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/301841793/plib_tc0.o: ../src/config/sam_e54_xpro_freertos/peripheral/tc/plib_tc0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/301841793" 
	@${RM} ${OBJECTDIR}/_ext/301841793/plib_tc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/301841793/plib_tc0.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/301841793/plib_tc0.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/301841793/plib_tc0.o.d" -o ${OBJECTDIR}/_ext/301841793/plib_tc0.o ../src/config/sam_e54_xpro_freertos/peripheral/tc/plib_tc0.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/767161090/plib_tcc0.o: ../src/config/sam_e54_xpro_freertos/peripheral/tcc/plib_tcc0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/767161090" 
	@${RM} ${OBJECTDIR}/_ext/767161090/plib_tcc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/767161090/plib_tcc0.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767161090/plib_tcc0.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/767161090/plib_tcc0.o.d" -o ${OBJECTDIR}/_ext/767161090/plib_tcc0.o ../src/config/sam_e54_xpro_freertos/peripheral/tcc/plib_tcc0.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1041620184/xc32_monitor.o: ../src/config/sam_e54_xpro_freertos/stdio/xc32_monitor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1041620184" 
	@${RM} ${OBJECTDIR}/_ext/1041620184/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1041620184/xc32_monitor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1041620184/xc32_monitor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1041620184/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/1041620184/xc32_monitor.o ../src/config/sam_e54_xpro_freertos/stdio/xc32_monitor.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1947381213/sys_cache.o: ../src/config/sam_e54_xpro_freertos/system/cache/sys_cache.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1947381213" 
	@${RM} ${OBJECTDIR}/_ext/1947381213/sys_cache.o.d 
	@${RM} ${OBJECTDIR}/_ext/1947381213/sys_cache.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1947381213/sys_cache.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1947381213/sys_cache.o.d" -o ${OBJECTDIR}/_ext/1947381213/sys_cache.o ../src/config/sam_e54_xpro_freertos/system/cache/sys_cache.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/557048589/sys_console_uart.o: ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/557048589" 
	@${RM} ${OBJECTDIR}/_ext/557048589/sys_console_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/557048589/sys_console_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/557048589/sys_console_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/557048589/sys_console_uart.o.d" -o ${OBJECTDIR}/_ext/557048589/sys_console_uart.o ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console_uart.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/557048589/sys_console.o: ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/557048589" 
	@${RM} ${OBJECTDIR}/_ext/557048589/sys_console.o.d 
	@${RM} ${OBJECTDIR}/_ext/557048589/sys_console.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/557048589/sys_console.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/557048589/sys_console.o.d" -o ${OBJECTDIR}/_ext/557048589/sys_console.o ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1747368521/sys_debug.o: ../src/config/sam_e54_xpro_freertos/system/debug/src/sys_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1747368521" 
	@${RM} ${OBJECTDIR}/_ext/1747368521/sys_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1747368521/sys_debug.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1747368521/sys_debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1747368521/sys_debug.o.d" -o ${OBJECTDIR}/_ext/1747368521/sys_debug.o ../src/config/sam_e54_xpro_freertos/system/debug/src/sys_debug.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1706319323/sys_int.o: ../src/config/sam_e54_xpro_freertos/system/int/src/sys_int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1706319323" 
	@${RM} ${OBJECTDIR}/_ext/1706319323/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706319323/sys_int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1706319323/sys_int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1706319323/sys_int.o.d" -o ${OBJECTDIR}/_ext/1706319323/sys_int.o ../src/config/sam_e54_xpro_freertos/system/int/src/sys_int.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/339643745/sys_time.o: ../src/config/sam_e54_xpro_freertos/system/time/src/sys_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/339643745" 
	@${RM} ${OBJECTDIR}/_ext/339643745/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/339643745/sys_time.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/339643745/sys_time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/339643745/sys_time.o.d" -o ${OBJECTDIR}/_ext/339643745/sys_time.o ../src/config/sam_e54_xpro_freertos/system/time/src/sys_time.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o: ../src/config/sam_e54_xpro_freertos/system/sys_time_h2_adapter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2074587504" 
	@${RM} ${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o.d" -o ${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o ../src/config/sam_e54_xpro_freertos/system/sys_time_h2_adapter.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/tasks.o: ../src/config/sam_e54_xpro_freertos/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/tasks.o.d" -o ${OBJECTDIR}/_ext/651216402/tasks.o ../src/config/sam_e54_xpro_freertos/tasks.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/initialization.o: ../src/config/sam_e54_xpro_freertos/initialization.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/initialization.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/initialization.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/initialization.o.d" -o ${OBJECTDIR}/_ext/651216402/initialization.o ../src/config/sam_e54_xpro_freertos/initialization.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/interrupts.o: ../src/config/sam_e54_xpro_freertos/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/interrupts.o.d" -o ${OBJECTDIR}/_ext/651216402/interrupts.o ../src/config/sam_e54_xpro_freertos/interrupts.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/exceptions.o: ../src/config/sam_e54_xpro_freertos/exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/exceptions.o.d" -o ${OBJECTDIR}/_ext/651216402/exceptions.o ../src/config/sam_e54_xpro_freertos/exceptions.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/startup_xc32.o: ../src/config/sam_e54_xpro_freertos/startup_xc32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/startup_xc32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/startup_xc32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/651216402/startup_xc32.o ../src/config/sam_e54_xpro_freertos/startup_xc32.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/libc_syscalls.o: ../src/config/sam_e54_xpro_freertos/libc_syscalls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/libc_syscalls.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/libc_syscalls.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/651216402/libc_syscalls.o ../src/config/sam_e54_xpro_freertos/libc_syscalls.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/freertos_hooks.o: ../src/config/sam_e54_xpro_freertos/freertos_hooks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/freertos_hooks.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/freertos_hooks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/freertos_hooks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/freertos_hooks.o.d" -o ${OBJECTDIR}/_ext/651216402/freertos_hooks.o ../src/config/sam_e54_xpro_freertos/freertos_hooks.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/246609638/port.o: ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/246609638" 
	@${RM} ${OBJECTDIR}/_ext/246609638/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/246609638/port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/246609638/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/246609638/port.o.d" -o ${OBJECTDIR}/_ext/246609638/port.o ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F/port.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1665200909/heap_3.o: ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1665200909" 
	@${RM} ${OBJECTDIR}/_ext/1665200909/heap_3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1665200909/heap_3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1665200909/heap_3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1665200909/heap_3.o.d" -o ${OBJECTDIR}/_ext/1665200909/heap_3.o ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_3.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/croutine.o: ../src/third_party/rtos/FreeRTOS/Source/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/croutine.o.d" -o ${OBJECTDIR}/_ext/404212886/croutine.o ../src/third_party/rtos/FreeRTOS/Source/croutine.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/list.o: ../src/third_party/rtos/FreeRTOS/Source/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/list.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/list.o.d" -o ${OBJECTDIR}/_ext/404212886/list.o ../src/third_party/rtos/FreeRTOS/Source/list.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/queue.o: ../src/third_party/rtos/FreeRTOS/Source/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/queue.o.d" -o ${OBJECTDIR}/_ext/404212886/queue.o ../src/third_party/rtos/FreeRTOS/Source/queue.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o: ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d" -o ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/timers.o: ../src/third_party/rtos/FreeRTOS/Source/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/timers.o.d" -o ${OBJECTDIR}/_ext/404212886/timers.o ../src/third_party/rtos/FreeRTOS/Source/timers.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/event_groups.o: ../src/third_party/rtos/FreeRTOS/Source/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/event_groups.o.d" -o ${OBJECTDIR}/_ext/404212886/event_groups.o ../src/third_party/rtos/FreeRTOS/Source/event_groups.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/stream_buffer.o: ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/stream_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/stream_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/stream_buffer.o.d" -o ${OBJECTDIR}/_ext/404212886/stream_buffer.o ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1767394448/osal_freertos.o: ../src/config/sam_e54_xpro_freertos/osal/osal_freertos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1767394448" 
	@${RM} ${OBJECTDIR}/_ext/1767394448/osal_freertos.o.d 
	@${RM} ${OBJECTDIR}/_ext/1767394448/osal_freertos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1767394448/osal_freertos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1767394448/osal_freertos.o.d" -o ${OBJECTDIR}/_ext/1767394448/osal_freertos.o ../src/config/sam_e54_xpro_freertos/osal/osal_freertos.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/cJSON.o: ../src/cJSON.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cJSON.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cJSON.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/cJSON.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/cJSON.o.d" -o ${OBJECTDIR}/_ext/1360937237/cJSON.o ../src/cJSON.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/com_lib.o: ../src/com_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/com_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/com_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/com_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/com_lib.o.d" -o ${OBJECTDIR}/_ext/1360937237/com_lib.o ../src/com_lib.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/netapp_lib.o: ../src/netapp_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/netapp_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/netapp_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/netapp_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/netapp_lib.o.d" -o ${OBJECTDIR}/_ext/1360937237/netapp_lib.o ../src/netapp_lib.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/shared_settings.o: ../src/shared_settings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shared_settings.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shared_settings.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/shared_settings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/shared_settings.o.d" -o ${OBJECTDIR}/_ext/1360937237/shared_settings.o ../src/shared_settings.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/mcp9800.o: ../src/mcp9800.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9800.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9800.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/mcp9800.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/mcp9800.o.d" -o ${OBJECTDIR}/_ext/1360937237/mcp9800.o ../src/mcp9800.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/OLED12864.o: ../src/OLED12864.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OLED12864.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OLED12864.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/OLED12864.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/OLED12864.o.d" -o ${OBJECTDIR}/_ext/1360937237/OLED12864.o ../src/OLED12864.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/BH1750FVI.o: ../src/BH1750FVI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/BH1750FVI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/BH1750FVI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/BH1750FVI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/BH1750FVI.o.d" -o ${OBJECTDIR}/_ext/1360937237/BH1750FVI.o ../src/BH1750FVI.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/lcw.o: ../src/lcw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/lcw.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/lcw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/lcw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/lcw.o.d" -o ${OBJECTDIR}/_ext/1360937237/lcw.o ../src/lcw.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/adc.o: ../src/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/adc.o.d" -o ${OBJECTDIR}/_ext/1360937237/adc.o ../src/adc.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/uart_command.o: ../src/uart_command.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart_command.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart_command.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/uart_command.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/uart_command.o.d" -o ${OBJECTDIR}/_ext/1360937237/uart_command.o ../src/uart_command.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/Judgeman.o: ../src/Judgeman.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Judgeman.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Judgeman.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/Judgeman.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/Judgeman.o.d" -o ${OBJECTDIR}/_ext/1360937237/Judgeman.o ../src/Judgeman.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" -o ${OBJECTDIR}/_ext/1360937237/eeprom.o ../src/eeprom.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/tcp_app.o: ../src/tcp_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tcp_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tcp_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/tcp_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/tcp_app.o.d" -o ${OBJECTDIR}/_ext/1360937237/tcp_app.o ../src/tcp_app.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/uart_app.o: ../src/uart_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/uart_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/uart_app.o.d" -o ${OBJECTDIR}/_ext/1360937237/uart_app.o ../src/uart_app.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/rs232_app.o: ../src/rs232_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rs232_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rs232_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/rs232_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/rs232_app.o.d" -o ${OBJECTDIR}/_ext/1360937237/rs232_app.o ../src/rs232_app.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/judgeman_app.o: ../src/judgeman_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/judgeman_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/judgeman_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/judgeman_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/judgeman_app.o.d" -o ${OBJECTDIR}/_ext/1360937237/judgeman_app.o ../src/judgeman_app.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/234661171/drv_ethphy.o: ../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_ethphy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/234661171" 
	@${RM} ${OBJECTDIR}/_ext/234661171/drv_ethphy.o.d 
	@${RM} ${OBJECTDIR}/_ext/234661171/drv_ethphy.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/234661171/drv_ethphy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/234661171/drv_ethphy.o.d" -o ${OBJECTDIR}/_ext/234661171/drv_ethphy.o ../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_ethphy.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o: ../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_extphy_ksz8091.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/234661171" 
	@${RM} ${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o.d 
	@${RM} ${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o.d" -o ${OBJECTDIR}/_ext/234661171/drv_extphy_ksz8091.o ../src/config/sam_e54_xpro_freertos/driver/ethphy/src/dynamic/drv_extphy_ksz8091.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/125405427/drv_gmac.o: ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/125405427" 
	@${RM} ${OBJECTDIR}/_ext/125405427/drv_gmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/125405427/drv_gmac.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/125405427/drv_gmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/125405427/drv_gmac.o.d" -o ${OBJECTDIR}/_ext/125405427/drv_gmac.o ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o: ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac_lib_samE5x.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/125405427" 
	@${RM} ${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o.d 
	@${RM} ${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o.d" -o ${OBJECTDIR}/_ext/125405427/drv_gmac_lib_samE5x.o ../src/config/sam_e54_xpro_freertos/driver/gmac/src/dynamic/drv_gmac_lib_samE5x.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/865364553/drv_i2c.o: ../src/config/sam_e54_xpro_freertos/driver/i2c/src/drv_i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/865364553" 
	@${RM} ${OBJECTDIR}/_ext/865364553/drv_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/865364553/drv_i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/865364553/drv_i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/865364553/drv_i2c.o.d" -o ${OBJECTDIR}/_ext/865364553/drv_i2c.o ../src/config/sam_e54_xpro_freertos/driver/i2c/src/drv_i2c.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1233363243/drv_miim.o: ../src/config/sam_e54_xpro_freertos/driver/miim/src/dynamic/drv_miim.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1233363243" 
	@${RM} ${OBJECTDIR}/_ext/1233363243/drv_miim.o.d 
	@${RM} ${OBJECTDIR}/_ext/1233363243/drv_miim.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1233363243/drv_miim.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1233363243/drv_miim.o.d" -o ${OBJECTDIR}/_ext/1233363243/drv_miim.o ../src/config/sam_e54_xpro_freertos/driver/miim/src/dynamic/drv_miim.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/helpers.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/helpers.o.d" -o ${OBJECTDIR}/_ext/1925797400/helpers.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/helpers.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/dns.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/dns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/dns.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/dns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/dns.o.d" -o ${OBJECTDIR}/_ext/1925797400/dns.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dns.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/icmp.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/icmp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/icmp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/icmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/icmp.o.d" -o ${OBJECTDIR}/_ext/1925797400/icmp.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/icmp.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcp.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcp.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcp.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcp.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/dhcp.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dhcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/dhcp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/dhcp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/dhcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/dhcp.o.d" -o ${OBJECTDIR}/_ext/1925797400/dhcp.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/dhcp.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/arp.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/arp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/arp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/arp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/arp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/arp.o.d" -o ${OBJECTDIR}/_ext/1925797400/arp.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/arp.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/berkeley_api.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/berkeley_api.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/berkeley_api.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/berkeley_api.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/berkeley_api.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/berkeley_api.o.d" -o ${OBJECTDIR}/_ext/1925797400/berkeley_api.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/berkeley_api.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/ipv4.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/ipv4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/ipv4.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/ipv4.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/ipv4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/ipv4.o.d" -o ${OBJECTDIR}/_ext/1925797400/ipv4.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/ipv4.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_alloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_heap_alloc.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_alloc.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_internal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_heap_internal.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_heap_internal.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/hash_fnv.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/hash_fnv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/hash_fnv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/hash_fnv.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/hash_fnv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/hash_fnv.o.d" -o ${OBJECTDIR}/_ext/1925797400/hash_fnv.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/hash_fnv.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/oahash.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/oahash.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/oahash.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/oahash.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/oahash.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/oahash.o.d" -o ${OBJECTDIR}/_ext/1925797400/oahash.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/oahash.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_helpers.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_helpers.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_manager.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_manager.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_manager.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_manager.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_manager.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_manager.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_manager.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_notify.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_notify.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_notify.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_notify.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_notify.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_notify.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_notify.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_notify.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_packet.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_packet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_packet.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_packet.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_packet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_packet.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_packet.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_packet.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/tcpip_announce.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_announce.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_announce.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/tcpip_announce.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/tcpip_announce.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/tcpip_announce.o.d" -o ${OBJECTDIR}/_ext/1925797400/tcpip_announce.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/tcpip_announce.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1925797400/udp.o: ../src/config/sam_e54_xpro_freertos/library/tcpip/src/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925797400" 
	@${RM} ${OBJECTDIR}/_ext/1925797400/udp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1925797400/udp.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1925797400/udp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1925797400/udp.o.d" -o ${OBJECTDIR}/_ext/1925797400/udp.o ../src/config/sam_e54_xpro_freertos/library/tcpip/src/udp.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/615292289/net_pres.o: ../src/config/sam_e54_xpro_freertos/net_pres/pres/src/net_pres.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/615292289" 
	@${RM} ${OBJECTDIR}/_ext/615292289/net_pres.o.d 
	@${RM} ${OBJECTDIR}/_ext/615292289/net_pres.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/615292289/net_pres.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/615292289/net_pres.o.d" -o ${OBJECTDIR}/_ext/615292289/net_pres.o ../src/config/sam_e54_xpro_freertos/net_pres/pres/src/net_pres.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o: ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_enc_glue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/509249492" 
	@${RM} ${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o.d 
	@${RM} ${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o.d" -o ${OBJECTDIR}/_ext/509249492/net_pres_enc_glue.o ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_enc_glue.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o: ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_cert_store.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/509249492" 
	@${RM} ${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o.d 
	@${RM} ${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o.d" -o ${OBJECTDIR}/_ext/509249492/net_pres_cert_store.o ../src/config/sam_e54_xpro_freertos/net_pres/pres/net_pres_cert_store.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/767142862/plib_adc0.o: ../src/config/sam_e54_xpro_freertos/peripheral/adc/plib_adc0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/767142862" 
	@${RM} ${OBJECTDIR}/_ext/767142862/plib_adc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/767142862/plib_adc0.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767142862/plib_adc0.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/767142862/plib_adc0.o.d" -o ${OBJECTDIR}/_ext/767142862/plib_adc0.o ../src/config/sam_e54_xpro_freertos/peripheral/adc/plib_adc0.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1507984452/plib_clock.o: ../src/config/sam_e54_xpro_freertos/peripheral/clock/plib_clock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1507984452" 
	@${RM} ${OBJECTDIR}/_ext/1507984452/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1507984452/plib_clock.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1507984452/plib_clock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1507984452/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1507984452/plib_clock.o ../src/config/sam_e54_xpro_freertos/peripheral/clock/plib_clock.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1988306724/plib_cmcc.o: ../src/config/sam_e54_xpro_freertos/peripheral/cmcc/plib_cmcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1988306724" 
	@${RM} ${OBJECTDIR}/_ext/1988306724/plib_cmcc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1988306724/plib_cmcc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1988306724/plib_cmcc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1988306724/plib_cmcc.o.d" -o ${OBJECTDIR}/_ext/1988306724/plib_cmcc.o ../src/config/sam_e54_xpro_freertos/peripheral/cmcc/plib_cmcc.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/767146861/plib_eic.o: ../src/config/sam_e54_xpro_freertos/peripheral/eic/plib_eic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/767146861" 
	@${RM} ${OBJECTDIR}/_ext/767146861/plib_eic.o.d 
	@${RM} ${OBJECTDIR}/_ext/767146861/plib_eic.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767146861/plib_eic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/767146861/plib_eic.o.d" -o ${OBJECTDIR}/_ext/767146861/plib_eic.o ../src/config/sam_e54_xpro_freertos/peripheral/eic/plib_eic.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1505834966/plib_evsys.o: ../src/config/sam_e54_xpro_freertos/peripheral/evsys/plib_evsys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1505834966" 
	@${RM} ${OBJECTDIR}/_ext/1505834966/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1505834966/plib_evsys.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1505834966/plib_evsys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1505834966/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1505834966/plib_evsys.o ../src/config/sam_e54_xpro_freertos/peripheral/evsys/plib_evsys.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1987970188/plib_nvic.o: ../src/config/sam_e54_xpro_freertos/peripheral/nvic/plib_nvic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1987970188" 
	@${RM} ${OBJECTDIR}/_ext/1987970188/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1987970188/plib_nvic.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1987970188/plib_nvic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1987970188/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1987970188/plib_nvic.o ../src/config/sam_e54_xpro_freertos/peripheral/nvic/plib_nvic.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o: ../src/config/sam_e54_xpro_freertos/peripheral/nvmctrl/plib_nvmctrl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/312016962" 
	@${RM} ${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/312016962/plib_nvmctrl.o ../src/config/sam_e54_xpro_freertos/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/301841679/plib_pm.o: ../src/config/sam_e54_xpro_freertos/peripheral/pm/plib_pm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/301841679" 
	@${RM} ${OBJECTDIR}/_ext/301841679/plib_pm.o.d 
	@${RM} ${OBJECTDIR}/_ext/301841679/plib_pm.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/301841679/plib_pm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/301841679/plib_pm.o.d" -o ${OBJECTDIR}/_ext/301841679/plib_pm.o ../src/config/sam_e54_xpro_freertos/peripheral/pm/plib_pm.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1987917037/plib_port.o: ../src/config/sam_e54_xpro_freertos/peripheral/port/plib_port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1987917037" 
	@${RM} ${OBJECTDIR}/_ext/1987917037/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1987917037/plib_port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1987917037/plib_port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1987917037/plib_port.o.d" -o ${OBJECTDIR}/_ext/1987917037/plib_port.o ../src/config/sam_e54_xpro_freertos/peripheral/port/plib_port.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o: ../src/config/sam_e54_xpro_freertos/peripheral/rtc/plib_rtc_timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/767159695" 
	@${RM} ${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o.d" -o ${OBJECTDIR}/_ext/767159695/plib_rtc_timer.o ../src/config/sam_e54_xpro_freertos/peripheral/rtc/plib_rtc_timer.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o: ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom3_i2c_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/89900541" 
	@${RM} ${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o.d" -o ${OBJECTDIR}/_ext/89900541/plib_sercom3_i2c_master.o ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom3_i2c_master.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o: ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom7_i2c_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/89900541" 
	@${RM} ${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o.d" -o ${OBJECTDIR}/_ext/89900541/plib_sercom7_i2c_master.o ../src/config/sam_e54_xpro_freertos/peripheral/sercom/i2c_master/plib_sercom7_i2c_master.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o: ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom2_usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2118479575" 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o.d" -o ${OBJECTDIR}/_ext/2118479575/plib_sercom2_usart.o ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom2_usart.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o: ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom0_usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2118479575" 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o.d" -o ${OBJECTDIR}/_ext/2118479575/plib_sercom0_usart.o ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom0_usart.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o: ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom5_usart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2118479575" 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o.d" -o ${OBJECTDIR}/_ext/2118479575/plib_sercom5_usart.o ../src/config/sam_e54_xpro_freertos/peripheral/sercom/usart/plib_sercom5_usart.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/301841793/plib_tc0.o: ../src/config/sam_e54_xpro_freertos/peripheral/tc/plib_tc0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/301841793" 
	@${RM} ${OBJECTDIR}/_ext/301841793/plib_tc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/301841793/plib_tc0.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/301841793/plib_tc0.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/301841793/plib_tc0.o.d" -o ${OBJECTDIR}/_ext/301841793/plib_tc0.o ../src/config/sam_e54_xpro_freertos/peripheral/tc/plib_tc0.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/767161090/plib_tcc0.o: ../src/config/sam_e54_xpro_freertos/peripheral/tcc/plib_tcc0.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/767161090" 
	@${RM} ${OBJECTDIR}/_ext/767161090/plib_tcc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/767161090/plib_tcc0.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/767161090/plib_tcc0.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/767161090/plib_tcc0.o.d" -o ${OBJECTDIR}/_ext/767161090/plib_tcc0.o ../src/config/sam_e54_xpro_freertos/peripheral/tcc/plib_tcc0.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1041620184/xc32_monitor.o: ../src/config/sam_e54_xpro_freertos/stdio/xc32_monitor.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1041620184" 
	@${RM} ${OBJECTDIR}/_ext/1041620184/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/1041620184/xc32_monitor.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1041620184/xc32_monitor.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1041620184/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/1041620184/xc32_monitor.o ../src/config/sam_e54_xpro_freertos/stdio/xc32_monitor.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1947381213/sys_cache.o: ../src/config/sam_e54_xpro_freertos/system/cache/sys_cache.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1947381213" 
	@${RM} ${OBJECTDIR}/_ext/1947381213/sys_cache.o.d 
	@${RM} ${OBJECTDIR}/_ext/1947381213/sys_cache.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1947381213/sys_cache.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1947381213/sys_cache.o.d" -o ${OBJECTDIR}/_ext/1947381213/sys_cache.o ../src/config/sam_e54_xpro_freertos/system/cache/sys_cache.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/557048589/sys_console_uart.o: ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console_uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/557048589" 
	@${RM} ${OBJECTDIR}/_ext/557048589/sys_console_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/557048589/sys_console_uart.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/557048589/sys_console_uart.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/557048589/sys_console_uart.o.d" -o ${OBJECTDIR}/_ext/557048589/sys_console_uart.o ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console_uart.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/557048589/sys_console.o: ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/557048589" 
	@${RM} ${OBJECTDIR}/_ext/557048589/sys_console.o.d 
	@${RM} ${OBJECTDIR}/_ext/557048589/sys_console.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/557048589/sys_console.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/557048589/sys_console.o.d" -o ${OBJECTDIR}/_ext/557048589/sys_console.o ../src/config/sam_e54_xpro_freertos/system/console/src/sys_console.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1747368521/sys_debug.o: ../src/config/sam_e54_xpro_freertos/system/debug/src/sys_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1747368521" 
	@${RM} ${OBJECTDIR}/_ext/1747368521/sys_debug.o.d 
	@${RM} ${OBJECTDIR}/_ext/1747368521/sys_debug.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1747368521/sys_debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1747368521/sys_debug.o.d" -o ${OBJECTDIR}/_ext/1747368521/sys_debug.o ../src/config/sam_e54_xpro_freertos/system/debug/src/sys_debug.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1706319323/sys_int.o: ../src/config/sam_e54_xpro_freertos/system/int/src/sys_int.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1706319323" 
	@${RM} ${OBJECTDIR}/_ext/1706319323/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706319323/sys_int.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1706319323/sys_int.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1706319323/sys_int.o.d" -o ${OBJECTDIR}/_ext/1706319323/sys_int.o ../src/config/sam_e54_xpro_freertos/system/int/src/sys_int.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/339643745/sys_time.o: ../src/config/sam_e54_xpro_freertos/system/time/src/sys_time.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/339643745" 
	@${RM} ${OBJECTDIR}/_ext/339643745/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/339643745/sys_time.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/339643745/sys_time.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/339643745/sys_time.o.d" -o ${OBJECTDIR}/_ext/339643745/sys_time.o ../src/config/sam_e54_xpro_freertos/system/time/src/sys_time.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o: ../src/config/sam_e54_xpro_freertos/system/sys_time_h2_adapter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2074587504" 
	@${RM} ${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o.d 
	@${RM} ${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o.d" -o ${OBJECTDIR}/_ext/2074587504/sys_time_h2_adapter.o ../src/config/sam_e54_xpro_freertos/system/sys_time_h2_adapter.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/tasks.o: ../src/config/sam_e54_xpro_freertos/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/tasks.o.d" -o ${OBJECTDIR}/_ext/651216402/tasks.o ../src/config/sam_e54_xpro_freertos/tasks.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/initialization.o: ../src/config/sam_e54_xpro_freertos/initialization.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/initialization.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/initialization.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/initialization.o.d" -o ${OBJECTDIR}/_ext/651216402/initialization.o ../src/config/sam_e54_xpro_freertos/initialization.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/interrupts.o: ../src/config/sam_e54_xpro_freertos/interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/interrupts.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/interrupts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/interrupts.o.d" -o ${OBJECTDIR}/_ext/651216402/interrupts.o ../src/config/sam_e54_xpro_freertos/interrupts.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/exceptions.o: ../src/config/sam_e54_xpro_freertos/exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/exceptions.o.d" -o ${OBJECTDIR}/_ext/651216402/exceptions.o ../src/config/sam_e54_xpro_freertos/exceptions.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/startup_xc32.o: ../src/config/sam_e54_xpro_freertos/startup_xc32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/startup_xc32.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/startup_xc32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/651216402/startup_xc32.o ../src/config/sam_e54_xpro_freertos/startup_xc32.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/libc_syscalls.o: ../src/config/sam_e54_xpro_freertos/libc_syscalls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/libc_syscalls.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/libc_syscalls.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/651216402/libc_syscalls.o ../src/config/sam_e54_xpro_freertos/libc_syscalls.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/651216402/freertos_hooks.o: ../src/config/sam_e54_xpro_freertos/freertos_hooks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/651216402" 
	@${RM} ${OBJECTDIR}/_ext/651216402/freertos_hooks.o.d 
	@${RM} ${OBJECTDIR}/_ext/651216402/freertos_hooks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/651216402/freertos_hooks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/651216402/freertos_hooks.o.d" -o ${OBJECTDIR}/_ext/651216402/freertos_hooks.o ../src/config/sam_e54_xpro_freertos/freertos_hooks.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/246609638/port.o: ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/246609638" 
	@${RM} ${OBJECTDIR}/_ext/246609638/port.o.d 
	@${RM} ${OBJECTDIR}/_ext/246609638/port.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/246609638/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/246609638/port.o.d" -o ${OBJECTDIR}/_ext/246609638/port.o ../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F/port.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1665200909/heap_3.o: ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_3.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1665200909" 
	@${RM} ${OBJECTDIR}/_ext/1665200909/heap_3.o.d 
	@${RM} ${OBJECTDIR}/_ext/1665200909/heap_3.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1665200909/heap_3.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1665200909/heap_3.o.d" -o ${OBJECTDIR}/_ext/1665200909/heap_3.o ../src/third_party/rtos/FreeRTOS/Source/portable/MemMang/heap_3.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/croutine.o: ../src/third_party/rtos/FreeRTOS/Source/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/croutine.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/croutine.o.d" -o ${OBJECTDIR}/_ext/404212886/croutine.o ../src/third_party/rtos/FreeRTOS/Source/croutine.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/list.o: ../src/third_party/rtos/FreeRTOS/Source/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/list.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/list.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/list.o.d" -o ${OBJECTDIR}/_ext/404212886/list.o ../src/third_party/rtos/FreeRTOS/Source/list.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/queue.o: ../src/third_party/rtos/FreeRTOS/Source/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/queue.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/queue.o.d" -o ${OBJECTDIR}/_ext/404212886/queue.o ../src/third_party/rtos/FreeRTOS/Source/queue.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o: ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o.d" -o ${OBJECTDIR}/_ext/404212886/FreeRTOS_tasks.o ../src/third_party/rtos/FreeRTOS/Source/FreeRTOS_tasks.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/timers.o: ../src/third_party/rtos/FreeRTOS/Source/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/timers.o.d" -o ${OBJECTDIR}/_ext/404212886/timers.o ../src/third_party/rtos/FreeRTOS/Source/timers.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/event_groups.o: ../src/third_party/rtos/FreeRTOS/Source/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/event_groups.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/event_groups.o.d" -o ${OBJECTDIR}/_ext/404212886/event_groups.o ../src/third_party/rtos/FreeRTOS/Source/event_groups.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/404212886/stream_buffer.o: ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/404212886" 
	@${RM} ${OBJECTDIR}/_ext/404212886/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/_ext/404212886/stream_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/404212886/stream_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/404212886/stream_buffer.o.d" -o ${OBJECTDIR}/_ext/404212886/stream_buffer.o ../src/third_party/rtos/FreeRTOS/Source/stream_buffer.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1767394448/osal_freertos.o: ../src/config/sam_e54_xpro_freertos/osal/osal_freertos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1767394448" 
	@${RM} ${OBJECTDIR}/_ext/1767394448/osal_freertos.o.d 
	@${RM} ${OBJECTDIR}/_ext/1767394448/osal_freertos.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1767394448/osal_freertos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1767394448/osal_freertos.o.d" -o ${OBJECTDIR}/_ext/1767394448/osal_freertos.o ../src/config/sam_e54_xpro_freertos/osal/osal_freertos.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/cJSON.o: ../src/cJSON.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cJSON.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cJSON.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/cJSON.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/cJSON.o.d" -o ${OBJECTDIR}/_ext/1360937237/cJSON.o ../src/cJSON.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/com_lib.o: ../src/com_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/com_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/com_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/com_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/com_lib.o.d" -o ${OBJECTDIR}/_ext/1360937237/com_lib.o ../src/com_lib.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/netapp_lib.o: ../src/netapp_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/netapp_lib.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/netapp_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/netapp_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/netapp_lib.o.d" -o ${OBJECTDIR}/_ext/1360937237/netapp_lib.o ../src/netapp_lib.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/shared_settings.o: ../src/shared_settings.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shared_settings.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/shared_settings.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/shared_settings.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/shared_settings.o.d" -o ${OBJECTDIR}/_ext/1360937237/shared_settings.o ../src/shared_settings.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/mcp9800.o: ../src/mcp9800.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9800.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9800.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/mcp9800.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/mcp9800.o.d" -o ${OBJECTDIR}/_ext/1360937237/mcp9800.o ../src/mcp9800.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/OLED12864.o: ../src/OLED12864.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OLED12864.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/OLED12864.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/OLED12864.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/OLED12864.o.d" -o ${OBJECTDIR}/_ext/1360937237/OLED12864.o ../src/OLED12864.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/BH1750FVI.o: ../src/BH1750FVI.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/BH1750FVI.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/BH1750FVI.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/BH1750FVI.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/BH1750FVI.o.d" -o ${OBJECTDIR}/_ext/1360937237/BH1750FVI.o ../src/BH1750FVI.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/lcw.o: ../src/lcw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/lcw.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/lcw.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/lcw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/lcw.o.d" -o ${OBJECTDIR}/_ext/1360937237/lcw.o ../src/lcw.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/adc.o: ../src/adc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/adc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/adc.o.d" -o ${OBJECTDIR}/_ext/1360937237/adc.o ../src/adc.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/uart_command.o: ../src/uart_command.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart_command.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart_command.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/uart_command.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/uart_command.o.d" -o ${OBJECTDIR}/_ext/1360937237/uart_command.o ../src/uart_command.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/Judgeman.o: ../src/Judgeman.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Judgeman.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/Judgeman.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/Judgeman.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/Judgeman.o.d" -o ${OBJECTDIR}/_ext/1360937237/Judgeman.o ../src/Judgeman.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/eeprom.o: ../src/eeprom.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/eeprom.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/eeprom.o.d" -o ${OBJECTDIR}/_ext/1360937237/eeprom.o ../src/eeprom.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/tcp_app.o: ../src/tcp_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tcp_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/tcp_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/tcp_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/tcp_app.o.d" -o ${OBJECTDIR}/_ext/1360937237/tcp_app.o ../src/tcp_app.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/uart_app.o: ../src/uart_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/uart_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/uart_app.o.d" -o ${OBJECTDIR}/_ext/1360937237/uart_app.o ../src/uart_app.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/rs232_app.o: ../src/rs232_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rs232_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rs232_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/rs232_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/rs232_app.o.d" -o ${OBJECTDIR}/_ext/1360937237/rs232_app.o ../src/rs232_app.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/judgeman_app.o: ../src/judgeman_app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/judgeman_app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/judgeman_app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/judgeman_app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/judgeman_app.o.d" -o ${OBJECTDIR}/_ext/1360937237/judgeman_app.o ../src/judgeman_app.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -I"../src/config/sam_e54_xpro_freertos/library" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src" -I"../src/config/sam_e54_xpro_freertos/library/tcpip/src/common" -I"../src" -I"../src/config/sam_e54_xpro_freertos" -I"../src/packs/ATSAME54P20A_DFP" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/CMSIS/" -I"../src/third_party/rtos/FreeRTOS/Source/include" -I"../src/third_party/rtos/FreeRTOS/Source/portable/GCC/SAM/ARM_CM4F" -Werror -Wall -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/sam_e54_xpro_freertos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o dist/${CND_CONF}/${IMAGE_TYPE}/sam_e54_xpro_freertos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=120960,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/sam_e54_xpro_freertos.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION) -mno-device-startup-code -o dist/${CND_CONF}/${IMAGE_TYPE}/sam_e54_xpro_freertos.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_sam_e54_xpro_freertos=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=120960,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/sam_e54_xpro_freertos.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/sam_e54_xpro_freertos
	${RM} -r dist/sam_e54_xpro_freertos

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
