

#ifndef _DSM_PUB_H
#define _DSM_PUB_H
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/workqueue.h>
#include <linux/wait.h>

#define CLIENT_NAME_LEN						(32) /* max client name length */
#define DSM_MAX_DEVICE_NAME_LEN				(32) /* max device name length */
#define DSM_MAX_MODULE_NAME_LEN				(16)  /* max module name length */
#define DSM_MAX_IC_NAME_LEN					(16)  /* max ic name length */

/*dsm error no define*/
#define DSM_ERR_NO_ERROR					(0)
#define DSM_ERR_I2C_TIMEOUT					(1)

/* pmu irq */
#define DSM_PMU_IRQ_ERROR_NO				(920005000)
#define DSM_PMU_VSYS_OV_D200UR_ERROR_NO          (DSM_PMU_IRQ_ERROR_NO + 2)
#define DSM_PMU_VSYS_UV_D10MR_ERROR_NO           (DSM_PMU_IRQ_ERROR_NO + 3)
#define DSM_PMU_VSYS_PWROFF_ABS_2D_ERROR_NO      (DSM_PMU_IRQ_ERROR_NO + 4)
#define DSM_PMU_VSYS_PWROFF_DEB_D80MR_ERROR_NO   (DSM_PMU_IRQ_ERROR_NO + 5)
#define DSM_PMU_VSYS_THSD_OTMP140_D1MR_ERROR_NO  (DSM_PMU_IRQ_ERROR_NO + 6)
#define DSM_PMU_VSYS_THSD_OTMP125_D1MR_ERROR_NO  (DSM_PMU_IRQ_ERROR_NO + 7)

/* pmu ocp */
#define DSM_PMU_OCP_ERROR_NO_BASE			(920007000)
#define DSM_PMU_OCPLDO2_ERROR_NO            (DSM_PMU_OCP_ERROR_NO_BASE + 0)
#define DSM_PMU_OCPLDO1_ERROR_NO            (DSM_PMU_OCP_ERROR_NO_BASE + 1)
#define DSM_PMU_OCPLDO0_ERROR_NO            (DSM_PMU_OCP_ERROR_NO_BASE + 2)
#define DSM_PMU_OCPBUCK4_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 3)
#define DSM_PMU_OCPBUCK3_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 4)
#define DSM_PMU_OCPBUCK2_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 5)
#define DSM_PMU_OCPBUCK1_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 6)
#define DSM_PMU_OCPBUCK0_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 7)
#define DSM_PMU_OCPLDO11_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 8)
#define DSM_PMU_OCPLDO10_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 9)
#define DSM_PMU_OCPLDO9_ERROR_NO            (DSM_PMU_OCP_ERROR_NO_BASE + 10)
#define DSM_PMU_OCPLDO8_ERROR_NO            (DSM_PMU_OCP_ERROR_NO_BASE + 11)
#define DSM_PMU_OCPLDO7_ERROR_NO            (DSM_PMU_OCP_ERROR_NO_BASE + 12)
#define DSM_PMU_OCPLDO5_ERROR_NO            (DSM_PMU_OCP_ERROR_NO_BASE + 13)
#define DSM_PMU_OCPLDO4_ERROR_NO            (DSM_PMU_OCP_ERROR_NO_BASE + 14)
#define DSM_PMU_OCPLDO3_ERROR_NO            (DSM_PMU_OCP_ERROR_NO_BASE + 15)
#define DSM_PMU_OCPLDO20_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 16)
#define DSM_PMU_OCPLDO19_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 17)
#define DSM_PMU_OCPLDO17_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 18)
#define DSM_PMU_OCPLDO16_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 19)
#define DSM_PMU_OCPLDO15_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 20)
#define DSM_PMU_OCPLDO14_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 21)
#define DSM_PMU_OCPLDO13_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 22)
#define DSM_PMU_OCPLDO12_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 23)
#define DSM_PMU_OCPLDO28_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 24)
#define DSM_PMU_OCPLDO27_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 25)
#define DSM_PMU_OCPLDO26_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 26)
#define DSM_PMU_OCPLDO25_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 27)
#define DSM_PMU_OCPLDO24_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 28)
#define DSM_PMU_OCPLDO23_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 29)
#define DSM_PMU_OCPLDO22_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 30)
#define DSM_PMU_OCPLDO21_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 31)
#define DSM_PMU_CLASSD_OCP_ERROR_NO         (DSM_PMU_OCP_ERROR_NO_BASE + 32)
#define DSM_PMU_OCPLDO32_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 36)
#define DSM_PMU_OCPLDO31_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 37)
#define DSM_PMU_OCPLDO30_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 38)
#define DSM_PMU_OCPLDO29_ERROR_NO           (DSM_PMU_OCP_ERROR_NO_BASE + 39)
#define DSM_PMU_BUCK4_SCP_ERROR_NO          (DSM_PMU_OCP_ERROR_NO_BASE + 40)
#define DSM_PMU_BUCK3_SCP_ERROR_NO          (DSM_PMU_OCP_ERROR_NO_BASE + 41)
#define DSM_PMU_BUCK2_SCP_ERROR_NO          (DSM_PMU_OCP_ERROR_NO_BASE + 42)
#define DSM_PMU_BUCK1_SCP_ERROR_NO          (DSM_PMU_OCP_ERROR_NO_BASE + 43)
#define DSM_PMU_BUCK0_SCP_ERROR_NO          (DSM_PMU_OCP_ERROR_NO_BASE + 44)

#define DSM_CHARGER_ERROR_NO  				(920011000)

/* pmu coul */
#define DSM_PMU_COUL_ERROR_NO				(920006000)

/* battery detect */
#define DSM_BATTERY_DETECT_ERROR_NO			(920002000)

