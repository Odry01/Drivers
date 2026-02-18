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
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/config/default/driver/i2c/src/drv_i2c.c ../src/config/default/driver/spi/src/drv_spi.c ../src/config/default/driver/usart/src/drv_usart.c ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c ../src/config/default/driver/wifi/wincs02/wdrv_winc.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c ../src/config/default/peripheral/adc/plib_adc0.c ../src/config/default/peripheral/can/plib_can0.c ../src/config/default/peripheral/clock/plib_clock.c ../src/config/default/peripheral/dac/plib_dac.c ../src/config/default/peripheral/divas/plib_divas.c ../src/config/default/peripheral/dmac/plib_dmac.c ../src/config/default/peripheral/eic/plib_eic.c ../src/config/default/peripheral/evsys/plib_evsys.c ../src/config/default/peripheral/freqm/plib_freqm.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/default/peripheral/pm/plib_pm.c ../src/config/default/peripheral/port/plib_port.c ../src/config/default/peripheral/rstc/plib_rstc.c ../src/config/default/peripheral/rtc/plib_rtc_clock.c ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c ../src/config/default/peripheral/supc/plib_supc.c ../src/config/default/peripheral/systick/plib_systick.c ../src/config/default/peripheral/tcc/plib_tcc0.c ../src/config/default/peripheral/wdt/plib_wdt.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/system/console/src/sys_console_uart.c ../src/config/default/system/console/src/sys_console.c ../src/config/default/system/dma/sys_dma.c ../src/config/default/system/int/src/sys_int.c ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c ../src/config/default/system/net/src/sys_wincs_net_service.c ../src/config/default/system/time/src/sys_time.c ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c ../src/config/default/system/sys_wincs_system_service.c ../src/config/default/tasks.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/ad9954_driver.c ../src/bme690_driver.c ../src/bmp585_driver.c ../src/can0_driver.c ../src/console_driver.c ../src/fcm360w_driver.c ../src/hdc302x_driver.c ../src/mcp9808_driver.c ../src/ntc_driver.c ../src/rstc_driver.c ../src/rtc_driver.c ../src/sen63c_driver.c ../src/sht4x_driver.c ../src/ssd1306_driver.c ../src/stcc4_driver.c ../src/timer_driver.c ../src/vcnl4200_driver.c ../src/ws281x_driver.c ../src/xm125_driver.c ../src/wincs02_driver.c ../src/app.c ../src/main.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/158385033/drv_i2c.o ${OBJECTDIR}/_ext/2070931557/drv_spi.o ${OBJECTDIR}/_ext/869808652/drv_usart.o ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o ${OBJECTDIR}/_ext/1857064221/winc_cmds.o ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o ${OBJECTDIR}/_ext/1857064221/winc_dev.o ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o ${OBJECTDIR}/_ext/1857064221/winc_socket.o ${OBJECTDIR}/_ext/1857064221/winc_tables.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o ${OBJECTDIR}/_ext/60163342/plib_adc0.o ${OBJECTDIR}/_ext/60165182/plib_can0.o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ${OBJECTDIR}/_ext/60166132/plib_dac.o ${OBJECTDIR}/_ext/1985337713/plib_divas.o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ${OBJECTDIR}/_ext/60167341/plib_eic.o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ${OBJECTDIR}/_ext/1987437027/plib_freqm.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ${OBJECTDIR}/_ext/829342769/plib_pm.o ${OBJECTDIR}/_ext/1865521619/plib_port.o ${OBJECTDIR}/_ext/1865585090/plib_rstc.o ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o ${OBJECTDIR}/_ext/1865616679/plib_supc.o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ${OBJECTDIR}/_ext/60181570/plib_tcc0.o ${OBJECTDIR}/_ext/60184501/plib_wdt.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o ${OBJECTDIR}/_ext/1832805299/sys_console.o ${OBJECTDIR}/_ext/14461671/sys_dma.o ${OBJECTDIR}/_ext/1881668453/sys_int.o ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o ${OBJECTDIR}/_ext/101884895/sys_time.o ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o ${OBJECTDIR}/_ext/1171490990/tasks.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o ${OBJECTDIR}/_ext/1360937237/bme690_driver.o ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o ${OBJECTDIR}/_ext/1360937237/can0_driver.o ${OBJECTDIR}/_ext/1360937237/console_driver.o ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o ${OBJECTDIR}/_ext/1360937237/ntc_driver.o ${OBJECTDIR}/_ext/1360937237/rstc_driver.o ${OBJECTDIR}/_ext/1360937237/rtc_driver.o ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o ${OBJECTDIR}/_ext/1360937237/timer_driver.o ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o ${OBJECTDIR}/_ext/1360937237/xm125_driver.o ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/158385033/drv_i2c.o.d ${OBJECTDIR}/_ext/2070931557/drv_spi.o.d ${OBJECTDIR}/_ext/869808652/drv_usart.o.d ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o.d ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o.d ${OBJECTDIR}/_ext/1857064221/winc_cmds.o.d ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o.d ${OBJECTDIR}/_ext/1857064221/winc_dev.o.d ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o.d ${OBJECTDIR}/_ext/1857064221/winc_socket.o.d ${OBJECTDIR}/_ext/1857064221/winc_tables.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o.d ${OBJECTDIR}/_ext/60163342/plib_adc0.o.d ${OBJECTDIR}/_ext/60165182/plib_can0.o.d ${OBJECTDIR}/_ext/1984496892/plib_clock.o.d ${OBJECTDIR}/_ext/60166132/plib_dac.o.d ${OBJECTDIR}/_ext/1985337713/plib_divas.o.d ${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d ${OBJECTDIR}/_ext/60167341/plib_eic.o.d ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d ${OBJECTDIR}/_ext/1987437027/plib_freqm.o.d ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d ${OBJECTDIR}/_ext/829342769/plib_pm.o.d ${OBJECTDIR}/_ext/1865521619/plib_port.o.d ${OBJECTDIR}/_ext/1865585090/plib_rstc.o.d ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o.d ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o.d ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o.d ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o.d ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o.d ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o.d ${OBJECTDIR}/_ext/1865616679/plib_supc.o.d ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d ${OBJECTDIR}/_ext/60181570/plib_tcc0.o.d ${OBJECTDIR}/_ext/60184501/plib_wdt.o.d ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o.d ${OBJECTDIR}/_ext/1832805299/sys_console.o.d ${OBJECTDIR}/_ext/14461671/sys_dma.o.d ${OBJECTDIR}/_ext/1881668453/sys_int.o.d ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o.d ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o.d ${OBJECTDIR}/_ext/101884895/sys_time.o.d ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o.d ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o.d ${OBJECTDIR}/_ext/1171490990/tasks.o.d ${OBJECTDIR}/_ext/1171490990/initialization.o.d ${OBJECTDIR}/_ext/1171490990/interrupts.o.d ${OBJECTDIR}/_ext/1171490990/exceptions.o.d ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o.d ${OBJECTDIR}/_ext/1360937237/bme690_driver.o.d ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o.d ${OBJECTDIR}/_ext/1360937237/can0_driver.o.d ${OBJECTDIR}/_ext/1360937237/console_driver.o.d ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o.d ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o.d ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o.d ${OBJECTDIR}/_ext/1360937237/ntc_driver.o.d ${OBJECTDIR}/_ext/1360937237/rstc_driver.o.d ${OBJECTDIR}/_ext/1360937237/rtc_driver.o.d ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o.d ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o.d ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o.d ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o.d ${OBJECTDIR}/_ext/1360937237/timer_driver.o.d ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o.d ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o.d ${OBJECTDIR}/_ext/1360937237/xm125_driver.o.d ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/158385033/drv_i2c.o ${OBJECTDIR}/_ext/2070931557/drv_spi.o ${OBJECTDIR}/_ext/869808652/drv_usart.o ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o ${OBJECTDIR}/_ext/1857064221/winc_cmds.o ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o ${OBJECTDIR}/_ext/1857064221/winc_dev.o ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o ${OBJECTDIR}/_ext/1857064221/winc_socket.o ${OBJECTDIR}/_ext/1857064221/winc_tables.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o ${OBJECTDIR}/_ext/60163342/plib_adc0.o ${OBJECTDIR}/_ext/60165182/plib_can0.o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ${OBJECTDIR}/_ext/60166132/plib_dac.o ${OBJECTDIR}/_ext/1985337713/plib_divas.o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ${OBJECTDIR}/_ext/60167341/plib_eic.o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ${OBJECTDIR}/_ext/1987437027/plib_freqm.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ${OBJECTDIR}/_ext/829342769/plib_pm.o ${OBJECTDIR}/_ext/1865521619/plib_port.o ${OBJECTDIR}/_ext/1865585090/plib_rstc.o ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o ${OBJECTDIR}/_ext/1865616679/plib_supc.o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ${OBJECTDIR}/_ext/60181570/plib_tcc0.o ${OBJECTDIR}/_ext/60184501/plib_wdt.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o ${OBJECTDIR}/_ext/1832805299/sys_console.o ${OBJECTDIR}/_ext/14461671/sys_dma.o ${OBJECTDIR}/_ext/1881668453/sys_int.o ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o ${OBJECTDIR}/_ext/101884895/sys_time.o ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o ${OBJECTDIR}/_ext/1171490990/tasks.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o ${OBJECTDIR}/_ext/1360937237/bme690_driver.o ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o ${OBJECTDIR}/_ext/1360937237/can0_driver.o ${OBJECTDIR}/_ext/1360937237/console_driver.o ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o ${OBJECTDIR}/_ext/1360937237/ntc_driver.o ${OBJECTDIR}/_ext/1360937237/rstc_driver.o ${OBJECTDIR}/_ext/1360937237/rtc_driver.o ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o ${OBJECTDIR}/_ext/1360937237/timer_driver.o ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o ${OBJECTDIR}/_ext/1360937237/xm125_driver.o ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o

# Source Files
SOURCEFILES=../src/config/default/driver/i2c/src/drv_i2c.c ../src/config/default/driver/spi/src/drv_spi.c ../src/config/default/driver/usart/src/drv_usart.c ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c ../src/config/default/driver/wifi/wincs02/wdrv_winc.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c ../src/config/default/peripheral/adc/plib_adc0.c ../src/config/default/peripheral/can/plib_can0.c ../src/config/default/peripheral/clock/plib_clock.c ../src/config/default/peripheral/dac/plib_dac.c ../src/config/default/peripheral/divas/plib_divas.c ../src/config/default/peripheral/dmac/plib_dmac.c ../src/config/default/peripheral/eic/plib_eic.c ../src/config/default/peripheral/evsys/plib_evsys.c ../src/config/default/peripheral/freqm/plib_freqm.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/default/peripheral/pm/plib_pm.c ../src/config/default/peripheral/port/plib_port.c ../src/config/default/peripheral/rstc/plib_rstc.c ../src/config/default/peripheral/rtc/plib_rtc_clock.c ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c ../src/config/default/peripheral/supc/plib_supc.c ../src/config/default/peripheral/systick/plib_systick.c ../src/config/default/peripheral/tcc/plib_tcc0.c ../src/config/default/peripheral/wdt/plib_wdt.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/system/console/src/sys_console_uart.c ../src/config/default/system/console/src/sys_console.c ../src/config/default/system/dma/sys_dma.c ../src/config/default/system/int/src/sys_int.c ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c ../src/config/default/system/net/src/sys_wincs_net_service.c ../src/config/default/system/time/src/sys_time.c ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c ../src/config/default/system/sys_wincs_system_service.c ../src/config/default/tasks.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/ad9954_driver.c ../src/bme690_driver.c ../src/bmp585_driver.c ../src/can0_driver.c ../src/console_driver.c ../src/fcm360w_driver.c ../src/hdc302x_driver.c ../src/mcp9808_driver.c ../src/ntc_driver.c ../src/rstc_driver.c ../src/rtc_driver.c ../src/sen63c_driver.c ../src/sht4x_driver.c ../src/ssd1306_driver.c ../src/stcc4_driver.c ../src/timer_driver.c ../src/vcnl4200_driver.c ../src/ws281x_driver.c ../src/xm125_driver.c ../src/wincs02_driver.c ../src/app.c ../src/main.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c

# Pack Options 
PACK_COMMON_OPTIONS=-I "${CMSIS_DIR}/CMSIS/Core/Include"



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32CM5164JH01100
MP_LINKER_FILE_OPTION=,--script="..\src\config\default\PIC32CM5164JH01100.ld"
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
${OBJECTDIR}/_ext/158385033/drv_i2c.o: ../src/config/default/driver/i2c/src/drv_i2c.c  .generated_files/flags/default/2ee2182108cea543896c506d1175e0f154088353 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/158385033" 
	@${RM} ${OBJECTDIR}/_ext/158385033/drv_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/158385033/drv_i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/158385033/drv_i2c.o.d" -o ${OBJECTDIR}/_ext/158385033/drv_i2c.o ../src/config/default/driver/i2c/src/drv_i2c.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/2070931557/drv_spi.o: ../src/config/default/driver/spi/src/drv_spi.c  .generated_files/flags/default/9a6a94e5f1582811f73bdf1abc86b93f08d5db1d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2070931557" 
	@${RM} ${OBJECTDIR}/_ext/2070931557/drv_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070931557/drv_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/2070931557/drv_spi.o.d" -o ${OBJECTDIR}/_ext/2070931557/drv_spi.o ../src/config/default/driver/spi/src/drv_spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/869808652/drv_usart.o: ../src/config/default/driver/usart/src/drv_usart.c  .generated_files/flags/default/60c0d8c3ed74bae5e2c6c0956b53ac691d7ec793 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/869808652" 
	@${RM} ${OBJECTDIR}/_ext/869808652/drv_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/869808652/drv_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/869808652/drv_usart.o.d" -o ${OBJECTDIR}/_ext/869808652/drv_usart.o ../src/config/default/driver/usart/src/drv_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o: ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c  .generated_files/flags/default/e277a092673e41d918617fed15a863c0591408a8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/622324608" 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o.d" -o ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o: ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c  .generated_files/flags/default/600898b8f1506dc056730c4dd6d952a746dc3add .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/622324608" 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o.d 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o.d" -o ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_cmds.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c  .generated_files/flags/default/caeca47e8891efe8d643701de78c0880b5512afc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmds.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmds.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_cmds.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_cmds.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c  .generated_files/flags/default/290232140da8c79f0fe95cc4ede5c02041cee6d3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_dev.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c  .generated_files/flags/default/a6b77bdb8c24fb2f0c8bdb721a38fdd684a7f8c5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_dev.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_dev.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_dev.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_dev.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c  .generated_files/flags/default/85d80b355824454c37ca150fcb3c9a767a015b4e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_socket.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c  .generated_files/flags/default/f81fce77d73119a3c02135ac74b7e38830f4b2c7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_socket.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_socket.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_tables.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c  .generated_files/flags/default/9e3dd4df9349a2cf1e21323c3eddb9194cba4fb1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_tables.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_tables.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_tables.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_tables.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc.c  .generated_files/flags/default/7a40e9e2c1be19f18c367966b3910755ba93bf3b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o ../src/config/default/driver/wifi/wincs02/wdrv_winc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c  .generated_files/flags/default/4077e5c6032258f29bf3454aa5b8410d28a29be .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c  .generated_files/flags/default/6e72ca1e5d9aa2477dd7588a3b8a3914581ae2e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c  .generated_files/flags/default/615efdec8f50cbcf70e3795c88869195a3fb7d28 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c  .generated_files/flags/default/ef9d8decd4584fd712f75d51ce452694a41387f5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c  .generated_files/flags/default/1701974e9b07bc31332cf14dfd46bb91e0376c2a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c  .generated_files/flags/default/6be38ab17bead0a89d4dc1a8ffc3c76accc681ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c  .generated_files/flags/default/24a7bb56898a2ec2d6c65b9cd1adfa58993744cf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c  .generated_files/flags/default/7fc3049b8aaa2779cb9a8365b21aea78dca09913 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c  .generated_files/flags/default/16db7c9768fab7763312072ce909e5e52dbb81a3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c  .generated_files/flags/default/69f9526b8701d960d8790afc2fd630d2a6f7c50c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c  .generated_files/flags/default/6cfabc953762133693499f0390bb8358623f1cd7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c  .generated_files/flags/default/f78cf10b4da5591f7f993f09df2d4a3096729f0d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c  .generated_files/flags/default/bf9e19341d33ee433e2e7a42362aa46902218c4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c  .generated_files/flags/default/e929c8373cf3102bf3893d05fdec29c10cf6fad9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c  .generated_files/flags/default/7766b3d3e2edccf17ce27c0e8ebfa7cf0f950837 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c  .generated_files/flags/default/3aad1a68ee8234b34b38cb7b239211814ede50a5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c  .generated_files/flags/default/4c3c29b5bc8dfd8b28ceefcdea56870d07aaab9b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c  .generated_files/flags/default/cb6a1a2804c89a7b9fa5ca59cebdf382c22d6ff2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c  .generated_files/flags/default/e480b806d7189edbf5188482ea58f468a0d05fe0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c  .generated_files/flags/default/f0cf6a7db00f3d05ffc2eb71c11f13627ab6b513 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c  .generated_files/flags/default/60fcd053fd3258101b7696724ec6a52e665c2005 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c  .generated_files/flags/default/6c90adef2e8482db63e516d38276439d056e28ef .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60163342/plib_adc0.o: ../src/config/default/peripheral/adc/plib_adc0.c  .generated_files/flags/default/327eced41848b78de9f05e9129b8244e4dafb711 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60163342" 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60163342/plib_adc0.o.d" -o ${OBJECTDIR}/_ext/60163342/plib_adc0.o ../src/config/default/peripheral/adc/plib_adc0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60165182/plib_can0.o: ../src/config/default/peripheral/can/plib_can0.c  .generated_files/flags/default/aa23114efcd267c5332cffbaf7b618c779611922 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60165182" 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60165182/plib_can0.o.d" -o ${OBJECTDIR}/_ext/60165182/plib_can0.o ../src/config/default/peripheral/can/plib_can0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1984496892/plib_clock.o: ../src/config/default/peripheral/clock/plib_clock.c  .generated_files/flags/default/f06975d22a9f8cda3a71c1cbb49de5684b4ca8e5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1984496892" 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1984496892/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ../src/config/default/peripheral/clock/plib_clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60166132/plib_dac.o: ../src/config/default/peripheral/dac/plib_dac.c  .generated_files/flags/default/a445bef76ce5e50232d7308805be8c15e21ea03 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60166132" 
	@${RM} ${OBJECTDIR}/_ext/60166132/plib_dac.o.d 
	@${RM} ${OBJECTDIR}/_ext/60166132/plib_dac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60166132/plib_dac.o.d" -o ${OBJECTDIR}/_ext/60166132/plib_dac.o ../src/config/default/peripheral/dac/plib_dac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1985337713/plib_divas.o: ../src/config/default/peripheral/divas/plib_divas.c  .generated_files/flags/default/faab2e00b67cf2fe6211d76f30ba573dad73bc62 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1985337713" 
	@${RM} ${OBJECTDIR}/_ext/1985337713/plib_divas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1985337713/plib_divas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1985337713/plib_divas.o.d" -o ${OBJECTDIR}/_ext/1985337713/plib_divas.o ../src/config/default/peripheral/divas/plib_divas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865161661/plib_dmac.o: ../src/config/default/peripheral/dmac/plib_dmac.c  .generated_files/flags/default/a7084b3c9454dd35f371af4709d54be6bce8a6c4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865161661" 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d" -o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ../src/config/default/peripheral/dmac/plib_dmac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60167341/plib_eic.o: ../src/config/default/peripheral/eic/plib_eic.c  .generated_files/flags/default/254afd913e52416365b04ea869434092762f603b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60167341" 
	@${RM} ${OBJECTDIR}/_ext/60167341/plib_eic.o.d 
	@${RM} ${OBJECTDIR}/_ext/60167341/plib_eic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60167341/plib_eic.o.d" -o ${OBJECTDIR}/_ext/60167341/plib_eic.o ../src/config/default/peripheral/eic/plib_eic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1986646378/plib_evsys.o: ../src/config/default/peripheral/evsys/plib_evsys.c  .generated_files/flags/default/9ef5d026601ef010971f272ed49467aff7041a86 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1986646378" 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ../src/config/default/peripheral/evsys/plib_evsys.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1987437027/plib_freqm.o: ../src/config/default/peripheral/freqm/plib_freqm.c  .generated_files/flags/default/dd8ef3abfe51453102958c13ec1e14830eae83ed .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1987437027" 
	@${RM} ${OBJECTDIR}/_ext/1987437027/plib_freqm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1987437027/plib_freqm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1987437027/plib_freqm.o.d" -o ${OBJECTDIR}/_ext/1987437027/plib_freqm.o ../src/config/default/peripheral/freqm/plib_freqm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/7435df01890f39f753e42878f6708a6a34304d71 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o: ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/default/3218b600c0b708c60ec0a70756c28cca411a4654 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1593096446" 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/829342769/plib_pm.o: ../src/config/default/peripheral/pm/plib_pm.c  .generated_files/flags/default/abf42be7d83c295a76a0d7d4de2965408bab5de5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/829342769" 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o.d 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/829342769/plib_pm.o.d" -o ${OBJECTDIR}/_ext/829342769/plib_pm.o ../src/config/default/peripheral/pm/plib_pm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/2e5983f443b150fd088a23ddd69eceaefbb83148 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865585090/plib_rstc.o: ../src/config/default/peripheral/rstc/plib_rstc.c  .generated_files/flags/default/15c409bc6f0931de187665ff70106d4d83db3a8d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865585090" 
	@${RM} ${OBJECTDIR}/_ext/1865585090/plib_rstc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865585090/plib_rstc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865585090/plib_rstc.o.d" -o ${OBJECTDIR}/_ext/1865585090/plib_rstc.o ../src/config/default/peripheral/rstc/plib_rstc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o: ../src/config/default/peripheral/rtc/plib_rtc_clock.c  .generated_files/flags/default/d7d2b6ac8d810b0cf8b4a4ef1e33a3214f452c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60180175" 
	@${RM} ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o.d" -o ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o ../src/config/default/peripheral/rtc/plib_rtc_clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o: ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c  .generated_files/flags/default/864f84d39075da2c22e4b01acb6bf01e7e6eeec5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/508257091" 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o.d" -o ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c  .generated_files/flags/default/22f98508ffe14fd32456b2fc9694a62075a66023 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c  .generated_files/flags/default/ab8965482ad7de8e09a92287c690ca883ad86afe .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c  .generated_files/flags/default/90ea39d5db98c9d16b28d5519720ef71b4f7f771 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c  .generated_files/flags/default/834c526eb6668634db7ee608b2e6d712e8170900 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865616679/plib_supc.o: ../src/config/default/peripheral/supc/plib_supc.c  .generated_files/flags/default/57a976bd840194e04b647d330433d4de12237c70 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865616679" 
	@${RM} ${OBJECTDIR}/_ext/1865616679/plib_supc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865616679/plib_supc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865616679/plib_supc.o.d" -o ${OBJECTDIR}/_ext/1865616679/plib_supc.o ../src/config/default/peripheral/supc/plib_supc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/flags/default/23179aa8fff52c2e92a18ba5e63e247a95c3dc63 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60181570/plib_tcc0.o: ../src/config/default/peripheral/tcc/plib_tcc0.c  .generated_files/flags/default/a1cc9875cf6bc59e72c4fe56699557607e65ec73 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60181570" 
	@${RM} ${OBJECTDIR}/_ext/60181570/plib_tcc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60181570/plib_tcc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60181570/plib_tcc0.o.d" -o ${OBJECTDIR}/_ext/60181570/plib_tcc0.o ../src/config/default/peripheral/tcc/plib_tcc0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60184501/plib_wdt.o: ../src/config/default/peripheral/wdt/plib_wdt.c  .generated_files/flags/default/36c0138f72ce04f904d4b1ff43bcf45c43cbebe4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60184501" 
	@${RM} ${OBJECTDIR}/_ext/60184501/plib_wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/60184501/plib_wdt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60184501/plib_wdt.o.d" -o ${OBJECTDIR}/_ext/60184501/plib_wdt.o ../src/config/default/peripheral/wdt/plib_wdt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/ff3e05dcc68d0254bde83b773274d1e981ca527c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1832805299/sys_console_uart.o: ../src/config/default/system/console/src/sys_console_uart.c  .generated_files/flags/default/2f155006d29f1bb0467deb86a903720b3268f925 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1832805299" 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1832805299/sys_console_uart.o.d" -o ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o ../src/config/default/system/console/src/sys_console_uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1832805299/sys_console.o: ../src/config/default/system/console/src/sys_console.c  .generated_files/flags/default/c1a3beefab95f7dcd6c12bc52d1d410ca68cb9d5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1832805299" 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console.o.d 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1832805299/sys_console.o.d" -o ${OBJECTDIR}/_ext/1832805299/sys_console.o ../src/config/default/system/console/src/sys_console.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/14461671/sys_dma.o: ../src/config/default/system/dma/sys_dma.c  .generated_files/flags/default/26adeecf7104261b3d1565b8a1db1fd13a42979f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/14461671" 
	@${RM} ${OBJECTDIR}/_ext/14461671/sys_dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/14461671/sys_dma.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/14461671/sys_dma.o.d" -o ${OBJECTDIR}/_ext/14461671/sys_dma.o ../src/config/default/system/dma/sys_dma.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1881668453/sys_int.o: ../src/config/default/system/int/src/sys_int.c  .generated_files/flags/default/9172034f5be2b042e15ffa25f12ad3eaccbe933f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1881668453" 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1881668453/sys_int.o.d" -o ${OBJECTDIR}/_ext/1881668453/sys_int.o ../src/config/default/system/int/src/sys_int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o: ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c  .generated_files/flags/default/1826b32e05c343e8b84630cc44b8caa49e491460 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/692303624" 
	@${RM} ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o.d" -o ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o: ../src/config/default/system/net/src/sys_wincs_net_service.c  .generated_files/flags/default/58c15493f00c02626f3dcd60c286c90e627711e9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1766557203" 
	@${RM} ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o.d" -o ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o ../src/config/default/system/net/src/sys_wincs_net_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/101884895/sys_time.o: ../src/config/default/system/time/src/sys_time.c  .generated_files/flags/default/b02b7f72bc78a2a5435e41ecd2c4bd27a988b761 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/101884895" 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/101884895/sys_time.o.d" -o ${OBJECTDIR}/_ext/101884895/sys_time.o ../src/config/default/system/time/src/sys_time.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o: ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c  .generated_files/flags/default/ac4f3ff7d5db29f20c32357e416613c32b1b3c5e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/634868841" 
	@${RM} ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o.d" -o ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o: ../src/config/default/system/sys_wincs_system_service.c  .generated_files/flags/default/8d1d58b25625fc62ffb3778a50a59ce5d679db52 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/753841488" 
	@${RM} ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o.d" -o ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o ../src/config/default/system/sys_wincs_system_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/tasks.o: ../src/config/default/tasks.c  .generated_files/flags/default/b4ac19d9af90f71ee5ee49d9bddd3a97445c0570 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/tasks.o.d" -o ${OBJECTDIR}/_ext/1171490990/tasks.o ../src/config/default/tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/9cae033e629af7a2c0d4ace5e94f52184fc057a6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/feec7e2df77c135f14632875da984b25665b1b63 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/165ff79e401f6c9f6e3db47c60d8d59c9149d673 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/c9a2c03a0d8a34298d30e1b9873fb235cf026bfa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/4103e84d74d31446391818156768f20366db87e2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ad9954_driver.o: ../src/ad9954_driver.c  .generated_files/flags/default/63ee0bfb10da1b1aad0aa049e4f6e425c4b721e4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ad9954_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o ../src/ad9954_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/bme690_driver.o: ../src/bme690_driver.c  .generated_files/flags/default/c6aab2f8e9e711c55a0e038b9d768ff464bc6b66 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bme690_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bme690_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/bme690_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/bme690_driver.o ../src/bme690_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/bmp585_driver.o: ../src/bmp585_driver.c  .generated_files/flags/default/b1a8a66b4b3f290de7ef363ca8c2bb68e3e5929 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/bmp585_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o ../src/bmp585_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/can0_driver.o: ../src/can0_driver.c  .generated_files/flags/default/4171fe296da94730d2d80d3e8d06e45007ffb7df .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/can0_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/can0_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/can0_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/can0_driver.o ../src/can0_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/console_driver.o: ../src/console_driver.c  .generated_files/flags/default/a11bc77c082dcb6d3d6001f75053b322ea0fab29 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/console_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/console_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/console_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/console_driver.o ../src/console_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o: ../src/fcm360w_driver.c  .generated_files/flags/default/d593f8c3a32518e37dd5967527a7c1050f777238 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o ../src/fcm360w_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o: ../src/hdc302x_driver.c  .generated_files/flags/default/301f77e1a7169e2b2551ad618fa45490749e9a9a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o ../src/hdc302x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o: ../src/mcp9808_driver.c  .generated_files/flags/default/6a6cec9c41c71d205ea52843e1b823b612e77ca2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o ../src/mcp9808_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ntc_driver.o: ../src/ntc_driver.c  .generated_files/flags/default/11d6a32ee2746795b51cb48779500306a6a68694 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ntc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ntc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ntc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ntc_driver.o ../src/ntc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/rstc_driver.o: ../src/rstc_driver.c  .generated_files/flags/default/871c85af3c03abe730915406abd57f597e8c03ce .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rstc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rstc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/rstc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/rstc_driver.o ../src/rstc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/rtc_driver.o: ../src/rtc_driver.c  .generated_files/flags/default/d816271a482b87eca25d6f506efa48147860d85f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/rtc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/rtc_driver.o ../src/rtc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/sen63c_driver.o: ../src/sen63c_driver.c  .generated_files/flags/default/f763d47d9fd0057c36b31b2f0a7456fc2416369d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sen63c_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o ../src/sen63c_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/sht4x_driver.o: ../src/sht4x_driver.c  .generated_files/flags/default/12f3fefd399e3fb6e03bbadf4bbdf45ba33fef5b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sht4x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o ../src/sht4x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o: ../src/ssd1306_driver.c  .generated_files/flags/default/95f7d6c8ce56fa624c7b9a87b89979acedc9c528 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o ../src/ssd1306_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/stcc4_driver.o: ../src/stcc4_driver.c  .generated_files/flags/default/ddd6ac3d180bf1801fc84407633108a66a436c94 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/stcc4_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o ../src/stcc4_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/timer_driver.o: ../src/timer_driver.c  .generated_files/flags/default/7d8cc6dbb45353f48f7cf023c625a7d7434cdffc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/timer_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/timer_driver.o ../src/timer_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o: ../src/vcnl4200_driver.c  .generated_files/flags/default/6df5940c2f13c5cba72749a8704aab7efe5d8199 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o ../src/vcnl4200_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ws281x_driver.o: ../src/ws281x_driver.c  .generated_files/flags/default/9f39034a917e964c9a7c935cdc98ffa172b29c40 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ws281x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o ../src/ws281x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/xm125_driver.o: ../src/xm125_driver.c  .generated_files/flags/default/8b3184672becd2ca6246b1baecb31a9c67ff9531 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/xm125_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/xm125_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/xm125_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/xm125_driver.o ../src/xm125_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/wincs02_driver.o: ../src/wincs02_driver.c  .generated_files/flags/default/62f064691e9a4d0a45065ad92b0ea695ad49cc99 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/wincs02_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o ../src/wincs02_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/993e39ba03a55a96f8c3c14b746ee34f4c3d5a4a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/c296fc3ab1d2e93ed62c6230656e600d9f19b454 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c  .generated_files/flags/default/1bdce5c0505a043adb62bf4b2db4cbdaf6405c09 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/158385033/drv_i2c.o: ../src/config/default/driver/i2c/src/drv_i2c.c  .generated_files/flags/default/40291d453af65743a14d92fee76cc36a9f54adb7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/158385033" 
	@${RM} ${OBJECTDIR}/_ext/158385033/drv_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/158385033/drv_i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/158385033/drv_i2c.o.d" -o ${OBJECTDIR}/_ext/158385033/drv_i2c.o ../src/config/default/driver/i2c/src/drv_i2c.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/2070931557/drv_spi.o: ../src/config/default/driver/spi/src/drv_spi.c  .generated_files/flags/default/1bbe008248189d132574e46d449c0f79331b684f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2070931557" 
	@${RM} ${OBJECTDIR}/_ext/2070931557/drv_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070931557/drv_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/2070931557/drv_spi.o.d" -o ${OBJECTDIR}/_ext/2070931557/drv_spi.o ../src/config/default/driver/spi/src/drv_spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/869808652/drv_usart.o: ../src/config/default/driver/usart/src/drv_usart.c  .generated_files/flags/default/6c97df6aa9665d55f46034807924547ddc9f92d8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/869808652" 
	@${RM} ${OBJECTDIR}/_ext/869808652/drv_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/869808652/drv_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/869808652/drv_usart.o.d" -o ${OBJECTDIR}/_ext/869808652/drv_usart.o ../src/config/default/driver/usart/src/drv_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o: ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c  .generated_files/flags/default/538fe3a468d4cbdb3cb49b29abcd4fa942ba0db2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/622324608" 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o.d" -o ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o: ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c  .generated_files/flags/default/cb871ae78c17dc574bdefe93741a0b8313a0591e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/622324608" 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o.d 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o.d" -o ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_cmds.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c  .generated_files/flags/default/898c5a1fa56d91ef6d994f2fc8130370d0ec8f21 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmds.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmds.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_cmds.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_cmds.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c  .generated_files/flags/default/4c659575b30d68f831b64bda3c13a63453df069c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_dev.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c  .generated_files/flags/default/4aed5abba9d780f3aba37bc613650f2f67d09ec6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_dev.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_dev.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_dev.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_dev.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c  .generated_files/flags/default/8e2506c7d909da7c8d76b6f352f4b850054d9eb9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_socket.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c  .generated_files/flags/default/323b1d8a9dc13346eb1b43120400343923a9cd82 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_socket.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_socket.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_tables.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c  .generated_files/flags/default/65964432f6fdf45a7ee2d85e652db5f6c671f41f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_tables.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_tables.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_tables.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_tables.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc.c  .generated_files/flags/default/8ace2fd3040eb4dbd9571a6058de998e3193adf8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o ../src/config/default/driver/wifi/wincs02/wdrv_winc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c  .generated_files/flags/default/125ae4a6a5a74e0bdccc4bf5b77096601a1ceb86 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c  .generated_files/flags/default/79d6faf5e4df1d8a4934f26d6fa097ee23c9f9af .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c  .generated_files/flags/default/d9861992028382649e2f80a1e9443a8793fa2e9e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c  .generated_files/flags/default/d9bc005700351a880140b0164fb37d9fc477d1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c  .generated_files/flags/default/b13db2f58f7d6b2b7c8caca20078228b5e58cb73 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c  .generated_files/flags/default/6c577751069f1f3473342df004fb4b9a7c19b69 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c  .generated_files/flags/default/354546102969df481e923f09744f90be5b13b6b0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c  .generated_files/flags/default/64b028ff0d30ea3c55a8576b96b81e4218b288fe .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c  .generated_files/flags/default/f560728787f5849bce1989984c3d7b759876fd64 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c  .generated_files/flags/default/960eb2b3da838b29f8d3020539032be8d4bee42b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c  .generated_files/flags/default/ba792a3fdb1fe87a9db3fd77fb4607378920f667 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c  .generated_files/flags/default/bf20ca70fd696447a5d9578ed4fa63c0f256e8e4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c  .generated_files/flags/default/c06224bb4eec07b20ce4d7621de1e147e50b6877 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c  .generated_files/flags/default/adf54413454aa8e5dca90500748098101a664932 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c  .generated_files/flags/default/812db9d424226f2856629415ad3ba5a03d60cbcf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c  .generated_files/flags/default/db5052be282959d92e2daa33dc858efdb49b98f0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c  .generated_files/flags/default/dfd89a353c06ad106eed2f825a9daa708487b42e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c  .generated_files/flags/default/25dae72d8468bfce17f526f6c4827273583b9c1f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c  .generated_files/flags/default/1030eb52345c5d7decfa970dc0a24ac1f06e6612 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c  .generated_files/flags/default/dd564fdc9cbbb65fd1aedd9b92c081fd7e51cd1f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c  .generated_files/flags/default/eec6c214d72240adc05f5a1a41ae7c201371c6b1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c  .generated_files/flags/default/cb4b4cb59b2c9d40b9972356a2a89f8d7013dc18 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60163342/plib_adc0.o: ../src/config/default/peripheral/adc/plib_adc0.c  .generated_files/flags/default/1c8d92a91940f2f4ca06e6948211a684bb8e187a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60163342" 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60163342/plib_adc0.o.d" -o ${OBJECTDIR}/_ext/60163342/plib_adc0.o ../src/config/default/peripheral/adc/plib_adc0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60165182/plib_can0.o: ../src/config/default/peripheral/can/plib_can0.c  .generated_files/flags/default/37d4af4dd93442bc8315f0d00205d05c37b91ab8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60165182" 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60165182/plib_can0.o.d" -o ${OBJECTDIR}/_ext/60165182/plib_can0.o ../src/config/default/peripheral/can/plib_can0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1984496892/plib_clock.o: ../src/config/default/peripheral/clock/plib_clock.c  .generated_files/flags/default/a3c34d4e65202e1c73a3f9cd6769766174067c8d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1984496892" 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1984496892/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ../src/config/default/peripheral/clock/plib_clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60166132/plib_dac.o: ../src/config/default/peripheral/dac/plib_dac.c  .generated_files/flags/default/913781a37e8c40b10565d0b5d33b9f1c6d3bb61b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60166132" 
	@${RM} ${OBJECTDIR}/_ext/60166132/plib_dac.o.d 
	@${RM} ${OBJECTDIR}/_ext/60166132/plib_dac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60166132/plib_dac.o.d" -o ${OBJECTDIR}/_ext/60166132/plib_dac.o ../src/config/default/peripheral/dac/plib_dac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1985337713/plib_divas.o: ../src/config/default/peripheral/divas/plib_divas.c  .generated_files/flags/default/7d57873e3a79d586b1368df99472181b0ccf4a96 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1985337713" 
	@${RM} ${OBJECTDIR}/_ext/1985337713/plib_divas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1985337713/plib_divas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1985337713/plib_divas.o.d" -o ${OBJECTDIR}/_ext/1985337713/plib_divas.o ../src/config/default/peripheral/divas/plib_divas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865161661/plib_dmac.o: ../src/config/default/peripheral/dmac/plib_dmac.c  .generated_files/flags/default/a4e9ab855724b29bbea3aebd9b9d3fb7d0d358a6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865161661" 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d" -o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ../src/config/default/peripheral/dmac/plib_dmac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60167341/plib_eic.o: ../src/config/default/peripheral/eic/plib_eic.c  .generated_files/flags/default/2f8ecfd46f5669d3e2d29ffd729f3b9f8561c686 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60167341" 
	@${RM} ${OBJECTDIR}/_ext/60167341/plib_eic.o.d 
	@${RM} ${OBJECTDIR}/_ext/60167341/plib_eic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60167341/plib_eic.o.d" -o ${OBJECTDIR}/_ext/60167341/plib_eic.o ../src/config/default/peripheral/eic/plib_eic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1986646378/plib_evsys.o: ../src/config/default/peripheral/evsys/plib_evsys.c  .generated_files/flags/default/fd88db9dfe1f7e28b59920b03d3eefc6d35f9e99 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1986646378" 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ../src/config/default/peripheral/evsys/plib_evsys.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1987437027/plib_freqm.o: ../src/config/default/peripheral/freqm/plib_freqm.c  .generated_files/flags/default/a44c2fec9f9bceced8fd0495a8029b91cedf0ace .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1987437027" 
	@${RM} ${OBJECTDIR}/_ext/1987437027/plib_freqm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1987437027/plib_freqm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1987437027/plib_freqm.o.d" -o ${OBJECTDIR}/_ext/1987437027/plib_freqm.o ../src/config/default/peripheral/freqm/plib_freqm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/4c8b9acae6a5a934d5b60b223cb77cba1604152c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o: ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/default/9eedea723df180b815fa2f5f0db2541ea90e8d0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1593096446" 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/829342769/plib_pm.o: ../src/config/default/peripheral/pm/plib_pm.c  .generated_files/flags/default/3d3d44d261086d86c29a68a669db025dbfe3c977 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/829342769" 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o.d 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/829342769/plib_pm.o.d" -o ${OBJECTDIR}/_ext/829342769/plib_pm.o ../src/config/default/peripheral/pm/plib_pm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/62b8915660991e37aea8f6aecc1b78772a3d6862 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865585090/plib_rstc.o: ../src/config/default/peripheral/rstc/plib_rstc.c  .generated_files/flags/default/c974bcb6062bc8005614ed1c41b78483df2b472f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865585090" 
	@${RM} ${OBJECTDIR}/_ext/1865585090/plib_rstc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865585090/plib_rstc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865585090/plib_rstc.o.d" -o ${OBJECTDIR}/_ext/1865585090/plib_rstc.o ../src/config/default/peripheral/rstc/plib_rstc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o: ../src/config/default/peripheral/rtc/plib_rtc_clock.c  .generated_files/flags/default/f9c3ee28651fe779081ea7c8d4494ae058ebdde8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60180175" 
	@${RM} ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o.d" -o ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o ../src/config/default/peripheral/rtc/plib_rtc_clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o: ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c  .generated_files/flags/default/480627214ea0f30dc187233f237a4837ec542c74 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/508257091" 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o.d" -o ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c  .generated_files/flags/default/70654f1c527b76e85ffbda2a0621c34f9148be0f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c  .generated_files/flags/default/b74ebe4b4c144e530de3f2d10083d39964ccd697 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c  .generated_files/flags/default/74d501c3e4ba222cc560797db4bb901a748a7c61 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c  .generated_files/flags/default/a98190b93e5bccdd3c9b74a12b23d41a2ff26727 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865616679/plib_supc.o: ../src/config/default/peripheral/supc/plib_supc.c  .generated_files/flags/default/c9a3111f85650f466d11bb67d2a611610207ec7c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865616679" 
	@${RM} ${OBJECTDIR}/_ext/1865616679/plib_supc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865616679/plib_supc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865616679/plib_supc.o.d" -o ${OBJECTDIR}/_ext/1865616679/plib_supc.o ../src/config/default/peripheral/supc/plib_supc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/flags/default/290634a25e7b2f3f84352a6aa0b2930732dd5bbc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60181570/plib_tcc0.o: ../src/config/default/peripheral/tcc/plib_tcc0.c  .generated_files/flags/default/8829659023d6a6cea41696dc071f1a7afd0470ba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60181570" 
	@${RM} ${OBJECTDIR}/_ext/60181570/plib_tcc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60181570/plib_tcc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60181570/plib_tcc0.o.d" -o ${OBJECTDIR}/_ext/60181570/plib_tcc0.o ../src/config/default/peripheral/tcc/plib_tcc0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60184501/plib_wdt.o: ../src/config/default/peripheral/wdt/plib_wdt.c  .generated_files/flags/default/34d38f226ecb4a22e2025692e3ebcc0abc164ce .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60184501" 
	@${RM} ${OBJECTDIR}/_ext/60184501/plib_wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/60184501/plib_wdt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60184501/plib_wdt.o.d" -o ${OBJECTDIR}/_ext/60184501/plib_wdt.o ../src/config/default/peripheral/wdt/plib_wdt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/175154cb7c32e67e9f49a28fad5ae6cd37e65093 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1832805299/sys_console_uart.o: ../src/config/default/system/console/src/sys_console_uart.c  .generated_files/flags/default/7ee9578ddd3436f3a52469116d5a83cd6a48e0c2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1832805299" 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1832805299/sys_console_uart.o.d" -o ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o ../src/config/default/system/console/src/sys_console_uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1832805299/sys_console.o: ../src/config/default/system/console/src/sys_console.c  .generated_files/flags/default/489393e782501175c5f96b5757e874476b98a73a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1832805299" 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console.o.d 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1832805299/sys_console.o.d" -o ${OBJECTDIR}/_ext/1832805299/sys_console.o ../src/config/default/system/console/src/sys_console.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/14461671/sys_dma.o: ../src/config/default/system/dma/sys_dma.c  .generated_files/flags/default/70642a339ecff48c6737e266d609adc149e96a8e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/14461671" 
	@${RM} ${OBJECTDIR}/_ext/14461671/sys_dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/14461671/sys_dma.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/14461671/sys_dma.o.d" -o ${OBJECTDIR}/_ext/14461671/sys_dma.o ../src/config/default/system/dma/sys_dma.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1881668453/sys_int.o: ../src/config/default/system/int/src/sys_int.c  .generated_files/flags/default/a959d2000c635c910a08e9abd1a2db7e219dbeba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1881668453" 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1881668453/sys_int.o.d" -o ${OBJECTDIR}/_ext/1881668453/sys_int.o ../src/config/default/system/int/src/sys_int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o: ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c  .generated_files/flags/default/a6facd926d6c7d260241228a962a18952ee04c5b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/692303624" 
	@${RM} ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o.d" -o ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o: ../src/config/default/system/net/src/sys_wincs_net_service.c  .generated_files/flags/default/69e298bdff41187a16d0dd2ccde62bc5f16c4178 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1766557203" 
	@${RM} ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o.d" -o ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o ../src/config/default/system/net/src/sys_wincs_net_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/101884895/sys_time.o: ../src/config/default/system/time/src/sys_time.c  .generated_files/flags/default/67727495832998ae2696a32baecc473c99e35ae8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/101884895" 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/101884895/sys_time.o.d" -o ${OBJECTDIR}/_ext/101884895/sys_time.o ../src/config/default/system/time/src/sys_time.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o: ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c  .generated_files/flags/default/d28234751327b0195344a3821bf6d5adac063a44 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/634868841" 
	@${RM} ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o.d" -o ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o: ../src/config/default/system/sys_wincs_system_service.c  .generated_files/flags/default/aeba2821999b24bcec9160edd7590067e99e756a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/753841488" 
	@${RM} ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o.d" -o ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o ../src/config/default/system/sys_wincs_system_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/tasks.o: ../src/config/default/tasks.c  .generated_files/flags/default/ae21047a5b3d88c1386654676db8a0842def3766 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/tasks.o.d" -o ${OBJECTDIR}/_ext/1171490990/tasks.o ../src/config/default/tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/d3a3182174da8575b00b2e88c6ad5031359000c0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/74b4f4812b34570d1e704c7e138e53d68c7e1b5c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/7d34228432dee3ce7c75280ebc5d196185bbee4d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/484ebeaf85352169cd13f104910f2bf7d14f1b07 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/fcbc3d45ebda41454f43ffe2629cd4eabbb3bcfe .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ad9954_driver.o: ../src/ad9954_driver.c  .generated_files/flags/default/51b63958b770452eda7c404b2468af01ea404178 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ad9954_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o ../src/ad9954_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/bme690_driver.o: ../src/bme690_driver.c  .generated_files/flags/default/30800b1b42355e584ba1cda684ffc92e472a3121 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bme690_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bme690_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/bme690_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/bme690_driver.o ../src/bme690_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/bmp585_driver.o: ../src/bmp585_driver.c  .generated_files/flags/default/ef435856bfe09cfea7c80827d07272213e9b2bb5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/bmp585_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o ../src/bmp585_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/can0_driver.o: ../src/can0_driver.c  .generated_files/flags/default/3c7cc2e8ad8f25c49478debdcca323e5b68e38f9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/can0_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/can0_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/can0_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/can0_driver.o ../src/can0_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/console_driver.o: ../src/console_driver.c  .generated_files/flags/default/e05b5cee35cf5e706354a14bfa5e4171b7a0c133 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/console_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/console_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/console_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/console_driver.o ../src/console_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o: ../src/fcm360w_driver.c  .generated_files/flags/default/c1ee8d70cb66be34debca892360a9fb73ebe7a27 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o ../src/fcm360w_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o: ../src/hdc302x_driver.c  .generated_files/flags/default/3cb2efd8b3e4923029457533f27d5819a3672873 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o ../src/hdc302x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o: ../src/mcp9808_driver.c  .generated_files/flags/default/87b838537a1ad4703b947e94602ac745ae3c9209 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o ../src/mcp9808_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ntc_driver.o: ../src/ntc_driver.c  .generated_files/flags/default/fb1d924a216d764be64979ff7d4ce49ec8be770f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ntc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ntc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ntc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ntc_driver.o ../src/ntc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/rstc_driver.o: ../src/rstc_driver.c  .generated_files/flags/default/ad5c4e10c2a294204a65e096f09ada1a18d7bad7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rstc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rstc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/rstc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/rstc_driver.o ../src/rstc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/rtc_driver.o: ../src/rtc_driver.c  .generated_files/flags/default/cced9e05dd2ee8217a461fdef3563f55d497840a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/rtc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/rtc_driver.o ../src/rtc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/sen63c_driver.o: ../src/sen63c_driver.c  .generated_files/flags/default/145e0776be5b64affbe71dbc0ed714d76757acf1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sen63c_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o ../src/sen63c_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/sht4x_driver.o: ../src/sht4x_driver.c  .generated_files/flags/default/1b0909603f6c4a2393e278e41f9230670b449514 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sht4x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o ../src/sht4x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o: ../src/ssd1306_driver.c  .generated_files/flags/default/c2834ed883d025856eca9442bc88bbb348daa497 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o ../src/ssd1306_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/stcc4_driver.o: ../src/stcc4_driver.c  .generated_files/flags/default/1946b654e4ccfe7014fe8548e782c46e56a99974 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/stcc4_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o ../src/stcc4_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/timer_driver.o: ../src/timer_driver.c  .generated_files/flags/default/903b3c51a15033ad9963b6ce7b26f8deae30e0ce .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/timer_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/timer_driver.o ../src/timer_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o: ../src/vcnl4200_driver.c  .generated_files/flags/default/80c3072c1ad37d650b5dcfb68f81583ffe606e98 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o ../src/vcnl4200_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ws281x_driver.o: ../src/ws281x_driver.c  .generated_files/flags/default/fabb49f4a04af1c4c18247785413e445a952e27c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ws281x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o ../src/ws281x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/xm125_driver.o: ../src/xm125_driver.c  .generated_files/flags/default/81af69d5a80c8a8b20ad4f0a8a49b64f52cb9942 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/xm125_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/xm125_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/xm125_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/xm125_driver.o ../src/xm125_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/wincs02_driver.o: ../src/wincs02_driver.c  .generated_files/flags/default/955236d987b512dada3764cab6c8c0a3526057f8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/wincs02_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o ../src/wincs02_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/9f90934da4fc13f719b3719da73dd6698611e7c3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/30387c44b42ec4109d09183b17d04f5060adfa2e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c  .generated_files/flags/default/d6e7154735aa7fc74a4dfc396d2cae90cd2af383 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    ../src/config/default/PIC32CM5164JH01100.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -mno-device-startup-code -o ${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=8192,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}/PIC32CM-JH01"
	
else
${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/default/PIC32CM5164JH01100.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -mno-device-startup-code -o ${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=8192,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}/PIC32CM-JH01"
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
