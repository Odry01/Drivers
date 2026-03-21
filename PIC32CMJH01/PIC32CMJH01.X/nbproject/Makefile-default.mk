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
SOURCEFILES_QUOTED_IF_SPACED=../src/config/default/driver/i2c/src/drv_i2c.c ../src/config/default/driver/spi/src/drv_spi.c ../src/config/default/driver/usart/src/drv_usart.c ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c ../src/config/default/driver/wifi/wincs02/wdrv_winc.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c ../src/config/default/peripheral/adc/plib_adc0.c ../src/config/default/peripheral/can/plib_can0.c ../src/config/default/peripheral/clock/plib_clock.c ../src/config/default/peripheral/dac/plib_dac.c ../src/config/default/peripheral/divas/plib_divas.c ../src/config/default/peripheral/dmac/plib_dmac.c ../src/config/default/peripheral/eic/plib_eic.c ../src/config/default/peripheral/evsys/plib_evsys.c ../src/config/default/peripheral/freqm/plib_freqm.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/default/peripheral/pm/plib_pm.c ../src/config/default/peripheral/port/plib_port.c ../src/config/default/peripheral/rstc/plib_rstc.c ../src/config/default/peripheral/rtc/plib_rtc_clock.c ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c ../src/config/default/peripheral/supc/plib_supc.c ../src/config/default/peripheral/systick/plib_systick.c ../src/config/default/peripheral/tcc/plib_tcc0.c ../src/config/default/peripheral/wdt/plib_wdt.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/system/console/src/sys_console_uart.c ../src/config/default/system/console/src/sys_console.c ../src/config/default/system/dma/sys_dma.c ../src/config/default/system/int/src/sys_int.c ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c ../src/config/default/system/net/src/sys_wincs_net_service.c ../src/config/default/system/time/src/sys_time.c ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c ../src/config/default/system/sys_wincs_system_service.c ../src/config/default/tasks.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/ad9954_driver.c ../src/bme690_driver.c ../src/bmp585_driver.c ../src/can0_driver.c ../src/console_driver.c ../src/fcm360w_driver.c ../src/hdc302x_driver.c ../src/mcp9808_driver.c ../src/ntc_driver.c ../src/rstc_driver.c ../src/rtc_driver.c ../src/sen63c_driver.c ../src/sht4x_driver.c ../src/ssd1306_driver.c ../src/stcc4_driver.c ../src/timer_driver.c ../src/vcnl4200_driver.c ../src/ws281x_driver.c ../src/xm125_driver.c ../src/wincs02_driver.c ../src/app.c ../src/main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/158385033/drv_i2c.o ${OBJECTDIR}/_ext/2070931557/drv_spi.o ${OBJECTDIR}/_ext/869808652/drv_usart.o ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o ${OBJECTDIR}/_ext/1857064221/winc_cmds.o ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o ${OBJECTDIR}/_ext/1857064221/winc_dev.o ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o ${OBJECTDIR}/_ext/1857064221/winc_socket.o ${OBJECTDIR}/_ext/1857064221/winc_tables.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o ${OBJECTDIR}/_ext/60163342/plib_adc0.o ${OBJECTDIR}/_ext/60165182/plib_can0.o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ${OBJECTDIR}/_ext/60166132/plib_dac.o ${OBJECTDIR}/_ext/1985337713/plib_divas.o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ${OBJECTDIR}/_ext/60167341/plib_eic.o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ${OBJECTDIR}/_ext/1987437027/plib_freqm.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ${OBJECTDIR}/_ext/829342769/plib_pm.o ${OBJECTDIR}/_ext/1865521619/plib_port.o ${OBJECTDIR}/_ext/1865585090/plib_rstc.o ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o ${OBJECTDIR}/_ext/1865616679/plib_supc.o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ${OBJECTDIR}/_ext/60181570/plib_tcc0.o ${OBJECTDIR}/_ext/60184501/plib_wdt.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o ${OBJECTDIR}/_ext/1832805299/sys_console.o ${OBJECTDIR}/_ext/14461671/sys_dma.o ${OBJECTDIR}/_ext/1881668453/sys_int.o ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o ${OBJECTDIR}/_ext/101884895/sys_time.o ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o ${OBJECTDIR}/_ext/1171490990/tasks.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o ${OBJECTDIR}/_ext/1360937237/bme690_driver.o ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o ${OBJECTDIR}/_ext/1360937237/can0_driver.o ${OBJECTDIR}/_ext/1360937237/console_driver.o ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o ${OBJECTDIR}/_ext/1360937237/ntc_driver.o ${OBJECTDIR}/_ext/1360937237/rstc_driver.o ${OBJECTDIR}/_ext/1360937237/rtc_driver.o ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o ${OBJECTDIR}/_ext/1360937237/timer_driver.o ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o ${OBJECTDIR}/_ext/1360937237/xm125_driver.o ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/158385033/drv_i2c.o.d ${OBJECTDIR}/_ext/2070931557/drv_spi.o.d ${OBJECTDIR}/_ext/869808652/drv_usart.o.d ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o.d ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o.d ${OBJECTDIR}/_ext/1857064221/winc_cmds.o.d ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o.d ${OBJECTDIR}/_ext/1857064221/winc_dev.o.d ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o.d ${OBJECTDIR}/_ext/1857064221/winc_socket.o.d ${OBJECTDIR}/_ext/1857064221/winc_tables.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o.d ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o.d ${OBJECTDIR}/_ext/60163342/plib_adc0.o.d ${OBJECTDIR}/_ext/60165182/plib_can0.o.d ${OBJECTDIR}/_ext/1984496892/plib_clock.o.d ${OBJECTDIR}/_ext/60166132/plib_dac.o.d ${OBJECTDIR}/_ext/1985337713/plib_divas.o.d ${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d ${OBJECTDIR}/_ext/60167341/plib_eic.o.d ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d ${OBJECTDIR}/_ext/1987437027/plib_freqm.o.d ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d ${OBJECTDIR}/_ext/829342769/plib_pm.o.d ${OBJECTDIR}/_ext/1865521619/plib_port.o.d ${OBJECTDIR}/_ext/1865585090/plib_rstc.o.d ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o.d ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o.d ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o.d ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o.d ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o.d ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o.d ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o.d ${OBJECTDIR}/_ext/1865616679/plib_supc.o.d ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d ${OBJECTDIR}/_ext/60181570/plib_tcc0.o.d ${OBJECTDIR}/_ext/60184501/plib_wdt.o.d ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o.d ${OBJECTDIR}/_ext/1832805299/sys_console.o.d ${OBJECTDIR}/_ext/14461671/sys_dma.o.d ${OBJECTDIR}/_ext/1881668453/sys_int.o.d ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o.d ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o.d ${OBJECTDIR}/_ext/101884895/sys_time.o.d ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o.d ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o.d ${OBJECTDIR}/_ext/1171490990/tasks.o.d ${OBJECTDIR}/_ext/1171490990/initialization.o.d ${OBJECTDIR}/_ext/1171490990/interrupts.o.d ${OBJECTDIR}/_ext/1171490990/exceptions.o.d ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o.d ${OBJECTDIR}/_ext/1360937237/bme690_driver.o.d ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o.d ${OBJECTDIR}/_ext/1360937237/can0_driver.o.d ${OBJECTDIR}/_ext/1360937237/console_driver.o.d ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o.d ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o.d ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o.d ${OBJECTDIR}/_ext/1360937237/ntc_driver.o.d ${OBJECTDIR}/_ext/1360937237/rstc_driver.o.d ${OBJECTDIR}/_ext/1360937237/rtc_driver.o.d ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o.d ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o.d ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o.d ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o.d ${OBJECTDIR}/_ext/1360937237/timer_driver.o.d ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o.d ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o.d ${OBJECTDIR}/_ext/1360937237/xm125_driver.o.d ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/158385033/drv_i2c.o ${OBJECTDIR}/_ext/2070931557/drv_spi.o ${OBJECTDIR}/_ext/869808652/drv_usart.o ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o ${OBJECTDIR}/_ext/1857064221/winc_cmds.o ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o ${OBJECTDIR}/_ext/1857064221/winc_dev.o ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o ${OBJECTDIR}/_ext/1857064221/winc_socket.o ${OBJECTDIR}/_ext/1857064221/winc_tables.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o ${OBJECTDIR}/_ext/60163342/plib_adc0.o ${OBJECTDIR}/_ext/60165182/plib_can0.o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ${OBJECTDIR}/_ext/60166132/plib_dac.o ${OBJECTDIR}/_ext/1985337713/plib_divas.o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ${OBJECTDIR}/_ext/60167341/plib_eic.o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ${OBJECTDIR}/_ext/1987437027/plib_freqm.o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ${OBJECTDIR}/_ext/829342769/plib_pm.o ${OBJECTDIR}/_ext/1865521619/plib_port.o ${OBJECTDIR}/_ext/1865585090/plib_rstc.o ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o ${OBJECTDIR}/_ext/1865616679/plib_supc.o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ${OBJECTDIR}/_ext/60181570/plib_tcc0.o ${OBJECTDIR}/_ext/60184501/plib_wdt.o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o ${OBJECTDIR}/_ext/1832805299/sys_console.o ${OBJECTDIR}/_ext/14461671/sys_dma.o ${OBJECTDIR}/_ext/1881668453/sys_int.o ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o ${OBJECTDIR}/_ext/101884895/sys_time.o ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o ${OBJECTDIR}/_ext/1171490990/tasks.o ${OBJECTDIR}/_ext/1171490990/initialization.o ${OBJECTDIR}/_ext/1171490990/interrupts.o ${OBJECTDIR}/_ext/1171490990/exceptions.o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o ${OBJECTDIR}/_ext/1360937237/bme690_driver.o ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o ${OBJECTDIR}/_ext/1360937237/can0_driver.o ${OBJECTDIR}/_ext/1360937237/console_driver.o ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o ${OBJECTDIR}/_ext/1360937237/ntc_driver.o ${OBJECTDIR}/_ext/1360937237/rstc_driver.o ${OBJECTDIR}/_ext/1360937237/rtc_driver.o ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o ${OBJECTDIR}/_ext/1360937237/timer_driver.o ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o ${OBJECTDIR}/_ext/1360937237/xm125_driver.o ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o

# Source Files
SOURCEFILES=../src/config/default/driver/i2c/src/drv_i2c.c ../src/config/default/driver/spi/src/drv_spi.c ../src/config/default/driver/usart/src/drv_usart.c ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c ../src/config/default/driver/wifi/wincs02/wdrv_winc.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c ../src/config/default/peripheral/adc/plib_adc0.c ../src/config/default/peripheral/can/plib_can0.c ../src/config/default/peripheral/clock/plib_clock.c ../src/config/default/peripheral/dac/plib_dac.c ../src/config/default/peripheral/divas/plib_divas.c ../src/config/default/peripheral/dmac/plib_dmac.c ../src/config/default/peripheral/eic/plib_eic.c ../src/config/default/peripheral/evsys/plib_evsys.c ../src/config/default/peripheral/freqm/plib_freqm.c ../src/config/default/peripheral/nvic/plib_nvic.c ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c ../src/config/default/peripheral/pm/plib_pm.c ../src/config/default/peripheral/port/plib_port.c ../src/config/default/peripheral/rstc/plib_rstc.c ../src/config/default/peripheral/rtc/plib_rtc_clock.c ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c ../src/config/default/peripheral/supc/plib_supc.c ../src/config/default/peripheral/systick/plib_systick.c ../src/config/default/peripheral/tcc/plib_tcc0.c ../src/config/default/peripheral/wdt/plib_wdt.c ../src/config/default/stdio/xc32_monitor.c ../src/config/default/system/console/src/sys_console_uart.c ../src/config/default/system/console/src/sys_console.c ../src/config/default/system/dma/sys_dma.c ../src/config/default/system/int/src/sys_int.c ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c ../src/config/default/system/net/src/sys_wincs_net_service.c ../src/config/default/system/time/src/sys_time.c ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c ../src/config/default/system/sys_wincs_system_service.c ../src/config/default/tasks.c ../src/config/default/initialization.c ../src/config/default/interrupts.c ../src/config/default/exceptions.c ../src/config/default/startup_xc32.c ../src/config/default/libc_syscalls.c ../src/ad9954_driver.c ../src/bme690_driver.c ../src/bmp585_driver.c ../src/can0_driver.c ../src/console_driver.c ../src/fcm360w_driver.c ../src/hdc302x_driver.c ../src/mcp9808_driver.c ../src/ntc_driver.c ../src/rstc_driver.c ../src/rtc_driver.c ../src/sen63c_driver.c ../src/sht4x_driver.c ../src/ssd1306_driver.c ../src/stcc4_driver.c ../src/timer_driver.c ../src/vcnl4200_driver.c ../src/ws281x_driver.c ../src/xm125_driver.c ../src/wincs02_driver.c ../src/app.c ../src/main.c

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
${OBJECTDIR}/_ext/158385033/drv_i2c.o: ../src/config/default/driver/i2c/src/drv_i2c.c  .generated_files/flags/default/383a237158c4d2dd58273d27231e5e4a68c3fe0b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/158385033" 
	@${RM} ${OBJECTDIR}/_ext/158385033/drv_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/158385033/drv_i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/158385033/drv_i2c.o.d" -o ${OBJECTDIR}/_ext/158385033/drv_i2c.o ../src/config/default/driver/i2c/src/drv_i2c.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/2070931557/drv_spi.o: ../src/config/default/driver/spi/src/drv_spi.c  .generated_files/flags/default/f380f293bbe75b92b4a594a06c8b066d6aace3dd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2070931557" 
	@${RM} ${OBJECTDIR}/_ext/2070931557/drv_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070931557/drv_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/2070931557/drv_spi.o.d" -o ${OBJECTDIR}/_ext/2070931557/drv_spi.o ../src/config/default/driver/spi/src/drv_spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/869808652/drv_usart.o: ../src/config/default/driver/usart/src/drv_usart.c  .generated_files/flags/default/693fb7cc5d23fc6a5e8a640b4a9d811a1890ae04 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/869808652" 
	@${RM} ${OBJECTDIR}/_ext/869808652/drv_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/869808652/drv_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/869808652/drv_usart.o.d" -o ${OBJECTDIR}/_ext/869808652/drv_usart.o ../src/config/default/driver/usart/src/drv_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o: ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c  .generated_files/flags/default/101ce29d0c26b0f75b731ba92dfccd82ac7fecc2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/622324608" 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o.d" -o ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o: ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c  .generated_files/flags/default/af8cf6f013e43cbf80756fe5ee9397160b90d958 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/622324608" 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o.d 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o.d" -o ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_cmds.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c  .generated_files/flags/default/a4242a609ed4f89539fe74ba14dbf112dd705cf2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmds.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmds.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_cmds.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_cmds.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c  .generated_files/flags/default/18066a49d0fd49a10e951e4fd0c1a71b374a35ba .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_dev.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c  .generated_files/flags/default/d2de66a336483253f2acd8d5aa2717c2ec059ce4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_dev.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_dev.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_dev.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_dev.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c  .generated_files/flags/default/c6102ae11df19ea42a31218df627d4f1db15fde0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_socket.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c  .generated_files/flags/default/d2ed1357763699f5ef166579474600d3a1421214 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_socket.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_socket.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_tables.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c  .generated_files/flags/default/5a82b83dc578b32457dcf4eed3fca88cd940694d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_tables.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_tables.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_tables.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_tables.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc.c  .generated_files/flags/default/9dc16ee13fa0e6d5c822794840536c5111afcf13 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o ../src/config/default/driver/wifi/wincs02/wdrv_winc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c  .generated_files/flags/default/b9fb8a4c271f97521f743af1a7750c586ad5ace1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c  .generated_files/flags/default/acda4dae7bce9a0d16e5773e6450e0a8f2f311cb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c  .generated_files/flags/default/98338cda920221b3eed942d3cf4df424a6adb607 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c  .generated_files/flags/default/1b23b035cc2540f44672e9d406b7d3460cff1141 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c  .generated_files/flags/default/b0846de0cef0f4760e2f505d550f151c0512ca08 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c  .generated_files/flags/default/e1439170b5de4ce5a1219d018bc220d53c54a4ed .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c  .generated_files/flags/default/933f1e322872c349d7714a3600f1ea57c7eef2b5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c  .generated_files/flags/default/82af2861b731c5391acbc084b1df1983a08c6cfd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c  .generated_files/flags/default/73a1a190ed23f46aac344434da600d8d738ef336 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c  .generated_files/flags/default/edef7568eb868d5bf8335da8127c8e2a34ecbec2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c  .generated_files/flags/default/c41176a63032f6d166bca144d4b76eb1c41df8f6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c  .generated_files/flags/default/3675930f5d3392eee1f1f6c69098448bb886505a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c  .generated_files/flags/default/3070e04fab397a8ae94fdcf6ad9cf77ceb0497a2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c  .generated_files/flags/default/860bb23afa774657bba461b0e68212f65028633a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c  .generated_files/flags/default/407e854a1fe101c62c42e78ec4eb19a79298fc1e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c  .generated_files/flags/default/fe446e1387de06bdac5e14a1a81c91dd95949944 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c  .generated_files/flags/default/287ca214073fa0076eca43708c38adc2a30cfe1b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c  .generated_files/flags/default/930e1d518b4d85c33898b4b740b855bd12ab9ccd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c  .generated_files/flags/default/2cb3cfc16f5a7a1e45cb15576f58f5dbad37a801 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c  .generated_files/flags/default/fbf47a8de777a7bc646be0026ab09727a52af787 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c  .generated_files/flags/default/4f3bd23e300d9c2ba3eef6aa06944323208c802e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c  .generated_files/flags/default/f1b2948a8be19457f553af2025493b757d4eec24 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60163342/plib_adc0.o: ../src/config/default/peripheral/adc/plib_adc0.c  .generated_files/flags/default/b1e2da5c21a24307cca29611d7a47d5c8c230aed .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60163342" 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60163342/plib_adc0.o.d" -o ${OBJECTDIR}/_ext/60163342/plib_adc0.o ../src/config/default/peripheral/adc/plib_adc0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60165182/plib_can0.o: ../src/config/default/peripheral/can/plib_can0.c  .generated_files/flags/default/bbd2b4a37467e48e3d1b078179b62af03622d5f1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60165182" 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60165182/plib_can0.o.d" -o ${OBJECTDIR}/_ext/60165182/plib_can0.o ../src/config/default/peripheral/can/plib_can0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1984496892/plib_clock.o: ../src/config/default/peripheral/clock/plib_clock.c  .generated_files/flags/default/439a3f67d50cc03ccbd0f75470a6d9a45fdbfb41 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1984496892" 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1984496892/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ../src/config/default/peripheral/clock/plib_clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60166132/plib_dac.o: ../src/config/default/peripheral/dac/plib_dac.c  .generated_files/flags/default/850ede5506ed301ce4fd8da8bd6796241143d55b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60166132" 
	@${RM} ${OBJECTDIR}/_ext/60166132/plib_dac.o.d 
	@${RM} ${OBJECTDIR}/_ext/60166132/plib_dac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60166132/plib_dac.o.d" -o ${OBJECTDIR}/_ext/60166132/plib_dac.o ../src/config/default/peripheral/dac/plib_dac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1985337713/plib_divas.o: ../src/config/default/peripheral/divas/plib_divas.c  .generated_files/flags/default/7fe059036cd3efb54c5b5ced3fdde4f52fb7914d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1985337713" 
	@${RM} ${OBJECTDIR}/_ext/1985337713/plib_divas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1985337713/plib_divas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1985337713/plib_divas.o.d" -o ${OBJECTDIR}/_ext/1985337713/plib_divas.o ../src/config/default/peripheral/divas/plib_divas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865161661/plib_dmac.o: ../src/config/default/peripheral/dmac/plib_dmac.c  .generated_files/flags/default/f1d78cdd1b9636bce17f9c22a4b1b0a6e18ec04b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865161661" 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d" -o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ../src/config/default/peripheral/dmac/plib_dmac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60167341/plib_eic.o: ../src/config/default/peripheral/eic/plib_eic.c  .generated_files/flags/default/1c396f1977354044a9b70b1cb59756b27259c464 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60167341" 
	@${RM} ${OBJECTDIR}/_ext/60167341/plib_eic.o.d 
	@${RM} ${OBJECTDIR}/_ext/60167341/plib_eic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60167341/plib_eic.o.d" -o ${OBJECTDIR}/_ext/60167341/plib_eic.o ../src/config/default/peripheral/eic/plib_eic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1986646378/plib_evsys.o: ../src/config/default/peripheral/evsys/plib_evsys.c  .generated_files/flags/default/86a37a115b550539274e79c4a8a7ba79fee4b54b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1986646378" 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ../src/config/default/peripheral/evsys/plib_evsys.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1987437027/plib_freqm.o: ../src/config/default/peripheral/freqm/plib_freqm.c  .generated_files/flags/default/d9ccc8449783444144432279bfe53d685c913821 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1987437027" 
	@${RM} ${OBJECTDIR}/_ext/1987437027/plib_freqm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1987437027/plib_freqm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1987437027/plib_freqm.o.d" -o ${OBJECTDIR}/_ext/1987437027/plib_freqm.o ../src/config/default/peripheral/freqm/plib_freqm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/e97bf8d554bd23e2ba2dfcea0c384f5e5ad7ba2c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o: ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/default/9b7eae3864369e509e42569eb3f0ccd26b8c4707 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1593096446" 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/829342769/plib_pm.o: ../src/config/default/peripheral/pm/plib_pm.c  .generated_files/flags/default/5d8646a6a7ee6ca9c769c4c5544a4978d7ad37ef .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/829342769" 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o.d 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/829342769/plib_pm.o.d" -o ${OBJECTDIR}/_ext/829342769/plib_pm.o ../src/config/default/peripheral/pm/plib_pm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/dd804867872a705490fac938569074f477108b50 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865585090/plib_rstc.o: ../src/config/default/peripheral/rstc/plib_rstc.c  .generated_files/flags/default/cce056b969f3f098a76055e8a636f6fde5decda2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865585090" 
	@${RM} ${OBJECTDIR}/_ext/1865585090/plib_rstc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865585090/plib_rstc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865585090/plib_rstc.o.d" -o ${OBJECTDIR}/_ext/1865585090/plib_rstc.o ../src/config/default/peripheral/rstc/plib_rstc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o: ../src/config/default/peripheral/rtc/plib_rtc_clock.c  .generated_files/flags/default/c79bdcad6c7c66a46b860eb67ec2fb316e954da .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60180175" 
	@${RM} ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o.d" -o ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o ../src/config/default/peripheral/rtc/plib_rtc_clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o: ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c  .generated_files/flags/default/eaf8c77d0ea9853e45d2e347d48c58046c30cdbf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/508257091" 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o.d" -o ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c  .generated_files/flags/default/41021454f493220426c17ae818e27b9e3f1c1741 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c  .generated_files/flags/default/3d7b2358023bfa49e7a8f707fbb40cba5646b9a9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c  .generated_files/flags/default/4c0d947e615cbddf28146e0ef7e601bea0590f0c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c  .generated_files/flags/default/ce0ec3db5ccd182e995571da905877d9d31aa06d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c  .generated_files/flags/default/945fb87a13962f72b5c25e4c4c47bd3ba87958ab .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865616679/plib_supc.o: ../src/config/default/peripheral/supc/plib_supc.c  .generated_files/flags/default/cc1b77fd7d51e127a3a3bf6bc4c022adc8729f5a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865616679" 
	@${RM} ${OBJECTDIR}/_ext/1865616679/plib_supc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865616679/plib_supc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865616679/plib_supc.o.d" -o ${OBJECTDIR}/_ext/1865616679/plib_supc.o ../src/config/default/peripheral/supc/plib_supc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/flags/default/66f1d077d8c80c537fc920bcb2e899b3b4673c7a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60181570/plib_tcc0.o: ../src/config/default/peripheral/tcc/plib_tcc0.c  .generated_files/flags/default/c51bdbd83591e546e80c98efd2d9161b1bf132b8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60181570" 
	@${RM} ${OBJECTDIR}/_ext/60181570/plib_tcc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60181570/plib_tcc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60181570/plib_tcc0.o.d" -o ${OBJECTDIR}/_ext/60181570/plib_tcc0.o ../src/config/default/peripheral/tcc/plib_tcc0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60184501/plib_wdt.o: ../src/config/default/peripheral/wdt/plib_wdt.c  .generated_files/flags/default/9e3261a1e52a1db6bc8dd23601bed57bb1bac7e6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60184501" 
	@${RM} ${OBJECTDIR}/_ext/60184501/plib_wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/60184501/plib_wdt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60184501/plib_wdt.o.d" -o ${OBJECTDIR}/_ext/60184501/plib_wdt.o ../src/config/default/peripheral/wdt/plib_wdt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/14aafbb3a79bff7964a1ba4003ac691f61592743 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1832805299/sys_console_uart.o: ../src/config/default/system/console/src/sys_console_uart.c  .generated_files/flags/default/4f872afd8892381e9248ad2e659406d107938b46 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1832805299" 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1832805299/sys_console_uart.o.d" -o ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o ../src/config/default/system/console/src/sys_console_uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1832805299/sys_console.o: ../src/config/default/system/console/src/sys_console.c  .generated_files/flags/default/886ae669aa6667c2ce3de9e2ac64f264cb84bdde .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1832805299" 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console.o.d 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1832805299/sys_console.o.d" -o ${OBJECTDIR}/_ext/1832805299/sys_console.o ../src/config/default/system/console/src/sys_console.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/14461671/sys_dma.o: ../src/config/default/system/dma/sys_dma.c  .generated_files/flags/default/a4bb20301d6133f8196ac8e5d0aa8e016cc40ca1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/14461671" 
	@${RM} ${OBJECTDIR}/_ext/14461671/sys_dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/14461671/sys_dma.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/14461671/sys_dma.o.d" -o ${OBJECTDIR}/_ext/14461671/sys_dma.o ../src/config/default/system/dma/sys_dma.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1881668453/sys_int.o: ../src/config/default/system/int/src/sys_int.c  .generated_files/flags/default/4a982db848e5d461707e268aecdc0a09f086bf36 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1881668453" 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1881668453/sys_int.o.d" -o ${OBJECTDIR}/_ext/1881668453/sys_int.o ../src/config/default/system/int/src/sys_int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o: ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c  .generated_files/flags/default/31c2cecac6a0bfe27638e5ba6f013b8ce0a0259a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/692303624" 
	@${RM} ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o.d" -o ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o: ../src/config/default/system/net/src/sys_wincs_net_service.c  .generated_files/flags/default/6cdab89a5c647a39f5b42a17a137e3bf0cd292df .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1766557203" 
	@${RM} ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o.d" -o ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o ../src/config/default/system/net/src/sys_wincs_net_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/101884895/sys_time.o: ../src/config/default/system/time/src/sys_time.c  .generated_files/flags/default/871d6c87ecd16a3c3c07e7bf298ba393915e0c14 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/101884895" 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/101884895/sys_time.o.d" -o ${OBJECTDIR}/_ext/101884895/sys_time.o ../src/config/default/system/time/src/sys_time.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o: ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c  .generated_files/flags/default/80ef1f88e89359e67bb882ce8b6111fc2b08ee4f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/634868841" 
	@${RM} ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o.d" -o ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o: ../src/config/default/system/sys_wincs_system_service.c  .generated_files/flags/default/39aed54a3d6fb933fc168ce7b3a3bbf6cc172a8b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/753841488" 
	@${RM} ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o.d" -o ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o ../src/config/default/system/sys_wincs_system_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/tasks.o: ../src/config/default/tasks.c  .generated_files/flags/default/2336cf1c6c0b56a1c99ea878027d3bc4c5bd3d5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/tasks.o.d" -o ${OBJECTDIR}/_ext/1171490990/tasks.o ../src/config/default/tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/3a3abcebfddb1691ea505144c6ad02367e5ea0e3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/dc438c70c1701d6fca646a24f9b676397af821dd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/ea4b4c291645d2f5f4d7089f3a3b3d3a726863db .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/7e9d5709c1cd9894e13c8b48c780391e53badd10 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/6882d2fed4c4ecc6b02723ceac12cbfff8e59034 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ad9954_driver.o: ../src/ad9954_driver.c  .generated_files/flags/default/61b785c3f92bfc97f4320b6f195506fd48be786b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ad9954_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o ../src/ad9954_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/bme690_driver.o: ../src/bme690_driver.c  .generated_files/flags/default/7f13caf89b8690f4716462f7119631155bd8c8cf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bme690_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bme690_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/bme690_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/bme690_driver.o ../src/bme690_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/bmp585_driver.o: ../src/bmp585_driver.c  .generated_files/flags/default/474af0e4cc0216a849b4f83b13fd0467c69a12ec .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/bmp585_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o ../src/bmp585_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/can0_driver.o: ../src/can0_driver.c  .generated_files/flags/default/61df3fe07b9080b578ff558144dc15763f575a2f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/can0_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/can0_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/can0_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/can0_driver.o ../src/can0_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/console_driver.o: ../src/console_driver.c  .generated_files/flags/default/aeec9f6a57bd3820691cf31a2ccc7544946b518d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/console_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/console_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/console_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/console_driver.o ../src/console_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o: ../src/fcm360w_driver.c  .generated_files/flags/default/4b7eeadd9cf3b42c0a391f2dfc12e032e0cfb7e5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o ../src/fcm360w_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o: ../src/hdc302x_driver.c  .generated_files/flags/default/873f577514805d2a9f4ea4ef19c050940bbd4141 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o ../src/hdc302x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o: ../src/mcp9808_driver.c  .generated_files/flags/default/52a49ce7b6dd5b26756569232912edd1af1fd351 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o ../src/mcp9808_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ntc_driver.o: ../src/ntc_driver.c  .generated_files/flags/default/c9934fe42c237e9add7d32f842400eebd2308cbc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ntc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ntc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ntc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ntc_driver.o ../src/ntc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/rstc_driver.o: ../src/rstc_driver.c  .generated_files/flags/default/df4ec95a5d338635e328dcb3a7bd87e5f8fdf6f3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rstc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rstc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/rstc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/rstc_driver.o ../src/rstc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/rtc_driver.o: ../src/rtc_driver.c  .generated_files/flags/default/447c301354f87add89959b44f0e97a9c6e43f976 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/rtc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/rtc_driver.o ../src/rtc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/sen63c_driver.o: ../src/sen63c_driver.c  .generated_files/flags/default/c34d2c64c529b4c4ba9f9ace45f3b53d11b23ba5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sen63c_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o ../src/sen63c_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/sht4x_driver.o: ../src/sht4x_driver.c  .generated_files/flags/default/bef5f5dc92fd388ee894fa71b696a6573c2db86 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sht4x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o ../src/sht4x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o: ../src/ssd1306_driver.c  .generated_files/flags/default/b110ea782b35f4959b45b9526500e6bd4dbf6e3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o ../src/ssd1306_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/stcc4_driver.o: ../src/stcc4_driver.c  .generated_files/flags/default/6d111b4929cb86665f54b5b96b7e4795c14076d5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/stcc4_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o ../src/stcc4_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/timer_driver.o: ../src/timer_driver.c  .generated_files/flags/default/330a83e8d28dab92c7862e485a5d646132f5f5dd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/timer_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/timer_driver.o ../src/timer_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o: ../src/vcnl4200_driver.c  .generated_files/flags/default/5931d49f808d995efb9f9ab384b4d3677bbcaec1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o ../src/vcnl4200_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ws281x_driver.o: ../src/ws281x_driver.c  .generated_files/flags/default/ce0e1aef1acccbf96d7da1bb9c2867bab4648930 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ws281x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o ../src/ws281x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/xm125_driver.o: ../src/xm125_driver.c  .generated_files/flags/default/5b7a959b763e80dcc47da3427e47eef0092124d2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/xm125_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/xm125_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/xm125_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/xm125_driver.o ../src/xm125_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/wincs02_driver.o: ../src/wincs02_driver.c  .generated_files/flags/default/d40d9106f28da9d07308376e63c12ba68ba5961 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/wincs02_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o ../src/wincs02_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/f4d9375d374d45ce4619638d49c8b9a45773db59 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/3b48368400082333b56f2de04b779206b6801774 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG   -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
else
${OBJECTDIR}/_ext/158385033/drv_i2c.o: ../src/config/default/driver/i2c/src/drv_i2c.c  .generated_files/flags/default/5dcfa482438d76472cc2932dd8875ec94c990774 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/158385033" 
	@${RM} ${OBJECTDIR}/_ext/158385033/drv_i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/158385033/drv_i2c.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/158385033/drv_i2c.o.d" -o ${OBJECTDIR}/_ext/158385033/drv_i2c.o ../src/config/default/driver/i2c/src/drv_i2c.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/2070931557/drv_spi.o: ../src/config/default/driver/spi/src/drv_spi.c  .generated_files/flags/default/7bec2911a958baf80be660ed9a34f2240bae81f2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/2070931557" 
	@${RM} ${OBJECTDIR}/_ext/2070931557/drv_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/2070931557/drv_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/2070931557/drv_spi.o.d" -o ${OBJECTDIR}/_ext/2070931557/drv_spi.o ../src/config/default/driver/spi/src/drv_spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/869808652/drv_usart.o: ../src/config/default/driver/usart/src/drv_usart.c  .generated_files/flags/default/c67f36d2caef01d5981fcf1ea79515f35ced74ed .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/869808652" 
	@${RM} ${OBJECTDIR}/_ext/869808652/drv_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/869808652/drv_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/869808652/drv_usart.o.d" -o ${OBJECTDIR}/_ext/869808652/drv_usart.o ../src/config/default/driver/usart/src/drv_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o: ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c  .generated_files/flags/default/99a3bb25864cebedfd18f7d60a17655ad9d4e1cf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/622324608" 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o.d" -o ${OBJECTDIR}/_ext/622324608/wdrv_winc_spi.o ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_spi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o: ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c  .generated_files/flags/default/fe529ac4a28fd2fb384459f7f3a7bc92d25e1c47 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/622324608" 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o.d 
	@${RM} ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o.d" -o ${OBJECTDIR}/_ext/622324608/wdrv_winc_eint.o ../src/config/default/driver/wifi/wincs02/dev/wdrv_winc_eint.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_cmds.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c  .generated_files/flags/default/c55ac25a50707a869dcb07b9f13f733ae65ff65c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmds.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmds.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_cmds.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_cmds.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmds.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c  .generated_files/flags/default/19409be503ed28ab6cb0d8cefea6bcede873aa8c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_cmd_req.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_cmd_req.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_dev.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c  .generated_files/flags/default/a63afbb50fcbfcf656d8bfa4c8586df770be6e31 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_dev.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_dev.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_dev.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_dev.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_dev.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c  .generated_files/flags/default/30d257d2c583619f89cdba3d6eebd400413ff150 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_sdio_drv.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_sdio_drv.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_socket.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c  .generated_files/flags/default/78b55b0170e98514ea140bd29cdadbc8ae05daaa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_socket.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_socket.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1857064221/winc_tables.o: ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c  .generated_files/flags/default/c28b930e83b11a1f475f20570fc5697bb67037a7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1857064221" 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_tables.o.d 
	@${RM} ${OBJECTDIR}/_ext/1857064221/winc_tables.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1857064221/winc_tables.o.d" -o ${OBJECTDIR}/_ext/1857064221/winc_tables.o ../src/config/default/driver/wifi/wincs02/nc_driver/winc_tables.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc.c  .generated_files/flags/default/9134483caa7bb05e144505265212c1f766ef2b25 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc.o ../src/config/default/driver/wifi/wincs02/wdrv_winc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c  .generated_files/flags/default/d6d804d7019992711cd613a944b70fd229b7a9c8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_assoc.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_assoc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c  .generated_files/flags/default/ce5b713813922bf4a44cffb37c3e18ed9f1d760a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_authctx.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_authctx.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c  .generated_files/flags/default/21f9710fe440b90d46a96704e000bb9e8fe97c9e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssctx.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssctx.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c  .generated_files/flags/default/257f6c5b7c989cd8612a441d70fea2dfa1b8c920 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_bssfind.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_bssfind.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c  .generated_files/flags/default/6166a9f575504a630ac872f93dbb45a146d292db .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dns.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_dns.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c  .generated_files/flags/default/f0035b75ee0a265423f342b5aceefa7763ef4a42 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_dhcps.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_dhcps.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c  .generated_files/flags/default/a58e0bce8816149397593d73fb3fd6fc5345dc7d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_extcrypto.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_extcrypto.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c  .generated_files/flags/default/a92d9aef00c29ae89c2523f801ebcabda36a3586 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_file.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_file.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c  .generated_files/flags/default/24e58732161db2e5fa52d122c92f87a79678ee1a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_mqtt.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_mqtt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c  .generated_files/flags/default/fd8db39c5fb7a685b3eefd2b3488cae1ad83d8bf .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_netif.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_netif.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c  .generated_files/flags/default/5510c73d659b68278207ceb3b45073c315992fb2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_ota.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_ota.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c  .generated_files/flags/default/9588df69782abe1b95b54ef1c14cc1898b72ffb6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_pps.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_pps.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c  .generated_files/flags/default/aff66e3fae460a1a0cfd7a251fa89c2f76f3ec1f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_nvm.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_nvm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c  .generated_files/flags/default/53fc4588126ef5a1af94fec5eadfe8499f258351 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_prov.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_prov.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c  .generated_files/flags/default/195033a96051c8aed902dfdf505576d9b00bb5dc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sntp.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_sntp.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c  .generated_files/flags/default/7c77870ab03fa0ee4805e23f76b950955c30849d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_socket.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_socket.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c  .generated_files/flags/default/7598e0944f173bb5b5ddcb3cbb76324c25efee7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_softap.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_softap.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c  .generated_files/flags/default/3f65541f140f7170316e05de5be667cc613ed721 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_sta.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_sta.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c  .generated_files/flags/default/72cc9f94f754866eeacd68cf2bc47b2b81d031bc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_systime.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_systime.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c  .generated_files/flags/default/3c3f7afd8f58b6a89a901d90d0bb0462e6356797 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_tls.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_tls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c  .generated_files/flags/default/8ff9cb746264f4da18dce9a91260dce324b7e53f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_utils.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_utils.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o: ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c  .generated_files/flags/default/45c545a5e3b640580d4b5ac659a24f664a660004 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1706628858" 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o.d 
	@${RM} ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o.d" -o ${OBJECTDIR}/_ext/1706628858/wdrv_winc_wifi.o ../src/config/default/driver/wifi/wincs02/wdrv_winc_wifi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60163342/plib_adc0.o: ../src/config/default/peripheral/adc/plib_adc0.c  .generated_files/flags/default/4e73e59be5cf664e8d6721542d642add84e5fca7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60163342" 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60163342/plib_adc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60163342/plib_adc0.o.d" -o ${OBJECTDIR}/_ext/60163342/plib_adc0.o ../src/config/default/peripheral/adc/plib_adc0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60165182/plib_can0.o: ../src/config/default/peripheral/can/plib_can0.c  .generated_files/flags/default/228a43068b01e25d88f4a9439f8e9dac9527ae0d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60165182" 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60165182/plib_can0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60165182/plib_can0.o.d" -o ${OBJECTDIR}/_ext/60165182/plib_can0.o ../src/config/default/peripheral/can/plib_can0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1984496892/plib_clock.o: ../src/config/default/peripheral/clock/plib_clock.c  .generated_files/flags/default/44aafa0da33852bd4a56761f8dfa7bf66ed6e0e4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1984496892" 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/1984496892/plib_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1984496892/plib_clock.o.d" -o ${OBJECTDIR}/_ext/1984496892/plib_clock.o ../src/config/default/peripheral/clock/plib_clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60166132/plib_dac.o: ../src/config/default/peripheral/dac/plib_dac.c  .generated_files/flags/default/d25a1f97ad449a47bda92f26c1aced2e86e3bf01 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60166132" 
	@${RM} ${OBJECTDIR}/_ext/60166132/plib_dac.o.d 
	@${RM} ${OBJECTDIR}/_ext/60166132/plib_dac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60166132/plib_dac.o.d" -o ${OBJECTDIR}/_ext/60166132/plib_dac.o ../src/config/default/peripheral/dac/plib_dac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1985337713/plib_divas.o: ../src/config/default/peripheral/divas/plib_divas.c  .generated_files/flags/default/d59bfcc15e108a29c52397ad67808917dbbc7c38 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1985337713" 
	@${RM} ${OBJECTDIR}/_ext/1985337713/plib_divas.o.d 
	@${RM} ${OBJECTDIR}/_ext/1985337713/plib_divas.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1985337713/plib_divas.o.d" -o ${OBJECTDIR}/_ext/1985337713/plib_divas.o ../src/config/default/peripheral/divas/plib_divas.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865161661/plib_dmac.o: ../src/config/default/peripheral/dmac/plib_dmac.c  .generated_files/flags/default/7689e157d4ea7e92cffd25587750ba53d1e4636a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865161661" 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865161661/plib_dmac.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865161661/plib_dmac.o.d" -o ${OBJECTDIR}/_ext/1865161661/plib_dmac.o ../src/config/default/peripheral/dmac/plib_dmac.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60167341/plib_eic.o: ../src/config/default/peripheral/eic/plib_eic.c  .generated_files/flags/default/f14575e849f185639900da1c6cc04092cd00c8f6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60167341" 
	@${RM} ${OBJECTDIR}/_ext/60167341/plib_eic.o.d 
	@${RM} ${OBJECTDIR}/_ext/60167341/plib_eic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60167341/plib_eic.o.d" -o ${OBJECTDIR}/_ext/60167341/plib_eic.o ../src/config/default/peripheral/eic/plib_eic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1986646378/plib_evsys.o: ../src/config/default/peripheral/evsys/plib_evsys.c  .generated_files/flags/default/3199d30d9231e1a22a9c448480b1f876bc93a9c0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1986646378" 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d 
	@${RM} ${OBJECTDIR}/_ext/1986646378/plib_evsys.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1986646378/plib_evsys.o.d" -o ${OBJECTDIR}/_ext/1986646378/plib_evsys.o ../src/config/default/peripheral/evsys/plib_evsys.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1987437027/plib_freqm.o: ../src/config/default/peripheral/freqm/plib_freqm.c  .generated_files/flags/default/7b29197355c7b31070862305eb2d937c63568de9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1987437027" 
	@${RM} ${OBJECTDIR}/_ext/1987437027/plib_freqm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1987437027/plib_freqm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1987437027/plib_freqm.o.d" -o ${OBJECTDIR}/_ext/1987437027/plib_freqm.o ../src/config/default/peripheral/freqm/plib_freqm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865468468/plib_nvic.o: ../src/config/default/peripheral/nvic/plib_nvic.c  .generated_files/flags/default/bce7aba1be9ce499ff8f47437e0a7143fd7b8854 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865468468" 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865468468/plib_nvic.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865468468/plib_nvic.o.d" -o ${OBJECTDIR}/_ext/1865468468/plib_nvic.o ../src/config/default/peripheral/nvic/plib_nvic.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o: ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c  .generated_files/flags/default/738a742407c208051dba53df391a5d9b5598418e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1593096446" 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d 
	@${RM} ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o.d" -o ${OBJECTDIR}/_ext/1593096446/plib_nvmctrl.o ../src/config/default/peripheral/nvmctrl/plib_nvmctrl.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/829342769/plib_pm.o: ../src/config/default/peripheral/pm/plib_pm.c  .generated_files/flags/default/ac35ea274d2ac7b39e9891c526b982eab85e158e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/829342769" 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o.d 
	@${RM} ${OBJECTDIR}/_ext/829342769/plib_pm.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/829342769/plib_pm.o.d" -o ${OBJECTDIR}/_ext/829342769/plib_pm.o ../src/config/default/peripheral/pm/plib_pm.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865521619/plib_port.o: ../src/config/default/peripheral/port/plib_port.c  .generated_files/flags/default/47a6b143b16b6e80060010879573889ddf568610 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865521619" 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865521619/plib_port.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865521619/plib_port.o.d" -o ${OBJECTDIR}/_ext/1865521619/plib_port.o ../src/config/default/peripheral/port/plib_port.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865585090/plib_rstc.o: ../src/config/default/peripheral/rstc/plib_rstc.c  .generated_files/flags/default/b521e825a0f0e6e2523648ab75cf5b5373227a84 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865585090" 
	@${RM} ${OBJECTDIR}/_ext/1865585090/plib_rstc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865585090/plib_rstc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865585090/plib_rstc.o.d" -o ${OBJECTDIR}/_ext/1865585090/plib_rstc.o ../src/config/default/peripheral/rstc/plib_rstc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o: ../src/config/default/peripheral/rtc/plib_rtc_clock.c  .generated_files/flags/default/d9b381f92d9dfca17fbbd9de58951c67ccc881b9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60180175" 
	@${RM} ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o.d 
	@${RM} ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o.d" -o ${OBJECTDIR}/_ext/60180175/plib_rtc_clock.o ../src/config/default/peripheral/rtc/plib_rtc_clock.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o: ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c  .generated_files/flags/default/5244b90df7c296ca47be98a05a09a4b66cbfd4f9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/508257091" 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o.d" -o ${OBJECTDIR}/_ext/508257091/plib_sercom2_i2c_master.o ../src/config/default/peripheral/sercom/i2c_master/plib_sercom2_i2c_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c  .generated_files/flags/default/5b9e9133fb437c21ea8f82f6f610690f4287034 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom3_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom3_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c  .generated_files/flags/default/8c6ffa6cf44f8070653524863f871eb14396417a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom4_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom4_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o: ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c  .generated_files/flags/default/b9fe43df8177c7bc2444f540f950725832e15257 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/17022449" 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o.d 
	@${RM} ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o.d" -o ${OBJECTDIR}/_ext/17022449/plib_sercom5_spi_master.o ../src/config/default/peripheral/sercom/spi_master/plib_sercom5_spi_master.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c  .generated_files/flags/default/fef4eaa9459364c4c7b719ca113ff1111f965afb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom1_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom1_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o: ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c  .generated_files/flags/default/b5e40d3fce73eea5dd1173955f91529b88231280 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/504274921" 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o.d 
	@${RM} ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o.d" -o ${OBJECTDIR}/_ext/504274921/plib_sercom0_usart.o ../src/config/default/peripheral/sercom/usart/plib_sercom0_usart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1865616679/plib_supc.o: ../src/config/default/peripheral/supc/plib_supc.c  .generated_files/flags/default/a0cff1908de1fc0ff1cfda0ac84bba5e8d62b813 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1865616679" 
	@${RM} ${OBJECTDIR}/_ext/1865616679/plib_supc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1865616679/plib_supc.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1865616679/plib_supc.o.d" -o ${OBJECTDIR}/_ext/1865616679/plib_supc.o ../src/config/default/peripheral/supc/plib_supc.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1827571544/plib_systick.o: ../src/config/default/peripheral/systick/plib_systick.c  .generated_files/flags/default/f01ca73c520f141247b2792781970fe2495622fa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1827571544" 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o.d 
	@${RM} ${OBJECTDIR}/_ext/1827571544/plib_systick.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1827571544/plib_systick.o.d" -o ${OBJECTDIR}/_ext/1827571544/plib_systick.o ../src/config/default/peripheral/systick/plib_systick.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60181570/plib_tcc0.o: ../src/config/default/peripheral/tcc/plib_tcc0.c  .generated_files/flags/default/dab5f1c4c8ee5c739973bf80fd02e8a109495014 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60181570" 
	@${RM} ${OBJECTDIR}/_ext/60181570/plib_tcc0.o.d 
	@${RM} ${OBJECTDIR}/_ext/60181570/plib_tcc0.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60181570/plib_tcc0.o.d" -o ${OBJECTDIR}/_ext/60181570/plib_tcc0.o ../src/config/default/peripheral/tcc/plib_tcc0.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/60184501/plib_wdt.o: ../src/config/default/peripheral/wdt/plib_wdt.c  .generated_files/flags/default/77292188e5ead107b3f86a4764bdbed197368bc7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/60184501" 
	@${RM} ${OBJECTDIR}/_ext/60184501/plib_wdt.o.d 
	@${RM} ${OBJECTDIR}/_ext/60184501/plib_wdt.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/60184501/plib_wdt.o.d" -o ${OBJECTDIR}/_ext/60184501/plib_wdt.o ../src/config/default/peripheral/wdt/plib_wdt.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/163028504/xc32_monitor.o: ../src/config/default/stdio/xc32_monitor.c  .generated_files/flags/default/a4ecb268360338e3092bd2e6f2c8f1b39faa094f .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/163028504" 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d 
	@${RM} ${OBJECTDIR}/_ext/163028504/xc32_monitor.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/163028504/xc32_monitor.o.d" -o ${OBJECTDIR}/_ext/163028504/xc32_monitor.o ../src/config/default/stdio/xc32_monitor.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1832805299/sys_console_uart.o: ../src/config/default/system/console/src/sys_console_uart.c  .generated_files/flags/default/78a91356ece0dd7b25734cbc4e481f36eb1f9776 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1832805299" 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1832805299/sys_console_uart.o.d" -o ${OBJECTDIR}/_ext/1832805299/sys_console_uart.o ../src/config/default/system/console/src/sys_console_uart.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1832805299/sys_console.o: ../src/config/default/system/console/src/sys_console.c  .generated_files/flags/default/19956247c746099fc2633a7e613dc5e9bc7a891b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1832805299" 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console.o.d 
	@${RM} ${OBJECTDIR}/_ext/1832805299/sys_console.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1832805299/sys_console.o.d" -o ${OBJECTDIR}/_ext/1832805299/sys_console.o ../src/config/default/system/console/src/sys_console.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/14461671/sys_dma.o: ../src/config/default/system/dma/sys_dma.c  .generated_files/flags/default/c1bec48aaf277c37ff957777df232e37ceeff2d0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/14461671" 
	@${RM} ${OBJECTDIR}/_ext/14461671/sys_dma.o.d 
	@${RM} ${OBJECTDIR}/_ext/14461671/sys_dma.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/14461671/sys_dma.o.d" -o ${OBJECTDIR}/_ext/14461671/sys_dma.o ../src/config/default/system/dma/sys_dma.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1881668453/sys_int.o: ../src/config/default/system/int/src/sys_int.c  .generated_files/flags/default/ff9ab24cdc7b241c8d789594c44fa5b631798ecc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1881668453" 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o.d 
	@${RM} ${OBJECTDIR}/_ext/1881668453/sys_int.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1881668453/sys_int.o.d" -o ${OBJECTDIR}/_ext/1881668453/sys_int.o ../src/config/default/system/int/src/sys_int.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o: ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c  .generated_files/flags/default/bda2fc8cc63647c760eacd969559ee9a9f1c4276 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/692303624" 
	@${RM} ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o.d" -o ${OBJECTDIR}/_ext/692303624/sys_wincs_mqtt_service.o ../src/config/default/system/mqtt/src/sys_wincs_mqtt_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o: ../src/config/default/system/net/src/sys_wincs_net_service.c  .generated_files/flags/default/559de82e46fa21b10ff4508c2fb5d57bebd1905d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1766557203" 
	@${RM} ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o.d" -o ${OBJECTDIR}/_ext/1766557203/sys_wincs_net_service.o ../src/config/default/system/net/src/sys_wincs_net_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/101884895/sys_time.o: ../src/config/default/system/time/src/sys_time.c  .generated_files/flags/default/80b307a022e30edb65195eefb460a463702612e8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/101884895" 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o.d 
	@${RM} ${OBJECTDIR}/_ext/101884895/sys_time.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/101884895/sys_time.o.d" -o ${OBJECTDIR}/_ext/101884895/sys_time.o ../src/config/default/system/time/src/sys_time.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o: ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c  .generated_files/flags/default/946687cb1b4ac0cb2af72887e3d0ad90be948f96 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/634868841" 
	@${RM} ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o.d" -o ${OBJECTDIR}/_ext/634868841/sys_wincs_wifi_service.o ../src/config/default/system/wifi/src/sys_wincs_wifi_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o: ../src/config/default/system/sys_wincs_system_service.c  .generated_files/flags/default/69401c28cccfdff9e93f9f011a9fc782d50da233 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/753841488" 
	@${RM} ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o.d 
	@${RM} ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o.d" -o ${OBJECTDIR}/_ext/753841488/sys_wincs_system_service.o ../src/config/default/system/sys_wincs_system_service.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/tasks.o: ../src/config/default/tasks.c  .generated_files/flags/default/a3f8e02369d983ea195c0ecd70caf5a074d83bd5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/tasks.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/tasks.o.d" -o ${OBJECTDIR}/_ext/1171490990/tasks.o ../src/config/default/tasks.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/initialization.o: ../src/config/default/initialization.c  .generated_files/flags/default/deaff7e51718e6f28ea042c639dac46cae2a93ad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/initialization.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/initialization.o.d" -o ${OBJECTDIR}/_ext/1171490990/initialization.o ../src/config/default/initialization.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/interrupts.o: ../src/config/default/interrupts.c  .generated_files/flags/default/bda9912393ecab2eeb783b80ddf324c5c61270c1 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/interrupts.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/interrupts.o.d" -o ${OBJECTDIR}/_ext/1171490990/interrupts.o ../src/config/default/interrupts.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/exceptions.o: ../src/config/default/exceptions.c  .generated_files/flags/default/d92ca392005f5427646920c06e5e2fa0da8377f0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/exceptions.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/exceptions.o.d" -o ${OBJECTDIR}/_ext/1171490990/exceptions.o ../src/config/default/exceptions.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/startup_xc32.o: ../src/config/default/startup_xc32.c  .generated_files/flags/default/71fdd5987cc01e73e6f73ab67a02c006f6445e6b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/startup_xc32.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/startup_xc32.o.d" -o ${OBJECTDIR}/_ext/1171490990/startup_xc32.o ../src/config/default/startup_xc32.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1171490990/libc_syscalls.o: ../src/config/default/libc_syscalls.c  .generated_files/flags/default/ef15852a04bdd66b813bf4d870a73f01931498dd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1171490990" 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d 
	@${RM} ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1171490990/libc_syscalls.o.d" -o ${OBJECTDIR}/_ext/1171490990/libc_syscalls.o ../src/config/default/libc_syscalls.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ad9954_driver.o: ../src/ad9954_driver.c  .generated_files/flags/default/516a37ff3cd507e3eaabbf6ed60006eff3dfdb01 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ad9954_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ad9954_driver.o ../src/ad9954_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/bme690_driver.o: ../src/bme690_driver.c  .generated_files/flags/default/82b7abdb056464bd86ca568cb4b3dad1b4d2e2b4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bme690_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bme690_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/bme690_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/bme690_driver.o ../src/bme690_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/bmp585_driver.o: ../src/bmp585_driver.c  .generated_files/flags/default/a5b769c25530d24ea11f779f023557073c5ed339 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/bmp585_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/bmp585_driver.o ../src/bmp585_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/can0_driver.o: ../src/can0_driver.c  .generated_files/flags/default/bcb427c6ca42d2ac6294b240d6c6c3118714f0 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/can0_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/can0_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/can0_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/can0_driver.o ../src/can0_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/console_driver.o: ../src/console_driver.c  .generated_files/flags/default/945aadb929dcc362a825bdc16ac5e13ebfc781f3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/console_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/console_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/console_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/console_driver.o ../src/console_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o: ../src/fcm360w_driver.c  .generated_files/flags/default/c58879c61a5569ff7309771d6fb8f7802390cb21 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/fcm360w_driver.o ../src/fcm360w_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o: ../src/hdc302x_driver.c  .generated_files/flags/default/7ef1135ac37bfe8ce721eaae46500de36c2b66d4 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/hdc302x_driver.o ../src/hdc302x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o: ../src/mcp9808_driver.c  .generated_files/flags/default/fc5ffd626f95a2a462bc14325594db4610f3b511 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/mcp9808_driver.o ../src/mcp9808_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ntc_driver.o: ../src/ntc_driver.c  .generated_files/flags/default/c75482e424fbe6fab9f7358309f0afd00f833b11 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ntc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ntc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ntc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ntc_driver.o ../src/ntc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/rstc_driver.o: ../src/rstc_driver.c  .generated_files/flags/default/6c3c699e992a23380a2504431655557b819fb673 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rstc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rstc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/rstc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/rstc_driver.o ../src/rstc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/rtc_driver.o: ../src/rtc_driver.c  .generated_files/flags/default/7a6f067409302ac018bb8f19dc74427f4ecdbda8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/rtc_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/rtc_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/rtc_driver.o ../src/rtc_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/sen63c_driver.o: ../src/sen63c_driver.c  .generated_files/flags/default/9f632e3029b11c7819cd545fec0807c81dd062bd .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sen63c_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/sen63c_driver.o ../src/sen63c_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/sht4x_driver.o: ../src/sht4x_driver.c  .generated_files/flags/default/d9c624dc808ca4db43c8d93523dbc74677c289b7 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/sht4x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/sht4x_driver.o ../src/sht4x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o: ../src/ssd1306_driver.c  .generated_files/flags/default/2d5a3b6cc49943908a09ac189d368e468588d0f5 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ssd1306_driver.o ../src/ssd1306_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/stcc4_driver.o: ../src/stcc4_driver.c  .generated_files/flags/default/20a2cbd3538a33ada9eb55ea972512be780e2fff .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/stcc4_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/stcc4_driver.o ../src/stcc4_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/timer_driver.o: ../src/timer_driver.c  .generated_files/flags/default/6da767d3270ddf281945d947632315137ef729a6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timer_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/timer_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/timer_driver.o ../src/timer_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o: ../src/vcnl4200_driver.c  .generated_files/flags/default/321e0251182b1c6907afa4cb8d89ad0e25db6b59 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/vcnl4200_driver.o ../src/vcnl4200_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/ws281x_driver.o: ../src/ws281x_driver.c  .generated_files/flags/default/17b19804a1377b0152607382f8a75a41c7e958f6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ws281x_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/ws281x_driver.o ../src/ws281x_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/xm125_driver.o: ../src/xm125_driver.c  .generated_files/flags/default/a5f7936de865cfb119cd6ad9a3e086031b82daf8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/xm125_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/xm125_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/xm125_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/xm125_driver.o ../src/xm125_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/wincs02_driver.o: ../src/wincs02_driver.c  .generated_files/flags/default/d6969561c974ff850dffe284a91b038ad4294f6 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/wincs02_driver.o.d" -o ${OBJECTDIR}/_ext/1360937237/wincs02_driver.o ../src/wincs02_driver.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  .generated_files/flags/default/6106290fa9fe205b45b8ed8e51d38a1d108fec8e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/81a2163bfc916984e132287a1fead84153e76940 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -fdata-sections -O1 -fno-common -I"../src" -I"../src/config/default" -I"../src/config/default/driver/wifi/wincs02/include/" -I"../src/config/default/driver/wifi/wincs02/include/dev" -I"../src/config/default/driver/wifi/wincs02/include/nc_driver" -I"../src/packs/CMSIS/" -I"../src/packs/CMSIS/CMSIS/Core/Include" -I"../src/packs/PIC32CM5164JH01100_DFP" -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -mdfp="${DFP_DIR}/PIC32CM-JH01" ${PACK_COMMON_OPTIONS} 
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE) -g   -mprocessor=$(MP_PROCESSOR_OPTION)  -mno-device-startup-code -o ${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=_min_heap_size=1024,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}/PIC32CM-JH01"
	
else
${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   ../src/config/default/PIC32CM5164JH01100.ld
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -mno-device-startup-code -o ${DISTDIR}/PIC32CMJH01.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--gc-sections,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml -mdfp="${DFP_DIR}/PIC32CM-JH01"
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