/* battery */
#define DSM_BATTERY_ERROR_NO_BASE                       (920001000)
#define ERROR_BATT_NOT_EXIST               (DSM_BATTERY_ERROR_NO_BASE + 3)
#define ERROR_BATT_TEMP_LOW                (DSM_BATTERY_ERROR_NO_BASE + 4)
#define ERROR_BATT_VOLT_HIGH               (DSM_BATTERY_ERROR_NO_BASE + 5)
#define ERROR_BATT_VOLT_LOW                (DSM_BATTERY_ERROR_NO_BASE + 6)
#define ERROR_BATT_TERMINATE_TOO_EARLY     (DSM_BATTERY_ERROR_NO_BASE + 7)
#define ERROR_BATT_NOT_TERMINATE           (DSM_BATTERY_ERROR_NO_BASE + 8)
#define ERROR_BATT_BAD_CURR_SENSOR         (DSM_BATTERY_ERROR_NO_BASE + 9)
#define ERROR_VBUS_VOLT_HIGH               (DSM_BATTERY_ERROR_NO_BASE + 10)
#define ERROR_WATCHDOG_RESET               (DSM_BATTERY_ERROR_NO_BASE + 11)
#define ERROR_CHARGE_CURR_OVERHIGH         (DSM_BATTERY_ERROR_NO_BASE + 12)
#define ERROR_DISCHARGE_CURR_OVERHIGH      (DSM_BATTERY_ERROR_NO_BASE + 13)
#define ERROR_CHARGE_CURR_ZERO             (DSM_BATTERY_ERROR_NO_BASE + 14)
#define ERROR_CHARGE_TEMP_FAULT            (DSM_BATTERY_ERROR_NO_BASE + 15)
#define ERROR_CHARGE_BATT_TEMP_SHUTDOWN    (DSM_BATTERY_ERROR_NO_BASE + 16)
#define ERROR_CHARGE_BATT_CAPACITY         (DSM_BATTERY_ERROR_NO_BASE + 17)
#define ERROR_CHARGE_CHARGER_TS            (DSM_BATTERY_ERROR_NO_BASE + 18)
#define ERROR_CHARGE_OTG                   (DSM_BATTERY_ERROR_NO_BASE + 19)
#define ERROR_FCP_VOL_OVER_HIGH            (DSM_BATTERY_ERROR_NO_BASE + 21)
#define ERROR_FCP_DETECT                   (DSM_BATTERY_ERROR_NO_BASE + 22)
#define ERROR_FCP_OUTPUT                   (DSM_BATTERY_ERROR_NO_BASE + 23)
#define ERROR_SWITCH_ATTACH                (DSM_BATTERY_ERROR_NO_BASE + 24)
#define ERROR_ADAPTER_OVLT                 (DSM_BATTERY_ERROR_NO_BASE + 25)
#define ERROR_ADAPTER_OCCURRENT            (DSM_BATTERY_ERROR_NO_BASE + 26)
#define ERROR_ADAPTER_OTEMP                (DSM_BATTERY_ERROR_NO_BASE + 27)
#define ERROR_SAFE_PLOICY_LEARN            (DSM_BATTERY_ERROR_NO_BASE + 28)
#define ERROR_SAFE_PLOICY_LEARN1           (DSM_BATTERY_ERROR_NO_BASE + 29)
#define ERROR_SAFE_PLOICY_LEARN2           (DSM_BATTERY_ERROR_NO_BASE + 31)
#define ERROR_SAFE_PLOICY_LEARN3           (DSM_BATTERY_ERROR_NO_BASE + 32)
#define ERROR_BOOST_OCP                    (DSM_BATTERY_ERROR_NO_BASE + 33)
#define ERROR_CHARGE_I2C_RW                (DSM_BATTERY_ERROR_NO_BASE + 34)
#define ERROR_BATT_SOC_CHANGE_FAST         (DSM_BATTERY_ERROR_NO_BASE + 35)
#define ERROR_CHARGE_VBAT_OVP               (DSM_BATTERY_ERROR_NO_BASE + 36)
#define ERROR_SCHARGERV200_FAULT           (DSM_BATTERY_ERROR_NO_BASE + 37)
/* log_mask   71 */
#define  SHB_ERR_FCP_VOL_OVER_HIGH         (DSM_BATTERY_ERROR_NO_BASE + 38)
#define  SHB_ERR_FCP_DETECT                (DSM_BATTERY_ERROR_NO_BASE + 39)
#define  SHB_ERR_FCP_OUTPUT                (DSM_BATTERY_ERROR_NO_BASE + 40)
#define  SHB_ERR_SWITCH_ATTACH             (DSM_BATTERY_ERROR_NO_BASE + 41)
#define  SHB_ERR_ADAPTER_OVLT              (DSM_BATTERY_ERROR_NO_BASE + 42)
#define  SHB_ERR_ADAPTER_OCCURRENT         (DSM_BATTERY_ERROR_NO_BASE + 43)
#define  SHB_ERR_ADAPTER_OTEMP             (DSM_BATTERY_ERROR_NO_BASE + 44)
#define  SHB_ERR_BOOST_OCP                 (DSM_BATTERY_ERROR_NO_BASE + 45)
/* water check */
#define ERROR_NO_WATER_CHECK_IN_EAR        (DSM_BATTERY_ERROR_NO_BASE + 46)
#define ERROR_NO_WATER_CHECK_IN_USB        (DSM_BATTERY_ERROR_NO_BASE + 47)
/*internal short current detect*/
#define DSM_BATTERY_ISCD_LEVEL0        (DSM_BATTERY_ERROR_NO_BASE + 48)
#define DSM_BATTERY_ISCD_LEVEL1        (DSM_BATTERY_ERROR_NO_BASE + 49)
#define DSM_BATTERY_ISCD_LEVEL2        (DSM_BATTERY_ERROR_NO_BASE + 50)
#define DSM_BATTERY_ISCD_LEVEL3        (DSM_BATTERY_ERROR_NO_BASE + 51)
#define DSM_BATTERY_ISCD_LEVEL4        (DSM_BATTERY_ERROR_NO_BASE + 52)
#define DSM_BATTERY_ISCD_LEVEL5        (DSM_BATTERY_ERROR_NO_BASE + 53)
#define DSM_BATTERY_ISCD_LEVEL6        (DSM_BATTERY_ERROR_NO_BASE + 54)
#define DSM_BATTERY_ISCD_LEVEL7       (DSM_BATTERY_ERROR_NO_BASE + 55)
#define DSM_BATTERY_ISCD_LEVEL8       (DSM_BATTERY_ERROR_NO_BASE + 56)
/* log_mask   71 */
#define SHB_ERR_VBUS_HIGH              (DSM_BATTERY_ERROR_NO_BASE + 57)
#define SHB_ERR_VBAT_OVP               (DSM_BATTERY_ERROR_NO_BASE + 58)

#define DSM_DIRECT_CHARGE_VOL_ACCURACY                (DSM_BATTERY_ERROR_NO_BASE + 60)
#define DSM_DIRECT_CHARGE_FULL_PATH_RESISTANCE        (DSM_BATTERY_ERROR_NO_BASE + 61)
#define DSM_DIRECT_CHARGE_LOADSWITCH_RESISTANCE       (DSM_BATTERY_ERROR_NO_BASE + 62)
#define DSM_DIRECT_CHARGE_USB_PORT_LEAKAGE_CURRENT    (DSM_BATTERY_ERROR_NO_BASE + 63)
#define DSM_DIRECT_CHARGE_VBUS_OVP                    (DSM_BATTERY_ERROR_NO_BASE + 64)
#define DSM_DIRECT_CHARGE_REVERSE_OCP                 (DSM_BATTERY_ERROR_NO_BASE + 65)
#define DSM_DIRECT_CHARGE_OTP                         (DSM_BATTERY_ERROR_NO_BASE + 66)
#define DSM_DIRECT_CHARGE_INPUT_OCP                   (DSM_BATTERY_ERROR_NO_BASE + 67)
#define DSM_DIRECT_CHARGE_ADAPTER_OTP                 (DSM_BATTERY_ERROR_NO_BASE + 68)

