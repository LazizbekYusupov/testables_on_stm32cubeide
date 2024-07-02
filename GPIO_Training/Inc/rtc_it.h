/*
 * rtc_it.h
 *
 *  Created on: Jun 18, 2024
 *      Author: User
 */

#ifndef RTC_IT_H_
#define RTC_IT_H_

#define RTC_ASYNCH_PREDIV 0x7F //127 in decimal, out of parenthesis from docs
#define RTC_SYNCH_PREDIV  0xF9 //249 same

#define BKP_FLAG 0x8888

void rtc_init(void);
void rtc_calendar_config(void);
void rtc_calendar_show(uint8_t *show_time, uint8_t *show_date);

#endif /* RTC_IT_H_ */
