/* SPDX-License-Identifier: MIT */
/*----------------------------------------------------------------------------/
/ Basic functions for modifying the CAN frame payload                          /
/-----------------------------------------------------------------------------/
/
/ Copyright (C) 2024, pawelt798, all right reserved.
/
/----------------------------------------------------------------------------*/

#ifndef CAN_BUS_DATA_OPERATIONS_H
#define CAN_BUS_DATA_OPERATIONS_H

#define uint8_t unsigned char
#define uint32_t unsigned int
#define TRACE_DEBUG_NL printf

void can_data_modify_bit(uint8_t *data, uint8_t bit_pos, uint8_t value);
void can_data_modify_value(uint8_t *data, size_t data_size, uint32_t start_bit, uint32_t bit_length, uint32_t value, uint32_t motorola_format);

#endif