#define ERROR_CHARGE_TEMP_WARM                        (DSM_BATTERY_ERROR_NO_BASE + 70)

/* SMPL*/
#define ERROR_NO_SMPL                       (920003000)

/* uscp */
#define ERROR_NO_USB_SHORT_PROTECT          (920004000)
#define ERROR_NO_USB_SHORT_PROTECT_NTC      (920004001)
#define SHB_ERR_USB_SHORT_PROTECT           (920004002) /* log_mask   71 */
#define SHB_ERR_USB_SHORT_PROTECT_NTC       (920004003) /* log_mask   71 */

/* pd_richtek */
#define PD_RICHTEK_ERROR_NO_BASE            (926010000)
#define ERROR_RT_DPSTS_BOTH_CONNECTED         (PD_RICHTEK_ERROR_NO_BASE + 0)
#define ERROR_RT_UFP_INVALID                  (PD_RICHTEK_ERROR_NO_BASE + 1)
#define ERROR_RT_DFP_INVALID                  (PD_RICHTEK_ERROR_NO_BASE + 2)
#define ERROR_RT_OVER_VDO_MAX_SIZE            (PD_RICHTEK_ERROR_NO_BASE + 3)
#define ERROR_RT_PD_MSG_NULL                  (PD_RICHTEK_ERROR_NO_BASE + 4)
#define ERROR_RT_DATA_OBJ_NULL                (PD_RICHTEK_ERROR_NO_BASE + 5)
#define ERROR_RT_OVER_VDO_MAX_SVID_SIZE       (PD_RICHTEK_ERROR_NO_BASE + 6)
#define ERROR_RT_PD_NR_PE_STATES              (PD_RICHTEK_ERROR_NO_BASE + 7)
#define ERROR_RT_PD_TIMER_NR                  (PD_RICHTEK_ERROR_NO_BASE + 8)
#define ERROR_RT_PD_ALLOC_MSG                 (PD_RICHTEK_ERROR_NO_BASE + 9)
#define ERROR_RT_PD_FREE_MSG                  (PD_RICHTEK_ERROR_NO_BASE + 10)
#define ERROR_RT_TCPC_DEV_NULL                (PD_RICHTEK_ERROR_NO_BASE + 11)
#define ERROR_RT_DATA_ROLE_ISNOT_PD_ROLE_DFP  (PD_RICHTEK_ERROR_NO_BASE + 12)
#define ERROR_RT_SVID_DATA_NULL               (PD_RICHTEK_ERROR_NO_BASE + 13)

/* tp */
#define DSM_TP_I2C_RW_ERROR_NO 				(926004000)
#define DSM_TP_FWUPDATE_ERROR_NO 			(926004001)
#define DSM_TP_RAWDATA_ERROR_NO             (20002)
#define DSM_TP_FW_CRC_ERROR_NO              (926004003)
#define DSM_TP_DEV_STATUS_ERROR_NO          (926004004)
#define DSM_TP_FREEZE_ERROR_NO          (926004005)/*one possible reason:LCD can't send out TSVD/TSHD signal */
#define DSM_TP_CHANGE_REPORT_ERROR_NO       (926004006)
#define DSM_TP_GLOVE_ON_COUNT_ERROR_NO      (926004007)
#define DSM_TP_ATMEL_IN_MOISTURE_ERROR_NO   (926004008)
#define DSM_TP_ATMEL_IN_VNOISE_ERROR_NO     (926004009)
#define DSM_TP_CALIBRATION_CRC_ERROR_NO     (926004010)
#define DSM_TP_FW_CRASH_ERROR_NO            (926004011)

/* tphostprocessing */
#define DSM_TPHOSTPROCESSING_SPI_RW_ERROR_NO 		(926011021)
#define DSM_TPHOSTPROCESSING_DEV_STATUS_ERROR_NO 	(926011022)

/*qcom*/
#define DSM_TP_CAP_ERROR_NO 			    (926004014)
#define DSM_TP_ESD_ERROR_NO					(926004015)
#define DSM_TP_F34_PDT_ERROR_NO 			(926004016)
#define DSM_TP_F54_PDT_ERROR_NO 			(926004017)
#define DSM_TP_PDT_PROPS_ERROR_NO 			(926004018)
#define DSM_TP_F34_READ_QUERIES_ERROR_NO 	(926004019)
#define DSM_TP_WAKEUP_ERROR_NO 	            (926004020)
#define DSM_TP_HID_TIMEOUT_ERROR_NO         (926004021)
#define DSM_TP_STARTUP_FAIDED_ERROR_NO      (926004022)
#define DSM_TP_GET_LCD_PANEL_NAME_ERROR_NO  (926004023)
#define DSM_TP_NO_IRQ_ERROR_NO				(20002)
#define DSM_TP_GHOST_TOUCH_ERROR_NO         (926004024)
#define DSM_TP_GET_LCD_INFO_ERROR_NO 		(926004025)
#define DSM_TP_NOISE_INFO_REPORT_ERROR_NO   (926004026)

/* lcd */
#define DSM_LCD_LDI_UNDERFLOW_NO            (922001000)
#define DSM_LCD_LDI_UNDERFLOW_ERROR_NO     	(922001000)
#define DSM_LCD_TE_TIME_OUT_ERROR_NO        (922001001)
#define DSM_LCD_STATUS_ERROR_NO				(922001002)
#define DSM_LCD_POWER_STATUS_ERROR_NO		(922001003)
#define DSM_LCD_PWM_ERROR_NO				(922001004)
#define DSM_LCD_BRIGHTNESS_ERROR_NO			(922001005)
#define DSM_LCD_ESD_RECOVERY_NO				(922001006)
#define DSM_LCD_ESD_OCP_RECOVERY_NO			(922001007)
#define DSM_LCD_OVP_ERROR_NO				(922001008)
#define DSM_LCD_OVP_COMFORT_MODE_NO			(922001009)
#define DSM_LCD_MIPI_ERROR_NO				(922001010)
#define DSM_LCD_MDSS_MDP_GPU_ERROR_NO		(922001013)
#define DSM_LCD_OTP_ERROR_NO				(922001014)
#define DSM_LCD_MDSS_DSI_ISR_ERROR_NO		(922001016)
#define DSM_LCD_MDSS_MDP_ISR_ERROR_NO		(922001017)
#define DSM_LCD_ESD_STATUS_ERROR_NO			(922001018)
#define DSM_LCD_ESD_RESET_ERROR_NO			(922001019)
#define DSM_LCD_POWER_STATUS_ERROR_NO_QCOM	(922001020)
#define DSM_LCD_MDSS_UNDERRUN_ERROR_NO		(922001021)
#define DSM_LCD_MDSS_IOMMU_ERROR_NO			(922001022)
#define DSM_LCD_MDSS_PIPE_ERROR_NO			(922001023)
#define DSM_LCD_MDSS_PINGPONG_ERROR_NO		(922001024)
#define DSM_LCD_MDSS_VSP_VSN_ERROR_NO		(922001025)
#define DSM_LCD_MDSS_ROTATOR_ERROR_NO		(922001026)
#define DSM_LCD_MDSS_FENCE_ERROR_NO			(922001027)
#define DSM_LCD_MDSS_CMD_STOP_ERROR_NO		(922001028)
#define DSM_LCD_MDSS_VIDEO_DISPLAY_ERROR_NO	(922001029)
#define DSM_LCD_MDSS_MDP_CLK_ERROR_NO		(922001030)
#define DSM_LCD_MDSS_MDP_BUSY_ERROR_NO		(922001031)
#define DSM_LCD_FB0_CLOSE_ERROR_NO			(922001032)
#define DSM_LCD_BTB_CHECK_ERROR_NO			(922001033)

