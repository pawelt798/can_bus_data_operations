/* SPDX-License-Identifier: MIT */
/*----------------------------------------------------------------------------/
/ Basic functions for modifying the CAN frame payload                          /
/-----------------------------------------------------------------------------/
/
/ Copyright (C) 2024, pawelt798, all right reserved.
/
/----------------------------------------------------------------------------*/

#include "stdafx.h"
#include "can_bus_data_operations.h"

void can_data_modify_bit(uint8_t *data, uint8_t bit_pos, uint8_t value)
{
	uint8_t calc_byte_position = (bit_pos / 8);
	uint8_t shift_bit = bit_pos % 8;

	if (value == 1)
	{
		data[calc_byte_position] = data[calc_byte_position] | (1 << shift_bit);
	}
	else if (value == 0)
	{
		data[calc_byte_position] &= ~(1 << shift_bit);
	}
}


void can_data_modify_value(uint8_t *data, size_t data_size, uint32_t start_bit, uint32_t bit_length, uint32_t value, uint32_t motorola_format) {
	uint32_t max_value = (1 << (bit_length)) - 1;
	// Check if out of range
	if (value > max_value)
	{
		return;
	}

	// Motorola byte order
	if (motorola_format) {
		// LSB calc
		uint32_t lsb_bit = start_bit;
		for (int i = 0; i < bit_length - 1; i++)
		{
			lsb_bit--;

			if (lsb_bit % 8 == 7)
			{
				lsb_bit += 16;
			}
		}
		// Fill data
		for (int i = 0; i < bit_length; i++)
		{
			can_data_modify_bit(data, lsb_bit, (value >> i) & 0x01);

			lsb_bit++;
			if (lsb_bit % 8 == 0)
			{
				lsb_bit -= 16;
			}
		}
	}
	// Intel byte order
	else {
		// Fill data
		for (int i = 0; i < bit_length; i++)
		{
			can_data_modify_bit(data, start_bit, (value >> i) & 0x01);
			start_bit++;
		}
	}
}
