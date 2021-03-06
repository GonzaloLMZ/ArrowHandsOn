/*
 * sme_cdc_cmd_parse.h
 *
 * Created: 11/01/2015 12:45:14
 *  Author: smkk
 */ 


#ifndef SME_CDC_CMD_PARSE_H_
#define SME_CDC_CMD_PARSE_H_

#include "sme_cmn.h"
#include <stdint-gcc.h>


extern char CDC_HELP_I2C[];
int sme_hex_str_to_data(uint8_t *s, uint8_t *data, uint8_t *datalen);
inline int sme_int_str_to_uint8(uint8_t *s, uint8_t *value);
inline int sme_hex_str_to_uint8(uint8_t *s, uint8_t *value);



inline int sme_int_str_to_uint8(uint8_t *s, uint8_t *value)
{
	if(!s || !s[0]) {
		return SME_EINVAL;
	}
	*value = atoi((char *)s);
	
	return SME_OK;
}

inline int sme_hex_str_to_uint8(uint8_t *s, uint8_t *value)
{
	if(!s || !s[0]) {
		return SME_EINVAL;
	}
	*value = (int)strtol((char *)s, NULL,
	((s[0] == '0') && (s[1] == 'x')) ? 0: 16);
	return SME_OK;
}

#endif /* SME_CDC_CMD_PARSE_H_ */