/* gpu */
#define DSM_LCD_GPU_HANG_ERROR_NO           (922002000)

#define DSM_SOC_HIFI_RESET                  (921001000)
#define DSM_CODEC_HIFI_RESET                (921001001)
#define DSM_CODEC_HIFI_IF_OPEN_ERR          (921001002)
#define DSM_SOC_HIFI_HIGH_CPU               (921001003)

#define DSM_HI6402_PLL_PD                   (921001004)
#define DSM_HI6402_PLL_UNLOCK               (921001005)
#define DSM_HI6402_PLL_CANNOT_LOCK          (921001006)
#define DSM_HI6402_SLIMBUS_READ_ERR         (921001007)
#define DSM_HI6402_SLIMBUS_LOST_MS          (921001008)
#define DSM_HI6402_MBHC_HS_ERR_TYPE         (921001009)
#define DSM_SOC_HIFI_UPDATE_BUFF_DELAY      (921001024)
#define DSM_SOC_HIFI_3A_ERROR               (921001031)
#define DSM_CODEC_HIFI_TIMEOUT              (921001032)
/*hifi*/
#define DSM_HIFI_AK4376_I2C_ERR             (921001034)
#define DSM_HIFI_AK4376_CODEC_PROBE_ERR     (921001035)
/*codec*/
#define DSM_CODEC_BUNK1_OCP                 (921001036)
#define DSM_CODEC_BUNK1_SCP                 (921001037)
#define DSM_CODEC_BUNK2_OCP                 (921001038)
#define DSM_CODEC_BUNK2_SCP                 (921001039)
#define DSM_CODEC_CP1_SHORT                 (921001040)
#define DSM_CODEC_CP2_SHORT                 (921001041)

/* anc_hs */
#define ANC_HS_OPEN_BOOST_ERR               (921002000)
#define ANC_HS_CANCEL_WORK_BLOCK            (921002001)
#define ANC_HS_CLOSE_BOOST_ERR              (921002002)
#define ANC_HS_ADCH_READ_ERR                (921002003)
#define ANC_HS_ADC_FULL_ERR                 (921002004)
#define ANC_HS_MIC_WITH_GPIO_ERR            (921002005)
#define ANC_HS_QUEUE_WORK_ERR               (921002006)
#define ANC_HS_BTN_NOT_IN_RANGE             (921002007)
#define ANC_HS_UNHANDLED_IRQ                (921002008)
#define ANC_HS_I2C_ERR                      (921002009)

/*smartpa*/
#define DSM_SMARTPA_I2C_ERR                 (921003000)
#define DSM_SMARTPA_INT_ERR                 (921003001)

/* sdio */
#define DSM_SDIO_RW_ERROR_NO                        (925002000)
#define DSM_SDIO_DCM_INIT_ERROR_NO                  (925002001)
#define DSM_SDIO_HARDWARE_LOCK_NO                   (925002002)
#define DSM_SDIO_RW_TIMEOUT_NO                      (925002003)
#define DSM_SDIO_ATTACH_ERR_NO                      (925002004)
#define DSM_SDIO_CDM52_INVELADE_ARGUMENT_ERR_NO     (925002005)
#define DSM_SDIO_CDM52_R5_ERR_NO                    (925002006)
#define DSM_SDIO_CDM52_R5_FUNCTION_NUMBER_ERR_NO    (925002007)
#define DSM_SDIO_CDM52_R5_OUT_OF_RANGE_ERR_NO       (925002008)
#define DSM_SDIO_CDM52__WAIT_FOR_CMD_ERR_NO         (925002009)
#define DSM_SDIO_CMD53_INVELADE_ARGUMENT_ERR_NO     (925002010)
#define DSM_SDIO_CMD53_ALLOC_TABLE_ERR_NO           (925002011)
#define DSM_SDIO_CMD53_CMD_ERR_NO                   (925002012)
#define DSM_SDIO_CMD53_DATA_ERR_NO                  (925002013)
#define DSM_SDIO_CMD53_R5_ERR_NO                    (925002014)
#define DSM_SDIO_CMD53_R5_FUNCTION_NUMBER_ERR_NO    (925002015)
#define DSM_SDIO_CMD53_R5_OUT_OF_RANGE_ERR_NO       (925002016)
#define DSM_SIDO_UNKOWN_ERR_NO                      (925002017)

/* sensors */
#define DSM_SHB_ERR_IOM7_CFG_DATA				(926005000)
#define DSM_SHB_ERR_IOM7_CMD					(926005001)
#define DSM_SHB_ERR_IOM7_DYNLOAD				(926005002)
#define DSM_SHB_ERR_IOM7_I2C_DBG				(926005003)
#define DSM_SHB_ERR_IOM7_IPC_TIMEOUT			(926005004)
#define DSM_SHB_ERR_IOM7_OTHER					(926005005)
#define DSM_SHB_ERR_IOM7_READ					(926005006)
#define DSM_SHB_ERR_IOM7_STEP					(926005007)
#define DSM_SHB_ERR_IOM7_WDG					(926005008)
#define DSM_SHB_ERR_IOM7_WRITE					(926005009)

