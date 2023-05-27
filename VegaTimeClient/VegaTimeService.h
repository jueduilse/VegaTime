/*
 * VegaTimeService.h
 *
 *  Created on: 2021Äê7ÔÂ14ÈÕ
 *      Author: xuyanwei
 */

#ifndef VEGATIMESERVICE_H_
#define VEGATIMESERVICE_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <inttypes.h>

int RunVegaTimeService(const char * cIP,const unsigned int cPort,const char * interface,const char * logPath,const unsigned int debugLevel, uint32_t readTimeInterval);

#ifdef __cplusplus
}
#endif

#endif /* VEGATIMESERVICE_H_ */