#define DSM_SHB_ERR_MCU_ACCEL					(926006000)
#define DSM_SHB_ERR_MCU_AIRPRESS				(926006001)
#define DSM_SHB_ERR_MCU_ALS						(926006002)
#define DSM_SHB_ERR_MCU_FUSION					(926006003)
#define DSM_SHB_ERR_MCU_GYRO					(926006004)
#define DSM_SHB_ERR_MCU_I2C_ERR					(926006005)
#define DSM_SHB_ERR_MCU_LABC					(926006006)
#define DSM_SHB_ERR_MCU_LIGHT 					(926006007)
#define DSM_SHB_ERR_MCU_MAG 					(926006008)
#define DSM_SHB_ERR_MCU_MOTION 					(926006009)
#define DSM_SHB_ERR_MCU_OTHER 					(926006010)
#define DSM_SHB_ERR_MCU_PDR 					(926006011)
#define DSM_SHB_ERR_MCU_PEDOMETER				(926006012)
#define DSM_SHB_ERR_MCU_PS						(926006013)
#define DSM_SHB_ERR_MCU_SYS_MAIN_INIT			(926006100)
#define DSM_SHB_ERR_MCU_SYS_SERVER_INIT			(926006101)
#define DSM_SHB_ERR_MCU_TIMER_TIMEOUT			(926006102)
#define DSM_SHB_ERR_MCU_ACC_PERIOD_ERROR		(926006103)
#define DSM_SHB_ERR_MCU_CA						(926006104)
#define DSM_SHB_ERR_SYSCOUNT					(926006105)

#define DSM_SHB_ERR_GSENSOR_I2C_ERR				(926007000)
#define DSM_SHB_ERR_GSENSOR_DATA_ABNORMAL		(926007001)
#define DSM_SHB_ERR_GSENSOR_DATA_ALL_ZERO		(926007002)
#define DSM_SHB_ERR_GSENSOR_DATA_NOT_UPDATE		(926007003)
#define DSM_SHB_ERR_LIGHT_I2C_ERR				(926007004)
#define DSM_SHB_ERR_LIGHT_IRQ_ERR				(926007005)
#define DSM_SHB_ERR_LIGHT_THRESHOLD_ERR			(926007006)
#define DSM_SHB_ERR_LIGHT_NO_IRQ				(926007007)
#define DSM_SHB_ERR_LIGHT_ENABLE_ERR			(926007008)
#define DSM_SHB_ERR_LIGHT_THRESHOLD_OUT			(926007009)
#define DSM_SHB_ERR_LIGHT_POWER_ERR				(926007010)
#define DSM_SHB_ERR_MAG_I2C_READ				(926007011)
#define DSM_SHB_ERR_MAG_DATA_ABNORAML			(926007012)
#define DSM_SHB_ERR_MAG_DATA_NOT_UPDATE			(926007013)
#define DSM_SHB_ERR_MAG_SELFTEST_ERR			(926007014)
#define DSM_SHB_ERR_SENSORSERVICE_EXIT_ERR		(926007015)
#define DSM_SHB_ERR_SENSORSERVICE_DATA_UPDATE	(926007016)

/* key */
#define DSM_KEY_ERROR_NO					(926003000)
#define DSM_POWER_KEY_ERROR_NO				(926003001)

/* hall */
#define DSM_HALL_ERROR_NO                   (926002000)


/* camera flash */
#define DSM_FLASH_I2C_ERROR_NO                            (927002000)
#define DSM_FLASH_OPEN_SHOTR_ERROR_NO                     (927002001)
#define DSM_FLASH_HOT_DIE_ERROR_NO                        (927002002)
#define DSM_FLASH_UNDER_VOLTAGE_LOCKOUT_ERROR_NO          (927002003)

/* camera hal flash*/
#define DSM_DALLAS_FLASH_SCHARGER_ERROR_NO  (927003018)

/* ext isp */
#define DSM_EXTISP_LOAD_FW_ERROR_NO         (927007000)
#define DSM_EXTISP_PQ_ERROR_NO              (927007001)
#define DSM_EXTISP_I2C_ERROR_NO             (927007002)
#define DSM_EXTISP_USPI_ERROR_NO            (927007003)
#define DSM_EXTISP_VCM_ERROR_NO             (927007004)
#define DSM_EXTISP_INTERRUPT_ERROR_NO       (927007005)
#define DSM_EXTISP_COMMONFUNC_ERROR_NO      (927007006)
#define DSM_EXTISP_A3_ERROR_NO              (927007007)
#define DSM_EXTISP_PIPE_ERROR_NO            (927007008)
#define DSM_EXTISP_RDN_ERROR_NO             (927007009)
#define DSM_EXTISP_TXLM_ERROR_NO            (927007010)
#define DSM_EXTISP_MTX_ERROR_NO             (927007011)
#define DSM_EXTISP_MRX_ERROR_NO             (927007012)
#define DSM_EXTISP_FEC0_ERROR_NO            (927007013)
#define DSM_EXTISP_SENSOR_ERROR_NO          (927007014)
#define DSM_EXTISP_FEC1_ERROR_NO            (927007015)
#define DSM_EXTISP_CAP_ERROR_NO             (927007016)
#define DSM_EXTISP_OTHER_ERROR_NO           (927007017)

/* camera csi */
#define DSM_CSI_MIPI0_ERROR_NO              (927001000)
#define DSM_CSI_MIPI1_ERROR_NO              (927001001)

/* camera qcom */
#define DSM_CAMERA_SOF_ERR								927009001
#define DSM_CAMERA_I2C_ERR								927009002
#define DSM_CAMERA_CHIP_ID_NOT_MATCH					927009003
#define DSM_CAMERA_OTP_ERR								927009004
#define DSM_CAMERA_SENSOR_NO_FRAME						927009005
#define DSM_CAMERA_LED_FLASH_CIRCUIT_ERR				927009006
#define DSM_CAMERA_LED_FLASH_OVER_TEMPERATURE			927009007
#define DSM_CAMERA_LED_FLASH_VOUT_ERROR					927009008
#define DSM_CAMERA_ISP_OVERFLOW							927009009
#define DSM_CAMERA_ISP_AXI_STREAM_FAIL					927009010
#define DSM_CAMERA_POST_EVENT_TIMEOUT					927009011
#define DSM_CAMERA_ACTUATOR_INIT_FAIL					927009012
#define DSM_CAMERA_ACTUATOR_SET_INFO_ERR				927009013
#define DSM_CAMERA_ACTUATOR_MOVE_FAIL					927009014
#define DSM_CAMERA_FD_LEAK_ERR							927009015
#define DSM_CAMERA_SENSOR_INIT_SESSION_FAIL				927009016
#define DSM_CAMERA_SESSION_ID_MATCH_FAIL				927009017
#define DSM_CAMERA_REPROCESS_PARAM_ERROR				927009018
#define DSM_CAMERA_MCT_PIPELINE_SET_FAIL				927009019
#define DSM_CAMERA_INVALID_POLL_FD						927009020
#define DSM_CAMERA_START_CHANNEL_NO_BUF					927009021
#define DSM_CAMERA_BUF_MANAGER_NO_BUF					927009022
#define DSM_CAMERA_ISP_REQUEST_HAL_BUF_FAIL				927009023
#define DSM_CAMERA_ISP_REQUEST_BUF_UPDATE_FAIL			927009024
#define DSM_CAMERA_CPP_INPUT_PARAMS_ERROR				927009025
#define DSM_CAMERA_CPP_OUTPUT_PARAMS_ERROR				927009026
#define DSM_CAMERA_ISPIF_PORT_ERROR						927009027
#define DSM_CAMERA_ISPIF_MODULE_NOT_FOUND 				927009028
#define DSM_CAMERA_ISPIF_CFG_ERROR						927009029
#define DSM_CAMERA_FOCUS_NOT_DONE						927009030
#define DSM_CAMERA_OIS_ACC_FAIL							927009031
#define DSM_CAMERA_OIS_CHECK_FAIL						927009032
#define DSM_CAMERA_OIS_INIT_FAIL						927009033
#define DSM_CAMERA_OIS_VIBRATE_FAIL						927009034
#define DSM_CAMERA_SENSOR_INIT_FAIL						927009035
#define DSM_CAMERA_SENSOR_SET_RESOLUTION_FAIL			927009036
#define DSM_CAMERA_SENSOR_APPLY_EXPOSURE_FAIL			927009037
#define DSM_CAMERA_SENSOR_START_STOP_STREAM_FAIL		927009038
#define DSM_CAMERA_EEPROM_CALIBRATE_FAIL				927009039
#define DSM_CAMERA_VIDC_OVERLOADED 						927009040
#define DSM_CAMERA_VIDC_SESSION_ERROR 					927009041
#define DSM_CAMERA_VIDC_LOAD_FW_FAIL 					927009042
#define DSM_CAMERA_OTP_I2C_ERR 							927009043

/* camera pmic */
#define DSM_CAMPMIC_I2C_ERROR_NO            (927010000)
#define DSM_CAMPMIC_ENABLE_ERROR_NO         (927010001)
#define DSM_CAMPMIC_OVER_CURRENT_ERROR_NO   (927010002)
#define DSM_CAMPMIC_TSD_ERROR_NO            (927010003)
#define DSM_CAMPMIC_UNDER_VOLTAGE_ERROR_NO  (927010004)

/* ov isp */
#define DSM_ISP22_MCU_NO_RSP_ERROR_NO       (927004000)
#define DSM_ISP22_CMD_SET_ERROR_NO          (927004001)
#define DSM_ISP22_SENSOR_PRIMARY_ERROR_NO   (927004002)
#define DSM_ISP22_SENSOR_SECONDARY_ERROR_NO (927004003)
#define DSM_ISP22_FLASH_ERROR_NO            (927004004)

/* ivp */
#define DSM_IVP_SMMU_ERROR_NO               (927005000)
#define DSM_IVP_WATCH_ERROR_NO              (927005001)
#define DSM_IVP_DWAXI_ERROR_NO              (927005002)
#define DSM_IVP_OPEN_ERROR_NO               (927005003)
#define DSM_IVP_MESSAGE_ERROR_NO            (927005004)
#define DSM_IVP_PANIC_ERROR_NO              (927005005)

/* wifi */
#define DSM_WIFI_MODULE_INIT_ERROR          (909030001)
#define DSM_WIFI_KSO_ERROR                  (909030002)
#define DSM_WIFI_CMD52_ERROR                (909030003)
#define DSM_WIFI_CMD53_ERROR                (909030004)
/*wifi open*/
#define DSM_WIFI_SDIO_RESET_COMM_ERROR      (909030005)
#define DSM_WIFI_SDIO_PROBE_ATTACH_ERROR    (909030006)
#define DSM_WIFI_SDIO_FIRMWARE_DL_ERROR     (909030007)
#define DSM_WIFI_DHD_DEV_INIT_IOCTL_ERROR   (909030008)
/*wifi scan*/
#define DSM_WIFI_WLC_SET_PASSIVE_SCAN_ERROR (909030009)
#define DSM_WIFI_WLC_SCAN_ERROR             (909030010)
#define DSM_WIFI_WLC_SET_SCANSUPPRESS_ERROR (909030011)
#define DSM_WIFI_WLC_GET_CHANNEL_ERROR      (909030012)
#define DSM_WIFI_WLC_SCAN_RESULTS_ERROR     (909030013)
/*wifi connect*/
#define DSM_WIFI_WLC_DISASSOC_ERROR         (909030014)
#define DSM_WIFI_WLC_SET_SSID_ERROR         (909030015)
#define DSM_WIFI_SET_CIPHER_ERROR           (909030016)
#define DSM_WIFI_SET_KEY_MGMT_ERROR         (909030017)
#define DSM_WIFI_SET_SHAREDKEY_ERROR        (909030018)
#define DSM_WIFI_OPEN_ERROR                 (909030019)

/*wifi qcom*/
#define DSM_WIFI_ERR                        (909030007)
#define DSM_WIFI_FAIL_LOADFIRMWARE_ERR      (909030007)
#define DSM_WIFI_DRIVER_LOAD_ERR            (909030019)
#define DSM_WIFI_MAC_ERR                    (909031004)
#define DSM_WIFI_ROOT_NOT_RIGHT_ERR         (909031009)

#define DSM_WIFI_RESERVED                   (20701)



/* recovery */
#define DSM_RECOVERY_ERROR_NO        (924001000)

/* selinux */
#define DSM_SELINUX_ERROR_NO                  (924002000)

/* modem spi */
#define DSM_SPI_WRITE_ACK_ERROR_NO                   (926009000)
#define DSM_SPI_READ_ACK_ERROR_NO                   (DSM_SPI_WRITE_ACK_ERROR_NO+1)
#define DSM_SPI_80_ACK_ERROR_NO                       (DSM_SPI_WRITE_ACK_ERROR_NO+2)
#define DSM_SPI_SYNC_ERROR_NO                           (DSM_SPI_WRITE_ACK_ERROR_NO + 3)
#define DSM_SPI_DOWN_ERROR_NO                          (DSM_SPI_WRITE_ACK_ERROR_NO + 4)
#define DSM_SPI_PORT_BUSY_NO                             (DSM_SPI_WRITE_ACK_ERROR_NO + 5)
#define DSM_SPI_DATA_READ_ERROR_NO                (DSM_SPI_WRITE_ACK_ERROR_NO + 6)
#define DSM_SPI_DATA_DROP_NO                            (DSM_SPI_WRITE_ACK_ERROR_NO + 7)
#define DSM_SPI_AUTO_READY_ERROR_NO              (DSM_SPI_WRITE_ACK_ERROR_NO + 8)
#define DSM_SPI_KZALLOC_FAILED_NO                    (DSM_SPI_WRITE_ACK_ERROR_NO + 9)
#define DSM_SPI_ALLOC_SKB_FAILED_NO                (DSM_SPI_WRITE_ACK_ERROR_NO + 10)
#define DSM_SPI_DOWN_RETRY_MAX_NO                 (DSM_SPI_WRITE_ACK_ERROR_NO + 11)
#define DSM_SPI_SYNC_ERR_MAX_NO                      (DSM_SPI_WRITE_ACK_ERROR_NO + 12)
#define DSM_APCP_SDIO_WRITE_ACK_ERROR_NO    (DSM_SPI_WRITE_ACK_ERROR_NO + 13)

/* spi */
#define DSM_SPI_ERROR_NO					(925001000) /* spi_sync timeout error */
#define DSM_SPI_INVALID_ARGUMENT_ERR_NO (925001001)
#define DSM_SPI_SHUTDOWN_ERR_NO               (925001002)
#define DSM_SPI_UNKOWN_ERR_NO                   (925001003)
#define DSM_SPI_SG_ALLOC_RX_PAGE_INVILAD_LEN (925001004)
#define DSM_SPI_SG_ALLOC_TX_PAGE_INVILAD_LEN (925001005)
#define DSM_SPI_RX_FIFO_NOT_EMPTY            (925001006)
#define DSM_SPI_SPI_IS_BUSY                  (925001007)

/* fs & ext4 */
#define DSM_FS_EXT4_ERROR					(928003000)
#define DSM_FS_EXT4_ERROR_INODE				(928003001)
#define DSM_FS_EXT4_ERROR_FILE				(928003002)
#define DSM_FS_EXT4_ERROR_READ_SUPER		(928003003)
#define DSM_FS_EXT4_ERROR_READ_SUPER_SECOND (928003004)
#define DSM_FS_EXT4_ERROR_WRITE_SUPER		(928003005)


/* f2fs */
#define DSM_F2FS_ERROR_MSG                      (928005000)
#define DSM_F2FS_SUPER_NEED_FSCK                (928005001)
#define DSM_F2FS_BUGCHK_NEED_FSCK               (928005002)


#define DSM_UART_OPEN_HWINIT_ERROR              (22100)
#define DSM_UART_OPEN_IRQ_REQUSET_FAILED        (DSM_UART_OPEN_HWINIT_ERROR+1)
#define DSM_UART_TX_DMA_MAP_FAILED              (DSM_UART_OPEN_HWINIT_ERROR+2)
#define DSM_UART_TX_DMA_BUSY_ERROR              (DSM_UART_OPEN_HWINIT_ERROR+3)
#define DSM_UART_RX_DMA_READ_BUFFER_FULL_ERROR  (DSM_UART_OPEN_HWINIT_ERROR+4)
#define DSM_UART_CONTROLLER_FIFO_OVERRUN_ERROR  (DSM_UART_OPEN_HWINIT_ERROR+5)
#define DSM_UART_CONTROLLER_LINE_BREAK_ERROR    (DSM_UART_OPEN_HWINIT_ERROR+6)
#define DSM_UART_CONTROLLER_PARITY_ERROR        (DSM_UART_OPEN_HWINIT_ERROR+7)
#define DSM_UART_CONTROLLER_FRAME_ERROR         (DSM_UART_OPEN_HWINIT_ERROR+8)

/* hwtc */
#define DSM_HWTC_ERROR_NO                       (927008000)

/* stat mm */
#define DSM_MM_STAT                             (924003000)


/* nfc */
#define DSM_NFC_I2C_WRITE_ERROR_NO					(923002000)
#define DSM_NFC_I2C_READ_ERROR_NO					(923002001)
#define DSM_NFC_CLK_ENABLE_ERROR_NO					(923002002)
#define DSM_NFC_I2C_WRITE_EOPNOTSUPP_ERROR_NO		(923002003)
#define DSM_NFC_I2C_READ_EOPNOTSUPP_ERROR_NO		(923002004)
#define DSM_NFC_I2C_WRITE_EREMOTEIO_ERROR_NO		(923002005)
#define DSM_NFC_I2C_READ_EREMOTEIO_ERROR_NO			(923002006)
#define DSM_NFC_RD_I2C_WRITE_ERROR_NO				(923002007)
#define DSM_NFC_RD_I2C_READ_ERROR_NO				(923002008)
#define DSM_NFC_RD_I2C_WRITE_EOPNOTSUPP_ERROR_NO	(923002009)
#define DSM_NFC_RD_I2C_READ_EOPNOTSUPP_ERROR_NO		(923002010)
#define DSM_NFC_RD_I2C_WRITE_EREMOTEIO_ERROR_NO		(923002011)
#define DSM_NFC_RD_I2C_READ_EREMOTEIO_ERROR_NO		(923002012)
#define DSM_NFC_SIM_CHECK_ERROR_NO					(923002013)
#define DSM_NFC_HAL_CORE_RESET						(923002014)
#define DSM_NFC_HISEE_COS_IMAGE_UPGRADE_ERROR_NO	(923002015)
#define DSM_NFC_HISEE_POWER_ON_OFF_ERROR_NO			(923002016)
#define DSM_NFC_HISEE_APDU_COMMAND_OPERATION_ERROR_NO (923002017)


/* fingerprint */
#define DSM_FINGERPRINT_WAIT_FOR_FINGER_ERROR_NO	(912001000)
#define DSM_FINGERPRINT_CAPTURE_IMAGE_ERROR_NO	(912001001)
#define DSM_FINGERPRINT_IDENTIFY_ERROR_NO                 (912001002)
#define DSM_FINGERPRINT_TEST_DEADPIXELS_ERROR_NO	(912001003)
#define DSM_FINGERPRINT_ENROLL_ERROR_NO	             (912001004)
#define DSM_FINGERPRINT_REMOVE_TEMPLATE_ERROR_NO	(912001005)
#define DSM_FINGERPRINT_ENUMERATE_ERROR_NO		(912001006)
#define DSM_FINGERPRINT_MODULE_OPEN_ERROR_NO		(912001007)
#define DSM_FINGERPRINT_PROBE_FAIL_ERROR_NO	       (912001008)
#define DSM_FINGERPRINT_DIFF_DEADPIXELS_ERROR_NO	(912001009)
#define DSM_FINGERPRINT_MANY_DEADPIXELS_ERROR_NO	(912001010)
#define DSM_FINGERPRINT_DB_FILE_LOST_ERROR_NO	    (912001011)


/************DMD NUMBER FOR TP AND SENSOR BEGIN**************/
#define CLIENT_DSM_KEY					"dsm_key"
#define DSM_GS_I2C_ERROR							(926007000)
#define DSM_GS_DATA_ERROR							(926007001)
#define DSM_GS_XYZ_0_ERROR							(926007002)
#define DSM_GS_DATA_TIMES_NOTCHANGE_ERROR			(926007003)
#define DSM_LPS_I2C_ERROR							(926007004)
#define DSM_LPS_WRONG_IRQ_ERROR						(926007005)
#define DSM_LPS_THRESHOLD_ERROR						(926007006)
#define DSM_LPS_ENABLED_IRQ_ERROR					(926007007)
#define DSM_LPS_ENABLED_ERROR						(926007008)
#define DSM_LPS_THRESHOLD_SIZE_ERROR				(926007009)
#define DSM_LPS_INSTANT_POWER_OFF_ERROR				(926007010)
#define DSM_MS_I2C_ERROR							(926007011)
#define DSM_MS_DATA_ERROR							(926007012)
#define DSM_MS_DATA_TIMES_NOTCHANGE_ERROR			(926007013)
#define DSM_MS_SELF_TEST_ERROR						(926007014)
#define DSM_SENSOR_SERVICE_EXIT						(926007015)
#define DSM_SENSOR_SERVICE_NODATA					(926007016)
#define DSM_HS_IRQ_TIMES_ERR						(926002001)
#define DSM_HS_IRQ_INTERVAL_ERR						(926002002)
#define DSM_VOL_KEY_PRESS_TIMES_ERR					(926003003)
#define DSM_VOL_KEY_PRESS_INTERVAL_ERR				(926003004)
#define DSM_POWER_KEY_PRESS_TIMES_ERR				(926003005)
#define DSM_POWER_KEY_PRESS_INTERVAL_ERR			(926003006)

enum DSM_KEYS_TYPE{
	DSM_VOL_KEY = 0,
	DSM_VOL_UP_KEY,
	DSM_VOL_DOWN_KEY,
	DSM_POW_KEY,
	DSM_HALL_IRQ,
};
#define DSM_POWER_KEY_VAL 		116
#define DSM_VOL_DOWN_KEY_VAL 	114
#define DSM_SENSOR_BUF_MAX 				2048
#define DSM_SENSOR_BUF_COM				2048

/************DMD NUMBER FOR AUDIO BEGIN**************/
#define DSM_AUDIO_ERROR_NUM                     (921001012)
#define DSM_AUDIO_HANDSET_DECT_FAIL_ERROR_NO    (DSM_AUDIO_ERROR_NUM)
#define DSM_AUDIO_ADSP_SETUP_FAIL_ERROR_NO      (DSM_AUDIO_ERROR_NUM + 1)
#define DSM_AUDIO_CARD_LOAD_FAIL_ERROR_NO       (DSM_AUDIO_ERROR_NUM + 2)
#define DSM_AUDIO_HAL_FAIL_ERROR_NO             (DSM_AUDIO_ERROR_NUM + 3)
#define DSM_AUDIO_MODEM_CRASH_ERROR_NO          (DSM_AUDIO_ERROR_NUM + 4)
#define DSM_AUDIO_HANDSET_PLUG_PRESS_ERROR      (DSM_AUDIO_ERROR_NUM + 5)
#define DSM_AUDIO_HANDSET_PRESS_RELEASE_ERROR   (DSM_AUDIO_ERROR_NUM + 6)
#define DSM_AUDIO_HANDSET_PLUG_RELEASE_ERROR    (DSM_AUDIO_ERROR_NUM + 7)
#define DSM_AUDIO_MMI_TEST_TIME_TOO_SHORT       (DSM_AUDIO_ERROR_NUM + 8)
#define DSM_AUDIO_CFG_CODEC_CLK_FAIL_ERROR      (DSM_AUDIO_ERROR_NUM + 9)
#define DSM_AUDIO_MODEM_CRASH_CODEC_CALLBACK    (DSM_AUDIO_ERROR_NUM + 10)
#define DSM_AUDIO_CODEC_RESUME_FAIL_ERROR       (DSM_AUDIO_ERROR_NUM + 11)
// (DSM_AUDIO_ERROR_NUM + 12) has been occupied by asd test
#define DSM_AUDIO_VRM_ERROR                     (DSM_AUDIO_ERROR_NUM + 21)

/* DM */
#define DSM_DM_VERITY_ERROR_NO	(928001000)
#define DSM_DM_VERITY_FEC_INFO_NO	(928001001)
#define DSM_DM_VERITY_CE_ERROR_NO	(928001002)
/*cpu_buck*/
#define ERROR_NO_CPU_BUCK_BASE  (920012000)

struct dsm_client_ops{
	int (*poll_state) (void);
	int (*dump_func) (int type, void *buff, int size);
};

struct dsm_dev{
	const char *name;
	const char *device_name;
	const char *ic_name;
	const char *module_name;
	struct dsm_client_ops *fops;
	size_t buff_size;
};

struct dsm_client{
	char client_name[CLIENT_NAME_LEN];
	char device_name[DSM_MAX_DEVICE_NAME_LEN];
	char ic_name[DSM_MAX_IC_NAME_LEN];
	char module_name[DSM_MAX_MODULE_NAME_LEN];
	int client_id;
	int error_no;
	unsigned long buff_flag;
	struct dsm_client_ops *cops;
	wait_queue_head_t waitq;
	size_t read_size;
	size_t used_size;
	size_t buff_size;
	u8 dump_buff[];
};

/*
* for userspace client, such as sensor service, please refer to it.
*/
struct dsm_extern_client{
	char client_name[CLIENT_NAME_LEN];
	int buf_size;
};

#ifdef CONFIG_HUAWEI_DSM
struct dsm_client *dsm_register_client (struct dsm_dev *dev);
void dsm_unregister_client (struct dsm_client *dsm_client,struct dsm_dev *dev);
struct dsm_client *dsm_find_client(char *dsm_name);
int dsm_client_ocuppy(struct dsm_client *client);
int dsm_client_unocuppy(struct dsm_client *client);
int dsm_client_record(struct dsm_client *client, const char *fmt, ...);
int dsm_client_copy(struct dsm_client *client, void *src, int sz);
void dsm_client_notify(struct dsm_client *client, int error_no);
extern void dsm_key_pressed(int type);
int dsm_update_client_vendor_info(struct dsm_dev *dev);
#else
static inline struct dsm_client *dsm_register_client (struct dsm_dev *dev)
{
	return NULL;
}
static inline struct dsm_client *dsm_find_client(char *dsm_name)
{
	return NULL;
}
static inline int dsm_client_ocuppy(struct dsm_client *client)
{
	return 1;
}
static inline int dsm_client_unocuppy(struct dsm_client *client)
{
	return 0;
}

static inline int dsm_client_record(struct dsm_client *client, const char *fmt, ...)
{
	return 0;
}
static inline int dsm_client_copy(struct dsm_client *client, void *src, int sz)
{
	return 0;
}
static inline void dsm_client_notify(struct dsm_client *client, int error_no)
{
	return;
}
static inline int dsm_update_client_vendor_info(struct dsm_dev *dev)
{
	return 0;
}
#endif

#endif
